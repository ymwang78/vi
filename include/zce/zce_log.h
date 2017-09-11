#ifndef __zce_log_h__
#define __zce_log_h__

#include <stdarg.h>

#ifndef _WIN32
#define __cdecl 
#endif

#ifdef __cplusplus
extern "C" {
#endif

enum _zlog_level
{
    ZLOG_TRACE = 0,
    ZLOG_DEBUG = 1,            /* debug */
    ZLOG_INFOR = 2,            /* info */
    ZLOG_WARNI = 3,            /* warn */
    ZLOG_ERROR = 4,            /* error */
    ZLOG_FATAL = 5,            /* fatal */
    ZLOG_NONEL = 255,        /* none */
};

typedef struct zlog_param {
    const char* name;
    int max_filesize;
    const char* logpath;
}zlog_param;

typedef struct _zlog_handle {
    int unused;
}*zlog_handle;

zlog_handle __cdecl zlog_init(zlog_handle sharehandle, zlog_param* param);

void __cdecl        zlog_fini();

void __cdecl        zlog_setlevel(unsigned level);

unsigned __cdecl    zlog_getlevel();

int __cdecl         zlog_snprintf(char* buffer, unsigned size, unsigned level, const char* funcname, const char* filename, int linenumber, const char* fmt, ...);

int __cdecl         zlog_vsnprintf(char* buffer, unsigned size, unsigned level, const char* funcname, const char* filename, int linenumber, const char* fmt, va_list argptr);

void __cdecl        zlog_logv(unsigned level, const char* funcname, const char* filename, int linenumber, const char* fmt, ...);

void __cdecl        zlog_vlog(unsigned level, const char* funcname, const char* filename, int linenumber, const char* fmt, va_list argptr);

#ifdef _WIN32
#   define ZLOG(lv, fn, ...)            do { if(zlog_getlevel() <= (lv)) zlog_logv((lv), __FUNCTION__, __FILE__, __LINE__, (fn), __VA_ARGS__); } while (0)
#   define ZLOG_SYSCALL(lv, s)          ZLOG((lv), "%s: os error: %d", (s), GetLastError())
#   define ZLOG_CEXCEPTION(lv, s, c)    ZLOG((lv), "%s: seh, code = 0x%08x", (s), (c))
#else
#   define ZLOG(lv, fn, ...)            do { if(zlog_getlevel() <= (lv)) zlog_logv((lv), __FUNCTION__, __FILE__, __LINE__, (fn), ##__VA_ARGS__); } while (0)
#   define ZLOG_SYSCALL(lv, s)          ZLOG((lv), "%s: os errno: %d", (s), errno)
#endif

#define ZCE_TRACE                       ZCE_DEBUG((ZLOG_TRACE, "{%s:%d} (tick:%lld)", __FILE__, __LINE__, zce_tick()))
#define ZCE_ASSERT(X)                   do{ if(!(X)) ZLOG(ZLOG_FATAL, "{%s:%d} assertion failed for '%s'", __FILE__, __LINE__, (#X)); } while(0)
#define ZCE_ASSERT_TEXT(X, Y)           do{ if(!(X)) ZLOG(ZLOG_FATAL, "{%s:%d} assertion failed for '%s'", __FILE__, __LINE__, (Y)); } while(0)
#define ZCE_ASSERT_RETURN(X, Y)         do{ if(!(X)) { ZLOG(ZLOG_FATAL, "{%s:%d} assertion failed for '%s'", __FILE__, __LINE__, (#X)); return Y; } } while(0)

//#   define ZCE_ASSERT(X)                do{ if(!(X)) zlog_logv(ZLOG_FATAL, __PRETTY_FUNCTION__, __FILE__, __LINE__, "assertion failed for '%s'.\n", (#X)); } while(0)

#define ZCE_DEBUG(X)                    ZLOG X
#define ZCE_ERROR(X)                    ZLOG X

#define ZLOG_ICEEXCEPTION(lv, ex, s)    ZLOG((lv), "%s: ice exception: name = %s, file = %s, line = %d", (s), ex.ice_name().c_str(), ex.ice_file(), ex.ice_line())
#define ZLOG_CPPEXCEPTION(lv, s)        ZLOG((lv), "%s: unknown exception", (s))

#ifdef __cplusplus
}
#endif

#endif
