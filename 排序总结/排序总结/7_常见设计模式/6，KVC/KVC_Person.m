//
//  KVC_Person.m
//  排序总结
//
//  Created by gjfax on 2020/1/16.
//  Copyright © 2020 macheng. All rights reserved.
//

#import "KVC_Person.h"
@interface KVC_Person ()
@property (nonatomic, assign) float weight;
@end
@implementation KVC_Person

-(NSString *)description
{
    //重写description方法，拼一个字符串，按既定个数输出
    return [NSString stringWithFormat:@"<%@:%p>,{height:%f,school:%@,name:%@,age:%d,weight:%f}",[self class],self,_height,self.school,self.name,self.age,self.weight];
}
@end
