
// This file is a part of MRNIU/FreeRTOS-PortentaH7
// (https://github.com/MRNIU/FreeRTOS-PortentaH7).
//
// freertos.c for MRNIU/FreeRTOS-PortentaH7.

#include "FreeRTOS.h"
#include "cmsis_os.h"
#include "main.h"
// #include "stm32h7xx_hal_gpio.h"
#include "stm32h7xx_hal.h"
#include "stm32h7xx_hal_uart.h"
#include "task.h"
#include <stdint.h>

osThreadId_t cm4_task_handle;
const osThreadAttr_t cm4_task_attributes = {.name = "cm4_task",
                                            .priority =
                                                (osPriority_t)osPriorityNormal,
                                            .stack_size = 128 * 4};
#define mainHAL_MAX_TIMEOUT 0xFFFFFFFFUL

void StartM4DefaultTask(void *argument);

void MX_FREERTOS_Init(void);

/* Handle to the UART used to output strings. */
static UART_HandleTypeDef xUARTHandle = {0};

void MX_FREERTOS_Init(void) {
  /* This core uses the UART, so initialise it. */
  xUARTHandle.Instance = USART3;
  xUARTHandle.Init.BaudRate = 115200;
  xUARTHandle.Init.WordLength = UART_WORDLENGTH_8B;
  xUARTHandle.Init.StopBits = UART_STOPBITS_1;
  xUARTHandle.Init.Parity = UART_PARITY_NONE;
  xUARTHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  xUARTHandle.Init.Mode = UART_MODE_TX_RX;
  xUARTHandle.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  xUARTHandle.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  xUARTHandle.Init.OverSampling = UART_OVERSAMPLING_16;
  HAL_UART_Init(&xUARTHandle);
  HAL_UARTEx_SetRxFifoThreshold(&xUARTHandle, UART_RXFIFO_THRESHOLD_1_4);
  HAL_UARTEx_EnableFifoMode(&xUARTHandle);

  // setup(); //<-this line
  cm4_task_handle = osThreadNew(StartM4DefaultTask, NULL, &cm4_task_attributes);
}

void StartM4DefaultTask(void *argument) {
  GPIO_InitTypeDef GPIO_InitStructure = {
      .Pin = LED_B_Pin,
      .Mode = GPIO_MODE_OUTPUT_PP,
      .Speed = GPIO_SPEED_LOW,
  };
  HAL_GPIO_Init(LED_B_GPIO_Port, &GPIO_InitStructure);
  HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, 1);
  static const uint8_t msg[] = "Hola Mundo!";
  /* Infinite loop */
  while (1) {
    osDelay(500);
    HAL_GPIO_TogglePin(LED_B_GPIO_Port, LED_B_Pin);
    HAL_UART_Transmit(&xUARTHandle, (uint8_t *)msg, sizeof(msg),
                      mainHAL_MAX_TIMEOUT);
  }
  // loop(); //<-this line
}
