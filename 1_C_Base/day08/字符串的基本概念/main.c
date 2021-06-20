//
//  main.c
//  字符串的基本概念
//
//  Created by xiaomage on 15/6/12.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    /*
    // 用双引号引起来的就是字符串
    printf("Hello, World!\n");
    
    // 字符串是由什么组成的?  字符"串" , 羊肉"串"
    
    // 如何定义字符串变量, 由于字符串是同一种类型的数据组成,  并且是有序的\
    而数组就是用于存储很多同一种类型的有序数据, 所以可以使用数组来保存字符串
    
    // 注意: 字符串变量和普通的字符数组有一定的区别
    // C语言规定, 字符串必须以\0结尾(作为字符串的结束符号), 所以字符串变量的元素个数比字符数组的元素个数多一个 \0
    char str[] = "lnj"; // 字符串变量 l n j \0
    printf("str size = %lu\n", sizeof(str));
    
    char charValues[] = {'l', 'n', 'j'}; // 字符数组 , 这个并不是字符串, 而是字符数组
    printf("charValues size = %lu\n", sizeof(charValues));
    
    int num = 10;
    float floatValue = 10.1f;
    double doubleValue = 9.9;
    char  charValue = 'm';
    printf("%i, %f, %lf, %c\n", num, floatValue, doubleValue, charValue);
    */
    
    /*************************华丽的分割线*******************************/
    
    /*
    // 内存寻址从大到小
    char str[] = "lnj"; // 字符串变量
    char str2[] = {'x', '\0' ,'m', 'g'}; // 字符数组
    
    // 如何输出字符串变量, %s
    // str 数组的名称, 数组的名称就是数组的地址
    // %s的原理, 从传入的"地址"开始逐个取出, 直到遇到"\0"位置
    printf("str = %s\n", str2); // offc3
    */
    
    /*************************华丽的分割线*******************************/
    
    // 字符串注意点, 字符串的初始化
    char str1[] = "lnj";
    char str2[] = {'l', 'n', 'j', '\0'};
    
    // 部分初始化, 部分初始化中, 没有被初始化的元素默认是0
    // \0对应的ASCII 0
    char str3[10] =  {'l', 'n', 'j'}; // l n j 0000000
    
    char str4[3] = {'l', 'n', 'j'}; // 该方式不是字符串, 而是字符数组, 因为没有\0
    char str5[] = {'l', 'n', 'j'}; // 错误写法
    
    // 需要明白的一点就是字符串以\0结尾, 没有\0就不是字符串
    // 只要是用双引号括起来的都是字符串
    // 字符串的本质就是数组
    char str6[] = "lnj";
    str6[1] = 'y';
    
    printf("%s", str6);
    
    return 0;
}
