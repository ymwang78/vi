// ***************************************************************
//  zce_config   version:  1.0   -  date: 12/24/2015
//  -------------------------------------------------------------
//  Yongming Wang(wangym@gmail.com)
//  -------------------------------------------------------------
//  Copyright (C) 2010 - All Rights Reserved
// ***************************************************************
// 
// ***************************************************************
#pragma once

#ifdef _WIN32
#   define NOMINMAX
#   if defined(_DEBUG) && !defined(_UNICODE)
#        //include <vld.h>
#        define ZCE_ZDB_MYSQL 1
#        define ZCE_ZDB_PGSQL 0
#   endif
#   include <winsock2.h>
#   include <ws2tcpip.h>
#   include <stdio.h>
#   include <stdlib.h>
#   include <string>
#   define ZDP_GEP

#elif defined(__APPLE__)
#   include <unistd.h>
#   include <fcntl.h>
#   include <sys/socket.h>
#   include <sys/poll.h>
#   include <netinet/in.h>
#   include <netinet/tcp.h>
#   include <arpa/inet.h>
#   include <netdb.h>
#   include <memory.h>
#   include <sys/types.h>
#   include <sys/wait.h>
#   include <libkern/OSAtomic.h>
#   include "TargetConditionals.h"
#   if TARGET_IPHONE_SIMULATOR
#   elif TARGET_OS_IPHONE
#   elif TARGET_OS_MAC
#       include <CoreServices/CoreServices.h>
#   else
#   endif
#   define SOCKET int
#   define SOCKET_ERROR -1
#   define INVALID_SOCKET -1
#else
#   include <unistd.h>
#   include <fcntl.h>
#   include <sys/socket.h>
#   include <sys/poll.h>
#   include <netinet/in.h>
#   include <netinet/tcp.h>
#   include <arpa/inet.h>
#   include <netdb.h>
#   include <stdlib.h>
#   include <memory.h>
#   include <sys/types.h>
#   include <sys/wait.h>
#   include <pthread.h>
#   define SOCKET int
#   define SOCKET_ERROR -1
#   define INVALID_SOCKET -1
#   ifdef __ANDROID__
#       include <jni.h>
#       define HASNOT_UUID 1
#       define ZCE_API __attribute__ ((visibility ("default")))
#   else
#       define ZCE_ZDB_MYSQL 1
#   endif
#endif

#ifndef ZCE_API
#   define ZCE_API
#endif

#include <zce/zce_types.h>
#include <zce/zce_log.h>
#include <zce/zce_api.h>

#ifndef ZCE_OBJECT_NO_MONITOR
#   define ZCE_OBJECT_DECLARE              zce_object_proxy object_proxy_
#   define ZCE_OBJECT_IMPLEMENT(x)         ,object_proxy_(x##_object)
#   define ZCE_OBJECT_IMPLEMENT_EMPTY(x)   :object_proxy_(x##_object)
#   define ZCE_OBJECT_INSTANCE(x)          static zce_object x##_object(#x);
#else
#   define ZCE_OBJECT_DECLARE 
#   define ZCE_OBJECT_IMPLEMENT(x)
#   define ZCE_OBJECT_IMPLEMENT_EMPTY(x)
#   define ZCE_OBJECT_INSTANCE(x)
#endif

#ifdef _WIN32
#    define ZCE_PATH_SEPERATOR '\\'
#else
#    define ZCE_PATH_SEPERATOR '/'
#endif

enum ERV_ZCE_ERROR
{
    ZCE_ERROR_OK = 0,

    ZCE_ERROR_BASE = 0x81000000, //keep for stdc error

    ZCE_ERROR_COMMON = 0x81010000,
    ZCE_ERROR_MALLOC ,  //内存分配错误
    ZCE_ERROR_UNSUPPORT,//遇到未支持的功能要求
    ZCE_ERROR_SHRTLEN,  //数据比要求的太短
    ZCE_ERROR_EXCDLEN,  //数据比要求的太长
    ZCE_ERROR_CORRUPT,  //数据不一致
    ZCE_ERROR_SYNTAX,   //数据语义错误
    ZCE_ERROR_ZIP,      //压缩出错
    ZCE_ERROR_TIMEOUT,  //接收响应超时
    ZCE_ERROR_CONVERTOR,
    ZCE_ERROR_CLOSED,   //连接已经关闭
    ZCE_ERROR_TOCLOSE,  //连接将要关闭
    ZCE_ERROR_PREVNULL, //ISTEAM PREV NOT EXISTS

    ZCE_ERROR_UVBASE = 0x81020000,

    ZDB_ERROR_COMMON = 0x82010000,
    ZDB_ERROR_CONNECTION,
    ZDB_ERROR_SQLINVALID,
    ZDB_ERROR_COLUMNOVERLOW,
    ZDB_ERROR_BINDERROR,

    ZDB_ERROR_SQLITE_COMMON = 0x81010000, //以下错误代码对应SQLITE自身的错误代码
    ZDB_ERROR_MYSQL_COMMON = 0x81020000, //以下错误代码对应MYSQL自身的错误代码
};
