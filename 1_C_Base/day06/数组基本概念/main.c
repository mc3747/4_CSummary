//
//  main.c
//  数组基本概念
//
//  Created by xiaomage on 15/6/9.
//  Copyright (c) 2015年 itcast. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    /*
    // 当需要保持很多"相同类型"的数据时就可以使用数组来保持
    // 因为如果使用变量, 那么将变得非常复杂, 并且非常没有技术含量
    int score = 99;
    int score1 = 98;
    ...
    int score998 = 88;
    printf("%i\n", score);
     */
    
    /*
     数组的定义格式:
     数据类型 变量名称;
     数据类型 数组名称[数据的个数];
     元素类型 数组名称[元素个数];
     元素类型: 就是数组中需要存储的数据类型, 一旦指定, 数组中就只能存储该类型的数据
     元素个数: 就是数组中能够存储的数据(元素)的个数
     */
    int num;
    num = 12;
    printf("num = %i\n", num);
    
    int scores[3]; // 定义了一个名称叫做scores的数组, 数组中可以存放3个int类型的数据
//    scores = 12; // 系统搞不清楚应该赋值给谁
    // 只要定义一个C语言的数组, 系统就自动会给数组中的每一块小得存储空间一个编号
    // 这个编号从0开始, 一次递增
    // 数组中系统自动绑定的编号, 我们称之为 索引
    scores[0] = 12;
    scores[1] = 66;
    scores[2] = 59;
    
    printf("scores[0] = %i\n", scores[0]);
    
    
    return 0;
}
