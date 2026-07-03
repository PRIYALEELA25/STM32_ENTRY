/*
 * STM32GPIO_DRIVER.c
 *
 *  Created on: Jun 18, 2026
 *      Author: hp
 */


#include "STM32GPIO_DRIVER.h"
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


void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx,uint8_t ENorDI){

	 if (ENorDI == ENABLE)
	    {
	        if (pGPIOx == GPIOA)
	        {
	            GPIOA_CLK_EN();
	        }
	        else if (pGPIOx == GPIOB)
	        {
	            GPIOB_CLK_EN();
	        }
	        else if (pGPIOx == GPIOC)
	        {
	            GPIOC_CLK_EN();
	        }
	        else if (pGPIOx == GPIOD)
	        {
	            GPIOD_CLK_EN();
	        }
	        else if (pGPIOx == GPIOE)
	        {
	            GPIOE_CLK_EN();
	        }
	        else if (pGPIOx == GPIOF)
	        {
	            GPIOF_CLK_EN();
	        }
	        else if (pGPIOx == GPIOG)
	        {
	            GPIOG_CLK_EN();
	        }
	        else if (pGPIOx == GPIOH)
	        {
	            GPIOH_CLK_EN();
	        }
	    }
	    else
	    {

	        if (pGPIOx == GPIOA)
	        {
	            GPIOA_CLK_DIS();
	        }

	        else if (pGPIOx == GPIOB)
	        {
	            GPIOB_CLK_DIS();
	        }
	        else if (pGPIOx == GPIOC)
	        {
	            GPIOC_CLK_DIS();
	        }
	        else if (pGPIOx == GPIOD)
	        {
	            GPIOD_CLK_DIS();
	        }
	        else if (pGPIOx == GPIOE)
	        {
	            GPIOE_CLK_DIS();
	        }
	        else if (pGPIOx == GPIOF)
	        {
	            GPIOF_CLK_DIS();
	        }
	        else if (pGPIOx == GPIOH)
	        {
	            GPIOH_CLK_DIS();
	        }
	    }
	}




/*********************************************************************
 * @fn          - GPIO Init
 *
 * @brief       - This function initializes the given GPIO port pin
 *
 * @param[in]   - pGPIOHandle: pointer to GPIO Handle Structure
 *
 * @return      - none
 *
 * @Note        - refer macros for gpio configurations
 *********************************************************************/
void GPIO_Init(GPIO_Handle_t *pGPIOHandle )
{

	uint32_t temp=0;

 //ENABLE PERIPHERAL CLOCK
	GPIO_PeriClockControl(pGPIOHandle ->pGPIOx,ENABLE);
//CONFIGURE THE MODE
	if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <=GPIO_MODE_ANALOG)
	{
		temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode<<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER &=~(0x3 <<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
				pGPIOHandle->pGPIOx->MODER |=temp;
				temp=0;
	}
	else{

	}



	//SPEED
	temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed<<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
			pGPIOHandle->pGPIOx->OSPEEDER  &=~(0x3 <<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
			pGPIOHandle->pGPIOx->OSPEEDER |=temp;
	//PUPD
	temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinPUPDControl<<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
			pGPIOHandle->pGPIOx->PUPDR  &=~(0x3 <<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
			pGPIOHandle->pGPIOx->PUPDR |=temp;

	//OTYPER
	temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType<<pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			pGPIOHandle->pGPIOx->OTYPER  &=~(1 <<pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			pGPIOHandle->pGPIOx->OTYPER |=temp;

	//ALTFN
			if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode ==GPIO_MODE_ALTFN ){
				uint8_t temp1, temp2;
				temp1=(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)/8;
				temp2=(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)%8;
				pGPIOHandle->pGPIOx->AFR[temp1]&=~((0xf)<<(4* temp2));
				pGPIOHandle->pGPIOx->AFR[temp1]|=(pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFuncmode<<(4* temp2));
			}


}


void GPIO_DeInit(GPIO_RegDef_t *pGPIOx){

}


/*********************************************************************
 * @fn          - GPIO_ReadFromInputPin
 *
 * @brief       - Reads the value in a gpio pin
 *
 * @param[in]   - pGPIOHANDLE
 * @param[in]   - PinNumber: Pin number to read
 *
 * @return      - uint8_t value(value inside that pin)
 *********************************************************************/

uint8_t GPIO_READFROMINPUTPIN(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber){
	uint8_t value;
	        value=(uint8_t)((pGPIOx->IDR>>PinNumber) & 0x00000001);
			return value;
}


/*********************************************************************
 * @fn          - GPIO_ReadFromInputPort
 *
 * @brief       - Reads the entire input port
 *
 * @return      - 16-bit value of the port
 *********************************************************************/

uint16_t GPIO_READFROMINPUTPORT(GPIO_RegDef_t *pGPIOx){
	uint16_t value;
		value=(uint16_t)pGPIOx->IDR;
		return value;
}


/*********************************************************************
 * @fn          - GPIO_WriteToOutputPin
 *
 * @brief       - Writes to an output pin
 *
 * @param[in]   - pGPIOx: GPIO port base address
 * @param[in]   - PinNumber: Pin number to write
 * @param[in]   - Value: GPIO_PIN_SET or GPIO_PIN_RESET
 *********************************************************************/
void GPIO_WRITETOOUTPUTPIN(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber,uint8_t value){
	if(value==1){
			pGPIOx->ODR|=(1<<PinNumber);
		}
		else{
			pGPIOx->ODR &=~(1<<PinNumber);
		}
}


/*********************************************************************
 * @fn          - GPIO_WriteToOutputPort
 *
 * @brief       - Writes to entire output port
 *********************************************************************/
void GPIO_WRITETOOUTPUTPORT(GPIO_RegDef_t *pGPIOx,uint8_t value){
	pGPIOx->ODR=value;
}


/*********************************************************************
 * @fn          - GPIO_ToggleOutputPin
 *
 * @brief       - Toggles the state of an output pin
 *********************************************************************/

void GPIO_TOGGLEOUTPUTPIN(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber)
{
	pGPIOx->ODR^=(uint8_t)(1<<PinNumber);
}

