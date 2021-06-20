//
//  main.c
//  字符串常用方法1
//
//  Created by xiaomage on 15/6/12.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int myStrlen(char str[]);
int myStrlen2(char str[], int length);

int main(int argc, const char * argv[]) {
    // 1.如何输出字符串
    /*
    // 1.1可以使用printf的%s占位符来输出
    // 弊端 : 如果想要换行, 必须加上\n
    // 优点 : 可以自定义格式化需要输出的字符串, 也就是可以按照我们需要的格式来输出
    char str[] = "lnj";
    printf("name = %s!!!!\n", str);
    printf("-------\n");
    
    // 1.2可以使用puts函数来输出
    // 优点: 可以自动换行
    // 缺点: 不可以自定义格式, 只能原样输出
    puts(str);
    printf("-------\n");
    */
    
    /*************************华丽的分割线*******************************/
    
    // 2.如何输入字符
    /*
    // 2.1利用scanf接收字符串的注意点
    // scanf接收字符串, 会以空格 , tab, 回车作为结束符号, 也就是说利用scanf接收字符串时, 字符串中不能出现空格, tab, 回车
    printf("请输入一个字符串\n");
    char buf[10];
    scanf("%s", buf);
    printf("buf = %s\n", buf);
    printf("-------\n");
     
    
    // 2.2利用gets接收字符串
    // warning: this program uses gets(), which is unsafe.
    // 如果使用gets接收字符串, 系统会提示我们正在使用一个不安全的方法接收字符
    // 优点: 如果利用gets接收字符串 , 可以在字符串中输入空格, tab
    printf("请输入一个字符串\n");
    char buf2[10]; // lnj c
    gets(buf2);
    printf("buf = %s\n", buf2);
    printf("-------\n");
    */
    
    /*************************华丽的分割线*******************************/
    
    // 3.如何计算字符串的长度
    //            0123
    char str[] = "lnj cool"; // 3
//    int length = sizeof(str) / sizeof(str[0]) - 1;
    // strlen的原理: 从传入的地址开始逐个取出字符串, 每取出一个就让计数器+1. 直到遇到\0为止
//    size_t size =  strlen(str); // 计算出来的结果不包括\0
//    int size = myStrlen(str);
    int length = sizeof(str) / sizeof(str[0]);
    int size = myStrlen2(str, length);
    
    printf("length = %lu\n", size);
    for (int i = 0; i < size; i++) {
        printf("str[%i] = %c\n", i , str[i]);
    }
    return 0;
}

int myStrlen2(char str[], int length)
{
    // 1.定义变量记录取出了多少个字符
    int count = 0;
    // 2.遍历字符数组
    for (int i = 0; i < length; i++) {
        if (str[i] != '\0') {
            count++;
        }
    }
    return count;
}

// 自定义一个strlen函数
int myStrlen(char str[])
{
   // 1.定义变量记录取出了多少个字符
    int count = 0;
  // 2.遍历字符数组
    while (str[count] != '\0') {
        count++; // 1 2 3
    }
    return count;
}
