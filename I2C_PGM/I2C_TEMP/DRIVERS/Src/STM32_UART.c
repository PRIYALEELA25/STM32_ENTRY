/*
 * STM32_UART.c
 *
 *  Created on: Jul 2, 2026
 *      Author: hp
 */


/*
 * STM32_USART_DRIVER.c
 *
 * Created on: Jul 2026
 */

#include "STM32_UART.h"

/*************************************************************
 * Private Function Prototypes
 *************************************************************/
static void USART_SetBaudRate(USART_RegDef_t *pUSARTx, uint32_t BaudRate);
static uint32_t RCC_GetPCLK1Value(void);
static uint32_t RCC_GetPCLK2Value(void);

/*************************************************************
 * Peripheral Clock Control
 *************************************************************/
void USART_PeriClockControl(USART_RegDef_t *pUSARTx, uint8_t EnOrDis)
{
    if(EnOrDis == ENABLE)
    {
        if(pUSARTx == USART1)
            USART1_CLK_EN();
        else if(pUSARTx == USART2)
            USART2_CLK_EN();
        else if(pUSARTx == USART3)
            USART3_CLK_EN();
        else if(pUSARTx == USART6)
            USART6_CLK_EN();
    }
    else
    {
        if(pUSARTx == USART1)
            USART1_CLK_DIS();
        else if(pUSARTx == USART2)
            USART2_CLK_DIS();
        else if(pUSARTx == USART3)
            USART3_CLK_DIS();
        else if(pUSARTx == USART6)
            USART6_CLK_DIS();
    }
}

/*************************************************************
 * USART Init
 *************************************************************/
void USART_Init(USART_Handle_t *pUSARTHandle)
{
    uint32_t tempreg = 0;

    USART_PeriClockControl(pUSARTHandle->pUSARTx, ENABLE);

    /*************** CR1 ****************/

    /* TX / RX Mode */
    if(pUSARTHandle->USART_Config.USART_Mode == USART_MODE_ONLY_TX)
    {
        tempreg |= (1 << 3);
    }
    else if(pUSARTHandle->USART_Config.USART_Mode == USART_MODE_ONLY_RX)
    {
        tempreg |= (1 << 2);
    }
    else if(pUSARTHandle->USART_Config.USART_Mode == USART_MODE_TXRX)
    {
        tempreg |= (1 << 3);
        tempreg |= (1 << 2);
    }

    /* Word Length */
    tempreg |= (pUSARTHandle->USART_Config.USART_WordLength << 12);

    /* Parity */
    if(pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_EN_EVEN)
    {
        tempreg |= (1 << 10);
    }
    else if(pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_EN_ODD)
    {
        tempreg |= (1 << 10);
        tempreg |= (1 << 9);
    }

    pUSARTHandle->pUSARTx->CR1 = tempreg;

    /*************** CR2 ****************/

    tempreg = 0;

    tempreg |= (pUSARTHandle->USART_Config.USART_NoOfStopBits << 12);

    pUSARTHandle->pUSARTx->CR2 = tempreg;

    /*************** CR3 ****************/

    tempreg = 0;

    if(pUSARTHandle->USART_Config.USART_HWFlowControl == USART_HW_FLOW_CTRL_CTS)
    {
        tempreg |= (1 << 9);
    }
    else if(pUSARTHandle->USART_Config.USART_HWFlowControl == USART_HW_FLOW_CTRL_RTS)
    {
        tempreg |= (1 << 8);
    }
    else if(pUSARTHandle->USART_Config.USART_HWFlowControl == USART_HW_FLOW_CTRL_CTS_RTS)
    {
        tempreg |= (1 << 9);
        tempreg |= (1 << 8);
    }

    pUSARTHandle->pUSARTx->CR3 = tempreg;

    /*************** Baud Rate ****************/

    USART_SetBaudRate(pUSARTHandle->pUSARTx,
                      pUSARTHandle->USART_Config.USART_Baud);

    /*************** Enable USART ****************/

    pUSARTHandle->pUSARTx->CR1 |= (1 << 13);
}

/*************************************************************
 * Enable / Disable Peripheral
 *************************************************************/
void USART_PeripheralControl(USART_RegDef_t *pUSARTx, uint8_t EnOrDis)
{
    if(EnOrDis == ENABLE)
    {
        pUSARTx->CR1 |= (1 << 13);
    }
    else
    {
        pUSARTx->CR1 &= ~(1 << 13);
    }
}

/*************************************************************
 * PCLK Values
 *************************************************************/
static uint32_t RCC_GetPCLK1Value(void)
{
    return 16000000U;      // Default HSI Clock
}

static uint32_t RCC_GetPCLK2Value(void)
{
    return 16000000U;
}

/*************************************************************
 * Baud Rate Calculation
 *************************************************************/
static void USART_SetBaudRate(USART_RegDef_t *pUSARTx, uint32_t BaudRate)
{
    uint32_t PCLKx;
    uint32_t usartdiv;
    uint32_t M_part, F_part;
    uint32_t tempreg = 0;

    if(pUSARTx == USART1 || pUSARTx == USART6)
        PCLKx = RCC_GetPCLK2Value();
    else
        PCLKx = RCC_GetPCLK1Value();

    usartdiv = (25 * PCLKx) / (4 * BaudRate);

    M_part = usartdiv / 100;

    tempreg |= (M_part << 4);

    F_part = usartdiv - (M_part * 100);

    F_part = (((F_part * 16) + 50) / 100) & 0x0F;

    tempreg |= F_part;

    pUSARTx->BRR = tempreg;
}

/*************************************************************
 * Send Data (Blocking)
 *************************************************************/
void USART_SendData(USART_Handle_t *pUSARTHandle,
                    uint8_t *pTxBuffer,
                    uint32_t Len)
{
    while(Len > 0)
    {
        /* Wait until TXE becomes 1 */
        while(!(pUSARTHandle->pUSARTx->SR & (1 << 7)));

        /* 9-bit word length */
        if(pUSARTHandle->USART_Config.USART_WordLength == USART_WORDLEN_9BITS)
        {
            uint16_t *pdata = (uint16_t*)pTxBuffer;

            pUSARTHandle->pUSARTx->DR = (*pdata & 0x01FF);

            if(pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_DISABLE)
            {
                pTxBuffer += 2;
                Len -= 2;
            }
            else
            {
                pTxBuffer++;
                Len--;
            }
        }
        else
        {
            /* 8-bit word length */
            pUSARTHandle->pUSARTx->DR = (*pTxBuffer & 0xFF);

            pTxBuffer++;
            Len--;
        }
    }

    /* Wait until Transmission Complete */
    while(!(pUSARTHandle->pUSARTx->SR & (1 << 6)));
}

/*************************************************************
 * Send Null-Terminated String
 *************************************************************/
void USART_SendString(USART_Handle_t *pUSARTHandle,
                      char *pTxBuffer)
{
    while(*pTxBuffer)
    {
        USART_SendData(pUSARTHandle,
                       (uint8_t *)pTxBuffer,
                       1);

        pTxBuffer++;
    }
}
