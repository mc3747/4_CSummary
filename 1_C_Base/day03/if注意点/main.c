//
//  main.c
//  if注意点
//
//  Created by xiaomage on 15/6/4.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
   
    
    /*
    // 因为C语言中, 任何数值都有真假性, 非0即真
    if (0) {
        printf("来这二\n");
    }else
    {
        printf("不去\n");
    }
     */
    
     /*************************华丽的分割线*******************************/
    
    // 移动代码的快捷键:
    // 上下移动: command + option + [(上) / ](下)
    // 左右移动: command + ](右) [(左)
    /*
     int age = 18;
     // ==   =
    if (age = 18) { // 18
        printf("开网卡\n");
    }
     */
    // 以后如果要判断某一个变量是否等于某一个值, 建议把常量写前面, 变量写后面
    /*
    if (18 = age) {
        printf("开网卡\n");
    }
     */
    
     /*************************华丽的分割线*******************************/
    
    /*
    // if如果省略大括号, 就会管理离他最近的一条语句 , 而;是一条空语句
    if (0);
        printf("lnj\n");
     */
    
     /*************************华丽的分割线*******************************/
    
    /*
    // 如果要在if后面定义变量, 那么必须写上大括号
    if (1)
        int number = 10;
    printf("number = %i\n", number);
     */
    
     /*************************华丽的分割线*******************************/
    
    // 如果if, else省略大括号, 那么else会匹配离他最近的一个if
    if(0){
        if(1){
            printf("A\n");
        }
        else{
            printf("B\n");
        }
    }
    else{
        if (1){
            printf("C\n");
        }
        else{
            printf("D\n");
        }
    }
    
    
    printf("end\n");
    return 0;
}
