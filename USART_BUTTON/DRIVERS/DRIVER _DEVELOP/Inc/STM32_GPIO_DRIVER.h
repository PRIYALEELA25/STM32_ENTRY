/*
 * STM32_GPIO_DRIVER.h
 *
 *  Created on: Jul 1, 2026
 *      Author: hp
 */

#ifndef INC_STM32_GPIO_DRIVER_H_
#define INC_STM32_GPIO_DRIVER_H_


#include "STM32F446RE.h"

/*
 *
 * GPIO PIN NUMBERS
 *
 */

#define GPIO_PIN_0     0
#define GPIO_PIN_1     1
#define GPIO_PIN_2     2
#define GPIO_PIN_3     3
#define GPIO_PIN_4     4
#define GPIO_PIN_5     5
#define GPIO_PIN_6     6
#define GPIO_PIN_7     7
#define GPIO_PIN_8     8
#define GPIO_PIN_9     9
#define GPIO_PIN_10    10
#define GPIO_PIN_11    11
#define GPIO_PIN_12    12
#define GPIO_PIN_13    13
#define GPIO_PIN_14    14
#define GPIO_PIN_15    15


/*
 * GPIO MODE
 */

#define GPIO_MODE_INPUT          0
#define GPIO_MODE_OUTPUT         1
#define GPIO_MODE_ALTFN          2
#define GPIO_MODE_ANALOG         3
#define GPIO_MODE_IT_FT          4   // Falling edge interrupt
#define GPIO_MODE_IT_RT          5   // Rising edge interrupt
#define GPIO_MODE_IT_RFT         6   // Rising + Falling


/*
 * OUTPUT TYPES
 */

#define GPIO_OP_TYPE_PP          0   // Push pull
#define GPIO_OP_TYPE_OD          1   // Open drain


/*
 * SPEED
 */

#define GPIO_SPEED_LOW           0
#define GPIO_SPEED_MEDIUM        1
#define GPIO_SPEED_FAST          2
#define GPIO_SPEED_HIGH          3


/*
 * PULL UP / DOWN
 */

#define GPIO_NO_PUPD             0
#define GPIO_PIN_PU              1
#define GPIO_PIN_PD              2


/*
 * GPIO PIN STATE
 */

#define GPIO_PIN_SET             1
#define GPIO_PIN_RESET           0


/*
 * GPIO CONFIG STRUCTURE
 */

typedef struct
{
    uint8_t GPIO_PinNumber;        // 0 - 15
    uint8_t GPIO_PinMode;          // input/output/alt/interrupt
    uint8_t GPIO_PinSpeed;         // speed
    uint8_t GPIO_PinPuPdControl;   // pull-up / pull-down
    uint8_t GPIO_PinOpType;        // push-pull / open-drain
    uint8_t GPIO_PinAltFunMode;    // AF mode (0–15)
} GPIO_PinConfig_t;


/*
 * GPIO HANDLE STRUCTURE
 */

typedef struct
{
    GPIO_RegDef_t *pGPIOx;
    GPIO_PinConfig_t GPIO_PinConfig;
} GPIO_Handle_t;


/*
 * DRIVER APIs
 */

/* Clock control */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx,uint8_t ENorDIS);


/* Init / De-init */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/* Data read/write */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/* Interrupt */
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t ENorDI);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void GPIO_IRQHandling(uint8_t PinNumber);



#endif /* INC_STM32_GPIO_DRIVER_H_ */
