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

#ifndef __Common_net_UdpClient__
#define __Common_net_UdpClient__
//#include "Common.h"
namespace Common
{
	NET_NAMESPACE_BEGIN
	class UdpClient
	{
	private:
		static const int MaxUDPSize = 0x10000;
		bool m_Active;
		char m_Buffer[MaxUDPSize];
		bool m_CleanedUp;
		Socket m_ClientSocket;
		AddressFamily m_Family;
		bool m_IsBroadcast;
		void _init(AddressFamily family)
		{
			//this->m_Buffer =new char[0x10000];
			this->m_Family = AddressFamily::InterNetwork;
			if ((family != AddressFamily::InterNetwork) && (family != AddressFamily::InterNetworkV6))
			{
				EXP("ArgumentException net_protocol_invalid_family UDP family");
			}
			this->m_Family = family;
			this->createClientSocket();
		}
		void _init(int port, AddressFamily family)
		{
			IPAddress  point;
			//this->m_Buffer =new char[0x10000];
			this->m_Family = AddressFamily::InterNetwork;
			if (!ValidateTcpPort(port))
			{
				EXP("ArgumentOutOfRangeException port");
			}
			if ((family != AddressFamily::InterNetwork) && (family != AddressFamily::InterNetworkV6))
			{
				EXP("ArgumentException net_protocol_invalid_family family");
			}
			this->m_Family = family;
			if (this->m_Family == AddressFamily::InterNetwork)
			{
				point.setPort(port);
			}
			//else
			//{
			//	point = IPAddress(IPAddress::IPv6Any, port);
			//}
			this->createClientSocket();
			this->m_ClientSocket.Bind(point);
		}
	public:
		UdpClient()
		{
			_init(AddressFamily::InterNetwork);
		};
		UdpClient(IPAddress localEP)
		{
			//this->m_Buffer = new byte[0x10000];
			this->m_Family = AddressFamily::InterNetwork;
			this->createClientSocket();
			this->m_ClientSocket.Bind(localEP);
		};
		UdpClient(AddressFamily family)
		{
			_init(family);
		};
		UdpClient(int port, AddressFamily family)
		{
			_init(port,family);
		};
		UdpClient(int port)
		{
			_init(port,AddressFamily::InterNetwork);
		};
		UdpClient(string hostname, int port)
		{
			//this->m_Buffer = new char[0x10000];
			this->m_Family = AddressFamily::InterNetwork;
			if (hostname.empty())
			{
				EXP("ArgumentNullException hostname");
			}
			if (!ValidateTcpPort(port))
			{
				EXP("ArgumentOutOfRangeException port");
			}
			this->Connect(hostname, port);
		};

 		void Connect(IPAddress endPoint)
		{
			this->m_Family = AddressFamily::InterNetwork;
			if (this->m_CleanedUp)
			{
				EXP("ObjectDisposedException");
			}
			if (endPoint.isNull())
			{
				EXP("ArgumentNullException endPoint");
			}
//			this->CheckForBroadcast(endPoint->Address);
			this->m_ClientSocket.Connect(endPoint);
			this->m_Active = true;
		}
		 
 		void Connect(IPAddress addr, int port)
		{
			this->m_Family = AddressFamily::InterNetwork;
			if (addr.isNull())
			{
				EXP("ArgumentNullException endPoint");
			}
			if(ValidateTcpPort(port)==false)
			{
				EXP("ArgumentOutOfRangeException port");
			}
			addr.setPort(port);
			Connect(addr);
		};
		void Connect(string hostname, int port)
		{
			if (hostname.empty())
			{
				EXP("ArgumentNullException hostname");
			}
			if(ValidateTcpPort(port)==false)
			{
				EXP("ArgumentOutOfRangeException port");
			}
			this->m_Family = AddressFamily::InterNetwork;
			this->m_ClientSocket.Connect(hostname,port);
		};
		void createClientSocket()
		{
			m_ClientSocket= Socket(this->m_Family, SocketType::Dgram, ProtocolType::Udp);
		};
		void Close()
		{
			if (!this->m_CleanedUp)
			{
				this->m_ClientSocket.Close();
				this->m_CleanedUp = true;
			}
		};
		char * Receive(IPAddress &remoteEP)
		{
			IPAddress any;
			if (this->m_CleanedUp)
			{
				EXP("ObjectDisposedException ");
			}
			int count = this->m_ClientSocket.ReceiveFrom(this->m_Buffer, 0x10000, any,SocketFlags::None);
			remoteEP =any;
			if (count < 0x10000)
			{
				return this->m_Buffer;
			}
			return this->m_Buffer;
		}
		int Send(char * dgram, int len)
		{
			if (this->m_CleanedUp)
			{
				EXP("ObjectDisposedException");
			}
			if (dgram == NULL)
			{
				EXP("ArgumentNullException dgram");
			}
			if (!this->m_Active)
			{
				EXP("InvalidOperationException net_notconnected");
			}
			return this->m_ClientSocket.Send(dgram, len, SocketFlags::None);
		};
		int Send(char * dgram, int len, IPAddress endPoint)
		{
			if (this->m_CleanedUp)
			{
				EXP("ObjectDisposedException");
			}
			if (dgram == NULL)
			{
				EXP("ArgumentNullException dgram");
			}
			if (this->m_Active && (endPoint.isNull() != false))
			{
				EXP("InvalidOperationException net_udpconnected");
			}
			if (endPoint.isNull())
			{
				return this->m_ClientSocket.Send(dgram, len, SocketFlags::None);
			}
			this->CheckForBroadcast(endPoint);
			return this->m_ClientSocket.SendTo(dgram, len, endPoint, SocketFlags::None);
		};
		int Send(char * dgram, int len, string hostname, int port)
		{
			if (this->m_CleanedUp)
			{
				EXP("ObjectDisposedException");
			}
			if (dgram == NULL)
			{
				EXP("ArgumentNullException dgram");
			}
			if (this->m_Active && ((hostname.empty() != false) || (port != 0)))
			{
				EXP("InvalidOperationException net_udpconnected");
			}
			if (hostname.empty() || (port == 0))
			{
				return this->m_ClientSocket.Send(dgram,len, SocketFlags::None);
			}
			Array<IPAddress> hostAddresses = GetHostAddresses(hostname);
			int index = 0;
			while ((index < hostAddresses.size() && (hostAddresses[index].getAf() != this->m_Family)))
			{
				index++;
			}
			if (hostAddresses.size() == 0 || index == hostAddresses.size())
			{
				EXP("ArgumentException net_invalidAddressList hostname");
			}
			this->CheckForBroadcast(hostAddresses[index]);
			IPAddress remoteEP = hostAddresses[index];
			remoteEP.setPort(port);
			return this->m_ClientSocket.SendTo(dgram, len, remoteEP, SocketFlags::None);
		};
		void JoinMulticastGroup(IPAddress multicastAddr)
		{
			if (this->m_CleanedUp)
			{
				EXP("ObjectDisposedException");
			}
			if (multicastAddr.getAf() != this->m_Family)
			{
				EXP("ArgumentException net_protocol_invalid_multicast_family UDP multicastAddr");
			}
			if (this->m_Family == AddressFamily::InterNetwork)
			{
				ip_mreq optionValue;
				optionValue.imr_multiaddr=multicastAddr.sadin.sin.sin_addr;
				optionValue.imr_interface.s_addr=htonl(INADDR_ANY) ;
				this->m_ClientSocket.SetSocketOption(SocketOptionLevel::IP, SocketOptionName::AddMembership, optionValue);
			}
		};
		void JoinMulticastGroup(ip_mreq multicastAddr)
		{
			if (this->m_CleanedUp)
			{
				EXP("ObjectDisposedException");
			}
			this->m_ClientSocket.SetSocketOption(SocketOptionLevel::IP, SocketOptionName::AddMembership, multicastAddr);
		}
		//MulticastTimeToLive 在windows下可能不为 10
		void JoinMulticastGroup(ip_mreq multicastAddr, int timeToLive)
		{
			if (!ValidateRange(timeToLive, 0, 0xff))
			{
				EXP("ArgumentOutOfRangeException timeToLive");
			}
			if (this->m_Family == AddressFamily::InterNetwork)
			{
				this->m_ClientSocket.SetSocketOption(SocketOptionLevel::IP, SocketOptionName::AddMembership, multicastAddr);
			}
			this->m_ClientSocket.SetSocketOption(((this->m_Family == AddressFamily::InterNetwork) ? SocketOptionLevel::IP : SocketOptionLevel::IPv6), SocketOptionName::MulticastTimeToLive, timeToLive);
		};
		void JoinMulticastGroup(IPAddress multicastAddr, int timeToLive)
		{
			JoinMulticastGroup(multicastAddr);
			this->m_ClientSocket.SetSocketOption(((this->m_Family == AddressFamily::InterNetwork) ? SocketOptionLevel::IP : SocketOptionLevel::IPv6), SocketOptionName::MulticastTimeToLive, timeToLive);
		};

	private:
		void CheckForBroadcast(IPAddress &ipAddress)
		{
			if (this->m_ClientSocket.isNull()!=false && !this->m_IsBroadcast && ipAddress.IsBroadcast())// && ipAddress->IsBroadcast)
			{
				this->m_IsBroadcast = true;
				this->m_ClientSocket.SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::Broadcast, 1);
			}
		}
 

	};
	NET_NAMESPACE_END
}
#endif
