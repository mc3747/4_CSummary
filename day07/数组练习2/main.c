//
//  main.c
//  数组练习2
//
//  Created by xiaomage on 15/6/10.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int arrayMax(int values[], int length);
int arrayMax2(int values[], int length);

int main(int argc, const char * argv[]) {
    //  设计一个函数int arrayMax(int a[], int count)找出数组元素的最大值
    int nums[5] = {-99, -188, -5, -100, -77};
    int length = sizeof(nums) / sizeof(nums[0]);
//    int max =  arrayMax(nums, length);
    int max = arrayMax2(nums, length);
    printf("max = %i\n", max);
    
    return 0;
}

int arrayMax2(int values[], int length)
{
    // 1.定义变量, 保存数组中最大值的角标(索引)
    int max = 0;
    // 2.遍历数组
    for (int i = 1; i < length; i++) {
        // 3.取出数组中对应角标的元素的值进行比较
        if (values[max] < values[i]) {
            // 如果当前遍历到的角标对应的元素的值大于max这个角标对应元素的值
            // 那么就将当前的角标最为最大值的角标
            max = i;
        }
    }
    return values[max];
}

int arrayMax(int nums[], int length)
{
    // 1.定义一个变量, 假设为最大值
//    int max = 0; // 注意: 不能假设一个不是数组中的值最为最大
    int max = nums[0];
    // 2.遍历数组
    for (int i = 1; i < length; i++) {
        // 3.依次取出数组中每一个元素的值, 和假设的最大值进行比较
        // 如果数组的元素大于假设的最大值, 就让当前元素的值作为最大值
        if (max < nums[i]) {
            max = nums[i];
        }
    }
    return max;
}


