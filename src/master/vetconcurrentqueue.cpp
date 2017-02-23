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
    int cur_size;
    
    pthread_mutex_lock(&mutex_);

    cur_size = size_;

    pthread_mutex_unlock(&mutex_);

    if(cur_size == 0)
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