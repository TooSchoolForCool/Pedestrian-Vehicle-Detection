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
* \file concurrentqueue.cpp
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2016-02-22
*/

#include "vetconcurrentqueue.h"

#include <iostream>
#include <queue>

#include <pthread.h>

using namespace std;

template <class Object>
VetConcurrentQueue<Object>::VetConcurrentQueue()
{
    pthread_mutex_init(&mutex_, NULL);
    size_ = 0;
}

template <class Object>
VetConcurrentQueue<Object>::~VetConcurrentQueue()
{
    pthread_mutex_destroy(&mutex_);
}

template <class Object>
bool VetConcurrentQueue<Object>::isEmpty() const
{
    if(size_ == 0)
        return true;
    else
        return false;
}

template <class Object>
void VetConcurrentQueue<Object>::push(const Object &obj)
{
    pthread_mutex_lock(&mutex_);

    queue_.push(obj);
    size_ = queue_.size();

    pthread_mutex_unlock(&mutex_);
}

template <class Object>
void VetConcurrentQueue<Object>::pop()
{
    pthread_mutex_lock(&mutex_);

    queue_.pop();
    size_ = queue_.size();

    pthread_mutex_unlock(&mutex_);
}

template <class Object>
int VetConcurrentQueue<Object>::size() const
{
    return(size_);
}

template <class Object>
Object& VetConcurrentQueue<Object>::front()
{
    pthread_mutex_lock(&mutex_);

    Object &obj = queue_.front();

    pthread_mutex_unlock(&mutex_);
    return obj;
}

template <class Object>
Object& VetConcurrentQueue<Object>::back()
{
    pthread_mutex_lock(&mutex_);

    Object &obj = queue_.back();

    pthread_mutex_unlock(&mutex_);
    return obj;
}

template <class Object>
void VetConcurrentQueue<Object>::clear()
{
    pthread_mutex_lock(&mutex_);

    while (!queue_.empty()){
      queue_.pop();
    }

   	size_ = 0;
    
    pthread_mutex_unlock(&mutex_);
}