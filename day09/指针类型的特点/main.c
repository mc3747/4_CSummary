//
//  main.c
//  指针类型的特点
//
//  Created by xiaomage on 15/6/14.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>
void change();
void change2();
void change3(int values[]);
void change4(int *p);
char *demo();
char *demo2();

int main(int argc, const char * argv[]) {
    /*
     只要是数据类型就具备3个特点
     1.可以用来定义变量
     2.可以用来作为形参的类型
     3.作为返回值
     */
    /*
    int num = 10;
    change(num);
    printf("num = %i\n", num);
    
//    char *name = "lnj";
//    change2(name);
    
    int nums[] = {1, 3, 5};
//    change3(nums); // 数组名就是数组的地址
    change4(nums); // 数组名就是数组第0个元素的地址
    printf("nums[0] = %i\n", nums[0]);
     */
    
    char *name = demo();
    printf("name = %s\n", name);
    
    char *name2 = demo2();
    printf("name2 = %s\n", name2);
    
    return 0;
}

char *demo2()
{
    char name[]= "lnj";
    return name;
}

char *demo()
{
    char *name = "lnj";
    return name;
}

void change4(int *p)
// int *p = nums; == int *p = &nums; == int *p = &nums[0]
// int *p; p = nums;  p == nums;
{
    p[0] = 998;
}
// 不专业
void change3(int values[])
{
    values[0] = 998;
}

/*
void change2(char *p)
{
    *p = "lmj";
}
 */

void change(int value)
{
    value = 55;
}
