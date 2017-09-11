// ***************************************************************
//  zce_reactor   version:  1.0     date: 07/31/2002
//  -------------------------------------------------------------
//  Yongming Wang(ymwang@iipc.zju.edu.cn)
//  The Institute of System Engineering, Zhejiang University
//  -------------------------------------------------------------
//  Copyright (C) 2002 - All Rights Reserved
// ***************************************************************
// 
// ***************************************************************
#ifndef __zce_reactor_h__
#define __zce_reactor_h__

#include <zce/zce_smartptr.h>
#include <deque>

class zce_thread;
class zce_allocator;
class zce_task;

class ZCE_API zce_reactor : virtual public zce_smartptr_mtbase
{
    struct pimpl;
    struct pimpl* pimpl_;

    friend class zce_reactor_thread;

public:

    zce_reactor();

    ~zce_reactor();

    unsigned long thread_id() const;
    
    void* loop_t() const;

    int start();

    void stop();

    int delegate_task(const zce_smartptr<zce_task>& task_ptr, int mstimeafter = 0);

    void delegate_work();

    void* alloc(unsigned size);

    void zfree(void*);
    //void trigger();

    virtual int on_start() { return 0; };

private:

    int loop();

    void terminate();
};

#endif //__zce_reactor_h__
