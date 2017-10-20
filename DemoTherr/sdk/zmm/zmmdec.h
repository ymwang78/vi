#ifndef __zmmdec_h__
#define __zmmdec_h__

#include "zmmapi.h"


/* 统计信息结构 */
typedef struct tagTCH_STAT_INFO
{
	unsigned int	unSize;						//本结构体长度, sizeof
	unsigned int	unTimeStamp;				//统计时刻，GetTickCount
	unsigned int	unTimeDiff;					//统计时长,ms
	unsigned int	unBitRate;					//比特率B/s
	unsigned int	unLostRate;					//丢包率，丢包万分比
	unsigned int	unFrameRate1;				//读取视频帧帧率 fps
	unsigned int	unFrameRate2;				//解码器回调帧率 fps

	unsigned short	usWidth;					// 视频宽度
	unsigned short	usHeight;					// 视频高度

	int		    	nStartTime;					//通道开始时间，time-t
	int		    	nConnectTime;				//通道连接建立时间，time-t

	unsigned long long	u64RecvPacket1;			//自通道建立后网络上收到的包数目
	unsigned long long	u64RecvByte1;			//自通道建立后网络上收到的字节数
	unsigned long long	u64RecvPacket2;			//自通道建立后协议层收到的有效包数目
	unsigned long long	u64RecvByte2;			//自通道建立后协议层收到的有效字节数

	unsigned int		unAudioType;				// 音频编码类型v2
	unsigned int		unVideoType;				// 视频编码类型v2，如(MAKEFOURCC('S', 'V', 'M', '4')) 表示 星望mpeg4
	unsigned char		ucAudioType;				// 音频编码类型
	unsigned char		ucVideoType;				// 视频编码类型

	unsigned short		usRealLocalPort;			//本地使用的真实端口
	unsigned short		usLocalPort;				//本地绑定的端口
	unsigned short		usPeerPort;					//对方端口
	char		szRealLocalAddr[64];			//本地真实地址
	char		szLocalAddr[64];				//本地绑定地址
	char		szPeerAddr[64];					//对方地址

	char		szScokType[8];					//SOCKET 类型 tcp,udp...

}TCH_STAT_INFO, *PTCH_STAT_INFO;
#ifdef WIN32
#else
#define CDECL
#define TRUE 1
#define FALSE 0
#define _T(x) x
typedef unsigned DWORD;
typedef void*  HWND;
#if !defined(OBJC_HIDE_64) && TARGET_OS_IPHONE && __LP64__
typedef bool BOOL;
#else
typedef signed char BOOL;
// BOOL is explicitly signed so @encode(BOOL) == "c" rather than "C"
// even if -funsigned-char is used.
#endif
typedef char TCHAR;
typedef unsigned char* LPBYTE;
typedef struct _GUID{
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
}GUID;

#ifndef UTINY_WAVEFORMATEX
#define UTINY_WAVEFORMATEX
typedef struct tWAVEFORMATEX
{
    unsigned short  wFormatTag;
    short  nChannels;
    unsigned nSamplesPerSec;
    unsigned nAvgBytesPerSec;
    unsigned short  nBlockAlign;
    unsigned short  wBitsPerSample;
    unsigned short  cbSize;
} WAVEFORMATEX;
#endif

#endif //defined(__MACH__)

enum _ZMMDEC_EVENT {
    ZMMDEC_EVENT_CONN = 1,    //network connect
    ZMMDEC_EVENT_DISCONN ,
    ZMMDEC_EVENT_NEW,         //new channel recv data
};

enum _ZMMDEC_STREAM {
    ZMMDEC_STREAM_ALL, //全部发送
    ZMMDEC_STREAM_IFRAME, //只发送关键帧
    ZMMDEC_STREAM_PAUSE, //暂停发送
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

    //获取到完整视频帧回调
    typedef int (*MEDIA_VIDEORAWFRAME_PROC)(unsigned index, unsigned char* buf, int len, int fmt, int timestamp, int keyflag, void* param);
    
    //播放视频前的回调，pBuf：视频缓冲；nLen：视频数据长度；nWidth：宽度；nHeight：高度；nTimeStamp：时间戳；nCSType：颜色空间类型；pParam：用户用据
    typedef int (*MEDIA_VIDEOPLAY_PROC)(unsigned index, unsigned char* outdata[4], int stride[4], int width, int height, int fmt, int timestamp, void* param);

    //播放音频前的回调，pBuf：音频缓冲；nLen：音频数据长度；lpAudioFormat：音频格式，换为WAVEFORMATEX*使用；pParam：用户数据
    typedef int (*MEDIA_AUDIOPLAY_PROC)(unsigned index, unsigned char* buf, int len, void* audiofmt, unsigned timestamp, void* param);

    typedef int (*MEDIA_EVENT_PROC)(unsigned evt, unsigned ssrc, void* param);

    typedef struct _zmmdec_handle {
        int unused;
    }*zmmdec_handle;
    
ZMM_API int  zmmdec_init();

ZMM_API int  zmmdec_fini();

ZMM_API int  zmmdec_setglobalprop(const TCHAR* name, const TCHAR* val);

ZMM_API zmmdec_handle  zmmdec_new(void* ctx);

ZMM_API void* zmmdec_getctx(zmmdec_handle handle);

ZMM_API void  zmmdec_delete(zmmdec_handle handle);

ZMM_API int  zmmdec_startstream(zmmdec_handle handle, const char* remote_ip, unsigned short remote_port, unsigned my_outip, unsigned short local_port, unsigned char tguid[16], int nettype, const char* local_ip);
    
ZMM_API int  zmmdec_stopstream(zmmdec_handle handle);

ZMM_API int  zmmdec_setstream(zmmdec_handle handle, enum _ZMMDEC_STREAM opt);

ZMM_API int  zmmdec_startdecode(zmmdec_handle handle, unsigned char index, unsigned ssrc, HWND hWnd, int playaudio, int fmt);

/*播放和暂停播放, flag bit0:播放视频，bit1:播放音频*/
ZMM_API int  zmmdec_playpause(zmmdec_handle handle, unsigned char index, unsigned flag);

ZMM_API int  zmmdec_stopdecode(zmmdec_handle handle, unsigned char index);

ZMM_API int  zmmdec_getstatinfo(zmmdec_handle handle, PTCH_STAT_INFO pStatInfo);

ZMM_API int  zmmdec_startlocalrecord(zmmdec_handle handle, const char* path_file, long record_time, bool audio_on);

ZMM_API int  zmmdec_stoplocalrecord(zmmdec_handle handle);

ZMM_API int  zmmdec_snapshot(zmmdec_handle handle, const char* path_file);

ZMM_API int  zmmdec_setaudioplaycallback(zmmdec_handle handle, MEDIA_AUDIOPLAY_PROC cb, void* param);

ZMM_API int  zmmdec_setvideorawframecallback(zmmdec_handle handle, MEDIA_VIDEORAWFRAME_PROC cb, void* param);

ZMM_API int  zmmdec_setvideoplaycallback(zmmdec_handle handle, MEDIA_VIDEOPLAY_PROC cb, void* param);

ZMM_API int  zmmdec_seteventcallback(zmmdec_handle handle, MEDIA_EVENT_PROC cb, void* param);

ZMM_API int  zmmdec_torgb24(unsigned char* dst, unsigned char* src, int srcfmt, unsigned width, unsigned height);

ZMM_API int  zmmdec_torgb32(unsigned char* dst, unsigned char* src, int srcfmt, unsigned width, unsigned height);

ZMM_API int  zmmdec_toyuv420(unsigned char* dst, unsigned char* src, int srcfmt, unsigned width, unsigned height);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __zmmdec_h__ */

