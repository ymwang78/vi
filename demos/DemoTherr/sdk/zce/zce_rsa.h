/* ***************************************************************
//  zce_rsa   version:  1.0  date: 2015/02/08/2/2015 
//  -------------------------------------------------------------
//  Yongming Wang(wangym@gmail.com)
//  -------------------------------------------------------------
//  Copyright (C) 2014 - All Rights Reserved
// ***************************************************************
// 
// **************************************************************/
#pragma once
#ifndef __zce_rsa_h__
#define __zce_rsa_h__

#include <zce/zce_config.h>

#ifdef __cplusplus
extern "C" {
#endif

    void ZCE_API zce_rsa_free(void*);

    int ZCE_API zce_rsa_genkey(void** pubkey, size_t* pubkeylen,
        void** prikey, size_t* prikeylen);

    int ZCE_API zce_rsa_prienc(const void* input, size_t inlen,
        void* prikey, size_t prikeylen,
        void** output, size_t* outlen);
    int ZCE_API zce_rsa_pridec(const void* input, size_t inlen,
        void* prikey, size_t prikeylen,
        void** output, size_t* outlen);
    int ZCE_API zce_rsa_pubenc(const void* input, size_t inlen,
        void* pubkey, size_t pubkeylen,
        void** output, size_t* outlen);
    int ZCE_API zce_rsa_pubdec(const void* input, size_t inlen,
        void* pubkey, size_t pubkeylen,
        void** output, size_t* outlen);

    int ZCE_API zce_rsa_prienc2(const void* input, size_t inlen,
        void* prikey, size_t prikeylen,
        void* output, size_t outlen);
    int ZCE_API zce_rsa_pridec2(const void* input, size_t inlen,
        void* prikey, size_t prikeylen,
        void* output, size_t outlen);
    int ZCE_API zce_rsa_pubenc2(const void* input, size_t inlen,
        void* pubkey, size_t pubkeylen,
        void* output, size_t outlen);
    int ZCE_API zce_rsa_pubdec2(const void* input, size_t inlen,
        void* pubkey, size_t pubkeylen,
        void* output, size_t outlen);

#ifdef __cplusplus
}
#endif

#endif // __zce_rsa_h__
