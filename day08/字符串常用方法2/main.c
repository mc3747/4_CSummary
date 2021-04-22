//
//  main.m
//  字符串常用方法2
//
//  Created by xiaomage on 15/6/12.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    // 1.字符串拼接
    /*
     // 原理 : 首先遍历第一个字符串,直到遇到\0为止, 然后取出第二个字符串中的字符, 从\0的位置开始添加, 添加完毕之后再在最后添加一个\0
     
    char str1[7] = "lnj"; // l n j c o o l \0
    char str2[10] = " cool";
    printf("拼接前: %s\n", str1);
    // dest : 目标 src : 源
    // 将src中的数据拼接到dest后面
    // 注意: 要想使用字符串拼接函数, 那么dest必须是一个数组, 并且数组的长度必须大于拼接之后的长度 \
    如果dest数组的长度, 不能完全存放dest+src+\0, 那么就会报错
//    strcat(str1, str2);
    
    // char * 相当于dest  const char * 相当于src size_t 需要拼接的个数
    // 为了避免拼接之后超出str1的存储范围, 那么可以动态计算str2中需要拷贝几个到str1后面不会超出
//                  str1能够存放的元素个数            -   str1已经存放的个数  - \0
    size_t length = sizeof(str1) / sizeof(str1[0]) - strlen(str1) - 1;
    printf("length = %lu\n", length);
    strncat(str1, str2, length);
    printf("拼接后: %s\n", str1);
     */
    
    /*************************华丽的分割线*******************************/
    
    // 2.字符串拷贝
    /*
    char str1[4] = "lnj";
    char str2[] = "cool";
    printf("拷贝前 : str1 = %s\n", str1);
    // char * 目标, const char * 源
    // strcpy函数会将源的数据拷贝到目标中, 并且会覆盖掉目标中原有的数据
    // 目标的容积必须能够存放拷贝的数据, 如果容积不够会报错
//    strcpy(str1, str2);
    
    // char * 目标, const char * 源 size_t 需要拷贝几个
    // 注意: 拷贝操作是逐个替换, 拷贝了几个就替换几个
    //              str1能够存放元素的个数         - 1是给\0留出位置
    int length = sizeof(str1) / sizeof(str1[0]) - 1;
    strncpy(str1, str2, length);
    printf("拷贝后 : str1 = %s\n", str1);
    */
    
    /*************************华丽的分割线*******************************/
    
    // 3.字符串比较
    /*
    char str1[] = "aac"; // a a
    char str2[] = "abc"; // a b

    // strcmp它会对传入的字符串进行比较, 比较完毕之后会返回一个整型的值给我们
    // 如果该值等于0,那么证明两个字符串相等
    // 如果该值小于0, 那么证明str1小于str2
    // 如果该值大于0, 那么证明str1大于str2
    // strcmp的原理: 取出字符串中的每一个字符进行逐个比较, 如果发现不相等就不会继续往下比较
    int res = strcmp(str1, str2);
    printf("res = %i\n", res);
     */
    
    return 0;
}
