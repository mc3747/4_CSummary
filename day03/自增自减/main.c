//
//  main.c
//  自增自减
//
//  Created by xiaomage on 15/6/4.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    // 1.自增自减基本概念
    /*
    int result = 10;
//    result = result + 5;
//    result += 5;
    
//    result = result + 1;
//    result += 1;
    // 自增: 如果想让某一个数加1可以使用自增
//    result++;
//    result++;
//    result = result - 1;
//    result -= 1;
    // 自减: 如果想让某一个数减1可以使用自减
//    result--;
     */
    
    // 2.自增的两种写法
    /*
//    result++;
//    ++result;
    // 自减的两种写法
    result--;
    --result;
     printf("result = %i\n", result);
    */
    
    // 3.自增自减写在前面和后面的区别
    /*
    // 如果++写在变量的前面, 那么会先将变量自增再用自增之后的结果参与运算
    // 如果++写在变量的后面, 那么会先将变量的值参与运算再将变量自增
    // 总结一句话: ++在前, 先自增再运算, ++在后, 先运算再自增
    int a = 10;
//    int b = a++;// b = 10, a = 11
//    int b = ++a;// a = 11,  b = 11;
//    int b = a--;// b = 10, a = 9;
    int b = --a; // a = 9, b = 9;
    printf("a = %i , b = %i\n", a, b);
     */
    
    /*
    // 无论++在前还是在后, 最终都会自增一次
    int a = 10;
    //       10   +  12
//    int b = (a++) + (++a);
    // a = 12
    // b = 22
    
    //        10  +   11
//    int b = (a++) + (a++);
    // a = 12
    // b = 21
//           11   +   12
    int b = (++a) + (++a);
    // a = 12
    // b = 23
    printf("a = %i, b = %i\n", a, b);
     */
    
    /*
//    5++;
    double doubleValue = 10.9;
    doubleValue++;
    printf("%f", doubleValue);
     */
    
    int a = 10;
//    int b = a++;
    // b = a; a = a + 1;
    
    int b = ++a;
    // a = a + 1; b = a;
    printf("a = %i, b = %i\n", a, b); // a = 11, b = 11
    
    return 0;
}
