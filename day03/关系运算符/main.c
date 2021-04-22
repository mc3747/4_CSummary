//
//  main.c
//  关系运算符
//
//  Created by xiaomage on 15/6/4.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    /*
     关系运算符:
     >
     <
     >=
     <=
     ==
     !=
     关系运算符的返回值只有两种, 要么真, 要么假. 1(真)和0(假)
     */
    
    // 1.基本使用
    /*
    int a = 10;
    int b = 5;
    int result = a > b;// 吗? 大于, 真, 非0即真.
    printf("result = %i\n", result);
     */
    
    /*
    int a = 10;
    int b = 8;
    int result = a != b;
    printf("result = %i\n", result);
     */
    
    // 2.关系运算符注意点
    /*
    // 关系运算符也有优先级. > < >= <= 优先级大于 == !=
    //             1 == 1
//    int result = 1 == 10 > 5;
    
    // 算术运算符的优先级 大于 关系运算符
    //             2 <  4
//    int result = 1 + 1 < 2 + 2;
    
    // 关系运算符的结合型: 从左至右
    //              1 > 1
//    int result = 10 > 3 > 1;
    
    // 如果优先级和结合性同时存在, 先优先级再结核性
    //              11 > 9 == 3 > 1
    //               1 == 3 > 1
    //               1 == 1
    int result = 10 + 1 > 5 + 4 == 3 > 1;
    
    printf("result = %i\n", result);
     */
    
    // 3.练习
//    int result = 3 > 4 + 7; // 3 > 11 = 0
//    int result = (3>4) + 7; // 0 + 7
//           5 != 4 + 14 > 3 == 10
//           5 != 18 > 3 == 10
//           5 != 1 == 10
//           1 == 10
    int result = 5 != 4 + 2 * 7 > 3 == 10;
    printf("result = %i\n", result);
    return 0;
}
