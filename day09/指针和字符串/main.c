//
//  main.c
//  指针和字符串
//
//  Created by xiaomage on 15/6/14.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // 保存字符串
    char str[] = "lnj";
    printf("str = %s\n", str);
    str[0] = 'm';
    printf("str = %s\n", str);
    
    // 因为数组名就是数组的地址, 数组名保存的就是数组的第0个元素的地址,所以我们可以使用指针来保存字符串
    
    // 通过指针保存一个字符串, 其实就是保存的字符串第0个元素的地址
    char *str2 = "lmj";
    printf("str2 = %s\n", str2);
//    str2[0] = 'm';
    printf("str2 = %s\n", str2);
    
    
    // 通过数组保存字符串和通过指针保存字符串的区别
    // 如果通过数组来保存字符串, 那么字符串是一个变量 str  可以修改
    // 如果通过指针来保存字符串, 那么字符串是一个常量 str2 不能修该
    // 数组保存的字符串存储在内存的栈中, 而通过指针保存的字符串存储在常量区
    // 存储在栈中的变量有一个特点, 当作用域结束系统会自动释放该变量
    // 存储在常量区中的值有一个特点, 不会被释放, 而且多个相同的值对应的地址相同
    
    char str3[] = "lnj";
    printf("str = %p\n", str);
    printf("str3 = %p\n", str3);
    
    char *str4 = "lmj";
    printf("str2 = %p\n", str2);
    printf("str4 = %p\n", str4);
    
    
    // 利用指针保存字符串的应用场景
    for (int i = 0; i < 100; i++) {
        // 意味着会开辟100块存储空间来保存xmg这个字符串
        // 并且会释放100次
//        char str5[] = "xmg";
        char *str6 = "xmg";
        printf("str5 = %s\n", str6);
    }
    
    /*
     保存字符串的两种方式:
     char str[] = "lnj";
     存储的位置: 栈
     特点: 相同的字符串会重复的分配存储空间
           字符串可以修改
     
     char *str = "lnj"
     存储的位置: 常量区
     特点: 相同的字符串不会重复的分配存储空间
            字符串不可以修改
     */
    
    return 0;
}
