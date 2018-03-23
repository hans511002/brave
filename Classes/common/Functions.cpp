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
	//һ������ڶ�����
	//
	const double TimeSpan::DaysPerTicks = 1.1574074074074074074074074074074e-11;
	//
	//һ������ڶ���Сʱ
	//
	const double TimeSpan::HoursPerTicks = 2.7777777777777777E-10;
	//
	//һ������ڶ��ٷ�����
	//
	const double TimeSpan::MinutesPerTicks = 1.6666666666666667E-8;
	//
	//��������
	//
	const double TimeSpan::SecondsPerTicks  = 0.000001;
	//
	//��������
	//
	const long long TimeSpan::MaxMillis=922337203685477ll ;
	//
	//�������						  15372286728
	//								  4294967296
	const long long TimeSpan::MaxSeconds = 922337203685ll;
	//
	//һ����ٺ���
	//
	const int TimeSpan::MillisPerDay = 0x5265c00;
	//
	//1Сʱ���ٺ���
	//
    const int TimeSpan::MillisPerHour = 0x36ee80;
	//
	//1���Ӷ��ٺ���
	//
    const int TimeSpan::MillisPerMinute = 0xea60;
	//
	//1����ٺ���
	//
    const int TimeSpan::MillisPerSecond = 0x3e8;

	const long long TimeSpan::TicksPerMillisecond = 0x3e8LL;
	const long long TimeSpan::TicksPerDay = 0x141DD76000LL;
	const long long TimeSpan::TicksPerHour = 0xD693A400LL;
	const long long TimeSpan::TicksPerMinute = 0x3938700LL;
	const long long TimeSpan::TicksPerSecond = 0xF4240LL;


	//
	//��С������
	//
	const long long TimeSpan::MinMilliSeconds = -922337203685477ll;
	//
	//��С����
	//
	const long long TimeSpan::MinSeconds = -922337203685ll;
    // ժҪ:
    //     ��ʾ���� Common.TimeSpan ֵ�����ֶ�Ϊֻ����
	const TimeSpan TimeSpan::MaxValue=TimeSpan(TimeSpan::MaxSeconds * TimeSpan::TicksPerSecond);
    //
    // ժҪ:
    //     ��ʾ��С�� Common.TimeSpan ֵ�����ֶ�Ϊֻ����
    const TimeSpan TimeSpan::MinValue=TimeSpan(TimeSpan::MinSeconds * TimeSpan::TicksPerSecond);
    //
    // ժҪ:
    //     ��ʾ�� Common.TimeSpan ֵ�����ֶ�Ϊֻ����
	const  TimeSpan TimeSpan::Zero=TimeSpan(0);
#endif

//DateTime const static var//
#ifdef __Common_DateTime_H__ 
	const int  DateTime::DaysToMonth365[]={ 0, 0x1f, 0x3b, 90, 120, 0x97, 0xb5, 0xd4, 0xf3, 0x111, 0x130, 0x14e, 0x16d };
	const int  DateTime::DaysToMonth366[]={ 0, 0x1f, 60, 0x5b, 0x79, 0x98, 0xb6, 0xd5, 0xf4, 0x112, 0x131, 0x14f, 0x16e };

	const string DateTime::WeekName[7][3]={{"������","Sunday","Sun"}
	,{"����һ","Monday","Mon"},{"���ڶ�","Tuesday","Tue"}
	,{"������","Wednesday","Wed"},{"������","Thursday","Thu"}
	,{"������","Friday","Fri"},{"������","Saturday","Sat"}};
	const string DateTime::MonthNames[13][3]={{"","",""}
	,{"1��","January","Jan"},{"2��","February","Feb"},{"3��","March","Mar"}
	,{"4��","April","Apr"},{"5��","May","May"},{"6��","June","June"}
	,{"7��","July","July"},{"8��","Aguest","Agu"},{"9��","September","Sep"}
	,{"10��","October","Oct"},{"11��","November","Nov"},{"12��","December","Dec"}};

	//string DateTime::_result="";
	//
	//ժҪ��
	//		UTC ��׼ʱ����ٺ���
	//	62135596800000
	//	62135596800000.0000
	const long long DateTime::MillesPerUTCSta=62135596800000ll;
	const long long DateTime::MillesPer2100Year=66238041600000ll;
	//
	//ժҪ��
	//		���Сʱ ������
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
	//ժҪ��
	//		100�������
	//	36524
	const int DateTime::DaysPer100Years = 0x8eac;
	//
	//ժҪ��
	//		400�������
	//	146097
    const int DateTime::DaysPer400Years = 0x23ab1;
	//
	//ժҪ��
	//		4�������
	//	1461
    const int DateTime::DaysPer4Years = 0x5b5;
	//
	//ժҪ��
	//		1�������
	//	365
    const int DateTime::DaysPerYear = 0x16d;
	//
	//ժҪ��
	//		һ����ٺ���
	//	86400000
	const int DateTime::MillisPerDay = 0x5265c00;
	//
	//ժҪ��
	//		1Сʱ���ٺ���
	//	3600000
    const int DateTime::MillisPerHour = 0x36ee80;
	//
	//ժҪ��
	//		1���Ӷ��ٺ���
	//	60000
    const int DateTime::MillisPerMinute = 0xea60;
	//
	//ժҪ��
	//		1����ٺ���
	//	1000
    const int DateTime::MillisPerSecond = 0x3e8;
//#if OSTYPE<=10
	const time_t DateTime::ts=time(NULL);
	const int DateTime::lHour=localtime(&ts)->tm_hour;		
	const TimeZone DateTime::localTimeZone =  TimeZone((lHour-gmtime(&ts)->tm_hour)>12?((lHour-gmtime(&ts)->tm_hour)-24):((lHour-gmtime(&ts)->tm_hour)<-12?((lHour-gmtime(&ts)->tm_hour)+24):(lHour-gmtime(&ts)->tm_hour)));
//#endif
	//
	//ժҪ��
	//		���ʱ��ֵ
	//	9999-12-31 23:59:59   //	315537897599999 ���� 
	const  DateTime  DateTime::MaxValue=DateTime(DateTime::MaxTicks);
	//
	//ժҪ��
	//		��Сʱ��ֵ
	//	0001-1-1 0:00:00  //	0 ����
	const  DateTime  DateTime::MinValue=DateTime(DateTime::MinTicks);
	//*****    DateTime    TimeSpan operator method          *                                    
	// ժҪ:
	//     ��һ��ָ�����ں�ʱ���ȥ��һ��ָ�������ں�ʱ��������ʱ������
	//
	// ����:
	//   d2:
	//     Common.DateTime����������
	//
	//   d1:
	//     Common.DateTime������������
	//
	// ���ؽ��:
	//     Common.TimeSpan������ d1 �� d2 ֮���ʱ�������� d1 ��ȥ d2��
	TimeSpan operator -(DateTime d1, DateTime d2)
	{
		return TimeSpan((d1.GetTicks()-d2.GetTicks()));
	}
	//
	// ժҪ:
	//     ��ָ�������ں�ʱ���ȥָ����ʱ�������������µ����ں�ʱ�䡣
	//
	// ����:
	//   d:
	//     Common.DateTime��
	//
	//   t:
	//     Common.TimeSpan��
	//
	// ���ؽ��:
	//     Common.DateTime������ֵΪ d ��ֵ��ȥ t ��ֵ��
	DateTime operator -(DateTime d, TimeSpan t)
	{
		return  DateTime(d._Ticks-t.getTotalTicks());
	}
	//
	// ժҪ:
	//     ȷ�� Common.DateTime ������ָ����ʵ���Ƿ񲻵ȡ�
	//
	// ����:
	//   d2:
	//     Common.DateTime��
	//
	//   d1:
	//     Common.DateTime��
	//
	// ���ؽ��:
	//     ��� d1 �� d2 ����ʾͬһ���ں�ʱ�䣬��Ϊ true������Ϊ false��
	bool operator !=(DateTime d1, DateTime d2)
	{
		if(d1.GetTicks()==d2.GetTicks())return false;
		else return true;
	}
	//
	// ժҪ:
	//     ��ָ����ʱ�����ӵ�ָ�������ں�ʱ���������µ����ں�ʱ�䡣
	//
	// ����:
	//   d:
	//     Common.DateTime��
	//
	//   t:
	//     Common.TimeSpan��
	//
	// ���ؽ��:
	//     Common.DateTime������ d �� t ֵ�ĺ͡�
	DateTime operator +(DateTime d, TimeSpan t)
	{
		return  DateTime(d._Ticks+t.getTotalTicks());
	}
	DateTime &operator +=(DateTime &d, TimeSpan t)
	{
		return d=DateTime(d._Ticks+t.getTotalTicks());
	}
	//
	// ժҪ:
	//     ȷ��ָ���� Common.DateTime �Ƿ�С����һ��ָ���� Common.DateTime��
	//
	// ����:
	//   t2:
	//     Common.DateTime��
	//
	//   t1:
	//     Common.DateTime��
	//
	// ���ؽ��:
	//     ��� t1 С�� t2����Ϊ true������Ϊ false��
	bool operator <(DateTime t1, DateTime t2)
	{
		return (t1.GetTicks()<t2.GetTicks()) ;
	}
	//
	// ժҪ:
	//     ȷ��ָ���� Common.DateTime �Ƿ�С�ڻ������һ��ָ���� Common.DateTime��
	//
	// ����:
	//   t2:
	//     Common.DateTime��
	//
	//   t1:
	//     Common.DateTime��
	//
	// ���ؽ��:
	//     ��� t1 С�ڻ���� t2����Ϊ true������Ϊ false��
	bool operator <=(DateTime t1, DateTime t2)
	{
		return (t1.GetTicks()<=t2.GetTicks());
	}
	//
	// ժҪ:
	//     ȷ�� Common.DateTime ������ָ����ʵ���Ƿ���ȡ�
	//
	// ����:
	//   d2:
	//     Common.DateTime��
	//
	//   d1:
	//     Common.DateTime��
	//
	// ���ؽ��:
	//     ��� d1 �� d2 ��ʾͬһ���ں�ʱ�䣬��Ϊ true������Ϊ false��
	bool operator ==(DateTime d1, DateTime d2)
	{
		return (d1.GetTicks()==d2.GetTicks());
	}
	//
	// ժҪ:
	//     ȷ��ָ���� Common.DateTime �Ƿ������һ��ָ���� Common.DateTime��
	//
	// ����:
	//   t2:
	//     Common.DateTime��
	//
	//   t1:
	//     Common.DateTime��
	//
	// ���ؽ��:
	//     ��� t1 ���� t2����Ϊ true������Ϊ false��
	bool operator >(DateTime t1, DateTime t2)
	{
		return (t1.GetTicks()>t2.GetTicks());
	}
	 
	//
	// ժҪ:
	//     ȷ��ָ���� Common.DateTime �Ƿ���ڻ������һ��ָ���� Common.DateTime��
	//
	// ����:
	//   t2:
	//     Common.DateTime��
	//
	//   t1:
	//     Common.DateTime��
	//
	// ���ؽ��:
	//     ��� t1 ���ڻ���� t2����Ϊ true������Ϊ false��
	bool operator >=(DateTime t1, DateTime t2)
	{
		return (t1.GetTicks()>=t2.GetTicks());
	}
#endif

//**************TimeSpan  ***********************************************                                    
#ifdef __Common_TimeSpan_H__
    // ժҪ:
    //     ������ֵΪָ��ʵ�����෴ֵ�� Common::TimeSpan��
    //
    // ����:
    //   t:
    //     Common::TimeSpan��
    //
    // ���ؽ��:
    //     ���ʵ������ֵ��ͬ���������෴�� Common::TimeSpan��
    TimeSpan &operator -(TimeSpan &t)
	{
		t._ticks=0-t._ticks;
		return t;
	}
    //
    // ժҪ:
    //     ����һ��ָ���� Common::TimeSpan �м�ȥָ���� Common::TimeSpan��
    //
    // ����:
    //   t2:
    //     TimeSpan��
    //
    //   t1:
    //     Common::TimeSpan��
    //
    // ���ؽ��:
    //     ֵΪ t1 ��ֵ��ȥ t2 ��ֵ�����ý���� TimeSpan��
    TimeSpan operator -(TimeSpan &t1, TimeSpan &t2)
	{
		return  TimeSpan(t1._ticks-t2._ticks);
	}
    TimeSpan &operator -=(TimeSpan &t1, TimeSpan &t2)
	{
		return t1=TimeSpan(t1._ticks-=t2._ticks);
	}
    //
    // ժҪ:
    //     ָʾ���� Common::TimeSpan ʵ���Ƿ���ȡ�
    //
    // ����:
    //   t2:
    //     TimeSpan��
    //
    //   t1:
    //     Common::TimeSpan��
    //
    // ���ؽ��:
    //     ��� t1 �� t2 ��ֵ����ȣ���Ϊ true������Ϊ false��
    bool operator !=(TimeSpan &t1, TimeSpan &t2)
	{
		return (t1._ticks!=t2._ticks);
	}
    //
    // ժҪ:
    //     �������ָ���� Common::TimeSpan ʵ����
    //
    // ����:
    //   t2:
    //     TimeSpan��
    //
    //   t1:
    //     Common::TimeSpan��
    //
    // ���ؽ��:
    //     ֵΪ t1 �� t2 ��ֵ֮�͵� Common::TimeSpan��
    TimeSpan operator +(TimeSpan &t1, TimeSpan &t2)
	{
		return  TimeSpan(t1._ticks+t2._ticks);
	}
    TimeSpan &operator +=(TimeSpan &t1, TimeSpan &t2)
	{
		return  t1=  TimeSpan(t1._ticks+t2._ticks);
	}
    //
    // ժҪ:
    //     ָʾָ���� Common::TimeSpan �Ƿ�С����һ��ָ���� Common::TimeSpan��
    //
    // ����:
    //   t2:
    //     TimeSpan��
    //
    //   t1:
    //     Common::TimeSpan��
    //
    // ���ؽ��:
    //     ��� t1 ��ֵС�� t2 ��ֵ����Ϊ true������Ϊ false��
    bool operator <(TimeSpan &t1, TimeSpan &t2)
	{
		return (t1._ticks<t2._ticks);
	}
    //
    // ժҪ:
    //     ָʾָ���� Common::TimeSpan �Ƿ�С�ڻ������һ��ָ���� Common::TimeSpan��
    //
    // ����:
    //   t2:
    //     TimeSpan��
    //
    //   t1:
    //     Common::TimeSpan��
    //
    // ���ؽ��:
    //     ��� t1 ��ֵС�ڻ���� t2 ��ֵ����Ϊ true������Ϊ false��
    bool operator <=(TimeSpan &t1, TimeSpan &t2)
	{
		return (t1._ticks<=t2._ticks);
	}
    //
    // ժҪ:
    //     ָʾ���� Common::TimeSpan ʵ���Ƿ���ȡ�
    //
    // ����:
    //   t2:
    //     TimeSpan��
    //
    //   t1:
    //     Common::TimeSpan��
    //
    // ���ؽ��:
    //     ��� t1 �� t2 ��ֵ��ȣ���Ϊ true������Ϊ false��
    bool operator ==(TimeSpan &t1, TimeSpan &t2)
	{
		return (t1._ticks==t2._ticks);
	}
    //
    // ժҪ:
    //     ָʾָ���� Common::TimeSpan �Ƿ������һ��ָ���� Common::TimeSpan��
    //
    // ����:
    //   t2:
    //     TimeSpan��
    //
    //   t1:
    //     Common::TimeSpan��
    //
    // ���ؽ��:
    //     ��� t1 ��ֵ���� t2 ��ֵ����Ϊ true������Ϊ false��
    bool operator >(TimeSpan &t1, TimeSpan &t2)
	{
		return (t1._ticks>t2._ticks);
	}
    //
    // ժҪ:
    //     ָʾָ���� Common::TimeSpan �Ƿ���ڻ������һ��ָ���� Common::TimeSpan��
    //
    // ����:
    //   t2:
    //     TimeSpan��
    //
    //   t1:
    //     Common::TimeSpan��
    //
    // ���ؽ��:
    //     ��� t1 ��ֵ���ڻ���� t2 ��ֵ����Ϊ true������Ϊ false��
    bool operator >=(TimeSpan &t1, TimeSpan &t2)
	{
		return (t1._ticks>=t2._ticks);
	}

#endif
    //
    // ժҪ:
    //     ����ctl�ļ������ݱ�:���ټ��ء������ļ�ͷ,������������
    //
    // ����:
    //   pCtlControlName:
    //     TimeSpan��
    //
    //   pCtlDataName:
    //     Common::TimeSpan��
	//
	//	pDbId:
    //
    // ���ؽ��:
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
		if(!parallel)cout<<"ִ��sqlldr����: "<<Command.c_str()<<endl;
		return Sqlldr(Command);
	}

	// ժҪ:
	//    ����sqlldrִ�е��룬�����ص������
	//
	// ����:
	//   pCommand:
	//     ִ�����
	//
	// ���ؽ��:
	//       -1 ʧ��
	//		0  �ɹ�����,��BAD�ļ�
	//		1  ���ݿ����У��ʧ�ܱ����ڻ��ֶβ�ƥ���
	//		2  ���벻��ȫ,����BAD�ļ�:�ֶ��쳣��
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
			printf("sqlldr���÷���ֵ:%d ��",ret) ;
			if( ret==0)
				printf("�ɹ�����,��BAD�ļ�\n") ;
			else if( ret==1)
				printf("����У��ʧ�ܣ������ڻ��ֶβ�ƥ���\n");
			else if( ret==2)
				printf("���벻��ȫ,����BAD�ļ�:�ֶ��쳣��\n") ;
		}
		return ret ;
	}

	// ժҪ:
	//    ����systemִ�г���,������ִ�����
	//
	// ����:
	//   pCommand:
	//		ִ�����
	//	pOutMsg:
	//		���������������Ϣ
	//	pRetValue:
	//		���ó���ķ���ֵ�����ڵ��óɹ�ʱ�вο��ԣ�
	//
	// ���ؽ��:
	//         true  �ɹ�
	//         false ʧ��
	bool System(string pCommand,string &pOutMsg,int& pRetValue)
	{
		int status , ret ;
		status = system(pCommand.c_str()) ;
		if((status & 0x7F)==0)
		{
			ret = status >>8 ;
			if( ret == 0x7F )
			{
				pOutMsg=String("���ó���[")+pCommand+"]������\n";
				return false ;
			}
			else
			{
				pRetValue = ret ;
				pOutMsg=String("�����������ý���,����ֵ��[")+ret+"]\n";
				return true ;
			}
		}
		else if( ((status & 0x80)^0x7F)==0 )
		{
			ret = status >>8 ;
			pOutMsg=String("���õ��ӳ����ж�,�����жϵ��ź���:")+ret+"]\n";
			return false ;
		}
		else if( ( ( (status&0x7F)+1)>>1) > 0 )
		{
			ret = status & 0x7F ;
			pOutMsg=String("���ź�[")+ret+"]�������\n";
			return false ;
		}
		else if( (status & 0x80) ==0 )
		{
			pOutMsg="����coredump";
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
				pOutMsg=String("���ó���[")+pCommand+"]������\n";
				return -1 ;
			}
			else
			{
				pOutMsg=String("�����������ý���,����ֵ��[")+ret+"]\n";
				return ret ;
			}
		}
		else if( ((status & 0x80)^0x7F)==0 )
		{
			ret = status >>8 ;
			pOutMsg=String("���õ��ӳ����ж�,�����жϵ��ź���:")+ret+"]\n";
			return -1 ;
		}
		else if( ( ( (status&0x7F)+1)>>1) > 0 )
		{
			ret = status & 0x7F ;
			pOutMsg=String("���ź�[")+ret+"]�������\n";
			return -1 ;
		}
		else if( (status & 0x80) ==0 )
		{
			pOutMsg="����coredump";
			return -1 ;
		}
		else
		{
			return -1;
		}
	}

#if OSTYPE>10
	//
	//ժҪ:
	//       Fork���ӽ��̴���ִ��һϵ������
	//����:
	//	lst_appName:
	//		ִ��������б�
	//
	int ForkRun(list<string> lst_appName)
	{
		int   p_id ;
		list<string>::iterator appIterator ;
		if((p_id=fork())>0)
		{
			//while(pidLen)			//ѭ���ȴ��ӽ��� pidLen �ӽ�����
			//{
			//	int stat;
			//	int rt;
			//	rt = wait(&stat);
			//	if (rt > 0)
			//	{
   // 				pidLen--;
   // 				if(stat)
   // 					return false;//�ӽ���ִ��ʧ��
			//		printf("Child %d exit status: %d\n", rt, WEXITSTATUS(stat));
			//	}
			//}
	//		int e, status;
	//      for(;;)	//�ȴ�
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
		else if(p_id==0)   //�ӽ��������ӽ���
		{
			for (appIterator=lst_appName.begin(); appIterator!=lst_appName.end();++appIterator)
			{
    			cout << *appIterator << endl;
    			system( (*appIterator).c_str()) ;
			}
			printf("�ӽ������\n");
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
		const char table_key[] ="��";
		const char read_key[] = "��ȡ���߼���¼����:";
		const char reject_key[]="�ܾ����߼���¼����:";
#endif

		if( (log_stream=fopen(log_file, "r" ))==NULL)
		{
			cout<< "SQL*Loader��־�ļ�[" << log_file <<"] open failed" <<endl;
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
			sprintf(s_temp,"SQL*Loader ʧ��,Ŀ���:[%s],��¼����:[%ld],�쳣��¼��:[%ld]\0",tableName,recordRead,recordReject);
		}
		if(bSuccess)
			sprintf(s_temp,"SQL*Loader �ɹ�,Ŀ���:[%s],��¼����:[%ld],�쳣��¼��:[%ld]\0",tableName,recordRead,recordReject);
		out_msg=s_temp;
		return bSuccess;
	}

}
