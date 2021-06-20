//
//  main.c
//  结构体基本概念
//
//  Created by xiaomage on 15/6/14.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    /*
     基本数据类型: int double float char
     构造类型: 数组/ 结构体
     
     人:
     姓名: // char *
     年龄: // int
     身高: // double
     
     狗:
     姓名 :
     年龄 : 
     身长 :
     体重 :
     几只眼睛 : 
     几条腿 :
     
     数组: 是用于保存一组相同类型的数据
     结构体: 是用于保存一组不同类型的数据
     
     要想保存人得数据, 就必须先定义变量
     数据类型 变量名称;
     
     如何定义一个结构体变量
     1.定义结构体类型
     2.根据结构体类型, 定义结构体变量
     
     定义结构体类型的格式:
     struct 结构体类型名称
     {
        属性;
     };
     */
//    int Person[] = {"lnj", 30, 1.75};
//    printf("name = %s\n", Person[0]);
    
    // 1.定义结构体类型
    struct Person
    {
//        char name[20];
        char *name;
        int age;
        double height;
    };
    // 2.定义结构体变量
//    int num;
    struct Person p;
    // 注意: 数组不能先定义再进行一次性的初始化, 所有下面的写法是错误的
//    p.name = "lnj"; // name = {'l', 'n', 'j', '\0'};
    // 可以使用 结构体变量名称.属性的方式给结构体变量赋值
    p.name = "lnj";
    p.age = 30;
    p.height = 1.75;
    
    /*
    int nums[3];
    nums[0] = 998;
    nums[1] = 887;
    nums[2] = 789;
     */
//    int nums[3];
//    nums = {1, 3, 5};
    
    return 0;
}
