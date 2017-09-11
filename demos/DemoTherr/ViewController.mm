//
//  ViewController.m
//  DemoTherr
//
//  Created by 丁寅初 on 2017/8/29.
//  Copyright © 2017年 dyc. All rights reserved.
//

#import "ViewController.h"
#import "zdsdk.h"
#import "FlyGLView.h"
#import "FlyVideoFrame.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    NSString * uas_ipStr = @"120.55.119.129";
    NSString * emailStr = @"laizhun001@zhidu.biz";
    NSString * passwordStr = @"laizhun001@zhidu.biz";
    
    _zdsdk_t * zd_t = ZDSDK_Login(messageCallback, notifyCallback, 0, [uas_ipStr UTF8String], (short) 5555, [emailStr UTF8String], [passwordStr UTF8String]);


    
//    FlyGLView * flyView = [[FlyGLView alloc] initWithFrame:CGRectMake(10, 50, 200, 100) videoPixelFormat:FlyPixelFormatYUV];
//    NSString * dev_channel = @"340200-340200200000401013-0001-0001";
//    int start = ZDSDK_MonitorStart(zd_t, [dev_channel UTF8String], 0, 0, flyView);
}
void messageCallback(void* identity, int msg_type, int error_code, void* msg_context) {
    NSLog(@"messageCallback-------------%@---------%d----------%d--------%@",identity,msg_type,error_code,msg_context);
}
void notifyCallback(void* identity, int notify_type, void* notify_info) {
    NSLog(@"notifyCallback-------------%@----------%d--------%@",identity,notify_type,notify_info);
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
