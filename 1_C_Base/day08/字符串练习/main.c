//
//  main.m
//  字符串练习
//
//  Created by xiaomage on 15/6/12.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>
int char_contains(char str[], int length,char key);
int char_contains2(char str[],char key);

int main(int argc, const char * argv[]) {
    // 编写一个函数char_contains(char str[],char key)， 如果字符串str中包含字符key则返回数值1，否则返回数值0
    // 给你一个字符串和一个key, 要求从字符串中找出key, 如果找到就返回1没有找到就返回0
    char str[] = "xiaomage";
    char key = 'z';
    int length = sizeof(str) / sizeof(str[0]);
//    int res = char_contains(str, length, key);
    int res = char_contains2(str, key);
    printf("res = %i\n", res);
    
    return 0;
}

int char_contains2(char str[],char key)
{
    /*
     xiaomage  a
     x != a  x != \0
     i != a  i != \0
     a != a
     
     xia  z
     x != z x != \0
     i != z i != \0
     a != z a != \0
     \0 != z \0!=\0
     */
    /*
     // 1.定义一个变量记录当前的索引
     //    int index = 0;
     // 2.遍历数组, 取出当前的字符判断是否不等于key, 并且当前出去的字符不是\0

    while (str[index] != key && str[index] != '\0') {
        index++;
    }
     */
    int index = -1;
    while (str[++index] != key && str[index] != '\0');
    
    //          a != '\0'
    //          \0 != \0
//    int res = str[index] != '\0' ? 1 : 0;
//    return  res;
    return str[index] != '\0' ? 1 : 0;
}

int char_contains(char str[], int length,char key)
{
    for (int i = 0; i < length; i++) {
        if (str[i] == key) {
            return 1;
        }
    }
    return 0;
    
}
