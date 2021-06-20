//
//  main.c
//  变量的存储细节
//
//  Created by xiaomage on 15/6/9.
//  Copyright (c) 2015年 itcast. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // 变量为什么要有类型? 每种类型占用的内存空间不一样 int 4, char 1 double 8
    // 只要定义变量, 系统就会开辟一块存储空间给我们的变量存储数据, 内存寻址是从大到小
    // 越先定义的变量, 内存地址越大
    // 变量的地址就是所占的存储空间最小的字节地址
    
    int num;
    // 注意: 由于内存寻址是从大到小, 所以存储数据也是从大到小的存储(先存储二进制的高位, 再存储低位)
    //  高位   -->                    低位
    // 00000000 00000000 00000000 00001001
    num = 9; // 9 -->二进制 -->存储(补码)
    int value;
    value = 600; //00000000 00000000 00000010 01011000
    // %p是输出地址
    // &变量名称, 是取出变量的地址
    printf("num = %p\n", &num);
    printf("value = %p\n", &value);
    
    // 获取存储的每一位
    char *c = &value;
    for (int i = 0; i < sizeof(num); i++) {
        int result = c[i]; // 取出每个字节中存储的数据
        printf("%i\n", result);
    }
    
    return 0;
}
