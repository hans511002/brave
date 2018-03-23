///	<summary>
///	C/C++��̻�����
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
///				this include boost thread��otl and so on third-party open source libraries
/// ==============================================================
/// �� ��: ��Զ��
/// �� ��: 2006-11-25
/// �� ��: 1.0
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

//����ȼ�
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
#include "Encoding.h"	//����
#include "Decoding.h"
#include "String.h"	//�ַ���
#include "Functions.h"	//	��ͨ����
#include "DateTimeFun.h"	//	ʱ����
#include "TimeSpan.h"	//ʱ��Ƭ
#include "DateTime.h"	//ʱ��
#include "DateTimer.h"//��ʱ��
#include "DirectoryInfo.hpp"//Ŀ¼�ļ�
#include "FileInfo.hpp"
#include "ArgsParse.h"//��������
#include "Log.h"//��־ 
#include "strCoding.h"	//�ַ���
	 

     
#include "HashTable.hpp"
#include "MulHashTable.hpp"
#include "MulHashTable2.hpp"
#include "HashTable2.hpp"		//	��ֵ����ֵ��������洢

 
//���ּ���hashKey
#include "numMap.hpp"
//hashFile
#ifndef HASH_CHECK_LEVEL
#define HASH_CHECK_LEVEL 3			// hashcode У����� HASH_CHECK_LEVEL=0 ��Ϊ����ʱ��ʹ��hash
#endif

#include "BTree.hpp"	//������
    
#include "CalcExp.h"			//	�򵥱��ʽ����									#include "CalcLogic.h"			//	�߼����ʽ����
#include "Eval.h"				//	��̬���� ����,�����������úͱ�������			#include "EvalCalc.h"			//	��̬����
#include "ExpEval.h"			//	lemon �ʷ������������ɵı��ʽ����
 

#include "NetConstDefine.h"		//	���粿��
#include "IPAddress.h"
#include "Socket.h"
#include "NetworkStream.h"
#include "TcpClient.h"
#include "UdpClient.h"
#include "TcpListener.h"

#include "FTP.h"  //Ӧ��Socket


//
namespace Common
{
	//������
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
	///	�ַ�����int����ת��
	///	<code>ԭ�ͣ�void ato_t(int &amp;t,char *s);</code>
	///	</summary>
	///	<param name="t"><see cref="int"/></param>
	///	<param name="s"><see cref="char"/></param>
	inline void ato_t(int &t, char * s) 
	{ 
		 sscanf(s, "%u", &t);
	}
	///	<summary>
	///	�ַ�����unsigned int����ת��
	///	<code>ԭ�ͣ�void ato_t(unsigned int &amp;t,char *s);</code>
	///	</summary>
	///	<param name="t"><see cref="unsigned int"/></param>
	///	<param name="s"><see cref="char"/></param>
 	inline void ato_t(unsigned int &t, char * s)
	{
		sscanf(s, "%d", &t);
	}
	///	<summary>
	///	�ַ�����double����ת��
	///	<code>ԭ�ͣ�void ato_t(double &amp;t,char *s);</code>
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
	///	�ַ�����long����ת��
	///	<code>ԭ�ͣ�void ato_t(long &amp;t,char *s);</code>
	///	</summary>
	///	<param name="t"><see cref="long"/></param>
	///	<param name="s"><see cref="char"/></param>
	inline void ato_t(long &t, char * s)
	{
		sscanf(s, "%ld", &t);
	}
	///	<summary>
	///	�ַ�����unsigned long����ת��
	///	<code>ԭ�ͣ�void ato_t(unsigned long &amp;t,char *s);</code>
	///	</summary>
	///	<param name="t"><see cref="unsigned long"/></param>
	///	<param name="s"><see cref="char"/></param>
	inline void ato_t(unsigned long &t, char * s)
	{
		sscanf(s, "%lu", &t);
	}
	///	<summary>
	///	�ַ�����long long����ת��
	///	<code>ԭ�ͣ�void ato_t(long long &amp;t,char *s);</code>
	///	</summary>
	///	<param name="t"><see cref="long long"/></param>
	///	<param name="s"><see cref="char"/></param>
	inline void ato_t(long long &t, char * s)
	{
		sscanf(s, "%lld", &t);
	}
	///	<summary>
	///	�ַ�����unsigned long long����ת��
	///	<code>ԭ�ͣ�void ato_t(unsigned long long &amp;t,char *s);</code>
	///	</summary>
	///	<param name="t"><see cref="unsigned long long"/></param>
	///	<param name="s"><see cref="char"/></param>
	inline void ato_t(unsigned long long &t, char * s)
	{
		sscanf(s, "%llu", &t);
	}
	///	<summary>
	///	��ȡϵͳ������Ϣ
	///	<code>ԭ�ͣ�void ato_t(unsigned long long &amp;t,char *s);</code>
	///	</summary>
	///	<param name="t"><see cref="unsigned long long"/></param>
	///	<param name="s"><see cref="char"/></param>
	inline String GetErrorMsg(){return strerror(errno);}
	///	<summary>
	///	������ʽ
	///	<code>ԭ�ͣ�inline double cal(const string &amp;s);</code>
	///	</summary>
	///	<param name="s"><see cref="�ַ������ʽ"/></param>
	///	<returns>������</returns>
	inline double cal(const string &s)
	{
		return calcExp<int>().cal(s);
	};
	///	<summary>
	///	��ȡ�������������е�·������
	///	<code>ԭ�ͣ�inline String getAppPath(char *argv[]);</code>
	///	</summary>
	///	<param name="argv">�����������������</param>
	///	<returns>�������������е�·��</returns>
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
	//�ӽ����˳�״̬���,�׳������쳣
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
			EXP(String("[ERROR]�ӳ����쳣���� ,���жϺ� =")+status+( WCOREDUMP(status) ? " (������core�ļ�)" :""));
#else
			EXP(String("[ERROR]�ӳ����쳣���� ,���жϺ� =")+status);
#endif
			return -1;
		}
		else if (WIFSTOPPED(status))
		{
			status=WSTOPSIG(status);
			EXP(String("[ERROR]�ӳ����쳣���� ,���жϺ� =")+status);
			return -1;
		}
		return -1;
#else
		return status;
#endif
	}

	//�ӽ����˳�״̬���,ͨ���������ش�����Ϣ
	inline int checkProExit(int &status,string &msg)
	{
#if OSTYPE>10
		char Err_Msg[256];
		if (WIFEXITED(status))
		{
			status=WEXITSTATUS(status);
			sprintf(Err_Msg,"[INFO]�ӳ����������� ,����״̬ = %d",status);
			msg=Err_Msg;
			return status;
		}
		else if (WIFSIGNALED(status))
		{
			status=WTERMSIG(status);
			sprintf(Err_Msg,"[ERROR]�ӳ����쳣���� ,���жϺ� = %d%s",status,
#if defined(WCOREDUMP)
				WCOREDUMP(status) ? " (������core�ļ�)" :"");
#else
			  "");
#endif
			msg=Err_Msg;
			return -1;
		}
		else if (WIFSTOPPED(status))
		{
			status=WSTOPSIG(status);
			sprintf(Err_Msg,"[ERROR]�ӳ���ֹͣ����,���жϺ� = %d",status);
			msg=Err_Msg;
			return -1;
		}
		return -1;
#else
		return status;
#endif
	}

	//�����ӽ���
	inline void sigchld(int sig)
	{
#if OSTYPE>10
		pid_t pid;
		int status;
		/* Reap defunct children until there aren't any more. */
		for (;;) //ѭ����������ȡ������������
		{
			pid = waitpid( (pid_t) -1, &status, WNOHANG ); //-1��ʾ��һ����ֹ���ӽ��̣�WNOHANG��ʾ������
			if (pid==0) //û���д����յ���
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
	///	�������߳��ź� windows������
	///	<code>ԭ�ͣ�inline void shieldSigs();</code>
	///	</summary> 
	inline void shieldSigs()
	{
#if OSTYPE>10
		sigset_t emptyset,fillset;
		sigfillset( &fillset );			//	��������ź�
		sigprocmask( SIG_BLOCK, &fillset, NULL );
		//sigemptyset( &emptyset );
		//for(int i=1;i<=36; i++)
		//{   //�����߳����������ź�
		//	sigaddset( &emptyset, i );
		//}
		//pthread_sigmask( SIG_BLOCK, &fillset, NULL );
#endif
	}
	//�����Լ�
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
	///	�źŴ�����
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
		///	���޷���ֵ�ĺ���ָ���ʼ��
		///	</summary> 
		sig_adapter(void (*func)(int)):_func(func){};
		///	<summary>
		///	����α����
		///	</summary> 
		void operator()(int sign_um) const
		{
			_func(sign_um);
		};
	};

}

#endif
