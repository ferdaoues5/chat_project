/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32g0xx_hal.h"

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
#define souris_led_Pin GPIO_PIN_12
#define souris_led_GPIO_Port GPIOC
#define chat_led_Pin GPIO_PIN_13
#define chat_led_GPIO_Port GPIOC
#define bumper_in2_Pin GPIO_PIN_3
#define bumper_in2_GPIO_Port GPIOC
#define capteur_bord_1_Pin GPIO_PIN_0
#define capteur_bord_1_GPIO_Port GPIOA
#define bumper_in3_Pin GPIO_PIN_1
#define bumper_in3_GPIO_Port GPIOA
#define Encodeur_2_Pin GPIO_PIN_6
#define Encodeur_2_GPIO_Port GPIOA
#define encoder2_mais_pwm_normale_Pin GPIO_PIN_7
#define encoder2_mais_pwm_normale_GPIO_Port GPIOA
#define VCP_TX_Pin GPIO_PIN_4
#define VCP_TX_GPIO_Port GPIOC
#define VCP_RX_Pin GPIO_PIN_5
#define VCP_RX_GPIO_Port GPIOC
#define bumper_in4_Pin GPIO_PIN_13
#define bumper_in4_GPIO_Port GPIOB
#define Encoder_1_Pin GPIO_PIN_8
#define Encoder_1_GPIO_Port GPIOA
#define Encodeur_1_Pin GPIO_PIN_9
#define Encodeur_1_GPIO_Port GPIOA
#define Driver1_REV_Pin GPIO_PIN_10
#define Driver1_REV_GPIO_Port GPIOA
#define Driver1_FWD_Pin GPIO_PIN_11
#define Driver1_FWD_GPIO_Port GPIOA
#define M_SCTR_Lidar_Pin GPIO_PIN_1
#define M_SCTR_Lidar_GPIO_Port GPIOD
#define DEV_EN_Lidar_Pin GPIO_PIN_2
#define DEV_EN_Lidar_GPIO_Port GPIOD
#define M_EN_Lidar_Pin GPIO_PIN_3
#define M_EN_Lidar_GPIO_Port GPIOD
#define bumper_in1_Pin GPIO_PIN_10
#define bumper_in1_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
