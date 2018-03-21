#include "infrared\infrared.h"
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

void infrared_init(void) {
	GPIO_InitTypeDef gpio_init;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE);	
	gpio_init.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	gpio_init.GPIO_Pin = GPIO_Pin_0| GPIO_Pin_1; // 0:left 1:right
 	gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &gpio_init);
}
