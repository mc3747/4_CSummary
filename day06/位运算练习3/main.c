//
//  main.c
//  位运算练习3
//
//  Created by xiaomage on 15/6/9.
//  Copyright (c) 2015年 itcast. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // 要求交换两个变量的值
    
    int a = 10;
    int b = 5;
    printf("交换前:a = %i , b = %i\n", a, b);
    // 第一种方式
    /*
    int temp = a;
    a = b;
    b = temp;
     */
    /*
     a = a + b; // a = 15
     b = a - b; // b = 15 - 5 = 10
     a = a - b; // a = 15 - 10 = 5
     */
    
    /*
    a = a ^ b;
    b = a ^ b; // b = a ^ b ^ b = a
    a = a ^ b; // a = a ^ a ^ b == b
     */
    /*
    b = a ^ b;
    a = a ^ b;//  a = a ^ a ^ b == b
    b = a ^ b;//  b = a ^ b ^ b == a
    
    printf("交换后:a = %i , b = %i\n", a, b);
     */
    
    
//    用户密码 , 纯数字
    int pwd = 123456789;
//    对用户密码进行简单加密
    int result = pwd ^ 998;
    printf("加密后:%d\n", result);
//    对用户密码进行解密
    result = result ^ 998;
     printf("解密后:%d\n", result);
    
    return 0;
}
