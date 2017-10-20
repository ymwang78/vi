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
@property (weak, nonatomic) IBOutlet UIView *bgView;//要呈现的画面所用的 View
@property (weak, nonatomic) IBOutlet UILabel *label;

@end

@implementation ViewController
extern "C" {
    void messageCallback(void* identity, int msg_type, int error_code, void* msg_context) {
        NSLog(@"messageCallback-------------%@---------%d----------%d--------%@",identity,msg_type,error_code,msg_context);
    }
    void notifyCallback(void* identity, int notify_type, void* notify_info) {
        NSLog(@"notifyCallback-------------%d", notify_type);
        printf("+++++++++++++++++=%s",notify_info);
    }
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    

    self.button.selected = YES;
    [self.bgView addSubview:self.label];
    self.bgView.clipsToBounds=YES;
    
    
    ZDSDK_Init();
    
    
    NSString * uas_ipStr = @"120.55.119.129";
    NSString * emailStr = @"laizhun001@zhidu.biz";
    NSString * passwordStr = @"laizhun001@zhidu.biz";

    _zdsdk_t * zd_t = ZDSDK_Login(messageCallback, notifyCallback, 0, [uas_ipStr UTF8String], (short) 5555, [emailStr UTF8String], [passwordStr UTF8String]);



//    FlyGLView * flyView = [[FlyGLView alloc] initWithFrame:CGRectMake(10, 50, 200, 100) videoPixelFormat:FlyPixelFormatYUV];
//    NSString * dev_channel = @"340200-340200200000401013-0001-0001";
//    int start = ZDSDK_MonitorStart(zd_t, [dev_channel UTF8String], 0, 0, flyView);
}
//----------------------------------------下边需要操作打印数据---------------------------------------
//上按钮
- (IBAction)shangBtn:(UIButton *)sender {
}
//下按钮
- (IBAction)xiaBtn:(UIButton *)sender {
}
//左按钮
- (IBAction)zuoBtn:(UIButton *)sender {
}
//右按钮
- (IBAction)youBtn:(UIButton *)sender {
}
//开启按钮
- (IBAction)kaiqiBtn:(UIButton *)sender {
}
//暂停按钮
- (IBAction)zantingBtn:(UIButton *)sender {
}
//拍照按钮
- (IBAction)paizhaoBtn:(UIButton *)sender {
}
//录像按钮
- (IBAction)luxiangBtn:(UIButton *)sender {
}
//翻转按钮
- (IBAction)fanzhuanBtn:(UIButton *)sender {
}
//声音开关
- (IBAction)shengyinBtn:(UIButton *)sender {
}
//拉取列表数据:把通道列表/设备列表数据打印出来即可
- (IBAction)laquBtn:(UIButton *)sender {
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
