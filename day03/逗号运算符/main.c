//
//  main.c
//  逗号运算符
//
//  Created by xiaomage on 15/6/4.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    /*
    int a = 10;
    int b = 5;
    int result;
    // 结合性 从左至右
    // a = 15, b = 6, result = 15 + 6 = 21
    a = a + 5, b = b + 1 , result = a + b;
    printf("a = %i, b = %i, result = %i\n", a, b, result);
     */
    
    // 只要是运算符那么一定会有运算结果, 逗号运算符也不例外.
    // 逗号运算符的结果是 最后一个表达式的结果
    
    int a = 10;
    int b = 5;
    //   6       a = 10 + 5 = 15 b = 5 + 1 = 6
    int result = ((a = a + 5), (b = b + 1)); // 仅仅作为了解
    printf("a = %i, b = %i, result = %i\n", a, b, result);
    return 0;
}
