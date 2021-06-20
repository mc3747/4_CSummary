//
//  main.c
//  day03
//
//  Created by xiaomage on 15/6/3.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // 1.类型转换
    /*
    // int 占用4个字节 double 占用8个字节
    // 只是相同类型的数据才能进行运算, 隐式类型转换 将小类型转换为大类型, 然后再进行运算
    // 在赋值的时候系统又给我们进行了一次隐式类型转换
    // 发现, 如果在隐式类型转换的时候, 将大类型转换为小类型会丢失精度
    int result = 10.9;
    printf("result = %d\n", result);
    
    // 强制类型转换格式: (类型)被强制类型转换的数据
    int result2 = (int)10.9;
    printf("result2 = %i", result2);
    
    // 自动类型提升
    // 自动类型的提升, 将参与运算的数据都转换为同一类型后再运算
    // 会自动将小的数据类型提升为大的数据类型
    int result3 = 1 + 9.9; // 1.0 + 9.9 = 10.9
     */
    
    /*
    // 在算术运算中, 参与运算的是什么类型, 计算出来就是什么类型
//    double result = 1.0 / 2; // 1.0 / 2.0 --> 0.5
//    double result = (double)1 / 2;// 1.0 / 2.0 --> 0.5
    double result = (double)(1 / 2); // (double)(0) --> 0.0
    printf("result = %lf\n", result);
     */
    
    // 2.算术运算符的结合性, 左结合, 从左至右的计算
    // 3.算术运算符的优先级 * / % 大于 + -
    // 如果优先级和结合同时存在, 那么先优先级再结核性
    int result = 3 + 4 * 5 + 6;
    printf("result = %i\n", result);
    
    return 0;
}

void test()
{
    /*
     + 加法
     - 减法
     * 乘法
     / 除法
     % 取模(取余)
     */
    // 1.定义变量保存计算结果
    int result;
    // 2.开始计算
    result = 1 + 1;
    result = 1 - 1;
    result = 2 * 2;
    result = 6 / 3;
    // 注意: 取模运算只能用于整数
//    result = 10 % 3;
//    result = 12 % 5;
//    result = 10.0 % 3.0;
    // 取模运算的正负性取决于左边的操作数, 如果左边为负数, 那么结果就是负数
//    result = 10 % -3;
//    result = -10 % -3;
//    result = -10 % 3;
    
    // 如果取模运算的左边小于右边, 那么结果就是左边
    result = 2 % 9;
    
    // 3.验证计算结果
    printf("result = %i", result);
}
