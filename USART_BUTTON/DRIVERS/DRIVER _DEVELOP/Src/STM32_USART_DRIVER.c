/*
 * STM32_USART_DRIVER.c
 *
 *  Created on: Jul 1, 2026
 *      Author: hp
 */






#include "STM32_USART_DRIVER.h"

void USART_Init(USART_Handle_t *pUSARTHandle) {
    uint32_t tempreg = 0;

    // 1. Enable Configuration Mode (TX/RX)
    if (pUSARTHandle->USART_Config.USART_Mode == USART_MODE_ONLY_TX) {
        tempreg |= (1 << 3); // TE Bit
    } else if (pUSARTHandle->USART_Config.USART_Mode == USART_MODE_TXRX) {
        tempreg |= (1 << 3) | (1 << 2); // TE and RE Bits
    }
    pUSARTHandle->pUSARTx->CR1 |= tempreg;

    // 2. Configure Word Length (M bit)
    pUSARTHandle->pUSARTx->CR1 &= ~(1 << 12);

    // 3. Configure Stop Bits
    pUSARTHandle->pUSARTx->CR2 &= ~(0x3 << 12);

    // 4. Baud Rate Generation (Assuming standard 16 MHz HSI Clock source)
    // Formula: SystemClock / (16 * Baud) -> 16000000 / (16 * 115200) = 8.6805

    if (pUSARTHandle->USART_Config.USART_Baud == USART_STD_BAUD_115200) {
        pUSARTHandle->pUSARTx->BRR = 0x008B;
    }
}

void USART_PeripheralControl(USART_RegDef_t *pUSARTx, uint8_t EnOrDis) {
    if (EnOrDis == 1) {
        pUSARTx->CR1 |= (1 << 13); // UE Bit On
    } else {
        pUSARTx->CR1 &= ~(1 << 13); // UE Bit Off
    }
}

void USART_SendData(USART_Handle_t *pUSARTHandle, uint8_t *pTxBuffer, uint32_t Len) {
    for (uint32_t i = 0; i < Len; i++) {
        // Wait until Transmit Data Register is empty (TXE bit 7 in SR)
        while (!(pUSARTHandle->pUSARTx->SR & (1 << 7)));

        // Write byte payload
        pUSARTHandle->pUSARTx->DR = (*pTxBuffer & 0xFF);
        pTxBuffer++;
    }
}

void USART_SendString(USART_Handle_t *pUSARTHandle, char *pTxBuffer) {
    while (*pTxBuffer) {
        while (!(pUSARTHandle->pUSARTx->SR & (1 << 7)));
        pUSARTHandle->pUSARTx->DR = (*pTxBuffer & 0xFF);
        pTxBuffer++;
    }
}
