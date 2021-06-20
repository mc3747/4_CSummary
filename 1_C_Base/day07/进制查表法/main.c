//
//  main.c
//  进制查表法
//
//  Created by xiaomage on 15/6/10.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>
void printfBinary(int value);
void printfBinary2(int value);
void printOct(int value);
void printfHex(int value);

void printfHex2(int value);
void printfOct2(int value);
void printfBinary3(int value);

int main(int argc, const char * argv[]) {
    /*
         0000000000000000000000000000
     00000000000000000000000000000111
     */
    int num = 10;// 1010;
//    printfBinary2(num);
//    printOct(num);
//    printfHex2(num);
//    printfOct2(num);
    printfBinary3(num);
    return 0;
}

void printfBinary3(int value)
{
    // 1.定义一个数组, 用于保存二进制中所有的取值
    char charValues[] = {'0', '1'};
    // 2.定义一个数组, 用于保存查询后的结果
    char results[32] = {'0'};
    // 3.定义一个变量, 用于记录当前需要存储到查询结果数组的索引
    int pos = 32;
    
    while (value != 0) {
        // 1.取出1位的值
        int res = value & 1;
        // 2.利用取出来得值到表中查询对应的结果
        char c = charValues[res];
        // 3.存储查询的结果
        results[--pos] = c;
        // 4.移除二进制被取过的1位
        value = value >> 1;
    }
    
    // 4.打印结果
    for (int i = pos; i < 32; i++) {
        printf("%c", results[i]);
    }
    printf("\n");

    
}

void printfOct2(int value)
{
    // 1.定义一个数组, 用于保存八进制中所有的取值
    char charValues[] = {'0', '1', '2', '3', '4', '5', '6', '7'};
    // 2.定义一个数组, 用于保存查询后的结果
    char results[11] = {'0'};
    // 3.定义一个变量, 用于记录当前需要存储到查询结果数组的索引
    int pos = 11;
    while (value != 0) {
        // 1.取出3位的值
        int res = value & 7;
        // 2.利用取出来得值到表中查询对应的结果
        char c = charValues[res];
        // 3.存储查询的结果
        results[--pos] = c;
        // 4.移除二进制被取过的三位
        value = value >> 3;
    }
    
    // 4.打印结果
    for (int i = pos; i < 11; i++) {
        printf("%c", results[i]);
    }
    printf("\n");
    
}

void printfHex2(int value)
{
    // 1.定义一个数组, 用于保存十六进制中所有的取值
    // 规律: 取出的4个二进制位得到的值, 正好是数组中角标对应的值
    char charValues[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
//                    '', '', '', '', '', '', '', ''
    char results[8] = {'0'};
    int pos = 8;
    
    while (value != 0) {
        // 取出4位的值
        int res = value & 15;
        // 利用这个值作为索引去数组中查询对应的十六进制的值
        char c = charValues[res];
//        printf("%c", c);
        // 将取出来得值放到用于存储结果数组中
        results[--pos] = c;
        
        // 每取完一次就干掉它最低的4位
        value = value >> 4;
//        printf("pos = %i\n", pos);
    }
    
    for (int i = pos; i < 8; i++) {
        printf("%c", results[i]);
    }
    printf("\n");
}

void printfHex(int value)
{
    for (int i = 0; i <= 8; i++) {
        int res = value & 15; // 1111
        // 对十六进制进行特殊处理
        if (res > 9) {
            //  11 - 10 1 + a
            char c = res - 10 + 'a';
            printf("%c", c);
        }else
        {
            printf("%i", res);
        }
        value = value >> 4;
    }
}

void printOct(int value)
{
    for (int i = 0; i <= 11; i++) {
        int res = value & 7; // 111
        printf("%i", res);
        value = value >> 3;
    }
}

void printfBinary2(int value)
{
    for (int i = 0; i <= 32; i++) {
        int res = value & 1;
        printf("%i", res);
        value = value >> 1;
    }
    printf("\n");
}

void printfBinary(int value)
{
//    int offset = sizeof(value) * 8 - 1;
    int offset = (sizeof(value) << 3) - 1;
    while (offset >= 0) {
        int res = (value >> offset) & 1;
        printf("%i", res);
        offset--;
    }
    printf("\n");
}
