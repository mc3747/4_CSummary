//
//  main.c
//  宏定义
//
//  Created by xiaomage on 15/6/15.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>
void test();

/*
 预处理指令
 什么是预处理指令:
    在我们的文件翻译成0和1之前做的操作我们称之为预处理指令 
    一般情况预处理指令都是以#号开头的
 宏定义
 
 条件编译
 文件包含
 */
/*
 宏定义的格式
    1.不带参数的宏定义
    2.带参数的宏定义
 
 #define 宏名 值
 
 宏定义的作用:    
    会在程序翻译成0和1之前, 将所有宏名替换为 宏的值
 
 宏定义在什么时候替换
 源代码 --> 预处理 -->汇编 -->二进制 -->可执行程序
 
 规范:
 一般情况宏名都大写, 多个单词之间用_隔开, 并且每个单词全部大写
 有得公司又要求宏名以k开头, 多个单词之间用驼峰命名
 
注意: 
    宏定义后面不要写分好
 
 宏定义也有作用域
    从定义的那一行开始, 一直到文件末尾
    虽然默认情况下宏定义的作用域是从定义的那一行开始, 一直到文件末尾. 但是我们也可以通过对应的关键字提前结束宏定义的作用域
 
 宏定义的使用场景:
    http://192.168.13.11/login
    http://192.168.13.11/accesstoken
    http://192.168.13.11/file,,,
#define BASE_URL "http://192.168.13.11/"
    
    获取屏幕的宽度
    获取手机系统版本号
    做一个单利
    判断系统版本
    ...
 */
#define COUNT 6// ;

//#define CLASS_COUNT 100

int main(int argc, const char * argv[]) {
//    int nums[6] = {1, 3, 5, 7, 9, 11};
    // 要求不能动态计算, 并且要求需求变更只修改一个地方
//    int length = sizeof(nums) / sizeof(nums[0]);
    int nums[COUNT] = {1, 3, 5, 7, 9, 11};
    
    
//    for (int i= 0; i < length; i++) {
    for (int i= 0; i < COUNT; i++) {
        printf("nums[%i] = %i\n", i, nums[i]);
    }

// 提前结束宏定义的作用域
//#undef COUNT
    
    // 如果宏名写在双引号中, 那么不会被替换
    printf("COUNT");
    
    test();
    return 0;
}

void test()
{
    int ages[COUNT] = {2, 4, 6, 8, 10};
    for (int i= 0; i < COUNT; i++) {
        printf("ages[%i] = %i\n", i, ages[i]);
    }
}
