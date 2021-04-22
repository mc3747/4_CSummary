//
//  main.c
//  if练习
//
//  Created by xiaomage on 15/6/4.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // 1.从键盘输入一个整数，判断其是否是偶数，如果是偶数就输出YES，否则输出NO；
    /*
    // 1.提示用户输入一个整数
    printf("请输入一个整数, 以回车结束\n");
    // 2.定义变量保存用户输入的正常
    int number = -1;
    // 3.接收用户输入的整数
    scanf("%i", &number);
    // 4.判断是否是偶数(偶数的特点: 可以被2整数, 没有余数)
//    int result = number % 2;
    if ((number % 2) == 0) {
        printf("YES\n");
    }else
    {
     // 5.输出结果
        printf("NO\n");
    }
     */
    
    /*************************华丽的分割线*******************************/
    
    // 2.接收用户输入的1～7的整数，根据用户输入的整数，输出对应的星期几
    /*
    // 1.提示用户输入1~7的整数
    printf("请输入一个1~7的整数, 以回车结束\n");
    // 2.定义变量保存
    int number = -1;
    // 3.接收用户输入的整数
    scanf("%i", &number);
    // 4.判断用户输入的整数, 输出对应的结果
    // 4.1排除非法数据
  
//    if (number>7 || number<1) {
//        printf("USB\n");
//        return 0;  结束函数
//    }
   
    
    if (number>7 || number<1) {
        printf("USB\n");
    }else if (number == 1) {
        printf("星期1\n");
    }else if (number == 2) {
        printf("星期2\n");
    }else if (number == 3) {
        printf("星期3\n");
    }else if (number == 4) {
        printf("星期4\n");
    }else if (number == 5) {
        printf("星期5\n");
    }else if (number == 6) {
        printf("星期6\n");
    }else if (number == 7) {
        printf("星期7\n");
    }
    
    printf("其它操作\n");
     */
    
     /*************************华丽的分割线*******************************/
    
    // 3.接收用户输入的一个整数month代表月份，根据月份输出对应的季节
    // 3~5 春季 6~8 夏季 9~11 秋季 12 1 2冬季
    /*
    // 1.提示用户输入一个整数
    printf("请输入一个整数, 以回车结束\n");
    // 2.定义变量保存用户输入的正常
    int number = -1;
    // 3.接收用户输入的整数
    scanf("%i", &number);
    // 4.根据用户输入的整数, 输出对应的季节
     */
    /*
    if (number >= 3 && number <= 5) {
        printf("春季");
    }else if (number >= 6 && number <= 8)
    {
        printf("夏季");
    }else if (number >= 9 && number <= 11)
    {
        printf("秋季");
    }else if (number == 12 || number == 1 || number == 2)
    {
        printf("穿秋裤的季节");
    }else
    {
        printf("地球不属于你\n");
    }
     */
    /*
    if (number >12 || number < 1) {
         printf("地球不属于你\n");
    }else if (number >= 3 && number <= 5) {
        printf("春季");
    }else if (number >= 6 && number <= 8)
    {
        printf("夏季");
    }else if (number >= 9 && number <= 11)
    {
        printf("秋季");
    }else
    {
        printf("穿秋裤的季节");
    }
     */
    
     /*************************华丽的分割线*******************************/
    
    // 4.键盘输入两个整数，判断大小后输出较大的那个数
    /*
    // 1.提示用户输入两个整数
    printf("请输入一个整数, 以回车结束\n");
    // 2.定义变量保存用户输入的整数
    int number1 = -1;
    int number2 = -1;
    // 3.接收用户输入的整数
    scanf("%i,%i", &number1, &number2);
    // 4.比较两个数的大小
//    int max = number1 > number2 ? number1 : number2;
    int max = -1; // 保存最大值
    if (number1 > number2) {
        max = number1;
        number1 = 0;
    }else
    {
        max = number2;
        number2 = 0;
    }
    printf("max = %i\n", max);
    printf("number1 = %i, number2 = %i\n", number1, number2);
     */
    /*
     三目运算符可以简化if else的操作, 如果仅仅是为了获取某个值, 那么建议使用三目运算符
     if else: 可以用来做一些更复杂的操作, 例如判断完毕之后还需要进行一些后续处理
     */
    
     /*************************华丽的分割线*******************************/
    
    // 5.从键盘输入3个整数，判断大小后输出较大的那个数
    /*
    // 1.提示用户输入3个整数
    printf("请输入3个整数, 以回车结束\n");
    // 2.定义变量保存用户输入的整数
    int number1 = -1;
    int number2 = -1;
    int number3 = -1;
    // 3.接收用户输入的整数
    scanf("%i,%i,%i", &number1, &number2, &number3);

    // 4.获取最值
    int max = -1; // 保存最大值
     */
    /*
    max = number1 > number2 ? number1 : number2;
    max = max > number3 ? max : number3;
    printf("max = %i\n", max);
     */
    /*
    if (number1 > number2 && number1 > number3) {
        max = number1;
    }else if (number2 > number1 && number2 > number3)
    {
        max = number2;
    }else if (number3 > number1 && number3 > number2)
    {
        max = number3;
    }
    printf("max = %i\n", max);
     */
    /*
    if (number1 > number2) {
        // 代表number1当前最大
        if (number1 > number3) {
            max = number1; // number1是最大
        }else
        {
            max = number3; // number3是最大
        }
    }else if (number2 > number3) // 此时此刻number2是最大的
    {
        // 代表number2当前最大
        max = number2;
    }else
    {
        max = number3;
    }
    printf("max = %i\n", max);
     */
    
     /*************************华丽的分割线*******************************/
    
    // 6.从键盘输入3个整数，排序后输出
   
    // 1.提示用户输入3个整数
    printf("请输入3个整数, 以回车结束\n");
    // 2.定义变量保存用户输入的整数
    int number1 = -1;
    int number2 = -1;
    int number3 = -1;
    // 3.接收用户输入的整数
    scanf("%i,%i,%i", &number1, &number2, &number3);
    // 4.排序
    
    /*
    if (number1 > number2 && number2 > number3) {
        printf("%i, %i , %i\n", number1, number2, number3);
    }else if (number1 > number3 && number3 > number2)
    {
         printf("%i, %i , %i\n", number1, number3, number2);
    }else if (number2 > number1 && number1 > number3)
    {
        printf("%i, %i , %i\n", number2, number1, number3);
    }else if (number2 > number3 && number3 > number1)
    {
        printf("%i, %i , %i\n", number2, number3, number1);
    }else if (number3 > number1 && number1 > number2)
    {
        printf("%i, %i , %i\n", number3, number1, number2);
    }else if (number3 > number2 && number2 > number1)
    {
        printf("%i, %i , %i\n", number3, number2, number1);
    }
     */
    /*
    // 如何交换两个变量的值
    int a = 10; // 可乐
    int b = 5; // 雪碧
    int temp  = -1;
    printf("交换前: a = %i, b = %i\n", a, b);
    temp = a;
    a = b;
    b = temp;
    printf("交换后: a = %i, b = %i\n", a, b);
     */
    // 4.1利用number1和number2进行比较, 如果number1小于number2交换两个变量的值
    if (number1 < number2) {
        int temp = number1;
        number1 = number2;
        number2 = temp;
    }
    if (number1 < number3) {
        int temp = number1;
        number1 = number3;
        number3 = temp;
    }
    if (number2 < number3) {
        int temp = number2;
        number2 = number3;
        number3 = temp;
    }
    
    printf("%i, %i, %i\n", number1, number2, number3);
    return 0;
}
