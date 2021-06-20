//
//  main.c
//  选择-冒泡排序优化
//
//  Created by xiaomage on 15/6/10.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

void selectSort(int nums[], int length);
void printArray(int nums[], int length);
//void swap(int v1, int v2);
void swap(int nums[], int i, int j);
void bubbleSort(int nums[], int length);

int main(int argc, const char * argv[])
{
    // 已知一个无序的数组, 里面有5个元素, 要求对数组进行排序
    int nums[8] = {99, 12, 88, 34, 5, 44, 12, 100};
    int length = sizeof(nums) / sizeof(nums[0]);
    
    printArray(nums, length);
//    selectSort(nums, length);
    bubbleSort(nums, length);
    
    printf("----------------\n");
    printArray(nums, length);

    return 0;
}

// 遍历数组
void printArray(int nums[], int length)
{
    for (int i = 0; i < length; i++) {
        printf("nums[%i] = %i\n", i, nums[i]);
    }
}

void bubbleSort(int nums[], int length)
{
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums, j, j+1);
            }
        }
    }
}

// 选择排序
void selectSort(int nums[], int length)
{
    for (int i = 0; i < length - 1; i++) {
        for (int j = i+1; j < length; j++) {
            if (nums[i] > nums[j]) {
                /*
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                 */
//                swap(nums[i], nums[j]);
                swap(nums, i, j);
            }
        }
    }

}

// 基本数据类型作为函数的参数, 是值传递, 在函数中修改形参不会影响实参的值
/*
void swap(int v1, int v2)
{
    int temp = v1;
    v1 = v2;
    v2 = temp;
}
 */
// 交换两个数的值
void swap(int nums[], int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
