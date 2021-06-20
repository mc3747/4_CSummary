//
//  main.c
//  结构体数组
//
//  Created by xiaomage on 15/6/14.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // 要求定义变量保存公司中所有部门的绩效
    
    struct Bumen
    {
        char *name;
        int count;
        double kpi;
    };
    struct Bumen ios = {"iOS", 20, 100.0};
    struct Bumen andorid = {"Andoird", 10, 99.0};
    struct Bumen php = {"php", 500, 88.0};
    
    // 元素类型 数组名称[元素个数];
    struct Bumen bumens[3] =
    {
        {"iOS", 20, 100.0}, // 0
        {"Andoird", 10, 99.0},
        {"php", 500, 88.0}
    };
//    bumens[0] == ios
    bumens[0].name = "iOSv587";
    bumens[0].count = 99;
    bumens[0].kpi = 100.0;
    
    printf("name = %s, count = %i, kpi = %lf\n", bumens[0].name, bumens[0].count, bumens[0].kpi);
    return 0;
}
