// ==============================================================
//progame      Common::DateTime 
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

#ifndef __Common_DateTimer_H__ 
#define __Common_DateTimer_H__
//#include "Common.h"
namespace Common
{
	//计时器
	class DateTimer:public DateTime
	{
	protected:
		inline unsigned long long _getNow()
		{
			unsigned long long tl=0;
#if OSTYPE>10
			struct timeval tv;
			struct timezone stz;
			gettimeofday (&tv ,&stz);
			int tz=(0-stz.tz_minuteswest)/60;
			//组合计算时区
			tl=32+tz;
			tl=tl<<59;		//	留5位时区标识
			return tl=(tl|DateTime::TicksPerUTCSta+ tv.tv_sec * DateTime::TicksPerSecond+tv.tv_usec);	//微秒
#else
			//int l=(GetCycleCount() /2660) % 1000000;			//	精确到微秒

			time_t  ts=time(NULL);
			int lHour=localtime(&ts)->tm_hour;		
			int tz=  TimeZone(lHour-gmtime(&ts)->tm_hour);
			//组合计算时区
			tl=32+tz;
			tl=tl<<59;		//	留5位时区标识

			unsigned long long l=GetPerformanceCounter();
			l = (((l * DateTime::TicksPerSecond ) / GetPerformanceUnit() )% DateTime::TicksPerSecond);	//	精确到微秒,性能低
			time_t t= time(NULL);
			return tl=tl | DateTime::TicksPerUTCSta+ (unsigned long long)t * DateTime::TicksPerSecond+l;
#endif
		}

	public :
		DateTimer(DateTime dt)
		{
			this->_Ticks=dt.GetTimeZone();
			this->_Ticks=((_Ticks+32)<<59)|dt.GetTicks();
		};
		DateTimer()
		{
			this->_Ticks=_getNow();
		};
		void start()
		{
			this->_Ticks=_getNow();
		};
		TimeSpan stop()
		{
			unsigned long long st=this->_getNow(); 
			return TimeSpan(st-this->_Ticks);
		};
	};
}
#endif
//
