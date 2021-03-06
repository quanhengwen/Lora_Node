/**
  * @file    led.c
  * @author  Liang
  * @version V1.0.0
  * @date    2019-1-10
  * @brief	
  **/

#include "led.h"

/**
 * LED GPIO 初始化
 * @param   
 * @return 
 * @brief 
 **/
void LED_Init(void)
{
 
  GPIO_InitTypeDef  GPIO_InitStructure;
 	
	/* 禁用端口JTAG功能 */
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO,ENABLE );
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
	DBGMCU->CR &= ~(uint32_t)DBGMCU_CR_TRACE_IOEN;
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure);	
	GPIO_SetBits(GPIOB,GPIO_Pin_2);
	GPIO_SetBits(GPIOB,GPIO_Pin_3);
	GPIO_SetBits(GPIOB,GPIO_Pin_4);
		
}


