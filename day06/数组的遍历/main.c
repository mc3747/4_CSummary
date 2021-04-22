//
//  main.c
//  数组的遍历
//
//  Created by xiaomage on 15/6/9.
//  Copyright (c) 2015年 itcast. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // 取出数组中所有的值, 称之为遍历
    int scores[6] = {1, 23, 44, 66, 71, 88, 99 , 2};
    /*
    printf("scores[0] = %i\n", scores[0]);
    printf("scores[1] = %i\n", scores[1]);
    printf("scores[2] = %i\n", scores[2]);
    printf("scores[3] = %i\n", scores[3]);
    printf("scores[4] = %i\n", scores[4]);
    printf("scores[5] = %i\n", scores[5]);
     */
    
    // 注意: 在遍历数组的时候, 尽量不要把遍历的次数写死
    // 遍历多少次应该由数组来决定, 也就是说遍历多少次应该通过数组计算得出
    /*
    printf("scores = %lu\n", sizeof(scores)); // 计算出数组占用的总字节数
    printf("scores[0] = %lu\n", sizeof(scores[0])); // 计算出数组中某一个元素占用的字节数
    printf("一个有多少个元素 : %lu\n", sizeof(scores) / sizeof(scores[0]));
    */
    // 动态计算数组的元素个数
    int length = sizeof(scores) / sizeof(scores[0]);
    
    for (int i = 0; i < length; i++) {
        printf("scores[%i] = %i\n", i,scores[i]);
    }
    return 0;
}
