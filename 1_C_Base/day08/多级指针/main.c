//
//  main.c
//  多级指针
//
//  Created by xiaomage on 15/6/12.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    /*
    char charValue = 'l';
    // 1.拷贝需要指向的变量的数据类型和变量名称
    // 2.在数据类型和变量名称之间加上一颗星
    // 3.修改变量名称
    char *charValueP;
    charValueP = &charValue;
    
    // 1.拷贝需要指向的变量的数据类型和变量名称
    // 2.在数据类型和变量名称之间加上一颗星
    // 3.修改变量名称
    char **charValuePP; // 不管有几颗*只要是指针变量就占用8个字节
//    printf("size = %lu\n", sizeof(charValuePP));
    charValuePP = &charValueP;
    
//    charValue = 'j';
    // *charValueP == charValue
//    *charValueP = 'j';
    
    // &charValue == charValueP
    printf("&charValue = %p\n", &charValue);
    printf("charValueP = %p\n", charValueP);
    // &charValueP == charValuePP
    printf("&charValueP = %p\n", &charValueP);
    printf("charValuePP = %p\n", charValuePP);
    
    // *charValuePP == 0ffc14 ==  charValueP
    // *pp == p
    
    // **charValuePP == *(*charValuePP) == *charValueP == 0ffc14 == l
    **charValuePP = 'n';
    
    printf("%c\n", **charValuePP);
    */
    
    /*************************华丽的分割线*******************************/
    
    char c = 'a';
    char *cp;
    cp = &c;
    char **cpp;
    cpp = &cp;
    char ***cppp;
    cppp = &cpp;
    printf("cppp = %c\n", ***cppp);
    
    /*
     
     *cp == c;
     *cpp ==  cp;
     **cpp == *(*cpp) == *cp == c
     多级指针的操作, 最简单的方式, 就是通过几颗星来存储, 就通过几颗星来访问
     还有一种方式就是画图, 看图片中有几个箭头, 有几个简单就用几颗星来访问
     */
    printf("c = %c\n", c);
    printf("*cp = %c\n", *cp);
    printf("&c = %p\n", &c);
    printf("cp = %p\n", cp);
    printf("*cpp = %p\n", *cpp);
    printf("**cpp = %c\n", **cpp);
    
    return 0;
}
