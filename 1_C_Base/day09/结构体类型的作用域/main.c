//
//  main.c
//  结构体类型的作用域
//
//  Created by xiaomage on 15/6/14.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>
void test();

// 如果将变量写到函数或者代码块外面, 那么就不是局部变量, 而是全局变量
// 全局变量的作用域是从定义的那一行开始, 直到文件末尾 (暂时这样理解)
int num;

// 如果将结构体类型写在函数或者代码块外面, 那么结构体类型的作用域和全局变量一样, 从定义的那一行开始一直直到文件末尾
// 相同作用域不能有同名的结构体类型
struct Person
{
    int age;
    char *name;
    double height;
};


int main(int argc, const char * argv[]) {
//    int num = 10;
    num = 10;
    
    struct Person sp;
    return 0;
}

void test()
{
    num = 55;
    struct Person sp1;
//    num = 20;
}

 /*
void demo()
{
    struct Person
    {
        int age;
        char *name;
        double height;
    };
    int num = 10;
    
    {
        struct Dog
        {
            int age;
            char *name;
        };
        struct Dog sd;
        
        // 在不同的作用域中可以有同名的局部变量, 如果访问采用就近原则
        int num = 50;
        printf("num = %i\n", num);
        
        // 在不同的作用域中可以定义同名的结构体类型 , 如果使用同名的结构体类型定义结构体变量, 采用就近原则
        struct Person
        {
            int age;
            char *name;
            double height;
        };
        struct Person sp = {30, "lnj", 1.75};
        
    }
    //    num = 55;
    //    struct Dog sd1;
    
    
    struct Person sp;
}
 

void test()
{
    // 1.如果结构体定义在函数或者代码块中, 那么结构体类型的作用域和变量的作用域一样, 从定义的那一行开始, 一直到函数结束或者到代码块结束
    struct Person sp;
}
 */
