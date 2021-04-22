//
//  ls.c
//  day10
//
//  Created by xiaomage on 15/6/15.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include "ls.h"

int minus(int v1, int v2)
{
    // 先将两个数相加, 然后再减去v2
    int res = sum(v1, v2) - v2;
    return res;
}