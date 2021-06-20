//
//  zs.c
//  day10
//
//  Created by xiaomage on 15/6/15.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include "zs.h"


int sum(int v1, int v2)
{
    // 先用v1 - v2 然后再加上v1
    int res = minus(v1, v2) + v1;
//    return v1 + v2;
    return res;
}
