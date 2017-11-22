#pragma once

#ifdef WIN32
#   if defined ZMM_EXPORTS
#       define ZMM_API __declspec(dllexport)
#   elif defined ZMM_IMPORTS
#       define ZMM_API __declspec(dllimport)
#   else
#       define ZMM_API
#   endif
#else
#   define ZMM_API __attribute__ ((visibility ("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
    
    ZMM_API int  zmm_init();

	ZMM_API void zmm_fini();

    ZMM_API const char* zmm_machine(int idx);

    ZMM_API int zmm_encrypt(unsigned char* buffer, unsigned buf_len, const unsigned char* input, unsigned inputlen);

    ZMM_API int zmm_decrypt(unsigned char* buffer, unsigned buf_len, const unsigned char* input, unsigned inputlen);

#ifdef __cplusplus
}
#endif /* __cplusplus */
