//progame      Common:TcpListener 
//company      hans
//copyright    Copyright (c) hans  2007-4     2008-03
//version      1.0
//Author       hans
//date         2007-4     2009-02
//description  Common namespace
//				This library is free software. Permission to use, copy,
//				modify and redistribute it for any purpose is hereby granted
//				without fee, provided that the above copyright notice appear
//				in all copies.
// ==============================================================

#ifndef __Common_net_Socket__
#define __Common_net_Socket__
//#include "Common.h"
namespace Common
{
	//注意：在Unix系统下，如果recv send函数在等待协议接收数据时网络断开了，那么调用recv的进程会接收到一个SIGPIPE信号，进程对该信号的默认处理是进程终止。
#if OSTYPE>10 
#define SOCKET unsigned int
//#define SOCKET_LEN_T
#define CLOSE_SOCKET(sock) ::close(sock)
#else
#define socklen_t int
#define CLOSE_SOCKET(sock) closesocket(sock)
#endif
#define SOCKET_CHECK if(m_socket==0)EXP("套接字为0,连接异常。")
	NET_NAMESPACE_BEGIN
	class Socket
	{
		void _init(bool bindSock=false);
		static bool socketLibInited;
	public:
		static const int DefaultCloseTimeout = -1;
		static bool Startup(int up=2,int low=1) //默认使用2.1版本
		{
#if OSTYPE<=10
			WORD wVersionRequested;
			WSADATA wsaData;
			int err;
			wVersionRequested = MAKEWORD(up,low );
			err = WSAStartup( wVersionRequested, &wsaData );
			if ( err != 0 )
			{
				// Tell the user that we couldn't find a useable                                     
				// winsock.dll.                                                                      
				perror("未找到可用的winsock.dll");
				return false;
			}
#endif
			return true;
		}
		static void Clearup()
		{
#if OSTYPE<=10
			WSACleanup();
#endif
		}
		bool isListening;
		SOCKET m_socket;			//	socket ID
		ProtocolFamily m_af;		//	地址家族类型
		SocketType m_socketType;	//	socket类型
		ProtocolType m_pcType;		//	控制协议类型

		int m_SendTimeout;			//	发送超时时间	            以微秒为单位  timeval         long    tv_sec;秒  long    tv_usec;  and microseconds 微秒
		int m_SendBufferSize;		//	发送缓冲区大小

		int m_ReceiveBufferSize;	//	接收数据缓冲区大小
		int m_ReceiveTimeout;		//	接收超时时间                以微秒为单位

		int m_CloseTimeout;			//	关闭延时时间                以秒为单位

		bool m_IsConnected;			//	是否已经连接上
		bool m_IsDisconnected;		//	是否可用
		IPAddress m_RemoteEndPoint;	//	远程IP地址节点
		IPAddress m_RightEndPoint;	//	本地IP地址节点
		bool useOverlappedIO;		//	是否使用IO重叠
		static bool UseOverlappedIO;
		bool m_WillBlock;				//	是否阻塞
		bool m_CleanedUp;				//	是否已经清理
		static void MicrosecondsToTimeValue(long long microSeconds, timeval & socketTime);
		static timeval GetMicrosecondsToTimeValue(long long microSeconds);
		Socket(){_init(true);};
		~Socket(){};
		Socket(ProtocolFamily addressFamily, SocketType socketType, ProtocolType protocolType)
		{
			this->m_af=addressFamily;
			this->m_socketType=socketType;
			this->m_pcType=protocolType;
			_init();
		};
//#if OSTYPE>10 
//		Socket(Socket & soc)
//#else
//#endif
		Socket &operator=(Socket soc)

		{
			this->m_socket=soc.m_socket;
			this->m_af=soc.m_af;
			this->m_socketType=soc.m_socketType;
			this->m_pcType=soc.m_pcType;
			this->isListening=soc.isListening;

			this->m_SendTimeout			=	soc.m_SendTimeout;
			this->m_SendBufferSize		=	soc.m_SendBufferSize;
			this->m_ReceiveBufferSize	=	soc.m_ReceiveBufferSize;
			this->m_ReceiveTimeout		=	soc.m_ReceiveTimeout;
			this->m_IsConnected			=	soc.m_IsConnected;
			this->m_IsDisconnected		=	soc.m_IsDisconnected;
			this->m_RemoteEndPoint		=	soc.m_RemoteEndPoint;
			this->m_RightEndPoint		=	soc.m_RightEndPoint;
			this->useOverlappedIO		=	soc.useOverlappedIO;
			this->m_WillBlock			=	soc.m_WillBlock;
			this->m_CleanedUp			=	soc.m_CleanedUp;
#if OSTYPE>10 
#else
			return *this;
#endif
		};
		bool isNull(){return this->m_socket==NULL;};
		inline static String getErrMsg(){return strerror(errno);};
		inline static String getErrMsg(int errCode){return strerror(errCode);};
		inline int getErrCode(){return errno;};
		//     建立与远程主机的连接。
		void Connect(IPAddress remoteEP);
 		//     建立与远程主机的连接。主机由 IP 地址的数组。
		void Connect(Array<IPAddress> & addresses,int port =-1);
		//     建立与远程主机的连接。主机由主机名和端口号指定。
		void Connect(String host, int port);
		//关闭socket 
		void Close();
		void Bind();
		void Bind(IPAddress address);
		//监听时
		void Listen(int backlog=1);
		//接受连接
		Socket Accept();
		//
		// 摘要:
		//     确定一个或多个套接字的状态。
		//
		// 参数:
		//   microSeconds:
		//     超时值（以毫秒为单位）。A -1 值指示超时值为无限大。
		//
		//   checkRead:
		//     要检查可读性的 System.Net.Sockets.Socket 实例的 System.Collections.IList。
		//
		//   checkError:
		//     要检查错误的 System.Net.Sockets.Socket 实例的 System.Collections.IList。
		//
		//   checkWrite:
		//     一个 System.Net.Sockets.Socket 实例的 System.Collections.IList，用于检查可写性。
		static int Select(Array<Socket> * checkRead, Array<Socket> * checkWrite, Array<Socket> * checkError, long long microSeconds);
		static int Select(Array<Socket> & checkList, SelectMode mode,long long microSeconds);
		//对应select函数 microSeconds 毫秒  mode 查询模式
		bool Poll(SelectMode mode,long long microSeconds);
		//   preBuffer:包含发送文件前要发送的数据。此参数可以为null。
		//   postBuffer: 包含发送文件后要发送的数据。此参数可以为null。
		//   fileName: 它包含要发送的文件的路径和名称。此参数可以为null。
		void SendFile(string fileName, char * preBuffer, char * postBuffer);
		//	已发送的字节数。
		inline int SendTo(const char * buffer, IPAddress &remoteEP,SocketFlags socketFlags=0,int * errorCode=NULL)
		{
			return SendTo((void *)buffer, strlen(buffer)+1,remoteEP,socketFlags.value,errorCode);
		};
		//	一个 System.String，它包含要发送的文件的路径和名称。
		void SendFile(string fileName);
		//	关闭套接字 上的发送和接收。
		void Shutdown(SocketShutdown how=2);
 		int getSocketErrorCode();
		int GetReuseAddress();
		bool SetReuseAddress(int value);
 		linger GetLingerState();
		bool SetLingerState(linger value);
		int GetReceiveBufferSize();
		bool SetReceiveBufferSize(int value);
		int GetSendBufferSize();
		bool SetSendBufferSize(int value);
		int GetReceiveTimeout();
		bool SetReceiveTimeout(int value);
		int GetSendTimeout();
		bool SetSendTimeout(int value);
		int GetCloseTimeout();
		bool SetCloseTimeout(int value);
		bool GetNoDelay();
		void SetNoDelay(bool value);
		IPAddress &RemoteEndPoint()	;
		inline ProtocolFamily getAddressFamily(){return m_af;};
		inline bool Connected(){return this->m_IsConnected;};
		//设置socket配置定义选项
		bool SetSocketOption(SocketOptionLevel optionLevel, SocketOptionName optionName, linger optionValue)
		{
			return (setsockopt(m_socket,optionLevel.value,optionName.value,SETSOCKOPT_OPTVAL_TYPE &optionValue,sizeof(optionValue))!=-1);
			 //setsockopt(m_socket,SOL_SOCKET,SO_REUSEADDR,SETSOCKOPT_OPTVAL_TYPE &on,sizeof(on))== -1	//	自动绑定地址
			 // || setsockopt(m_socket,SOL_SOCKET,SO_LINGER,SETSOCKOPT_OPTVAL_TYPE &lng,sizeof(lng)) == -1)  
		};
		bool SetSocketOption(SocketOptionLevel optionLevel, SocketOptionName optionName, int optionValue)
		{
			if(optionLevel==SocketOptionLevel::Socket &&( optionName==SocketOptionName::ReceiveTimeout || optionName==SocketOptionName::SendTimeout))
			{
				struct timeval tv=GetMicrosecondsToTimeValue(optionValue);
				return (setsockopt(m_socket,optionLevel.value,optionName.value,SETSOCKOPT_OPTVAL_TYPE &tv,sizeof(tv))!=-1);
			}
			return (setsockopt(m_socket,optionLevel.value,optionName.value,SETSOCKOPT_OPTVAL_TYPE &optionValue,sizeof(optionValue))!=-1);
		};
		//设置socket配置定义选项
		bool SetSocketOption(SocketOptionLevel optionLevel, SocketOptionName optionName, ip_mreq optionValue)
		{
			return (setsockopt(m_socket,optionLevel.value,optionName.value,SETSOCKOPT_OPTVAL_TYPE &optionValue,sizeof(optionValue))!=-1);
		};
		int GetSocketOption(SocketOptionLevel optionLevel, SocketOptionName optionName)
		{
			if (this->m_CleanedUp)
			{
				EXP("已经清理socket");
			}
			if ((optionLevel == SocketOptionLevel::Socket) && (optionName == SocketOptionName::Linger))
			{
				EXP("socket属性类型不对");
			}
			if ((optionLevel == SocketOptionLevel::IP) && ((optionName == SocketOptionName::AddMembership) || (optionName == SocketOptionName::DropMembership)))
			{
				EXP("socket属性类型不对");
			}
			if ((optionLevel == SocketOptionLevel::IPv6) && ((optionName == SocketOptionName::AddMembership) || (optionName == SocketOptionName::DropMembership)))
			{
				EXP("socket属性类型不对");
			}
			if(optionLevel==SocketOptionLevel::Socket &&( optionName==SocketOptionName::ReceiveTimeout || optionName==SocketOptionName::SendTimeout))
			{
				struct timeval tv;
				if(setsockopt(m_socket,optionLevel.value,optionName.value,SETSOCKOPT_OPTVAL_TYPE &tv,sizeof(tv))!=-1)
				{
					return tv.tv_sec * 1000000 + tv.tv_usec;
				};
				EXP("GetSocketOption 发生错误");
			}
			int optionValue = 0;
			socklen_t optionLength = 4;
			if (getsockopt(this->m_socket, optionLevel.value, optionName.value, (char *) &optionValue, &optionLength) != -1)
			{
				return optionValue;
			}
			EXP("GetSocketOption 发生错误");
		};

		linger GetLingerOpt()
		{
			if (this->m_CleanedUp)
			{
				EXP("已经清理socket");
			}
			linger  optionValue ={0,0};
			socklen_t		optionLength = 4;
			if (getsockopt(this->m_socket, SocketOptionLevel::Socket, SocketOptionName::Linger, (char *)  &optionValue, &optionLength) == -1)
			{
				EXP("getLingerOpt 发生错误");
			}
			return optionValue;
		}
		ip_mreq GetMulticastOpt(SocketOptionName   optionName)
		{
			if (this->m_CleanedUp)
			{
				EXP("已经清理socket");
			}
			ip_mreq   optionValue;
			memset(&optionValue,0,sizeof(ip_mreq));
			socklen_t size = sizeof(ip_mreq);
			if (getsockopt(this->m_socket, SocketOptionLevel::IP, optionName.value,(char *)  &optionValue, &size) == -1)
			{
				EXP("getMulticastOpt 发生错误");
			}
			return optionValue;
		}

		//     接收到的字节数。
		inline int Receive(char * buffer, int size,SocketFlags socketFlags=0,int * errorCode=NULL)
		{
//#if OSTYPE>10 
//			return read(m_socket,buffer,size);		//	unix可以使用read读取
//#endif 
			int res=recv(m_socket,buffer,size,socketFlags.value);
			if(res==-1 && errorCode!=NULL)*errorCode=errno;
			return res;
		};
		//     接收到的字节数。
		inline int ReceiveFrom(char * buf, int len,IPAddress &remoteEP, SocketFlags socketFlags=0,int * errorCode=NULL)
		{
			socklen_t fromlen=sizeof(remoteEP.sadin);
			int res= recvfrom(this->m_socket,buf,len,socketFlags.value ,&remoteEP.sadin.sa,&fromlen);
			if(res==-1 && errorCode!=NULL)*errorCode=errno;
			return res;
		};
		//     已发送到 System.Net.Sockets.Socket 的字节数。
		inline int Send(void * buffer, int size,SocketFlags socketFlags=0,int * errorCode=NULL)
		{
			if(errorCode)*errorCode=0;
			if(buffer==NULL)return -1;
			int res= send(this->m_socket,(const char *)buffer,size,socketFlags.value);
			if(res==-1 && errorCode!=NULL)*errorCode=errno;
			return res;
		};
		//	已发送的字节数。
		inline int SendTo(void * buffer, int size, IPAddress &remoteEP,SocketFlags socketFlags=0,int * errorCode=NULL)
		{
			if(errorCode)*errorCode=0;
			socklen_t fromlen=sizeof(remoteEP.sadin);
			int res= sendto ( this->m_socket ,(const char *) buffer, size, socketFlags.value, &remoteEP.sadin.sa, fromlen ) ;
			if(res==-1 && errorCode!=NULL)*errorCode=errno;
			return res;
		};

 

	};
	NET_NAMESPACE_END
}
#endif
//
