// ***************************************************************
//  http_header   version:  1.0 - date: 07/13/2007
//  -------------------------------------------------------------
//  Yongming Wang(ymwang@iipc.zju.edu.cn)
//  The Institute of System Engineering, Zhejiang University
//  -------------------------------------------------------------
//  Copyright (C) 2002 - All Rights Reserved
// ***************************************************************
// 
// ***************************************************************
#pragma once
#ifndef __zce_http_stream__
#define __zce_http_stream__

#include <zce/zce_config.h>
#include <zce/zce_handler.h>
#include <zce/zce_smartptr.h>
#include <zce/text_stream.h>

#define HTTP_VERSION_BIND(x, y) (((x) << 16) | (y))
#define HTTP_VERSION_MAJOR(v)    (((v) >> 16) & 0x0000ffff)
#define HTTP_VERSION_MINOR(v)    ((v) & 0x0000ffff)

enum HTTP_CGI_E{
    HTTP_CGI_STANDARD,
    HTTP_CGI_UWSGI,
};

std::string ZCE_API http_urlencode(const std::string& str);

std::string ZCE_API http_urldecode(const std::string& str);

struct ZCE_API ZCE_HTTP_REQUEST
{
    enum HTTP_REQUEST_METHOD_E
    {
        HTTP_REQUEST_METHOD_UNKNOW,
        HTTP_REQUEST_METHOD_GET,
        HTTP_REQUEST_METHOD_POST,
        HTTP_REQUEST_METHOD_PUT,
        HTTP_REQUEST_METHOD_DELETE,
        HTTP_REQUEST_METHOD_OPTIONS,
        HTTP_REQUEST_METHOD_HEAD,
        HTTP_REQUEST_METHOD_TRACE,
        HTTP_REQUEST_METHOD_LIMIT
    };
    ZCE_HTTP_REQUEST() : method_(HTTP_REQUEST_METHOD_UNKNOW), version_(0) {};
    ZCE_HTTP_REQUEST(const std::string& url, HTTP_REQUEST_METHOD_E method, unsigned version = HTTP_VERSION_BIND(1, 1));

    std::string             url_;
    HTTP_REQUEST_METHOD_E   method_;
    unsigned                version_;
};

struct ZCE_API ZCE_HTTP_RESPONSE
{
    ZCE_HTTP_RESPONSE(){};
    ZCE_HTTP_RESPONSE(const std::string& str, unsigned code = 200, unsigned version = HTTP_VERSION_BIND(1, 1));
    unsigned        result_code_; 
    std::string        result_string_;
    unsigned        version_;
};

struct ZCE_API ZCE_HTTP_HEADER : public TEXT_HEADER
{
    ZCE_HTTP_REQUEST    request_;
    ZCE_HTTP_RESPONSE   response_;

private:
    unsigned    unpack_offset_;
    bool        unpack_finished_;

    int parse_first_line(const char* buf, int size);
    int parse_param(const char* buf, int size);

    int parse_request_uri(const char* buf, int size);
    int parse_status_code(const char* buf, int size);

    //int decode_uwsgi(const char* buf, int size);
public:
    ZCE_HTTP_HEADER();
    ZCE_HTTP_HEADER(TEXT_HEADER::TEXT_HEADER_E header_type);
    ZCE_HTTP_HEADER(const ZCE_HTTP_REQUEST& request);
    ZCE_HTTP_HEADER(const ZCE_HTTP_RESPONSE& request);
    bool is_unpack_finished() const { return unpack_finished_; }

    int  unpack(HTTP_CGI_E cgi, const zce_byte* buf, int size);
    int  pack(char* buf, int size)const;

    const std::string& get_x_forward_for() const;
};

class ZCE_API zce_http_stream : public zce_istream
{
    HTTP_CGI_E  cgi_;

    ZCE_HTTP_HEADER http_header_;

    std::string remote_ip_;

public:

    zce_http_stream(HTTP_CGI_E cgi = HTTP_CGI_STANDARD);

    virtual ~zce_http_stream();

    int  header_length()  const { return http_header_.header_length(); }
    int  body_length() { return http_header_.body_length(); }
    int  encode(char* buf, int size) const { return http_header_.pack(buf, size); }
    
    ZCE_HTTP_HEADER& header() { return http_header_; }
    void header(const ZCE_HTTP_HEADER& httpheader) { http_header_ = httpheader; }
    bool is_request()const    { return http_header_.header_type_ == TEXT_HEADER::TEXT_HEADER_REQUEST; }
    unsigned version()const { return (is_request() ? (http_header_.request_.version_) : (http_header_.response_.version_)); }

    const std::string& get_x_forward_for() const;

public:

    virtual void on_open(bool passive, const char* peerip, zce_uint16 peerport);

    virtual void on_read(zce_dblock& dblock, void*);

    virtual void on_http_data(const ZCE_HTTP_HEADER& header, const zce_dblock& dblock) = 0;

    void write_ack(unsigned code, zce_byte* buf, unsigned length);
};

#endif
