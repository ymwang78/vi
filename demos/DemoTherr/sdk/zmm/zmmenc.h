#pragma once

#include "zmmapi.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WIN32
    typedef struct {
        wchar_t*	DisplayName;
        wchar_t*	FriendlyName;
        unsigned	isvideo;
    } zmm_deviceinfo;
#else
#   define TRUE 1
#   define FALSE 0
#   define __cdecl
    typedef unsigned char WORD;
    typedef unsigned DWORD;
    typedef long LONG;
    typedef void*  HWND;    
    typedef char TCHAR;
    typedef int HRESULT;

#ifndef UTINY_WAVEFORMATEX
#   define UTINY_WAVEFORMATEX
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
#endif //UTINY_WAVEFORMATEX

    typedef struct tagBITMAPINFOHEADER {
        DWORD      biSize;
        LONG       biWidth;
        LONG       biHeight;
        WORD       biPlanes;
        WORD       biBitCount;
        DWORD      biCompression;
        DWORD      biSizeImage;
        LONG       biXPelsPerMeter;
        LONG       biYPelsPerMeter;
        DWORD      biClrUsed;
        DWORD      biClrImportant;
    } BITMAPINFOHEADER, *LPBITMAPINFOHEADER, *PBITMAPINFOHEADER;

#endif //WIN32

    typedef struct _zmmenc_video_handle {
        int		unused;
    }*zmmenc_video_handle;

    typedef struct _zmmenc_audio_handle {
        int		unused;
    }*zmmenc_audio_handle;

    typedef struct {
        unsigned vtype;
        unsigned width;
        unsigned height;
        unsigned bitrate;
        unsigned keyframe;  /* milliseconds */
        unsigned framerate;
        unsigned char bVBR; /* see: ms-help://MS.MSDNQTR.v90.en/codec_api/html/usingvbrencoding.htm */
    }zmmenc_video_encparam;

    typedef struct {
        unsigned atype;
        unsigned short wChannel;        /* 1 or 2 */
        unsigned short wBitsPerSample;	/* 8 or 16 */
        unsigned nSamplesPerSec;        /* 8,000; 11,025; 16,000; or 22050, 44100, 48000 */
        unsigned nAvgBytesPerSec;
        unsigned nDelay;        /* 250,300...ms*/
        unsigned AES;           /* 0, 1, or 2, see: ms-help://MS.MSDNQTR.v90.en/codec_api/html/mfpkey_wmaaecma_featr_aesproperty.htm*/
        unsigned EchoLength;    /* 128 256 512 1024, see: ms-help://MS.MSDNQTR.v90.en/codec_api/html/mfpkey_wmaaecma_featr_echo_lengthproperty.htm */
        unsigned char bAGC;     /* see: ms-help://MS.MSDNQTR.v90.en/codec_api/html/mfpkey_wmaaecma_featr_agcproperty.htm */
    }zmmenc_audio_encparam;

    //keyframe mean private data length (even if 0), so don't bind control flag with keyframe
    enum
    {
        ZMMENC_FLAG_KEYFRAME = 0x1,
        ZMMENC_FLAG_VIDEO = 0x2,
        ZMMENC_FLAG_AUDIO = 0x4,
        ZMMENC_FLAG_CONTROL = 0x8,
        ZMMENC_FLAG_RAW = 0x10,
        ZMMENC_FLAG_RESEND = 0x20,
    };

    enum ZMMENC_VIDEOROTATE {
        ZMMENC_VIDEOROTATE_0,
        ZMMENC_VIDEOROTATE_90,
        ZMMENC_VIDEOROTATE_180,
        ZMMENC_VIDEOROTATE_270,
    };

    enum
    {
        ZMMENC_EVENT_CONN = 1,
        ZMMENC_EVENT_DISCONN,
        ZMMENC_EVENT_NEW,
        ZMMENC_EVENT_VIDEODENY,
        ZMMENC_EVENT_AUDIODENY,
    };

    enum ZMMENC_VIDEO_MODE {
        ZMMENC_VIDEO_MODE_FULL,
        ZMMENC_VIDEO_MODE_VERCENTER,
    };

    typedef struct _zmmenc_handle {
        int unused;
    }*zmmenc_handle;

    typedef void(*PFUN_ZMMENC_EVENT_PROC)    (zmmenc_handle hd, unsigned evt, void* param, void* ctx);
    typedef void(*PFUN_ZMMENC_PARAMCALLBACK) (void* context, unsigned flag, void* encparam);
    typedef void(*PFUN_ZMMENC_PCMCALLBACK)   (void* context, const void* pData, unsigned len, const WAVEFORMATEX* param);
    typedef void(*PFUN_ZMMENC_VIDEOCALLBACK) (void* context, const void* pData, const BITMAPINFOHEADER* param, int step);
    typedef void(*PFUN_ZMMENC_AUDIOCALLBACK) (void* context, const void* pData, unsigned length, unsigned flag,
        const void* privatedata, unsigned short privatelength, char payload);

#ifdef _WIN32
    ZMM_API zmm_deviceinfo* zmm_enum_device();
    ZMM_API void zmm_free_deviceinfo(zmm_deviceinfo*);
#endif

    ZMM_API zmmenc_handle zmmenc_new(PFUN_ZMMENC_EVENT_PROC, bool preview, void* ctx);
    ZMM_API void*  zmmenc_getctx(zmmenc_handle handle);
    ZMM_API void zmmenc_delete(zmmenc_handle);

    ZMM_API int zmmenc_startstream(zmmenc_handle, const char* local_ip, unsigned short localport,
        const char* remote_ip, unsigned short remote_port, unsigned my_outip, char* actstr, unsigned actlen);
    ZMM_API void zmmenc_stopstream(zmmenc_handle);

    ZMM_API int zmmenc_start_video(zmmenc_handle, const TCHAR* videoname, zmmenc_video_encparam param,
        PFUN_ZMMENC_VIDEOCALLBACK, void* context, HWND hwnd, HWND hwndmsg, unsigned msg);
    ZMM_API int zmmenc_switch_video(zmmenc_handle handle,
                                    const TCHAR* videoname);
    ZMM_API void zmmenc_stop_video(zmmenc_handle);
    ZMM_API void zmmenc_set_videomode(zmmenc_handle ench, enum ZMMENC_VIDEO_MODE v);
    ZMM_API void zmmenc_set_video(zmmenc_handle, zmmenc_video_encparam);
    ZMM_API void zmmenc_set_beautify(zmmenc_handle, bool v);
    ZMM_API int  zmmenc_encode_video(zmmenc_handle, const void* pData, unsigned length, const BITMAPINFOHEADER* param,
        int rotate, enum ZMMENC_VIDEO_MODE);

    ZMM_API int zmmenc_start_audio(zmmenc_handle,
        const TCHAR* audioname, zmmenc_audio_encparam param,
        PFUN_ZMMENC_PCMCALLBACK, PFUN_ZMMENC_AUDIOCALLBACK cbaudio, void* context, HWND hwndmsg, unsigned msg);
    ZMM_API void zmmenc_stop_audio(zmmenc_handle);
    ZMM_API int  zmmenc_encode_audio(zmmenc_handle, const void* pData, unsigned length);

#ifdef _WIN32

    ZMM_API void zmmenc_resize_video(zmmenc_handle);
    ZMM_API void zmmenc_event(zmmenc_handle, unsigned param1, unsigned param2);

#endif //_WIN32

#ifdef __cplusplus
}
#endif
