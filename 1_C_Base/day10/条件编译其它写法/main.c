//
//  main.c
//  条件编译其它写法
//
//  Created by xiaomage on 15/6/15.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

#define SCORE 100
//#define COUNT 50

int main(int argc, const char * argv[]) {

    /*
#ifdef SCORE // 判断是否定义了后面的宏
    printf("score\n");
#elif COUNT
    printf("count\n");
#else
    printf("OTHER\n");
#endif
     
#ifndef SCORE // 是不是没有定义名称叫做SCORE的宏
    printf("no score\n");
#else
    printf("score\n");
#endif
     */
    
    /*
#if defined(SCORE) // 判断是否定义了SCORE这个宏
    printf("score\n");
#else
    printf("no score\n");
#endif
    
#if !defined(SCORE) // 判断是否没有定义SCORE这个宏
    printf("no score\n");
#else
    printf("score\n");
#endif
     */
    

    return 0;
}
