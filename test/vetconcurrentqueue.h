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
#include <stdio.h>

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
    void front(Object &obj);
    Object& back();
    void back(Object &obj);
    void clear();

private:
    std::queue<Object> queue_;
    int size_;
    pthread_mutex_t mutex_;
};

#define INCLUDE_VETCONCURRENTQUEUE_CPP
#include "vetconcurrentqueue.cpp"

#endif	// VETCONCURRENTQUEUE_H