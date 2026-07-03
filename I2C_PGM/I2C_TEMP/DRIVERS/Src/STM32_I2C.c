/*
 * STM32_I2C.c
 *
 *  Created on: Jul 2, 2026
 *      Author: hp
 */
#include "STM32F446RE.h"
#include "STM32_I2C.h"

/************************************************************
 * Peripheral Clock Control
 ************************************************************/
void I2C_PeriClockControl(I2C_RegDef_t *pI2Cx, uint8_t EnorDi)
{
    if(EnorDi == ENABLE)
    {
        if(pI2Cx == I2C1)
            RCC->APB1ENR |= (1 << 21);
        else if(pI2Cx == I2C2)
            RCC->APB1ENR |= (1 << 22);
        else if(pI2Cx == I2C3)
            RCC->APB1ENR |= (1 << 23);
    }
    else
    {
        if(pI2Cx == I2C1)
            RCC->APB1ENR &= ~(1 << 21);
        else if(pI2Cx == I2C2)
            RCC->APB1ENR &= ~(1 << 22);
        else if(pI2Cx == I2C3)
            RCC->APB1ENR &= ~(1 << 23);
    }
}

/*
 * I2C Init
 ***/
void I2C_Init(I2C_Handle_t *pI2CHandle)
{
    uint32_t temp = 0;

    I2C_PeriClockControl(pI2CHandle->pI2Cx, ENABLE);

    /******** ACK CONTROL ********/
    temp = pI2CHandle->I2C_Config.I2C_ACKControl;
    pI2CHandle->pI2Cx->CR1 |= (temp << 10);

    /******** FREQ SET ********/
    pI2CHandle->pI2Cx->CR2 |= 16; // 16MHz APB1 assumed

    /******** DEVICE ADDRESS ********/
    temp = pI2CHandle->I2C_Config.I2C_DeviceAddress << 1;
    pI2CHandle->pI2Cx->OAR1 = temp;

    /******** CCR CALC (Standard Mode 100KHz) ********/
    uint32_t ccr_value = 80; // simplified for 16MHz

    pI2CHandle->pI2Cx->CCR = ccr_value;

    /******** TRISE ********/
    pI2CHandle->pI2Cx->TRISE = 17;

    /******** ENABLE I2C ********/
    pI2CHandle->pI2Cx->CR1 |= (1 << 0);
}

/**
 * Generate START Condition
 */
static void I2C_GenerateStartCondition(I2C_RegDef_t *pI2Cx)
{
    pI2Cx->CR1 |= (1 << 8);

    // wait until SB is set
    while(!(pI2Cx->SR1 & (1 << 0)));
}

/*
 * Generate STOP Condition
 */
void I2C_GenerateStopCondition(I2C_RegDef_t *pI2Cx)
{
    pI2Cx->CR1 |= (1 << 9);
}

/*
 * Send Address
 */
static void I2C_ExecuteAddressPhaseWrite(I2C_RegDef_t *pI2Cx, uint8_t SlaveAddr)
{
    SlaveAddr = SlaveAddr << 1;
    SlaveAddr &= ~(1); // write

    pI2Cx->DR = SlaveAddr;

    while(!(pI2Cx->SR1 & (1 << 1))); // ADDR flag

    (void)pI2Cx->SR1;
    (void)pI2Cx->SR2;
}

static void I2C_ExecuteAddressPhaseRead(I2C_RegDef_t *pI2Cx, uint8_t SlaveAddr)
{
    SlaveAddr = (SlaveAddr << 1) | 1; // read

    pI2Cx->DR = SlaveAddr;

    while(!(pI2Cx->SR1 & (1 << 1)));

    (void)pI2Cx->SR1;
    (void)pI2Cx->SR2;
}

/*
 * Master Send Data
 **/
void I2C_MasterSendData(I2C_Handle_t *pI2CHandle,
                        uint8_t *pTxBuffer,
                        uint32_t Len,
                        uint8_t SlaveAddr,
                        uint8_t Sr)
{
    I2C_GenerateStartCondition(pI2CHandle->pI2Cx);

    I2C_ExecuteAddressPhaseWrite(pI2CHandle->pI2Cx, SlaveAddr);

    while(Len > 0)
    {
        while(!(pI2CHandle->pI2Cx->SR1 & (1 << 7))); // TXE

        pI2CHandle->pI2Cx->DR = *pTxBuffer;
        pTxBuffer++;
        Len--;
    }

    while(!(pI2CHandle->pI2Cx->SR1 & (1 << 2))); // BTF

    if(Sr == 0)
    {
        I2C_GenerateStopCondition(pI2CHandle->pI2Cx);
    }
}

/****
 * Master Receive Data
 **/
void I2C_MasterReceiveData(I2C_Handle_t *pI2CHandle,
                           uint8_t *pRxBuffer,
                           uint32_t Len,
                           uint8_t SlaveAddr,
                           uint8_t Sr)
{
    I2C_GenerateStartCondition(pI2CHandle->pI2Cx);

    I2C_ExecuteAddressPhaseRead(pI2CHandle->pI2Cx, SlaveAddr);

    if(Len == 1)
    {
        pI2CHandle->pI2Cx->CR1 &= ~(1 << 10); // no ACK
        I2C_GenerateStopCondition(pI2CHandle->pI2Cx);

        while(!(pI2CHandle->pI2Cx->SR1 & (1 << 6)));

        *pRxBuffer = pI2CHandle->pI2Cx->DR;
    }

    if(Len > 1)
    {
        for(uint32_t i = Len; i > 0; i--)
        {
            if(i == 2)
            {
                pI2CHandle->pI2Cx->CR1 &= ~(1 << 10);
                I2C_GenerateStopCondition(pI2CHandle->pI2Cx);
            }

            while(!(pI2CHandle->pI2Cx->SR1 & (1 << 6)));

            *pRxBuffer = pI2CHandle->pI2Cx->DR;
            pRxBuffer++;
        }
    }

    if(pI2CHandle->I2C_Config.I2C_ACKControl == I2C_ACK_ENABLE)
    {
        pI2CHandle->pI2Cx->CR1 |= (1 << 10);
    }
}


