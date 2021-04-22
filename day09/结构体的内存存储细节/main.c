//
//  main.c
//  结构体的内存存储细节
//
//  Created by xiaomage on 15/6/14.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    /*
    // 1.定义结构体类型并不会分配存储空间
    struct Person{
        int age; // 4
        int height; // 4
        int width; // 4
    };
    // 2.只有定义结构体变量才会真正的分配存储空间
    struct Person sp = {30, 1, 1};
    // 结构体第0个属性的地址就是结构体的地址
    printf("&sp = %p\n", &sp);
    printf("age = %p\n", &sp.age);
    
    printf("size = %lu\n", sizeof(sp));
    
//    int nums[3] = {1, 3, 5};
    // nums == &nums == &nums[0]
    
    // 和数组一样, 结构体内存寻址从大到小, 存储数组是从小到大(先存储第0个属性, 再一次存储其它属性)
    printf("height = %p\n", &sp.height);
    printf("width = %p\n", &sp.width);
     */
    
    
    /*
     结构体如何开辟存储空间
     看上去, 结构体分配存储空间是将所有属性占用的存储空间的总和加在一起后再分配
     注意: 
     其实结构体分配存储空间本质上并不是将所有属性占用的存储空间的总和加在一起后再分配
     而是会获取结构体类型中占用内存最大的属性的大小, 然后取该大小的倍数
     特例: 
     如果剩余的存储空间"不够"存储将要存储的数据, 那么就会重新开辟8个字节的存储空间, 并且将需要存储的数据放到新开辟的存储空间中
     如果剩余的存储空间"够"存储将要存储的数据, 那么就不会开辟了
     */
    struct Person{
        
//        double height; // 8
        
        int age; // 4
//        int heigth; // 4
        double height; // 8

        char c; // 1
//        char *name; // 8
    };
    struct Person sp;
    printf("size = %lu\n", sizeof(sp));
    return 0;
}
