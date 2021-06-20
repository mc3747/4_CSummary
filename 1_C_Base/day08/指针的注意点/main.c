//
//  main.c
//  指针的注意点
//
//  Created by xiaomage on 15/6/12.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // 1.指针只能保存地址
    /*
    int *p = 200;
    printf("%i\n", *p);
     */
    
    /*************************华丽的分割线*******************************/
    
    // 2.同一个变量可以有多个指针指向它
    /*
    int num = 10;
    int *p = &num;
    // *p == num
//    num = 55;
    *p = 55;
    
    int *p1 = p;
    *p1 = 100;
    
    int *p2 = &num;
    
    printf("%i\n", *p);
     */
    
    /*************************华丽的分割线*******************************/
    
    // 3.指针的指向可以修改
    /*
    int a = 10;
    int b = 5;
    
    int *p = &a;
    *p = 88;
    
    p = &b;
    
    *p = 44;
    
    printf("%i\n", a);
    printf("%i\n", b);
    */
    
    /*************************华丽的分割线*******************************/
    
    // 4.不要访问野指针
    /*
    // 没有赋值的指针, 我们称之为野指针
//    int *p;
    int *p = NULL; // 0
    printf("%i\n", *p);
     */
    
    /*************************华丽的分割线*******************************/
    
    // 5.指针类型是什么类型, 就只能指向什么类型的数据
    /*
    int num = 10;
    char charValue = 'l';
    double doubleValue = 9.9;
    
//    int *p = &num;
//    int *p = &charValue;
//    int *p = &doubleValue;
    
    double *p = &doubleValue;
    printf("%lf\n", *p);
     */
    
    return 0;
}
