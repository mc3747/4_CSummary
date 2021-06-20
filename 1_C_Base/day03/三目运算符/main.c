//
//  main.c
//  三目运算符
//
//  Created by xiaomage on 15/6/4.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    /*
    int a = 20;
    int b = 15;
//    int result = a > b;
    // 三目运算符格式: 条件表达式 ? 结果A : 结果B
    // 结合性: 从左至右
    // 只要条件表达式为真就返回结果A, 如果条件表达式为假, 那么就返回结果B
    // a大于b吗? 如果a大于b就返回a, 否则返回b
//    int result = (a > b)? a : b;
    
    // 三目运算符的优先级: 低于关系运算符和算术运算符
    //             25 > 15 ? 20 : 15
    int result = a + 5 > b ? a : b;
    
    printf("result = %i\n", result);
     */
    
    
    // 从键盘输入3个整数, 利用三目运算符取出最大值并输出
    // 1.提示用于输出三个整数, 用逗号隔开, 以回车结束
    printf("请输入三个整数, 用逗号隔开, 以回车结束\n");
    // 2.定义三个变量保存用户输入的数据
    int num1, num2, num3;
    // 3.利用scanf函数接收用户输入的数据
    scanf("%i,%i,%i", &num1, &num2, &num3); // 17, 5, 88
    // 4.比较三个数的大小, 取出最大值
    // 4.1获取num1和num2中的最大值
//    int temp = num1 > num2 ? num1 : num2;// 17 > 5 ? 17 : 5; temp = 17
    // 4.2利用num1和num2中的最大值和剩下的num3比较
//    int result = temp > num3 ? temp : num3;// 17 > 88 ? 17 : 88; result = 88
    
    // youtube写法 usb写法
    // 1.阅读性比较差
    // 2.性能也比较差
    int result = (num1 > num2 ? num1 : num2) > num3 ? (num1 > num2 ? num1 : num2) : num3;
    // 5.输出结果
    printf("result= %i\n", result);
    
    return 0;
}
