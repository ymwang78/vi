// ***************************************************************
//  zdb_mongo   version:  1.0   -  date: 12/1/2010
//  -------------------------------------------------------------
//  Yongming Wang(wangym@gmail.com)
//  -------------------------------------------------------------
//  Copyright (C) 2010 - All Rights Reserved
// ***************************************************************
// 
// ***************************************************************
#ifndef __zdb_mongo_h__
#define __zdb_mongo_h__

#include <zce/zce_task.h>
#undef max
#include <client/dbclient.h>

class ZCE_API zdb_mongo_connection : public zce_smartptr_mtbase, public mongo::DBClientConnection
{
    bool connection_ok_;
public:
    zdb_mongo_connection() {};
    zdb_mongo_connection(const  std::string& conn_str);
    bool connetion_ok();
    int get(const std::string& coll, const mongo::Query& query, mongo::BSONObj& obj);
};

class ZCE_API zdb_mongo_database
{
    std::string conn_str_;
    int cur_pos_;
    zce_tss tss_conn_;
public:
    zdb_mongo_database(const std::string& str);
    zce_smartptr<zdb_mongo_connection> get_connection();
};

int ZCE_API mongo_getIntField(const mongo::BSONObj& p, const char* field, int defaultval);

#define ZDB_MONGO_GETFILED(x) inline x zdb_mongo_getfiled(const mongo::BSONObj& p, const char* field, x defaultval = 0) { \
    return (x)p.getIntField(field, defaultval); \
}

ZDB_MONGO_GETFILED(zce_char);
ZDB_MONGO_GETFILED(zce_byte);
ZDB_MONGO_GETFILED(zce_int16);
ZDB_MONGO_GETFILED(zce_uint16);
ZDB_MONGO_GETFILED(zce_int32);
ZDB_MONGO_GETFILED(zce_uint32);

inline zce_int64 zdb_mongo_getfiled(const mongo::BSONObj& p, const char* field, zce_int64 defaultval = 0) {
        return p[field].numberLong(); 
}

inline zce_uint64 zdb_mongo_getfiled(const mongo::BSONObj& p, const char* field, zce_uint64 defaultval = 0) {
    return p[field].numberLong();
}

inline std::string zdb_mongo_getfiled(const mongo::BSONObj& p, const char* field, const std::string& defaultval = "") {
    return p.getStringField(field);
}

namespace Json {
    class Value;
}

void zdb_bson_to_json(Json::Value& jarray, mongo::BSONObj& args);

namespace zdp {
    struct _zbson_dummy {
    };
    static int zbson_unpack(_zbson_dummy& v , const mongo::BSONElement& _elem) {
        return -1;
    };
};

class zbson_mongo_unpack
{
public:

    template <typename T>
    inline int operator()(T& _v, const mongo::BSONElement& _elem) {
        return zdp::zbson_unpack(_v, _elem.Obj());
    }

    inline int operator()(zce_char& _v, const mongo::BSONElement& _elem) {
        _v = (zce_char)_elem.numberInt();
        return 0;
    }
    inline int operator()(zce_byte& _v, const mongo::BSONElement& _elem) {
        _v = (zce_byte)_elem.numberInt();
        return 0;
    }
    inline int operator()(zce_int16& _v, const mongo::BSONElement& _elem) {
        _v = (zce_int16)_elem.numberInt();
        return 0;
    }
    inline int operator()(zce_uint16& _v, const mongo::BSONElement& _elem) {
        _v = (zce_uint16)_elem.numberInt();
        return 0;
    }
    inline int operator()(zce_int32& _v, const mongo::BSONElement& _elem) {
        _v = (zce_int32)_elem.numberInt();
        return 0;
    }
    inline int operator()(zce_uint32& _v, const mongo::BSONElement& _elem) {
        _v = (zce_int32)_elem.numberInt();
        return 0;
    }
    inline int operator()(zce_int64& _v, const mongo::BSONElement& _elem) {
        _v = (zce_int64)_elem.numberLong();
        return 0;
    }
    inline int operator()(zce_uint64& _v, const mongo::BSONElement& _elem) {
        _v = (zce_uint64)_elem.numberLong();
        return 0;
    }
};

template <typename T>
inline int zdb_mongo_unpack(std::vector<T>& _arr, const mongo::BSONElement& _elem)
{
    if (_elem.type() != mongo::Array)
        return ZCE_ERROR_SYNTAX;
    auto _elem_array = _elem.Array();
    if (_elem_array.size() > 0)
        _arr.resize(_elem_array.size());
    for (unsigned i = 0; i < _elem_array.size(); ++i) {
        int ret = zbson_mongo_unpack()(_arr[i], _elem_array[i]);
        if (ret < 0)
            return ret;
    }
    return 0;
}

#endif // __zdb_mongo_h__
