//
//  main.c
//  char基本概念
//
//  Created by xiaomage on 15/6/9.
//  Copyright (c) 2015年 itcast. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    /*
    // 研究的问题: char类型的变量在内存中是如何存储的?
    // char 1个字节
    int num;
    char charValue;
    charValue = 'a'; // 计算机智能识别0和1
    // a == 97 == 01100001
    int size = sizeof(charValue);
    printf("%i\n", size);
    printf("num = %p\n", &num);
    printf("char = %p\n", &charValue);
    
    // 在C语言中, 不看怎么存, 只看怎么取
    printf("%c\n", charValue);
    printf("%i\n", charValue);
     */
    
    /*************************华丽的分割线*******************************/
    
    /*
     字符6和数字6就是完全不相同的两个数
    char c1 = 6; // 00000110
    char c2 = '6';// 00110110
    
    printf("%i\n", c1);
    printf("%i\n", c2);
     */
    
    /*************************华丽的分割线*******************************/
    
    // char类型在某些情况下可以当做整型来用
    // 如果对内存要求特别严格, 而且需要存储的整数不超过char类型的取值范围, 那么就可以使用char类型来代替int类型
    // -2(7)~2(7)-1   == -128 ~ 127
    char c = 129; // 1000 0000
    printf("%i\n", c);
    
    return 0;
}
