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
		//	��������ڴ�й¶�Ĺ��ܡ�
		static void vCheckMemoryLeak();
		//	��WINDOWS�еĽṹ���쳣ת��ΪC++�쳣��
		static void vMapSEHtoCE();
		//	ʹnew����ʧ��ʱ�׳��쳣��
		static void vSetThrowNewException();
		//	�ø����������׳��쳣
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
	///	�쳣��Ϣ��
	///	</summary>
	///	<remarks>
	///	���ڳ���ִ�����쳣��Ϣ�Ĳ����봫��
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
		///	�洢�쳣������Ϣ
		///	</summary>
		string Message;
		Exception(){};
		///	<summary>
		///	���������캯��������ָ����������������������ʼ����������
		///	<code>ԭ�ͣ�Exception(string s);</code>
		///	</summary>
		///	<param name="s">�쳣������Ϣ</param>
		inline Exception(string s)
		{
			this->Message = s;
		};
		///	<summary>
		///	��ȡ�쳣��Ϣ����ָ��
		///	<code>ԭ�ͣ�const char  * GetMessage();</code>
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

