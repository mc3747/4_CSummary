//
//  main.c
//  typedef
//
//  Created by xiaomage on 15/6/15.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

/*
 什么是typedef, 它有什么作用
 typedef可以给一个已知的数据类型起别名 (外号)
 
 利用typedef给数据类型起别名的格式:
 
 typedef 原有的数据类型 别名(外号);
 
 注意: 
 1. typedef不仅能给系统原有的数据类型起别名, 也可以给一个自定义的数据类型起别名
 2. 利用typedef给数据类型起别名, 并不会生成一个新的数据类型, 仅仅是给原有的类型起了一个别名而已
 */

int sum(int v1, int v2)
{
    return v1 + v2;
}

int minus(int v1, int v2)
{
    return v1 - v2;
}

// 注意: 如果是给指向函数的指针起别名, 那么指向函数的指针的指针名称就是它的别名
// functionPotinter == int(*functionPotinter)(int , int)
typedef int(*functionPotinter)(int , int);
int main(int argc, const char * argv[]) {
   
    // 9如何定义变量 :   数据类型 变量名称;
//    int (*sumP)(int , int ) = sum;
    functionPotinter sumP = sum;
    printf("sum = %i\n", sumP(10 , 20));
    
//    int (*minusP)(int, int) = minus;
    functionPotinter minusP = minus;
    printf("minus = %i\n", minusP(20, 10));
    return 0;
}

// ----------------------------给指针起别名----------------------------
// String == char *
typedef char * String;
void test4()
{
    //    char *name = "lnj";
    // 注意: 如果给指针起别名之后, 那么以后利用别名定义变量就不用再加*了
    String name = "lnj";
    printf("name = %s\n", name);
    
    
}

// ----------------------------给枚举类型起别名----------------------------

// 1.先定义枚举类型, 再给枚举类型起别名
/*
 enum Gender
 {
 kGenderMale,
 kGenderFemale
 };
 typedef enum Gender SEX;
 */

// 2.定义枚举类型的同时给枚举类型起别名
/*
 typedef enum Gender
 {
 kGenderMale,
 kGenderFemale
 } SEX;
 */

// 3.定义枚举类型的同时给枚举类型起别名, 并且省略枚举原有类型名称
typedef enum
{
    kGenderMale,
    kGenderFemale
} SEX;

void test3()
{
    
    // 给枚举起别名
    //    enum Gender sex;
    SEX sex;
    sex = kGenderMale;
    /*
     定义枚举变量有3种方式
     1.先定义枚举类型, 再定义枚举变量
     2.定义枚举类型的同时定义枚举变量
     3.定义枚举类型的同时定义枚举变量, 并且省略枚举类型名称
     */
    /*
     enum Gender2
     {
     kGenderMale2,
     kGenderFemale2
     } sex2;
     sex2 = kGenderFemale2;
     
     enum
     {
     kGenderMale3,
     kGenderFemale3
     } sex3;
     sex3 = kGenderFemale3;
     */
    
}
// ----------------------------给结构体类型起别名----------------------------


// 1.先定义结构体类型, 再给类型起别名
/*
 struct Person
 {
 int age;
 double height;
 char *name;
 };
 // SPerson == struct Person
 typedef struct Person SPerson;
 */

// 2.定义结构体类型的同时, 给结构体类型起别名
/*
 typedef struct Person
 {
 int age;
 double height;
 char *name;
 } SPerson;
 */

// 3.定义结构体类型的同时, 给结构体类型起别名, 并且省略掉原有类型的名称

 typedef struct
 {
 int age;
 double height;
 char *name;
 } SPerson;
void test2()
{
    /*
     // 给构造类型起别名
     struct Person
     {
     int age;
     double height;
     char *name;
     };
     */
//    struct Person sp0;
    SPerson sp;
    SPerson sp1;
    SPerson sp2;
    SPerson sp3;
    SPerson sp4;
    /*
     结构体变量的定义方式
     1.先定义类型再定义变量
     2.定义类型的同时定义变量
     3.定义类型的同时定义变量, 并且省略类型名称
     */
}

// ----------------------------给基本数据类型起别名----------------------------
// Integer == int
typedef int Integer;
typedef Integer myInt;
// int float doulbe char
void test1()
{
    int num = 10;
    printf("num = %i\n", num);
    
    Integer age = 30;
    printf("age = %i\n", age);
    
    myInt score = 99;
    printf("score = %i\n", score);
}