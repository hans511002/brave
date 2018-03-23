#ifndef __Common_INCHEAD_H__ 
#define __Common_INCHEAD_H__
//平台库
#include "platform.h"	//	_MSC_VER

#define ROUND8(x)     (((x)+7)&~7)

namespace Common
{
	class String;
	class Log;
	class DateTime;
	class TimeSpan;
	class Convert;
	class ArgsParse;

	static int blog_buffer_size=32760;
	static char * copyRight="Copyright  2006-2010 Athor:hans";
	static char * version="1.0";
	static int defaultPrintUnit=200000;
	static int defaultPreFetch=10000;
	static int defaultBuffSize=30000;

	namespace net
	{
		using namespace Common;
		class SocketType;
		class SocketAsyncOperation;
	}
#define NET_NAMESPACE_BEGIN namespace net{
#define NET_NAMESPACE_END	}
}

#include "Exception.h"
#include "Array.h"
#include "Convert.h"
#include "hashMath.h"
#include "Enums.h"
#include "String.h"	//字符串

#if CPP_FILE == 1											//	ArgsParse.cpp
#include "DateTimeFun.h"	//	时间类
#include "TimeSpan.h"	//时间片
#include "DateTime.h"	//时间
#include "DateTimer.h"//计时器
#include "Log.h"//日志
#include "ArgsParse.h"//参数解析

#elif CPP_FILE==2											//	DirectoryInfo.cpp
#include "Functions.h"	//	普通函数
#include "DateTimeFun.h"	//	时间类
#include "TimeSpan.h"	//时间片
#include "DateTime.h"	//时间
#include "DateTimer.h"//计时器
#include "DirectoryInfo.hpp"//目录文件
#include "FileInfo.hpp"
#elif CPP_FILE==3											//	FTP.cpp
#include "Functions.h"	//	普通函数
#include "DateTimeFun.h"	//	时间类
#include "TimeSpan.h"	//时间片
#include "DateTime.h"	//时间
#include "DateTimer.h"//计时器
#include "DirectoryInfo.hpp"//目录文件
#include "FileInfo.hpp"
#include "NetConstDefine.h"		//	网络部分
#include "IPAddress.h"
#include "Socket.h"
#include "NetworkStream.h"
#include "TcpClient.h"
#include "UdpClient.h"
#include "TcpListener.h"

#include "FTP.h"  //应用Socket
#elif CPP_FILE==4											//FtpClient.cpp
#include "FtpClient.h"	//unix FTP
#elif CPP_FILE==5											 
#elif CPP_FILE==6											//md5.cpp
#include "md5.h"	
#elif CPP_FILE==7											//NetConstDefine.cpp
#include "NetConstDefine.h"		//	网络部分
#include "IPAddress.h"
#include "Socket.h"
#include "NetworkStream.h"
#include "TcpClient.h"
#include "UdpClient.h"
#include "TcpListener.h"
#elif CPP_FILE==8											//ShareMemory.cpp
#include "md5.h"	
#include "Functions.h"	//	普通函数
#include "DateTimeFun.h"	//	时间类
#include "TimeSpan.h"	//时间片
#include "DateTime.h"	//时间
#include "DateTimer.h"//计时器
#include "DirectoryInfo.hpp"//目录文件
#include "FileInfo.hpp"
#include "ShareMemory.h"
#include "SemaphoreMutex.h"
#elif CPP_FILE==9											//Socket.cpp
#include "Functions.h"	//	普通函数
#include "DateTimeFun.h"	//	时间类
#include "TimeSpan.h"	//时间片
#include "DateTime.h"	//时间
#include "DateTimer.h"//计时器
#include "DirectoryInfo.hpp"//目录文件
#include "FileInfo.hpp"
#include "NetConstDefine.h"		//	网络部分
#include "IPAddress.h"
#include "Socket.h"
#include "NetworkStream.h"
#include "TcpClient.h"
#include "UdpClient.h"
#include "TcpListener.h"

#elif CPP_FILE==10											//String.cpp

#elif CPP_FILE==11											//NetConstDefine.cpp
#elif CPP_FILE==12											//NetConstDefine.cpp

#endif
#endif
