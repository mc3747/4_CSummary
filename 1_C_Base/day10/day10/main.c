//
//  main.c
//  day10
//
//  Created by xiaomage on 15/6/15.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>
void test();
//void test(int v1);

/*
 局部变量
 概念: 局部变量就是定义在函数, 代码块和函数形参列表中的变量, 我们就称之为局部变量
 作用范围: 从定义的那一行开始一直直到遇到大括号结束或者遇到return为止
 特点: 
    相同作用域范围内不能出现同名的局部变量
    不同作用域范围内出现同名的局部变量, 内部的局部变量会覆盖外部的局部变量
注意:
    局部变量没有固定的初始化值, 如果没有对局部变量进行初始化, 那么局部变量中是一些随机的值, 所以在开发中千万不要使用未初始化的局部变量
 存储位置:
    局部变量存储在栈中, 当作用域结束系统会自动释放栈中的局部变量
 
 
 全局变量
 概念: 写在函数,代码块,形参列表外的变量, 我们就称之为全局变量
 作用范围: 从定义的那一行开始一直直到文件末尾(暂时这样认为)
 特点:
    全局变量和局部变量可以同名
    如果存在和全局变量同名的局部变量, 那么局部变量会覆盖全局变量
注意:
    全局变量如果没有进行初始化, 那么系统默认会将全局变量初始化为0
 存储位置:
    全局变量存储在静态区中, 他会随着程序的启动而创建, 随着程序的结束而结束
 */

int num; // 全局变量  num = 0;

int main(int argc, const char * argv[]) {
    /*
    int num = 10;
    {
//        int a = 55;
        int num = 998;
        printf("num = %i\n", num);
    }
//    a = 100;
//    int num = 20;
    
    int b;
    printf("b = %i\n", b);
     */
    /*
    int num; // 局部变量
    num = 10; // 访问的是局部变量num
    printf("num = %i\n", num); // 10
    test();
    printf("num = %i\n", num); // 10
     */
    test();
    test();
    return 0;
}
//int num;
void test()
{
//    printf("num = %i\n", num);
//    num = 998; // 访问的是全局变量
    num++; // 1 2
    printf("num = %i\n", num);
}

//void test(int v1)
//{
////    printf("num = %i\n", num);
//    int v1 = 55;
//}
