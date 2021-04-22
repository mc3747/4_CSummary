//
//  main.c
//  指针和字符串注意点
//
//  Created by xiaomage on 15/6/14.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    /*
    // 指针没有被初始化不能随便使用, 野指针
    int *p;
    printf("*p = %i\n", *p);
     */
    /*
    char str[10];
    scanf("%s", str);
    printf("str = %s\n", str);
     */
    
    // 1.指针没有初始化, 野指针
    char *str;
    scanf("%s", str);
    printf("str = %s\n", str);
    
    // 注意: 用指针来保存字符串不可以被修改
    // 指针没有初始化不能随便使用
    return 0;
}
