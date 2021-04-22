//
//  main.c
//  static对局部变量的作用
//
//  Created by xiaomage on 15/6/15.
//  Copyright (c) 2015年 xiaomage. All rights reserved.
//

#include <stdio.h>


void test()
{
    int a = 0; // 局部变量
    // 当使用static来修饰局部变量, 那么会延长局部变量的生命周期, 并且会更改局部变量存储的位置 , 将局部变量从栈转移到静态区中
    // 只要使用static修改局部变量之后, 当执行到定义局部变量的代码就会分配存储空间, 但是只有程序结束才会释放该存储空间
    static int b = 0;
    a++; // 1
    b++; // 1  2
    printf("a = %i\n", a); // 1
    printf("b = %i\n", b); // 1
    printf("------------\n");
}


void demo(int r)
{
    /*
     应用场景":
     当某个方法的调用频率非常高, 而该方法中更有些变量的值是固定不变的
     那么这个时候就可以使用static来修饰该变量, 让该变量只开辟一次存储空间
     这样可以提高程序的效率和性能
     */
    static double pi = 3.1415926; // 固定
    double res = pi * r * r;
    printf("res = %lf\n", res);
}
int main(int argc, const char * argv[]) {
    
//    test();
//    test();
    
    for (int i = 0; i < 100; i++) {
        demo(i);
    }
    
    return 0;
}
