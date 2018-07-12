#include "DbPreload.h"
namespace std
{
    DbPreload::DbPreload(const string & dir, bool autoClose) : running(false), thr(NULL), autoClose(autoClose)
    {
        thr = new std::thread(&DbPreload::run, this);
    };

    DbPreload::DbPreload() :running(false), thr(NULL), autoClose(false)
    {
        thr=new std::thread(&DbPreload::run, this); 
    };
    DbPreload::~DbPreload() 
    {
        close();
    };
    void DbPreload::setAutoClose()
    {
        autoClose = true;
    };

    //PMutex mutex;
    void DbPreload::addPreLoadDir(const string & dir)
    {
        //std::mutex mutex;//线程互斥对象   std::ref(n)引用传递参数
        PMutex m(this->m);
        for(int i = 0; i < preLoadDirs.size(); i++)
            preLoadDirs.push_back(dir);
    };
    void DbPreload::addPreLoadDb(const string & dir, const string & dbName)
    {
        PMutex m(this->m);
        if(this->dbNameMap.find(dbName) == this->dbNameMap.end())
            this->dbNameMap.insert(StringStringMap::value_type(dbName, dir));
        if(this->loadPathMap.find(dir) == this->loadPathMap.end())
        {
            loadPath.push(dir);
            this->loadPathMap.insert(StringIntMap::value_type(dir, 0));
        }
    };
    void DbPreload::detach()
    {
        thr->detach();
    };
    thread::id DbPreload::get_id()
    {
       return this->thr->get_id();
    };
    void DbPreload::join()
    {
        thr->join();
    };
    void DbPreload::close() {
        running = false;
        join();
    };
    bool DbPreload::isDetach()
    {
        return !this->thr->joinable();
    };
    bool DbPreload::isRunning()
    {
        return this->running;
    };
    void DbPreload::run()
    {
        while(running) 
        {
            try
            {
                Common::Array<string> preLoadDirs;
                Common::Array<string> loadPath;
                StringIntMap loadPathMap;
                StringStringMap dbNameMap;
                string dirPath;
                {
                    PMutex m(this->m);
                    if(!preLoadDirs.empty())
                    {
                        dirPath = preLoadDirs.remove(0);
                        dirPath = cocos2d::FileUtils::getInstance()->fullPathForFilename(dirPath);
                    }
                }
                if(dirPath.empty()){
                    if(running)
                        Sleep(100);//0.1s
                    continue;
                }
                //扫描子文件夹
                Common::DirectoryInfo dir(dirPath);
                Common::Array<Common::String>  subDirs=dir.GetDirectories();


            }
            catch(...)
            {

            } 
        
        }
    };
}


