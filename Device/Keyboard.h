/*
 * @Author: 2353919304@qq.com
 * @Date: 2024-09-26 22:48:30
 * @LastEditors: 2353919304@qq.com
 * @LastEditTime: 2024-09-26 22:51:10
 * @FilePath: \Calc\Device\Keyboard.h
 * @Description: 矩阵键盘驱动头文件
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */
#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#include "./My_REG52.c"

void Init_Keyboard();
uint8_t Get_Key();
void Key_Proc(uint8_t value);

#endif // !__KEYBOARD_H__