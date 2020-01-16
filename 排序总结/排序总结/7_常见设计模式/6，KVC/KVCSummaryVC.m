//
//  KVCSummaryVC.m
//  排序总结
//
//  Created by gjfax on 2020/1/9.
//  Copyright © 2020 macheng. All rights reserved.
//

#import "KVCSummaryVC.h"
#import "KVC_Book.h"
#import "KVC_Person.h"

// =====================================================
/*
 1，KVC简介：Key-Value Coding，即键值编码。它是一种不通过存取方法，而通过属性名称字符串间接访问属性的机制。
 
 2，KVC原理：允许开发者通过Key名直接访问对象的属性，或者给对象的属性赋值。而不需要调用明确的存取方法。这样就可以在运行时动态地访问和修改对象的属性
 
 3，KVC设值
 
 4，KVC取值kvc
        
 
 */
// =====================================================
@interface KVCSummaryVC ()

@end

@implementation KVCSummaryVC

- (void)viewDidLoad {
    [super viewDidLoad];
    
}
//1，基本属性:基本类型，对象类型，集合类型（NSArray，NSDictionary， NSSet）
- (IBAction)demo1:(id)sender {
    KVC_Person *person = [[KVC_Person alloc] init];
    [person setValue:@100 forKey:@"age"];
    NSLog(@"%@",person);
}

//2,设置私有属性
- (IBAction)demo2:(id)sender {
    KVC_Person *person = [[KVC_Person alloc] init];
    [person setValue:@1.8 forKey:@"height"];
    [person setValue:@"北大" forKey:@"school"];
    [person setValue:@62.5 forKey:@"weight"];
    NSLog(@"%@",person);
}



@end
