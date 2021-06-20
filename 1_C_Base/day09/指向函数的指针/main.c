//
//  main.c
//  指向函数的指针
//
//  Created by xiaomage on 15/6/14.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

void test()
{
    printf("哥被执行了\n");
}

int getAge()
{
    return 30;
}

void sum(int v1, int v2)
{
    int res = v1 +  v2;
    printf("res = %i\n", res);
}

int sum2(int v1 , int v2)
{
    int res = v1 + v2;
    return  res;
}

// 函数也会占用一块存储空间
// 因为函数也会占用一块存储空间所以函数也由自己的地址
// 函数的地址保存在函数名中
// 函数名就是函数的地址 == 数组名就是数组的地址
int main(int argc, const char * argv[]) {
    
    printf("test = %p\n", test);
    /*
     
     没有返回值没有参数
     没有返回值有参数
     有返回值没有参数
     有返回值有参数
     
     指向函数的指针的定义格式
     void (*funtionP) ();
     
     *    : 代表是一个指针
     funtionP    : 代表指针变量的名称, 区分
     (*funtionP) : 代表将来指向一个函数
     void : 代表将来指向的函数没有返回值
     ()   : 代表将来指向的函数没有参数
     
     
     普通指针的定义格式
     数据类型 *指针变量名称
     int *p;
     */
    
    /*************************华丽的分割线*******************************/
    
    /*
    void (*funtionP) ();
    funtionP = test; // 注意: 千万不能写成test()
    test(); // 0x100000f00();
    (*funtionP)(); // 0x100000f00()
    // test == funtionP
    funtionP();
    
//    int num = 10;
//    int *p = &num;
//    printf("%i\n", *p);
    
    int ages[] = {1 , 3 ,5};
    int *p;
    p = ages; // ages就是数组的地址
    // p == ages;
//     ages[0];
//     p[0];
//     *(p + n);
     */

    /*************************华丽的分割线*******************************/
    
    int (*ageP)();
    ageP = getAge;
    printf("age = %i\n", ageP());
    
//    void (*sumP)(int v1, int v2);
    void (*sumP)(int, int);
    sumP = sum;
    sumP(10, 20);

    
    int (*sumP2)(int , int);
    sumP2 = sum2;
    printf("sum = %i\n", sumP2(10, 20));
    
    return 0;
}
