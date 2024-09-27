/*
 * @Author: foxbrokenleaf
 * @Date: 2024-09-26 22:41:48
 * @LastEditors: 2353919304@qq.com
 * @LastEditTime: 2024-09-27 21:23:59
 * @FilePath: \Calc\User\main.c
 * @Description: 主函数
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */
#include <REG52.H>
#include "../Device/LCD1602.h"
#include "../Device/Keyboard.h"

uint8_t Old_Key = 0;
uint8_t Key_Down = 0;
uint8_t Key_Up = 0;
uint8_t New_Key = 0;

void Delay1ms()		//@12.000MHz
{
	unsigned char i, j;

	i = 12;
	j = 169;
	do
	{
		while (--j);
	} while (--i);
}


void Filter_Key(){
    New_Key = Get_Key();
    Key_Down = (Old_Key ^ New_Key) & New_Key;
    Key_Up = (Old_Key ^ New_Key) & Old_Key;
    Old_Key = New_Key;
}

void main(){

    Init_LCD1602();
    Init_Keyboard();

    while(1){
        Filter_Key();
        Delay1ms();
        Key_Proc(Key_Down);
    }
}