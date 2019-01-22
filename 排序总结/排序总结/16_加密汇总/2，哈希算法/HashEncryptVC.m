//
//  HashEncryptVC.m
//  排序总结
//
//  Created by gjfax on 2019/1/22.
//  Copyright © 2019 macheng. All rights reserved.
//

#import "HashEncryptVC.h"
#import <CommonCrypto/CommonDigest.h>

@interface HashEncryptVC ()
@property (weak, nonatomic) IBOutlet UITextView *textView1;
@property (weak, nonatomic) IBOutlet UITextView *textView2;

@end

@implementation HashEncryptVC

- (void)viewDidLoad {
    [super viewDidLoad];
    
}

- (IBAction)encryptAction:(id)sender {
    NSString *text1 = [self md5:_textView1.text];
    NSString *text2 = [self md5String:_textView1.text];
    NSLog(@"✅text1:%@",text1);
    NSLog(@"✅text2:%@",text2);
    _textView2.text = text1;
}

#pragma mark -  方法1
- (NSString *)md5:(NSString *)str
{
    const char *cStr = [str UTF8String];
    unsigned char result[16];
    CC_MD5(cStr, strlen(cStr), result); // This is the md5 call
    return [NSString stringWithFormat:
            @"%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
            result[0], result[1], result[2], result[3],
            result[4], result[5], result[6], result[7],
            result[8], result[9], result[10], result[11],
            result[12], result[13], result[14], result[15]
            ];
}

#pragma mark -  方法2
- (NSString *)md5String:(NSString *)string {
    const char *str = string.UTF8String;
    uint8_t buffer[CC_MD5_DIGEST_LENGTH];
    
    CC_MD5(str, (CC_LONG)strlen(str), buffer);
    
    return [self stringFromBytes:buffer length:CC_MD5_DIGEST_LENGTH];
}

- (NSString *)stringFromBytes:(uint8_t *)bytes length:(int)length {
    NSMutableString *strM = [NSMutableString string];
    
    for (int i = 0; i < length; i++) {
        [strM appendFormat:@"%02x", bytes[i]];
    }
    
    return [strM copy];
}

@end
