/*
 * @Author: 2353919304@qq.com
 * @Date: 2024-09-26 22:48:03
 * @LastEditors: 2353919304@qq.com
 * @LastEditTime: 2024-09-27 21:19:34
 * @FilePath: \Calc\Device\LCD1602.h
 * @Description: LCD1602驱动头文件
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */
#ifndef __LCD1602_H__
#define __LCD1602_H__

#include "./My_REG52.c"

void Init_LCD1602();
void Reset_Pos();
void Clearn_Screece();
void Write_Data(uint8_t value);
void Write_Command(uint8_t value);
void Set_Pos(uint8_t colums);
void Show_Num(long value);
void Show_String(char *str);
void Test_LCD1602();

#endif // !__LCD1602_H__

