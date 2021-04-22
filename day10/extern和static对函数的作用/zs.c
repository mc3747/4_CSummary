//
//  zs.c
//  day10
//
//  Created by xiaomage on 15/6/15.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include "zs.h"

// 声明内部函数一般用于内部函数定义在后面, 而想在定义之前使用内部函数
static void demo();

// 只要在函数的返回值前面加上一个extern就可以让函数变为一个外部函数, 由于默认就是外部函数, 所以在开发中一般情况extern没人写
// 如果extern写在函数的实现中, 代表定义一个外部函数
// 如果extern写在函数的声明中, 代表声明一个外部函数
extern void test()
{
    printf("test printf\n");
    demo();
}

// 只要在函数的返回值前面加上static就可以让函数变为内部函数, 其它文件就不能访问了
// 如果static写在函数的实现中, 代表定义一个内部函数
// 如果static写在函数的声明中, 代表声明一个内部函数
static void demo()
{
    printf("demo printf\n");
}