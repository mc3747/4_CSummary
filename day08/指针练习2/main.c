//
//  main.c
//  指针练习2
//
//  Created by xiaomage on 15/6/12.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>
//int demo(int v1, int v2, int v3);
int demo(int v1, int v2, int v3, int *p1, int *p2);

int main(int argc, const char * argv[]) {
    // 要求定义一个函数, 传递三个值, 返回这三个值得和,差,平局值
    int a = 10;
    int b = 20;
    int c = 30;
//    int res =  demo(a , b , c);
//    printf("res = %i\n", res);
    
    // 定义三个变量用于保存计算结果
    int res1 = 0; // 和
    int res2 = 0; // 差
//    int res3 = 0; // 平局值
    
    // *p1 == res1 *p2 == res2
    // 我们想要的就是调用完函数之后, 和差平均值对应的变量都被"修改"为对应的值
   int res3 = demo(a, b, c, &res1, &res2);
    
    printf("和 = %i, 差 = %i, 平均值 = %i\n", res1, res2, res3);
    
    return 0;
}

int demo(int v1, int v2, int v3, int *p1, int *p2)
{
    int sum = v1 + v2 + v3;
    *p1 = sum;
    int m = v1 - v2 - v3;
    *p2 = m;
    int average = sum / 3;
    
    return average;
    
    /*
    // 因为返回的是一个逗号表达式, 而逗号表达式的值是最后一个表达式的值, 所有返回的是average
//    return sum, m, average;
    */
    
    /*
    // return 连个作用 1.返回值给调用者 2.结束函数
    // 注意点: return后面不可以写任何语句, 因为执行不到
    return sum;
    printf("--------------\n");
    return m;
    return average;
     */
}
