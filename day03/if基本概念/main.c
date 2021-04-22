//
//  main.c
//  if基本概念
//
//  Created by xiaomage on 15/6/4.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

/*
 第一种格式:
 if (条件表达式)
 {
    语句...
 }
 只要 条件表达式 为真, 那么就会执行if后面大括号中的内容.
 
 第二种格式:
 if (条件表达式)
 {
    语句...
 }else
 {
    语句...
 }
 只要 条件表达式 为真,那么就会执行if后面大括号中的内容. 
 如果 条件表达式 不为真, 那么就会执行else后面大括号中的内容
 规律: 两个大括号中的内容, 一定会有一个会被执行
 
 第三种格式:
 if (条件表达式1)
 {
     语句...
 }
 else if (条件表达式2)
 {
     语句...
 }
 else if (条件表达式3)
 {
     语句...
 }
 .....
 else
 {
     语句...
 }
 只要 条件表达式1 为真,那么就会执行if后面大括号中的内容. 而其它大括号不会被执行
 如果 条件表达式1 不为真, 那么就会取判断条件表达式2, 如果 条件表达式2 为真就会执行 条件表达式2 后面大括号中的内容
 其它的else if一次类推, 
 当前面所有的if, else if的条件表达式都不为真, 就会执行else后面大括号中的内容
 规律:
 众多大括号只会执行其中一个
 如果执行到后面大括号中的内容, 代表前面的所有条件都不满足
 
 第4种格式:
 if (条件表达式)
      语句...
 
 如果省略if后面的大括号, 当条件表达式为真时, 只会执行if后面的第一条语句
 
 第5种格式:(if嵌套)
 if(添加表达式)
 {
     if(添加表达式)
     {
 
     }
 }else
 {
     if(添加表达式)
     {
     
     }else
    {
    }
 }
 */
int main(int argc, const char * argv[]) {
    /*
    int age = 12;
    // 判断年龄是否大于等于18岁
    if (age >= 18)
    {
        printf("开网卡\n");
    }
    printf("end\n");
     */
    
    /*
    int age = 19;
    if (age >= 18)
    {
        printf("开网卡\n");
    }else
    {
        printf("回家叫芭比\n");
    }
     */
    
    /*
    int age = 6;
    if (age == 1) {
        printf("该学走路了");
    }else if (age == 6)
    {
        printf("该上学了");
    }else if (age == 18)
    {
        printf("该谈朋友了");
    }else
    {
        printf("在家好好呆着");
    }
     */
    
    /*
    int age = 15;
    if (age >= 18)
        printf("开网卡\n"); // 只有条件满足才会执行
    printf("给钱\n"); // 无论条件是否满足, 都会执行
    */
    
    // 判断一个数, 是否在3~5之间
//    3<= a <= 5; // 错误
//    (a >= 3) && (a <= 5);
    int a = 10;
    if (a >= 3) {
        if (a <= 5) {
            printf("a是一个3~5之间的数\n");
        }else
        {
            printf("a不是一个3~5之间的数\n");
        }
    }else
    {
        printf("a不是一个3~5之间的数\n");
    }
    printf("end\n");
    return 0;
}
