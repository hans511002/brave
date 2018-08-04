
#ifndef STD_DBPRELOAD_H
#define STD_DBPRELOAD_H
#include "BaseNode.h"
using namespace std;

namespace std
{ 
 	struct DbFile
	{
		string ske;
		string tex;
		string dbName;
		int state;
		DbFile(string ske = "", string tex = "", string dbName = "") :state(0), ske(ske), tex(tex), dbName(dbName){};
	};
	typedef map<string, DbFile*> DbFileMap; 
	class DbPreload : public Ref
    {
	public:
		static  mutex dbloadMutex;
	protected:
		bool _startSch;

        Common::Array<string> preLoadDirs;
		Common::Array<DbFile *> loadDbFiles;
		//DbFileMap loadPathMap;
		DbFileMap dbNameMap;
        bool running;
        bool autoClose;
        bool autoStart;
        std::mutex m;
        std::thread *thr;
		int loadSkeNum;
		int loadTexNum;
        //std::thread::hardware_concurrency()
		Common::Array<DbFile> listDbFiles(const string & dir, const string & dbName="");
		void loadDbData(DbFile & dir);
		void addImageAsyncCallBack(float dt);
	public:
        DbPreload(const string & dir, bool autoStart = true);
        DbPreload(bool autoStart = true);
        ~DbPreload();
        //PMutex mutex;
        virtual void addPreLoadDir(const string & dir);
		virtual void addPreLoadDb(const string & dir, const string & dbName);
		virtual void addPreLoadDb(const string & ske, const string & tex, const string & dbName);
		virtual void addPreLoadDb(const DbFile & db);
		virtual void addPreLoadDb(const Common::Array<DbFile> & dbs);
		virtual void startSch();
		virtual bool isStartSch();

		virtual void setAutoClose();
        virtual void start();
        virtual void join();
        virtual thread::id get_id();
        virtual void detach();
        virtual bool isDetach();
        virtual bool isRunning();
        virtual void close();
        virtual void run();
        virtual float getProgress();
    };

}

#endif
