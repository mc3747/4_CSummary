//
//  main.c
//  指针练习1
//
//  Created by xiaomage on 15/6/12.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>


void swap(int *v1, int *v2)
// int *v1 = &a, int *v2 = &b; v1 = 0ffc13 v2 = 0ffc9
// *v1 == a  *v2 == b
{
    int temp = *v1; // int temp = 0ffc13
    *v1 = *v2;
    *v2 = temp;
}

int main(int argc, const char * argv[]) {
    // 定义一个函数交换两个变量的值
    int a = 10; // 0ffc13
    int b = 5; // offc9
    printf("交换前:a = %i, b = %i\n", a, b);
//    int temp = a;
//    a = b;
//    b = temp;
    swap(&a, &b);
    printf("交换后:a = %i, b = %i\n", a, b);
    return 0;
}
