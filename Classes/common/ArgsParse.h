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
	///	参数解析规则存储结构体。
	///	</summary>
	///	<remarks>
	///	命令行输入参数解析规则存储结构体，用于存储参数格式化检查信息。使用见<see cref="ArgsParse"/>
	///	</remarks>
    /// <example><code>
	///	const ArgItem items[]={	{"-d","日期参数","用于替换配置中的宏变量",0,Common::INT,6},
	///						  };
	///	ArgsParse pars;
	///	if(!pars.parse(argc,argv,items,1))exit(1);
	///	
    /// </code></example>
	struct ArgItem
	{
		///	<summary>
		///	前缀
		///	</summary>
		String prefix		;
		///	<summary>
		///	名称
		///	</summary>
		String name			;
		///	<summary>
		///	描述
		///	</summary>
		String desc			;
		///	<summary>
		///	是否必需	0:可选,1:必需,2...分组ID,表示组中参数个数,必需有一个存在
		///	</summary>
		int needType		;
		///	<summary>
		///	需要验证的类型 验证值是否能转换为目标类型
		///	</summary>
		varType  valueType	;
		///	<summary>
		///	需要的值长度
		///	</summary>
		int length			;
		String defaultVal ;
		ArgItem(){};//"-r","确认关闭","是否关闭共享内存，刷新数据到磁盘",1,Common::NONE,0
		ArgItem(String _prefix,String _name,String _desc,int _needType,varType  _valueType,int _length)
			:prefix(_prefix),name(_name),desc(_desc),needType(_needType),valueType(_valueType),length(_length){};
	} ;
	///	<summary>
	///	参数解析类
	///	</summary>
	///	<remarks>
	///	命令行参数解析类,需要使用结构体<see cref="ArgItem"/>
	///	-h -version FULLPATH APPNAME APPPATH DEBUG -DEBUG 已经默认保留使用
	///	</remarks>
    /// <example><code>
	///	应用命令行参数解析：
	///	const ArgItem items[]={	{"-d","日期参数","用于替换配置中的宏变量",0,Common::INT,6},
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
		///	解析对象构造函数，用于指定参数及参数检验条件初始化解析对象
		///	<code>原型：ArgsParse(int argc=0,char *argv[]=NULL,const ArgItem items[]=NULL,int _count=0,Log *log=NULL);</code>
		///	</summary>
		///	<param name="argc">命令行参数个数，对应数组参数argv长度</param>
		///	<param name="argv">命令行输入参数，字符串指针数组</param>
		///	<param name="items">参数格式化信息结构数组，用于检验输入参数</param>
		///	<param name="_count">参数格式化信息结构数组长度</param>
		///	<param name="log">日志对象指针，用于日志输出</param>
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
		///	解析对象析构函数，用于对象自释放资源
		///	<code>原型：~ArgsParse();</code>
		///	</summary>
		~ArgsParse(){clear();};
		///	<summary>
		///	打印提示信息
		///	<code>原型：void paramsTip(String msg="");</code>
		///	</summary>
		///	<param name="msg">附加的要打印的提示信息</param>
		void paramsTip(String msg="");
 
		///	<summary>
		///	设置日志对象指针
		///	<code>原型：void setLog(Log *log);</code>
		///	</summary>
		///	<param name="log">日志对象<see cref="Log"/></param>
		void setLog(Log *log){this->log=log;};
		///	<summary>
		///	清理对象私有属性值，释放内存空间
		///	<code>原型：void clear();</code>
		///	</summary>
		void clear(){this->argItems.clear();this->paramsValue.clear();};
		///	<summary>
		///	解析命令行参数，在初始化时设置了解析规则[items]以及个数[_count]时使用
		///	<code>原型：bool parse(int argc,char *argv[]);</code>
		///	</summary>
		///	<param name="argc">命令行参数个数，对应数组参数argv长度</param>
		///	<param name="argv">命令行输入参数，字符串指针数组</param>
		///	<returns>返回解析结果，输入参数满足匹配规则时返回真[true]，反之返回假[false]</returns>
		bool parse(int argc,char *argv[])
		{
			this->_argc=argc;
			this->_argv=argv;
			return parse();
		};
		///	<summary>
		///	解析命令行参数，在初始化时设置了参数[argv]以及个数[argc]时使用
		///	<code>原型：bool parse(const ArgItem items[],int _count);</code>
		///	</summary>
		///	<param name="items">参数格式化信息结构数组，用于检验输入参数</param>
		///	<param name="_count">参数格式化信息结构数组长度</param>
		///	<returns>返回解析结果，输入参数满足匹配规则时返回真[true]，反之返回假[false]</returns>
		bool parse(const ArgItem items[],int _count)
		{
			argItems.clear();
			paramsValue.clear();
			addParam(items,_count);
			return parse();
		};
		///	<summary>
		///	解析命令行参数，在初始化时设置了参数[argv]以及个数[argc]时使用
		///	<code>原型：bool parse(int argc,char *argv[],const ArgItem items[],int _count);</code>
		///	</summary>
		///	<param name="argc">命令行参数个数，对应数组参数argv长度</param>
		///	<param name="argv">命令行输入参数，字符串指针数组</param>
		///	<param name="items">参数格式化信息结构数组，用于检验输入参数</param>
		///	<param name="_count">参数格式化信息结构数组长度</param>
		///	<returns>返回解析结果，输入参数满足匹配规则时返回真[true]，反之返回假[false]</returns>
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
		///	解析命令行参数，真正的解析过程
		///	<code>原型：bool parse();</code>
		///	</summary>
		///	<returns>返回解析结果，输入参数满足匹配规则时返回真[true]，反之返回假[false]</returns>
		bool parse();
		/// <summary>
		/// 向参数解析体中添加参数配置项
		///	<code>原型：void addParam(ArgItem item);</code>
		/// </summary>
		/// <param name="item">参数检验规则项<code>类型：<see cref="ArgItem"/></code></param>
		void addParam(ArgItem item);
		/// <summary>
		/// 向参数解析体中批量添加参数配置项
		///	<code>原型：void addParam(Array&lt;ArgItem&gt; items);</code>
		/// </summary>
		/// <param name="items">参数检验规则项<code>类型：<see cref="Array"/>&lt;<see cref="ArgItem"/>&gt;</code></param>
		void addParam(Array<ArgItem> items);
		/// <summary>
		/// 向参数解析体中批量添加参数配置项
		///	<code>原型：void addParam(const ArgItem items[],int _count);</code>
		/// </summary>
		/// <param name="items">参数检验规则项<code>类型：<see cref="ArgItem"/>数组</code></param>
		/// <param name="_count">数组参数长度<code>类型：<see cref="int"/></code></param>
		void addParam(const ArgItem items[],int _count);
		/// <summary>
		/// 向参数解析体中添加参数配置
		///	<code>原型：void addParam(const char* _prefix, const char* _name, const char* _desc,
		///	                         int _needType,varType _valueType , int _length);</code>
		/// </summary>
		/// <param name="_prefix">参数前缀<code>类型：<see cref="char"/>指针</code></param>
		/// <param name="_name">参数名称<code>类型：<see cref="char"/>指针</code></param>
		/// <param name="_desc">参数描述<code>类型：<see cref="char"/>指针</code></param>
		/// <param name="_needType">参数验证类型<code>类型：<see cref="int"/></code></param>
		/// <param name="_valueType">参数值类型<code>类型：<see cref="varType"/></code></param>
		/// <param name="_length">参数要求长度<code>类型：<see cref="int"/></code></param>
		void addParam(const char* _prefix, const char* _name, const char* _desc,int _needType,varType _valueType , int _length);
		/// <summary>
		/// 移除解析体的参数配置项
		///	<code>原型：void removeParam(String s_prefix);</code>
		/// </summary>
		/// <param name="s_prefix">参数前缀<code>类型：<see cref="String"/></code></param>
		void removeParam(String s_prefix);

		/// <summary>
		/// 获取整数值
		///	<code>原型：inline int getInt(String _prefix);</code>
		/// </summary>
		/// <param name="s_prefix">参数前缀<code>类型：<see cref="String"/></code></param>
		///	<returns>返回解析后的输入参数值，如为可选参数时未输入此项值时为0。</returns>
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
		/// 获取长整数值
		///	<code>原型：inline long getLong(String _prefix);</code>
		/// </summary>
		/// <param name="s_prefix">参数前缀<code>类型：<see cref="String"/></code></param>
		///	<returns>返回解析后的输入参数值，如为可选参数时未输入此项值时为0。</returns>
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
		/// 获取64位长整数值
		///	<code>原型：inline long long getLLong(String _prefix);</code>
		/// </summary>
		/// <param name="s_prefix">参数前缀<code>类型：<see cref="String"/></code></param>
		///	<returns>返回解析后的输入参数值，如为可选参数时未输入此项值时为0。</returns>
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
		/// 获取字符串输入值
		///	<code>原型：inline String getStr(String _prefix);</code>
		/// </summary>
		/// <param name="s_prefix">参数前缀<code>类型：<see cref="String"/></code></param>
		///	<returns>返回解析后的输入参数值，如为可选参数时未输入此项值时为空字符串[""]。</returns>
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
		/// 判断是否输入此前缀参数
		///	<code>原型：inline bool getBool(String _prefix);</code>
		/// </summary>
		/// <param name="s_prefix">参数前缀<code>类型：<see cref="String"/></code></param>
		///	<returns>返回解析后的输入参数值，存在此前缀参数返回[true],反之返回[false]。</returns>
		inline bool getBool(String _prefix)
		{
			map<String,String>::const_iterator _where=paramsValue.find(_prefix.ToUpper());
			return (_where!=paramsValue.end());
		}

		/// <summary>
		/// 设置解析体中的参数值
		///	<code>原型：inline bool setInt(String _prefix,int val);</code>
		/// </summary>
		/// <param name="s_prefix">参数前缀<code>类型：<see cref="String"/></code></param>
		/// <param name="val">参数值<code>类型：<see cref="int"/></code></param>
		inline void setInt(String _prefix,int val)
		{
			paramsValue[_prefix.ToUpper()]=String(val);
		}
		/// <summary>
		/// 设置解析体中的参数值
		///	<code>原型：inline void setStr(String _prefix,String val);</code>
		/// </summary>
		/// <param name="s_prefix">参数前缀<code>类型：<see cref="String"/></code></param>
		/// <param name="val">参数值<code>类型：<see cref="String"/></code></param>
		inline void setStr(String _prefix,String val)
		{
			paramsValue[_prefix.ToUpper()]=val;
		}
		/// <summary>
		/// 设置解析体中的参数值
		///	<code>原型：inline void setLong(String _prefix,long val);</code>
		/// </summary>
		/// <param name="s_prefix">参数前缀<code>类型：<see cref="String"/></code></param>
		/// <param name="val">参数值<code>类型：<see cref="long"/></code></param>
		inline void setLong(String _prefix,long val)
		{
			paramsValue[_prefix.ToUpper()]=String(val);
		}
		/// <summary>
		/// 设置解析体中的参数值
		///	<code>原型：inline void setLLong(String _prefix,long long val);</code>
		/// </summary>
		/// <param name="s_prefix">参数前缀<code>类型：<see cref="String"/></code></param>
		/// <param name="val">参数值<code>类型：<see cref="long long"/></code></param>
		inline void setLLong(String _prefix,long long val)
		{
			paramsValue[_prefix.ToUpper()]=String(val);
		}
		/// <summary>
		/// 设置解析体中的参数值
		///	<code>原型：inline void setBool(String _prefix,bool val);</code>
		/// </summary>
		/// <param name="s_prefix">参数前缀<code>类型：<see cref="String"/></code></param>
		/// <param name="val">参数值<code>类型：<see cref="bool"/></code></param>
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
