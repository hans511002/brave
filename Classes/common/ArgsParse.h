// ==============================================================
//progame      Common::ArgsParse 
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

#ifndef __Common_ArgsParse__
#define __Common_ArgsParse__
//#include "Common.h"
namespace Common
{

	///	<summary>
	///	������������洢�ṹ�塣
	///	</summary>
	///	<remarks>
	///	���������������������洢�ṹ�壬���ڴ洢������ʽ�������Ϣ��ʹ�ü�<see cref="ArgsParse"/>
	///	</remarks>
    /// <example><code>
	///	const ArgItem items[]={	{"-d","���ڲ���","�����滻�����еĺ����",0,Common::INT,6},
	///						  };
	///	ArgsParse pars;
	///	if(!pars.parse(argc,argv,items,1))exit(1);
	///	
    /// </code></example>
	struct ArgItem
	{
		///	<summary>
		///	ǰ׺
		///	</summary>
		String prefix		;
		///	<summary>
		///	����
		///	</summary>
		String name			;
		///	<summary>
		///	����
		///	</summary>
		String desc			;
		///	<summary>
		///	�Ƿ����	0:��ѡ,1:����,2...����ID,��ʾ���в�������,������һ������
		///	</summary>
		int needType		;
		///	<summary>
		///	��Ҫ��֤������ ��ֵ֤�Ƿ���ת��ΪĿ������
		///	</summary>
		varType  valueType	;
		///	<summary>
		///	��Ҫ��ֵ����
		///	</summary>
		int length			;
		String defaultVal ;
		ArgItem(){};//"-r","ȷ�Ϲر�","�Ƿ�رչ����ڴ棬ˢ�����ݵ�����",1,Common::NONE,0
		ArgItem(String _prefix,String _name,String _desc,int _needType,varType  _valueType,int _length)
			:prefix(_prefix),name(_name),desc(_desc),needType(_needType),valueType(_valueType),length(_length){};
	} ;
	///	<summary>
	///	����������
	///	</summary>
	///	<remarks>
	///	�����в���������,��Ҫʹ�ýṹ��<see cref="ArgItem"/>
	///	-h -version FULLPATH APPNAME APPPATH DEBUG -DEBUG �Ѿ�Ĭ�ϱ���ʹ��
	///	</remarks>
    /// <example><code>
	///	Ӧ�������в���������
	///	const ArgItem items[]={	{"-d","���ڲ���","�����滻�����еĺ����",0,Common::INT,6},
	///						  };
	///	ArgsParse pars;
	///	if(!pars.parse(argc,argv,items,2))exit(1);
	///	String month_no=pars.getStr("-d");s
	///	int monthNo=pars.getInt("-d");
    /// </code></example>
	class ArgsParse
	{
		int _argc;
		char **_argv;
		map<String,ArgItem>		argItems ;
		map<String,String>		paramsValue ;
		Log *log;
		String appVer;
	public:
		ArgsParse(char * ver=NULL)
		{
			if(ver)appVer=ver;
		};
		///	<summary>
		///	���������캯��������ָ����������������������ʼ����������
		///	<code>ԭ�ͣ�ArgsParse(int argc=0,char *argv[]=NULL,const ArgItem items[]=NULL,int _count=0,Log *log=NULL);</code>
		///	</summary>
		///	<param name="argc">�����в�����������Ӧ�������argv����</param>
		///	<param name="argv">����������������ַ���ָ������</param>
		///	<param name="items">������ʽ����Ϣ�ṹ���飬���ڼ����������</param>
		///	<param name="_count">������ʽ����Ϣ�ṹ���鳤��</param>
		///	<param name="log">��־����ָ�룬������־���</param>
		ArgsParse(int argc,char *argv[],const ArgItem items[]=NULL,int _count=0,Log *log=NULL)
		{
			argItems.clear();
			paramsValue.clear();
			this->_argc=argc;
			this->_argv=argv;
			this->log=log;
			if(items)
				addParam(items,_count);
		};
		///	<summary>
		///	���������������������ڶ������ͷ���Դ
		///	<code>ԭ�ͣ�~ArgsParse();</code>
		///	</summary>
		~ArgsParse(){clear();};
		///	<summary>
		///	��ӡ��ʾ��Ϣ
		///	<code>ԭ�ͣ�void paramsTip(String msg="");</code>
		///	</summary>
		///	<param name="msg">���ӵ�Ҫ��ӡ����ʾ��Ϣ</param>
		void paramsTip(String msg="");
 
		///	<summary>
		///	������־����ָ��
		///	<code>ԭ�ͣ�void setLog(Log *log);</code>
		///	</summary>
		///	<param name="log">��־����<see cref="Log"/></param>
		void setLog(Log *log){this->log=log;};
		///	<summary>
		///	�������˽������ֵ���ͷ��ڴ�ռ�
		///	<code>ԭ�ͣ�void clear();</code>
		///	</summary>
		void clear(){this->argItems.clear();this->paramsValue.clear();};
		///	<summary>
		///	���������в������ڳ�ʼ��ʱ�����˽�������[items]�Լ�����[_count]ʱʹ��
		///	<code>ԭ�ͣ�bool parse(int argc,char *argv[]);</code>
		///	</summary>
		///	<param name="argc">�����в�����������Ӧ�������argv����</param>
		///	<param name="argv">����������������ַ���ָ������</param>
		///	<returns>���ؽ�������������������ƥ�����ʱ������[true]����֮���ؼ�[false]</returns>
		bool parse(int argc,char *argv[])
		{
			this->_argc=argc;
			this->_argv=argv;
			return parse();
		};
		///	<summary>
		///	���������в������ڳ�ʼ��ʱ�����˲���[argv]�Լ�����[argc]ʱʹ��
		///	<code>ԭ�ͣ�bool parse(const ArgItem items[],int _count);</code>
		///	</summary>
		///	<param name="items">������ʽ����Ϣ�ṹ���飬���ڼ����������</param>
		///	<param name="_count">������ʽ����Ϣ�ṹ���鳤��</param>
		///	<returns>���ؽ�������������������ƥ�����ʱ������[true]����֮���ؼ�[false]</returns>
		bool parse(const ArgItem items[],int _count)
		{
			argItems.clear();
			paramsValue.clear();
			addParam(items,_count);
			return parse();
		};
		///	<summary>
		///	���������в������ڳ�ʼ��ʱ�����˲���[argv]�Լ�����[argc]ʱʹ��
		///	<code>ԭ�ͣ�bool parse(int argc,char *argv[],const ArgItem items[],int _count);</code>
		///	</summary>
		///	<param name="argc">�����в�����������Ӧ�������argv����</param>
		///	<param name="argv">����������������ַ���ָ������</param>
		///	<param name="items">������ʽ����Ϣ�ṹ���飬���ڼ����������</param>
		///	<param name="_count">������ʽ����Ϣ�ṹ���鳤��</param>
		///	<returns>���ؽ�������������������ƥ�����ʱ������[true]����֮���ؼ�[false]</returns>
		bool parse(int argc,char *argv[],const ArgItem items[],int _count,Log *log=NULL)
		{
			this->_argc=argc;
			this->_argv=argv;
			this->log=log;
			argItems.clear();
			paramsValue.clear();
			addParam(items,_count);
			return parse();
		};
		///	<summary>
		///	���������в����������Ľ�������
		///	<code>ԭ�ͣ�bool parse();</code>
		///	</summary>
		///	<returns>���ؽ�������������������ƥ�����ʱ������[true]����֮���ؼ�[false]</returns>
		bool parse();
		/// <summary>
		/// ���������������Ӳ���������
		///	<code>ԭ�ͣ�void addParam(ArgItem item);</code>
		/// </summary>
		/// <param name="item">�������������<code>���ͣ�<see cref="ArgItem"/></code></param>
		void addParam(ArgItem item);
		/// <summary>
		/// �������������������Ӳ���������
		///	<code>ԭ�ͣ�void addParam(Array&lt;ArgItem&gt; items);</code>
		/// </summary>
		/// <param name="items">�������������<code>���ͣ�<see cref="Array"/>&lt;<see cref="ArgItem"/>&gt;</code></param>
		void addParam(Array<ArgItem> items);
		/// <summary>
		/// �������������������Ӳ���������
		///	<code>ԭ�ͣ�void addParam(const ArgItem items[],int _count);</code>
		/// </summary>
		/// <param name="items">�������������<code>���ͣ�<see cref="ArgItem"/>����</code></param>
		/// <param name="_count">�����������<code>���ͣ�<see cref="int"/></code></param>
		void addParam(const ArgItem items[],int _count);
		/// <summary>
		/// ���������������Ӳ�������
		///	<code>ԭ�ͣ�void addParam(const char* _prefix, const char* _name, const char* _desc,
		///	                         int _needType,varType _valueType , int _length);</code>
		/// </summary>
		/// <param name="_prefix">����ǰ׺<code>���ͣ�<see cref="char"/>ָ��</code></param>
		/// <param name="_name">��������<code>���ͣ�<see cref="char"/>ָ��</code></param>
		/// <param name="_desc">��������<code>���ͣ�<see cref="char"/>ָ��</code></param>
		/// <param name="_needType">������֤����<code>���ͣ�<see cref="int"/></code></param>
		/// <param name="_valueType">����ֵ����<code>���ͣ�<see cref="varType"/></code></param>
		/// <param name="_length">����Ҫ�󳤶�<code>���ͣ�<see cref="int"/></code></param>
		void addParam(const char* _prefix, const char* _name, const char* _desc,int _needType,varType _valueType , int _length);
		/// <summary>
		/// �Ƴ�������Ĳ���������
		///	<code>ԭ�ͣ�void removeParam(String s_prefix);</code>
		/// </summary>
		/// <param name="s_prefix">����ǰ׺<code>���ͣ�<see cref="String"/></code></param>
		void removeParam(String s_prefix);

		/// <summary>
		/// ��ȡ����ֵ
		///	<code>ԭ�ͣ�inline int getInt(String _prefix);</code>
		/// </summary>
		/// <param name="s_prefix">����ǰ׺<code>���ͣ�<see cref="String"/></code></param>
		///	<returns>���ؽ�������������ֵ����Ϊ��ѡ����ʱδ�������ֵʱΪ0��</returns>
		inline int	getInt(String _prefix)
		{
			map<String,String>::const_iterator _where=paramsValue.find(_prefix.ToUpper());
			if(_where!=paramsValue.end())
				return Convert::ToInt(_where->second);
			else if(argItems.find(_prefix)!=argItems.end())
				return atoi(argItems[_prefix].defaultVal.c_str());
			else
				return 0;
		}
		/// <summary>
		/// ��ȡ������ֵ
		///	<code>ԭ�ͣ�inline long getLong(String _prefix);</code>
		/// </summary>
		/// <param name="s_prefix">����ǰ׺<code>���ͣ�<see cref="String"/></code></param>
		///	<returns>���ؽ�������������ֵ����Ϊ��ѡ����ʱδ�������ֵʱΪ0��</returns>
		inline long getLong(String _prefix)
		{
			map<String,String>::const_iterator _where=paramsValue.find(_prefix.ToUpper());
			if(_where!=paramsValue.end())
				return Convert::ToLong(_where->second);
			else if(argItems.find(_prefix)!=argItems.end())
				return atol(argItems[_prefix].defaultVal.c_str());
			else
				return 0;
		}
		/// <summary>
		/// ��ȡ64λ������ֵ
		///	<code>ԭ�ͣ�inline long long getLLong(String _prefix);</code>
		/// </summary>
		/// <param name="s_prefix">����ǰ׺<code>���ͣ�<see cref="String"/></code></param>
		///	<returns>���ؽ�������������ֵ����Ϊ��ѡ����ʱδ�������ֵʱΪ0��</returns>
		inline long long getLLong(String _prefix)
		{
			map<String,String>::const_iterator _where=paramsValue.find(_prefix.ToUpper());
			if(_where!=paramsValue.end())
				return Convert::ToLLong(_where->second);
			else if(argItems.find(_prefix)!=argItems.end())
				return atoll(argItems[_prefix].defaultVal.c_str());
			else
				return 0;
		}
		/// <summary>
		/// ��ȡ�ַ�������ֵ
		///	<code>ԭ�ͣ�inline String getStr(String _prefix);</code>
		/// </summary>
		/// <param name="s_prefix">����ǰ׺<code>���ͣ�<see cref="String"/></code></param>
		///	<returns>���ؽ�������������ֵ����Ϊ��ѡ����ʱδ�������ֵʱΪ���ַ���[""]��</returns>
		inline String getStr(String _prefix)
		{
			map<String,String>::const_iterator _where=paramsValue.find(_prefix.ToUpper());
			if(_where!=paramsValue.end())
				return _where->second;
			else if(argItems.find(_prefix)!=argItems.end())
				return argItems[_prefix].defaultVal;
			else
				return "";
		}
		/// <summary>
		/// �ж��Ƿ������ǰ׺����
		///	<code>ԭ�ͣ�inline bool getBool(String _prefix);</code>
		/// </summary>
		/// <param name="s_prefix">����ǰ׺<code>���ͣ�<see cref="String"/></code></param>
		///	<returns>���ؽ�������������ֵ�����ڴ�ǰ׺��������[true],��֮����[false]��</returns>
		inline bool getBool(String _prefix)
		{
			map<String,String>::const_iterator _where=paramsValue.find(_prefix.ToUpper());
			return (_where!=paramsValue.end());
		}

		/// <summary>
		/// ���ý������еĲ���ֵ
		///	<code>ԭ�ͣ�inline bool setInt(String _prefix,int val);</code>
		/// </summary>
		/// <param name="s_prefix">����ǰ׺<code>���ͣ�<see cref="String"/></code></param>
		/// <param name="val">����ֵ<code>���ͣ�<see cref="int"/></code></param>
		inline void setInt(String _prefix,int val)
		{
			paramsValue[_prefix.ToUpper()]=String(val);
		}
		/// <summary>
		/// ���ý������еĲ���ֵ
		///	<code>ԭ�ͣ�inline void setStr(String _prefix,String val);</code>
		/// </summary>
		/// <param name="s_prefix">����ǰ׺<code>���ͣ�<see cref="String"/></code></param>
		/// <param name="val">����ֵ<code>���ͣ�<see cref="String"/></code></param>
		inline void setStr(String _prefix,String val)
		{
			paramsValue[_prefix.ToUpper()]=val;
		}
		/// <summary>
		/// ���ý������еĲ���ֵ
		///	<code>ԭ�ͣ�inline void setLong(String _prefix,long val);</code>
		/// </summary>
		/// <param name="s_prefix">����ǰ׺<code>���ͣ�<see cref="String"/></code></param>
		/// <param name="val">����ֵ<code>���ͣ�<see cref="long"/></code></param>
		inline void setLong(String _prefix,long val)
		{
			paramsValue[_prefix.ToUpper()]=String(val);
		}
		/// <summary>
		/// ���ý������еĲ���ֵ
		///	<code>ԭ�ͣ�inline void setLLong(String _prefix,long long val);</code>
		/// </summary>
		/// <param name="s_prefix">����ǰ׺<code>���ͣ�<see cref="String"/></code></param>
		/// <param name="val">����ֵ<code>���ͣ�<see cref="long long"/></code></param>
		inline void setLLong(String _prefix,long long val)
		{
			paramsValue[_prefix.ToUpper()]=String(val);
		}
		/// <summary>
		/// ���ý������еĲ���ֵ
		///	<code>ԭ�ͣ�inline void setBool(String _prefix,bool val);</code>
		/// </summary>
		/// <param name="s_prefix">����ǰ׺<code>���ͣ�<see cref="String"/></code></param>
		/// <param name="val">����ֵ<code>���ͣ�<see cref="bool"/></code></param>
		inline void setBool(String _prefix,bool val)
		{
			if(val)
			{
				paramsValue[_prefix.ToUpper()]="TRUE";
			}
			else
			{
				map<String,String>::const_iterator _where=paramsValue.find(_prefix.ToUpper());
				if(_where!=paramsValue.end())
				{
					paramsValue.erase(_prefix);
				}
			}
		}
	};
}
#endif
