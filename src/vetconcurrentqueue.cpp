/**
* [
*  Copyright (c) 2016 by Vehicle-Eye Technology
*  ALL RIGHTS RESERVED.
*
*  The software and information contained herein are proprietary to,  and comprise
*  valuable trade secrets of, Vehicle-Eye Technology.  Disclosure of the software
*  and information will materially harm the business of Vehicle-Eye Technology.
*  This software is furnished pursuant to a written development agreement and may
*  be used, copied, transmitted, and stored only in accordance with the terms of
*  such agreement and with the inclusion of the above copyright notice.  This
*  software and information or any other copies thereof may not be provided or
*  otherwise made available to any other party.
* ]
*/


/*!
* \file vetconcurrentqueue.cpp
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2016-02-22
*/

#ifdef INCLUDE_VETCONCURRENTQUEUE_CPP

#include "vetconcurrentqueue.h"

template <typename Object>
VetConcurrentQueue<Object>::VetConcurrentQueue()
{
    pthread_mutex_init(&mutex_, NULL);
    size_ = 0;
}

template <typename Object>
VetConcurrentQueue<Object>::~VetConcurrentQueue()
{
    pthread_mutex_destroy(&mutex_);
}

template <typename Object>
bool VetConcurrentQueue<Object>::empty()
{
    bool ret;
    
    pthread_mutex_lock(&mutex_);

    ret = (size_ == 0 ? true : false);

    pthread_mutex_unlock(&mutex_);

    return ret;
}

template <typename Object>
void VetConcurrentQueue<Object>::push(const Object &obj)
{
    pthread_mutex_lock(&mutex_);

    queue_.push(obj);
    size_++;

    pthread_mutex_unlock(&mutex_);
}

template <typename Object>
void VetConcurrentQueue<Object>::pop()
{
    pthread_mutex_lock(&mutex_);

    queue_.pop();
    size_--;

    pthread_mutex_unlock(&mutex_);
}

template <typename Object>
int VetConcurrentQueue<Object>::size()
{
    int cur_size;

    pthread_mutex_lock(&mutex_);

    cur_size = size_;

    pthread_mutex_unlock(&mutex_);

    return cur_size;
}

template <typename Object>
Object& VetConcurrentQueue<Object>::front()
{
    pthread_mutex_lock(&mutex_);

    Object &obj = queue_.front();

    pthread_mutex_unlock(&mutex_);
    return obj;
}

template <typename Object>
void VetConcurrentQueue<Object>::front(Object &obj)
{
    pthread_mutex_lock(&mutex_);

    obj = queue_.front();

    pthread_mutex_unlock(&mutex_);
}

template <typename Object>
Object& VetConcurrentQueue<Object>::back()
{
    pthread_mutex_lock(&mutex_);

    Object &obj = queue_.back();

    pthread_mutex_unlock(&mutex_);
    return obj;
}

template <typename Object>
void VetConcurrentQueue<Object>::back(Object &obj)
{
    pthread_mutex_lock(&mutex_);

    obj = queue_.back();

    pthread_mutex_unlock(&mutex_);
}

template <typename Object>
void VetConcurrentQueue<Object>::clear()
{
    pthread_mutex_lock(&mutex_);

    while ( !queue_.empty() ){
        queue_.pop();
    }

   	size_ = 0;
    
    pthread_mutex_unlock(&mutex_);
}

#endif