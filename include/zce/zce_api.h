/* ***************************************************************
//  zce_api   version:  1.0  date: 23/23/2009
//  -------------------------------------------------------------
//  Yongming Wang(wangym@gmail.com)
//  -------------------------------------------------------------
//  Copyright (C) 2009 - All Rights Reserved
// ***************************************************************
// 
// **************************************************************/
#ifndef __zce_api_h__
#define __zce_api_h__

#include <zce/zce_config.h>
#include <zce/zce_types.h>
#include <vector>
#include <stdarg.h>
#include <sstream>

#ifdef __cplusplus
extern "C"
{
#endif
    typedef union _zce_sockaddr_t zce_sockaddr_t;

    int ZCE_API zce_init();

    void ZCE_API zce_fini();

    struct tm * ZCE_API zce_localtime_r(const time_t *t, struct tm *res);

    unsigned long long ZCE_API zce_tick();

    unsigned long long ZCE_API zce_nowms();

    unsigned long long ZCE_API zce_atoi64(const char* str);

    unsigned  ZCE_API zce_thread_id();

    void ZCE_API zce_oom_adjust(int adjust);

    void ZCE_API zce_to_hex(char* out, unsigned out_size, const char* in, unsigned in_size, bool upper = false);

    int ZCE_API zce_from_hex(char* out, unsigned out_size, const char* in, unsigned in_size);

    int ZCE_API zce_base64_decode(const unsigned char* input, size_t inputlen, unsigned char* result);

    int ZCE_API zce_base64_encode(unsigned char* buffer, const unsigned char* input, size_t input_len);
    
    size_t ZCE_API zce_base64_length(const char* input);

    bool ZCE_API zce_interrupted();

    void ZCE_API zce_enable_coredump(bool enable);

    void ZCE_API zce_msleep(int msec);

    unsigned ZCE_API zce_getmem();

    unsigned ZCE_API zce_getcpu();

    enum ERV_ZCE_COMPRESS {
        ZCE_COMPRESS_NONE,
        ZCE_COMPRESS_BZIP2,
		ZCE_COMPRESS_CLEAN,
    };

    //out_size should be large enough
    int ZCE_API zce_compress(ERV_ZCE_COMPRESS cps, char* out_buf, size_t& out_size, const char* in_buf, size_t in_size);
    int ZCE_API zce_decompress(ERV_ZCE_COMPRESS cps, char* out_buf, size_t& out_size, const char* in_buf, size_t in_size);

    int ZCE_API zce_inet_ntop4(const unsigned char* src, char* dst, size_t size);
    int ZCE_API zce_inet_ntop6(const unsigned char* src, char* dst, size_t size);
    const char* ZCE_API zce_inet_ntop(int af, const void* src, char* dst, size_t size);

    int ZCE_API zce_inet_pton4(const char* src, unsigned char* dst);
    int ZCE_API zce_inet_pton6(const char* src, unsigned char* dst);
    int ZCE_API zce_inet_pton(int af, const char* src, void* dst);

    int ZCE_API zce_inet_aton(zce_sockaddr_t*, const char* addr, int port);
    int ZCE_API zce_inet_ntoa(char* ip, unsigned len, const zce_sockaddr_t* addr, bool bport);

    #if defined(_WIN32)
        int zce_getmac(char mac[20]);
    #endif //defined(_WIN32) && (_WIN32_WINNT < 0x0600)

#ifdef __cplusplus
}
#endif

int ZCE_API zce_create_pipe(SOCKET fds[2]);

int ZCE_API zce_symbol_read(const char* buf, int size, std::string& val, char split = ' ');

int ZCE_API zce_symbol_read_linefeed(const char* buf, int size, std::string& val);

std::string ZCE_API zce_to_hex(const unsigned char* p, unsigned size);

std::vector<unsigned char> ZCE_API zce_from_hex(const std::string& in);

std::string ZCE_API zce_md5sum(const char* fname);

std::string ZCE_API zce_md5_encode(const char* input, size_t inputlen, unsigned char binout[16]);

std::string ZCE_API zce_string_format(unsigned length, const char* format, ...);

std::string ZCE_API zce_trim(const std::string& str,
	const std::string& whitespace = " \t");

std::string ZCE_API zce_get_path(const char* filename);

bool ZCE_API zce_makedir(const char* dir);

int ZCE_API zce_list_ip(std::vector<std::string>& ip_list);

template<typename T>
inline T zce_min(T v1, T v2) 
{
    return (v1 < v2) ? v1 : v2;
}

template<typename T>
inline T zce_max(T v1, T v2)
{
    return (v1 > v2) ? v1 : v2;
}

template<typename T>
inline T zce_abs(const T& iValue)
{
    return iValue > 0 ? iValue : -iValue;
}

template<typename T>
inline T zce_sum(const std::vector<T>& iVec)
{
    T v = 0;
    for (auto iter = iVec.begin(); iter != iVec.end(); ++iter) {
        v += *iter;
    }
    return v;
}

#ifdef _WIN32

HRESULT zce_createinstance(const wchar_t* dllname, REFCLSID rclsid, REFIID riid, LPVOID* ppv);

std::string zce_to_utf8(const wchar_t* src, unsigned len);

std::wstring zce_to_utf16(const char* src, unsigned len);

#endif

template<typename T>
static inline T zce_counter(zce_uint32 spanid, zce_uint32& lastspanid, T& count)
{
    if (spanid == lastspanid) {
        ++count;
        return 0;
    }
    else {
        T v = count;
        count = 0;
        lastspanid = spanid;
        return v;
    }
}

#endif // __zce_api_h__
