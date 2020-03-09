//
//  MacroViewController.m
//  排序总结
//
//  Created by gjfax on 2020/3/9.
//  Copyright © 2020 macheng. All rights reserved.
//

#import "MacroViewController.h"

//对象宏
#define M_PI        3.14159265358979323846264338327950288

//函数宏
#define PLUS(x,y) ((x) + (y))

#define Baby @"asdfas"

@interface MacroViewController ()

@end
// =====================================================
/*
 1,对象宏
 2,函数宏
 3,宏的注意点
    
    可变参数
    ({...})
    #:将宏参数转成字符串
    ##:用##运算符来实现标识符连接
    换行\
 3,Clang系统宏:MIN,MAX等
 4,利用宏来改造NSLog
    __FILE__返回当前文件的绝对路径，
    __LINE__返回展开该宏时在文件中的行数，
    __func__是改宏所在scope的函数名称。
    __DATE__、__TIME__、__STDC_
 5,测试相关的宏:XCTAssertTrue
 6,#define和const区别
 */
// =====================================================
@implementation MacroViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    printf("%f",M_PI);
    
    printf("%d",PLUS(3,2));
    
    MIN(3, 8);
    
    NSLog(@"%@",Baby);
}



@end
