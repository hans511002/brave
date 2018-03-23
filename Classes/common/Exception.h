// ==============================================================
//progame      Common::Exception  simple exception class
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

#ifndef __Common_Exception_H__
#define __Common_Exception_H__
 
namespace Common
{
#if OSTYPE<=10 && !defined(NDEBUG)
	static string ShowStack( HANDLE hThread, CONTEXT& c ); // dump a stack
	class CWinUtil 
	{
	private:
		CWinUtil();
	public:
		//	启动检查内存泄露的功能。
		static void vCheckMemoryLeak();
		//	把WINDOWS中的结构化异常转化为C++异常。
		static void vMapSEHtoCE();
		//	使new函数失败时抛出异常。
		static void vSetThrowNewException();
		//	让浮点数错误抛出异常
		static void vSetThrowFloatException();
		static void vSetUnExpectedExceptionFilter();
		static int NewHandler( size_t size );
		static void vInitStackEnviroment();
	private:
		static void _cdecl TranslateSEHtoCE( UINT code, PEXCEPTION_POINTERS pep ) ;
		static long _stdcall UnExpectedExceptionFilter( LPEXCEPTION_POINTERS pe ); 
	};
#endif
	///	<summary>
	///	异常信息类
	///	</summary>
	///	<remarks>
	///	用于程序执行中异常信息的捕获与传递
	///	</remarks>
    /// <example><code>
    /// </code></example>
	class Exception:public std::exception
	{
	public:
#if OSTYPE<=10 && !defined(NDEBUG)
		UINT m_exceptionCode;
		EXCEPTION_RECORD m_exceptionRecord;
		CONTEXT m_context;
		Exception(UINT code, PEXCEPTION_POINTERS pep );
		static String GetName(DWORD dwCode);
		static String GetDescription(DWORD dwCode);
		operator unsigned int() { return m_exceptionCode; }
#endif
		const char* what(){ return Message.c_str();	}
		///	<summary>
		///	存储异常描述信息
		///	</summary>
		string Message;
		Exception(){};
		///	<summary>
		///	解析对象构造函数，用于指定参数及参数检验条件初始化解析对象
		///	<code>原型：Exception(string s);</code>
		///	</summary>
		///	<param name="s">异常描述信息</param>
		inline Exception(string s)
		{
			this->Message = s;
		};
		///	<summary>
		///	获取异常信息数据指针
		///	<code>原型：const char  * GetMessage();</code>
		///	</summary>
		const char  * GetMessage()
		{
			return this->Message.c_str();
		}
		~Exception()throw (){};
	};

	inline ostream& operator<<(ostream& target, const Exception& s)
	{
		target << s.Message;
		return target;
	};
	inline static string getErrMsg(){return strerror(errno);};
	inline static string getErrMsg(int errCode){return strerror(errCode);};
	inline int getErrCode(){return errno;};
}
#ifndef EXP
#define EXP(msg) {Common::String MSG=Common::String(__FILE__)+Common::String(":")+Common::String(__LINE__)+Common::String("\n");/* cout<<__FILE__<<": error  on line "<< __LINE__<<endl ;*/throw Exception(MSG+Common::String(msg));}
#endif
#ifndef PERR
#define PERR(msg) cout<<__FILE__<<msg<<":"<< " error on line "<< __LINE__<<endl ;
#endif
#ifndef ERR_FILE_LINE
#define ERR_FILE_LINE "ERROR:"+Common::String(__FILE__)+":"+ " on line "+Common::String(__LINE__)
#endif

#endif

