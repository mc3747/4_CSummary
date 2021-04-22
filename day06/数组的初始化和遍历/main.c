//
//  main.c
//  数组的初始化和遍历
//
//  Created by xiaomage on 15/6/9.
//  Copyright (c) 2015年 itcast. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // 需求保持全班101个人的分数
    // 元素类型 数组名称[元素个数];
    /*
    // 先定义再初始化
    int scores[5];
    scores[0] = 99;
    scores[1] = 88;
    scores[2] = 77;
    scores[3] = 66;
    scores[4] = 100;
     */
    /*
    int num;
    num = 10;
    
    int num1 = 10;
     */
    // 依次将{}中的每一个值赋值给数组中的每一个元素
    // 并且从0开始赋值
    // 也称之为数组的初始化(完全初始化)
    int scores[5] = {99,88,77,66,100};
    
    // 部分初始化
    // 默认从0开始初始化, 依次赋值
    // 注意: 如果"在部分初始化中"对应的内存没有被初始化, 那么默认是0
    int scores1[3] = {11, 22};
    printf("0 = %i\n", scores1[0]);
    printf("1 = %i\n", scores1[1]);
    printf("2 = %i\n", scores1[2]);
    
    printf("-------\n");
    
    // 注意: 如果没有对数组进行初始化(完全和部门), 那么不要随便使用数组中的数据, 可能是一段垃圾数据(随机值)
    int scores2[3];
    printf("0 = %i\n", scores2[0]);
    printf("1 = %i\n", scores2[1]);
    printf("2 = %i\n", scores2[2]);
    
    printf("-------\n");
    
    // 注意: 定义数组的时候, 数组的元素个数不能使用变量, 如果使用变量, 那么数组中是一些随机值
    int num = 10;
    int scores3[num];
    printf("0 = %i\n", scores3[0]);
    printf("1 = %i\n", scores3[1]);
    printf("2 = %i\n", scores3[2]);
    
    // 注意: 不建议使用变量定义数组, 如果使用了变量定义数组, 作为数组的元素个数, 不初始化的情况下是随机值, 如果初始化会直接报错
//    int num2 = 10;
//    int scores4[num2] = {11, 12};
     printf("-------\n");
    
    // 注意: 如果定义的同时进行初始化, 那么元素的个数可以省略
    // 省略之后, 初始化赋值几个数据, 那么数组的长度就是几. 也就是说数组将来就能存储几个数据
    int scores5[] = {1, 3};
    printf("0 = %i\n", scores5[0]);
    printf("1 = %i\n", scores5[1]);
    printf("-------\n");
    
    // 注意; 如果定义数组时没有进行初始化, 那么不能省略元素个数
//    int scores6[];
    
//    0 1 2 3 4
//    int socres7[101] = {0, 0, 0, 1, 3};
//    int socres7[101];
//    socres7[99] = 1;
//    socres7[100] = 3;
    
    // 可以通过[索引] = 的方式, 给指定索引的元素赋值
    int socres7[101] = {[99] = 1, [100] = 3};
    printf("3 = %i\n", socres7[99]);
    printf("4 = %i\n", socres7[100]);

    
//    注意: 只能在定义的同时利用{}进行初始化, 如果是先定义那么就不能使用{}进行初始化
    // 如果先定义那么就不能再进行整体赋值, 只能单个赋值
//    int scores8[3];
//    scores8 = {1 , 4, 19};
//    scores8[0] = 1;
    
    return 0;
}
