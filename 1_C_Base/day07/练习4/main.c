//
//  main.c
//  练习4
//
//  Created by xiaomage on 15/6/10.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // 要求从键盘输入6个0~9的数字,排序后输出
    // 0~9999
    
    // 1.定义数组保存用户输入的数据
    int nums[10] = {0};
    // 2.接收用户的数据
    int value = -1;
    for (int i = 0; i < 6; i++) {
        printf("请输入第%i个数据\n", i + 1);
        scanf("%i", &value); // 2, 2, 1, 2
        // 7, 3, 6, 1
//        nums[value] = 1;
        nums[value] = nums[value] + 1;
    }
    
    for (int i = 0; i < 10; i++) { // i == 7
//        printf("nums[%i] = %i\n", i , nums[i]);
        /*
        if (nums[i] != 0) {
            printf("%i\n", i); // 1, 2, 2, 2
        }
         */
        for (int j = 0; j < nums[i]; j++) { // j == 1
            printf("%i\n", i); // 1, 1, 2, 3, 3, 6
        }
    }
    
    return 0;
}
