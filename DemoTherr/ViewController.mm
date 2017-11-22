//
//  ViewController.m
//  DemoTherr
//

#import "ViewController.h"
#import "zdsdk/zdsdk.h"
#import "FlyGLView.h"
#import "FlyVideoFrame.h"
#include <vector>
@interface ViewController ()
@property (weak, nonatomic) IBOutlet UIButton *button;
@property (weak, nonatomic) IBOutlet UIView *bgView;//要呈现的画面所用的 View
@property (weak, nonatomic) IBOutlet UILabel *label;

@end

static zdsdk_t _zd_t;
struct zdsdk_context_t
{
    ViewController* pController;
};


@implementation ViewController

extern "C" {
    static void messageCallback(void* identity, int msg_type, int error_code, void* msg_context) {
        zdsdk_context_t* ctx = (zdsdk_context_t*)(identity);
        [ctx->pController messageCallback:msg_type errorCode:error_code context:msg_context];
        //dispatch_sync(dispatch_get_main_queue(), ^{
        //    [ctx->pController messageCallback:msg_type errorCode:error_code context:msg_context];
        //});
    }
    static void notifyCallback(void* identity, int notify_type, void* notify_info) {
        zdsdk_context_t* ctx = (zdsdk_context_t*)(identity);
        dispatch_sync(dispatch_get_main_queue(), ^{
            [ctx->pController eventCallback:notify_type context:notify_info];
        });
    }
}

- (void)messageCallback:(int)msgtype errorCode:(int)errorcode context:(void*)ctx {
    NSLog(@"messageCallback---------%d----------%d------%@", msgtype,errorcode,ctx);
    switch ((ERV_MSG_TYPE)msgtype) {
        case MSG_TYPE_LOGIN: {
            //NOW YOU CAN GET FDLIST OR CHANNELLIST
            break;
        }
        case MSG_TYPE_LOGOUT: {
            break;
        }
        default:
            break;
    }
}

- (void)eventCallback:(int)evttype context:(void*)ctx{
    NSLog(@"eventCallback----------%d", evttype);
    switch((ERV_EVENT_TYPE)evttype){
        case EVENT_TYPE_RUN:
            ZDSDK_Run(_zd_t);
            break;
        default:
            break;
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
    NSString * emailStr = @"zhidu002@zhidu.biz";
    NSString * passwordStr = @"1234";

    zdsdk_context_t* ctx = new zdsdk_context_t;
    ctx->pController = self;
    _zd_t = ZDSDK_Login(messageCallback, notifyCallback, (void*)ctx,
                        [uas_ipStr UTF8String], (short) 5555,
                        [emailStr UTF8String], [passwordStr UTF8String]);
    
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
    int fdsize = ZDSDK_GetFDlist(_zd_t, 0, 0);
    if (fdsize <= 0)
        return;
    std::vector<ZDSDK_FD_INFO> vec(fdsize+20);
    fdsize = ZDSDK_GetFDlist(_zd_t, &vec[0], vec.size());
    if (fdsize < 0)
        return;
    for (unsigned i = 0; i < fdsize; ++i) {
        NSLog(@"fdid:%s", vec[i].id);
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
