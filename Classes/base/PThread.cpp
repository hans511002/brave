#include "PThread.h"
namespace std
{
    PMutex::PMutex() :locked(false)
    {
        m.lock();
        this->locked = true;
    }

    PMutex::~PMutex()
    {
        m.unlock();
        this->locked = false;
    }

    void PMutex::lock() {
        m.lock();
        this->locked = true;
    };
    void PMutex::unlock() {
        m.unlock();
        this->locked = false;
    };
    bool PMutex::tryLock() {
        if(!this->locked)
        {
            this->lock();
            return this->locked;
        }
        else
        {
            return false;
        }
    };
    bool PMutex::isLocked() {
        return this->locked;
    };

}


