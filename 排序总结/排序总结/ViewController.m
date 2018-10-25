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
#import <objc/runtime.h>

@interface ViewController ()<UITableViewDelegate,UITableViewDataSource>

@property (weak, nonatomic) IBOutlet UIButton *logDisplayButton;
@property (weak, nonatomic) IBOutlet UIButton *logHiddenButton;
@property (weak, nonatomic) IBOutlet UIButton *logClearButton;

@property (nonatomic, strong) NSArray *cellDisplayNameArray;
@property (nonatomic, strong) NSArray *cellControllerNameArray;
@property (nonatomic, weak) UITableView *tableView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"重要知识点汇总";
    [self initArrays];
    [self initTableView];
    [self.logDisplayButton addTarget:self action:@selector(logDisplay) forControlEvents:UIControlEventTouchUpInside];
    [self.logHiddenButton addTarget:self action:@selector(logHidden) forControlEvents:UIControlEventTouchUpInside];
    [self.logClearButton addTarget:self action:@selector(logClear) forControlEvents:UIControlEventTouchUpInside];

}
- (void)logDisplay {
    
    [[HAMLogOutputWindow sharedInstance] setHidden:NO];
}

- (void)logHidden {
     [[HAMLogOutputWindow sharedInstance] setHidden:YES];
}

- (void)logClear {
    MCLogClear;
}

#pragma mark -  初始化
- (void)initArrays {
    
    
    self.cellDisplayNameArray = @[@"1，方法的可变参数",@"2，方法的多个返回值",@"3，控制器传值",@"4，调用方法的方式",
                                  @"5，定时器汇总",@"6，PerformSelector方法测试",@"7，24种设计模式汇总",@"8，单例模式",@"9，简单代理",@"10，协议代理",@"11，多代理",@"12，KVO基本使用",@"13，Block封装KVO",@"14，通知模式",@"15，匹配的三种方式",@"16，正则表达式的使用场景",@"17，RunTime总结",@"18，对象的初始化方法",@"19，字典转模型"];
    
    self.cellControllerNameArray = @[@"",@"",@"PassValueVC",@"CallMethodViewController",
 @"TimerViewController",@"RootViewController",@"DesignModeSummaryVC",@"SingltonVC",@"SimpleDelegateTestVC",@"ProtocolDelegateVC",@"MutiDelegatVC",@"BaseKVOViewController",@"BlockKVOViewController",@"NotificationVC",@"MatchingMethodVC",@"RegularExpressionVC",@"RunTimeVC",@"InitMethodVC",@"DicToModelVC"];
}

#pragma mark -  初始化tableview

- (void)initTableView {
    UITableView *tableView = [[UITableView alloc] initWithFrame:CGRectMake(0, 150, [UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height - 150) style:UITableViewStylePlain];
    tableView.backgroundColor = [UIColor whiteColor];
    tableView.delegate = self;
    tableView.dataSource = self;
    tableView.separatorStyle = UITableViewCellSeparatorStyleSingleLine;
    [self.view addSubview:tableView];
    _tableView = tableView;
}

#pragma mark - tableView delegate
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return self.cellDisplayNameArray.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    
    //由于此方法调用十分频繁，cell的标示声明成静态变量有利于性能优化
    static NSString *cellIdentifier=@"UITableViewCellIdentifierKey";
    
    //首先根据标识去缓存池取
    UITableViewCell *cell=[tableView dequeueReusableCellWithIdentifier:cellIdentifier];
   
    //如果缓存池没有到则重新创建并放到缓存池中
    if(!cell){
        cell=[[UITableViewCell alloc]initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:cellIdentifier];
    }
    cell.textLabel.text = self.cellDisplayNameArray[indexPath.row];
    cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    return cell;
}


- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    if (indexPath.row == 0) {
          [self test1];
        
    }else if (indexPath.row == 1) {
        [self test2];
    }else {
         [self.navigationController pushViewController:[self getController:self.cellControllerNameArray[indexPath.row]] animated:YES];
    };
   
}

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section{
    return 0;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 60;
}



#pragma mark - 根据字符串名称动态获取控制器对象
- (id)getController:(NSString *)controllerName {
    // 类名
    NSString *class =[NSString stringWithFormat:@"%@", controllerName];
    const char *className = [class cStringUsingEncoding:NSASCIIStringEncoding];
    
    // 从一个字串返回一个类
    Class newClass = objc_getClass(className);
    if (!newClass)
    {
        // 创建一个类
        Class superClass = [NSObject class];
        newClass = objc_allocateClassPair(superClass, className, 0);
        // 注册你创建的这个类
        objc_registerClassPair(newClass);
    }
    // 创建对象
    id instance = [[newClass alloc] init];
    return instance;
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
