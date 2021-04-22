//
//  main.c
//  printf
//
//  Created by xiaomage on 15/6/3.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
//   折叠代码的快捷键 : command + option + 方向键
//   单行注释的快捷键: command + /
    
    // 1.输出基本数据类型
    /*
    int number = 10;
    int value = 20;
    printf("%i, %i\n", number, value);
    
    float floatValue = 10.1f;
    printf("%f\n",floatValue);
    
    char charValue = 'a';
    printf("%c\n", charValue);
    
    double doubleValue = 9.9;
    printf("%lf", doubleValue);
     */
    
    // 3..指定位宽
    /*
    // 如何指定位宽? %mi; // 其中m就是位宽 而i输出对应类型的数据
    // 默认情况下位宽是右对齐, 如果需要输出的类型宽度不够, 会在左边补空格
    // 如果在位宽前面加上-号, 就会改变位宽的对齐方式为左对齐,如果需要输出的类型宽度不够,会在右边补空格
//    int number = 99;
//    printf("%5i!!!", number);
//    printf("%-5i!!!", number);
    
    // 注意: 如果指定了位宽, 但是实际输出的内容超出了宽度, 会按照实际的宽度来输出
//    int number = 9999;
//    printf("%2i", number);
    
    // 可以在位宽前面加上0, 如果输出的内容宽度不够就会用0来补, 如果宽度已经够了, 那么会按照实际的宽度输出
    int number = 8;
    // 01
    // 2015-06-05
    printf("%02i", number);
     */
    
    // 3.保留位数
    /*
    // %f默认会保留6位小数
    // 指定保留多少位小数: %.nf, 其中n就是需要保留多少位小数, f用于输出实型
    float floatValue = 3.14;
    printf("%.2f", floatValue);
     */
    
    // 4.%f各种坑
    /*
    // 为什么指定保留10位之后还不对呢? 因为float类型有效位数是7位(不包括小数点)
    // 如何计算有效位? 从第一个数开始计算
    // 如果输出的数据超出了有效位数, 那么就会出现一些垃圾数据
    float floatValue = 3.1415926525;
    printf("%.10f\n", floatValue); // 默认情况保留6位
    
    // 如何想完整的输出那么必须将数据保存位double类型, 因为double类型的有效位是15位
    double doubleValue = 3.1415926525;
    printf("%.10lf\n", doubleValue);
     */
    
    // 5.如何提高比格
    float floatValue = 3.1415926;
    printf("%.*f", 5,floatValue);
    return 0;
}
