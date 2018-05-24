// ==============================================================
//progame      Common::Log write message to file
//company      hans
//copyright    Copyright (c) hans  2007-4     2008-03
//version      1.0
//Author       hans
//date         2007-4     2008-03
//description  Common namespace
//				This library is free software. Permission to use, copy,
//				modify and redistribute it for any purpose is hereby granted
//				without fee, provided that the above copyright notice appear
//				in all copies.
// ==============================================================

#ifndef __Common_Log_H__
#define __Common_Log_H__
//#include "Common.h"
namespace Common
{
	class DbLog
	{
	public:
		static void * _con ;//	配置数据库连接对象
		static void * _rs;
		static bool writeDbLogFlag;
		static String dbLogTable;
		static String dbConnStr;
		static String sql;
		static void writeDbLog(String & msg,Log *log,bool isDebug,int type);
	};
	///	<summary>
	///	日志对象,写文本日志
	///	</summary>
	///	<remarks>
	///	
	///	</remarks>
    /// <example><code>
    /// </code></example>
	class Log
	{
	public:
#if defined(USE_BOOST_THREAD)
		boost::mutex io_mutex;
#endif
		String LogDirName;
		String AppName;
		String AppCategory;
		String ExecParameter;
		bool isFirst;
		static const string TypeName[];
        Log(string _AppName="")
		{
			//cout<<"初始化日志对象"<<endl;
			LogDirName="log";
            AppName = _AppName;
			isFirst=true;
		};
		~Log(){};
		Log(Log & log)
		{
			this->LogDirName=log.LogDirName;
			this->AppName=log.AppName;
			this->AppCategory=log.AppCategory;
			this->ExecParameter=log.ExecParameter;
		};
		static void OutputLogToFile(string strMessage,string strAppCategory="")
		{
			Log log;
			log.WriteLogToFile(strMessage,strAppCategory,1);
		};
		static void OutputErrorToFile(string strMessage,string strAppCategory="")
		{
			Log log;
			log.WriteLogToFile(strMessage,strAppCategory,2);
		};
		//
		//摘要
		//	日志打印
		//参数:
		//	msg:
		//		日志信息
		//	strAppCategory:
		//		日志文件分类
		//	type:
		//		日志类型,0:只在调试时输出,1:日志文件信息,2:错误信息,3:警告,4纯打印信息
		//
		void writeLog(String msg,String strAppCategory,int type=1)
		{
			WriteLogToFile(msg,strAppCategory,type);
		};
		String getLogFile()
		{
			//cout<<"LogDirName="<<this->LogDirName.c_str()<<endl;
			//cout<<"AppName="<<this->AppName.c_str()<<endl;
			//cout<<"AppCategory="<<this->AppCategory.c_str()<<endl;
			return this->LogDirName+ this->AppName+"_"+DateTime::Now().ToString(ShotDate) + this->AppCategory + ".txt";
		};
		Log &operator =(Log & log)
		{
			this->LogDirName=log.LogDirName;
			this->AppName=log.AppName;
			this->AppCategory=log.AppCategory;
			this->ExecParameter=log.ExecParameter;
			return *this;
		};
		void setLogDirName(String _LogDirName)
		{
			this->LogDirName=_LogDirName;
		};
		void setAppName(String _AppName)
		{
			this->AppName=_AppName;
		};
		void setAppCategory(String _AppCategory)
		{
			this->AppCategory=_AppCategory;
		};

	protected:
		void WriteLogToFile(string strMessage,string strAppCategory,int type);
	};

#define PERR(msg) cout<<__FILE__<<msg<<":"<< " error on line "<< __LINE__<<endl ;
#if !defined(ERR_FILE_LINE)
#define ERR_FILE_LINE "ERROR:"+String(__FILE__)+":"+ " on line "+String(__LINE__)
#endif
	inline void writeLog(String msg,Common::Log *log,bool isDebug,int type=-1)
	{
		if(DbLog::writeDbLogFlag && type>=0)
			DbLog::writeDbLog(msg,log,isDebug,type);
		msg=msg.ReplaceAll("\n","\n\t\t\t\t");
		switch(type)
		{
		case 0:
			if(isDebug)
				if(log)log->writeLog(msg,log->AppCategory,type);
				else cout<<Log::TypeName[type]<<DateTime::Now().ToString()<<"\t"<<msg<<endl;
			break;
		case 1:
		case 2:
		case 3:
			if(log)log->writeLog(msg,log->AppCategory,type);
			else cout<<Log::TypeName[type]<<DateTime::Now().ToString()<<"\t"<<msg<<endl;
			break;
		default:
			cout<<Log::TypeName[1]<<DateTime::Now().ToString()<<"\t"<<msg<<endl;
			break;
		}
	};
};

#endif

