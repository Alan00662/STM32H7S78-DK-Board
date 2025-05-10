/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    xspi.c
  * @brief   This file provides code for the configuration
  *          of the XSPI instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "xspi.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

XSPI_HandleTypeDef hxspi1;

/* XSPI1 init function */
void MX_XSPI1_Init(void)
{

  /* USER CODE BEGIN XSPI1_Init 0 */

  /* USER CODE END XSPI1_Init 0 */

  XSPIM_CfgTypeDef sXspiManagerCfg = {0};

  /* USER CODE BEGIN XSPI1_Init 1 */

  /* USER CODE END XSPI1_Init 1 */
  hxspi1.Instance = XSPI1;
  hxspi1.Init.FifoThresholdByte = 2;
  hxspi1.Init.MemoryMode = HAL_XSPI_SINGLE_MEM;
  hxspi1.Init.MemoryType = HAL_XSPI_MEMTYPE_APMEM_16BITS;
  hxspi1.Init.MemorySize = HAL_XSPI_SIZE_32GB;
  hxspi1.Init.ChipSelectHighTimeCycle = 1;
  hxspi1.Init.FreeRunningClock = HAL_XSPI_FREERUNCLK_DISABLE;
  hxspi1.Init.ClockMode = HAL_XSPI_CLOCK_MODE_0;
  hxspi1.Init.WrapSize = HAL_XSPI_WRAP_32_BYTES;
  hxspi1.Init.ClockPrescaler = 0;
  hxspi1.Init.SampleShifting = HAL_XSPI_SAMPLE_SHIFT_NONE;
  hxspi1.Init.DelayHoldQuarterCycle = HAL_XSPI_DHQC_ENABLE;
  hxspi1.Init.ChipSelectBoundary = HAL_XSPI_BONDARYOF_8KB;
  hxspi1.Init.MaxTran = 0;
  hxspi1.Init.Refresh = 0;
  hxspi1.Init.MemorySelect = HAL_XSPI_CSSEL_NCS1;
  if (HAL_XSPI_Init(&hxspi1) != HAL_OK)
  {
    Error_Handler();
  }
  sXspiManagerCfg.nCSOverride = HAL_XSPI_CSSEL_OVR_NCS1;
  sXspiManagerCfg.IOPort = HAL_XSPIM_IOPORT_1;
  if (HAL_XSPIM_Config(&hxspi1, &sXspiManagerCfg, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN XSPI1_Init 2 */

  /* USER CODE END XSPI1_Init 2 */

}

void HAL_XSPI_MspInit(XSPI_HandleTypeDef* xspiHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  if(xspiHandle->Instance==XSPI1)
  {
  /* USER CODE BEGIN XSPI1_MspInit 0 */

  /* USER CODE END XSPI1_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_XSPI1;
    PeriphClkInit.Xspi1ClockSelection = RCC_XSPI1CLKSOURCE_PLL2S;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }

    /* XSPI1 clock enable */
    __HAL_RCC_XSPIM_CLK_ENABLE();
    __HAL_RCC_XSPI1_CLK_ENABLE();

    __HAL_RCC_GPIOO_CLK_ENABLE();
    __HAL_RCC_GPIOP_CLK_ENABLE();
    /**XSPI1 GPIO Configuration
    PO3     ------> XSPIM_P1_DQS1
    PP10     ------> XSPIM_P1_IO10
    PP12     ------> XSPIM_P1_IO12
    PP14     ------> XSPIM_P1_IO14
    PP2     ------> XSPIM_P1_IO2
    PP5     ------> XSPIM_P1_IO5
    PO2     ------> XSPIM_P1_DQS0
    PP1     ------> XSPIM_P1_IO1
    PP11     ------> XSPIM_P1_IO11
    PP15     ------> XSPIM_P1_IO15
    PP3     ------> XSPIM_P1_IO3
    PP0     ------> XSPIM_P1_IO0
    PP7     ------> XSPIM_P1_IO7
    PP8     ------> XSPIM_P1_IO8
    PP13     ------> XSPIM_P1_IO13
    PP4     ------> XSPIM_P1_IO4
    PO4     ------> XSPIM_P1_CLK
    PP6     ------> XSPIM_P1_IO6
    PO0     ------> XSPIM_P1_NCS1
    PP9     ------> XSPIM_P1_IO9
    */
    GPIO_InitStruct.Pin = HEXASPI_DQS1_Pin|HEXASPI_DQS0_Pin|HEXASPI_CLK_Pin|GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_XSPIM_P1;
    HAL_GPIO_Init(GPIOO, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = HEXASPI_IO10_Pin|HEXASPI_IO12_Pin|HEXASPI_IO14_Pin|HEXASPI_IO2_Pin
                          |HEXASPI_IO5_Pin|HEXASPI_IO1_Pin|HEXASPI_IO11_Pin|HEXASPI_IO15_Pin
                          |HEXASPI_IO3_Pin|HEXASPI_IO0_Pin|HEXASPI_IO7_Pin|HEXASPI_IO8_Pin
                          |HEXASPI_IO13_Pin|HEXASPI_IO4_Pin|HEXASPI_IO6_Pin|HEXASPI_IO9_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_XSPIM_P1;
    HAL_GPIO_Init(GPIOP, &GPIO_InitStruct);

  /* USER CODE BEGIN XSPI1_MspInit 1 */

  /* USER CODE END XSPI1_MspInit 1 */
  }
}

void HAL_XSPI_MspDeInit(XSPI_HandleTypeDef* xspiHandle)
{

  if(xspiHandle->Instance==XSPI1)
  {
  /* USER CODE BEGIN XSPI1_MspDeInit 0 */

  /* USER CODE END XSPI1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_XSPIM_CLK_DISABLE();
    __HAL_RCC_XSPI1_CLK_DISABLE();

    /**XSPI1 GPIO Configuration
    PO3     ------> XSPIM_P1_DQS1
    PP10     ------> XSPIM_P1_IO10
    PP12     ------> XSPIM_P1_IO12
    PP14     ------> XSPIM_P1_IO14
    PP2     ------> XSPIM_P1_IO2
    PP5     ------> XSPIM_P1_IO5
    PO2     ------> XSPIM_P1_DQS0
    PP1     ------> XSPIM_P1_IO1
    PP11     ------> XSPIM_P1_IO11
    PP15     ------> XSPIM_P1_IO15
    PP3     ------> XSPIM_P1_IO3
    PP0     ------> XSPIM_P1_IO0
    PP7     ------> XSPIM_P1_IO7
    PP8     ------> XSPIM_P1_IO8
    PP13     ------> XSPIM_P1_IO13
    PP4     ------> XSPIM_P1_IO4
    PO4     ------> XSPIM_P1_CLK
    PP6     ------> XSPIM_P1_IO6
    PO0     ------> XSPIM_P1_NCS1
    PP9     ------> XSPIM_P1_IO9
    */
    HAL_GPIO_DeInit(GPIOO, HEXASPI_DQS1_Pin|HEXASPI_DQS0_Pin|HEXASPI_CLK_Pin|GPIO_PIN_0);

    HAL_GPIO_DeInit(GPIOP, HEXASPI_IO10_Pin|HEXASPI_IO12_Pin|HEXASPI_IO14_Pin|HEXASPI_IO2_Pin
                          |HEXASPI_IO5_Pin|HEXASPI_IO1_Pin|HEXASPI_IO11_Pin|HEXASPI_IO15_Pin
                          |HEXASPI_IO3_Pin|HEXASPI_IO0_Pin|HEXASPI_IO7_Pin|HEXASPI_IO8_Pin
                          |HEXASPI_IO13_Pin|HEXASPI_IO4_Pin|HEXASPI_IO6_Pin|HEXASPI_IO9_Pin);

  /* USER CODE BEGIN XSPI1_MspDeInit 1 */

  /* USER CODE END XSPI1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
