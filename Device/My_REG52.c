/*
 * @Author: 2353919304@qq.com
 * @Date: 2024-09-26 23:56:04
 * @LastEditors: 2353919304@qq.com
 * @LastEditTime: 2024-09-27 17:39:49
 * @FilePath: \Calc\Device\My_REG52.c
 * @Description: 定义数据类型别名
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */
#ifndef __MY_REG52_C__
#define __MY_REG52_C__

#include <reg52.h>
#include <INTRINS.H>

sfr P1M1 = 0x91;
sfr P1M0 = 0x92;
sfr P2M1 = 0x95;
sfr P2M0 = 0x96;
sfr P3M1 = 0xB1;
sfr P3M0 = 0xB2;

typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;


#endif // !__MY_REG52_H__
