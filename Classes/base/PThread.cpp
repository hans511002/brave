#include "PThread.h"
namespace std
{
	PMutex::PMutex(std::mutex * m, bool locked) :locked(locked), m(m)
	{
		if (locked)
			this->locked = m->try_lock();
	}

    PMutex::~PMutex()
    {
        if(this->locked)
			m->unlock();
        this->locked = false;
    }

    void PMutex::lock() {
        m->lock();
        this->locked = true;
    };
    void PMutex::unlock() {
        if(this->locked )
			m->unlock();
        this->locked = false;
    };
    bool PMutex::tryLock() {
        if(!this->locked)
        {
			this->locked=m->try_lock();
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


