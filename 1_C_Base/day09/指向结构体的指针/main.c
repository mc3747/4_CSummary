//
//  main.c
//  指向结构体的指针
//
//  Created by xiaomage on 15/6/14.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    struct Person
    {
        int age;
        char *name;
        double height;
    };
    
    struct Person sp = {30, "lnj", 1.75};
    
    sp.name = "lnj";
    sp.age = 30;
    sp.height = 1.75;
    
    // 定义了一个指向结构体的指针
    // *sip == sp
    struct Person *sip;
    sip = &sp;
    /*
    // 注意: 报错的原因是因为.运算符的优先级比*高
    (*sip).name = "xxx";
    (*sip).age = 88;
    (*sip).height = 1.95;
    printf("age = %i, name = %s, height = %lf\n", (*sip).age, (*sip).name, (*sip).height);
     */
    
    /*
    sip->age = 99;
    sip->name = "oooo";
    sip->height = 2.1;
    printf("age = %i, name = %s, height = %lf\n", sip->age, sip->name, sip->height);
     */
    
    /*
     如何定义指向结构体变量的指针
     1.拷贝结构体类型 和 结构体变量名称
     2.在类型和名称中间加上一颗心
     
     当指针指向结构体之后如何利用指针访问结构体
     结构体变量名称.属性;
     (*结构体指针变量名称).属性;
     结构体指针变量名称->属性;
     
     */
    
    return 0;
}
