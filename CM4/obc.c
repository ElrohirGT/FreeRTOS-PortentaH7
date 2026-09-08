#include "debug.h"
#include "i2c.h"
#include "usart.h"
#include <obc.h>

#define QTZ_OBC_DEBUG_PREFIX "[OBC-IT]"

void QTZ_OBC_ArmInterrupts() {
  if (HAL_I2C_Slave_Receive_IT(&hi2c1, GLOBAL_CTX.i2c.rx.data,
                               GLOBAL_CTX.i2c.rx.capacity) != HAL_OK) {
    QTZ_Debug_Error(QTZ_OBC_DEBUG_PREFIX
                    "Failed to arm the I2C slave receive!");
    GLOBAL_CTX.state = QTZ_OBC_STATE_ERROR;
  }
  if (HAL_UART_Receive_IT(&huart4, GLOBAL_CTX.uart_rs485.rx.data,
                          GLOBAL_CTX.uart_rs485.rx.capacity) != HAL_OK) {
    QTZ_Debug_Error(QTZ_OBC_DEBUG_PREFIX
                    "Failed to arm the I2C slave receive!");
    GLOBAL_CTX.state = QTZ_OBC_STATE_ERROR;
  }
}
