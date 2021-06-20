//
//  main.c
//  指针练习
//
//  Created by xiaomage on 15/6/14.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int myStrlen(char *str);
int myStrlen2(char *str);
int myStrlen3(char *str);

int main(int argc, const char * argv[]) {
    // 要求自己实现strlen函数
    char *name = "lnj";
//    size_t size = strlen(name);
    int size =myStrlen3(name);
    printf("size = %i\n", size);
    return 0;
}


int myStrlen3(char *str)
{
    int count = 0;
    // \0 ascii 0 // 0代表假 1真
    while (*str++)count++;
    
    return count;
}

int myStrlen2(char *str)
{
    int count = 0;
    //    *str == str[0]
    while (*str++ != '\0') {
        count++; // 1
//        str = str + 1; // str == str[1]
//        str++; // ++可以在变量名前, 也可以在变量名后
    }
    return count;
}

int myStrlen(char *str)
{
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}
