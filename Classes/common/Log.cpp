// ==============================================================
//progame      Common::Log  
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
#include "Common.h"

namespace Common
{
	const string Log::TypeName[]={"[DEBUG]","[INFO ]","[WARN ]","[ERROR]"};
	bool DbLog::writeDbLogFlag=false;
	String DbLog::dbLogTable="etl_att_monitir_log";
	void *DbLog::_con=NULL ;
	void *DbLog::_rs=NULL;

	void Log::WriteLogToFile(string strMessage,string strAppCategory,int type)
	{
#if defined(USE_BOOST_THREAD)
		boost::mutex::scoped_lock lock(io_mutex);
#endif
		if(isFirst)
		{
			Path::GetDemandDir(LogDirName);
			if(Directory::CreateDir(LogDirName)==false)
			{
				printf("日志目录创建失败:%s\n",LogDirName.c_str());
				return;
			}
			isFirst=false;
		}
		string strInfo;
		string strTempDir;
		strTempDir	=getLogFile();
		FILE *fp=fopen(strTempDir.c_str(),"a+");
		if(fp==NULL)
		{
			printf("日志文件打开失败:%s,%s\n",strTempDir.c_str(),strerror(errno));
			return;
		}
		strInfo = Log::TypeName[type] +DateTime::Now().ToString()+"\t"+ strMessage;
        //printf("内容[%s]\n",strInfo.Str);
		//printf("_getdrive: %d \n",fileno(fp));
		fprintf(fp,"%s\r\n",strInfo.c_str());
		fclose(fp);
		cout<<strInfo<<endl;
	}
	void DbLog::writeDbLog(String & msg,Log *log,bool isDebug,int type)
	{
		//String sql;
		//if(_con==NULL)
		//{
		//	_con=new Connection();
		//	_rs=new ResultSet();
		//}
		//Connection &con=*((Connection *)DbLog::_con);
		//ResultSet &rs=*((ResultSet *)DbLog::_rs);
		////写日志
		//try
		//{	
		//	if(!con.connected)
		//	{
		//		String sql=" insert into "+dbLogTable+"(LOG_ID, MONTH_NO,date_no,program_NAME,EXEC_PARAMETER,LOG_MESS,LOG_Date,Log_TYPE)"
		//			" values(ETL_ATT_MONITOR_LOG_ID.nextval,:MONTH_NO<int> ,:date_no<int>,:program_NAME<char[100]>,:EXEC_PARAMETER<char[100]>,:Log_Mess<char[4000]> "
		//			",:LOG_Date<timestamp>,:Log_TYPE<int>)";
		//		con.close();
		//		rs.close();
		//		con.rlogon(dbLogTable,1);
		//		rs.open(1,sql,con);
		//	}
		//	DateTime dt;
		//	rs.open(1,sql,con);
		//	rs<<dt.GetYearMonth();
		//	rs<<dt.GetDay();
		//	rs<<log->AppName.c_str();
		//	rs<<log->ExecParameter.c_str();
		//	if(msg.size()>3999)
		//		rs<<msg.SubString(0,3999).c_str();
		//	else
		//		rs<<msg.c_str();
		//	rs<<DateTime().GetOtlTime();
		//	rs<<type; 
		//	rs.flush();
		//}
		//catch(otl_exception& er)
		//{
		//	String log_mess="写数据库日志发生错误："+String((char *)er.msg)+"\nstm_text:"+er.stm_text+"\nvar_info:"+er.var_info+"\n==>"+msg; 
		//	writeLog(log_mess,log,isDebug,type);
		//	rs.close();
		//	//con.close();
		//}
	};
}
//
