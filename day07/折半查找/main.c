//
//  main.c
//  折半查找
//
//  Created by xiaomage on 15/6/10.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>
#include <time.h>

int findKey(int nums[], int key, int length);
int findKey2(int nums[], int length, int key);
int findKey3(int nums[], int length, int key);

int main(int argc, const char * argv[]) {
    // 现在已知一个有序的数组, 和一个key. 要求从数组中找到key对应的索引的位置
    // 对该方法进行封装, 要求找到就返回对应的索引, 找不到就返回-1
    int nums[500000] = {1, 3, 5, 7, 9, [499999] = 99};
    int key = 99;
    int length = sizeof(nums) / sizeof(nums[0]);
    
    /*
     // 消耗了多少1181毫秒
    clock_t startTime = clock();
    int index =  findKey(nums, key, length);
    clock_t endTime = clock();
    printf("消耗了多少%lu毫秒\n", endTime - startTime);
    printf("index = %i\n", index);
     */
    
    // 消耗了多少1毫秒
    clock_t startTime = clock();
//    int index = findKey2(nums, length, key);
    // 消耗了多少2毫秒
    int index = findKey3(nums, length, key);
    clock_t endTime = clock();
    printf("消耗了多少%lu毫秒\n", endTime - startTime);
    printf("index = %i\n", index);
    
    return 0;
}

int findKey3(int nums[], int length, int key)
{
    int min, max, mid;
    min = 0;
    max = length - 1;
    
    // 只要还在我们的范围内就需要查找
    while (min <= max) {
        // 计算中间值
        mid = (min  + max) / 2;
        if (key > nums[mid]) {
            min = mid + 1;
        }else if (key < nums[mid])
        {
            max = mid - 1;
        }else
        {
            return mid;
        }
        
    }
    return -1;
}

int findKey2(int nums[], int length, int key)
{
    int min, max, mid;
    min = 0;
    max = length - 1;
    mid = (min + max) / 2;
    
    while (key != nums[mid]) {
        // 判断如果要找的值, 大于了取出的值, 那么min要改变
        if (key > nums[mid]) {
            min = mid + 1;
        // 判断如果要找的值, 小雨了取出的值, 那么max要改变
        }else if (key < nums[mid])
        {
            max = mid - 1;
        }
        
        // 超出范围, 数组中没有需要查找的值
        if (min > max) {
            return -1;
        }
        // 每次改变完min和max都需要重新计算mid
        mid = (min + max) / 2;
    }
//    printf("aaaaaa\n");
    
    return mid;

}

int findKey(int nums[], int key, int length)
{
    for (int i = 0; i < length; i++) {
        if (nums[i] == key) {
//            printf("%i\n", i);
            return i;
        }
    }
    return -1;
}
