// ***************************************************************
//  zce_task_queue   version:  1.0   -  date: 11/15/2015
//  -------------------------------------------------------------
//  Yongming Wang(wangym@gmail.com)
//  -------------------------------------------------------------
//  Copyright (C) 2010 - All Rights Reserved
// ***************************************************************
// 
// ***************************************************************
#pragma once
#ifndef __zce_task_queue_h__
#define __zce_task_queue_h__

#include <zce/zce_config.h>
#include <zce/zce_smartptr.h>
#include <zce/zce_task.h>
#include <deque>

class zce_schedule;

class ZCE_API zce_task_queue : public zce_task
{
    zce_smartptr<zce_schedule> schedule_ptr_;

    zce_smartptr<zce_task_queue> proxy_ptr_;

    std::deque<zce_smartptr<zce_task> > deque_;

    zce_mutex task_lock_;

    bool paused_;

public:

    zce_task_queue(const zce_smartptr<zce_schedule>& schedule_ptr);

    int enqueue(const zce_smartptr<zce_task>& req);

    virtual void call();
};

#endif // __zce_task_queue_h__
