// ***************************************************************
//  zdb_redis   version:  1.0   -  date: 9/25/2015
//  -------------------------------------------------------------
//  Yongming Wang(wym@zhidu.biz)
//  Zhidu Network Co. Ltd.
//  -------------------------------------------------------------
//  Copyright (C) 2015 - All Rights Reserved
// ***************************************************************
// 
// ***************************************************************
#ifndef __zdb_redis_h__
#define __zdb_redis_h__

#include <zce/zce_config.h>
#include <zce/zce_task.h>
#include <zce/zce_types.h>
#include <zce/zce_dblock.h>
#include <map>

struct redisContext;
class zdb_redis_ptr;

class ZCE_API zdb_redis_connection : public zce_smartptr_mtbase
{
    redisContext* context_;

    bool connection_ok_;

    int get_retval_i64(zce_int64& v, const zdb_redis_ptr& r);

public:

    zdb_redis_connection();

    zdb_redis_connection(const std::string& ip, unsigned short port, const char* passwd);

    bool connetion_ok() const {
        return connection_ok_;
    };

    void close();

    redisContext* context() { return context_; }

    int hget(const std::string& k, const std::string& h, zce_int64& v);

    int hgetall(const std::string& k, std::map<std::string, std::string>&);

    int hgetall(const std::string& k, std::map<zce_int64, std::string>&);

    int hdel(const std::string& k, const std::string& h);

    int hset(const std::string& k, const std::string& h, zce_int64 v, zce_uint32 expiresec);

    int hset(const std::string& k, zce_int64 h, const zce_byte* v, unsigned l, zce_uint32 expiresec);

    int hinc(const std::string& k, const std::string& h, zce_int64 v, zce_uint32 expiresec, zce_int64* outv = 0);

    int set(const std::string& k, zce_int64 v, zce_uint32 expiresec);

    int set(const std::string& k, const std::string& v, zce_uint32 expiresec);

    int set(const std::string& k, const zce_byte* v, unsigned l, zce_uint32 expiresec);

    int get(const std::string& k, zce_int64& v);

    int get(const std::string& k, std::string& v);

    int get(const std::string& k, zce_dblock& v);

    int del(const std::string& k);

    int inc(const std::string& k, zce_int64 val = 1, zce_int64 expiresec = 0, zce_int64* outv = 0);

    int zinc(const std::string& k, const std::string& m, zce_int64 val = 1, zce_int64 expiresec = 0, zce_int64* outv = 0);

    int zset(const std::string& k, const std::string& m, zce_int64 val, zce_int64 expiresec = 0);

    int zdel(const std::string& k, const std::string& m);

    int expire(const std::string& k, zce_int64 expiresec);
};

class ZCE_API zdb_redis_databse : public zce_smartptr_mtbase
{
    std::string ip_;
    unsigned short port_;
    std::string passwd_;
    zce_tss tss_conn_;
public:
    zdb_redis_databse(const std::string& ip, unsigned short port, const char* passwd);
    zce_smartptr<zdb_redis_connection> get_connection();
};

struct redisReply;

class ZCE_API zdb_redis_ptr
{
    redisReply* reply_;

public:

    zdb_redis_ptr(redisReply* r = 0)
        :reply_(r) {
    }

    zdb_redis_ptr& operator = (redisReply* r);

    ~zdb_redis_ptr();

    inline operator redisReply*() const {
        return this->reply_;
    }

    inline redisReply* operator->() const {
        return this->reply_;
    }

    inline bool operator == (redisReply* right) const {
        return (this->reply_ == right);
    }

    inline bool operator != (redisReply* right) const {
        return !(this->reply_ == right);
    }
};

#endif // __zdb_redis_h__
