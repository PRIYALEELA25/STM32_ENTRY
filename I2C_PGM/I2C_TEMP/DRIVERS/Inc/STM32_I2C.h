/*
 * STM32_I2C.h
 *
 *  Created on: Jul 2, 2026
 *      Author: hp
 */

#ifndef INC_STM32_I2C_H_
#define INC_STM32_I2C_H_


#include "STM32F446RE.h"

/*
 * Configuration structure for I2Cx peripheral
 */
typedef struct
{
    uint32_t I2C_SCLSpeed;       // Standard or Fast mode
    uint8_t  I2C_DeviceAddress;  // Slave mode address (7-bit)
    uint8_t  I2C_ACKControl;     // ACK enable/disable
    uint8_t  I2C_FMDutyCycle;    // Fast mode duty cycle
} I2C_Config_t;

/*
 * Handle structure for I2Cx peripheral
 */
typedef struct
{
    I2C_RegDef_t  *pI2Cx;        // Pointer to I2C peripheral
    I2C_Config_t  I2C_Config;   // Configuration settings

    // For interrupt-based communication
    uint8_t       *pTxBuffer;    // TX buffer pointer
    uint8_t       *pRxBuffer;    // RX buffer pointer
    uint32_t      TxLen;         // TX length
    uint32_t      RxLen;         // RX length
    uint8_t       TxRxState;     // Communication state
    uint8_t       DevAddr;       // Slave device address
    uint32_t      RxSize;        // RX size
    uint8_t       Sr;            // Repeated start value
} I2C_Handle_t;
/*
 * @I2C_SCLSpeed
 */
#define I2C_SCL_SPEED_SM       100000   // Standard mode 100kHz
#define I2C_SCL_SPEED_FM4K     400000   // Fast mode 400kHz
#define I2C_SCL_SPEED_FM2K     200000   // Fast mode 200kHz

/*
 * @I2C_ACKControl
 */
#define I2C_ACK_ENABLE         1
#define I2C_ACK_DISABLE        0

/*
 * @I2C_FMDutyCycle
 */
#define I2C_FM_DUTY_2          0        // Tlow/Thigh = 2
#define I2C_FM_DUTY_16_9       1        // Tlow/Thigh = 16/9

/*
 * I2C Status Register 1 flags
 */
#define I2C_FLAG_SB            (1 << 0)  // Start bit (Master)
#define I2C_FLAG_ADDR          (1 << 1)  // Address sent/matched
#define I2C_FLAG_BTF           (1 << 2)  // Byte transfer finished
#define I2C_FLAG_STOPF         (1 << 4)  // Stop detection (Slave)
#define I2C_FLAG_RXNE          (1 << 6)  // RX not empty
#define I2C_FLAG_TXE           (1 << 7)  // TX empty
#define I2C_FLAG_BERR          (1 << 8)  // Bus error
#define I2C_FLAG_ARLO          (1 << 9)  // Arbitration lost
#define I2C_FLAG_AF            (1 << 10) // Acknowledge failure
#define I2C_FLAG_OVR           (1 << 11) // Overrun/Underrun


/*************************************************************
 *                 APIs supported by this driver
 *************************************************************/

/*
 * Peripheral Clock Setup
 */
void I2C_PeriClockControl(I2C_RegDef_t *pI2Cx, uint8_t EnorDi);

/*
 * Init and De-init
 */
void I2C_Init(I2C_Handle_t *pI2CHandle);
void I2C_DeInit(I2C_RegDef_t *pI2Cx);

/*
 * Data Send and Receive (Master mode - Blocking)
 */
void I2C_MasterSendData(I2C_Handle_t *pI2CHandle, uint8_t *pTxBuffer, uint32_t Len, uint8_t SlaveAddr, uint8_t Sr);
void I2C_MasterReceiveData(I2C_Handle_t *pI2CHandle, uint8_t *pRxBuffer, uint32_t Len, uint8_t SlaveAddr, uint8_t Sr);

/*
 * Data Send and Receive (Master mode - Interrupt)
 */
uint8_t I2C_MasterSendDataIT(I2C_Handle_t *pI2CHandle, uint8_t *pTxBuffer, uint32_t Len, uint8_t SlaveAddr, uint8_t Sr);
uint8_t I2C_MasterReceiveDataIT(I2C_Handle_t *pI2CHandle, uint8_t *pRxBuffer, uint32_t Len, uint8_t SlaveAddr, uint8_t Sr);

/*
 * Slave mode APIs
 */
void I2C_SlaveSendData(I2C_RegDef_t *pI2Cx, uint8_t data);
uint8_t I2C_SlaveReceiveData(I2C_RegDef_t *pI2Cx);

/*
 * IRQ Configuration and ISR Handling
 */
void I2C_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void I2C_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void I2C_EV_IRQHandling(I2C_Handle_t *pI2CHandle);  // Event IRQ
void I2C_ER_IRQHandling(I2C_Handle_t *pI2CHandle);  // Error IRQ

/*
 * Other Peripheral Control APIs
 */
void I2C_PeripheralControl(I2C_RegDef_t *pI2Cx, uint8_t EnorDi);
uint8_t I2C_GetFlagStatus(I2C_RegDef_t *pI2Cx, uint32_t FlagName);
void I2C_ManageAcking(I2C_RegDef_t *pI2Cx, uint8_t EnorDi);
void I2C_GenerateStopCondition(I2C_RegDef_t *pI2Cx);
void I2C_SlaveEnableDisableCallbackEvents(I2C_RegDef_t *pI2Cx, uint8_t EnorDi);

/*
 * Application Callback
 */
void I2C_ApplicationEventCallback(I2C_Handle_t *pI2CHandle, uint8_t AppEvent);
#endif /* INC_STM32_I2C_H_ */
