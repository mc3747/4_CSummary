//
//  main.c
//  逻辑运算符
//
//  Created by xiaomage on 15/6/4.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    /*
     逻辑运算符的返回值只有两种: 要么真要么假, 要么是1(真), 要么是0(假)
     &&(与运算)
     格式: 表达式1 && 表达式2
     结合性: 从左至右
     只有表达式1和表达式2都为真的时候, 逻辑与表达式才返回真
     如果表达式1或者表达式2中有一个是假, 那么逻辑与表达式返回的结果都是假
     口诀: 一假则假
     
     ||(或运算)
     格式: 表达式1 || 表达式2
     结合性: 从左至右
     只要表达式1或者表达式2中有一个是真的, 逻辑或表达式返回的值就是真
     只有表达式1和表达式2的值都是假, 逻辑或的值才是假
     口诀: 一真则真
     
     !(非运算)
     格式: !表达式
     结合性: 从右至左
     如果表达式是真, 就返回假
     如果表达式是加, 就返回真
     取反
     */
    
    // 1.基本使用
    /*
    //             1 &&  0
    int result = 10 > 8 && 5 > 8;
    printf("result = %i\n", result);
     */
    
    /*
    //              1 ||    0
    int result = 10 > 18 || 15 > 8;
    printf("result = %i\n", result);
     */
    
    /*
    int result = !(10 > 18);// !0
    printf("result = %i\n", result);
     */
    
    // 2.注意点:
    /*
    // 由于C语言规定, 任何数值都有真假性, 非0即真. 所有逻辑运算符可以直接与数值进行计算
//    int result = 0 && 11;
//    int result = 0 || 0;
    // 逻辑非结合性: 从右至左
    int result = !!!!!!1;// 0
    printf("result = %i\n", result);
     */
    
    // 由于逻辑与有一个特点: 一假则假, 所以如果前面的表达式的值为假, 那么后面的表达式没有必要参与运算
//    int result = 10 > 18 && 9 > 5;
    
//    int a = 10;
//    int result = 10 > 18 && ++a > 5;
//    printf("result = %i , a = %i\n", result, a);
    
    // 由于逻辑或有一个特点: 一真则真, 所以如果前面的表达式的值为真, 那么后面的表达式没有必要参与运算

    // 逻辑与和逻辑或的这个特点, 称之为逻辑运算符的短路
    int a = 10;
    int result = 10 > 18 || ++a > 5;
    printf("result = %i , a = %i\n", result, a);
    
    
    
    return 0;
}
