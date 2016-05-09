//��һ����ˮ�ư�

#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"
#include "stm32f4xx_hal.h"

//������SysTick������ʱ
void SysTick_Handler()
{
	HAL_IncTick();
}
int
main(int argc, char* argv[])
{
	//��Щ�Ͳ������˰�<(�����)>
	__HAL_RCC_GPIOG_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOK_CLK_ENABLE();
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.Pin = GPIO_PIN_6;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOG, &GPIO_InitStructure);
	GPIO_InitStructure.Pin = GPIO_PIN_4 | GPIO_PIN_5;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);
	GPIO_InitStructure.Pin = GPIO_PIN_3;
	HAL_GPIO_Init(GPIOK, &GPIO_InitStructure);

	//��ֻ������һյLED��������յLEDϨ��
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOK, GPIO_PIN_3, GPIO_PIN_SET);
	while (1)
    {
		//�ȴ�һ��
		HAL_Delay(1000);
		//�رյ�1յLED��������2յLED
		HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_6);
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_4);
		//�ȴ�һ��
		HAL_Delay(1000);
		//�رյ�2յLED��������3յLED
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_4);
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_5);
		//�ȴ�һ��
		HAL_Delay(1000);
		//�رյ�3յLED��������4յLED
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_5);
		HAL_GPIO_TogglePin(GPIOK, GPIO_PIN_3);
		//�ȴ�һ��
		HAL_Delay(1000);
		//�رյ�4յLED��������1յLED
		HAL_GPIO_TogglePin(GPIOK, GPIO_PIN_3);
		HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_6);
    }
}

