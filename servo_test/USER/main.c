#include "stm32f10x.h"
#include "delay\delay.h"
#include "stervo\stervo.h"
#include "motor\motor.h"
#include "infrared\infrared.h"

//设置舵机角度上下限，上限为160度，下限为80度
#define angleLimit(x) ((x) < 80? 80 : ( (x) > 160? 160 : (x)))

//测试二路红外卡在黑线外侧
int main() {
	int angle = 120;
	SystemInit();    //系统初始化
	delay_init();    //延时函数初始化
	stervo_init();   //舵机初始化
	motor_init();    //电机端口初始化
	infrared_init(); //红外传感器初始化
	set_stervo_angle(angle); //调整舵机角度使前轮摆正
	delay_ms(1000);    //延时1s等待舵机调整完毕
	move_forward();  //前进
	while (1) {
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 1) {        //如果左侧传感器压黑线
			angle -= 1; //左转一个小角度
			angle = angleLimit(angle); //限制舵机角度不过届
			set_stervo_angle(angle);   //更新舵机角度
			//delay_ms(10);   //延时10ms，等待舵机调整，同时前进
		}
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 1) {        //如果右侧传感器压黑线
			angle += 1; //右转一个小角度
			angle = angleLimit(angle); //限制舵机角度不过届
			set_stervo_angle(angle);   //更新舵机角度
			//delay_ms(10);   //延时10ms，等待舵机调整，同时前进
		}
	}
	/*
	SystemInit();
	delay_init();
	motor_init();
	stervo_init();
	move_forward();
	delay_ms(5000);
	stop();
	while(1) {
	set_stervo_angle(80);
	delay_ms(50000);
	set_stervo_angle(100);
	delay_ms(50000);
	set_stervo_angle(120);
	delay_ms(50000);
	set_stervo_angle(140);
	delay_ms(50000);
	set_stervo_angle(160);
	delay_ms(50000);
	}
	*/
}
