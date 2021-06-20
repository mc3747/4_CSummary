//
//  main.c
//  冒泡排序
//
//  Created by xiaomage on 15/6/10.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    /*
     思路: 
     1.先分析如何比较
     2.找出比较的规律比较完一次之后第二次比较会少一次
     3.打印倒三角
     4.打印需要比较的角标
     5.比较并交换位置
     6.将常量替换为变量(length)
     */
    // 已知一个无序的数组, 里面有5个元素, 要求对数组进行排序
    int nums[6] = {99, 12, 88, 34, 5, 7};
    int length = sizeof(nums) / sizeof(nums[0]);
    for (int i = 0; i < length; i++) {
        printf("nums[%i] = %i\n", i, nums[i]);
    }
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
//            printf("*");
//            printf("%i == %i\n", j, j+1);
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
//        printf("\n");
    }
    printf("----------\n");
    for (int i = 0; i < length; i++) {
        printf("nums[%i] = %i\n", i, nums[i]);
    }
    return 0;
}
