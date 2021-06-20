//
//  main.c
//  指向函数的指针练习
//
//  Created by xiaomage on 15/6/14.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>
char upper(char value);
void upperCase(char *p);
//void ts(char *temp);
void ts(char *temp, void (*funtionP)(char *));

int main(int argc, const char * argv[]) {
    // 需求: 要求用户输入一段英文, 将用户输入的英文单词所有的首字母大写
    // hello world --> Hello World
    
    
    // 1.接收用户输入的字符串
    // 2.遍历字符串, 判断当前字符是否是空格, 如果是空格就将下一个字符转换为大写
    
    // 1.先实现接受字符串
    // 2.再实现字母的大小写转换
    // 3.再实现替换字符串中的单词首字符
    
    /*
    printf("请输入一句英文, 单词之间用空格隔开\n");
//    char *str;
    char str[100];
//    scanf("%s", str);
    gets(str);
    printf("str = %s", str);
     */
    
    /*
    char c = 'a'; // + - 1
//    printf("c = %c\n", upper(c));
    upperCase(&c);
    // *p == c
    printf("c = %c\n", c);
     */
    
    // 1.接收用户输入的数据
    printf("请输入一句英文, 单词之间用空格隔开\n");
    char str[100];
    gets(str);
    // 注意: 数组名称不能做+1操作, 只有指针才可以
    printf("str = %s\n", str);
    /*
    char *temp = str;
    // 2.遍历字符串
    upperCase(temp);
    // temp == &str[0]
    while (*temp != '\0') { // h e l l o 空格 w
        // 2.1取出当前的字符, 判断是否等于 空格, 如果等于空格就需要将下一个字符转换为大写
        if ((*temp) == ' ') {
            // 2.2将下一个字符转换为大写
            upperCase(++temp); // temp == &str[6]; == w
        }else
        {
            temp++; // temp == &str[7];
        }
    }
     */
    ts(str, upperCase);
    
    printf("str = %s", str);
    
    return 0;
}

void ts(char *temp, void (*funtionP)(char *))
{
    // 1.不管三七二十一先将第一个字母转换为大写
    upperCase(temp);
    // temp == &str[0]
    while (*temp != '\0') { // h e l l o 空格 w
        // 2.1取出当前的字符, 判断是否等于 空格, 如果等于空格就需要将下一个字符转换为大写
        if ((*temp) == ' ') {
            // 2.2将下一个字符转换为大写
//            upperCase(++temp); // temp == &str[6]; == w
            funtionP(++temp);
        }else
        {
            temp++; // temp == &str[7];
        }
    }

}


void upperCase(char *p)
{
    // 1.判断是否是小写字母
    if (*p >= 'a' && *p <= 'z') {
        // 2.将小写字母转换为大写字母
        *p = *p - ('a'  - 'A'); // 32 小写的ascii大于大写
    }

}
char upper(char value)
{
    // 1.判断是否是小写字母
    if (value >= 'a' && value <= 'z') {
        // 2.将小写字母转换为大写字母
        value = value - ('a'  - 'A'); // 32 小写的ascii大于大写
    }
    return value;
}
