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

#ifndef __Common_net_TcpClient__
#define __Common_net_TcpClient__
//#include "Common.h"
namespace Common
{
	NET_NAMESPACE_BEGIN
	class TcpClient
	{
		    // Fields
	private:
		bool m_Active;
		bool m_CleanedUp;
		Socket m_ClientSocket;
		//NetworkStream m_DataStream;
		AddressFamily m_Family;

		void initialize()
		{
			m_ClientSocket = Socket(this->m_Family, SocketType::Stream, ProtocolType::Tcp);
			m_Active = false;
			m_CleanedUp=false;
		};

	public:
		TcpClient(AddressFamily family)
		{
			m_Family = AddressFamily::InterNetwork;
			if ((family != AddressFamily::InterNetwork) && (family != AddressFamily::InterNetworkV6))
			{
				EXP("ArgumentException( net_protocol_invalid_family  TCP family");
			}
			m_Family = family;
			initialize();
		};
		TcpClient()
		{
			m_Family = AddressFamily::InterNetwork;
			initialize();
		};
		TcpClient(IPAddress localEP)
		{
			this->m_Family = AddressFamily::InterNetwork;
			initialize();
			m_ClientSocket.Bind(localEP);
		};
		TcpClient(Socket acceptedSocket)
		{
			m_Family =acceptedSocket.m_af;// AddressFamily.InterNetwork;
			this->m_ClientSocket = acceptedSocket;
			this->m_Active = true;
			m_CleanedUp=false;
		};
		TcpClient(String hostname, int port)
		{
			m_CleanedUp=false;
			this->m_Family = AddressFamily::InterNetwork;
			if (hostname=="")
			{
				EXP("hostname is null");
			}
			if (port>65535 || port<0)
			{
				EXP("port error, port=["+String(port)+"]");
			}
			try
			{
				this->Connect(hostname, port);
			}
			catch (Exception exception)
			{
				if (this->m_ClientSocket.isNull()==false)
				{
					this->m_ClientSocket.Close();
				}
				throw exception;
			}
		};
		~TcpClient(){this->Close();};
		void Connect(IPAddress remoteEP)
		{
			if (this->m_CleanedUp)
			{
				EXP("ObjectDisposedException");
			}
			if (remoteEP.isNull())
			{
				EXP("remoteEP is null");
			}
			this->m_ClientSocket.Connect(remoteEP);
			this->m_Active = true;
		};
		void Connect(IPAddress address, int port)
		{
			if (port>65535 || port<0)
			{
				EXP("port error, port=["+String(port)+"]");
			}
			address.sadin.sin.sin_port = htons(port);
			Connect(address);
		};
		void Connect(string hostname, int port)
		{
			this->m_Family = AddressFamily::InterNetwork;
			if (hostname=="")
			{
				EXP("hostname is null");
			}
			if (port>65535 || port<0)
			{
				EXP("port error, port=["+String(port)+"]");
			}
			this->m_ClientSocket.Connect(hostname, port);
		};
		void Connect(Array<IPAddress> & ipAddresses, int port)
		{
			m_ClientSocket.Connect(ipAddresses, port);
			m_Active = true;
		};

		void Close()
		{
			if (this->m_CleanedUp)
				return;
			this->m_ClientSocket.Close();
			//if (disposing)
			//{
			//	IDisposable  dataStream = this->m_DataStream;
			//	if (dataStream != 0)
			//	{
			//		dataStream->Dispose();
			//	}
			//	else
			//	{
			//		m_ClientSocket.Shutdown(SocketShutdown::Both);
			//		m_ClientSocket.Close();
			//	}
			//	GC::SuppressFinalize(this);
			//}
			this->m_CleanedUp = true;
		};
		int numericOption(SocketOptionLevel optionLevel, SocketOptionName optionName)
		{
			return (int) m_ClientSocket.GetSocketOption(optionLevel, optionName);
		}
		Socket &Client()
		{
			return this->m_ClientSocket;
		}
		bool Connected()
		{
			return this->m_ClientSocket.Connected();
		}
		int GetReceiveBufferSize()
		{
			return this->numericOption(SocketOptionLevel::Socket, SocketOptionName::ReceiveBuffer);
		}
		bool SetReceiveBufferSize(int value)
		{
			this->m_ClientSocket.m_ReceiveBufferSize=value;
			return this->m_ClientSocket.SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ReceiveBuffer, value);
		}

		int GetSendBufferSize()
		{
			return this->numericOption(SocketOptionLevel::Socket, SocketOptionName::SendBuffer);
		}
		bool SetSendBufferSize(int value)
		{
			this->m_ClientSocket.m_SendBufferSize=value;
			return this->m_ClientSocket.SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::SendBuffer, value);
		}
		 
		int GetReceiveTimeout()
		{
			return this->numericOption(SocketOptionLevel::Socket, SocketOptionName::ReceiveTimeout);
		}
		bool SetReceiveTimeout(int value)
		{
			this->m_ClientSocket.m_ReceiveTimeout=value;
			return this->m_ClientSocket.SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ReceiveTimeout, value);
		}
		 
		int GetSendTimeout()
		{
			return this->numericOption(SocketOptionLevel::Socket, SocketOptionName::SendTimeout);
		}
		bool SetSendTimeout(int value)
		{
			this->m_ClientSocket.m_SendTimeout=value;
			return this->m_ClientSocket.SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::SendTimeout, value);
		}
 
		linger GetLingerState()
		{
			return this->m_ClientSocket.GetLingerOpt();
		}
		bool SetLingerState(linger value)
		{
			return this->m_ClientSocket.SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::Linger, value);
		}
		bool Active()
		{
			return this->m_Active;
		}
		int getSocketErrorCode()
		{
			return this->m_ClientSocket.GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::Error);
		}


	};
	NET_NAMESPACE_END
}
#endif
