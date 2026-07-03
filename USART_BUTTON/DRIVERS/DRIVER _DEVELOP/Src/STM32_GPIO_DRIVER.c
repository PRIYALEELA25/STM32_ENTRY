/*
 * STM32_GPIO_DRIVER.c
 *
 *  Created on: Jul 1, 2026
 *      Author: hp
 */


#include "STM32_GPIO_DRIVER.h"
/*********************************************************************
 * @fn          - GPIO_PeriClockControl
 *
 * @brief       - Enables or disables peripheral clock for GPIO port
 *
 * @param[in]   - pGPIOx: GPIO port base address
 * @param[in]   - EnorDi: ENABLE or DISABLE macros
 *
 * @return      - none
 *
 * @Note        - none
 *********************************************************************/



#include "STM32_GPIO_DRIVER.h"

void GPIO_Init(GPIO_Handle_t *pGPIOHandle) {
    uint32_t temp = 0;

    // 1. Configure Mode
    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->MODER &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->MODER |= temp;

    // 2. Configure Speed
    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->OSPEEDER &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->OSPEEDER |= temp;

    // 3. Configure Pull-up/Pull-down
    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->PUPDR |= temp;

    // 4. Configure Output Type
    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOpType << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    pGPIOHandle->pGPIOx->OTYPER |= temp;

    // 5. Configure Alternate Function
    if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN) {
        uint8_t af_row = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
        uint8_t af_pos = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;
        pGPIOHandle->pGPIOx->AFR[af_row] &= ~(0xF << (4 * af_pos));
        pGPIOHandle->pGPIOx->AFR[af_row] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * af_pos));
    }
}

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value) {
    if (Value == 1) {
        pGPIOx->ODR |= (1 << PinNumber);
    } else {
        pGPIOx->ODR &= ~(1 << PinNumber);
    }
}

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber) {
    pGPIOx->ODR ^= (1 << PinNumber);
}
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
    if(EnorDi == ENABLE)
    {
        if(pGPIOx == GPIOA)
            GPIOA_CLK_EN();
        else if(pGPIOx == GPIOB)
            GPIOB_CLK_EN();
        else if(pGPIOx == GPIOC)
            GPIOC_CLK_EN();
        else if(pGPIOx == GPIOD)
            GPIOD_CLK_EN();
        else if(pGPIOx == GPIOE)
            GPIOE_CLK_EN();
        else if(pGPIOx == GPIOF)
            GPIOF_CLK_EN();
        else if(pGPIOx == GPIOG)
            GPIOG_CLK_EN();
        else if(pGPIOx == GPIOH)
            GPIOH_CLK_EN();
    }
    else
    {
        // Disable clock if required
    }
}


uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
    return (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x1);
}
