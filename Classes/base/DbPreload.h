
#ifndef STD_DBPRELOAD_H
#define STD_DBPRELOAD_H
#include "BaseNode.h"
using namespace std;

namespace std
{ 
    typedef map<string, bool> StringBoolMap;
    typedef map<string, int> StringIntMap;
    typedef map<string, string> StringStringMap;
    class DbPreload
    {
    protected:
        Common::Array<string> preLoadDirs;
        Common::Array<string> loadPath;
        StringIntMap loadPathMap;
        StringStringMap dbNameMap;
        bool running;
        bool autoClose;
        std::mutex m;
        std::thread *thr;
        //std::thread::hardware_concurrency()
    public:
        DbPreload(const string & dir,bool autoClose=false);
        DbPreload();
        ~DbPreload();
        //PMutex mutex;
        virtual void addPreLoadDir(const string & dir);
        virtual void addPreLoadDb(const string & dir, const string & dbName);
        virtual void setAutoClose();
        virtual void join();
        virtual thread::id get_id();
        virtual void detach();
        virtual bool isDetach();
        virtual bool isRunning();
        virtual void close();
        virtual void run();
    };

}

#endif
