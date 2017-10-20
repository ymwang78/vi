#ifndef __zmmupdate_h__
#define __zmmupdate_h__

#include "zmmapi.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct{
    unsigned unused;
}* zmmupdate_handle;

/*some magic number for the status*/
enum _ZMMUPDATE_PERCENT {
    ZMMUPDATE_PERCENT_UNKNOWN     = -1,
    ZMMUPDATE_PERCENT_ERROR       = -2,
    ZMMUPDATE_PERCENT_NEEDNOT     = -3,
    ZMMUPDATE_PERCENT_PAUSED      = -4,
    ZMMUPDATE_PERCENT_RESUMED     = -5,
    ZMMUPDATE_PERCENT_FINISHED    = 101,
};

//初始化更新任务
ZMM_API zmmupdate_handle zmmupdate_init(const wchar_t* uniquename, const wchar_t* appdata_path);

//检查本地是否已经有下载完成的更新包，如果有，则执行之
ZMM_API void zmmupdate_check(zmmupdate_handle, const wchar_t* resourcename);

ZMM_API void zmmupdate_update_revision(zmmupdate_handle, const wchar_t* resourcename, const wchar_t* rev);

//执行检查更新包下载
ZMM_API void zmmupdate_update(zmmupdate_handle, const wchar_t* resourcename, const wchar_t* url, HWND hwnd, UINT msg, WPARAM wp);

ZMM_API void zmmupdate_fini(zmmupdate_handle);

ZMM_API void zmmupdate_resourc_location(zmmupdate_handle, const wchar_t* resourcename, wchar_t location[256]);

//////////////////////////////////////////////////////////////////////////

typedef struct {
    unsigned unused;
}*zmmupdate_heavy;

enum _ZMMUPDATE_DLHEAVY_ACTION {
    ZMMUPDATE_DLHEAVY_ACTION_RESUME = 1,
    ZMMUPDATE_DLHEAVY_ACTION_STOP,
    ZMMUPDATE_DLHEAVY_ACTION_PAUSE,
    ZMMUPDATE_DLHEAVY_ACTION_WAIT
};

typedef void(__cdecl *ZMMUPDATE_DLHEAVY_CALLBACK)(zmmupdate_heavy, void*, int);

ZMM_API zmmupdate_heavy __cdecl zmmupdate_download_heavy_new(const wchar_t* url, const wchar_t* dstfile, ZMMUPDATE_DLHEAVY_CALLBACK callback, void* callbackcontext);

ZMM_API void __cdecl zmmupdate_download_heavy_action(zmmupdate_heavy handle, int action);

ZMM_API bool __cdecl zmmupdate_check_md5(const wchar_t* filepath, const unsigned char* md5);

#ifdef __cplusplus
}
#endif

#endif
