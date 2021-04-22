//
//  main.c
//  条件编译
//
//  Created by xiaomage on 15/6/15.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

#define SCORE 90

#define DEBUG 1 // 0是调试阶段 1是发布阶段

#if DEBUG == 0
// 调试阶段
#define NJLog(format, ...) printf(format,## __VA_ARGS__)
#else
// 发布阶段
#define NJLog(format, ...)
#endif

/*
 条件编译和选则结构if的共同点
 都可以对给定的条件进行判断, 添加满足或者不满足都可以执行特定的代码
  条件编译和选则结构if的共区别
 1.生命周期不同
    if 运行时
    #if 编译之前
 2.#if需要一个明确的结束符号 #endif
    为什么需要一个明确的结束符号?
    如果省略掉#endif, 那么系统就不知道条件编译的范围, 那么会将满足条件之后的第二个条件之后的所有内容都清除
 3.if会将所有的代码都编译到二进制中
  #if只会将满足条件的部分一直到下一个条件的部分 编译到二进制中
 
 条件编译的优点
 1.缩小应用程序的大小
 
 应用场景:
 用于调试和发布阶段进行测试
 调试阶段: 程序写代码的阶段
 发布阶段: 上传到AppStore的阶段
 */
int main(int argc, const char * argv[]) {
    // 条件编译和if非常非常像
    // if选择结构会对给定条件进行判断, 如果条件满足就执行if后面大括号中的内容
    // 条件编译也一样, 会对给定的条件进行判断, 如果条件满足就编译条件后面的内容

    int score = 90;
    if (score == 100) {
//        printf("牛逼\n");
//        printf("发朵大红花\n");
        NJLog("牛逼\n");
        NJLog("发朵大红花\n");
    }else if(score == 90)
    {
//        printf("牛X\n");
//        printf("发朵小红花\n");
        NJLog("牛X\n");
        NJLog("发朵小红花\n");
    }else
    {
//        printf("继续加油\n");
//        printf("别哭\n");
        NJLog("继续加油\n");
        NJLog("别哭\n");
    }

//    int score = 100;

    /*
    // 预处理指令什么时候执行? 编译之前 \
    变量什么时候定义? 执行了才会定义
    // 注意点: 条件编译不能用来判断变量, 因为不在同一个生命周期
    // 君生我未生, 我生君已老
    // 一般情况下, 条件编译是和宏定义结合在一起使用的
//#if score == 100
#if SCORE == 100
printf("牛逼\n");
printf("发朵大红花\n");
#elif SCORE == 90
printf("牛X\n");
printf("发朵小红花\n");
#else
printf("继续加油\n");
printf("别哭\n");
#endif // 作为结束符号
     */


#if DEBUG == 0
    char *name = "lnj";
    char *pwd = "123";
#else
    char *name = NULL;
    char *pwd = NULL;
#endif
    
//    printf("name = %s, pwd = %s\n", name, pwd);
    NJLog("name = %s, pwd = %s\n", name, pwd);
    return 0;
}
