//
//  main.c
//  折半查找练习
//
//  Created by xiaomage on 15/6/10.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int insertValue(int nums[], int length, int key);

int main(int argc, const char * argv[]) {
    // 现有一个有序的数组, 要求给定一个数字, 将该数字插入到数组中, 还要保证数组是有序的
    // 其实就是找到需要插入数字的位置
    // 其实这个位置就是min的位置
    /*
     min = 0
     max = 4
     mid = 2
     */
//                 0  1  2  3  4  5
    int nums[5] = {1, 3, 5, 7,9};
    int key = 4;
    int length = sizeof(nums) / sizeof(nums[0]);
    printf("需要插入的位置是%i\n", insertValue(nums, length, key));
           
    return 0;
}

int insertValue(int nums[], int length, int key)
{
    int min , max, mid;
    min = 0;// 1 2
    max = length - 1;// 4  1
    while (min <= max) {
        mid = (min + max) / 2; // 2 0 1
        if (key > nums[mid]) {
            min = mid + 1;
        }else if (key < nums[mid])
        {
            max = mid - 1;
        }
    }
    return min;
}
