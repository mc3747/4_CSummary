//
//  main.c
//  数组和函数
//
//  Created by xiaomage on 15/6/10.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

// 基本数据类型作为函数的参数是值传递
// 如果形参是基本数据类型, 在函数中修改形参的值不会影响到实参的值
void change(int value)
{
    value = 55;
}

// 注意: 数组名作为函数的参数传递, 是传递的数组的地址
// 因为数组名就是数组的地址 &number = &number[0] == number
// 注意: 如果数组作为函数的形参, 元素的个数可以省略
// 如果形参是数组, 那么在函数中修改形参的值, 会影响到实参的值
//void change2(int values[2])
void change2(int values[])
{
//    values[0] = 88;
    values[1] = 99;
}
int main(int argc, const char * argv[]) {
    /*
    int num = 10;
    change(num);
    printf("num = %i\n", num);
     */
    
    int nums[2] = {1, 5};
    /*
    change2(nums); // 相当于传递了数组的地址
    printf("nums[1] = %i\n", nums[1]);
     */
    change(nums[0]);
    printf("nums[0] = %i\n", nums[0]);
    return 0;
}
