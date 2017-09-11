// ***************************************************************
//  zmmcom   version:  1.0   -  date: 12/24/2015
//  -------------------------------------------------------------
//  Yongming Wang(wangym@gmail.com)
//  -------------------------------------------------------------
//  Copyright (C) 2010 - All Rights Reserved
// ***************************************************************
// 
// ***************************************************************
#pragma once

#include "zmmapi.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

	typedef struct _zmmcom_handle {
		int		unused;
	} *zmmcom_handle;

	typedef struct _zmmcom_addr {
		const char* addr;
		unsigned short port;
		unsigned char  translayer;
	} zmmcom_addr;

	enum _ZMMCOM_EVENT {
		ZMMCOM_EVENT_CONN = 1,    //network connect
		ZMMCOM_EVENT_DISCONN,
	};

	typedef enum _ZMMCOM_PROTO {
		ZMMCOM_PROTO_ZDP,
		ZMMCOM_PROTO_WHP,
        ZMMCOM_PROTO_GEP,
	}ZMMCOM_PROTO;

typedef void(*PFUN_ZMMCOM_EVENT_PROC)(zmmcom_handle hd, unsigned evt, void* param, void* ctx);

typedef void(*PFUN_ZMMCOM_DATAP_PROC)(zmmcom_handle hd, unsigned char* data, unsigned len, void* ctx, void* resctx);

zmmcom_handle ZMM_API zmmcom_new(PFUN_ZMMCOM_EVENT_PROC, PFUN_ZMMCOM_DATAP_PROC, void* ctx, ZMMCOM_PROTO v);

int ZMM_API zmmcom_connect(zmmcom_handle hd, zmmcom_addr* addrs, unsigned addrs_len);

//timeouit == 0: oneway send;
int ZMM_API zmmcom_send(zmmcom_handle hd, unsigned char* data, unsigned len, void* ctx, int restimeout);

int ZMM_API zmmcom_heartbeat(zmmcom_handle hd, unsigned char* data, unsigned len);

int ZMM_API zmmcom_close(zmmcom_handle hd);

int ZMM_API zmmcom_ptpinit(zmmcom_addr* addrs, unsigned addrs_len);

int ZMM_API zmmcom_ptpbind(unsigned id, unsigned short listenport, 
	const char* remoteip, unsigned short remoteport, const char* jsoncfg);

#ifdef __cplusplus
}
#endif /* __cplusplus */
