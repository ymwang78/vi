#pragma once
// ***************************************************************
//  zce_timer   version:  1.0   -  date: 11/26/2015
//  -------------------------------------------------------------
//  Yongming Wang(wangym@gmail.com)
//  -------------------------------------------------------------
//  Copyright (C) 2010 - All Rights Reserved
// ***************************************************************
// 
// ***************************************************************
#include <zce/zce_config.h>
#include <zce/zce_smartptr.h>

class zce_reactor;
class zce_task_queue;

class ZCE_API zce_timer_doozer : virtual public zce_smartptr_mtbase
{
public:
    virtual void handle_timeout(const void* arg) = 0;
};

class ZCE_API zce_timer : public zce_smartptr_mtbase
{
    struct pimpl;
    struct pimpl *pimpl_;

    class zce_timer_delegate;
    class zce_timer_handler;

    void do_delegate(bool bstart);

public:
    zce_timer(const zce_smartptr<zce_reactor>& reactor, 
        const zce_smartptr<zce_timer_doozer>& doozerptr, 
        unsigned msecond, 
        bool repeat = true, 
        const void* arg = 0);

    ~zce_timer();

    void set_queue(const zce_smartptr<zce_task_queue>&);

    void start();

    void cancel();

    void handle_timeout();

    void on_close();
};


template<typename _t>
class zce_timer_tpl : public zce_timer_doozer
{
public:
    zce_timer_tpl(_t* p) : p_(p) {
    }
public:
    void handle_timeout(const void *arg) {
        p_->handle_timeout(arg);
    }
private:
    _t*    p_;
};
