/*
 * STM32_SPI_DRIVER.c
 *
 *  Created on: Jul 2, 2026
 *      Author: hp
 */

#include"STM32_SPI_DRIVER.h"

void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
    if (EnorDi == ENABLE)
    {
        if (pSPIx == SPI1)
        {
            SPI1_CLK_EN();
        }
        else if (pSPIx == SPI2)
        {
            SPI2_CLK_EN();
        }
        else if (pSPIx == SPI3)
        {
            SPI3_CLK_EN();
        }
    }
    else
    {
        if (pSPIx == SPI1)
        {
            SPI1_CLK_DIS();
        }
        else if (pSPIx == SPI2)
        {
            SPI2_CLK_DIS();
        }
        else if (pSPIx == SPI3)
        {
            SPI3_CLK_DIS();
        }
    }
}


void SPI_Init(SPI_Handle_t *pSPIHandle)
{
    // Enable peripheral clock first!
    SPI_PeriClockControl(pSPIHandle->pSPIx, ENABLE);

    uint32_t tempreg = 0;

    // 1. Configure device mode (Master/Slave)
    tempreg |= (pSPIHandle->SPIConfig.SPI_DeviceMode << 2);

    // 2. Configure bus config
    if (pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_FD)
    {
        // Full duplex: BIDIMODE = 0
        tempreg &= ~(1 << 15);
    }
    else if (pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_HD)
    {
        // Half duplex: BIDIMODE = 1
        tempreg |= (1 << 15);
    }
    else if (pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_SIMPLEX_RX)
    {
        // Simplex RX: BIDIMODE = 0, RXONLY = 1
        tempreg &= ~(1 << 15);
        tempreg |= (1 << 10);
    }

    // 3. Configure clock speed (baud rate)
    tempreg |= (pSPIHandle->SPIConfig.SPI_SclkSpeed << 3);

    // 4. Configure DFF (data frame format)
    tempreg |= (pSPIHandle->SPIConfig.SPI_DFF << 11);

    // 5. Configure CPOL
    tempreg |= (pSPIHandle->SPIConfig.SPI_CPOL << 1);

    // 6. Configure CPHA
    tempreg |= (pSPIHandle->SPIConfig.SPI_CPHA << 0);

    // 7. Configure SSM
    tempreg |= (pSPIHandle->SPIConfig.SPI_SSM << 9);

    // Write to CR1 register
    pSPIHandle->pSPIx->CR1 = tempreg;
}



void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len)
{
    while (Len > 0)
    {
        // 1. Wait until TXE is set (TX buffer empty)
        while (!(pSPIx->SR & SPI_TXE_FLAG));

        // 2. Check DFF bit in CR1
        if (pSPIx->CR1 & (1 << 11))
        {
            // 16-bit DFF
            pSPIx->DR = *((uint16_t*)pTxBuffer);
            Len -= 2;
            (uint16_t*)pTxBuffer++;
        }
        else
        {
            // 8-bit DFF
            pSPIx->DR = *pTxBuffer;
            Len--;
            pTxBuffer++;
        }
    }
}




void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len)
{
    while (Len > 0)
    {
        // 1. Wait until RXNE is set (RX buffer not empty)
        while (!(pSPIx->SR & SPI_RXNE_FLAG));

        // 2. Check DFF bit in CR1
        if (pSPIx->CR1 & (1 << 11))
        {
            // 16-bit DFF
            *((uint16_t*)pRxBuffer) = pSPIx->DR;
            Len -= 2;
            (uint16_t*)pRxBuffer++;
        }
        else
        {
            // 8-bit DFF
            *pRxBuffer = pSPIx->DR;
            Len--;
            pRxBuffer++;
        }
    }
}




// Get flag status from SR register
uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx, uint32_t FlagName)
{
    if (pSPIx->SR & FlagName)
    {
        return FLAG_SET;
    }
    return FLAG_RESET;
}

// Enable/Disable SPI peripheral
void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
    if (EnorDi == ENABLE)
    {
        pSPIx->CR1 |= (1 << 6);  // Set SPE bit
    }
    else
    {
        pSPIx->CR1 &= ~(1 << 6); // Clear SPE bit
    }
}

// Configure SSI bit (for software slave management)
void SPI_SSIConfig(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
    if (EnorDi == ENABLE)
    {
        pSPIx->CR1 |= (1 << 8);
    }
    else
    {
        pSPIx->CR1 &= ~(1 << 8);
    }
}
