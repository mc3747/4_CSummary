//
//  main.c
//  day09
//
//  Created by xiaomage on 15/6/14.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    /*
    int num = 10;
    int *numP = &num;
    num = 55;
    *numP = 100;
    // num == *numP
    printf("%i\n", num);
    printf("%i\n", *numP);
    
    int ages[3] = {1, 3 , 5};
    // 数组名就是数组的地址, 数组的地址就是首元素的地址
    printf("ages = %p\n", ages);
    printf("&ages[0] = %p\n", &ages[0]);
    
    // 指针是专门用于保存地址
    // 数据类型 *变量名称;
    // 由于数组的首元素的地址就是数组的地址, 所以定义一个指针指向数组其实就是定义一个指针指向数组的首元素, 所以数组的首元素是什么类型, 那么指向数组的指针就是什么类型'
//    int *p = &ages[0];
    int *p = ages;
    printf("p = %p\n", p);
    printf("&ages[0] = %p\n", &ages[0]);
     */
    
    /*************************华丽的分割线*******************************/
    
    /*
    // 如何利用指针操作数组
    int ages[3] = {1, 3 , 5};
    
    ages[0] = 998;
    printf("ages[0] = %i\n", ages[0]);
    
    int *p = ages; // int *p = &ages[0]; &ages[0] == ages
    printf("p = %p\n", p);
    printf("ages = %p\n", ages); // p == ages;
    
    // 以为p指针中存储的值和ages中存储的值相同, 所以以前用ages的地方都可以使用p来替代
    p[0] = 889;
    printf("ages[0] = %i\n", p[0]);
    
    for (int i = 0; i < 3; i++) {
        printf("p%i] = %i\n", i, p[i]);
    }
     */
    
    /*************************华丽的分割线*******************************/
    
    /*
    int ages[3] = {1, 3 , 5};
    int *p;
    p = ages; // int *p = &ages[0];
    printf("ages[0] = %i\n", ages[0]);
    printf("*p = %i\n", *p);
    
    printf("p = %p\n", p);
//    p = &ages[1];
    // 指针+1, 并不是真实的+1, 而是+4
    // 指针类型的两个用途: \
       第一个用途, 取值的时候, 会根据指针类型所占用的字节去取出对应字节的数据 \
       第二个用途, 用于做加法运算, 指针+1, 其实是加上指针类型所占用的长度 , 如果当前指针类型是int, 那么+1本质上是加上4个字节
    p = p + 1;
    printf("p + 1 = %p\n", p);
    printf("*p = %i\n", *p);
    
//    p = &ages[2];
    p =  p + 1;
    printf("p + 1 = %p\n", p);
    printf("*p = %i\n", *p);
    
    int a = 10;
    a = a  + 1;
    printf("a = %i\n", a);  // 11
     */
    
    /*************************华丽的分割线*******************************/
    
    /*
    int num = 10;
    int *numP = &num;
    printf("num = %i\n", num);
    // *numP 代表访问numP指向的那块内存空间
    printf("*numP = %i\n", *numP);
     */
    
    /*************************华丽的分割线*******************************/
    
    /*
    char c = 'a';
    char *cp = &c;
    printf("cp = %p\n", cp);
    cp = cp + 1;
    printf("cp + 1 = %p\n", cp);
    cp = cp + 1;
    printf("cp + 1 = %p\n", cp);
     */
    
    int ages[3] = {1, 3 , 5};
    int *p;
    p = ages;
    /*
    printf("ages[0] = %i\n", *(p + 0));
    printf("ages[1] = %i\n", *(p + 1)); // p = p + 1; *p;
    printf("ages[2] = %i\n", *(p + 2));
     */
    /*
    for (int i = 0; i < 3; i++) {
        // 指针+1, 是加上指针类型所占用的长度
        printf("ages[%i] = %i\n", i, *(p + i));
    }
     */
    
    /*
     只要一个指针指向了数组, 那么访问数组就有3种方式:
     1. : ages[0];
     2. : p[0];
     3. : *(p + 0);
     */
    
    printf("ages[0] = %i\n", 2[p]);
    return 0;
}
