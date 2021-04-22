//
//  main.c
//  变量的基本概念
//
//  Created by xiaomage on 15/6/3.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    // 1.申请一块存储空间, 也就是定义一个变量
    /*
    // 定义变量的格式: 数据类型  变量名称;
    // 定义一个基本数据类型的变量
    // int float double char
    int number; // 定义了一个名称叫做number的变量
    // 会在内存中开辟一块存储空间给number, 用于存储数据
    int value; // 定义了一个名称叫做value的变量
    // 又会在内存中开辟一块存储空间给value, 用于存储数据
    */
    
    /*
    // 2.连续定义, 如果多个变量都是相同类型的, 那么可以采用连续定义
    int number, value;
    
    // 3.如何往变量对应的存储空间当中存储数据
    // 注意: 变量中不能随便存储数据, 只能存储与之对应的数据
    // 概念: 变量的第一次赋值, 我们称之为初始化,
    // 注意, 要想使用变量都必须先对变量进行初始化, 然后才能够使用
    // 如果不对变量进行初始化, 那么其实变量中存储的是一些垃圾数据
    number = 10; // 会将等号右边的数据放到等号左边的变量对应的存储空间中
    
    
    // 4.如何使用变量
    // 占位符号, %号是占位符号的起始符号
    printf("%i\n", number);
    
    
    float floatValue; // 定义了一个实型的变量
    floatValue = 10.1f; // 往floatValue对应的存储空间中存储了10.1这个值
    printf("%f\n", floatValue);
    
    int intValue, age; // 定义了一个整型的变量
    printf("%i\n", intValue);
    printf("%i\n", age);
    */
    
    // 6.初始化的两种方式
    /*
    // 1.先定义再初始化
    int number;
    number = 10;
    // 2.定义的同时初始化
    int value = 10;
     */
    
    // 7.完全初始化
//    int number, value;
//    number = value = 10;
    
    int number;
    number = 10;
    int value;
    value = number;

    // 8.部分初始化
//    int number, value = 10;
    
    
    return 0;
}
