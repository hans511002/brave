
#ifndef STD_PTHREAD_H
#define STD_PTHREAD_H
#include "cocos2d.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>
namespace std
{


//thread::detach()
//std::mutex mutex;//线程互斥对象  
//std::thread t1(&HelloWorld::myThread, this, 10, 20);//创建一个分支线程，回调到myThread函数里   
//t1.join();
//
//mutex.lock();//加锁   
//mutex.unlock();

class PMutex
{
    std::mutex &m;
    bool locked;
public:
    PMutex(std::mutex & m);
    ~PMutex();
    void lock();
    void unlock();
    bool tryLock();
    bool isLocked();
};

}

#endif
