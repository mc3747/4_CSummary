//
//  main.c
//  位运算符练习1
//
//  Created by xiaomage on 15/6/9.
//  Copyright (c) 2015年 itcast. All rights reserved.
//

#include <stdio.h>

void printBinay(int value);

int main(int argc, const char * argv[]) {
    /*
     要求定义一个函数, 传入一个整数, 输出该整数的二进制
     %i %o %x
     
     0000 0000 0000 0000 0000 0000 0000 1001
    &0000 0000 0000 0000 0000 0000 0000 0001
     
     // 1.让9的二进制向右移31, 就可以获取到9得最高位的二进制, 然后让9的二进制的最高位和1相&, 那么就可以获得9的最高位
     // 2.让9的二进制向右移30, 就可以获得9二进制的第二位
     // 3.以此类推, 直到0位置
     
     技巧:
     1.任何数与1相&都是那个数
     2.利用位移取出每一位
     */
    int num = 15;
    printBinay(num);
    return 0;
}
void printBinay(int value)
{
    // 1.定义变量需要向右移动的位数
    int offset = 31;
    // 2.通过循环取出每一位
    while (offset >=0) {
        int result  = (value >> offset) & 1;
        printf("%i", result);
        // 3.每次取出一位就让控制右移的变量-1
        offset--;
        if ((offset+1) % 4 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}
