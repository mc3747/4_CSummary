//
//  main.c
//  结构体初始化
//
//  Created by xiaomage on 15/6/14.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    /*
    int nums[] = {1, 3, 5};
    
    int nums[3];
    nums[0] = 1;
    nums[1] = 3;
    nums[2] = 5;
     
    int nums[3];
    nums = {1, 3, 5}; // 错误
    
    int nums[3] = {[1] = 2};
     printf("nums[0] = %i\n", nums[0]);
    */
    
    struct Dog
    {
        char *name;
        int age;
        double height;
    };
    // 1.定义的同时初始化
    struct Dog sd = {"wc", 13, 5.0};
    
    // 2.先定义再初始化(逐个初始化)
    struct Dog sd1;
    sd1.name = "ww";
    sd1.age = 5;
    sd1.height = 10.9;
    
    // 3.先定义再初始化(一次性初始化)
    struct Dog sd2;
    // 特别注意: 结构体和数组有一点区别, 数组不能先定义再进行一次性的初始化, 而结构体可以
    // 只不过需要明确的告诉系统{}中是一个结构体
    sd2 = (struct Dog){"xq", 8, 8.8}; // 数组? 结构体?
    
    // 4.指定将数据赋值给指定的属性
    struct Dog sd3 = {.height = 1.77, .name = "ww", .age = 33};
    
    printf("name = %s, age = %i, height = %lf\n", sd3.name, sd3.age, sd3.height);
    
    
    return 0;
}
