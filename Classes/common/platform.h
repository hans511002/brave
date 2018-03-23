// ==============================================================
//progame      Common namespace
//company      hans
//copyright    Copyright (c) hans  2007-2010
//version      1.0
//Author       hans
//date         2007-03
//description  Common namespace
//				This library is free software. Permission to use, copy,
//				modify and redistribute it for any purpose is hereby granted
//				without fee, provided that the above copyright notice appear
//				in all copies.
//				平台头文件
// ==============================================================
#ifndef __Common_Platform__
#define __Common_Platform__

#ifndef NDEBUG
//#define NDEBUG
#define DEBUG_COUT(X) X
#else
#define DEBUG_COUT(X) 
#endif

#ifndef COMPILE_MODE
#define COMPILE_MODE 32
#endif

#ifdef _MSC_VER
#define OSTYPE 10
#else 
#define OSTYPE 40
#endif

#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC
 
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
 
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
 
#elif CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include "mmsystem.h"
#elif CC_TARGET_PLATFORM == CC_PLATFORM_WP8 || CC_TARGET_PLATFORM == CC_PLATFORM_WINRT
 
#elif CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
 
#endif

#if OSTYPE<=10 && !defined(NDEBUG)
#define _CRTDBG_MAP_ALLOC
#ifndef _DEBUG
#define _DEBUG
#endif
#endif

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdarg.h>
#include <time.h>
#include "math.h"
#include <list>
#include <vector>
#include <map>
#include <set>
#include <limits.h>
#include <fcntl.h>
#include <ctype.h>
#include <signal.h>
#include <errno.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <sstream>
#include <stack> 
#include <cctype>   // isdigit()
#include <numeric>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/timeb.h>

using namespace std;

#if OSTYPE<=10
#ifndef WIN32
#define WIN32
#endif
#endif


#if OSTYPE>10
#pragma warning(disable:4786)
#if OSTYPE>31
#else
#include <sys/core.h>
#endif
# include <unistd.h>
# include <semaphore.h>
# include <sys/sem.h>
# include <sys/mman.h>
# include <sys/shm.h>
# include <sys/user.h>

# include <netinet/in.h>
# include <arpa/inet.h>
# include <dirent.h> 
# include <sys/dir.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/socket.h>
# include <sys/file.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <net/if.h>
# include <net/if_arp.h>
# include <termio.h>
# include <netdb.h>
# include <utime.h>
# include <sys/io.h>
# include <iconv.h>
# include <sys/time.h>
# include <sys/select.h>
#else
#pragma warning(disable:4786 4996 4018 4244 4267 4312 4819 4098 4638 4309; once : 4385 4311 ; error : 164 )

#include <new.h>
# include <sys/utime.h>
#include <sys/locking.h>
# include <io.h>
# include   <direct.h>
//# include   <dir.h>  
//# include <windows.h>				//windows平台函数
#include <ws2tcpip.h>
# include   <process.h>
# include   <share.h>
//#include <tchar.h>				//宽字符
//using namespace std;
//#define WIN32_LEAN_AND_MEAN		// 从 Windows 头中排除极少使用的资料
# include <LIMITS.H>
# include <eh.H>
//#include <Atalkwh.h> // for AppleTalk 协议
#if !defined(NDEBUG)
#define DEBUG_NEW new( _NORMAL_BLOCK, __FILE__, __LINE__ )
#include <crtdbg.h>
#pragma pack( push, 8 )
#include <imagehlp.h>
#pragma pack( pop, )
#endif



 
//#include "winport.h"
 
 



//Windows 系统引用定义 结束//
#endif


//函数统一
#if OSTYPE>10
#define SLEEP(x) usleep(1000 * x)
#define SEARCH_CMD "which "
#define POPEN(cmd,type) popen(cmd,type)
#define PCLOSE(file) pclose(file)
#define Pause()   {cout<<"请输入回车继续....";int c=getchar();}

#else
#define SLEEP(x) Sleep(x)
#define atoll _atoi64
#define SEARCH_CMD "where "
#define POPEN(cmd,type) _popen(cmd,type)
#define PCLOSE(file) _pclose(file)
#define Pause()   system("pause")
#endif
//
//namespace Common
//{
//	class DateTime;
//	class TimeSpan;
//
//	static int blog_buffer_size=32760;
//	static char * version="1.0";
//	static int defaultPrintUnit=200000;
//	static int defaultPreFetch=10000;
//	static int defaultBuffSize=30000;
//
//}
//int   truncate(const   char   *path,   off_t   length); 
//int   ftruncate(int   fd,   off_t   length); 


//handle   =   fileno(fp);                   //   使用fileno()将FILE结构转换成文件句柄 
//chsize(handle,   8);

#if OSTYPE>31	//	gcc
#define STDSPACE 
#else
#define STDSPACE std
#endif


#endif

