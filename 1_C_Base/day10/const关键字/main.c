//
//  main.c
//  const关键字
//
//  Created by xiaomage on 15/6/15.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
   
    /*
     如果const写在指针类型的左边, 那么意味着指向的内存空间中的值不能改变, 但是指针的指向可以改变
     如果const写在指针的数据类型和*号之间, 那么意味着指向的内存空间中的值不能改变, 但是指针的指向可以改变
     如果const写在指针的右边(数据类型 * const), 那么意味着指针的指向不可以改变, 但是指针指向的存储空间中的值可以改变
     
     规律:
     如果const写在指针变量名的旁边, 那么指针的指向不能变, 而指向的内存空间的值可以变
     如果const写在数据类型的左边或者右边, 那么指针的指向可以改变, 但是指向的内存空间的值不能改变
     */
    /*
    const char *name = "lnj";
    printf("name = %s\n", name);
    name = "lk";
    printf("name = %s\n", name);
     */
    
    /*
    int num = 10;
    int *p = &num;
//    const int *p = &num;
//    int const *p = &num;
//    int * const p = &num;
    *p = 998; // 修改了指针指向的内存空间中存储的值
    printf("&num = %p\n", &num);
    printf("p = %p\n", p);
    printf("num = %d\n", num);
    
    int age = 30;
    p = &age;// 修改了指针的指向
    printf("&age = %p\n", &age);
    printf("p = %p\n", p);
     */
    return 0;
}

void test()
{
    // const对基本数据类型的作用, 可以让基本数据类型的变量变为常量
    // const有两种写法, 1.写在数据类型的左边, 2.写在数据类型的右边
//    const int num = 10;
    int const num = 10;
    printf("num = %i\n", num);
//    num = 55;
    printf("num = %i\n", num);
}
