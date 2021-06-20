//
//  main.c
//  scanf实现原理
//
//  Created by xiaomage on 15/6/3.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    // 添加断点快捷键: command + \
    
    // 1.提醒用户
//    printf("请输入两个整数 , 整数之间用逗号隔开, 使用回车结束\n");
    // 2.定义变量保存用户输入的数据
    int num1, num2;
    char charValue;
    // 3.接收用户输入的数据
    // num1 = 123, charValue = + , num2 = 456
    scanf("%i%c%i", &num1, &charValue, &num2);
    // 4.求差
//    int result = num1 - num2;
    // 5.输出验证
//    printf("result = %i\n", result);
    printf("num1 = %i, cahrValue = %c, num2 = %i\n", num1, charValue, num2);
    
    // 用户输入-->输入缓冲区-->scanf
    
    char charValue2;
    int num3;
    // scanf只要输入缓冲区中有内容, 就不会要求用户输入数据
    scanf("%c%i", &charValue2, &num3);
    printf("charVaue2 = %c, num3 = %i\n", charValue2, num3);
    
    return 0;
}
