/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define M0_nCS_Pin GPIO_PIN_13
#define M0_nCS_GPIO_Port GPIOC
#define M1_NCS_Pin GPIO_PIN_14
#define M1_NCS_GPIO_Port GPIOC
#define M1_ENC_Z_Pin GPIO_PIN_15
#define M1_ENC_Z_GPIO_Port GPIOC
#define M0_SO1_Pin GPIO_PIN_0
#define M0_SO1_GPIO_Port GPIOC
#define M0_SO2_Pin GPIO_PIN_1
#define M0_SO2_GPIO_Port GPIOC
#define M1_SO2_Pin GPIO_PIN_2
#define M1_SO2_GPIO_Port GPIOC
#define M1_SO1_Pin GPIO_PIN_3
#define M1_SO1_GPIO_Port GPIOC
#define GPIO_3_Pin GPIO_PIN_2
#define GPIO_3_GPIO_Port GPIOA
#define GPIO_4_Pin GPIO_PIN_3
#define GPIO_4_GPIO_Port GPIOA
#define M1_TEMP_Pin GPIO_PIN_4
#define M1_TEMP_GPIO_Port GPIOA
#define AUX_TEMP_Pin GPIO_PIN_5
#define AUX_TEMP_GPIO_Port GPIOA
#define VBUS_S_Pin GPIO_PIN_6
#define VBUS_S_GPIO_Port GPIOA
#define M1_AL_Pin GPIO_PIN_7
#define M1_AL_GPIO_Port GPIOA
#define GPIO_5_Pin GPIO_PIN_4
#define GPIO_5_GPIO_Port GPIOC
#define M0_TEMP_Pin GPIO_PIN_5
#define M0_TEMP_GPIO_Port GPIOC
#define M1_BL_Pin GPIO_PIN_0
#define M1_BL_GPIO_Port GPIOB
#define M1_CL_Pin GPIO_PIN_1
#define M1_CL_GPIO_Port GPIOB
#define GPIO_6_FLT_Pin GPIO_PIN_2
#define GPIO_6_FLT_GPIO_Port GPIOB
#define AUX_L_Pin GPIO_PIN_10
#define AUX_L_GPIO_Port GPIOB
#define AUX_H_Pin GPIO_PIN_11
#define AUX_H_GPIO_Port GPIOB
#define EN_GATE_Pin GPIO_PIN_12
#define EN_GATE_GPIO_Port GPIOB
#define M0_AL_Pin GPIO_PIN_13
#define M0_AL_GPIO_Port GPIOB
#define M0_BL_Pin GPIO_PIN_14
#define M0_BL_GPIO_Port GPIOB
#define M0_CL_Pin GPIO_PIN_15
#define M0_CL_GPIO_Port GPIOB
#define M1_AH_Pin GPIO_PIN_6
#define M1_AH_GPIO_Port GPIOC
#define M1_BH_Pin GPIO_PIN_7
#define M1_BH_GPIO_Port GPIOC
#define M1_CH_Pin GPIO_PIN_8
#define M1_CH_GPIO_Port GPIOC
#define M0_ENC_Z_Pin GPIO_PIN_9
#define M0_ENC_Z_GPIO_Port GPIOC
#define M0_AH_Pin GPIO_PIN_8
#define M0_AH_GPIO_Port GPIOA
#define M0_BH_Pin GPIO_PIN_9
#define M0_BH_GPIO_Port GPIOA
#define M0_CH_Pin GPIO_PIN_10
#define M0_CH_GPIO_Port GPIOA
#define USB_DP_Pin GPIO_PIN_12
#define USB_DP_GPIO_Port GPIOA
#define USB_DM_Pin GPIO_PIN_13
#define USB_DM_GPIO_Port GPIOA
#define GPIO_7_FLT_Pin GPIO_PIN_15
#define GPIO_7_FLT_GPIO_Port GPIOA
#define SPI_SCK_Pin GPIO_PIN_10
#define SPI_SCK_GPIO_Port GPIOC
#define SPI_MISO_Pin GPIO_PIN_11
#define SPI_MISO_GPIO_Port GPIOC
#define SPI_MOSI_Pin GPIO_PIN_12
#define SPI_MOSI_GPIO_Port GPIOC
#define nFAULT_Pin GPIO_PIN_2
#define nFAULT_GPIO_Port GPIOD
#define GPIO_8_FLT_Pin GPIO_PIN_3
#define GPIO_8_FLT_GPIO_Port GPIOB
#define M0_ENC_A_Pin GPIO_PIN_4
#define M0_ENC_A_GPIO_Port GPIOB
#define M0_ENC_B_Pin GPIO_PIN_5
#define M0_ENC_B_GPIO_Port GPIOB
#define M1_ENC_A_Pin GPIO_PIN_6
#define M1_ENC_A_GPIO_Port GPIOB
#define M1_ENC_B_Pin GPIO_PIN_7
#define M1_ENC_B_GPIO_Port GPIOB
#define CAN_R_Pin GPIO_PIN_8
#define CAN_R_GPIO_Port GPIOB
#define CAN_D_Pin GPIO_PIN_9
#define CAN_D_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
