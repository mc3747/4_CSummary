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
    设置setValue:forKey时的顺序：
        1，查找setKey:、_setKey: (按顺序查找)
        2，如果没有，查看accessInstanceVariablesDirectly方法
        3，如果2返回yes，会按照 _key、_isKey、key、iskey的顺序查找成员变量
    4，步骤2，3未搜索到对应的key，抛出一个NSUndefinedKeyException的异常，重写- (void)setValue:(nullable id)value forUndefinedKey:(NSString *)key;
 
 4，KVC取值kvc
    valueForKey:
        1，按照 getKey、key、iskey、_key 顺序查找方法
        2，如果没有，查看accessInstanceVariablesDirectly方法
        3，如果2返回yes，会按照_key、_isKey、key、iskey的顺序查找成员变量
        4，步骤2，3未找到报错NSUnkonwKeyException错误
    
 设置私有属性
 设置的属性不存在
 
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

//2,设置私有属性,只读属性
- (IBAction)demo2:(id)sender {
    KVC_Person *person = [[KVC_Person alloc] init];
    NSLog(@"设置前❎%@",person);
//声明私有属性
    [person setValue:@18 forKey:@"heightInt"];
//只读属性
    [person setValue:@"北大" forKey:@"school"];
//类扩展私有属性
    [person setValue:@62.5 forKey:@"weight"];
    NSLog(@"设置后✅%@",person);
}
//3，keypath
/*
 而KVC对于keyPath是搜索机制第一步就是分离
 key，用小数点.来分割key，然后再像普通key一样按照先前介绍的顺序搜索下去。如果没有小数点，就直接向普通key来搜索
 */

- (IBAction)demo3:(id)sender {
    KVC_Book *book = [[KVC_Book alloc] init];
    [book setValue:@"活着" forKey:@"bookName"];
    NSLog(@"%@",book);
    KVC_Person *person = [[KVC_Person alloc] init];
    [person setValue:book forKey:@"book"];
    [person setValue:@"变形金刚" forKeyPath:@"book.bookName"];
    NSLog(@"%@",book);
}

//
- (IBAction)demo4:(id)sender {
    
}
//
- (IBAction)demo5:(id)sender {
}



@end
