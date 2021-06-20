//
//  main.c
//  指向函数的指针的应用场景
//
//  Created by xiaomage on 15/6/14.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int sum(int v1, int v2)
{
    return v1 + v2;
}

int minus(int v1, int v2)
{
    return v1 - v2;
}

// 让demo接受一个指向函数的指针
// 以后我们只需要给demo函数传递对应的指针, 那么函数内部就可以调用不同的函数
int demo(int v1, int v2)
{
    return minus(v1, v2);
}

int demo2(int v1, int v2)
{
    return sum(v1, v2);
}

int demo3(int v1, int v2, int (*p)(int, int))
{
    return p(v1, v2);
}

int main(int argc, const char * argv[]) {
    // 定义一个方法, 给你两个数, 用户要求你做加法你就做加法, 用户要求你做减法, 那你就做减法
//    printf("sum = %i\n", sum(10, 20));
//    printf("minus = %i\n", minus(20, 10));
    
//    printf("minus = %i\n", demo(20 , 10));
//    printf("sum = %i\n", demo2(20 , 10));
    
    printf("mins = %i\n", demo3(20, 10, minus));
    printf("sum = %i\n", demo3(20, 10, sum));
    
    return 0;
}
