/*
 * STM32F446RE.h
 *
 *  Created on: Jul 1, 2026
 *      Author: hp
 */

#ifndef INC_STM32F446RE_H_
#define INC_STM32F446RE_H_

#include <stdint.h>

#define _vo volatile

/* Memory Base Addresses */
#define FLASH_BASEADDR            0x08000000U
#define ROM_BASEADDR              0x1FFF0000U
#define SRAM1_BASEADDR            0x20000000U
#define SRAM2_BASEADDR            0x2001C000U
#define SRAM_BASEADDR             SRAM1_BASEADDR
/*
 * PERIPHERAL BUS BASE ADDRESS
 */

#define APB1PERI_BASEADDR          0x40000000U
#define APB2PERI_BASEADDR          0x40010000U
#define AHB1PERI_BASEADDR          0x40020000U
#define AHB2PERI_BASEADDR          0x50000000U
#define AHB3PERI_BASEADDR          0xA0001000U



/* PERIPHERALS IN AHB1*/
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



/* USART Base Addresses */
#define USART2_BASEADDR            (APB1PERI_BASEADDR + 0x4400)

/* Register Structures */
typedef struct {
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

typedef struct {
    _vo uint32_t CR;
    _vo uint32_t PLLCFGR;
    _vo uint32_t CFGR;
    _vo uint32_t CIR;
    _vo uint32_t AHB1RSTR;
    _vo uint32_t AHB2RSTR;
    _vo uint32_t AHB3RSTR;
    uint32_t      RESERVED0;
    _vo uint32_t APB1RSTR;
    _vo uint32_t APB2RSTR;
    uint32_t      RESERVED1[2];
    _vo uint32_t AHB1ENR;
    _vo uint32_t AHB2ENR;
    _vo uint32_t AHB3ENR;
    uint32_t      RESERVED2;
    _vo uint32_t APB1ENR;
    _vo uint32_t APB2ENR;
} RCC_RegDef_t;

typedef struct {
    _vo uint32_t SR;
    _vo uint32_t DR;
    _vo uint32_t BRR;
    _vo uint32_t CR1;
    _vo uint32_t CR2;
    _vo uint32_t CR3;
    _vo uint32_t GPTR;
} USART_RegDef_t;

/* Peripheral Pointers */
#define GPIOA               ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB               ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC               ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD               (GPIO_RegDef_t*)(GPIOD_BASEADDR)
#define GPIOE               (GPIO_RegDef_t*)(GPIOE_BASEADDR)
#define GPIOF               (GPIO_RegDef_t*)(GPIOF_BASEADDR)
#define GPIOG               (GPIO_RegDef_t*)(GPIOG_BASEADDR)
#define GPIOH               (GPIO_RegDef_t*)(GPIOH_BASEADDR)


#define RCC                 ((RCC_RegDef_t*)RCC_BASEADDR)
#define USART2              ((USART_RegDef_t*)USART2_BASEADDR)

/* Clock Enable Macros */
#define GPIOA_CLK_EN()      (RCC->AHB1ENR |= (1 << 0))
#define GPIOB_CLK_EN()      (RCC->AHB1ENR |= (1 << 1))
#define GPIOC_CLK_EN()      (RCC->AHB1ENR |= (1 << 2))
#define GPIOD_CLK_EN()      (RCC->AHB1ENR |= (1 << 3))
#define GPIOE_CLK_EN()      (RCC->AHB1ENR |= (1 << 4))
#define GPIOF_CLK_EN()      (RCC->AHB1ENR |= (1 << 5))
#define GPIOG_CLK_EN()      (RCC->AHB1ENR |= (1 << 6))
#define GPIOH_CLK_EN()      (RCC->AHB1ENR |= (1 << 7))
#define USART2_CLK_EN()     (RCC->APB1ENR |= (1 << 17))


#define USART2_CLK_DIS()   (RCC->APB1ENR &= ~(1 << 17))

#define ENABLE   1
#define DISABLE  0
#endif /* INC_STM32F446RE_H_ */
