//
//  ObjectOrientedViewController.m
//  排序总结
//
//  Created by gjfax on 2020/3/9.
//  Copyright © 2020 macheng. All rights reserved.
//

#import "ObjectOrientedViewController.h"

@interface ObjectOrientedViewController ()

@end
// =====================================================
/*
 继承:可以重写方法
 分类:不适合重写方法,
 */
// =====================================================
@implementation ObjectOrientedViewController

- (void)viewDidLoad {
    [super viewDidLoad];
 
}

- (IBAction)demo1:(id)sender {
    GJSPushViewControllerWithName(@"ProtocolDemoViewController", ((UIButton *)sender).titleLabel.text, YES);
}




@end
