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
//#include "Common.h"
#define CPP_FILE 9
#include "Common.h" // "includeHead.h"

namespace Common
{
	NET_NAMESPACE_BEGIN
	bool Socket::socketLibInited=false;
	void Socket::_init(bool bindSock)
	{
		isListening=false;
		m_socket=0;

		m_CloseTimeout=0;

		m_SendTimeout=0;				//Ĭ������  262140=65535*4
		m_SendBufferSize=262144;		//256k

		m_ReceiveBufferSize=262144;		//65536*4;
		m_ReceiveTimeout=0;

		m_IsConnected=false;
		m_IsDisconnected=false;
		useOverlappedIO=false;
		m_WillBlock=true;
		m_CleanedUp=false;
		if(bindSock)
		{
			m_af.value=ProtocolFamily::InterNetwork;
			m_socketType=SocketType::Stream;
			m_pcType.value=ProtocolType::Tcp;
		}
		if(socketLibInited==false)
		{
			this->Startup();
			socketLibInited=true;
		}
		//int sc=socket(m_af.value,m_socketType.value,m_pcType.value);
		m_socket = socket(m_af.value,m_socketType.value,m_pcType.value);
		if (m_socket == -1)
		{
			m_socket=0;
			m_IsDisconnected=true;
		}
	};
	void Socket::MicrosecondsToTimeValue(long long microSeconds, timeval & socketTime)
	{
		socketTime.tv_sec=int(microSeconds / 0xf4240);
		socketTime.tv_usec = int(microSeconds % 0xf4240);
	}
	timeval Socket::GetMicrosecondsToTimeValue(long long microSeconds)
	{
		timeval socketTime;
		socketTime.tv_sec=int(microSeconds / 0xf4240);
		socketTime.tv_usec = int(microSeconds % 0xf4240);
		return socketTime;
	};
	//	�ر��׽��� �ϵķ��ͺͽ��ա�
	void Socket::Shutdown(SocketShutdown how)
	{
		if(this->m_socket>0)
		{
			shutdown(m_socket,how.value);
		}
	};
	int Socket::getSocketErrorCode()
	{
		return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::Error);
	};
	int Socket::GetReuseAddress()
	{
		if (this->m_af == ProtocolFamily::InterNetwork)
		{
			return this->GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ReuseAddress);
		}
		//if (m_af != ProtocolFamily::InterNetworkV6)
		//{
		//	throw __gc new NotSupportedException(SR::GetString(S"net_invalidversion"));
		//}
		//return this->GetSocketOption(SocketOptionLevel::IPv6, SocketOptionName::ReuseAddress);
		return 0;
	};
	bool Socket::SetReuseAddress(int value)
	{
		if ((value < -1) || ((value == -1) && (m_af != ProtocolFamily::InterNetworkV6)))
		{
			EXP("ArgumentOutOfRangeException( value )");
		}
		if (m_af == ProtocolFamily::InterNetwork)
		{
			return this->SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ReuseAddress, value);
		}
		//else
		//{
		//	if (m_af != ProtocolFamily::InterNetworkV6)
		//	{
		//		throw __gc new NotSupportedException(SR::GetString(S"net_invalidversion"));
		//	}
		//	this->SetSocketOption(SocketOptionLevel::IPv6, SocketOptionName::ReuseAddress, *static_cast<__box Int32*>(value));
		//}
		return false;
	};
	linger Socket::GetLingerState()
	{
		return this->GetLingerOpt();
	};
	bool Socket::SetLingerState(linger value)
	{
		return this->SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::Linger, value);
	};
	int Socket::GetReceiveBufferSize()
	{
		return this->GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ReceiveBuffer);
	};
	bool Socket::SetReceiveBufferSize(int value)
	{
		this->m_ReceiveBufferSize=value;
		return this->SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ReceiveBuffer, value);
	};
	int Socket::GetSendBufferSize()
	{
		return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::SendBuffer);
	};
	bool Socket::SetSendBufferSize(int value)
	{
		this->m_SendBufferSize=value;
		return this->SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::SendBuffer, value);
	};
	int Socket::GetReceiveTimeout()
	{
		return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ReceiveTimeout);
	};
	bool Socket::SetReceiveTimeout(int value)
	{
		this->m_ReceiveTimeout=value;
		return this->SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ReceiveTimeout, value);
	};
	int Socket::GetSendTimeout()
	{
		return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::SendTimeout);
	};
	bool Socket::SetSendTimeout(int value)
	{
		this->m_SendTimeout=value;
		return this->SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::SendTimeout, value);
	};
	int Socket::GetCloseTimeout()
	{
		return this->m_CloseTimeout;
	};
	bool Socket::SetCloseTimeout(int value)
	{
		this->m_CloseTimeout=value;
		linger lng;
		if(value>0)
		{
			lng.l_onoff=1;
		}
		lng.l_linger=value;
		if(SetLingerState(lng)==false)
		{
			return false;
		}
		return true;
	};
	bool Socket::GetNoDelay()
	{
		if (this->GetSocketOption(SocketOptionLevel::Tcp, SocketOptionName::NoDelay) == 0)
		{
			return false;
		}
		return true;
	};
	void Socket::SetNoDelay(bool value)
	{
		this->SetSocketOption(SocketOptionLevel::Tcp, SocketOptionName::NoDelay, (value ? 1 : 0));
	};
	IPAddress & Socket::RemoteEndPoint()
	{
		return this->m_RemoteEndPoint;
	}



	//   preBuffer:���������ļ�ǰҪ���͵����ݡ��˲�������Ϊnull��
	//   postBuffer: ���������ļ���Ҫ���͵����ݡ��˲�������Ϊnull��
	//   fileName: ������Ҫ���͵��ļ���·�������ơ��˲�������Ϊnull��
	void Socket::SendFile(string fileName, char * preBuffer, char * postBuffer)
	{
		Send(preBuffer,strlen(preBuffer));
		FILE * dFile=fopen(fileName.c_str(),"rb");
		subFileStream sf(dFile);
		char buffer[2048];
		int len=0;
		memset(buffer,0,2048);
		while((len=fread(buffer,1,2048,dFile))>0)
		{
			if(Send(buffer,len)!=len)break;
			memset(buffer,0,2048);
		}
		Send(postBuffer,strlen(postBuffer));
	};
	void Socket::SendFile(string fileName)
	{
		SendFile(fileName, NULL, NULL);
	};
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
	int Socket::Select(Array<Socket> * checkRead, Array<Socket> * checkWrite, Array<Socket> * checkError, long long microSeconds)
	{
		struct timeval tv;
		if(microSeconds>=0)
			tv=GetMicrosecondsToTimeValue(microSeconds) ;
		int maxSocket=0;
		fd_set readfds ;FD_ZERO(&readfds);
		fd_set writefds ;FD_ZERO(&writefds);
		fd_set errorfds ;FD_ZERO(&errorfds);
		if(checkRead)
		for(int i=0;i<checkRead->size();i++)
		{
			FD_SET(checkRead->at(i).m_socket, &readfds);
			if(maxSocket<checkRead->at(i).m_socket)
				maxSocket=checkRead->at(i).m_socket;
		}
		if(checkWrite)
		for(int i=0;i<checkWrite->size();i++)
		{
			FD_SET(checkWrite->at(i).m_socket, &readfds);
			if(maxSocket<checkWrite->at(i).m_socket)
				maxSocket=checkWrite->at(i).m_socket;
		}
		if(checkError)
		for(int i=0;i<checkError->size();i++)
		{
			FD_SET(checkError->at(i).m_socket, &readfds);
			if(maxSocket<checkError->at(i).m_socket)
				maxSocket=checkError->at(i).m_socket;
		}
		int iRet = select(maxSocket+1, (checkRead!=NULL)?&readfds:NULL,(checkWrite!=NULL)?&writefds:NULL,(checkError!=NULL)?&errorfds:NULL,((microSeconds>=0)?&tv:NULL)) ;

		if(iRet>0)
		{
			if(checkRead)
			{
				for(int i=0;i<checkRead->size();i++)
				{
					if(FD_ISSET(checkRead->at(i).m_socket,&readfds)==0)
					{
						checkRead->remove(i);
						i--;
					}
				}
			}
			if(checkWrite)
			{
				for(int i=0;i<checkWrite->size();i++)
				{
					if(FD_ISSET(checkWrite->at(i).m_socket,&writefds)==0)
					{
						checkWrite->remove(i);
						i--;
					}
				}
			}
			if(checkError)
			{
				for(int i=0;i<checkError->size();i++)
				{
					if(FD_ISSET(checkError->at(i).m_socket,&errorfds)==0)
					{
						checkError->remove(i);
						i--;
					}
				}
			}
		}
		return iRet;
	};


	int Socket::Select(Array<Socket> & checkList, SelectMode mode,long long microSeconds)
	{
		struct timeval tv;
		if(microSeconds>=0)
			tv=GetMicrosecondsToTimeValue(microSeconds) ;
		int maxSocket=0;
		fd_set mask ;
		FD_ZERO(&mask);
		int clen=checkList.size();
		for(int i=0;i<clen;i++)
		{
			FD_SET(checkList.at(i).m_socket, &mask);
			if(maxSocket<checkList.at(i).m_socket)
				maxSocket=checkList.at(i).m_socket;
		}
		int i = select(maxSocket+1, (mode.value==0?&mask:NULL), (mode.value==1?&mask:NULL), (mode.value==2?&mask:NULL), ((microSeconds>=0)?&tv:NULL));
		if (i == -1)
		{
			EXP(strerror(errno));
		}
		else
		{
			for(int i=0;i<clen;i++)
			{
				if(FD_ISSET(checkList.at(i).m_socket,&mask)==0)
				{
					return i;
				}
			}
			return -1;
		}
	};
	//��Ӧselect���� microSeconds ����  mode ��ѯģʽ
	bool Socket::Poll( SelectMode mode,long long microSeconds)
	{
		if (this->m_CleanedUp)
		{
			EXP("�Ѿ����Socket������������");
		}
		struct timeval tv;
		if(microSeconds>=0)
			tv=this->GetMicrosecondsToTimeValue(microSeconds) ;
		fd_set mask ;
		FD_ZERO(&mask);
		FD_SET(this->m_socket, &mask); 

		int i = select(this->m_socket+1, (mode.value==0?&mask:NULL), (mode.value==1?&mask:NULL), (mode.value==2?&mask:NULL), ((microSeconds>=0)?&tv:NULL));
		if (i == -1)
		{
			Close() ;
			EXP(strerror(errno));
		}
		else
		{
			return (FD_ISSET(m_socket, &mask))>0;
		}
	}
	Socket Socket::Accept()
	{
		if (m_CleanedUp)				//	�Ѿ�����Socket
		{
			EXP("�Ѿ����Socket�������ٽ���������");
		}
		if (!isListening)			//	���Ǽ���״̬
		{
			EXP("net_sockets_mustlisten");
		}
		if (m_IsDisconnected)		//	��������
		{
			EXP("net_sockets_disconnectedAccept");
		}
		socklen_t len=sizeof(m_RemoteEndPoint.sadin.sa);
		SOCKET hSocketNew = accept(m_socket, &m_RemoteEndPoint.sadin.sa, &len);
		if (hSocketNew > 0)
		{
			Socket sc;
			sc.m_socket=hSocketNew;
			sc.m_af=this->m_af;
			sc.m_socketType=this->m_socketType;
			sc.m_pcType=this->m_pcType;
			sc.isListening=false;

			sc.m_SendTimeout		=	this->m_SendTimeout;
			sc.m_SendBufferSize		=	this->m_SendBufferSize;
			sc.m_ReceiveBufferSize	=	this->m_ReceiveBufferSize;
			sc.m_ReceiveTimeout		=	this->m_ReceiveTimeout;
			sc.m_IsConnected		=	this->m_IsConnected;
			sc.m_IsDisconnected		=	this->m_IsDisconnected;
			sc.m_RemoteEndPoint		=	this->m_RemoteEndPoint;
			sc.m_RightEndPoint		=	this->m_RightEndPoint;
			sc.useOverlappedIO		=	this->useOverlappedIO;
			sc.m_WillBlock			=	this->m_WillBlock;
			sc.m_CleanedUp			=	this->m_CleanedUp;
			return sc;
		}
		else
		{
			EXP(strerror(errno));
		}
	};
	//����ʱ
	void Socket::Listen(int backlog)
	{
		//struct linger lng = { 0, 0 }; // �ر���ʱ
		//if (this->SetReuseAddress(1)==false //int on=1; setsockopt(m_socket,SOL_SOCKET,SO_REUSEADDR,SETSOCKOPT_OPTVAL_TYPE &on,sizeof(on))== -1
		//	|| this->SetLingerState(lng)==false )//setsockopt(m_socket,SOL_SOCKET,SO_LINGER,SETSOCKOPT_OPTVAL_TYPE &lng,sizeof(lng))== -1 )
		///m_RightEndPoint.sadin.sin.sin_port=0 ;			//�Զ˿ں�Ϊ0����bind��,ʹ��getsockname�����ں˷���ı��ض˿ں�

		if (listen(m_socket, backlog)<0)
		{
			Close();
			EXP("������������");
		}
		socklen_t len=sizeof(m_RightEndPoint.sadin.sa);
		if (getsockname(m_socket, &m_RightEndPoint.sadin.sa, &len)<0)
			EXP("��ȡ���ذ󶨵�ַ�Ͷ˿ڷ�������");
		this->isListening=true;
	};
	//     ������Զ�����������ӡ�
	void Socket::Connect(IPAddress remoteEP)
	{
		SOCKET_CHECK
		if (this->m_CleanedUp)
		{
			EXP("�Ѿ����Socket������������");
		}
		if(m_IsConnected)EXP("Socket�Ѿ����ӵ�һ��������������������");
		if(remoteEP.inited==false)//(remoteEP.sadin.sin.sin_port==0) //(const sockaddr *)&sin,
		{
			EXP("δ��ʼ��Զ�����ӵ�ַ�ڵ�");
		}
		if (m_IsDisconnected)		//	��������
		{
			EXP("net_sockets_disconnectedConnect");
		}
		if (isListening)
		{
			EXP("net_sockets_mustnotlisten");
		}
		this->m_RemoteEndPoint=remoteEP;
		//����socket����,��<bind addr in  use>֮��   ���õ�ַ
		if (SetReuseAddress(1)==false)//int on =1 ;setsockopt(m_socket,SOL_SOCKET,SO_REUSEADDR,SETSOCKOPT_OPTVAL_TYPE &on, sizeof(on)) == -1
		{
			EXP("�󶨱��ص�ַʧ��");
			Close();
		}
  		int bufsize = 65535*4 ;
  		if(setsockopt(m_socket,SOL_SOCKET,SO_RCVBUF,SETSOCKOPT_OPTVAL_TYPE &bufsize,sizeof(bufsize))==-1)
		{
			EXP("�������ݽ��ջ�����ʧ��");
			Close();
		}
		//if(SetReceiveBufferSize(this->m_ReceiveBufferSize)==false)
		//
		if(setsockopt(m_socket,SOL_SOCKET,SO_RCVBUF,SETSOCKOPT_OPTVAL_TYPE &m_ReceiveBufferSize,sizeof(m_ReceiveBufferSize))==-1) 
		{
			EXP("�������ݽ��ջ�����ʧ��");
			Close();
		}
		linger lng;
		if(m_CloseTimeout>0)
		{
			lng.l_onoff=1;
		}
		lng.l_linger=m_CloseTimeout;
		if(SetLingerState(lng)==false)
		{
			EXP("�����׽��ֹر���ʱʧ��");
		}
		if (connect(m_socket, (const sockaddr *)(&m_RemoteEndPoint.sadin.sin), sizeof(m_RemoteEndPoint.sadin.sin)) == -1) //���ӵ�Զ�̷������˿�
		{
			EXP("���ӷ�������ʧ��");
			Close();
		}
		m_IsConnected=true;
	};
	//     ������Զ�����������ӡ������� IP ��ַ�����顣
	void Socket::Connect(Array<IPAddress> & addresses,int port)
	{
		SOCKET_CHECK
		if ((this->m_af.value!= ProtocolFamily::InterNetwork) && (this->m_af.value != ProtocolFamily::InterNetworkV6))
		{
			EXP("net_invalidversion");
		}
		if (this->m_CleanedUp)
		{
			EXP("�Ѿ����Socket������������");
		}
		if(m_IsConnected)EXP("Socket�Ѿ����ӵ�һ��������������������");
		if (m_IsDisconnected)		//	��������
		{
			EXP("net_sockets_disconnectedConnect");
		}
		if (isListening)
		{
			EXP("net_sockets_mustnotlisten");
		}
		//����socket����,��<bind addr in  use>֮��                                    
		if (SetReuseAddress(1)==false)//int on =1 ;setsockopt(m_socket,SOL_SOCKET,SO_REUSEADDR,SETSOCKOPT_OPTVAL_TYPE &on, sizeof(on)) == -1
		{
			EXP("�󶨱��ص�ַʧ��");
			Close();
		}
		linger lng;
		if(m_CloseTimeout>0)
		{
			lng.l_onoff=1;
		}
		lng.l_linger=m_CloseTimeout;
		if(SetLingerState(lng)==false)
		{
			EXP("�����׽��ֹر���ʱʧ��");
		}
		for(int i=0;i<addresses.size();i++)
		{
			if(addresses[i].inited==false)//(remoteEP.sadin.sin.sin_port==0) //(const sockaddr *)&sin,
			{
				continue;
			}
			this->m_RemoteEndPoint=addresses[i];
			if(port!=-1)
				this->m_RemoteEndPoint.setPort(port);
			if (connect(m_socket, (const sockaddr *)(&m_RemoteEndPoint.sadin.sin), sizeof(m_RemoteEndPoint.sadin.sin)) == -1) //���ӵ�Զ�̷������˿�
			{
				if(i<addresses.size()-1)
					continue;
				else
				{
					EXP("���ӷ�������ʧ��");
					Close();
				}
			}
			else
				break;
		}
		m_IsConnected=true;
	};
	//     ������Զ�����������ӡ��������������Ͷ˿ں�ָ����
	void Socket::Connect(String host, int port)
	{
		SOCKET_CHECK
		if (host=="")
		{
			EXP("hostname is null");
		}
		if (port>65535 || port<0)
		{
			EXP("port error, port=["+String(port)+"]");
		}
		Array<IPAddress> addresses;
		GetHostAddresses(addresses,host,port );
		if(addresses.size()==1)
		{
			Connect(addresses[0]);
		}
		else
		{
			Connect(addresses);
		}
	};
	//�ر�socket 
	void Socket::Close()
	{
		if(this->m_socket>0)
		{
		//	Shutdown(2);
			CLOSE_SOCKET(this->m_socket);
			this->m_socket=0;
		}
	};
	void Socket::Bind()
	{
		if (::bind(m_socket, &m_RightEndPoint.sadin.sa, sizeof(m_RightEndPoint.sadin.sa)) == -1)
		{
			Close();
			EXP("�󶨵�ַ��������");
		}
	};
	void Socket::Bind(IPAddress address)
	{
		this->m_RightEndPoint=address;
		Bind();
	};

	NET_NAMESPACE_END
}
//
