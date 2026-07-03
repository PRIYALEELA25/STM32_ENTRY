/*
 * STM32F446RE.h
 *
 *  Created on: Jun 18, 2026
 *      Author: hp
 */

#ifndef INC_STM32F446RE_H_
#define INC_STM32F446RE_H_
#define FLASH_BASEADDR            0x08000000U
#define ROM_BASEADDR              0x1FFF0000U
#define SRAM1_BASEADDR            0x20000000U
#define SRAM2_BASEADDR            0x2001C000U
#define SRAM_BASEADDR             SRAM1_BASEADDR
#include <stdint.h>

#define _vo volatile
/*
 * PERIPHERAL BUS BASE ADDRESS
 */

#define APB1PERI_BASEADDR          0x40000000U
#define APB2PERI_BASEADDR          0x40010000U
#define AHB1PERI_BASEADDR          0x40020000U
#define AHB2PERI_BASEADDR          0x50000000U
#define AHB3PERI_BASEADDR          0xA0001000U

/*
 * PERIPHERALS IN AHB1
 */

#define GPIOA_BASEADDR             (AHB1PERI_BASEADDR+0X0000)
#define GPIOB_BASEADDR             (AHB1PERI_BASEADDR+0X0400)
#define GPIOC_BASEADDR             (AHB1PERI_BASEADDR+0X0800)
#define GPIOD_BASEADDR             (AHB1PERI_BASEADDR+0X0C00)
#define GPIOE_BASEADDR             (AHB1PERI_BASEADDR+0X1000)
#define GPIOF_BASEADDR             (AHB1PERI_BASEADDR+0X1400)
#define GPIOG_BASEADDR             (AHB1PERI_BASEADDR+0X1800)
#define GPIOH_BASEADDR             (AHB1PERI_BASEADDR+0X1C00)
#define CRC_BASEADDR               (AHB1PERI_BASEADDR+0X3000)
#define RCC_BASEADDR               (AHB1PERI_BASEADDR+0X3800)



/*
 * PERIPHERALS IN AHB2
 */

#define USB_BASEADDR                0x50000000U
#define DCMI_BASEADDR               0x50050000U

/*
 * PERIPHERALS IN AHB3
 */
#define QUADSPI_BASEADDR            0xA0001000U
#define FMC_BASEADDR                0xA0000000U

/*
 * PERIPHERALS IN APB1
 */

#define TIM2_BASEADDR         (APB1PERI_BASEADDR+0x0000)
#define TIM3_BASEADDR         (APB1PERI_BASEADDR+0x0400)
#define TIM4_BASEADDR         (APB1PERI_BASEADDR+0x0800)
#define TIM5_BASEADDR         (APB1PERI_BASEADDR+0x0C00)


#define SPI2_BASEADDR        (APB1PERI_BASEADDR+0x3800)
#define SPI3_BASEADDR        (APB1PERI_BASEADDR+0x3C00)


#define USART2_BASEADDR      (APB1PERI_BASEADDR+0x4400)
#define USART3_BASEADDR      (APB1PERI_BASEADDR+0x4800)
#define UART4_BASEADDR       (APB1PERI_BASEADDR+0x4C00)
#define UART5_BASEADDR       (APB1PERI_BASEADDR+0x5000)


#define I2C1_BASEADDR        (APB1PERI_BASEADDR+0x5400)
#define I2C2_BASEADDR        (APB1PERI_BASEADDR+0x5800)
#define I2C3_BASEADDR        (APB1PERI_BASEADDR+0x5C00)


#define CAN1_BASEADDR        (APB1PERI_BASEADDR+0x6400)
#define CAN2_BASEADDR        (APB1PERI_BASEADDR+0x6800)


/*
 * PERIPHERALS IN APB2
 *
 */
#define EXTI_BASEADDR          (APB2PERI_BASEADDR+0x3C00)
#define SYSCFG_BASEADDR        (APB2PERI_BASEADDR+0c3800)
#define TIM1_BASEADDR          (APB2PERI_BASEADDR+0x0000)
#define TIM8_BASEADDR          (APB2PERI_BASEADDR+0x0400)

#define USART1_BASEADDR        (APB2PERI_BASEADDR+0x1000)
#define USART6_BASEADDR        (APB2PERI_BASEADDR+0x1400)

#define SPI1_BASEADDR          (APB2PERI_BASEADDR+0x3000)
#define SPI4_BASEADDR          (APB2PERI_BASEADDR+0x3400)

#define EXTI_BASEADDR          (APB2PERI_BASEADDR+0x3C00)

#define TIM9_BASEADDR          (APB2PERI_BASEADDR+0x4000)
#define TIM1O_BASEADDR         (APB2PERI_BASEADDR+0x4400)
#define TIM11_BASEADDR         (APB2PERI_BASEADDR+0x4800)


/*
 *GPIO REGISTER STRUCTER
 */
typedef struct
{
    _vo uint32_t MODER;
    _vo uint32_t OTYPER;
    _vo uint32_t OSPEEDER;
    _vo uint32_t PUPDR;
    _vo uint32_t IDR;
    _vo uint32_t ODR;
    _vo uint32_t BSRR;
    _vo uint32_t LCKR;
    _vo uint32_t AFR[2];
} GPIO_RegDef_t;


/*
 * EXTI REGISTER STRUCTURE
 */
typedef struct{
	_vo uint32_t IMR;
	_vo uint32_t EMR;
	_vo uint32_t RTSR;
	_vo uint32_t FTSR;
	_vo uint32_t SWIER;
	_vo uint32_t PR;



}EXTI_RegDef_t;

/*
 * SYSCONFIG REGISTER STRUCTURE
 */
typedef struct{
	_vo uint32_t MEMRMP;
	_vo uint32_t PMC;
	_vo uint32_t EXTICR[4];
	_vo uint32_t RESERVED[2];
	_vo uint32_t CMPCR;
	   uint32_t RESERVED1;
	_vo uint32_t CFGR;
}SYSCFG_RegDef_t;

/*
 * RCC REGISTER STRUCTRE
 */
typedef struct{
	    _vo uint32_t CR;
		_vo uint32_t PLLCFGR;
		_vo uint32_t CFGR ;
		_vo uint32_t CIR;
		_vo uint32_t AHB1RSTR;
		_vo uint32_t AHB2RSTR;
		_vo uint32_t AHB3RSTR;
		 uint32_t RESERVED0;
		_vo uint32_t APB1RSTR;
		_vo uint32_t APB2RSTR;
		 uint32_t RESERVED1;
		 uint32_t RESERVED2;

		_vo uint32_t AHB1ENR;
		_vo uint32_t AHB2ENR;
		_vo uint32_t AHB3ENR;
	    uint32_t RESERVED3;

		_vo uint32_t APB1ENR;
		_vo uint32_t APB2ENR;

	    uint32_t RESERVED4;
		uint32_t RESERVED5;

		_vo uint32_t AHB1LPENR;
		_vo uint32_t AHB2LPENR;
		_vo uint32_t AHB3LPENR;

		uint32_t RESERVED6;

		_vo uint32_t APB1LPENR;
		_vo uint32_t APB2LPENR;

		uint32_t RESERVED7;
		uint32_t RESERVED8;


		_vo uint32_t BDCR;
		_vo uint32_t CSR;
		uint32_t RESERVED9;
		uint32_t RESERVED10;

		_vo uint32_t SSCGR;
		_vo uint32_t PLLI2SCFGR;
		_vo uint32_t PLLSAICFGR;

	    _vo uint32_t DCKCFGR;
		_vo uint32_t CKGATENR;
		_vo uint32_t DCKCFGR2;


}RCC_RegDef_t;
/*
 * I2C REGISTER STRUCT
 */

typedef struct{

	_vo uint32_t CR1;
	_vo uint32_t CR2;
	_vo uint32_t OAR1;
	_vo uint32_t OAR2;
	_vo uint32_t DR;
	_vo uint32_t SR1;
	_vo uint32_t SR2;
	_vo uint32_t CCR;
	_vo uint32_t TRISE;
	_vo uint32_t FLTR;

}I2C_RegDef_t;

/*
 * SPI REGISTER STRUCTURE
 */

  typedef struct{
	_vo uint32_t CR1;
	_vo uint32_t CR2;
	_vo uint32_t SR;
	_vo uint32_t DR;
	_vo uint32_t CRCPR;
	_vo uint32_t TXCRCR;
	_vo uint32_t I2SCFGR;
	_vo uint32_t I2SPR;
  }SPI_RegDef_t;


/*
 * USART REGISTER STRUCTURE
 */

  typedef struct{
	_vo uint32_t SR;
	_vo uint32_t DR;
	_vo uint32_t BRR;
	_vo uint32_t CR1;
	_vo uint32_t CR2;
	_vo uint32_t CR3;
	_vo uint32_t GPTR;

  }USART_RegDef_t;
  /*
   * POINTER TO ACCESS GPIO REGISTERS
   */

#define GPIOA (GPIO_RegDef_t*)(GPIOA_BASEADDR)
#define GPIOB (GPIO_RegDef_t*)(GPIOB_BASEADDR)
#define GPIOC (GPIO_RegDef_t*)(GPIOC_BASEADDR)
#define GPIOD (GPIO_RegDef_t*)(GPIOD_BASEADDR)
#define GPIOE (GPIO_RegDef_t*)(GPIOE_BASEADDR)
#define GPIOF (GPIO_RegDef_t*)(GPIOF_BASEADDR)
#define GPIOG (GPIO_RegDef_t*)(GPIOG_BASEADDR)
#define GPIOH (GPIO_RegDef_t*)(GPIOH_BASEADDR)


/*
 * POINTER TO ACCESS SPI REGISTER
 */
#define SPI1 (SPI_RegDef_t*)(SPI1_BASEADDR)
#define SPI4 (SPI_RegDef_t*)(SPI4_BASEADDR)
/*
 * POINTER TO ACCESS I2C REGISTER
 */
#define I2C1 (I2C_RegDef_t*)(I2C1_BASEADDR)
#define I2C2 (I2C_RegDef_t*)(I2C2_BASEADDR)
#define I2C3 (I2C_RegDef_t*)(I2C3_BASEADDR)

 /*
  * POINTER TO ACCESS USART
  */
#define USART1 (USART_RegDef_t*)USART1_BASEADDR
#define USART2 (USART_RegDef_t*)USART1_BASEADDR
#define USART3 (USART_RegDef_t*)USART1_BASEADDR
#define USART4 (USART_RegDef_t*)USART1_BASEADDR
#define USART5 (USART_RegDef_t*)USART1_BASEADDR
#define USART6 (USART_RegDef_t*)USART1_BASEADDR
/*
 * POINTER TO ACCESS RCC REIGISTER
 */

#define RCC  ((RCC_RegDef_t*)RCC_BASEADDR)

  /*
   * AHB1 CLOCK ENABLE
   */

#define GPIOA_CLK_EN()    (RCC->AHB1ENR|=(1<<0))
#define GPIOB_CLK_EN()    (RCC->AHB1ENR|=(1<<1))
#define GPIOC_CLK_EN()    (RCC->AHB1ENR|=(1<<2))
#define GPIOD_CLK_EN()    (RCC->AHB1ENR|=(1<<3))
#define GPIOE_CLK_EN()    (RCC->AHB1ENR|=(1<<4))
#define GPIOF_CLK_EN()    (RCC->AHB1ENR|=(1<<5))
#define GPIOG_CLK_EN()    (RCC->AHB1ENR|=(1<<6))
#define GPIOH_CLK_EN()    (RCC->AHB1ENR|=(1<<7))


  /*
   * AHB1 CLOCK DISABLE
   */
#define GPIOA_CLK_DIS()   (RCC->AHB1ENR&=~(1<<0))
#define GPIOB_CLK_DIS()   (RCC->AHB1ENR&=~(1<<1))
#define GPIOC_CLK_DIS()   (RCC->AHB1ENR&=~(1<<2))
#define GPIOD_CLK_DIS()   (RCC->AHB1ENR&=~(1<<3))
#define GPIOE_CLK_DIS()   (RCC->AHB1ENR&=~(1<<4))
#define GPIOF_CLK_DIS()   (RCC->AHB1ENR&=~(1<<5))
#define GPIOG_CLK_DIS()   (RCC->AHB1ENR&=~(1<<6))
#define GPIOH_CLK_DIS()   (RCC->AHB1ENR&=~(1<<7))


/*
   * USART CLOCK ENABLE
   */

  #define USART1_CLK_EN()   (RCC->APB2ENR |= (1 << 4))
  #define USART6_CLK_EN()   (RCC->APB2ENR |= (1 << 5))

  #define USART2_CLK_EN()   (RCC->APB1ENR |= (1 << 17))
  #define USART3_CLK_EN()   (RCC->APB1ENR |= (1 << 18))
  #define UART4_CLK_EN()    (RCC->APB1ENR |= (1 << 19))
  #define UART5_CLK_EN()    (RCC->APB1ENR |= (1 << 20))

  /*
   * USART CLOCK DISABLE
   */

  #define USART1_CLK_DIS()   (RCC->APB2ENR &= ~(1 << 4))
  #define USART6_CLK_DIS()   (RCC->APB2ENR &= ~(1 << 5))

  #define USART2_CLK_DIS()   (RCC->APB1ENR &= ~(1 << 17))
  #define USART3_CLK_DIS()   (RCC->APB1ENR &= ~(1 << 18))
  #define UART4_CLK_DIS()    (RCC->APB1ENR &= ~(1 << 19))
  #define UART5_CLK_DIS()    (RCC->APB1ENR &= ~(1 << 20))

#define ENABLE           1
#define DISABLE          0



#endif /* INC_STM32F446RE_H_ */
