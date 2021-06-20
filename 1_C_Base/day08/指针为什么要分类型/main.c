//
//  main.c
//  指针为什么要分类型
//
//  Created by xiaomage on 15/6/12.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    /*
    char *cp;
    int *ip;
    double *dp;
    double **dpp;
    // mac系统中的指针无论是什么类型, 几级真正都占用8个字节
    // 由于Mac是64位了,  32  = 4 * 8;  64 = 8 * 8;
    printf("cp = %lu, ip = %lu, dp = %lu, dpp = %lu\n", sizeof(cp), sizeof(ip), sizeof(dp), sizeof(dpp));
     */
    // 指针为什么要分类型?
    // 因为当我们利用指针去取值的时候, 系统就会自动根据指针的类型来确定应该取对少个字节中的值
    int  intValue = 1230; //
    char charValue = '1';
    /*
     00110001
     11001110
     00000100
     00000000
     
     00000000 00000100 11001110 00110001
     */
    /*
    int *charValueP;
    charValueP = &charValue;
    
    printf("%i\n", *charValueP);
    printf("%i\n", 0b00000000000001001100111000110001);
     */
    
    /*
     11001110
     */
    char *p = &intValue;
    printf("%i\n", *p);
    
    return 0;
}
