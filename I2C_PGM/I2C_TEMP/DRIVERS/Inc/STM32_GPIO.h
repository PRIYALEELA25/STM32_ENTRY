/*
 * STM32_GPIO.h
 *
 *  Created on: Jul 2, 2026
 *      Author: hp
 */

#ifndef INC_STM32_GPIO_H_
#define INC_STM32_GPIO_H_


#include "STM32F446RE.h"



/*
 * configuration structure for gpio pin
 */
typedef struct{
	uint8_t GPIO_PinNumber;//0-15
	uint8_t GPIO_PinMode;//input  or output
	uint8_t GPIO_PinSpeed;//speed
	uint8_t GPIO_PinPUPDControl;//pull up or pull down
	uint8_t GPIO_PinOPType;//output type push pull or open drain
	uint8_t GPIO_PinAltFuncmode; //alternate function
}GPIO_PinConfig_t;

/*
 * handle structure for a gpio pin
 */
typedef struct{
	GPIO_RegDef_t *pGPIOx; //pointer to the gpio port base address
	GPIO_PinConfig_t GPIO_PinConfig;// pin configuration settings
}GPIO_Handle_t;

#define GPIO_PIN_NO_0            0
#define GPIO_PIN_NO_1            1
#define GPIO_PIN_NO_2            2
#define GPIO_PIN_NO_3            3
#define GPIO_PIN_NO_4            4
#define GPIO_PIN_NO_5            5
#define GPIO_PIN_NO_6            6
#define GPIO_PIN_NO_7            7
#define GPIO_PIN_NO_8            8
#define GPIO_PIN_NO_9            9
#define GPIO_PIN_NO_10           10
#define GPIO_PIN_NO_11           11
#define GPIO_PIN_NO_12           12
#define GPIO_PIN_NO_13           13
#define GPIO_PIN_NO_14           14
#define GPIO_PIN_NO_15           15

/*
 *MACROS FOR GPIO MODES
 */
#define GPIO_MODE_IN             0       /* IN ,VALUE 00*/
#define GPIO_MODE_OUT            1       /* OUT ,VALUE 01*/
#define GPIO_MODE_ALTFN          2       /* ALTFN ,VALUE 10*/
#define GPIO_MODE_ANALOG         3       /* ANALOG ,VALUE 11*/


/*
 * MACROS FOR SPEED
 */
#define GPIO_SPEED_LOW           0        /* LOW ,VALUE 00*/
#define GPIO_SPEED_MEDIUM        1         /* MEDIUM ,VALUE 01*/
#define GPIO_SPEED_FAST          2           /* FAST ,VALUE 10*/
#define GPIO_SPEED_HIGH          3            /* HIGH,VALUE 11*/

/*
 * MACROS FOR OUTPUT TYPE
 */
#define GPIO_OTYPE_PUSHPULL      0        /*PUSHPULL,VALUE 00*/
#define GPIO_OTYPE_OPENDRAIN     1         /*OPEN DRAIN, VALUE 01*/

/*
 * GPIO PULL UP OR PULL DOWN MACROS
 */
#define GPIO_PUPDR_NO_PULL_UP     0       /*   NO PULL UP, VALUE 00*/
#define GPIO_PUPDR_PULL_UP        1       /*  PULL UP,VALUE 01*/
#define GPIO_PUPDR_PULL_DOWN      2       /* PULL DOWN, VALUE 10*/

/*
 * FUNCTIONS
 */

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx,uint8_t ENorDIS);

void GPIO_Init(GPIO_Handle_t *pGPIOHandle );

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

uint8_t GPIO_READFROMINPUTPIN(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber);
uint16_t GPIO_READFROMINPUTPORT(GPIO_RegDef_t *pGPIOx);

void GPIO_WRITETOOUTPUTPIN(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber,uint8_t value);

void GPIO_WRITETOOUTPUTPORT(GPIO_RegDef_t *pGPIOx,uint8_t value);

void GPIO_TOGGLEOUTPUTPIN(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber);






#endif /* INC_STM32_GPIO_H_ */
