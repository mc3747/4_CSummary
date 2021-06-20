//
//  main.c
//  结构体的嵌套定义
//
//  Created by xiaomage on 15/6/14.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    
    /*
    struct Person
    {
        int age; // 年龄
        char *name; // 姓名
        
        // 出生日期
        int year;
        int month;
        int day;
        
        // 初始化时晨
        int HH; // 24小时
        int mm; // 分钟
        int ss; // 秒钟
        
        // 入学时间
        int year2;
        int month2;
        int day2;
        
        // 毕业时间
        int year3;
        int month3;
        int day3;
    };
    
    struct Person sp = {30, "lnj", 1986, 1, 15 , 15, 20, 8};
     */
    
    // 定义一个时间结构体类型
    struct Time
    {
        int HH;
        int mm;
        int ss;
    };
    
    struct Date
    {
        int year;
        int month;
        int day;
        struct Time time;
    };
    
    
    
    struct Person
    {
        int age;
        char *name;
        
        // 出生日期
        struct Date birth;
        // 出生时间
//        struct Date time;
//        struct Time shic;
        
        // 小学入学时间
        struct Date ruxue;
        // 小学毕业时间
        struct Date biye;
        // ....
    };
    struct Person sp =
    {
        30,
        "lnj",
        {
            1980,
            1,
            15,
            {
                15,
                12,
                8
            }
        },
        {
            1990,
            6,
            9
        },
        {
            1996,
            9,
            5
        }
    };
    
    // 注意: 如果结构体的属性又是一个结构体, 那么可以通过连续.的方式, 访问结构体属性中的属性
    //      如果结构体类型中的属性又是一个结构体, 那么赋值时候通过{}赋值
    printf("year = %i, month = %i, day = %i\n", sp.birth.year, sp.birth.month, sp.birth.day);
    
    return 0;
}
