//
//  main.c
//  位运算符练习2
//
//  Created by xiaomage on 15/6/9.
//  Copyright (c) 2015年 itcast. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // 利用位运算符, 判断一个数的奇偶性
    int num = 9;
    /*
    // 开发中常用的方式
    if (num % 2 == 0) {
        printf("偶数\n");
    }else
    {
        printf("奇数\n");
    }
    
    // 注意: 三目(三元)运算符, 的结果A和结果B如果是表达式, 那么必须有返回值
    (num % 2 == 0) ? printf("偶数\n"):printf("奇数\n");
    
    int length = printf("李");
    printf("------%i\n", length);
     */
    
    /*
     1001 9
     1011 11
     
     1010 10
     1100 12
     通过观察, 我们发现如果是偶数, 那么二进制的最后一位是0, 如果是奇数那么二进制的最后一位是1
     */
    /*
    if ((num & 1) == 1)
    {
        printf("奇数\n");
    }else
    {
        printf("偶数\n");
    }
     */
    
    if ((num & 1))
    {
        printf("奇数\n");
    }else
    {
        printf("偶数\n");
    }
    return 0;
}
