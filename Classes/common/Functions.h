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

// ժҪ:
//     ��������ͷ�ļ�.
//
//ע�⣺
//		Ϊ���Ч�ʣ���������󶼽���������ò������ݡ�
//
//
// �� ��: ��Զ��
// �� ��: 2007-4-25
// �� ��: 1.0
//
namespace Common
{
	///	<summary>
	///	����ctl�ļ������ݱ�:���ټ��ء������ļ�ͷ,�����������ơ�
	///	<code>ԭ�ͣ�	int  ImportCtlFile( String ctlName,String stlDataName,String dbConnStr,bool direct=false,
	///                             bool parallel=false,int readsize=6553600,int bindsize=6553600,
	///                             int rows=10000,const long skipNum=0,const long loadRowNum=0);</code>
	///	</summary>
	///	<param name="ctlName">ctl����ͷ�ļ�,����<see cref="String"/></param>
	///	<param name="stlDataName">�����ļ�,����<see cref="String"/></param>
	///	<param name="dbConnStr">�������Ӵ�,����<see cref="String"/></param>
	///	<param name="direct">�Ƿ�ʹ��ֱͨ���룬�����������ݿ�汾��Ŀ�����ݿ���ͬʱ����ʹ��,����<see cref="bool"/></param>
	///	<param name="parallel">�Ƿ�֧�Ų���,����<see cref="bool"/></param>
	///	<param name="readsize">��ȡ��С,����<see cref="int"/></param>
	///	<param name="bindsize">���´�С,����<see cref="int"/></param>
	///	<param name="rows">�����ύ��¼����С,����<see cref="int"/></param>
	///	<param name="skipNum">������¼��,����<see cref="int"/></param>
	///	<param name="loadRowNum">�޶����ؼ�¼��,����<see cref="int"/></param>
	///	<returns>����ִ�н���� 0:�ɹ�,1:����У��ʧ�ܣ������ڻ��ֶβ�ƥ���,2:���벻��ȫ,����BAD�ļ�:�ֶ��쳣��,-1:ʧ��</returns>
	int  ImportCtlFile( String ctlName,String stlDataName,String dbConnStr,bool direct=false,bool parallel=false
		,int readsize=6553600,int bindsize=6553600,int rows=10000,const long skipNum=0,const long loadRowNum=0);
	///	<summary>
	///	ִ��sqlldr�ⲿ���á�
	///	<code>ԭ�ͣ�int  Sqlldr(string pCommand);</code>
	///	</summary>
	///	<param name="pCommand">ִ�������ַ���<see cref="String"/></param>
	///	<returns>����ִ�н���� 0:�ɹ�,1:����У��ʧ�ܣ������ڻ��ֶβ�ƥ���,2:���벻��ȫ,����BAD�ļ�:�ֶ��쳣��,-1:ʧ��</returns>
	int  Sqlldr(string pCommand);
	///	<summary>
	///	���ִ��sqlldr�����־�ļ���
	///	<code>ԭ�ͣ�bool CheckSqlldrRet(const char*log_file ,string &amp;out_msg ) ;</code>
	///	</summary>
	///	<param name="log_file">�ļ����ַ���ָ��</param>
	///	<param name="out_msg">������Ϣ<see cref="String"/></param>
	///	<returns>����sqlldrִ�н�����ɹ�[true]����֮���ؼ�[false]</returns>
	bool CheckSqlldrRet(const char*log_file ,string &out_msg ) ;
	///	<summary>
	///	ִ��ϵͳ���á�
	///	<code>ԭ�ͣ�bool System(string pCommand,string &amp;pOutMsg,int&amp; pRetValue);</code>
	///	</summary>
	///	<param name="pCommand">ִ�������ַ���,����<see cref="String"/></param>
	///	<param name="pOutMsg">������Ϣ,����<see cref="String"/></param>
	///	<param name="pRetValue">����ִ�н������ֵ,����<see cref="int"/></param>
	///	<returns>�Ƿ�ִ�гɹ����ɹ�[true]����֮���ؼ�[false]</returns>
	bool System(string pCommand,string &pOutMsg,int& pRetValue);
	///	<summary>
	///	ִ��ϵͳ���á�
	///	<code>ԭ�ͣ�int System(string pCommand,String &amp;pOutMsg);</code>
	///	</summary>
	///	<param name="pCommand">ִ�������ַ���,����<see cref="String"/></param>
	///	<param name="pOutMsg">������Ϣ,����<see cref="String"/></param>
	///	<returns>����ִ�н������ֵ</returns>
	int System(string pCommand,String &pOutMsg);

#if OSTYPE>10
	int  ForkRun(list<string> lst_appName) ;
	int  ForkRun(Array<string> lst_appName);
	int  ForkRun(Array<String> lst_appName);
#endif

	///	<summary>
	///	�����ļ����룬��64λ�����н�����ļ��ţ��ļ���ƫ��λ�ã����ݳ��ȡ�
	///	<code>ԭ�ͣ�inline int decodePos(unsigned long long &amp;pos,int &amp;len)</code>
	///	</summary>
	///	<param name="pos">λ��,����<see cref="unsigned long long"/></param>
	///	<param name="len">����,����<see cref="int"/></param>
	///	<returns>�ļ���</returns>
	inline int decodePos(unsigned long long &pos,int &len)
	{
		unsigned int fileNum=pos>>56;	//8λ�ļ���
		len=pos>>40 & 0xFFFF;			//16λ��С
		pos=pos & 0xFFFFFFFFFFll;			//40�ڲ�λ�ú�
		return fileNum;
	};
	///	<summary>
	///	�����ļ����룬��64λ�����н�����ļ��ţ��ļ���ƫ��λ�ã����ݳ��ȡ�
	///	<code>ԭ�ͣ�inline unsigned long long encodePos(const int &amp;fileNum,const unsigned long long &amp;pos,const int &amp;len)</code>
	///	</summary>
	///	<param name="fileNum">�ļ���,����<see cref="unsigned long long"/></param>
	///	<param name="pos">λ��,����<see cref="unsigned long long"/></param>
	///	<param name="len">����,����<see cref="int"/></param>
	///	<returns>������</returns>
	inline unsigned long long  encodePos(const int &fileNum,const unsigned long long &pos,const int &len)
	{
		unsigned long long res=((unsigned int)fileNum<<16) | ((unsigned int)len);
		return ((res<<40) | pos);
	};

	///	<summary>
	///	��ȡhash����
	///	<code>ԭ�ͣ�inline static void getHashCode(const string &amp; s,unsigned long long &amp;hashCode);</code>
	///	</summary>
	///	<param name="s">�����ַ���,����<see cref="String"/></param>
	///	<param name="hashCode">������ֵ,����<see cref="unsigned long long"/></param>
	inline static void getHashCode(const string & s,unsigned long long &hashCode)
	{
		hashCode=hashMath::hashsp(s);
		hashCode=((hashCode<<32) | hashMath::hashpjw(s));
	}
	///	<summary>
	///	��ȡhash����
	///	<code>ԭ�ͣ�inline static unsigned long long getHashCode(const string &amp; s);</code>
	///	</summary>
	///	<param name="s">�����ַ���,����<see cref="String"/></param>
	///	<returns>�ַ�����hash����ֵ</returns>
	inline static unsigned long long getHashCode(const string & s)
	{
		unsigned long long hashCode;
		getHashCode(s,hashCode);
		return hashCode;
	}
	///	<summary>
	///	��ȡhash����
	///	<code>ԭ�ͣ�inline static void getHashCode(const char *  s,unsigned long long &amp;hashCode);</code>
	///	</summary>
	///	<param name="s">�����ַ���,����charָ��</param>
	///	<param name="hashCode">������ֵ,����<see cref="unsigned long long"/></param>
	inline static void getHashCode(const char * s,unsigned long long &hashCode)
	{
		hashCode=hashMath::hashsp(s);
		hashCode=((hashCode<<32) | hashMath::hashpjw(s));
	}
	///	<summary>
	///	��ȡhash����
	///	<code>ԭ�ͣ�inline static unsigned long long getHashCode(const char * s);</code>
	///	</summary>
	///	<param name="s">�����ַ���,����charָ��</param>
	///	<returns>�ַ�����hash����ֵ</returns>
	inline static unsigned long long getHashCode(const char * s)
	{
		unsigned long long hashCode;
		getHashCode(s,hashCode);
		return hashCode;
	}

	///	<summary>
	///	�ļ����ԣ��ж��ļ��Ƿ����
	///	<code>ԭ�ͣ�inline bool testFile(const string&amp; file);</code>
	///	</summary>
	///	<param name="file">�ļ���·��</param>
	///	<returns>�Ƿ����,����<see cref="bool"/>������[true],��֮[false]</returns>
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
	///	��ѯ��ִ���ļ�,pathĿ¼�µ�
	///	<code>ԭ�ͣ�inline string getFilePath(const string&amp; fileName);</code>
	///	</summary>
	///	<param name="fileName">�ļ���</param>
	///	<returns>�������ļ���·��</returns>
	inline string getFilePath(const string& fileName)
	{
		FILE * hFile;
		char szBuff[256];	
		hFile=POPEN((SEARCH_CMD+fileName).c_str(),"r");
		if(!hFile)
			EXP("ִ���ļ���������ʧ��");
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
	///	��ȡ��������ֵ
	///	<code>ԭ�ͣ�inline string getEnv(const string &amp; name);</code>
	///	</summary>
	///	<param name="name">������</param>
	///	<returns>��������ֵ</returns>
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
		if(!hostname)EXP("��ȡ��������ʧ��");
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
	//ͨ���������ƻ�ȡIP
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
