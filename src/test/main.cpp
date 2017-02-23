//============================================================================
// Name        : testPthread.cpp
// Author      : nohack
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
using namespace std;

pthread_key_t key;
pthread_mutex_t mutex;
pthread_cond_t cond;

void * Test01(void *ptr)
{
	int a = 100;
	pthread_cleanup_push(pthread_mutex_unlock, &mutex);
	while(a > 0)
	{
		usleep(3);
		pthread_mutex_lock(&mutex);
		printf("1111mutex_lock\n");
		pthread_cond_wait(&cond, &mutex);
		printf("1111cond_wait\n");
		pthread_mutex_unlock(&mutex);
		a--;
	}
	pthread_cleanup_pop(0);
	return NULL;
}

void* Test02(void* ptr)
{
	int b = 120;
    while(b > 0)
    {
        usleep(2);
        pthread_mutex_lock(&mutex);
        printf("2222mutex_lock\n");
        pthread_cond_wait(&cond, &mutex);
        printf("2222cond_wait\n");
        pthread_mutex_unlock(&mutex);
        usleep(2);
        b--;
    }

    return NULL;
}

int main() {
	pthread_t tid1, tid2;
    int ret;
    void *status1,*status2;
    //pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&mutex, NULL);
    printf("Start:\n");
    ret = pthread_create(&tid1, NULL, Test01, NULL);
    ret = pthread_create(&tid2, NULL, Test02, NULL);
    printf("ret = 0x%x\n", ret);

    usleep(4);
    pthread_cancel(tid1);

    do
    {
    	usleep(4);
        pthread_cond_signal(&cond);
    } while(1);
    printf("end.\n");

    pthread_join(tid1,&status1);
    pthread_join(tid2,&status2);
    return 0;
}
