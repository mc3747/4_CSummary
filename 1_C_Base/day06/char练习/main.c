//
//  main.c
//  char练习
//
//  Created by xiaomage on 15/6/9.
//  Copyright (c) 2015年 itcast. All rights reserved.
//

#include <stdio.h>
char lowerCase(char temp);
int main(int argc, const char * argv[]) {
    // 要求用户从键盘输入一个字母, 如果用户输入的是大写那么就转换为小写
    
    printf("请输入一个字母\n");
    char charValue;
    scanf("%c", &charValue);
    
    // 转换
//    charValue = charValue + 32; //  65 + 32 = 97
    printf("%c\n", lowerCase(charValue));
    return 0;
}

char lowerCase(char temp)
{
    // 1.判断是否是大写字母
    if (temp >= 'A' && temp <= 'Z') {
    // 注意: 开发中千万不要这么写, 魔鬼数字
//    if (temp >= 65 && temp <= 90) {
//        temp = temp + 32;
        temp = temp + ('a' - 'A');
    }
    return temp;
}
