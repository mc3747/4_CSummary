//
//  BlockDemo7VC.m
//  排序总结
//
//  Created by gjfax on 2020/1/10.
//  Copyright © 2020 macheng. All rights reserved.
//

#import "BlockDemo7VC.h"

@interface BlockDemo7VC ()<UIPickerViewDelegate,UIPickerViewDataSource>
@property(nonatomic,strong)UIPickerView *pickerView;
@property(nonatomic,strong)NSArray *dataSouce;
@property (nonatomic, strong) UIButton *titleButton;
@property (nonatomic, strong) UIButton *confirmButton;
@end

@implementation BlockDemo7VC

- (void)viewDidLoad {
    [super viewDidLoad];
        [self.view addSubview:self.titleButton];
        [self.view addSubview:self.confirmButton];
        [self.view addSubview:self.pickerView];
    
    //    默认选中数据
            [self pickerView:self.pickerView didSelectRow:0 inComponent:1];
        
    //    每行的默认选中数据
        for (int i = 0; i < self.dataSouce.count; ++i) {
            [self.pickerView selectRow:1 inComponent:i animated:YES];
            [self pickerView:self.pickerView didSelectRow:1 inComponent:i];
        }
}

- (void)getTitle:(id)sender {
    
    // 遍历集合中的所有组
    for (int i = 0; i < self.dataSouce.count; ++i) {
        
        // 第i组里面的所有数据
        NSUInteger count = [self.dataSouce[i] count];
        
        // 生成随机数去选中
        u_int32_t ranNum = arc4random_uniform((int)count);
        
        // 获取第i组当前选中的行
        NSInteger selRowNum = [self.pickerView selectedRowInComponent:i];
        
        // 如果随机数与当前选中的行号一致,需要重新生成随机数
        while (selRowNum == ranNum) {
            ranNum = arc4random_uniform((int)count);
        }
        
        // 让pickerView选中数据
        [self.pickerView selectRow:ranNum inComponent:i animated:YES];
        
        // 将数据现实到label上
        [self pickerView:self.pickerView didSelectRow:ranNum inComponent:i];
    }
    
}

#pragma mark - dataSouce
//有几行
- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView {
    return self.dataSouce.count;
}
//行中有几列
- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component {
    return [self.dataSouce[component] count];
}
//列显示的数据
- (NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger) row forComponent:(NSInteger)component {
    return self.dataSouce[component][row];
}

#pragma mark - delegate
// 选中某一组的某一行
- (void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component {
    NSString *selFood = self.dataSouce[component][row];
    NSLog(@"%@", selFood);
    self.titleButton.titleLabel.text = selFood;
}

#pragma mark - lazy loading
- (UIPickerView *)pickerView {
    if (!_pickerView) {
        _pickerView = [[UIPickerView alloc] initWithFrame:CGRectMake(0, 200, self.view.bounds.size.width, 320)];
        _pickerView.delegate = self;
        _pickerView.dataSource = self;
//        _pickerView.showsSelectionIndicator = YES;
    }
    return _pickerView;
    
}

- (NSArray *)dataSouce {
    if (!_dataSouce) {
        _dataSouce = @[@[@"西瓜",@"西红柿",@"番茄"],@[@"",@"西红柿",@"番茄"],@[@"西瓜",@"西红柿",@"番茄"]];
      
    }
    return _dataSouce;
}

- (UIButton *)titleButton
{
    if (!_titleButton) {
        _titleButton = [[UIButton alloc] init];
        _titleButton.frame = CGRectMake(0, 100, MAIN_SCREEN_WIDTH, 50);
        [_titleButton setTitle:@"点击选择" forState:UIControlStateNormal];
        [_titleButton addTarget:self action:@selector(getTitle:) forControlEvents:UIControlEventTouchUpInside];
    }
    
    return _titleButton;
}

- (UIButton *)confirmButton
{
    if (!_confirmButton) {
        _confirmButton = [[UIButton alloc] init];
        _confirmButton.frame = CGRectMake(0, 150, MAIN_SCREEN_WIDTH, 50);
        [_confirmButton setTitle:@"点击确认" forState:UIControlStateNormal];
    }
    
    return _confirmButton;
}
@end
