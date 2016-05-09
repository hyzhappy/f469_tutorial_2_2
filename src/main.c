//做一个流水灯吧

#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"
#include "stm32f4xx_hal.h"

//还是用SysTick进行延时
void SysTick_Handler()
{
	HAL_IncTick();
}
int
main(int argc, char* argv[])
{
	//这些就不解释了吧<(￣︶￣)>
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

	//先只点亮第一盏LED，其余三盏LED熄灭
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOK, GPIO_PIN_3, GPIO_PIN_SET);
	while (1)
    {
		//等待一秒
		HAL_Delay(1000);
		//关闭第1盏LED，开启第2盏LED
		HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_6);
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_4);
		//等待一秒
		HAL_Delay(1000);
		//关闭第2盏LED，开启第3盏LED
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_4);
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_5);
		//等待一秒
		HAL_Delay(1000);
		//关闭第3盏LED，开启第4盏LED
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_5);
		HAL_GPIO_TogglePin(GPIOK, GPIO_PIN_3);
		//等待一秒
		HAL_Delay(1000);
		//关闭第4盏LED，开启第1盏LED
		HAL_GPIO_TogglePin(GPIOK, GPIO_PIN_3);
		HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_6);
    }
}

