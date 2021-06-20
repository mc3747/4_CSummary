//
//  main.c
//  数组练习1
//
//  Created by xiaomage on 15/6/10.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // 从键盘录入当天出售BTC的价格并计算出售的BTC的总价和平均价(比如说一天出售了3个比特币)
    
    // 1.接收数据
    /*
    printf("请输入第1个比特币的价格\n");
    int value1 = -1;
    scanf("%i", &value1);
    
    printf("请输入第2个比特币的价格\n");
    int value2 = -1;
    scanf("%i", &value2);

    printf("请输入第3个比特币的价格\n");
    int value3 = -1;
    scanf("%i", &value3);
     */
    
//    int value3 = -1;
    /*
    int sum = 0;
    int value = -1;
    for (int i = 0; i < 3; i++) {
        printf("请输入第3个比特币的价格\n");
        scanf("%i", &value);
        sum += value;
    }
     */
    
    // 1.1定义数组保存每个比特币的价格
    int values[4] = {-1};
    // 1.2动态计算数组的元素个数
    int length = sizeof(values) / sizeof(values[0]);
    // 1.3定义变量保存总和
    int sum = 0;
    for (int i = 0; i < length; i++) {
        printf("请输入第%i个比特币的价格\n", i + 1);
        scanf("%i", &values[i]);
        
        sum += values[i];
    }
    
    /*
    // 2.计算总和
//    int sum = value1 + value2 + value3;
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += values[i];
    }
     */
    // 3.计算平局值
    int average = sum / length;
    // 4.输出结果
    printf("sum = %i, average = %i\n", sum, average);
    
    return 0;
}
