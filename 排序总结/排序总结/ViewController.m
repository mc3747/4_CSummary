//
//  ViewController.m
//  排序总结
//
//  Created by gjfax on 2018/5/9.
//  Copyright © 2018年 macheng. All rights reserved.
//

#import "ViewController.h"
#import "ParameterManager.h"
#import "ParameterClass.h"
#import "ReturnValueManager.h"
#import "PassValueVC.h"
#import "CallMethodViewController.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UIButton *testBtn1;
@property (weak, nonatomic) IBOutlet UIButton *testBtn2;
@property (weak, nonatomic) IBOutlet UIButton *testBtn3;
@property (weak, nonatomic) IBOutlet UIButton *testBtn4;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    [_testBtn1 addTarget:self action:@selector(test1) forControlEvents:UIControlEventTouchUpInside];
    [_testBtn2 addTarget:self action:@selector(test2) forControlEvents:UIControlEventTouchUpInside];
    [_testBtn3 addTarget:self action:@selector(test3) forControlEvents:UIControlEventTouchUpInside];
    [_testBtn4 addTarget:self action:@selector(test4) forControlEvents:UIControlEventTouchUpInside];
}

#pragma mark -  1，可变参数
- (void)test1 {
/*1，传字典 */
    
/*2，传模型 */
    Parameter1 *parameter1 = [Parameter1 new];
    parameter1.number = 14;
    ParameterManager<Parameter1 *> *manager1 = [ParameterManager new];
    manager1.parameter = parameter1;
    [manager1 getParaWithType:MethodType1];
    
/*2，传同一类型的参数，个数不定 */
    [ParameterManager getType:MethodType0 params:@"23",@"389",@"889",nil];
}

#pragma mark -  2，多个返回值
- (void)test2 {
    
//返回字典
    NSDictionary *dic = [ReturnValueManager returnMoreResult1:@"20"];
    NSLog(@"返回结果%@",dic);
    
//传入指针
    NSString *string1;
    NSString *string2;
    [ReturnValueManager returnMoreResult2:@"30" returnString1:&string1 returnString2:&string2];
    NSLog(@"返回结果：%@和%@",string1,string2);
    
//返回block
    [ReturnValueManager returnMoreResult3:@"40" Block:^(NSString *returnString1, NSString *returnString2) {
        NSLog(@"返回结果：%@和%@",returnString1,returnString2);
    }];
}

#pragma mark -  控制器传值
- (void)test3 {
    PassValueVC *vc = [[PassValueVC alloc] init];
    [self.navigationController pushViewController:vc animated:YES];
}

#pragma mark -  调用方法的几种方式
- (void)test4 {
    CallMethodViewController *vc = [[CallMethodViewController alloc] init];
    [self.navigationController pushViewController:vc animated:YES];
}
@end
