/*
 * STM32_UART.h
 *
 *  Created on: Jul 2, 2026
 *      Author: hp
 */

#ifndef INC_STM32_UART_H_
#define INC_STM32_UART_H_





#include "STM32F446RE.h"

typedef struct {
    uint32_t USART_Baud;
    uint8_t  USART_Mode;
    uint8_t  USART_NoOfStopBits;
    uint8_t  USART_WordLength;
    uint8_t  USART_ParityControl;
    uint8_t  USART_HWFlowControl;
} USART_Config_t;
/*
 * Handle structure for USARTx peripheral
 */
typedef struct
{
    USART_RegDef_t *pUSARTx;
    USART_Config_t USART_Config;


    // For interrupt-based communication
    uint8_t        *pTxBuffer;    // TX buffer pointer
    uint8_t        *pRxBuffer;    // RX buffer pointer
    uint32_t       TxLen;         // TX length
    uint32_t       RxLen;         // RX length
    uint8_t        TxBusyState;   // TX state
    uint8_t        RxBusyState;   // RX state
} USART_Handle_t;



/* Configuration Macros */

#define USART_STD_BAUD_1200     1200
#define USART_STD_BAUD_2400     2400
#define USART_STD_BAUD_9600     9600
#define USART_STD_BAUD_19200    19200
#define USART_STD_BAUD_38400    38400
#define USART_STD_BAUD_57600    57600
#define USART_STD_BAUD_115200   115200
#define USART_STD_BAUD_230400   230400
#define USART_STD_BAUD_460800   460800
#define USART_STD_BAUD_921600   921600

#define USART_MODE_ONLY_TX         0
#define USART_MODE_ONLY_RX    1
#define USART_MODE_TXRX            2



#define USART_STOPBITS_1       0
#define USART_STOPBITS_0_5     1
#define USART_STOPBITS_2       2
#define USART_STOPBITS_1_5     3


/*
 * @USART_WordLength
 */
#define USART_WORDLEN_8BITS    0
#define USART_WORDLEN_9BITS    1


/*
 * @USART_ParityControl
 */
#define USART_PARITY_DISABLE   0
#define USART_PARITY_EN_EVEN   1
#define USART_PARITY_EN_ODD    2

/*
 * @USART_HWFlowControl
 */
#define USART_HW_FLOW_CTRL_NONE     0
#define USART_HW_FLOW_CTRL_CTS      1
#define USART_HW_FLOW_CTRL_RTS      2
#define USART_HW_FLOW_CTRL_CTS_RTS  3


/* Driver APIs */
void USART_Init(USART_Handle_t *pUSARTHandle);
void USART_PeripheralControl(USART_RegDef_t *pUSARTx, uint8_t EnOrDis);
void USART_SendData(USART_Handle_t *pUSARTHandle, uint8_t *pTxBuffer, uint32_t Len);
void USART_SendString(USART_Handle_t *pUSARTHandle, char *pTxBuffer);





#endif /* INC_STM32_UART_H_ */
