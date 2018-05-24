// ==============================================================
//progame      Common functions  declare
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

#ifndef __common_Functions_H__
#define __common_Functions_H__


typedef long long Long;

// 摘要:
//     公共函数头文件.
//
//注意：
//		为提高效率，所有类对象都建议采用引用参数传递。
//
//
// 作 者: 邹远贵
// 日 期: 2007-4-25
// 版 本: 1.0
//
namespace Common
{
	///	<summary>
	///	加载ctl文件到数据表:快速加载。忽略文件头,加载条数限制。
	///	<code>原型：	int  ImportCtlFile( String ctlName,String stlDataName,String dbConnStr,bool direct=false,
	///                             bool parallel=false,int readsize=6553600,int bindsize=6553600,
	///                             int rows=10000,const long skipNum=0,const long loadRowNum=0);</code>
	///	</summary>
	///	<param name="ctlName">ctl控制头文件,类型<see cref="String"/></param>
	///	<param name="stlDataName">数据文件,类型<see cref="String"/></param>
	///	<param name="dbConnStr">数据连接串,类型<see cref="String"/></param>
	///	<param name="direct">是否使用直通导入，编译程序的数据库版本与目标数据库相同时才能使用,类型<see cref="bool"/></param>
	///	<param name="parallel">是否支撑并行,类型<see cref="bool"/></param>
	///	<param name="readsize">读取大小,类型<see cref="int"/></param>
	///	<param name="bindsize">绑定下大小,类型<see cref="int"/></param>
	///	<param name="rows">单次提交记录数大小,类型<see cref="int"/></param>
	///	<param name="skipNum">跳过记录数,类型<see cref="int"/></param>
	///	<param name="loadRowNum">限定加载记录数,类型<see cref="int"/></param>
	///	<returns>返回执行结果： 0:成功,1:对象校验失败：表不存在或字段不匹配等,2:导入不完全,产生BAD文件:字段异常等,-1:失败</returns>
	int  ImportCtlFile( String ctlName,String stlDataName,String dbConnStr,bool direct=false,bool parallel=false
		,int readsize=6553600,int bindsize=6553600,int rows=10000,const long skipNum=0,const long loadRowNum=0);
	///	<summary>
	///	执行sqlldr外部调用。
	///	<code>原型：int  Sqlldr(string pCommand);</code>
	///	</summary>
	///	<param name="pCommand">执行命令字符串<see cref="String"/></param>
	///	<returns>返回执行结果： 0:成功,1:对象校验失败：表不存在或字段不匹配等,2:导入不完全,产生BAD文件:字段异常等,-1:失败</returns>
	int  Sqlldr(string pCommand);
	///	<summary>
	///	检查执行sqlldr后的日志文件。
	///	<code>原型：bool CheckSqlldrRet(const char*log_file ,string &amp;out_msg ) ;</code>
	///	</summary>
	///	<param name="log_file">文件名字符串指针</param>
	///	<param name="out_msg">返回信息<see cref="String"/></param>
	///	<returns>返回sqlldr执行结果，成功[true]，反之返回假[false]</returns>
	bool CheckSqlldrRet(const char*log_file ,string &out_msg ) ;
	///	<summary>
	///	执行系统调用。
	///	<code>原型：bool System(string pCommand,string &amp;pOutMsg,int&amp; pRetValue);</code>
	///	</summary>
	///	<param name="pCommand">执行命令字符串,类型<see cref="String"/></param>
	///	<param name="pOutMsg">返回信息,类型<see cref="String"/></param>
	///	<param name="pRetValue">命令执行结果返回值,类型<see cref="int"/></param>
	///	<returns>是否执行成功，成功[true]，反之返回假[false]</returns>
	bool System(string pCommand,string &pOutMsg,int& pRetValue);
	///	<summary>
	///	执行系统调用。
	///	<code>原型：int System(string pCommand,String &amp;pOutMsg);</code>
	///	</summary>
	///	<param name="pCommand">执行命令字符串,类型<see cref="String"/></param>
	///	<param name="pOutMsg">返回信息,类型<see cref="String"/></param>
	///	<returns>命令执行结果返回值</returns>
	int System(string pCommand,String &pOutMsg);

#if OSTYPE>10
	int  ForkRun(list<string> lst_appName) ;
	int  ForkRun(Array<string> lst_appName);
	int  ForkRun(Array<String> lst_appName);
#endif

	///	<summary>
	///	解码文件编码，从64位编码中解码出文件号，文件内偏移位置，数据长度。
	///	<code>原型：inline int decodePos(unsigned long long &amp;pos,int &amp;len)</code>
	///	</summary>
	///	<param name="pos">位移,类型<see cref="unsigned long long"/></param>
	///	<param name="len">长度,类型<see cref="int"/></param>
	///	<returns>文件号</returns>
	inline int decodePos(unsigned long long &pos,int &len)
	{
		unsigned int fileNum=pos>>56;	//8位文件号
		len=pos>>40 & 0xFFFF;			//16位大小
		pos=pos & 0xFFFFFFFFFFll;			//40内部位置号
		return fileNum;
	};
	///	<summary>
	///	解码文件编码，从64位编码中解码出文件号，文件内偏移位置，数据长度。
	///	<code>原型：inline unsigned long long encodePos(const int &amp;fileNum,const unsigned long long &amp;pos,const int &amp;len)</code>
	///	</summary>
	///	<param name="fileNum">文件号,类型<see cref="unsigned long long"/></param>
	///	<param name="pos">位移,类型<see cref="unsigned long long"/></param>
	///	<param name="len">长度,类型<see cref="int"/></param>
	///	<returns>编码结果</returns>
	inline unsigned long long  encodePos(const int &fileNum,const unsigned long long &pos,const int &len)
	{
		unsigned long long res=((unsigned int)fileNum<<16) | ((unsigned int)len);
		return ((res<<40) | pos);
	};

	///	<summary>
	///	获取hash编码
	///	<code>原型：inline static void getHashCode(const string &amp; s,unsigned long long &amp;hashCode);</code>
	///	</summary>
	///	<param name="s">数据字符串,类型<see cref="String"/></param>
	///	<param name="hashCode">编码结果值,类型<see cref="unsigned long long"/></param>
	inline static void getHashCode(const string & s,unsigned long long &hashCode)
	{
		hashCode=hashMath::hashsp(s);
		hashCode=((hashCode<<32) | hashMath::hashpjw(s));
	}
	///	<summary>
	///	获取hash编码
	///	<code>原型：inline static unsigned long long getHashCode(const string &amp; s);</code>
	///	</summary>
	///	<param name="s">数据字符串,类型<see cref="String"/></param>
	///	<returns>字符串的hash编码值</returns>
	inline static unsigned long long getHashCode(const string & s)
	{
		unsigned long long hashCode;
		getHashCode(s,hashCode);
		return hashCode;
	}
	///	<summary>
	///	获取hash编码
	///	<code>原型：inline static void getHashCode(const char *  s,unsigned long long &amp;hashCode);</code>
	///	</summary>
	///	<param name="s">数据字符串,类型char指针</param>
	///	<param name="hashCode">编码结果值,类型<see cref="unsigned long long"/></param>
	inline static void getHashCode(const char * s,unsigned long long &hashCode)
	{
		hashCode=hashMath::hashsp(s);
		hashCode=((hashCode<<32) | hashMath::hashpjw(s));
	}
	///	<summary>
	///	获取hash编码
	///	<code>原型：inline static unsigned long long getHashCode(const char * s);</code>
	///	</summary>
	///	<param name="s">数据字符串,类型char指针</param>
	///	<returns>字符串的hash编码值</returns>
	inline static unsigned long long getHashCode(const char * s)
	{
		unsigned long long hashCode;
		getHashCode(s,hashCode);
		return hashCode;
	}

	///	<summary>
	///	文件测试，判断文件是否存在
	///	<code>原型：inline bool testFile(const string&amp; file);</code>
	///	</summary>
	///	<param name="file">文件名路径</param>
	///	<returns>是否存在,类型<see cref="bool"/>，存在[true],反之[false]</returns>
	inline bool testFile(const string& file)
	{
		FILE *hFile=fopen(file.c_str(),"r") ;
	    if(hFile==0) 
		{
			return false;
		}
		else
		{
			fclose(hFile);
			return true;
		}
	}

	///	<summary>
	///	查询可执行文件,path目录下的
	///	<code>原型：inline string getFilePath(const string&amp; fileName);</code>
	///	</summary>
	///	<param name="fileName">文件名</param>
	///	<returns>完整的文件名路径</returns>
	inline string getFilePath(const string& fileName)
	{
		FILE * hFile;
		char szBuff[256];	
		hFile=POPEN((SEARCH_CMD+fileName).c_str(),"r");
		if(!hFile)
			EXP("执行文件查找命令失败");
		string filePath="";
		if(fgets(szBuff, sizeof(szBuff)-1, hFile))
		{
			filePath=szBuff;
			filePath[filePath.size()-1]=0;
			if(!testFile(filePath))
				filePath="";
		}
		PCLOSE(hFile);
		return filePath;
	}
	///	<summary>
	///	获取环境变量值
	///	<code>原型：inline string getEnv(const string &amp; name);</code>
	///	</summary>
	///	<param name="name">变量名</param>
	///	<returns>环境变量值</returns>
	inline string getEnv(const string & name)
	{
		char* val = getenv(name.c_str());
		if(val==NULL)return "";
		return val;
	}
	inline String getHostName()
	{
		String hostName="";
		FILE * hostname;
		char szBuff[100];	
		hostname=POPEN("hostname","r");
		if(!hostname)EXP("获取本机名称失败");
		if(fgets(szBuff, sizeof(szBuff)-1, hostname))
		{
			szBuff[strlen(szBuff)-1]=0;
			hostName=szBuff;
		}
		PCLOSE(hostname);
		return hostName;
	};
	inline String getHostIP(String hostName="")
	{
		if(hostName.Trim()=="")
			hostName=getHostName();
		struct hostent *phe ;
		if ((phe = gethostbyname( hostName.c_str()))==NULL)
		{
			return hostName;
		}
		struct in_addr in;
		memcpy((char *)&in, phe->h_addr, phe->h_length);
		return inet_ntoa(in);
	};
	inline Array<String> getHostIPs(String hostName="")
	{
		Array<String> res;
		if(hostName.Trim()=="")
			hostName=getHostName();
		union
		{
			struct sockaddr    sa;
			struct sockaddr_in sin;
		} sadin ;
		struct hostent *phe ;
		if ((phe = gethostbyname( hostName.c_str()))==NULL)
			return res;
		struct in_addr in;
		int i=0;
		while(phe->h_addr_list[i])
		{
			memcpy((char *)&in, phe->h_addr_list[i], phe->h_length);
			res.push_back( inet_ntoa(in));
			i++;
		}
		return res;
	};
#if OSTYPE>10
	//通过网卡名称获取IP
	inline String getIPbyNetCard(String name)
	{
		char *local_ip;
        struct sockaddr_in *my_ip;
        struct sockaddr_in myip;
        my_ip = &myip;
        struct ifreq ifr;
        int sock;
        if((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
        {
                return 1;
        }
		strcpy(ifr.ifr_name,name.c_str());
        if(ioctl(sock, SIOCGIFADDR, &ifr) < 0)
        {
                return 1;
        }
        my_ip->sin_addr = ((struct sockaddr_in *)(&ifr.ifr_addr))->sin_addr;
        local_ip = inet_ntoa(my_ip->sin_addr);
        close(sock);
		return local_ip;
	};
#endif
	inline string operator+(const int b,const string a)
	{
		//int ss=1;test
		char t[12];
		sprintf(t,"%d",b);
		return t+a;
	}
	inline string operator+(const string a,const int b)
	{
		char t[12];
		sprintf(t,"%d",b);
		return a+t;
	}
	inline string operator+(const long b,const string a)
	{
		char t[12];
		sprintf(t,"%ld",b);
		return t+a;
	}
	inline string operator+(const string a,const long b)
	{
		char t[12];
		sprintf(t,"%ld",b);
		return a+t;
	}
	inline string operator+(const double b,const string a)
	{
		char t[12];
		sprintf(t,"%f",b);
		return t+a;
	}
	inline string operator+(const string a,const double b)
	{
		char t[12];
		sprintf(t,"%f",b);
		return a+t;
	}

#define ELEM(i)   arr[i-1]
#define SWAP(i,j) temp = ELEM(i), ELEM(i) = ELEM(j), ELEM(j) = temp
	template <class className> void sort(Array<className> & arr,int (compare)(className & val1,className & val2))
	{
		int i, j, k, n = arr.size();
		className temp;
		if (n <= 1) 
		{ 
			return;
		}
		for (i = n/2, j = i; i >= 1; i--) 
		{ 
			k = i;
			className topId = ELEM(k);
			do
			{ 
				if (k*2 == n || (*compare)(ELEM(k*2), ELEM(k*2+1)) > 0) 
				{ 
					if ((*compare)(topId, ELEM(k*2)) >= 0) 
					{
						break;
					}
					ELEM(k) = ELEM(k*2);
					k = k*2;
				}
				else
				{ 
					if ((*compare)(topId, ELEM(k*2+1)) >= 0)
					{
						break;
					}
					ELEM(k)= ELEM(k*2+1);
					k = k*2+1;
				}
			} while (k <= j);
			ELEM(k) = topId; 
		}
		for (i = n; i >= 2; i--)
		{ 
			SWAP(1,i);
			className topId = ELEM(1);
			for (k = 1, j = (i-1)/2; k <= j;)
			{ 
				if (k*2 == i-1 || (*compare)(ELEM(k*2), ELEM(k*2+1)) > 0) 
				{
					if ((*compare)(topId, ELEM(k*2)) >= 0) 
					{
						break;
					}
					ELEM(k) = ELEM(k*2);
					k = k*2;
				}
				else
				{ 
					if ((*compare)(topId, ELEM(k*2+1)) >= 0)
					{
						break;
					}
					ELEM(k)= ELEM(k*2+1);
					k = k*2+1;
				}
			} 
			ELEM(k) = topId; 
		}

	}

	template <class className> void sort(Array<className> & arr)
	{
		int i, j, k, n = arr.size();
		className temp;
		if (n <= 1) 
		{ 
			return;
		}
		for (i = n/2, j = i; i >= 1; i--) 
		{ 
			k = i;
			className topId = ELEM(k);
			do
			{ 
				if (k*2 == n || ELEM(k*2) > ELEM(k*2+1))
				{ 
					if (topId>= ELEM(k*2)) 
					{
						break;
					}
					ELEM(k) = ELEM(k*2);
					k = k*2;
				}
				else
				{ 
					if (topId >= ELEM(k*2+1))
					{
						break;
					}
					ELEM(k)= ELEM(k*2+1);
					k = k*2+1;
				}
			} while (k <= j);
			ELEM(k) = topId; 
		}
		for (i = n; i >= 2; i--)
		{ 
			SWAP(1,i);
			className topId = ELEM(1);
			for (k = 1, j = (i-1)/2; k <= j;)
			{ 
				if (k*2 == i-1 || ELEM(k*2) > ELEM(k*2+1))
				{
					if(topId >= ELEM(k*2))
					{
						break;
					}
					ELEM(k) = ELEM(k*2);
					k = k*2;
				}
				else
				{ 
					if (topId >= ELEM(k*2+1))
					{
						break;
					}
					ELEM(k)= ELEM(k*2+1);
					k = k*2+1;
				}
			} 
			ELEM(k) = topId; 
		}
	}
	template <class className> void sort(className *arr,int (compare)(className & val1,className & val2),int size)
	{
		int i, j, k, n = size;
		className temp;
		if (n <= 1) 
		{ 
			return;
		}
		for (i = n/2, j = i; i >= 1; i--) 
		{ 
			k = i;
			className topId = ELEM(k);
			do
			{ 
				if (k*2 == n || (*compare)(ELEM(k*2), ELEM(k*2+1)) > 0) 
				{ 
					if ((*compare)(topId, ELEM(k*2)) >= 0) 
					{
						break;
					}
					ELEM(k) = ELEM(k*2);
					k = k*2;
				}
				else
				{ 
					if ((*compare)(topId, ELEM(k*2+1)) >= 0)
					{
						break;
					}
					ELEM(k)= ELEM(k*2+1);
					k = k*2+1;
				}
			} while (k <= j);
			ELEM(k) = topId; 
		}
		for (i = n; i >= 2; i--)
		{ 
			SWAP(1,i);
			className topId = ELEM(1);
			for (k = 1, j = (i-1)/2; k <= j;)
			{ 
				if (k*2 == i-1 || (*compare)(ELEM(k*2), ELEM(k*2+1)) > 0) 
				{
					if ((*compare)(topId, ELEM(k*2)) >= 0) 
					{
						break;
					}
					ELEM(k) = ELEM(k*2);
					k = k*2;
				}
				else
				{ 
					if ((*compare)(topId, ELEM(k*2+1)) >= 0)
					{
						break;
					}
					ELEM(k)= ELEM(k*2+1);
					k = k*2+1;
				}
			} 
			ELEM(k) = topId; 
		}

	}

	template <class className> void sort(className * arr,int size)
	{
		int i, j, k, n = size;
		className temp;
		if (n <= 1) 
		{ 
			return;
		}
		for (i = n/2, j = i; i >= 1; i--) 
		{ 
			k = i;
			className topId = ELEM(k);
			do
			{ 
				if (k*2 == n || ELEM(k*2) > ELEM(k*2+1))
				{ 
					if (topId>= ELEM(k*2)) 
					{
						break;
					}
					ELEM(k) = ELEM(k*2);
					k = k*2;
				}
				else
				{ 
					if (topId >= ELEM(k*2+1))
					{
						break;
					}
					ELEM(k)= ELEM(k*2+1);
					k = k*2+1;
				}
			} while (k <= j);
			ELEM(k) = topId; 
		}
		for (i = n; i >= 2; i--)
		{ 
			SWAP(1,i);
			className topId = ELEM(1);
			for (k = 1, j = (i-1)/2; k <= j;)
			{ 
				if (k*2 == i-1 || ELEM(k*2) > ELEM(k*2+1))
				{
					if(topId >= ELEM(k*2))
					{
						break;
					}
					ELEM(k) = ELEM(k*2);
					k = k*2;
				}
				else
				{ 
					if (topId >= ELEM(k*2+1))
					{
						break;
					}
					ELEM(k)= ELEM(k*2+1);
					k = k*2+1;
				}
			} 
			ELEM(k) = topId; 
		}
	}
#undef ELEM
#undef SWAP

	static String deCodeConnstr(String dbConnStr)
	{
		char dest[40];
		memset(dest,0,40);
		int index1=dbConnStr.IndexOf('/');
		int index2=dbConnStr.IndexOf('@');
		String user=dbConnStr.SubString(0,index1);
		String pass=dbConnStr.SubString(index1+1,index2-index1-1);
		String url=dbConnStr.SubString(index2+1);
		Decoding::MSLDecode(pass.c_str(),dest);
		dbConnStr=user+"/"+pass+"@"+url;
		return dbConnStr;
	};
	inline static String deCodePass(String pass)
	{
		char dest[40];
		memset(dest,0,40);
		Decoding::MSLDecode(pass.c_str(),dest);
		return dest;
	};
	inline static String enCodePass(String pass)
	{
		char dest[40];
		memset(dest,0,40);
		Encoding::MSLEncode(pass.c_str(),dest);
		return dest;
	};

}
#endif
//
