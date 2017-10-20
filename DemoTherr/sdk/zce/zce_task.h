// ***************************************************************
//  zce_task   version:  1.0   -  date: 4/27/2012
//  -------------------------------------------------------------
//  Yongming Wang(wangym@gmail.com)
//  -------------------------------------------------------------
//  Copyright (C) 2010 - All Rights Reserved
// ***************************************************************
// 
// ***************************************************************
#ifndef __zce_task_h__
#define __zce_task_h__

#include <zce/zce_config.h>
#include <zce/zce_smartptr.h>
#include <deque>

typedef struct _JavaVM JavaVM;
typedef struct _JNIEnv JNIEnv;

class ZCE_API zce_task : virtual public zce_smartptr_mtbase
{
public:
    const char* const task_name_;

    zce_task(const char* const name)
        : task_name_(name) {
    };

    virtual void call() = 0;
};

typedef zce_smartptr<zce_task> zce_task_ptr;

class ZCE_API zce_tss : virtual public zce_smartptr_mtbase
{
    struct pimpl;
    struct pimpl* pimpl_;

public:

    zce_tss();

    ~zce_tss();

    zce_smartptr_mtbase* ts_object(zce_smartptr_mtbase* ptr);

    zce_smartptr_mtbase* ts_object();

public:
    struct global_t : public zce_smartptr_mtbase {
        static JavaVM* jvm_;
        JNIEnv* env_;
        void* spec_;

        global_t() : env_(0), spec_(0) {

        }
    };
    static global_t* get_global();
};

class ZCE_API zce_schedule : public zce_smartptr_mtbase
{
    class zce_worker;

    struct pimpl;
    struct pimpl *pimpl_;

    void do_work();

public:
    zce_schedule();

    ~zce_schedule();

    int active(int work_thread_cnt);

    void stop();

    int perform(const zce_smartptr<zce_task>& req);
};

#include <zce/zce_singleton.h>

typedef zce_singleton<zce_schedule> zce_schedule_sigt;

//////////////////////////////////////////////////////////////////////////

template <typename H, typename T0, typename T1, typename T2>
class zce_delegate_task : public zce_task
{
    zce_smartptr<H> host_ptr_;
    T0 t0_;
    T1 t1_;
    T2 t2_;

public:
    zce_delegate_task(H* h, const T0& t0, const T1& t1, const T2& t2)
        :zce_task("zce_delegate_task"),
        host_ptr_(h), t0_(t0), t1_(t1), t2_(t2) {

    }

    virtual void call() {
        if (host_ptr_) {
            host_ptr_->do_delegate(t0_, t1_, t2_);
        }
    }
};

#endif
