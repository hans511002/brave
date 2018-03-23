///	<summary>
///	C/C++编程基础类
/// <para>
/// </para>
///	<code>
/// ==============================================================
///progame      public Common namespace
///company      hans
///copyright    Copyright (c) hans  2007-4 
///version      1.2
///Author       hans
///date         2006     2015
///description  Common namespace
///				This library is free software. Permission to use, copy,
///				modify and redistribute it for any purpose is hereby granted
///				without fee, provided that the above copyright notice appear
///				in all copies.
///				
///				this include boost thread、otl and so on third-party open source libraries
/// ==============================================================
/// 作 者: 邹远贵
/// 日 期: 2006-11-25
/// 版 本: 1.0
///
///	</code>
///	</summary>
/// <example><code>  
///	#include &lt;Common.h>
///	using namespace Common;
/// </code></example>
//
#ifndef __Common_H__
#define __Common_H__

//警告等级
#pragma warning( push ,2)
#ifdef UNICODE
#undef UNICODE
#endif
//#ifndef NDEBUG
//#define NDEBUG
//#endif
#include "CCStdC.h"
using namespace std;
#include "platform.h"



#ifndef NDEBUG
//#define NDEBUG
#define DEBUG_COUT(X) X
#else
#define DEBUG_COUT(X) 
#endif
  
#define ROUND8(x)     (((x)+7)&~7)
#define ROUND4(x)     (((x)+3)&~3)
 
namespace Common
{
	class String;
	class Log;
	class DateTime;
	class TimeSpan;
	class Convert;
	class ArgsParse;

	typedef void (*WriteLogFun)(const String& msg,int type);
	    
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
#include "md5.h"
#include "Enums.h"
#include "Convert.h"
#include "hashMath.h"
#include "Encoding.h"	//编码
#include "Decoding.h"
#include "String.h"	//字符串
#include "Functions.h"	//	普通函数
#include "DateTimeFun.h"	//	时间类
#include "TimeSpan.h"	//时间片
#include "DateTime.h"	//时间
#include "DateTimer.h"//计时器
#include "DirectoryInfo.hpp"//目录文件
#include "FileInfo.hpp"
#include "ArgsParse.h"//参数解析
#include "Log.h"//日志 
#include "strCoding.h"	//字符串
	 

     
#include "HashTable.hpp"
#include "MulHashTable.hpp"
#include "MulHashTable2.hpp"
#include "HashTable2.hpp"		//	单值，多值，单链表存储

 
//数字键做hashKey
#include "numMap.hpp"
//hashFile
#ifndef HASH_CHECK_LEVEL
#define HASH_CHECK_LEVEL 3			// hashcode 校验次数 HASH_CHECK_LEVEL=0 当为数字时不使用hash
#endif

#include "BTree.hpp"	//二叉树
    
#include "CalcExp.h"			//	简单表达式计算									#include "CalcLogic.h"			//	逻辑表达式计算
#include "Eval.h"				//	动态计算 升级,包括函数调用和变量传递			#include "EvalCalc.h"			//	动态计算
#include "ExpEval.h"			//	lemon 词法解析程序生成的表达式计算
 

#include "NetConstDefine.h"		//	网络部分
#include "IPAddress.h"
#include "Socket.h"
#include "NetworkStream.h"
#include "TcpClient.h"
#include "UdpClient.h"
#include "TcpListener.h"

#include "FTP.h"  //应用Socket


//
namespace Common
{
	//幂运算
	inline double pow(int x,int y)
	{
		return ::pow((double)x,y);
	};
	#define ATO(T,T_type) inline void ato_t(T &t,char * s)		\
	{                                                           \
		switch(T_type)                                          \
		{                                                       \
			case 3:/*int*/                                      \
			sscanf(s,"%d",&t);break;                            \
			case 31:/*unsigned int*/                            \
			sscanf(s,"%u",&t);break;                            \
			case 4:/*DOUBLE*/                                   \
			sscanf(s,"%f",&t);break;                            \
			case 20:/*long*/                                    \
			sscanf(s,"%ld",&t);break;                           \
			case 201:/*unsigned long*/                          \
			sscanf(s,"%lu",&t);break;                           \
			case 64:/*long long*/                               \
			sscanf(s,"%lld",&t);break;                          \
			case 641:/*unsigned long long*/                     \
			sscanf(s,"%llu",&t);break;                          \
		}                                                       \
	}
	///	<summary>
	///	字符串到int类型转换
	///	<code>原型：void ato_t(int &amp;t,char *s);</code>
	///	</summary>
	///	<param name="t"><see cref="int"/></param>
	///	<param name="s"><see cref="char"/></param>
	inline void ato_t(int &t, char * s) 
	{ 
		 sscanf(s, "%u", &t);
	}
	///	<summary>
	///	字符串到unsigned int类型转换
	///	<code>原型：void ato_t(unsigned int &amp;t,char *s);</code>
	///	</summary>
	///	<param name="t"><see cref="unsigned int"/></param>
	///	<param name="s"><see cref="char"/></param>
 	inline void ato_t(unsigned int &t, char * s)
	{
		sscanf(s, "%d", &t);
	}
	///	<summary>
	///	字符串到double类型转换
	///	<code>原型：void ato_t(double &amp;t,char *s);</code>
	///	</summary>
	///	<param name="t"><see cref="double"/></param>
	///	<param name="s"><see cref="char"/></param>
	inline void ato_t(double &t, char * s)
	{
		//sscanf(s, "%lf", &t);
		float f=0;
		sscanf(s, "%f", &f);
		t = f;
	}
	///	<summary>
	///	字符串到long类型转换
	///	<code>原型：void ato_t(long &amp;t,char *s);</code>
	///	</summary>
	///	<param name="t"><see cref="long"/></param>
	///	<param name="s"><see cref="char"/></param>
	inline void ato_t(long &t, char * s)
	{
		sscanf(s, "%ld", &t);
	}
	///	<summary>
	///	字符串到unsigned long类型转换
	///	<code>原型：void ato_t(unsigned long &amp;t,char *s);</code>
	///	</summary>
	///	<param name="t"><see cref="unsigned long"/></param>
	///	<param name="s"><see cref="char"/></param>
	inline void ato_t(unsigned long &t, char * s)
	{
		sscanf(s, "%lu", &t);
	}
	///	<summary>
	///	字符串到long long类型转换
	///	<code>原型：void ato_t(long long &amp;t,char *s);</code>
	///	</summary>
	///	<param name="t"><see cref="long long"/></param>
	///	<param name="s"><see cref="char"/></param>
	inline void ato_t(long long &t, char * s)
	{
		sscanf(s, "%lld", &t);
	}
	///	<summary>
	///	字符串到unsigned long long类型转换
	///	<code>原型：void ato_t(unsigned long long &amp;t,char *s);</code>
	///	</summary>
	///	<param name="t"><see cref="unsigned long long"/></param>
	///	<param name="s"><see cref="char"/></param>
	inline void ato_t(unsigned long long &t, char * s)
	{
		sscanf(s, "%llu", &t);
	}
	///	<summary>
	///	获取系统错误信息
	///	<code>原型：void ato_t(unsigned long long &amp;t,char *s);</code>
	///	</summary>
	///	<param name="t"><see cref="unsigned long long"/></param>
	///	<param name="s"><see cref="char"/></param>
	inline String GetErrorMsg(){return strerror(errno);}
	///	<summary>
	///	计算表达式
	///	<code>原型：inline double cal(const string &amp;s);</code>
	///	</summary>
	///	<param name="s"><see cref="字符串表达式"/></param>
	///	<returns>计算结果</returns>
	inline double cal(const string &s)
	{
		return calcExp<int>().cal(s);
	};
	///	<summary>
	///	获取程序启动命令中的路径部分
	///	<code>原型：inline String getAppPath(char *argv[]);</code>
	///	</summary>
	///	<param name="argv">程序运行输入参数集</param>
	///	<returns>程序启动命令中的路径</returns>
	inline String getAppPath(char *argv[])
	{
		String path=argv[0];//Path::DirectorySeparatorChar
		if(path.LastIndexOf("/")>0)
		{
			return path.SubString(0,path.LastIndexOf("/")+1);
		}
		else if(path.LastIndexOf("\\")>0)
		{
			return path.SubString(0,path.LastIndexOf("\\")+1);
		}
		else
		{
			return "";
		}
	};
	//子进程退出状态检查,抛出错误异常
	inline int checkSubProExit(int &status)
	{
#if OSTYPE>10
		if (WIFEXITED(status))
		{
			status=WEXITSTATUS(status);
			return status;
		}
		else if (WIFSIGNALED(status))
		{
			status=WTERMSIG(status);
#if defined(WCOREDUMP)
			EXP(String("[ERROR]子程序异常结束 ,软中断号 =")+status+( WCOREDUMP(status) ? " (产生了core文件)" :""));
#else
			EXP(String("[ERROR]子程序异常结束 ,软中断号 =")+status);
#endif
			return -1;
		}
		else if (WIFSTOPPED(status))
		{
			status=WSTOPSIG(status);
			EXP(String("[ERROR]子程序异常结束 ,软中断号 =")+status);
			return -1;
		}
		return -1;
#else
		return status;
#endif
	}

	//子进程退出状态检查,通过参数返回错误信息
	inline int checkProExit(int &status,string &msg)
	{
#if OSTYPE>10
		char Err_Msg[256];
		if (WIFEXITED(status))
		{
			status=WEXITSTATUS(status);
			sprintf(Err_Msg,"[INFO]子程序正常结束 ,结束状态 = %d",status);
			msg=Err_Msg;
			return status;
		}
		else if (WIFSIGNALED(status))
		{
			status=WTERMSIG(status);
			sprintf(Err_Msg,"[ERROR]子程序异常结束 ,软中断号 = %d%s",status,
#if defined(WCOREDUMP)
				WCOREDUMP(status) ? " (产生了core文件)" :"");
#else
			  "");
#endif
			msg=Err_Msg;
			return -1;
		}
		else if (WIFSTOPPED(status))
		{
			status=WSTOPSIG(status);
			sprintf(Err_Msg,"[ERROR]子程序停止运行,软中断号 = %d",status);
			msg=Err_Msg;
			return -1;
		}
		return -1;
#else
		return status;
#endif
	}

	//回收子进程
	inline void sigchld(int sig)
	{
#if OSTYPE>10
		pid_t pid;
		int status;
		/* Reap defunct children until there aren't any more. */
		for (;;) //循环非阻塞，取出死进程清理
		{
			pid = waitpid( (pid_t) -1, &status, WNOHANG ); //-1表示第一个中止的子进程，WNOHANG表示非阻塞
			if (pid==0) //没有有待回收的了
				break;
			if (pid<0)
			{
				/* because of ptrace */
				if (errno==EINTR) 
					continue;
				break;
			}
		}
#endif
	}
	///	<summary>
	///	屏蔽子线程信号 windows不存在
	///	<code>原型：inline void shieldSigs();</code>
	///	</summary> 
	inline void shieldSigs()
	{
#if OSTYPE>10
		sigset_t emptyset,fillset;
		sigfillset( &fillset );			//	填充所有信号
		sigprocmask( SIG_BLOCK, &fillset, NULL );
		//sigemptyset( &emptyset );
		//for(int i=1;i<=36; i++)
		//{   //对子线程屏蔽所有信号
		//	sigaddset( &emptyset, i );
		//}
		//pthread_sigmask( SIG_BLOCK, &fillset, NULL );
#endif
	}
	//分离自己
	inline int detachSelf()
	{
#if OSTYPE>10
		return pthread_detach(pthread_self());
#endif
		return 0;
	}
	inline void sigterm(int sign_um)
	{
		exit(EXIT_FAILURE);
	}
	//signal(SIGTERM,sigterm);//handle kill
	//signal(SIGINT,sigterm); //handle ctrl-c

	///	<summary>
	///	信号处理类
	///	</summary> 
	/// <example><code>signal(SIGTERM,sig_adapter(reset));//handle kill
	///	sig_adapter sigPro(reset);
	///	signal(SIGTERM,sig_adapter);
	///	</code>
	///	</example>
	class sig_adapter
	{
		void (*_func)(int);
	public:
		///	<summary>
		///	以无返回值的函数指针初始化
		///	</summary> 
		sig_adapter(void (*func)(int)):_func(func){};
		///	<summary>
		///	运行伪函数
		///	</summary> 
		void operator()(int sign_um) const
		{
			_func(sign_um);
		};
	};

}

#endif
