﻿#include "DbPreload.h"
#include "FileUtil.h"
namespace std
{
    DbPreload::DbPreload(const string & dir, bool autoStart) : running(true), thr(NULL), autoClose(true), autoStart(autoStart), loadNum(0)
    {
        thr = new std::thread(&DbPreload::run, this);
    };

    DbPreload::DbPreload(bool autoStart) :running(true), thr(NULL), autoClose(false), autoStart(autoStart), loadNum(0)
    {
        thr=new std::thread(&DbPreload::run, this); 
    }; 
    void DbPreload::start() {
        this->autoStart = true;
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
        preLoadDirs.push_back(dir);
    };
    void DbPreload::addPreLoadDb(const string & dir, const string & dbName)
    {
		Common::Array<DbFile> dbs = DbPreload::listDbFiles(dir, dbName);
		if (!dbs.empty()){
			PMutex m(this->m);
			for (int i = 0; i < dbs.size(); i++)
			{
				DbFile & dbf = dbs.at(i);
				if (this->dbNameMap.find(dbf.dbName) == this->dbNameMap.end())
				{
					loadDbFiles.push(dbf);
					DbFile * dbp = &loadDbFiles.at(loadDbFiles.size() - 1);
					this->dbNameMap.insert(DbFileMap::value_type(dbName, dbp));
				}
			}
		}
    };
	void DbPreload::addPreLoadDb(const string & ske, const string & tex, const string & dbName){
		addPreLoadDb(DbFile(ske, tex, dbName));
	};
	void  DbPreload::addPreLoadDb(const DbFile & dbf){
		PMutex m(this->m);
		if (this->dbNameMap.find(dbf.dbName) == this->dbNameMap.end())
		{
			loadDbFiles.push(dbf);
			DbFile * dbp = &loadDbFiles.at(loadDbFiles.size() - 1);
			this->dbNameMap.insert(DbFileMap::value_type(dbf.dbName, dbp));
		}
	}
	void DbPreload::addPreLoadDb(const Common::Array<DbFile> & dbs){
		PMutex m(this->m);
		for (int i = 0; i < dbs.size(); i++)
		{
			const DbFile & dbf = dbs.at(i);
			if (this->dbNameMap.find(dbf.dbName) == this->dbNameMap.end())
			{
				loadDbFiles.push(dbf);
				DbFile * dbp = &loadDbFiles.at(loadDbFiles.size() - 1);
				this->dbNameMap.insert(DbFileMap::value_type(dbf.dbName, dbp));
			}
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
        autoClose = true;
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
        int loadIdx = 0;
        while(running) 
        {
            if(!autoStart)
            {
                if(running)
                    Sleep(100);//0.1s
                continue;
            }
            FileUtils * fu = cocos2d::FileUtils::getInstance();
            const std::vector<std::string>& spath = fu->getSearchPaths();
            try
            {
                //Common::Array<string> preLoadDirs;
                //Common::Array<string> loadPath;
                //StringIntMap loadPathMap;
                //StringStringMap dbNameMap;
                string dirPath;
                {
                    PMutex m(this->m);
                    if(!preLoadDirs.empty())
                    {
                        dirPath = preLoadDirs.remove(0);
						if ((dirPath[0] != '/')){
							string _npath = "";
							string tdir = dirPath;
							dirPath = "";
							for (int i = 0; i < spath.size(); i++)
							{
								const string &sp = spath.at(i);
								if (sp[sp.size() - 1] == '/')
									_npath = spath.at(i) + tdir;
								else
									_npath = spath.at(i) + "/" + tdir;
                                 if(fu->isDirectoryExist(_npath))
                                {
									dirPath = _npath;
									break;;
								}
							} 
						}
                    }
                }
                if(dirPath.empty()){
                    if(running)
                        Sleep(100);//0.1s
                    continue;
                }
				if (dirPath[dirPath.size() - 1] != '/')
					dirPath = dirPath + "/";
                //扫描子文件夹
				Common::Array<DbFile> dbs=listDbFiles(dirPath);
				if (!dbs.empty()){
					addPreLoadDb(dbs);
				}
				Common::DirectoryInfo dir(dirPath);
                vector<string> subDirs = FileUtil::getAllFiles(dirPath, true, false, true);
				//Common::Array<Common::String>  subDirs = dir.GetDirectories("", false, Common::SearchOption::AllDirectories);
				if (!subDirs.empty()){
					for (int i = 0; i < subDirs.size(); i++)
					{
						string sbdir=subDirs.at(i);
						Common::Array<DbFile> sdbs = listDbFiles(sbdir);
						if (!sdbs.empty())	
                            addPreLoadDb(sdbs);
					}
				}
				if (this->autoClose){
					break;
				}
				int len = loadDbFiles.size();
                for(int i = loadIdx; i < len; i++)
				{
					loadDbData(loadDbFiles.at(i));
                    loadNum++;
				}
                loadIdx = len;
				if (this->autoClose)
					break;
            }
            catch(...)
            {
				if (running)
					Sleep(100);//0.1s
				continue;
            } 
        }
		running = false;
    };
	Common::Array<DbFile>  DbPreload::listDbFiles(const string & dir, const string & dbName){
		Common::Array<DbFile> res;
        vector<string> sfiles = FileUtil::getAllFiles(dir,  false,true, false);
        FileUtils * fu = cocos2d::FileUtils::getInstance();

		//Common::DirectoryInfo sdir(dir);
		//Common::Array<Common::String> sfiles =sdir.GetFiles();
		if (sfiles.empty())return res;
		map<string, string>  fileMap;
		for (int i = 0; i < sfiles.size(); i++)
		{
            string &file = sfiles.at(i);
			//Common::FileInfo f(file);
            Common::String fileName = FileUtil::getFileName(file);// f.getName();
			int idx = fileName.LastIndexOf("_");
            if(idx>0 && (fileName.EndsWith(".json") || fileName.EndsWith(".png") || fileName.EndsWith(".dbbin")))
            {
				Common::String dname=	fileName.SubString(0, idx);
				fileMap.insert(map<string, string>::value_type(file, dname));
			}
		}
        for(map<string, string>::iterator it = fileMap.begin(); it != fileMap.end(); it++)
        {
            Common::String file = it->first;
			if (file.EndsWith(".png") ){
				Common::String dname=fileMap.find(file)->second;
				Common::String texFile = dir + '/' + dname + "_tex.json";
                Common::String skeFile = dir + '/' + dname + "_ske.json";
				if (fileMap.find(texFile) != fileMap.end() && fileMap.find(skeFile) != fileMap.end()){
					res.push_back(DbFile(skeFile, texFile, dname));
				}
			}
		}
		if (!dbName.empty() && res.size() == 1){
			res.at(0).dbName = dbName;
		} 
		return res;
	};
 
	void DbPreload::loadDbData(DbFile & db){
		const auto factory = dragonBones::CCFactory::getFactory();
		if (!factory->getDragonBonesData(db.dbName))
		{
			factory->loadDragonBonesData(db.ske, db.dbName); 
			factory->loadTextureAtlasData(db.tex, db.dbName);
            this->dbNameMap[db.dbName]->state = 1;
		}
	};
    float DbPreload::getProgress() {
        double d = loadNum;
        double l = loadDbFiles.size();
        return d/l;
    };
}


