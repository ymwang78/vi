//
//  ViewController.m
//  DemoTherr
//

#import "ViewController.h"
#import "zdsdk/zdsdk.h"
#import "FlyGLView.h"
#import "FlyVideoFrame.h"
#include <vector>
#include <deque>
#include <zce/zce_api.h>
#include <zce/zce_sync.h>
#include <zce/zce_smartptr.h>
@interface ViewController ()
@property (weak, nonatomic) IBOutlet UIButton *button;
@property (weak, nonatomic) IBOutlet UIView *bgView;//要呈现的画面所用的 View
@property (weak, nonatomic) IBOutlet UILabel *label;

@end

struct zdsdk_context_t
{
    ViewController* pController;
    FlyGLView* pView;
};

struct zdsdk_frame_t : public zce_smartptr_mtbase
{
    std::vector<zce_byte> buffer;
    unsigned datalen;
    
    unsigned width;
    unsigned height;
    unsigned fmt;
};

static zdsdk_t _zd_t;
static zdsdk_context_t _zd_ctx;
static unsigned _ui_threadid;
static zce_mutex _lock;
static std::deque<zce_smartptr<zdsdk_frame_t> > empty_queue_;
static std::deque<zce_smartptr<zdsdk_frame_t> > data_queue_;

@implementation ViewController

extern "C" {
    static void messageCallback(void* identity, int msg_type, int error_code, void* msg_context) {
        zdsdk_context_t* ctx = (zdsdk_context_t*)(identity);
        if (zce_thread_id() == _ui_threadid) {
            [ctx->pController messageCallback:msg_type errorCode:error_code context:msg_context];
        }
        else {
            dispatch_sync(dispatch_get_main_queue(), ^{
                [ctx->pController messageCallback:msg_type errorCode:error_code context:msg_context];
            });
        }
    }
    
    static void notifyCallback(void* identity, int notify_type, void* notify_info) {
        zdsdk_context_t* ctx = (zdsdk_context_t*)(identity);
        if (zce_thread_id() == _ui_threadid) {
            [ctx->pController eventCallback:notify_type context:notify_info];
        }
        else {
            dispatch_sync(dispatch_get_main_queue(), ^{
                [ctx->pController eventCallback:notify_type context:notify_info];
            });
        }
    }
    
    static int mediaCallback(unsigned index, unsigned char* outdata[4], int stride[4], int width, int height, int fmt, int timestamp, void* param) {
        NSLog(@"messageCallback---------%d----------", width);
        zce_smartptr<zdsdk_frame_t> frame_ptr;
        do {
            zce_guard<zce_mutex> g(_lock);
            if (!empty_queue_.empty()) {
                frame_ptr = empty_queue_.front();
                empty_queue_.pop_front();
            }
            else {
                frame_ptr = new zdsdk_frame_t;
            }
            int nLen = width* height* 3;
            if (frame_ptr->buffer.size() < nLen)
                frame_ptr->buffer.resize(nLen);
            memcpy(&frame_ptr->buffer[0], outdata[0], width* height);
            memcpy(&frame_ptr->buffer[width* height], outdata[1], width* height / 4);
            memcpy(&frame_ptr->buffer[width* height * 5 / 4], outdata[2], width* height /4);
            frame_ptr->datalen = nLen;
            frame_ptr->width = width;
            frame_ptr->height = height;
            frame_ptr->fmt = fmt;
            
            data_queue_.push_back(frame_ptr);
            
            if (data_queue_.size() > 4) {
                auto frontptr = data_queue_.front();
                data_queue_.pop_front();
                empty_queue_.push_back(frontptr);
            }
        }while(0);

        if (zce_thread_id() == _ui_threadid) {
            [_zd_ctx.pController mediaCallback];
        }
        else {
            dispatch_sync(dispatch_get_main_queue(), ^{
                [_zd_ctx.pController mediaCallback];
            });
        }
        
        return 0;
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
        case MSG_TYPE_START_MONITOR: {
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

- (void)mediaCallback{
    NSLog(@"mediaCallback----------");
    zce_smartptr<zdsdk_frame_t> frame_ptr;
    {
        zce_guard<zce_mutex> g(_lock);
        if (data_queue_.empty())
            return;
        frame_ptr = data_queue_.front();
        data_queue_.pop_front();
    }
    [_zd_ctx.pView render:&frame_ptr->buffer[0] nWidth:frame_ptr->width nHeight:frame_ptr->height];
    {
        zce_guard<zce_mutex> g(_lock);
        empty_queue_.push_back(frame_ptr);
    }
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    self.button.selected = YES;
    self.bgView.clipsToBounds=YES;
    
    FlyGLView * flyView = [[FlyGLView alloc] initWithFrame:CGRectMake(10, 50, 200, 100) videoPixelFormat:FlyPixelFormatYUV];
    [self.bgView addSubview:flyView];
    
    ZDSDK_Init();
    
    _ui_threadid = zce_thread_id();
    
    NSString * uas_ipStr = @"120.55.119.129";
    NSString * emailStr = @"yadi002@zhidu.biz";
    NSString * passwordStr = @"1234";

    zdsdk_context_t* ctx = &_zd_ctx;
    ctx->pController = self;
    ctx->pView = flyView;
    
    _zd_t = ZDSDK_Login(messageCallback, notifyCallback, (void*)ctx,
                        [uas_ipStr UTF8String], (short) 5555,
                        [emailStr UTF8String], [passwordStr UTF8String]);
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
    NSString * dev_channel = @"340200-340200200000301085-0001-0001";
    ZDSDK_SetMediaDisplayCallback(_zd_t, mediaCallback);
    int start = ZDSDK_MonitorStart(_zd_t, [dev_channel UTF8String], 0, 0, 0);
    NSLog(@"ZDSDK_MonitorStart:%d", start);
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
