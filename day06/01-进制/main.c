//
//  main.c
//  01-进制
//
//  Created by xiaomage on 15-6-09.
//  Copyright (c) 2014年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
//     1.默认就是10进制
    int num = 12;
//    2.在前面加上一个0就代表八进制
    int num1 = 014;
    
//    %d是以十进制的方式输出一个整数
    printf("%d\n", num1);
//    %o是以八进制的方式输出一个整数
    printf("%o\n", num);
    
//    在数值前面加上0b就代表二进制
    int num2 = 0b1100;
    printf("%d\n", num2);
//    在数值前面加上0x就代表十六进制
    int num3 = 0xc;
    printf("%d\n", num3);
//     %x是以十六进制的方式输出一个整数
    printf("%x\n", num);
    
//     口诀:不看你怎么存,只看你怎去取
    
    return 0;
}

