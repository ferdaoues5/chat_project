/*
 * lidar.c
 *
 *  Created on: Dec 22, 2023
 *      Author: chizu
 */
#include "main.h"
#include "cmsis_os.h"
#include "dma.h"
//#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
//#define SIZE_BUFFER_LIDAR 40
#define STACK_DEPTH 256
#define SIZE_BUFFER_LIDAR 400

extern TaskHandle_t xHandleResetLidar;
uint8_t buffer_lidar[SIZE_BUFFER_LIDAR]={};
uint8_t tab_lidar[SIZE_BUFFER_LIDAR]={};

uint8_t h_reset[2]={0xA5,0x80};
uint8_t c_scan [2] = {0xA5,0x60};
uint8_t health_s [2] = {0xA5,0x91};


SemaphoreHandle_t sem_Lidar_half_cplt;
SemaphoreHandle_t sem_Lidar_cplt;

//executé quand buffer rempli à moitié. Quand c'est le cas, commencer à traiter données
void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart)
{
	//printf("ha\r\n");
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	xSemaphoreGiveFromISR(sem_Lidar_half_cplt, &xHigherPriorityTaskWoken);
	portYIELD_FROM_ISR(xHigherPriorityTaskWoken);//debloque tache qui était bloquée (lidarRecup)
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	//printf("c\r\n");
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	xSemaphoreGiveFromISR(sem_Lidar_cplt, &xHigherPriorityTaskWoken);
	portYIELD_FROM_ISR(xHigherPriorityTaskWoken);

}


//rempli tableau de valeuras du LIDAR
void lidarDataRecup(void *used)
{
	int i,j=0,k;
	int flag_start=0;

	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET); //DEV_EN enabled

	//Reset du LiDAR
	HAL_UART_Receive_DMA(&huart2,buffer_lidar,SIZE_BUFFER_LIDAR);
	HAL_UART_Transmit(&huart2, h_reset, 2, HAL_MAX_DELAY);
	vTaskDelay(1000);
	//printf("***rEsEt***\r\n");
	HAL_UART_Receive_DMA(&huart2,buffer_lidar,SIZE_BUFFER_LIDAR);
	HAL_UART_Transmit(&huart2, c_scan, 2, 100);
	vTaskDelay(1000);

	//printf("*Lidar recup*\r\n");
	vSemaphoreCreateBinary(sem_Lidar_half_cplt);
	vSemaphoreCreateBinary(sem_Lidar_cplt);
	//xHigherPriorityTaskWoken=pdFALSE;
	//HAL_Delay(100);

	for (;;)
	{
		xSemaphoreTake(sem_Lidar_half_cplt,portMAX_DELAY);

		for (i=0;i<(SIZE_BUFFER_LIDAR/2);i++)
		{
			if (buffer_lidar[i]==0xA5 && buffer_lidar[i+1]==0x5A)
			{
				flag_start=1;
				tab_lidar[j]=buffer_lidar[i];
				j++;
			}
		}


		//mettre tâche qui cherche debut de trame 0xA5 et je sais plus
		//if (buffer_lidar[i-1]==0xA5 && buffer_lidar[i]==5A)
		//{
		//}

		xSemaphoreTake(sem_Lidar_cplt,portMAX_DELAY);

		for (i=(SIZE_BUFFER_LIDAR/2);i<SIZE_BUFFER_LIDAR;i++)
		{
			if (flag_start==1 && buffer_lidar[i]!=0xA5 && buffer_lidar[i+1]!=0x5A)
			{
				tab_lidar[j]=buffer_lidar[i];
				j++;
			}

			else if (buffer_lidar[i]==0xA5 && buffer_lidar[i+1]==0x5A && flag_start==0)
			{
				flag_start=1;
				j=0;
				tab_lidar[i]=buffer_lidar[j];
				j++;
			}

		}

		for(i=0;i<SIZE_BUFFER_LIDAR;i++)
		{
			printf("0x%02X\n\r",tab_lidar[i]);
		}

	}

}


