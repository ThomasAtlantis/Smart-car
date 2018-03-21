#include "motor\motor.h"

// right  B4 B5 
// left B6 B7

void motor_init() {
	
	GPIO_InitTypeDef gpio_l, gpio_r;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	gpio_l.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio_l.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
	gpio_l.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &gpio_l);

	gpio_r.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	gpio_r.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio_r.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &gpio_r);
	
}

void move_forward() {
	GPIO_SetBits(GPIOB, GPIO_Pin_4);    //4 1
	GPIO_ResetBits(GPIOB, GPIO_Pin_5);  //5 0
	GPIO_ResetBits(GPIOB, GPIO_Pin_6);  //6 0
	GPIO_SetBits(GPIOB, GPIO_Pin_7);    //7 1
}

void stop() {
	GPIO_ResetBits(GPIOB, GPIO_Pin_4);
	GPIO_ResetBits(GPIOB, GPIO_Pin_5);
	GPIO_ResetBits(GPIOB, GPIO_Pin_6);
	GPIO_ResetBits(GPIOB, GPIO_Pin_7);
}