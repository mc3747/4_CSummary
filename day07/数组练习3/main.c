//
//  main.c
//  数组练习3
//
//  Created by xiaomage on 15/6/10.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // 从键盘输入3个0~9的数字,然后输出0~9中哪些数字没有出现过
    // 从键盘输入100个0~2000的数字,然后输出0~2000中哪些数字没有出现过
    /*
     输入: 1, 3 ,5
     输出: 0, 2, 4, , 6, 7, 8, 9
     */
    /*
    // 1.接收用户输入的数据
    int num1, num2, num3;
    printf("输入三个整数, 用逗号隔开\n");
    scanf("%i,%i,%i", &num1, &num2, &num3);
    
    // 2.遍历打印0~9
    for (int i = 0; i <= 9; i++) {
        // 3.判断当前打印的值是否是用户输入的值, 如果是就不打印
        if (num1 != i &&
            num2 != i &&
            num3 != i) {
            
            printf("%i\n", i);
        }
    }
     */
    
    // 空间换时间
    // 1.定义数组保存所有用户输入的数
    int nums[10] = {0};
    // 2.接收用户输入的数据
    int value = -1;
    for (int i = 0; i < 3; i++) {
        printf("请输入%i个整数\n", i+1);
        scanf("%i", &value);
        nums[value] = 1;
    }
    
    for (int i = 0; i < 10; i++) {
//        printf("nums[%i] = %i\n", i , nums[i]);
        if (nums[i] != 1) {
            printf("%i\n", i);
        }
    }
    
    return 0;
}
