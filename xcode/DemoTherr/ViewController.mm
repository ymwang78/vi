//
//  ViewController.m
//  DemoTherr
//
//  Created by 丁寅初 on 2017/8/29.
//  Copyright © 2017年 dyc. All rights reserved.
//

#import "ViewController.h"
#import "zdsdk/zdsdk.h"
#import "FlyGLView.h"
#import "FlyVideoFrame.h"
@interface ViewController ()
@property (weak, nonatomic) IBOutlet UIButton *button;
@property (weak, nonatomic) IBOutlet UIView *bgView;
@property (weak, nonatomic) IBOutlet UILabel *label;
@property (weak, nonatomic) IBOutlet UIImageView *imageView;

@end

@implementation ViewController

extern "C" {
    void messageCallback(void* identity, int msg_type, int error_code, void* msg_context) {
        NSLog(@"messageCallback-------------%@---------%d----------%d--------%@",identity,msg_type,error_code,msg_context);
    }
    
    void notifyCallback(void* identity, int notify_type, void* notify_info) {
        NSLog(@"notifyCallback-------------%d", notify_type);
    }
}


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    [self.button addTarget:self action:@selector(button:) forControlEvents:UIControlEventTouchUpInside];
    
    self.button.selected = YES;
    [self.bgView addSubview:self.label];
    [self.bgView addSubview:self.imageView];
    self.bgView.frame = CGRectMake(100, 200, 0, 0 );
    self.bgView.clipsToBounds=YES;
    
  
    ZDSDK_Init();
    
    NSString * uas_ipStr = @"120.55.119.129";
    NSString * emailStr = @"laizhun001@zhidu.biz";
    NSString * passwordStr = @"1234";

    _zdsdk_t * zd_t = ZDSDK_Login(messageCallback, notifyCallback, 0,
              [uas_ipStr UTF8String], (short) 5555,
              [emailStr UTF8String], [passwordStr UTF8String]);
    
    //FlyGLView * flyView = [[FlyGLView alloc] initWithFrame:CGRectMake(10, 50, 200, 100) videoPixelFormat:FlyPixelFormatYUV];
    //NSString * dev_channel = @"340200-340200200000401013-0001-0001";
    //int start = ZDSDK_MonitorStart(zd_t, [dev_channel UTF8String], 0, 0, flyView);
}


- (void)button:(UIButton *)btn {
    if (btn.selected == YES) {
        [UIView animateWithDuration:3 animations:^{
            self.bgView.frame = CGRectMake(100, 200, 200, 200 );
        }];
        btn.selected = NO;
    } else {
        [UIView animateWithDuration:3 animations:^{
            self.bgView.frame = CGRectMake(100, 200, 0, 0 );
        }];
        btn.selected = YES;
    }
    
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
