//
//  DarkerCommand.h
//  DesignModeDemo
//
//  Created by koala on 2018/4/24.
//  Copyright © 2018年 koala. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CommandProtocol.h"
#import "Receiver.h"

@interface DarkerCommand : NSObject <CommandProtocol>

// 绑定接收器
- (instancetype)initWithReceiver:(Receiver *)receiver paramter:(CGFloat)paramter;

@end
