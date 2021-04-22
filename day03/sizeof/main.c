//
//  main.c
//  sizeof
//
//  Created by xiaomage on 15/6/4.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // sizeof可以用来计算一个变量或一个常量、一种数据类型所占的内存字节数
    // 注意: sizeof是一个运算符, 不是一个函数
    // 利用sizeof计算的格式: sizeof(变量/常量/数据类型);
    
    // 1.计算常量占用的内存字节数
    /*
//    int number = sizeof(10);// 10是一个整型常量, 整型 == int == 4
    // 如果利用sizeof计算常量, 那么可以省略()
    int number = sizeof 10;
    printf("number = %i\n", number);
     */
    
    // 2.计算变量
    /*
    double doubleValue = 10.9;// doubleValue是实型 , 实型 ==  double == 8
//    int number = sizeof(doubleValue);
     // 如果利用sizeof计算变量, 那么可以省略()
    int number = sizeof doubleValue;
    printf("number = %i\n", number);
     */
    
    // 3.计算数据类型
    /*
    int number = sizeof(char);
    // 注意: 如果利用sizeof计算数据类型, ()不能省略
//    int number = sizeof char;
    printf("number = %i\n", number);
     */

    return 0;
}
