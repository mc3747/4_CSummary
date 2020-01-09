//
//  ViewController.m
//  KVO演示
//
//  Created by zuoA on 16/4/27.
//  Copyright © 2016年 Azuo. All rights reserved.
//

#import "BaseKVOViewController.h"
#import "myKVO.h"

@interface BaseKVOViewController ()

@property (nonatomic, weak)UILabel *label;
@property (nonatomic, weak) UIButton *button;
@property (nonatomic,strong)myKVO *myKVO;

@end

@implementation BaseKVOViewController


- (void)viewDidLoad {
    [super viewDidLoad];
    RandomBackgroundColor;
    
    UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake(20,100, 300, 30)];
    label.backgroundColor = RandColor;
    [self.view addSubview:label];
    _label = label;
    
    UIButton *button = [[UIButton alloc] initWithFrame:CGRectMake(20, 150, 100, 30)];
    [button setTitle:@"点击增加" forState:UIControlStateNormal];
    [button setBackgroundColor:RandColor];
    [button addTarget:self action:@selector(changeNum:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
    _button = button;
    
    self.myKVO = [[myKVO alloc]init];
    
    /*1.注册对象myKVO为被观察者:
     option中，
      NSKeyValueObservingOptionOld 以字典的形式提供 “初始对象数据”;
      NSKeyValueObservingOptionNew 以字典的形式提供 “更新后新的数据”;
     */
    [self.myKVO addObserver:self forKeyPath:@"num" options:NSKeyValueObservingOptionOld|NSKeyValueObservingOptionNew context:nil];
    
}

/* 2.只要object的keyPath属性发生变化，就会调用此回调方法，进行相应的处理：UI更新：*/
-(void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary<NSString *,id> *)change context:(void *)context
{
    if([keyPath isEqualToString:@"num"] && object == self.myKVO)
    {
        // 响应变化处理：UI更新（label文本改变）
        self.label.text = [NSString stringWithFormat:@"当前的num值为：%@",[change valueForKey:@"new"]];
        
        //上文注册时，枚举为2个，因此可以提取change字典中的新、旧值的这两个方法
        NSLog(@"\noldnum:%@ newnum:%@",[change valueForKey:@"old"],[change valueForKey:@"new"]);
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    
    /* 3.移除KVO */ 
    [self removeObserver:self forKeyPath:@"num" context:nil];
}

//按钮事件
- (void)changeNum:(UIButton *)sender {
    //按一次，使num的值+1
    self.myKVO.num = self.myKVO.num + 1;
}

@end
