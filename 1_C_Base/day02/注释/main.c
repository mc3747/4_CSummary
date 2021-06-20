//
//  main.c
//  关键字
//
//  Created by xiaomage on 15/6/3.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>



// 单行注释
// 单行注释有自己的作用范围, 范围就是从第二个斜线开始, 一直到这一行的末尾
// 注释不会参与编译, 也就是说注释不会被翻译为0和1


/*
 多行注释
 以 /星 开头
 以 星/ 结尾
 */

// 多行注释有自己的作用范围,范围就是从/*开始 一直到遇到第一个*/为止
// 注释不会参与编译, 也就是说注释不会被翻译为0和1


// 程序一启动就会自动调用名称叫做main的函数


/*
 该方法用于根据一个电话号码发送一条信息
 其中num就是电话号码
 */
int sendMessageWithNumber(int num)
{
    return 0;
}

int main() {
    
    // 下面这一行代码用于往屏幕上输出Hello, World!
//    printf("Hello, World!\n");
    
    printf("111111111\n");
    printf("222222222\n");
    //    printf("333333333\n");
    printf("444444444\n");
    printf("555555555\n");
    
    return 0;
}
