// ==============================================================
//progame      Common functions
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
//#define CPP_FILE 5
//#include "Common.h" // "includeHead.h"	//unix FTP

namespace Common
{
#ifdef __Common_fileData_H__
	int fileData::groupSize=7777777;
	char fileData::staticDcp[4096];
#endif
//DataTable static var //
#ifdef __Common_DataTable_H__
	String DataTable::dbStr;
	bool DataTable::stringObject=false;
#endif
//TimeSpan static const var //
#ifdef __Common_TimeSpan_H__
	//
	//一毫秒等于多少天
	//
	const double TimeSpan::DaysPerTicks = 1.1574074074074074074074074074074e-11;
	//
	//一毫秒等于多少小时
	//
	const double TimeSpan::HoursPerTicks = 2.7777777777777777E-10;
	//
	//一毫秒等于多少分钟数
	//
	const double TimeSpan::MinutesPerTicks = 1.6666666666666667E-8;
	//
	//最大毫秒数
	//
	const double TimeSpan::SecondsPerTicks  = 0.000001;
	//
	//最大毫秒数
	//
	const long long TimeSpan::MaxMillis=922337203685477ll ;
	//
	//最大秒数						  15372286728
	//								  4294967296
	const long long TimeSpan::MaxSeconds = 922337203685ll;
	//
	//一天多少毫秒
	//
	const int TimeSpan::MillisPerDay = 0x5265c00;
	//
	//1小时多少毫秒
	//
    const int TimeSpan::MillisPerHour = 0x36ee80;
	//
	//1分钟多少毫秒
	//
    const int TimeSpan::MillisPerMinute = 0xea60;
	//
	//1秒多少毫秒
	//
    const int TimeSpan::MillisPerSecond = 0x3e8;

	const long long TimeSpan::TicksPerMillisecond = 0x3e8LL;
	const long long TimeSpan::TicksPerDay = 0x141DD76000LL;
	const long long TimeSpan::TicksPerHour = 0xD693A400LL;
	const long long TimeSpan::TicksPerMinute = 0x3938700LL;
	const long long TimeSpan::TicksPerSecond = 0xF4240LL;


	//
	//最小毫秒数
	//
	const long long TimeSpan::MinMilliSeconds = -922337203685477ll;
	//
	//最小秒数
	//
	const long long TimeSpan::MinSeconds = -922337203685ll;
    // 摘要:
    //     表示最大的 Common.TimeSpan 值。此字段为只读。
	const TimeSpan TimeSpan::MaxValue=TimeSpan(TimeSpan::MaxSeconds * TimeSpan::TicksPerSecond);
    //
    // 摘要:
    //     表示最小的 Common.TimeSpan 值。此字段为只读。
    const TimeSpan TimeSpan::MinValue=TimeSpan(TimeSpan::MinSeconds * TimeSpan::TicksPerSecond);
    //
    // 摘要:
    //     表示零 Common.TimeSpan 值。此字段为只读。
	const  TimeSpan TimeSpan::Zero=TimeSpan(0);
#endif

//DateTime const static var//
#ifdef __Common_DateTime_H__ 
	const int  DateTime::DaysToMonth365[]={ 0, 0x1f, 0x3b, 90, 120, 0x97, 0xb5, 0xd4, 0xf3, 0x111, 0x130, 0x14e, 0x16d };
	const int  DateTime::DaysToMonth366[]={ 0, 0x1f, 60, 0x5b, 0x79, 0x98, 0xb6, 0xd5, 0xf4, 0x112, 0x131, 0x14f, 0x16e };

	const string DateTime::WeekName[7][3]={{"星期日","Sunday","Sun"}
	,{"星期一","Monday","Mon"},{"星期二","Tuesday","Tue"}
	,{"星期三","Wednesday","Wed"},{"星期四","Thursday","Thu"}
	,{"星期五","Friday","Fri"},{"星期六","Saturday","Sat"}};
	const string DateTime::MonthNames[13][3]={{"","",""}
	,{"1月","January","Jan"},{"2月","February","Feb"},{"3月","March","Mar"}
	,{"4月","April","Apr"},{"5月","May","May"},{"6月","June","June"}
	,{"7月","July","July"},{"8月","Aguest","Agu"},{"9月","September","Sep"}
	,{"10月","October","Oct"},{"11月","November","Nov"},{"12月","December","Dec"}};

	//string DateTime::_result="";
	//
	//摘要：
	//		UTC 标准时间多少毫秒
	//	62135596800000
	//	62135596800000.0000
	const long long DateTime::MillesPerUTCSta=62135596800000ll;
	const long long DateTime::MillesPer2100Year=66238041600000ll;
	//
	//摘要：
	//		最大小时 毫秒数
	//	315537897599999	 
	const long long DateTime::MaxMillesSecond=315537897599999ll;
	const long long DateTime::MinMillesSecond=0;
	const long long DateTime::MaxTicks = 0x461040BCB9F1FFFLL;
	const long long DateTime::MinTicks = 0L;
	const long long DateTime::TicksCeiling = 0xF800000000000000LL;
	const long long DateTime::TicksMask = 0x7FFFFFFFFFFFFFFLL;
	const long long DateTime::TicksPerDay = 0x141DD76000LL;
	const long long DateTime::TicksPerHour = 0xD693A400LL;
	const long long DateTime::TicksPerMillisecond = 0x3e8LL;
	const long long DateTime::TicksPerMinute = 0x3938700LL;
	const long long DateTime::TicksPerSecond = 0xF4240LL;
	const long long DateTime::TicksPerUTCSta=0xDCBFFEFF2BC000LL;
	const long long DateTime::SecondPerUTCSta=0xE7791F700ll;

	//
	//摘要：
	//		100年多少天
	//	36524
	const int DateTime::DaysPer100Years = 0x8eac;
	//
	//摘要：
	//		400年多少天
	//	146097
    const int DateTime::DaysPer400Years = 0x23ab1;
	//
	//摘要：
	//		4年多少天
	//	1461
    const int DateTime::DaysPer4Years = 0x5b5;
	//
	//摘要：
	//		1年多少天
	//	365
    const int DateTime::DaysPerYear = 0x16d;
	//
	//摘要：
	//		一天多少毫秒
	//	86400000
	const int DateTime::MillisPerDay = 0x5265c00;
	//
	//摘要：
	//		1小时多少毫秒
	//	3600000
    const int DateTime::MillisPerHour = 0x36ee80;
	//
	//摘要：
	//		1分钟多少毫秒
	//	60000
    const int DateTime::MillisPerMinute = 0xea60;
	//
	//摘要：
	//		1秒多少毫秒
	//	1000
    const int DateTime::MillisPerSecond = 0x3e8;
//#if OSTYPE<=10
	const time_t DateTime::ts=time(NULL);
	const int DateTime::lHour=localtime(&ts)->tm_hour;		
	const TimeZone DateTime::localTimeZone =  TimeZone((lHour-gmtime(&ts)->tm_hour)>12?((lHour-gmtime(&ts)->tm_hour)-24):((lHour-gmtime(&ts)->tm_hour)<-12?((lHour-gmtime(&ts)->tm_hour)+24):(lHour-gmtime(&ts)->tm_hour)));
//#endif
	//
	//摘要：
	//		最大时间值
	//	9999-12-31 23:59:59   //	315537897599999 毫秒 
	const  DateTime  DateTime::MaxValue=DateTime(DateTime::MaxTicks);
	//
	//摘要：
	//		最小时间值
	//	0001-1-1 0:00:00  //	0 毫秒
	const  DateTime  DateTime::MinValue=DateTime(DateTime::MinTicks);
	//*****    DateTime    TimeSpan operator method          *                                    
	// 摘要:
	//     从一个指定日期和时间减去另一个指定的日期和时间以生成时间间隔。
	//
	// 参数:
	//   d2:
	//     Common.DateTime（减数）。
	//
	//   d1:
	//     Common.DateTime（被减数）。
	//
	// 返回结果:
	//     Common.TimeSpan，它是 d1 和 d2 之间的时间间隔，即 d1 减去 d2。
	TimeSpan operator -(DateTime d1, DateTime d2)
	{
		return TimeSpan((d1.GetTicks()-d2.GetTicks()));
	}
	//
	// 摘要:
	//     从指定的日期和时间减去指定的时间间隔，以生成新的日期和时间。
	//
	// 参数:
	//   d:
	//     Common.DateTime。
	//
	//   t:
	//     Common.TimeSpan。
	//
	// 返回结果:
	//     Common.DateTime，它的值为 d 的值减去 t 的值。
	DateTime operator -(DateTime d, TimeSpan t)
	{
		return  DateTime(d._Ticks-t.getTotalTicks());
	}
	//
	// 摘要:
	//     确定 Common.DateTime 的两个指定的实例是否不等。
	//
	// 参数:
	//   d2:
	//     Common.DateTime。
	//
	//   d1:
	//     Common.DateTime。
	//
	// 返回结果:
	//     如果 d1 和 d2 不表示同一日期和时间，则为 true；否则为 false。
	bool operator !=(DateTime d1, DateTime d2)
	{
		if(d1.GetTicks()==d2.GetTicks())return false;
		else return true;
	}
	//
	// 摘要:
	//     将指定的时间间隔加到指定的日期和时间以生成新的日期和时间。
	//
	// 参数:
	//   d:
	//     Common.DateTime。
	//
	//   t:
	//     Common.TimeSpan。
	//
	// 返回结果:
	//     Common.DateTime，它是 d 和 t 值的和。
	DateTime operator +(DateTime d, TimeSpan t)
	{
		return  DateTime(d._Ticks+t.getTotalTicks());
	}
	DateTime &operator +=(DateTime &d, TimeSpan t)
	{
		return d=DateTime(d._Ticks+t.getTotalTicks());
	}
	//
	// 摘要:
	//     确定指定的 Common.DateTime 是否小于另一个指定的 Common.DateTime。
	//
	// 参数:
	//   t2:
	//     Common.DateTime。
	//
	//   t1:
	//     Common.DateTime。
	//
	// 返回结果:
	//     如果 t1 小于 t2，则为 true；否则为 false。
	bool operator <(DateTime t1, DateTime t2)
	{
		return (t1.GetTicks()<t2.GetTicks()) ;
	}
	//
	// 摘要:
	//     确定指定的 Common.DateTime 是否小于或等于另一个指定的 Common.DateTime。
	//
	// 参数:
	//   t2:
	//     Common.DateTime。
	//
	//   t1:
	//     Common.DateTime。
	//
	// 返回结果:
	//     如果 t1 小于或等于 t2，则为 true；否则为 false。
	bool operator <=(DateTime t1, DateTime t2)
	{
		return (t1.GetTicks()<=t2.GetTicks());
	}
	//
	// 摘要:
	//     确定 Common.DateTime 的两个指定的实例是否相等。
	//
	// 参数:
	//   d2:
	//     Common.DateTime。
	//
	//   d1:
	//     Common.DateTime。
	//
	// 返回结果:
	//     如果 d1 和 d2 表示同一日期和时间，则为 true；否则为 false。
	bool operator ==(DateTime d1, DateTime d2)
	{
		return (d1.GetTicks()==d2.GetTicks());
	}
	//
	// 摘要:
	//     确定指定的 Common.DateTime 是否大于另一个指定的 Common.DateTime。
	//
	// 参数:
	//   t2:
	//     Common.DateTime。
	//
	//   t1:
	//     Common.DateTime。
	//
	// 返回结果:
	//     如果 t1 大于 t2，则为 true；否则为 false。
	bool operator >(DateTime t1, DateTime t2)
	{
		return (t1.GetTicks()>t2.GetTicks());
	}
	 
	//
	// 摘要:
	//     确定指定的 Common.DateTime 是否大于或等于另一个指定的 Common.DateTime。
	//
	// 参数:
	//   t2:
	//     Common.DateTime。
	//
	//   t1:
	//     Common.DateTime。
	//
	// 返回结果:
	//     如果 t1 大于或等于 t2，则为 true；否则为 false。
	bool operator >=(DateTime t1, DateTime t2)
	{
		return (t1.GetTicks()>=t2.GetTicks());
	}
#endif

//**************TimeSpan  ***********************************************                                    
#ifdef __Common_TimeSpan_H__
    // 摘要:
    //     返回其值为指定实例的相反值的 Common::TimeSpan。
    //
    // 参数:
    //   t:
    //     Common::TimeSpan。
    //
    // 返回结果:
    //     与此实例的数值相同，但符号相反的 Common::TimeSpan。
    TimeSpan &operator -(TimeSpan &t)
	{
		t._ticks=0-t._ticks;
		return t;
	}
    //
    // 摘要:
    //     从另一个指定的 Common::TimeSpan 中减去指定的 Common::TimeSpan。
    //
    // 参数:
    //   t2:
    //     TimeSpan。
    //
    //   t1:
    //     Common::TimeSpan。
    //
    // 返回结果:
    //     值为 t1 的值减去 t2 的值后所得结果的 TimeSpan。
    TimeSpan operator -(TimeSpan &t1, TimeSpan &t2)
	{
		return  TimeSpan(t1._ticks-t2._ticks);
	}
    TimeSpan &operator -=(TimeSpan &t1, TimeSpan &t2)
	{
		return t1=TimeSpan(t1._ticks-=t2._ticks);
	}
    //
    // 摘要:
    //     指示两个 Common::TimeSpan 实例是否不相等。
    //
    // 参数:
    //   t2:
    //     TimeSpan。
    //
    //   t1:
    //     Common::TimeSpan。
    //
    // 返回结果:
    //     如果 t1 和 t2 的值不相等，则为 true；否则为 false。
    bool operator !=(TimeSpan &t1, TimeSpan &t2)
	{
		return (t1._ticks!=t2._ticks);
	}
    //
    // 摘要:
    //     添加两个指定的 Common::TimeSpan 实例。
    //
    // 参数:
    //   t2:
    //     TimeSpan。
    //
    //   t1:
    //     Common::TimeSpan。
    //
    // 返回结果:
    //     值为 t1 和 t2 的值之和的 Common::TimeSpan。
    TimeSpan operator +(TimeSpan &t1, TimeSpan &t2)
	{
		return  TimeSpan(t1._ticks+t2._ticks);
	}
    TimeSpan &operator +=(TimeSpan &t1, TimeSpan &t2)
	{
		return  t1=  TimeSpan(t1._ticks+t2._ticks);
	}
    //
    // 摘要:
    //     指示指定的 Common::TimeSpan 是否小于另一个指定的 Common::TimeSpan。
    //
    // 参数:
    //   t2:
    //     TimeSpan。
    //
    //   t1:
    //     Common::TimeSpan。
    //
    // 返回结果:
    //     如果 t1 的值小于 t2 的值，则为 true；否则为 false。
    bool operator <(TimeSpan &t1, TimeSpan &t2)
	{
		return (t1._ticks<t2._ticks);
	}
    //
    // 摘要:
    //     指示指定的 Common::TimeSpan 是否小于或等于另一个指定的 Common::TimeSpan。
    //
    // 参数:
    //   t2:
    //     TimeSpan。
    //
    //   t1:
    //     Common::TimeSpan。
    //
    // 返回结果:
    //     如果 t1 的值小于或等于 t2 的值，则为 true；否则为 false。
    bool operator <=(TimeSpan &t1, TimeSpan &t2)
	{
		return (t1._ticks<=t2._ticks);
	}
    //
    // 摘要:
    //     指示两个 Common::TimeSpan 实例是否相等。
    //
    // 参数:
    //   t2:
    //     TimeSpan。
    //
    //   t1:
    //     Common::TimeSpan。
    //
    // 返回结果:
    //     如果 t1 和 t2 的值相等，则为 true；否则为 false。
    bool operator ==(TimeSpan &t1, TimeSpan &t2)
	{
		return (t1._ticks==t2._ticks);
	}
    //
    // 摘要:
    //     指示指定的 Common::TimeSpan 是否大于另一个指定的 Common::TimeSpan。
    //
    // 参数:
    //   t2:
    //     TimeSpan。
    //
    //   t1:
    //     Common::TimeSpan。
    //
    // 返回结果:
    //     如果 t1 的值大于 t2 的值，则为 true；否则为 false。
    bool operator >(TimeSpan &t1, TimeSpan &t2)
	{
		return (t1._ticks>t2._ticks);
	}
    //
    // 摘要:
    //     指示指定的 Common::TimeSpan 是否大于或等于另一个指定的 Common::TimeSpan。
    //
    // 参数:
    //   t2:
    //     TimeSpan。
    //
    //   t1:
    //     Common::TimeSpan。
    //
    // 返回结果:
    //     如果 t1 的值大于或等于 t2 的值，则为 true；否则为 false。
    bool operator >=(TimeSpan &t1, TimeSpan &t2)
	{
		return (t1._ticks>=t2._ticks);
	}

#endif
    //
    // 摘要:
    //     加载ctl文件到数据表:快速加载。忽略文件头,加载条数限制
    //
    // 参数:
    //   pCtlControlName:
    //     TimeSpan。
    //
    //   pCtlDataName:
    //     Common::TimeSpan。
	//
	//	pDbId:
    //
    // 返回结果:
    //     
	int ImportCtlFile( String ctlName,String ctlDataName,String dbConnStr,bool direct,bool parallel
		,int readsize,int bindsize,int rows,const long skipNum,const long loadRowNum)
	{
		cout<<"Begin SQL*Loader..."<<endl;
		String Command ;
		String logName,badName ;
		if(ctlDataName=="")
		{
			logName=ctlName+".log";
			badName=ctlName+".bad";//skip=%ld load=%ld
		}
		else
		{
			logName=ctlDataName+".log";
			badName=ctlDataName+".bad";//skip=%ld load=%ld
		}

		Command="sqlldr userid="+dbConnStr+" control="+ctlName+" log="+logName+" bad="+badName;
		if(ctlDataName!="")Command+=" data="+ctlDataName;
		if(skipNum>0)Command+=String(" skip=")+skipNum;
		if(loadRowNum>0)Command+=String(" load=")+loadRowNum;
		if(parallel)Command+=" parallel=TRUE  skip_unusable_indexes=true skip_index_maintenance=true ";
		if(direct)Command+=" direct=TRUE ";
		if(readsize>0 && readsize<=20000000)
			Command+=String(" readsize=")+readsize;
		if(bindsize>0 && bindsize<=readsize)
			Command+=String(" bindsize=")+bindsize;
		else
			Command+=String(" bindsize=")+readsize;
		if(rows>0)
			Command+=String(" rows=")+rows;
#if OSTYPE>10
		Command+=" silent=header,feedback ";
#endif
		if(!parallel)cout<<"执行sqlldr命令: "<<Command.c_str()<<endl;
		return Sqlldr(Command);
	}

	// 摘要:
	//    调用sqlldr执行导入，并返回导入情况
	//
	// 参数:
	//   pCommand:
	//     执行命令。
	//
	// 返回结果:
	//       -1 失败
	//		0  成功导入,无BAD文件
	//		1  数据库对象校验失败表不存在或字段不匹配等
	//		2  导入不完全,产生BAD文件:字段异常等
	int Sqlldr(string pCommand)
	{
		int  ret=0 ;
		string errMsg;
		if( ! System(pCommand, errMsg,ret) )
		{
			cout<<"Error: "<<errMsg.c_str()<<endl;
			ret =-1;
		}
		else
		{
			printf("sqlldr调用返回值:%d ，",ret) ;
			if( ret==0)
				printf("成功导入,无BAD文件\n") ;
			else if( ret==1)
				printf("对象校验失败：表不存在或字段不匹配等\n");
			else if( ret==2)
				printf("导入不完全,产生BAD文件:字段异常等\n") ;
		}
		return ret ;
	}

	// 摘要:
	//    调用system执行程序,并返回执行情况
	//
	// 参数:
	//   pCommand:
	//		执行命令。
	//	pOutMsg:
	//		调用情况，错误信息
	//	pRetValue:
	//		调用程序的返回值（仅在调用成功时有参考性）
	//
	// 返回结果:
	//         true  成功
	//         false 失败
	bool System(string pCommand,string &pOutMsg,int& pRetValue)
	{
		int status , ret ;
		status = system(pCommand.c_str()) ;
		if((status & 0x7F)==0)
		{
			ret = status >>8 ;
			if( ret == 0x7F )
			{
				pOutMsg=String("调用程序[")+pCommand+"]不存在\n";
				return false ;
			}
			else
			{
				pRetValue = ret ;
				pOutMsg=String("程序正常调用结束,返回值是[")+ret+"]\n";
				return true ;
			}
		}
		else if( ((status & 0x80)^0x7F)==0 )
		{
			ret = status >>8 ;
			pOutMsg=String("调用的子程序中断,引起中断的信号是:")+ret+"]\n";
			return false ;
		}
		else if( ( ( (status&0x7F)+1)>>1) > 0 )
		{
			ret = status & 0x7F ;
			pOutMsg=String("由信号[")+ret+"]引起结束\n";
			return false ;
		}
		else if( (status & 0x80) ==0 )
		{
			pOutMsg="产生coredump";
			return false ;
		}
		else
		{
			return false;
		}
	}

	int System(string pCommand,String &pOutMsg)
	{
		int status , ret ;
		status = system(pCommand.c_str()) ;
		if((status & 0x7F)==0)
		{
			ret = status >>8 ;
			if( ret == 0x7F )
			{
				pOutMsg=String("调用程序[")+pCommand+"]不存在\n";
				return -1 ;
			}
			else
			{
				pOutMsg=String("程序正常调用结束,返回值是[")+ret+"]\n";
				return ret ;
			}
		}
		else if( ((status & 0x80)^0x7F)==0 )
		{
			ret = status >>8 ;
			pOutMsg=String("调用的子程序中断,引起中断的信号是:")+ret+"]\n";
			return -1 ;
		}
		else if( ( ( (status&0x7F)+1)>>1) > 0 )
		{
			ret = status & 0x7F ;
			pOutMsg=String("由信号[")+ret+"]引起结束\n";
			return -1 ;
		}
		else if( (status & 0x80) ==0 )
		{
			pOutMsg="产生coredump";
			return -1 ;
		}
		else
		{
			return -1;
		}
	}

#if OSTYPE>10
	//
	//摘要:
	//       Fork出子进程串行执行一系列命令
	//参数:
	//	lst_appName:
	//		执行命令的列表
	//
	int ForkRun(list<string> lst_appName)
	{
		int   p_id ;
		list<string>::iterator appIterator ;
		if((p_id=fork())>0)
		{
			//while(pidLen)			//循环等待子进程 pidLen 子进程数
			//{
			//	int stat;
			//	int rt;
			//	rt = wait(&stat);
			//	if (rt > 0)
			//	{
   // 				pidLen--;
   // 				if(stat)
   // 					return false;//子进程执行失败
			//		printf("Child %d exit status: %d\n", rt, WEXITSTATUS(stat));
			//	}
			//}
	//		int e, status;
	//      for(;;)	//等待
	//      {
	//			e = waitpid(pid,&status,WNOHANG);
	//          if(e<0)
	//          {
	//				e = waitpid(pid,&status,WNOHANG);
	//              break;
	//          }
	//          usleep(500);
	//		}
		}
		else if(p_id==0)   //子进程启动子进程
		{
			for (appIterator=lst_appName.begin(); appIterator!=lst_appName.end();++appIterator)
			{
    			cout << *appIterator << endl;
    			system( (*appIterator).c_str()) ;
			}
			printf("子进程完毕\n");
			exit(0);
		}
		else if (p_id<0)
		{
			cout<<"Create child process failed" << endl ;
			return -1 ;
		}
		return 1;
	}
	int  ForkRun(Array<string> lst_appName)
	{
		list<string> temp;
		for(int i=0;i<lst_appName.size();i++)
		{
			temp.push_back(lst_appName[i]);
		}
		return ForkRun(temp);
	}
	int  ForkRun(Array<String> lst_appName)
	{
		Array<string> temp;
		for(int i=lst_appName.size()-1;i>=0;i--)
		{
			temp[i]=lst_appName[i];
		}
		return ForkRun(temp);
	}

#endif

	bool CheckSqlldrRet(const char* log_file,string & out_msg)
	{
		FILE* log_stream =NULL ;
		bool bSuccess=true;
		char line[1024];
		char tableName[50] ;
		char s_temp[256];
		long recordRead=0L,recordReject=0L;
		char* ptr=0,*ptr2=0 ;
		int i=0 ;

#if OSTYPE>10
		char error_key[]="SQL*Loader-" ;
		const char table_key[]="Table";
		const char read_key[] ="Total logical records read:";
		const char reject_key[]="Total logical records rejected:";
#else
		char error_key[]="SQL*Loader-" ;
		const char table_key[] ="表";
		const char read_key[] = "读取的逻辑记录总数:";
		const char reject_key[]="拒绝的逻辑记录总数:";
#endif

		if( (log_stream=fopen(log_file, "r" ))==NULL)
		{
			cout<< "SQL*Loader日志文件[" << log_file <<"] open failed" <<endl;
			return false ;
		}
		fseek(log_stream,0L,SEEK_SET) ;
		while(!feof(log_stream))
		{
			memset(line,0x00,sizeof(line));
			if( fgets( line, 1024, log_stream )== NULL)
				break ;

			line[strlen(line)-1]='\0';
			if(strlen(line)==0)
				continue ;

			if(strstr(line,error_key)!=NULL)
			{
				bSuccess =false;
				out_msg=line;
			}
			else if( strncmp(line,table_key,strlen(table_key) )==0 && strstr(line,":") != NULL )
			{
				ptr = (char*)(line+strlen(table_key)) ;
				while( *ptr++==' ') ;
				ptr--;
				ptr2=ptr;
				while( *ptr2++!=':') ;
				ptr2--;
				memset(tableName,0x00,sizeof(tableName));
				strncpy(tableName,ptr,ptr2-ptr) ;
			}
			else if( strncmp(line,read_key,strlen(read_key))== 0
				|| strncmp(line,reject_key,strlen(reject_key))== 0 )
			{
				ptr= (char*)line + strlen(line)-1 ;
				while( isdigit(*ptr))
					ptr-- ;
				if( !isdigit(*ptr))
					ptr++ ;
				strcpy( s_temp,ptr);
				s_temp[strlen(s_temp)-1]='\0';

				if(strncmp(line,read_key,strlen(read_key))==0)
					recordRead=atol(s_temp) ;
				if(strncmp(line,reject_key,strlen(reject_key))==0)
					recordReject=atol(s_temp) ;
			}
		}
		fclose(log_stream) ;
		if( recordRead>0 && recordReject>0 )
		{
			bSuccess=false;
			sprintf(s_temp,"SQL*Loader 失败,目标表:[%s],记录总数:[%ld],异常记录数:[%ld]",tableName,recordRead,recordReject);
		}
		if(bSuccess)
			sprintf(s_temp,"SQL*Loader 成功,目标表:[%s],记录总数:[%ld],异常记录数:[%ld]",tableName,recordRead,recordReject);
		out_msg=s_temp;
		return bSuccess;
	}

}
