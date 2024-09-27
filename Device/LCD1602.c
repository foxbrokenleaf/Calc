/*
 * @Author: 2353919304@qq.com
 * @Date: 2024-09-26 22:47:53
 * @LastEditors: 2353919304@qq.com
 * @LastEditTime: 2024-09-27 21:25:10
 * @FilePath: \Calc\Device\LCD1602.c
 * @Description: LCD1602驱动实现
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */
#include "./LCD1602.h"

extern uint8_t SPos;

sbit RS = P3 ^ 2;
sbit RW = P3 ^ 3;
sbit EN = P3 ^ 4;
#define DO P2

void Delay_us(uint8_t us)		//@12.000MHz
{
    while(us--){
        _nop_();
        _nop_();
        _nop_();
        _nop_();
    }
}

void Delay_ms(uint8_t ms)		//@12.000MHz
{
    while(ms--){
        unsigned char i, j;

        i = 12;
        j = 169;
        do
        {
            while (--j);
        } while (--i);
    }
}

uint32_t power(uint32_t num,uint8_t pow){
    uint32_t res = 1;
    if(pow == 0) res = 1;
    else while(pow--) res *= num;
    return res;
}

void Write_Data(uint8_t value){
    RS = 1;
    RW = 0;
    DO = value;
    EN = 1;
    Delay_us(40);
    EN = 0;

    SPos++;
}

void Write_Command(uint8_t value){
    RS = 0;
    RW = 0;
    DO = value;
    EN = 1;
    Delay_ms(50);
    EN = 0;
}

void Init_LCD1602(){
    P2M1 = 0x00;
    P2M0 = 0x00;
    P3M1 = P3M1 & 0xE3;
    P3M0 = P3M0 & 0xE3;    

    Write_Command(0x0F);    //开启显示屏
    
    Write_Command(0x01);
    Write_Command(0x80);
    // Write_Command(0x02);
    
}

void Set_Pos(uint8_t colums){
    Write_Command(0x80 + colums);
}

void Show_Num(long value){
    uint8_t zero_flag = 1;
    uint8_t loop_i = 10;

    Write_Command(0x01);
    Write_Command(0x80);

    if(value < 0){
        Write_Data('-');
        value = -value;
    }

    while(loop_i--){
        if(value / power(10,loop_i) % 10 != 0 && zero_flag == 1){
            zero_flag = 0;
            Write_Data((value / power(10,loop_i) % 10) + '0');
        }
        else if(zero_flag == 0) Write_Data((value / power(10,loop_i) % 10) + '0');
    }
}

void Show_String(char *str){
    while (*str != '\0'){
        Write_Data(*str);
        if(*(str++) == '\0') break;
    }
    
}

void Test_LCD1602(){
    DO = 0xff;
}