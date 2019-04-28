//
//  NativeAndWebTableVC.m
//  排序总结
//
//  Created by gjfax on 2019/3/21.
//  Copyright © 2019 macheng. All rights reserved.
//

#import "NativeAndWebTableVC.h"

@interface NativeAndWebTableVC ()

@end

@implementation NativeAndWebTableVC

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.contentArray = @[@"webView相关",@"webView和js交互",@"WKWebview相关",@"第三方好用"];
    self.vcNameArray = @[@"WebViewBaseVC",@"NativeAndWebVC",@"WKWebViewSummaryVC",@"NativeAndWebSummaryVC"];
    self.vcTitleArray = self.contentArray;
}



@end
