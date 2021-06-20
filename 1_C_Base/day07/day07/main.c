//
//  main.c
//  day07
//
//  Created by xiaomage on 15/6/10.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // 变量在内存中的存储
    // 由于变量的内存寻址是从大到小, 所以存储数据时会从高字节开始存储
    int num = 10; // 0000 0000 0000 0000 0000 0000 0000 1010
    
    // 注意: 数组的存储和变量有点不一样, 数组存储元素, 是从所占用的低字节开始存储
    char charValues[4] = {'l', 'u', 'c', 'k'};
    /*
     charValues[0] = 0x7fff5fbff7c8
     charValues[1] = 0x7fff5fbff7c9
     charValues[2] = 0x7fff5fbff7ca
     charValues[3] = 0x7fff5fbff7cb
     */
    printf("charValues[0] = %p\n", &charValues[0]);
    printf("charValues[1] = %p\n", &charValues[1]);
    printf("charValues[2] = %p\n", &charValues[2]);
    printf("charValues[3] = %p\n", &charValues[3]);
    
    // &charValues == &charValues[0] == charValues
    printf("&charValues = %p\n", &charValues);
    // 其实数组名就是数组的地址
    printf("charValues = %p\n", charValues);
    
//    00000000 00000000 00000000 00000101
//    00000000 00000000 00000000 00000110
    int nums[2] = {5, 6};
    
    return 0;
}
