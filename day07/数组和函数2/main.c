//
//  main.c
//  数组和函数2
//
//  Created by xiaomage on 15/6/10.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>
//void printArray(int values[5]);
void printArray(int values[5], int length);

int main(int argc, const char * argv[]) {
    // 要求定义一个函数, 实现遍历数组. (只要别人传递数组给函数, 就要求输出数组中所有元素的值)
    int nums[3] = {1 , 3 , 5};
//    printf("size = %i\n", sizeof(nums));
    
    int length = sizeof(nums) / sizeof(nums[0]);
    
    printArray(nums, length); // 数组名称就是数组的地址
    return 0;
}

// 如果传递的数组的名称, 其实传递的是地址
// 如果传递的是地址, 其实传递的是指针
// 指针在64位编译环境占8个字节

// 注意: 如果数组作为形参, 那么在函数中就不能通过数组的名称计算出数组元素的个数
// 因为系统会自动将数组形参转换为指针, 指针占用8个字节
void printArray(int values[5], int length)
{
//    printf("size = %i\n", sizeof(values));
    
    // 1.动态计算数组的元素个数
//    int length = sizeof(values) / sizeof(values[0]);
    // 2.遍历数组
    for (int i = 0; i < length; i++) {
        printf("values[%i] = %i\n", i,values[i]);
    }
}
