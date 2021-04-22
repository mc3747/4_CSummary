//
//  main.c
//  字符串数组
//
//  Created by xiaomage on 15/6/12.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    char name1[] = "lnj";
    char name2[] = "lmj";
    char name3[] = "xb";
    char name4[] = "lk";
    
    // 如果想存储一堆字符串那么可以使用字符串数组
    // 说白了字符串数组就是二维数组
    char names[5][20] =
    {
        "lnj",
        "lmj",
        "xb",
        "lk",
        "xj"
    }
    
    char names2[2][20] =
    {
        {'l', 'n', 'j', '\0'},
        {'l', 'm', 'j', '\0'}
    }
    
    return 0;
}
