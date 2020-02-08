//
//  DifferentTypeFilesVC.m
//  排序总结
//
//  Created by gjfax on 2020/2/7.
//  Copyright © 2020 macheng. All rights reserved.
//

#import "DifferentTypeFilesVC.h"
#import "ShowPDFViewController.h"

@interface DifferentTypeFilesVC ()

@end

@implementation DifferentTypeFilesVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}

- (IBAction)demo1:(id)sender {

        ShowPDFViewController *vc = [[ShowPDFViewController alloc] init];
        
    //    vc.urlStr = @"http://oshsanwqi.bkt.clouddn.com/TestPDF.pdf";
        
    //    vc.urlStr =@"https://app.gjfax.com/APP_SERVER/remote/trading/getLegalAgreement?gqdm=161248&applicationId=110929";
        
        vc.urlStr = @"https://app.gjfax.com/APP_SERVER/remote/product/getProductSpecification?gqdm=161248";
        
        [self.navigationController pushViewController:vc animated:YES];
}


@end
