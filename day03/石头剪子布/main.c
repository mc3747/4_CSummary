//
//  main.c
//  石头剪子布
//
//  Created by xiaomage on 15/6/4.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    /*
     有两个角色 : 玩家(我), 电脑
     两个角色都可以出 0 == 石头/ 1 == 剪子 / 2 == 布
     由于我们不知道玩家和电脑到底出的什么拳, 所以我们用0, 1, 2来代替石头/ 剪子 / 布
     玩家的出拳可以让用户自己输入
     电脑的出拳必须生产一个随机数, 如何生产随机数?
     将玩家的出拳和电脑的出拳进行比较, 得到比赛结果
     
     石头 > 剪刀 / 剪刀 > 布 / 布 > 石头
     */
    // 1.生产电脑的出拳
    // arc4random_uniform方法会根据传入的整数生产一个随机数
    // 生成的值就是 0~(N-1)的值
    int cmp =  arc4random_uniform(3);
//    printf("cmp = %i\n", cmp);
    // 2.接收玩家的出拳
    // 2.1定义变量保存玩家的出拳
    int player = -1;
    // 2.2利用scanf接收
    printf("请输入出拳, 0代表石头, 1代表剪刀, 2代表布\n");
    scanf("%i", &player);
    // 3.比较玩家和电脑的出拳
    if (((0 == player)&&(1 == cmp)) ||
        ((1 == player) && (2 == cmp)) ||
        ((2 == player) && (0 == cmp))) {
            printf("玩家获胜\n");
    }else if (((0 == cmp)&&(1 == player)) ||
              ((1 == cmp) && (2 == player)) ||
              ((2 == cmp) && (0 == player)))
        {
            printf("电脑获胜\n");
        }else
        {
            printf("以和为贵\n");
        }
    printf("player = %i, cmp = %i\n", player, cmp);
    return 0;
}
