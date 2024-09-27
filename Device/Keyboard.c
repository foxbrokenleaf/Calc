/*
 * @Author: 2353919304@qq.com
 * @Date: 2024-09-26 22:48:10
 * @LastEditors: 2353919304@qq.com
 * @LastEditTime: 2024-09-27 21:28:44
 * @FilePath: \Calc\Device\Keyboard.c
 * @Description: 矩阵键盘驱动实现
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */
#include "./Keyboard.h"
#include "LCD1602.h"

uint8_t SPos = 0x80;
static uint8_t Left_flag = 1;
static long Left_Value = 0;
static char Operator = '\0';
static long Right_Value = 0;
static long Result = 0;


sbit L1 = P1 ^ 0;
sbit L2 = P1 ^ 1;
sbit L3 = P1 ^ 2;
sbit L4 = P1 ^ 3;
sbit C1 = P1 ^ 4;
sbit C2 = P1 ^ 5;
sbit C3 = P1 ^ 6;
sbit C4 = P1 ^ 7;

void Init_Keyboard(){
    P1M0 = 0x00;
    P1M1 = 0x00;
}

uint32_t Calc(){
    if(Operator == '+') Result = Left_Value + Right_Value;
    else if(Operator == '-') Result = Left_Value - Right_Value;
    else if(Operator == '*') Result = Left_Value * Right_Value;
    else if(Operator == '/') Result = Left_flag / Right_Value;
    return 0;
}

uint8_t Get_Key(){
    uint8_t res = 0;

    L1 = 1;
    L2 = 1;
    L3 = 1;
    L4 = 0;
    if(C1 == 0) res = 1;
    else if(C2 == 0) res = 2;
    else if(C3 == 0) res = 3;
    else if(C4 == 0) res = 4;

    L1 = 1;
    L2 = 1;
    L3 = 0;
    L4 = 1;
    if(C1 == 0) res = 5;
    else if(C2 == 0) res = 6;
    else if(C3 == 0) res = 7;
    else if(C4 == 0) res = 8;

    L1 = 1;
    L2 = 0;
    L3 = 1;
    L4 = 1;
    if(C1 == 0) res = 9;
    else if(C2 == 0) res = 10;
    else if(C3 == 0) res = 11;
    else if(C4 == 0) res = 12;

    L1 = 0;
    L2 = 1;
    L3 = 1;
    L4 = 1;
    if(C1 == 0) res = 13;
    else if(C2 == 0) res = 14;
    else if(C3 == 0) res = 15;
    else if(C4 == 0) res = 16;
    
    return res;
}

void Input_Value(uint8_t value){
    if(Left_flag == 1){
        Left_Value *= 10;
        Left_Value += value;
        Show_Num(Left_Value);
    }
    else{
        Right_Value *= 10;
        Right_Value += value;
        Show_Num(Right_Value);
    }
}

void Key_Proc(uint8_t value){
    switch(value){
        case 1:
            Write_Data('=');
            Calc();
            Show_Num(Result);
            Result = 0;
            Left_Value = 0;
            Operator = '\0';
            Right_Value = 0;
            Left_flag = 1;
            break;
        case 2:
            // Write_Data('0');
            Input_Value(0);
            break;
        case 3:     //Del
            if(SPos > 0x80 - 1){
                Write_Command(SPos--);
                Write_Data(' ');
                Write_Command(SPos--);
            }
            break;
        case 4:
            // Write_Command(0x01);
            Write_Data('+');
            Operator = '+';
            Left_flag = 0;
            break;
        case 5:
            // Write_Data('1');
            Input_Value(1);
            break;
        case 6:
            // Write_Data('2');
            Input_Value(2);
            break;      
        case 7:
            // Write_Data('3');
            Input_Value(3);
            break;
        case 8:
            // Write_Command(0x01);        
            Write_Data('-');
            Operator = '-';
            Left_flag = 0;
            break;
        case 9:
            // Write_Data('4');
            Input_Value(4);
            break;
        case 10:
            // Write_Data('5');
            Input_Value(5);
            break;
        case 11:
            // Write_Data('6');
            Input_Value(6);
            break;
        case 12:
            // Write_Command(0x01);
            Write_Data('x');
            Operator = '*';
            Left_flag = 0;
            break;
        case 13:
            // Write_Data('7');
            Input_Value(7);
            break;
        case 14:
            // Write_Data('8');
            Input_Value(8);
            break;      
        case 15:
            // Write_Data('9');
            Input_Value(9);
            break;
        case 16:
            // Write_Command(0x01);
            Write_Data('/');
            Operator = '/';
            Left_flag = 0;
            break;                                                                                                                            
        default:
            break;
    }    
}