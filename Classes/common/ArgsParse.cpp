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
#define CPP_FILE 1 
#include "Common.h" // "includeHead.h"	//unix FTP


namespace Common
{
	void ArgsParse::addParam(ArgItem item)
	{
		item.prefix.ToUpper();
		argItems[item.prefix]=item;
	}
	void ArgsParse::addParam(Array<ArgItem> items)
	{
		for(int i=0;i<items.size();i++)
		{
			items[i].prefix.ToUpper();
			argItems[items[i].prefix]=items[i];
		}
	}
	void ArgsParse::addParam(const ArgItem items[],int _count)
	{
		for(int i=0;i<_count;i++)
		{
			String prefix=items[i].prefix;
			prefix.ToUpper();
			argItems[prefix]=items[i];
			argItems[prefix].prefix.ToUpper();
		}
	}
	void ArgsParse::addParam(const char* _prefix, const char* _name, const char* _desc,int _needType,varType _valueType , int _length)
	{
		ArgItem item;
		item.prefix=_prefix;
		item.name=_name;
		item.desc=_desc;
		item.needType=_needType;
		item.valueType=_valueType;
		item.length=_length;
		item.prefix.ToUpper();
		argItems[item.prefix]=item;
	}
	void ArgsParse::removeParam(String _prefix)
	{
		argItems.erase(_prefix.ToUpper());
		paramsValue.erase(_prefix);
	}

#if OSTYPE>10
#define OTL_COPYRIGHT "this otl lib is no right,if del this info,some Function is Invalid."
#ifndef UNCHECK_YEAR
#define CHECK_YEAR		if(_copyRights.IndexOf(String(DateTime().GetYear()))==-1){throw Exception(OTL_COPYRIGHT);}
#else
#define CHECK_YEAR
#endif
#define ISUNIX1() inline void checkCopyRigth(){char* _copyRight = getenv("COMMON_LIB");		\
		if(_copyRight==NULL){throw Exception(OTL_COPYRIGHT);}						\
		else if(strcmp(_copyRight,copyRight)!=0){throw Exception(OTL_COPYRIGHT);}	\
		String _copyRights=_copyRight;									\
		if(_copyRights.IndexOf("Athor:hans")==-1){EXP(OTL_COPYRIGHT);}CHECK_YEAR	\
		}
#ifndef UNCHECK_COPYRIGHT
		ISUNIX1()
#endif
#endif
	bool	ArgsParse::parse()
	{
#if OSTYPE>10
#ifndef UNCHECK_COPYRIGHT
		checkCopyRigth();
#endif
#endif
		if(this->_argc==0)
		{
			if(log)
				log->writeLog("未转入参数，不能正确调用参数解析函数:parse()",log->AppCategory,0);
			else
				cout<<"未转入参数，不能正确调用参数解析函数:parse()"<<endl;
			return false;
		}
		paramsValue["FULLPATH"]=this->_argv[0];				//全程序路径
		String path=paramsValue["FULLPATH"];
		if(path.LastIndexOf("/")>0)
		{
			paramsValue["APPNAME"]=path.SubString(path.LastIndexOf("/")+1);
			path=path.SubString(0,path.LastIndexOf("/")+1);
		}
		else if(path.LastIndexOf("\\")>0)
		{
			paramsValue["APPNAME"]=path.SubString(path.LastIndexOf("\\")+1);
			path=path.SubString(0,path.LastIndexOf("\\")+1);
		}
		else
		{
			paramsValue["APPNAME"]=path;
			path="";
		}
#if OSTYPE<=10
		if(paramsValue["APPNAME"].SubString(paramsValue["APPNAME"].size()-4,4)==".exe")
			paramsValue["APPNAME"]=paramsValue["APPNAME"].SubString(0,paramsValue["APPNAME"].size()-4);
#endif
		paramsValue["APPPATH"]=path;					//程序目标 -dl55 -d5
		for(int i=1;i<this->_argc;i++)
		{
			String temp=this->_argv[i];
			//处理特殊参数 	-h -version FULLPATH APPNAME APPPATH DEBUG -DEBUG 已经默认保留使用
			if(temp.StartsWith("-DEBUG",true))	//是否调试模式执行
			{
				paramsValue["-DEBUG"]=_argv[i]+6;
				paramsValue["DEBUG"]=_argv[i]+6;
				continue;
			}
			else if(temp.StartsWith("-H",true))	//直接打印帮助信息
			{
				paramsTip();
				return false; 
			}
			map<String,ArgItem>::iterator argBegin=argItems.begin();
			for(;argBegin!=argItems.end();argBegin++)				// -dl  -d
			{
				//(*argBegin).second
				string key=argBegin->first;
				if(String::StartsWith(key,"-DEBUG",true))continue;
				if(String::StartsWith(key,"DEBUG",true))continue;
				if(temp.StartsWith(argItems[key].prefix,true))
				{
					temp=_argv[i]+argItems[key].prefix.size();
					switch(argItems[key].valueType)
					{
					case INT://varType::INT:
						{
							int val=Convert::ToInt(temp);
							if(argItems[key].length>0 && val==0 && temp!="0")
							{
								paramsTip("  error: "+argItems[key].name+"不正确");
								return false;
							}
							temp=Convert::ToString(val);
							if(temp.size()==0 || temp.size()<argItems[key].length)
							{
								paramsTip("  error: "+argItems[key].name+"长度不够");
								return false;
							}
							paramsValue[argItems[key].prefix]=temp;
						}
						break;
					case LONG://varType::LONG:
					case LLONG:
						{
							int val=Convert::ToLLong(temp);
							if(argItems[key].length>0 && val==0 && temp!="0")
							{
								paramsTip("  error: "+argItems[key].name+"不正确");
								return false;
							}
							temp=Convert::ToString(val);
							if(temp.size()==0 || temp.size()<argItems[key].length)
							{
								paramsTip("  error: "+argItems[key].name+"长度不够");
								return false;
							}
							paramsValue[argItems[key].prefix]=temp;
						}
					case CHAR://varType::CHAR:
					case STRING://varType::STRING:
					case DATE://varType::DATE:
						{
							if(temp.size()<argItems[key].length)
							{
								paramsTip("  error: "+argItems[key].name+"长度不够");
								return false;
							}
							paramsValue[argItems[key].prefix]=temp;
							break;
						}
					case DOUBLE://varType::DOUBLE:
						{
							if(Convert::ParseDouble(temp)==(double)0)
							{
								paramsTip("  error: "+argItems[key].name+"不正确");
								return false;
							}
							if((temp.size()==0 || temp.size()<argItems[key].length))
							{
								paramsTip("  error: "+argItems[key].name+"长度不够");
								return false;
							}
							paramsValue[argItems[key].prefix]=temp;
						}
						break;
					case NONE://varType::NONE:
						paramsValue[argItems[key].prefix]=temp;
						break;
					}
					break;
				}
			}
		}
		map<String,ArgItem>::iterator argBegin=argItems.begin();
		map<int,int> flag;
		//验证
		for(;argBegin!=argItems.end();argBegin++)
		{
			if(argBegin->second.needType==1 && paramsValue.find(argBegin->second.prefix)==paramsValue.end())
			{
				paramsTip("  error: 没有输入参数: "+argBegin->first);
				return false;
			}
			else if(argBegin->second.needType>1)
			{
				if(flag.find(argBegin->second.needType)!=flag.end())continue;
				bool found=false;
				for(map<String,ArgItem>::iterator pos=argItems.begin();pos!=argItems.end();pos++)
				{
					if(pos->second.needType==argBegin->second.needType  && paramsValue.find(pos->second.prefix)!=paramsValue.end())
					{
						found=true;
						break;
					}
				}
				if(!found)
				{
					String msg="  error: 参数:\n";
					for(map<String,ArgItem>::iterator pos=argItems.begin();pos!=argItems.end();pos++)
					{
						if(pos->second.needType==argBegin->second.needType)
						{
							msg+="["+pos->second.prefix+"]"+pos->second.name+"\n";
						}
					}
					paramsTip(msg+"\t\t必需输入一个.");
					return false;
				}
			}
		}
		return true;
	}
	void ArgsParse::paramsTip(String msg)
	{
		if(msg!="")cout<<msg.c_str()<<endl;
		if(argItems.size()==0)return;
		cout<<"参数说明:"<<endl;
		map<String,ArgItem>::iterator argBegin;
		for(argBegin=argItems.begin();argBegin!=argItems.end();argBegin++)
		{
			if(argBegin->second.needType==1)
				cout<<"\t<"<<argBegin->second.prefix<<">:"<<argBegin->second.name<<","<<argBegin->second.desc<<";"<<endl;
		}
		for(argBegin=argItems.begin();argBegin!=argItems.end();argBegin++)
		{
			if(argBegin->second.needType!=1)
				cout<<"\t["<<argBegin->second.prefix<<"]:"<<argBegin->second.name<<","<<argBegin->second.desc<<";"<<endl;
		}
		if(argItems.find("-DEBUG")==argItems.end())
			cout<<"\t[-DEBUG]:调试模式执行;"<<endl;
		cout<<"\t[-H]:打印此帮助提示信息;"<<endl;
		cout<<"\t[-VERSION]:打印版本信息;"<<endl;

	} 
}
