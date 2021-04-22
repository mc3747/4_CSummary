//
//  main.c
//  文件包含
//
//  Created by xiaomage on 15/6/15.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>
//#include "zs.h" // int sum(int v1, int v2);
// 函数可以重复声明, 但不能重复定义
//void test();
//void test();
//void test();
//void test();


#include "zs.h"// int sum(int v1, int v2);
// 重复导入会降低编译效率
//#include "ls.h"

/*
 #include <>
 <>会先去编译器环境下查找, 找不到再去系统的环境下查找

 #include ""
 ""会先在当前文件查找, 找不到再去编译器环境下查找, 找不到再去系统的环境下查找
 
 作用: 
 将""或者<>中的内容完全拷贝过来
 
 注意:
 如果正确的编写.h文件
 如果防止循环拷贝  A拷贝B, B拷贝A
 间接拷贝问题  A拷贝B, B拷贝C, C拷贝D
 */
int main(int argc, const char * argv[]) {
    printf("sum = %i\n", sum(10, 20));
    
    printf("minus = %i\n", minus(10, 20));
    
    return 0;
}

void test()
{
    printf("0000000\n");
}

