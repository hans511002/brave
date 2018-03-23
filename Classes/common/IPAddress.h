//progame      Common:TcpListener 
//company      hans
//copyright    Copyright (c) hans  2007-4     2008-03
//version      1.0
//Author       hans
//date         2007-4     2009-04
//description  Common namespace
//				This library is free software. Permission to use, copy,
//				modify and redistribute it for any purpose is hereby granted
//				without fee, provided that the above copyright notice appear
//				in all copies.
// ==============================================================

#ifndef __Common_net_IPAddress__
#define __Common_net_IPAddress__
//#include "Common.h"
#ifndef SETSOCKOPT_OPTVAL_TYPE
#define SETSOCKOPT_OPTVAL_TYPE (const char  *)
#endif
namespace Common
{
NET_NAMESPACE_BEGIN

	typedef  char byte;
	class IPAddress//SOCKADDR_IN
	{
	public :
		static const int maxPort;
		static const int minPort;
		union
		{
			struct sockaddr    sa;
			struct sockaddr_in sin;
		} sadin ;
		bool inited;
		bool isNull(){return !inited;};
		void _init(const Common::String & ipString, int port)
		{
			if (ipString=="")
			{
				EXP("hostname is null");
			}
			if (port>65535 || port<0)
			{
				EXP("port error, port=["+String(port)+"]");
			}
			if(port>maxPort)EXP("传入端口号大于端口最大值"+String(maxPort));
			if(port<minPort)EXP("传入端口号小于端口最大值"+String(minPort));
			sadin.sin.sin_port = htons(port);
			//将点分隔地址转换成长整数                                    
			if ((sadin.sin.sin_addr.s_addr = inet_addr(ipString.c_str())) == -1)
			{
				//失败,表明输入的是主机名,通过系统配置转换名为地址                                    
				//通过IP获取主机信息 gethostbyaddr(inet_addr(m_host.c_str()),sizeof(long),AF_INET)
				struct hostent *phe ;
				if ((phe = gethostbyname(SETSOCKOPT_OPTVAL_TYPE ipString.c_str()))==NULL)
				{
					EXP("gethostbyname failed");
					return;
				}
				memcpy((char *)&sadin.sin.sin_addr, phe->h_addr, phe->h_length);
			}
			sadin.sin.sin_family = AF_INET ;	//	默认inet地址协议
			inited=true;
		};
		IPAddress(const Common::String & ipString, int port){memset(&sadin,0,sizeof(sadin));_init(ipString,port);};
		IPAddress(Common::String ipString)
		{
			memset(&sadin,0,sizeof(sadin));
			int index=ipString.IndexOf(':');
			if(index>0)
			{
				_init(ipString.SubString(0,index),atoi(ipString.SubString(index+1).c_str()));
			}
			else
			{
				_init(ipString,0);
				//EXP("指定的IP串不存在端口号");
			}
		};
		IPAddress(){memset(&sadin,0,sizeof(sadin));inited=false;sadin.sin.sin_family = AF_INET ;};
		IPAddress(int port){memset(&sadin,0,sizeof(sadin));inited=false;sadin.sin.sin_port = htons(port);sadin.sin.sin_family = AF_INET ;};
		void setPort(int port)
		{
			if (port>65535 || port<0)
			{
				EXP("port error, port=["+String(port)+"]");
			}
			sadin.sin.sin_port = htons(port);
		};
		void setHost(String ip)
		{
			if (ip=="")
			{
				EXP("hostname is null");
			}
			//将点分隔地址转换成长整数                                    
			if ((sadin.sin.sin_addr.s_addr = inet_addr(ip.c_str())) == -1)
			{
				//失败,表明输入的是主机名,通过系统配置转换名为地址                                    
				//通过IP获取主机信息 gethostbyaddr(inet_addr(m_host.c_str()),sizeof(long),AF_INET)
				struct hostent *phe ;
				if ((phe = gethostbyname(SETSOCKOPT_OPTVAL_TYPE ip.c_str()))==NULL)
				{
					EXP("gethostbyname failed");
					return;
				}
				memcpy((char *)&sadin.sin.sin_addr, phe->h_addr, phe->h_length);
			}
			if(sadin.sin.sin_port!=0)inited=true;
		};
		void setAf(int value)
		{
			this-> sadin.sin.sin_family = value ;
		}
		int getAf()
		{
			return this->sadin.sin.sin_family;
		}
		bool IsBroadcast()
		{
			return (int)sadin.sin.sin_addr.s_addr==(int)htonl(INADDR_BROADCAST) ;//sadin.sin.sin_addr.s_addr
		}
		void setAny()
		{
			sadin.sin.sin_addr.s_addr=htonl(INADDR_ANY) ;
		};
		static void setAny(IPAddress &address)
		{
			address.sadin.sin.sin_addr.s_addr=htonl(INADDR_ANY) ;
		};
		bool setBroadcast()
		{
			sadin.sin.sin_addr.s_addr=htonl(INADDR_BROADCAST) ;
		}
		static bool setBroadcast(IPAddress &address)
		{
			address.sadin.sin.sin_addr.s_addr=htonl(INADDR_BROADCAST) ;
		}
		string ToString()
		{
			string s=inet_ntoa(this->sadin.sin.sin_addr);
			s=s+":"+String(this->sadin.sin.sin_port);
			return s;
			//char name[32];memset(name,0,32);
			//gethostname(name,32);
			//return name;
		};
		String getHost()
		{
			return inet_ntoa(this->sadin.sin.sin_addr);
		};
		int getPort()
		{
			return this->sadin.sin.sin_port;
		};
	//#define INADDR_ANY              (u_long)0x00000000
	//#define INADDR_LOOPBACK         0x7f000001
	//#define INADDR_BROADCAST        (u_long)0xffffffff
	//#define INADDR_NONE             0xffffffff
	};
	inline static bool ValidateRange(int actual, int fromAllowed, int toAllowed)
	{
		return ((actual >= fromAllowed) && (actual <= toAllowed));
	}
	inline static addrinfo * getAddrInfo(const char *hostname,const char *service
		,addrinfo hints)
	{
		struct addrinfo *result;
		if(getaddrinfo(hostname , service, &hints,&result)==0)
			return result; 
		else
			return NULL;
	}
	inline static bool ValidateTcpPort(int port)
	{
		return ((port >= 0) && (port <= 0xffff));
	}
	inline static void GetHostAddresses(Array<IPAddress> & addresses,string name,int port )
	{
		addresses.clear();
		struct sockaddr_in sin;
		//将点分隔地址转换成长整数                                    
		if ((sin.sin_addr.s_addr = inet_addr(name.c_str())) == -1)
		{
			//失败,表明输入的是主机名,通过系统配置转换名为地址                                    
			//通过IP获取主机信息 gethostbyaddr(inet_addr(m_host.c_str()),sizeof(long),AF_INET)
			struct hostent *phe ;
			if ((phe = gethostbyname(SETSOCKOPT_OPTVAL_TYPE name.c_str()))==NULL)
			{
				EXP("gethostbyname failed");
				return;
			}
			int i=0;
			while(phe->h_addr_list[i])
			{
				memcpy((char *)(&addresses[i].sadin.sin.sin_addr), phe->h_addr_list[i], phe->h_length);
				addresses[i].sadin.sin.sin_port=htons(port);
				addresses[i].inited=true;
				addresses[i].sadin.sin.sin_family = AF_INET ;	//	默认inet地址协议
				i++;
			}
		}
		else
		{
			addresses[0].sadin.sin=sin;
			addresses[0].sadin.sin.sin_port=htons(port);
			addresses[0].sadin.sin.sin_family = AF_INET ;	//	默认inet地址协议
			addresses[0].inited=true;
		}
	}
	inline static Array<IPAddress> GetHostAddresses(string name="",int port=0 )
	{
		Array<IPAddress> addresses;
		GetHostAddresses(addresses,name,port );
		return addresses;
	}
NET_NAMESPACE_END
}
#endif
//
