//
//  main.c
//  二维数组和函数
//
//  Created by xiaomage on 15/6/12.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>
void change(int nums[]);
void change2(char names[2][3]);
void change3(char values[]);
void change4(char value);

int main(int argc, const char * argv[]) {
    /*
    int nums[2] = {1, 2};
    // 数组的名称就是数组的地址
    // &nums == nums == &nums[0]
    change(nums);
    printf("nums[0] = %i\n", nums[0]);
     */
    
    char names[2][3] =
    {
        {'l', 'n', 'j'},
        {'x', 'm', 'g'}
    };
//    &names == names == &names[0] , names就是数组的地址
    printf("&names = %p\n", &names);
    printf("names = %p\n", names);
    printf("&names[0] = %p\n", &names[0]);
    
//  二维数组名称作为函数参数传递, 是传递的地址
//    change2(names);
    // names[0] == 一维数组
//    change3(names[0]);
    
    // names[0][0] == 一维数组的一个元素 == 值
    change4(names[0][0]);
    
    printf("names[0][0] = %c\n", names[0][0]);
    return 0;
}

// 基本数据类型
void change4(char value)
{
    value = 'E';
     printf("我执行了\n");
}

// 以后只要看到函数的参数是一个数组, 那么就是地址传递
// 在函数中修改形参的值会影响到参数
void change3(char values[])
{
    values[0] = 'Q';
     printf("我执行了\n");
}

void change2(char values[2][3])
{
    values[0][1] = 'w';
    printf("我执行了\n");
}

// 数组作为函数的参数传递, 修改形参的值会影响到实参
void change(int nums[])
{
    nums[0] = 998;
    printf("我执行了\n");
}
