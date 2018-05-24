// ==============================================================
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

#ifndef __Common_TcpListener__
#define __Common_TcpListener__
//#include "Common.h"
namespace Common
{
	NET_NAMESPACE_BEGIN
	// 摘要:
	//     从 TCP 网络客户端侦听连接。
	class TcpListener
	{
    // Fields
		bool m_Active;
		Socket m_ServerSocket;
		IPAddress m_ServerSocketEP;
	public :
		//     初始化在指定端口上侦听的 System.Net.Sockets.TcpListener 类的新实例。port:用来侦听传入的连接尝试的端口。
		TcpListener():m_ServerSocket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp),m_Active(false){};
		TcpListener(int port):m_ServerSocketEP(port),m_ServerSocket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp),m_Active(false){};
		TcpListener(IPAddress localEP):m_ServerSocketEP(localEP),m_ServerSocket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp),m_Active(false){};
		TcpListener(String IP, int port):m_ServerSocketEP(IP,port),m_ServerSocket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp),m_Active(false){};
		TcpListener(IPAddress localEP,int port):m_ServerSocketEP(localEP),m_ServerSocket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp),m_Active(false)
		{
			m_ServerSocketEP.sadin.sin.sin_port = htons(port);
		};
		~TcpListener(){Close();};
		void setAddress(IPAddress localEP)
		{
			m_ServerSocketEP=localEP;
		};
		Socket AcceptSocket()
		{
			 return m_ServerSocket.Accept();
		};
		//TcpClient AcceptTcpClient()
		//{
		//	 return TcpClient(m_ServerSocket.Accept());
		//};
		//最大连接数限制
		void Start(int backlog)
		{
			if ((backlog > 0x7fffffff) || (backlog < 0))
			{
				EXP("ArgumentOutOfRangeException("+String(backlog)+")");
			}
			if (m_ServerSocket.isNull())
			{
				EXP("InvalidOperationException( net_InvalidSocketHandle )");
			}
			if (this->m_Active)
			{
				return;
			}
			else
			{
				this->m_ServerSocket.Bind(this->m_ServerSocketEP);
				this->m_ServerSocket.Listen(backlog);
				this->m_Active = true;
			}
		};
		void Start()
		{
			Start(0x7fffffff);
		};
		void Stop()
		{
			if (this->m_ServerSocket.isNull()==false)
			{
				this->m_ServerSocket.Close();
			}
			m_Active = false;
			m_ServerSocket=Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);		//	重新初始socket,以便重新监听
		};
		void Close()
		{
			this->m_ServerSocket.Close();m_Active = false;
		}
		bool Pending()
		{
			if (!this->m_Active)
			{
				EXP("InvalidOperationException( net_stopped )");
			}
			return this->m_ServerSocket.Poll(0, SelectMode::SelectRead);
		};

		// Properties
		bool Active() { return m_Active; };// TcpListener 正主动侦听，则为 true；否则为 false。
		IPAddress &LocalEndpoint() { return  m_ServerSocketEP; }
		Socket Server() { return m_ServerSocket; }
	};
	NET_NAMESPACE_END
}
#endif
