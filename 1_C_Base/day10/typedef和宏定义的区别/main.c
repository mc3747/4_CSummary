//
//  main.c
//  typedef和宏定义的区别
//
//  Created by xiaomage on 15/6/15.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

typedef int myInt;
#define Integer int

typedef char * String;
#define MY_STRING char *
// 一般情况下如果要给数据类型起一个名称建议用typedef, 不要用define
int main(int argc, const char * argv[]) {
    /*
    int num = 10;
    printf("num = %i\n", num);
    
    myInt age = 30;
    printf("age = %i\n", age);
    
    Integer score = 99;
    printf("score = %i\n", score);
     */
    /*
    char *name = "lnj";
    printf("name = %s\n", name);
    
    String name2 = "lmj";
    printf("name2 = %s\n", name2);
    
    MY_STRING name3 = "lk";
    printf("name3 = %s\n", name3);
     */
    
    String name1, name2;
    name1 = "lnj";
    name2 = "lmj";
    printf("name1 = %s, name2 = %s\n", name1, name2);
    
//    char *name3, name4; // char *name3; char name4;
    MY_STRING name3, name4;
    name3 = "lk";
    name4 = "xb";
    printf("name3 = %s, name4 = %s\n", name3, name4);
    return 0;
}
