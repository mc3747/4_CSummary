//
//  main.c
//  选择排序
//
//  Created by xiaomage on 15/6/10.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // 已知一个无序的数组, 里面有5个元素, 要求对数组进行排序
    int nums[8] = {99, 12, 88, 34, 5, 44, 12, 100};
    
    /*
    int a = 10;
    int b = 12;
    int c = 5;
    
    printf("%i, %i, %i\n", a, b, c);
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    if (a > c)
    {
        int temp = a;
        a = c;
        c = temp;
    }
    
    if (b > c) {
        int temp = b;
        b = c;
        c = temp;
    }
    
    printf("%i, %i, %i\n", a, b, c);
     */
    int length = sizeof(nums) / sizeof(nums[0]);
    printf("length = %i\n", length);
    for (int i = 0; i < length; i++) {
        printf("nums[%i] = %i\n", i, nums[i]);
    }
    
    // length - 1是为了防止角标越界
    // length - 1因为最后一个元素已经没有可以比较的了
    // 0, 1, 2, 3, 4
    for (int i = 0; i < length - 1; i++) {
        for (int j = i+1; j < length; j++) {
//            printf("*");
//            printf("i = %i, j = %i\n", i, j);
            if (nums[i] > nums[j]) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
//        printf("\n");
    }
    
    printf("--------------\n");
    for (int i = 0; i < length; i++) {
        printf("nums[%i] = %i\n", i, nums[i]);
    }
    
    return 0;
}
