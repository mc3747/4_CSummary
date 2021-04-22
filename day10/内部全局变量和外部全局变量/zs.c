//
//  zs.c
//  day10
//
//  Created by xiaomage on 15/6/15.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include "zs.h"

/*
int num; // 由于Xcode升级之后导致的, 在Xcode6以前是可以的
如果直接在zs.c当中定义外部全局变量num, 那么我们说过同名的外部全局变量指向同一块存储空间,
 那么如果在多个文件中有同名的外部全局变量, 可能导致A文件的数据被B文件不小心修改了
 降低了数据的封装性, 提高了发生错误的概率
*/
//int num;

// extern关键字用来修饰全局变量, 代表声明一个全局变量
// 注意: 声明全局变量和声明函数一样, 仅仅是告诉系统我们有这个全局变量, 但并不会真在的开辟存储空间
//extern int num;

//static int num; // 0  666

//int num; // 0 666


void test()
{
extern int num;
    printf("zs.c = num = %i\n", num); // 0
    num = 666;
}
int num;
