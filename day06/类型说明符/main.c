//
//  main.c
//  类型说明符
//
//  Created by xiaomage on 15/6/9.
//  Copyright (c) 2015年 itcast. All rights reserved.
//

#include <stdio.h>
/*
 类型说明符:
 1.说明长度的(它可以用于修改类型所占用的存储空间的大小)
 short; short == short int  == 2个字节 == %hi/ %hd
 long; long == long int  == 8个字节 == %li / %ld
 long long; == long long int  == 8个字节 == %lli / %lld
 
 用于说明数据类型, 一般情况下和int配合使用
 
 2.说明符号位(它可以用于修改符号位是否用于正负数)
 unsigned; 无符号 , 取值正数和零 == %u
 signed; 有符号, 默认就是有符号 , 取值 正数和零以及负数
 
 3.不同类型的说明符可以混合使用
 unsigned short
 signed long
 // 注意: 相同类型不能在一起使用
 unsigned signed
 */
int main(int argc, const char * argv[]) {
    /*
    // int  == 4个字节 == -2(31)~2(31)-1
    
    int num = 12345678901;
    printf("num = %i\n", num);
    
    
    // int == 4个字节, long int == 8个字节 == -2(63)~2(63)-1
    long int num1 = 12345678901;
    printf("num1 = %li\n", num1);
    
    // long int == long
    // 用%li 或者 %ld来输出long类型的数据
    // C语言中不看怎么存, 只看怎么取
    long num2 = 12345678901;
    printf("num2 = %li\n", num2);
    
    // long long
    // 在64位变一下, 基本没区别, 但是如果是在32位就有区别
    // 32位下long占4个字节, long long 占8个字节
    // 注意: 如果使用long long修饰变量, 那么输出的时候需要使用%lli或者%lld
    long long int num3 = 12345678901;
    printf("num3 = %lli\n", num3);
    
    printf("long long  = %i, long  = %i\n", sizeof(num3), sizeof(num2));
    
    // long long int == long long
    long long num4 = 12345678901;
    printf("num4 = %lli\n", num4);
     */
    
    /*************************华丽的分割线*******************************/
    
    /*
    // int == 4个字节 == -2(31)~2(31)-1
    int num = 9; // 0000 1001
    printf("num = %i\n", num);
    
    // 如果以后需要保存的数据的取值范围没有超过short int的取值范围, 可以使用short int来保存
    // 但是在企业级开发中很少使用
    // short int == 2个字节 == -2(15)~2(15)-1
    short int num1 = 9;
    printf("num1 = %i\n", num1);
    
    // short int == short
    // 如果要输出short int类型的数据, 可以使用%hi或者%hd
    short num2 = 9;
    printf("num2 = %hi\n", num2);
    
    printf("short = %i, int = %i\n", sizeof(num1), sizeof(num));
    
    */
    
    /*************************华丽的分割线*******************************/
    
    /*
    // signed 有符号
    // 如果给变量加上修饰符signed, 代表当前变量的取值可以是正数 / 负数/ 零
    // 如果给变量加上修饰符signed, 就代表把二进制的最高位作为符号位
    // 而且默认情况下所有变量都是有符号的(signed)
    signed int num = 0;  // 正数 / 负数/ 零 int == -2(31)~2(31)-1
    printf("num = %i\n", num);
    
    // unsigned 代表无符号. 无符号就代表当前变量的取值只能是正数 / 零
    // 如果给变量加上修饰符unsigned, 就代表"不"把二进制的最高位作为符号位

    // 如果想打印无符号的变量, 只能用%u
    unsigned int num1 = -12;
    printf("num1 = %u", num1);
     */
    
    /*************************华丽的分割线*******************************/
    
    // 不同类型的说明符可以混合使用
    unsigned long int num = 99;
    printf("num = %lu\n", num);
    
    signed short int num1 = 23;
    printf("num1 = %hi\n", num1);
    
    // 注意: 相同类型的说明符不能同时在一起使用
//    short long int num2 = 998;
//    unsigned signed  int num3 = 998;
    
    return 0;
}
