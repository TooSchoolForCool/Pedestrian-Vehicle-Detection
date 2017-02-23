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
* \file vetconcurrentqueue.h
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2016-02-22
*/

#ifndef VETCONCURRENTQUEUE_H 	// VETCONCURRENTQUEUE_H
#define VETCONCURRENTQUEUE_H 	// VETCONCURRENTQUEUE_H

#include <pthread.h>
#include <iostream>
#include <queue>

template <typename Object>
class VetConcurrentQueue 
{
public:
    VetConcurrentQueue();
    ~VetConcurrentQueue();

public:
    bool empty();
    void push(const Object &obj);
    void pop();
    int size();
    Object& front();
    Object& back();
    void clear();

private:
    std::queue<Object> queue_;
    int size_;
    pthread_mutex_t mutex_;
};

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
    if(size_ == 0)
        return true;
    else
        return false;
}

template <typename Object>
void VetConcurrentQueue<Object>::push(const Object &obj)
{
    pthread_mutex_lock(&mutex_);

    queue_.push(obj);
    size_ = queue_.size();

    pthread_mutex_unlock(&mutex_);
}

template <typename Object>
void VetConcurrentQueue<Object>::pop()
{
    pthread_mutex_lock(&mutex_);

    queue_.pop();
    size_ = queue_.size();

    pthread_mutex_unlock(&mutex_);
}

template <typename Object>
int VetConcurrentQueue<Object>::size()
{
    return size_;
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
Object& VetConcurrentQueue<Object>::back()
{
    pthread_mutex_lock(&mutex_);

    Object &obj = queue_.back();

    pthread_mutex_unlock(&mutex_);
    return obj;
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

#endif	// VETCONCURRENTQUEUE_H