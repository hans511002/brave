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
	//ע�⣺��Unixϵͳ�£����recv send�����ڵȴ�Э���������ʱ����Ͽ��ˣ���ô����recv�Ľ��̻���յ�һ��SIGPIPE�źţ����̶Ը��źŵ�Ĭ�ϴ����ǽ�����ֹ��
#if OSTYPE>10 
#define SOCKET unsigned int
//#define SOCKET_LEN_T
#define CLOSE_SOCKET(sock) ::close(sock)
#else
#define socklen_t int
#define CLOSE_SOCKET(sock) closesocket(sock)
#endif
#define SOCKET_CHECK if(m_socket==0)EXP("�׽���Ϊ0,�����쳣��")
	NET_NAMESPACE_BEGIN
	class Socket
	{
		void _init(bool bindSock=false);
		static bool socketLibInited;
	public:
		static const int DefaultCloseTimeout = -1;
		static bool Startup(int up=2,int low=1) //Ĭ��ʹ��2.1�汾
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
				perror("δ�ҵ����õ�winsock.dll");
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
		ProtocolFamily m_af;		//	��ַ��������
		SocketType m_socketType;	//	socket����
		ProtocolType m_pcType;		//	����Э������

		int m_SendTimeout;			//	���ͳ�ʱʱ��	            ��΢��Ϊ��λ  timeval         long    tv_sec;��  long    tv_usec;  and microseconds ΢��
		int m_SendBufferSize;		//	���ͻ�������С

		int m_ReceiveBufferSize;	//	�������ݻ�������С
		int m_ReceiveTimeout;		//	���ճ�ʱʱ��                ��΢��Ϊ��λ

		int m_CloseTimeout;			//	�ر���ʱʱ��                ����Ϊ��λ

		bool m_IsConnected;			//	�Ƿ��Ѿ�������
		bool m_IsDisconnected;		//	�Ƿ����
		IPAddress m_RemoteEndPoint;	//	Զ��IP��ַ�ڵ�
		IPAddress m_RightEndPoint;	//	����IP��ַ�ڵ�
		bool useOverlappedIO;		//	�Ƿ�ʹ��IO�ص�
		static bool UseOverlappedIO;
		bool m_WillBlock;				//	�Ƿ�����
		bool m_CleanedUp;				//	�Ƿ��Ѿ�����
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
		//     ������Զ�����������ӡ�
		void Connect(IPAddress remoteEP);
 		//     ������Զ�����������ӡ������� IP ��ַ�����顣
		void Connect(Array<IPAddress> & addresses,int port =-1);
		//     ������Զ�����������ӡ��������������Ͷ˿ں�ָ����
		void Connect(String host, int port);
		//�ر�socket 
		void Close();
		void Bind();
		void Bind(IPAddress address);
		//����ʱ
		void Listen(int backlog=1);
		//��������
		Socket Accept();
		//
		// ժҪ:
		//     ȷ��һ�������׽��ֵ�״̬��
		//
		// ����:
		//   microSeconds:
		//     ��ʱֵ���Ժ���Ϊ��λ����A -1 ֵָʾ��ʱֵΪ���޴�
		//
		//   checkRead:
		//     Ҫ���ɶ��Ե� System.Net.Sockets.Socket ʵ���� System.Collections.IList��
		//
		//   checkError:
		//     Ҫ������� System.Net.Sockets.Socket ʵ���� System.Collections.IList��
		//
		//   checkWrite:
		//     һ�� System.Net.Sockets.Socket ʵ���� System.Collections.IList�����ڼ���д�ԡ�
		static int Select(Array<Socket> * checkRead, Array<Socket> * checkWrite, Array<Socket> * checkError, long long microSeconds);
		static int Select(Array<Socket> & checkList, SelectMode mode,long long microSeconds);
		//��Ӧselect���� microSeconds ����  mode ��ѯģʽ
		bool Poll(SelectMode mode,long long microSeconds);
		//   preBuffer:���������ļ�ǰҪ���͵����ݡ��˲�������Ϊnull��
		//   postBuffer: ���������ļ���Ҫ���͵����ݡ��˲�������Ϊnull��
		//   fileName: ������Ҫ���͵��ļ���·�������ơ��˲�������Ϊnull��
		void SendFile(string fileName, char * preBuffer, char * postBuffer);
		//	�ѷ��͵��ֽ�����
		inline int SendTo(const char * buffer, IPAddress &remoteEP,SocketFlags socketFlags=0,int * errorCode=NULL)
		{
			return SendTo((void *)buffer, strlen(buffer)+1,remoteEP,socketFlags.value,errorCode);
		};
		//	һ�� System.String��������Ҫ���͵��ļ���·�������ơ�
		void SendFile(string fileName);
		//	�ر��׽��� �ϵķ��ͺͽ��ա�
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
		//����socket���ö���ѡ��
		bool SetSocketOption(SocketOptionLevel optionLevel, SocketOptionName optionName, linger optionValue)
		{
			return (setsockopt(m_socket,optionLevel.value,optionName.value,SETSOCKOPT_OPTVAL_TYPE &optionValue,sizeof(optionValue))!=-1);
			 //setsockopt(m_socket,SOL_SOCKET,SO_REUSEADDR,SETSOCKOPT_OPTVAL_TYPE &on,sizeof(on))== -1	//	�Զ��󶨵�ַ
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
		//����socket���ö���ѡ��
		bool SetSocketOption(SocketOptionLevel optionLevel, SocketOptionName optionName, ip_mreq optionValue)
		{
			return (setsockopt(m_socket,optionLevel.value,optionName.value,SETSOCKOPT_OPTVAL_TYPE &optionValue,sizeof(optionValue))!=-1);
		};
		int GetSocketOption(SocketOptionLevel optionLevel, SocketOptionName optionName)
		{
			if (this->m_CleanedUp)
			{
				EXP("�Ѿ�����socket");
			}
			if ((optionLevel == SocketOptionLevel::Socket) && (optionName == SocketOptionName::Linger))
			{
				EXP("socket�������Ͳ���");
			}
			if ((optionLevel == SocketOptionLevel::IP) && ((optionName == SocketOptionName::AddMembership) || (optionName == SocketOptionName::DropMembership)))
			{
				EXP("socket�������Ͳ���");
			}
			if ((optionLevel == SocketOptionLevel::IPv6) && ((optionName == SocketOptionName::AddMembership) || (optionName == SocketOptionName::DropMembership)))
			{
				EXP("socket�������Ͳ���");
			}
			if(optionLevel==SocketOptionLevel::Socket &&( optionName==SocketOptionName::ReceiveTimeout || optionName==SocketOptionName::SendTimeout))
			{
				struct timeval tv;
				if(setsockopt(m_socket,optionLevel.value,optionName.value,SETSOCKOPT_OPTVAL_TYPE &tv,sizeof(tv))!=-1)
				{
					return tv.tv_sec * 1000000 + tv.tv_usec;
				};
				EXP("GetSocketOption ��������");
			}
			int optionValue = 0;
			socklen_t optionLength = 4;
			if (getsockopt(this->m_socket, optionLevel.value, optionName.value, (char *) &optionValue, &optionLength) != -1)
			{
				return optionValue;
			}
			EXP("GetSocketOption ��������");
		};

		linger GetLingerOpt()
		{
			if (this->m_CleanedUp)
			{
				EXP("�Ѿ�����socket");
			}
			linger  optionValue ={0,0};
			socklen_t		optionLength = 4;
			if (getsockopt(this->m_socket, SocketOptionLevel::Socket, SocketOptionName::Linger, (char *)  &optionValue, &optionLength) == -1)
			{
				EXP("getLingerOpt ��������");
			}
			return optionValue;
		}
		ip_mreq GetMulticastOpt(SocketOptionName   optionName)
		{
			if (this->m_CleanedUp)
			{
				EXP("�Ѿ�����socket");
			}
			ip_mreq   optionValue;
			memset(&optionValue,0,sizeof(ip_mreq));
			socklen_t size = sizeof(ip_mreq);
			if (getsockopt(this->m_socket, SocketOptionLevel::IP, optionName.value,(char *)  &optionValue, &size) == -1)
			{
				EXP("getMulticastOpt ��������");
			}
			return optionValue;
		}

		//     ���յ����ֽ�����
		inline int Receive(char * buffer, int size,SocketFlags socketFlags=0,int * errorCode=NULL)
		{
//#if OSTYPE>10 
//			return read(m_socket,buffer,size);		//	unix����ʹ��read��ȡ
//#endif 
			int res=recv(m_socket,buffer,size,socketFlags.value);
			if(res==-1 && errorCode!=NULL)*errorCode=errno;
			return res;
		};
		//     ���յ����ֽ�����
		inline int ReceiveFrom(char * buf, int len,IPAddress &remoteEP, SocketFlags socketFlags=0,int * errorCode=NULL)
		{
			socklen_t fromlen=sizeof(remoteEP.sadin);
			int res= recvfrom(this->m_socket,buf,len,socketFlags.value ,&remoteEP.sadin.sa,&fromlen);
			if(res==-1 && errorCode!=NULL)*errorCode=errno;
			return res;
		};
		//     �ѷ��͵� System.Net.Sockets.Socket ���ֽ�����
		inline int Send(void * buffer, int size,SocketFlags socketFlags=0,int * errorCode=NULL)
		{
			if(errorCode)*errorCode=0;
			if(buffer==NULL)return -1;
			int res= send(this->m_socket,(const char *)buffer,size,socketFlags.value);
			if(res==-1 && errorCode!=NULL)*errorCode=errno;
			return res;
		};
		//	�ѷ��͵��ֽ�����
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
