//
//  WebViewBaseVC.m
//  排序总结
//
//  Created by gjfax on 2019/3/21.
//  Copyright © 2019 macheng. All rights reserved.
//

#import "WebViewBaseVC.h"
#import "WYWebProgressLayer.h"
#import "CacheFileManagerTool.h"

@interface WebViewBaseVC ()<UIWebViewDelegate>
@property (nonatomic, strong) UIWebView *webView;
@property (nonatomic,strong) WYWebProgressLayer  *progressLayer;
@end

@implementation WebViewBaseVC

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // 1,创建UIWebView(位置跟屏幕的大小一致)
    _webView = [[UIWebView alloc] initWithFrame:CGRectMake(0, 114, MAIN_SCREEN_WIDTH, MAIN_SCREEN_HEIGHT - 114)];
    
    // 2,设置属性
    //自动缩放适应
    _webView.scalesPageToFit = YES;
    //交互设置
    _webView.userInteractionEnabled =YES;
    
    // 3,加载网站内容
    //网络资源：加载http请求，xcode7以后需要设置：在Xcode7.1中苹果更改了这项设定的名称，在App Transport Security Settings下添加Allows Arbitrary Loads类型Boolean,值设为YES
    NSString *urlPath = @"https://www.baidu.com";
    NSURL *url = [NSURL URLWithString:urlPath];
    
    
    // 如果有缓存，那么就从缓存中取得
    NSString *htmlString = [CacheFileManagerTool readFromCache:urlPath];
    if(!(htmlString == nil || [htmlString isEqualToString:@""])){
        
        [_webView loadHTMLString:htmlString baseURL:url];
        
    }else{
        
        [_webView loadRequest:[NSURLRequest requestWithURL:url]];
        [CacheFileManagerTool writeToCache:urlPath];
    };
    
//    NSURLRequest *urlRequest = [[NSURLRequest alloc] initWithURL:url];
//    [_webView loadRequest:urlRequest];
    
    //加载本地资源
    //    NSString *filePath = [[NSBundle mainBundle] pathForResource:@"gyyh@2x" ofType:@"png"];
    //    NSURL *localUrl = [NSURL fileURLWithPath:filePath];
    //    NSURLRequest *localRequest = [[NSURLRequest alloc] initWithURL:localUrl];
    //    [webView loadRequest:localRequest];
    
    // 4,显示webView
    [self.view addSubview:_webView];
    
    // 5,设置代理
    _webView.delegate = self;
    
    // 6, 创建前进和回退按钮
    UIView *backgroundView = [[UIView alloc] initWithFrame:CGRectMake(0, 64, MAIN_SCREEN_WIDTH, 50)];
    backgroundView.backgroundColor = [UIColor whiteColor];
    [self.view addSubview:backgroundView];
    
    UIButton *btn1 = [[UIButton alloc] initWithFrame:CGRectMake(0, 64, 50, 50)];
    btn1.backgroundColor = [UIColor blueColor];
    [btn1 setTitle:@"后退" forState:UIControlStateNormal];
    btn1.showsTouchWhenHighlighted = YES;
    [btn1 addTarget:self action:@selector(goBack:) forControlEvents:UIControlEventTouchUpInside];
    
    UIButton *btn3 = [[UIButton alloc] initWithFrame:CGRectMake(100, 64, 50, 50)];
    btn3.backgroundColor = [UIColor yellowColor];
    [btn3 setTitle:@"刷新" forState:UIControlStateNormal];
    [btn3 setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    btn3.showsTouchWhenHighlighted = YES;
    [btn3 addTarget:self action:@selector(refreshUrl) forControlEvents:UIControlEventTouchUpInside];
    
    UIButton *btn4 = [[UIButton alloc] initWithFrame:CGRectMake(200, 64, 50, 50)];
    btn4.backgroundColor = [UIColor blackColor];
    [btn4 setTitle:@"禁止" forState:UIControlStateNormal];
    btn4.showsTouchWhenHighlighted = YES;
    [btn4 addTarget:self action:@selector(stopLoading) forControlEvents:UIControlEventTouchUpInside];
    
    UIButton *btn2 = [[UIButton alloc] initWithFrame:CGRectMake(325, 64, 50, 50)];
    btn2.backgroundColor = [UIColor redColor];
    [btn2 setTitle:@"前进" forState:UIControlStateNormal];
    btn2.showsTouchWhenHighlighted = YES;
    [btn2 addTarget:self action:@selector(goForward:) forControlEvents:UIControlEventTouchUpInside];
    
    
    [self.view addSubview:btn1];
    [self.view addSubview:btn2];
    [self.view addSubview:btn3];
    [self.view addSubview:btn4];
    
    // 7，添加进度条:webViewDidStartLoad方法里
    
    // 8，添加缓存
    
    // 9，添加post请求
}

#pragma mark - 返回
- (void)goBack: (NSString *)goBackBtn{
    [_webView goBack];
}
#pragma mark - 前进
- (void)goForward: (NSString *)goForwardBtn {
    [_webView goForward];
}
#pragma mark - 刷新url
- (void)refreshUrl {
    NSURL *url = [NSURL URLWithString:@"https://www.jd.com/"];
    NSURLRequest *urlRequest = [[NSURLRequest alloc] initWithURL:url];
    [_webView loadRequest:urlRequest];
}
#pragma mark - 停止加载
-(void)stopLoading {
    
    [_webView stopLoading];
    
}
#pragma mark - UIWebView delegate
// 可以用来加载拦截特定的站点
- (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType {
    //1.截取到当前地址
    NSString *url1=request.URL.absoluteString;
    //2.做你想做的操作
    if ([url1 isEqualToString:@"https://www.jd.com/"]) {
        NSLog(@"跳转到京东啦");
    }
    return YES;
}

// 加载前调用
- (void)webViewDidStartLoad:(UIWebView *)webView {
    NSLog(@"开始加载");
    _progressLayer = [WYWebProgressLayer layerWithFrame:CGRectMake(0, 114, SCREEN_WIDTH, 2)];
    [self.view.layer addSublayer:_progressLayer];
    [_progressLayer startLoad];
}

// 加载后调用
- (void)webViewDidFinishLoad:(UIWebView *)webView {
    NSLog(@"加载结束");
   [_progressLayer finishedLoad];
}

// 加载失败后失败的原因
- (void)webView:(UIWebView *)webView didFailLoadWithError:( NSError *)error {
    NSLog(@"失败%@",error);
     [_progressLayer finishedLoad];
}

#pragma mark -  基本介绍：前进，后退，刷新，禁止

#pragma mark - 进度条和过渡页

#pragma mark -  webview发送post请求



@end
