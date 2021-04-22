
#include <stdio.h>



int call()
{
    int number; // 定义变量
    return 0;
}


int value;

int main(int argc, const char * argv[])
{

    /*
//    number = 10;
    int number; // 变量有自己的作用域
    // 变量的作用域从定义的哪一行开始, 直到大括号结束或者遇到return为止
    number = 10;
    printf("return之前");
    return 0; // 结束函数, 只要执行到return就和执行到}一样, 代表着函数结束了
//    printf("%i", number);
     */
    
//    call();
//    number = 50;
    
    /*
    {
        int number;
    }
    number = 50;
     */
    
    /*
    int number;
    {
     // 自己没有找粑粑
        number = 10;
        printf("%i", number);
    }
     */
    
    /*
    int number;
//    int number; // 同意范围内不能出现同名的变量
    {
        // 1.如果自己对应的范围中有, 就使用自己的
        // 2.不同的范围中可以有相同名称的变量
        int number;
        number = 10;
        printf("%i\n", number);// 10
    }
    printf("%i\n", number);// 0
    */
    
    // 内存寻址从大到小, 如果按照这种规则, 那么先定义的变量内存地址一定大于后定义的变量
    int number = 0;
    int value = 0;
    // 如何获得变量的详细地址(变量的地址), &变量名称
    // 利用%p占位符来打印变量的详细地址
    // 输出的是一个十六进制的数
    //  a/ b/ c/ d/ e/ f/
    // 10/11/12/13/14/15
    printf("%p\n", &number);
    printf("%p\n", &value);
    
    
    return 0;
}
