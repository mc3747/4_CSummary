//
//  main.c
//  scanf函数
//
//  Created by xiaomage on 15/6/3.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // 1.要求: 存储用户输入的整数
    /*
    // 1.用户输入的整数确定吗? 不确定 --> 定义变量
    // 2.如何接收用户输入的整数? scanf函数
    // scanf格式: scanf("格式化字符串", 列表项); --> scanf("%i", 变量);
    
    // 1.定义变量
    int number;
    // 2.利用scanf函数接收用户输入的数据
    scanf("%i", &number);// 注意: 必须告诉scanf函数变量的详细地址, 才能存储用户输入的数据
    // 3.输出接收到的数据
    printf("number = %i", number);
     */
    
    // 2.要求从控制台接收用户输入的两个整数, 然后计算两个整数的和
    /*
    // 0.提示用户输入数据
    printf("亲, 请输入第一个数字, 以回车键结束\n");
    // 1.定义两个变量保存用户输入的数据
    int num1, num2;
    // 2.利用scanf接收用户输入的数据
    // 2.1接收第一个数
    scanf("%i", &num1);
    printf("亲, 请输入第二个数字, 以回车键结束\n");
    scanf("%i", &num2);
    
    // 3.将接收到的两个数相加
    int result = (num1 + num2);
    
    // 4.输出两个数验证结果
    printf("result = %d", result);
     */
    /*
    int num1, num2;
    num1 = num2 = 10;
    printf("num1 = %i, num2 = %i", num1, num2);
     */
    
    /*
    // 0.提示用户输入数据
    printf("亲, 请输入两个数字, 以回车键结束\n");
    // 1.定义两个变量保存用户输入的数据
    int num1, num2;
    // 2.利用scanf接收用户输入的数据
    // 注意: 利用scanf接收多个数据的时候, 输入的内容要求和"格式化字符串"中的一模一样
    // 如果输入的数据与格式化字符串中的不匹配, 那么scanf函数会自动终止
//    scanf("%i,%i", &num1, &num2);
    // 如果多个数据之间没有其它字符, 那么可以利用 空格, 回车, table来作为分隔
    // 但是, 如果格式化字符串中有%c除外
//    scanf("%i%i", &num1, &num2);
    char charValue;
    // 输入: 123-->num1, a -->charValue, 456-->num2
    // 技巧: 无论想接收什么类型的数据, 只要有需要一次性接收多个, 就给每一个数据之间加上固定的符号作为分隔符(例如: ,)
    scanf("%i-%c-%i", &num1, &charValue, &num2);
    
    // 3.将接收到的两个数相加
//    int result = (num1 + num2);
    
    // 4.输出两个数验证结果
//    printf("result = %d", result);
    
    printf("num1 = %i, char = %c , num2 = %i", num1, charValue, num2);
     */
    
    // 3.\n问题
    int number, number2;
    // \n代表换行
    // 如何告诉scanf函数我们输入完毕? 回车 == \n
    // 因为回车是scanf的结束符, 所以不能在scanf的格式化字符串末尾写上\n
    // 如果不小心把\n放到了scanf格式化字符串的末尾, 也可以破, 原样输入或输入一个不匹配的类型
    scanf("%i\n%i\n", &number, &number2);
    printf("number = %i , number2 = %i\n", number, number2);
    return 0;
}
