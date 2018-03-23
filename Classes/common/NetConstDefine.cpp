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
//#include "Common.h"
#define CPP_FILE 7
#include "Common.h" // "includeHead.h"	//unix FTP

namespace Common
{
NET_NAMESPACE_BEGIN
//����ͨ���ೣ������//
	const int SocketType::Stream = 1;         // stream socket                                     
	const int SocketType::Dgram = 2;		    // datagram socket                                     
	const int SocketType::Raw = 3;		    // raw-protocol interface                                     
	const int SocketType::Rdm = 4;		    // reliably-delivered message                                     
	const int SocketType::Seqpacket = 5;	    // sequenced packet stream                                     
	const int SocketType::Unknown = -1;

	const int SocketAsyncOperation::None = 0;
	const int SocketAsyncOperation::Accept = 1;
	const int SocketAsyncOperation::Connect = 2;
	const int SocketAsyncOperation::Disconnect = 3;
	const int SocketAsyncOperation::Receive = 4;
	const int SocketAsyncOperation::ReceiveFrom = 5;
	const int SocketAsyncOperation::ReceiveMessageFrom = 6;
	const int SocketAsyncOperation::Send = 7;
	const int SocketAsyncOperation::SendPackets = 8;
	const int SocketAsyncOperation::SendTo = 9;
	//ָ���׽��ֵķ��ͺͽ�����Ϊ��
	const int SocketFlags::None = 0;//     ���Դ˵���ʹ�ñ�־��
	const int SocketFlags::OutOfBand = 1;		//     ����������ݡ�//#define MSG_OOB         0x1             // process out-of-band data                                     
	const int SocketFlags::Peek = 2;			//     �鿴�������Ϣ��//#define MSG_PEEK        0x2             // peek at incoming message                                     
	const int SocketFlags::DontRoute = 4;		//     ��ʹ��·�ɱ��͡�//#define MSG_DONTROUTE   0x4             // send without using routing tables                                     
	const int SocketFlags::MaxIOVectorLength = 0x10;		//     Ϊ���ͺͽ������ݵ� WSABUF �ṹ�����ṩ��׼ֵ��//#define MSG_MAXIOVLEN   16
	const int SocketFlags::Truncated = 0x100;//     ����Ϣ̫���޷�����ָ���Ļ�������������ضϡ�
	const int SocketFlags::ControlDataTruncated = 0x200;//     ָʾ�ؼ����ݲ��ʺ��ڲ� 64-KB �������������ѱ��ضϡ�
	const int SocketFlags::Broadcast = 0x400;//     ָʾ�㲥���ݰ���
	const int SocketFlags::Multicast = 0x800;
	const int SocketFlags::Partial = 0x8000;	//     ��Ϣ�Ĳ��ַ��ͻ���ա�//#define MSG_PARTIAL     0x8000          // partial send or recv for message xport                                     
	// ���� Socket ��״̬��
	const int SocketInformationOptions::Connected = 2;//     System.Net.Sockets.Socket �����ӡ�
	const int SocketInformationOptions::Listening = 4;//     System.Net.Sockets.Socket �������������ӡ�
	const int SocketInformationOptions::NonBlocking = 1;//     System.Net.Sockets.Socket Ϊ��������
	const int SocketInformationOptions::UseOnlyOverlappedIO = 8;//     System.Net.Sockets.Socket ʹ���ص� I/O��

	const int SocketShutdown::Receive=1;//     ���ý��յ� System.Net.Sockets.Socket�����ֶ�Ϊ������
	const int SocketShutdown::Send=2;//     ���÷��͵� System.Net.Sockets.Socket�����ֶ�Ϊ������
	const int SocketShutdown::Both=3;//     Ϊ���ͺͽ��ս��� System.Net.Sockets.Socket�����ֶ�Ϊ������
	//�����׽���ѡ���
	const int SocketOptionLevel::IP = 0;//     System.Net.Sockets.Socket ѡ��������� IP �׽��֡�
	const int SocketOptionLevel::Tcp = 6;//     System.Net.Sockets.Socket ѡ��������� TCP �׽��֡�
	const int SocketOptionLevel::Udp = 0x11;//     System.Net.Sockets.Socket ѡ��������� UDP �׽��֡�
	const int SocketOptionLevel::IPv6 = 0x29;//     System.Net.Sockets.Socket ѡ��������� IPv6 �׽��֡�
	const int SocketOptionLevel::Socket = 0xffff;//     System.Net.Sockets.Socket ѡ�������������׽��֡�
	//��������ѡ�����ơ�
	//     ��ȫ�ر��׽��֣�����������
	const int SocketOptionName::DontLinger = -129;
	//     ʹ�׽����ܹ�Ϊ��ռ���ʽ��а󶨡�
	const int SocketOptionName::ExclusiveAddressUse = -5;
	//     ָ��Ҫ���뵽������ݱ��е� IP ѡ�//#define IP_OPTIONS          1           // set/get IP per-packet options                                        
	const int SocketOptionName::IPOptions = 1;
	//     Ϊ���ͺϲ����� Nagle �㷨��#define TCP_NODELAY     0x0001
	const int SocketOptionName::NoDelay = 1;
	//     ��¼������Ϣ��//#define SO_DEBUG        0x0001          // turn on debugging info recording                                     
	const int SocketOptionName::Debug = 1;
	//     ����У�������Ϊ��� UDP ���ݱ���
	const int SocketOptionName::NoChecksum = 1;
	//     ʹ�� RFC-1222 �ж���ļӼ����ݡ���ѡ��ֻ������һ�Σ����������Ժ���޷��رա�
	const int SocketOptionName::Expedited = 2;
	//     ָʾӦ�ó���Ϊ������ݱ��ṩ IP ͷ��
	const int SocketOptionName::HeaderIncluded = 2;


	//     ʹ�� RFC-1222 �ж���Ľ������ݡ���ѡ��ֻ������һ�Σ����������Ժ�Ͳ��ܹرա�
#ifdef SUNIX
	const int SocketOptionName::BsdUrgent = 2;
#else
	const int SocketOptionName::BsdUrgent = 0x7000;//#define TCP_BSDURGENT   0x7000
#endif
	//     �׽�������������//#define SO_ACCEPTCONN   0x0002          // socket has had listen()                                     
	const int SocketOptionName::AcceptConnection = 2;
	//     ���ķ����ֶε� IP ͷ���͡�#define IP_TOS              8           // set/get IP Type Of Service                                           
#ifdef SUNIX
	const int SocketOptionName::TypeOfService = 3;
#else
	const int SocketOptionName::TypeOfService = 8;
#endif
	//     �����׽��ְ󶨵�����ʹ���еĵ�ַ��//#define SO_REUSEADDR    0x0004          // allow local address reuse                                     
	const int SocketOptionName::ReuseAddress = 4;
	//     ���� IP ͷ����ʱ���ֶΡ�#define IP_TTL              7           // set/get IP Time To Live                                              
#ifdef SUNIX
	const int SocketOptionName::IpTimeToLive = 4;
#else
	const int SocketOptionName::IpTimeToLive = 7;
#endif
	//     ʹ�� keep-alive��//#define SO_KEEPALIVE    0x0008          // keep connections alive                                     
	const int SocketOptionName::KeepAlive = 8;
	//     Ϊ����Ķ�·�㲥���ݰ����ýӿڡ� #define IP_MULTICAST_IF     2           // set/get IP multicast interface                                       
#ifdef SUNIX
	const int SocketOptionName::MulticastInterface = 9;
#else
	const int SocketOptionName::MulticastInterface = 2;
#endif
	//     IP ��·�㲥����ʱ�䡣#define IP_MULTICAST_TTL    3           // set/get IP multicast timetolive                                      
#ifdef SUNIX
	const int SocketOptionName::MulticastTimeToLive = 10;
#else
	const int SocketOptionName::MulticastTimeToLive = 3;
#endif
	//     IP ��·�㲥���ء� #define IP_MULTICAST_LOOP   4           // set/get IP multicast loopback                                        
#ifdef SUNIX
	const int SocketOptionName::MulticastLoopback = 11;
#else
	const int SocketOptionName::MulticastLoopback = 4;
#endif
	//     ���һ�� IP ���Ա��//#define IP_ADD_MEMBERSHIP   5           // add  an IP group membership                                          
#ifdef SUNIX
	const int SocketOptionName::AddMembership = 12;
#else
	const int SocketOptionName::AddMembership = 5;
#endif
	//     ����һ�� IP ���Ա��//#define IP_DROP_MEMBERSHIP  6           // drop an IP group membership                                          
#ifdef SUNIX
	const int SocketOptionName::DropMembership = 13;
#else
	const int SocketOptionName::DropMembership = 6;
#endif
	//     ���� IP ���ݱ����зֶΡ�#define IP_DONTFRAGMENT     9           // set/get IP Don't Fragment flag                                       
#ifdef SUNIX
	const int SocketOptionName::DontFragment = 14;
#else
	const int SocketOptionName::DontFragment = 6;
#endif
	//     ����Դ�顣
	const int SocketOptionName::AddSourceMembership = 15;
	//     ����һ��Դ�顣
	const int SocketOptionName::DropSourceMembership = 16;
	//     ��·�ɣ������ݰ�ֱ�ӷ��͵��ӿڵ�ַ��//#define SO_DONTROUTE    0x0010          // just use interface addresses                                     
	const int SocketOptionName::DontRoute = 16;
	//     ��ֹԴ�е����ݡ�
	const int SocketOptionName::BlockSource = 17;
	//     ȡ����ֹ��ǰ����ֹ��Դ��
	const int SocketOptionName::UnblockSource = 18;
	//     �����йؽ��յ������ݰ�����Ϣ��
	const int SocketOptionName::PacketInformation = 19;
	//     ���û��ȡ UDP У��͸��ǡ�
	const int SocketOptionName::ChecksumCoverage = 20;
	//     ָ�� Internet Э��汾 6 (IPv6) ���ݰ������·����Ծ����Ŀ���������� Internet Э��汾 4 ������ʱ�� (TTL)��
	const int SocketOptionName::HopLimit = 21;
	//     �������׽����Ϸ��͹㲥��Ϣ��//#define SO_BROADCAST    0x0020          // permit sending of broadcast msgs                                     
	const int SocketOptionName::Broadcast = 0x0020;
	//     ����ʱ�ܿ�Ӳ����//#define SO_USELOOPBACK  0x0040          // bypass hardware when possible                                     
	const int SocketOptionName::UseLoopback = 0x0040;
	//     �������δ���͵����ݣ����ڹر�ʱ������ //#define SO_LINGER       0x0080          // linger on close if data present                                     
	const int SocketOptionName::Linger = 0x0080;
	//     ���������������еĴ������ݡ�//#define SO_OOBINLINE    0x0100          // leave received OOB data in line                                     
	const int SocketOptionName::OutOfBandInline = 0x0100;
	//     ָ��Ϊ���ͱ�����ÿ���׽��ֻ������ռ�����������������Ϣ��С�� TCP ���ڵĴ�С�޹ء�//#define SO_SNDBUF       0x1001          // send buffer size                                     
	const int SocketOptionName::SendBuffer = 0x1001;
	//     ָ��Ϊ���ձ�����ÿ���׽��ֻ������ռ�����������������Ϣ��С�� TCP ���ڵĴ�С�޹ء�//#define SO_RCVBUF       0x1002          // receive buffer size                                     
	const int SocketOptionName::ReceiveBuffer = 0x1002;
	//     Ϊ Overload:System.Net.Sockets.Socket.Send ����ָ����ˮӡ��//#define SO_SNDLOWAT     0x1003          // send low-water mark                                     
	const int SocketOptionName::SendLowWater = 0x1003;
	//     Ϊ Overload:System.Net.Sockets.Socket.Receive ����ָ����ˮӡ��
	const int SocketOptionName::ReceiveLowWater = 4100;
	//     ���ͳ�ʱ����ѡ��ֻ������ͬ�������������첽�������� System.Net.Sockets.Socket.BeginSend(System.Byte[],System.Int32,System.Int32,System.Net.Sockets.SocketFlags,System.AsyncCallback,System.Object)
	//     ��������Ч��//#define SO_SNDTIMEO     0x1005          // send timeout                                     
	const int SocketOptionName::SendTimeout = 0x1005;
	//     ���ճ�ʱ����ѡ��ֻ������ͬ�������������첽�������� System.Net.Sockets.Socket.BeginSend(System.Byte[],System.Int32,System.Int32,System.Net.Sockets.SocketFlags,System.AsyncCallback,System.Object)
	//     ��������Ч��//#define SO_RCVTIMEO     0x1006          // receive timeout                                     
	const int SocketOptionName::ReceiveTimeout = 0x1006;
	//     ��ȡ����״̬�������//#define SO_ERROR        0x1007          // get error status and clear                                     
	const int SocketOptionName::Error = 0x1007;
	//     ��ȡ�׽������͡�//#define SO_TYPE         0x1008          // get socket type                                     
	const int SocketOptionName::Type = 0x1008;
	//     ʹ�������׽��ֵ����Ը����ѽ����׽��ֵ����ԡ����Ч��ʹ�� Winsock2 SO_UPDATE_ACCEPT_CONTEXT �׽���ѡ����ҽ����������ӵ��׽�������֧�֡�
	const int SocketOptionName::UpdateAcceptContext = 28683;
	//     ʹ�������׽��ֵ����Ը����������׽��ֵ����ԡ����Ч��ʹ�� Winsock2 SO_UPDATE_CONNECT_CONTEXT �׽���ѡ����ҽ����������ӵ��׽�������֧�֡�
	const int SocketOptionName::UpdateConnectContext = 28688;
	//     ����֧�֣����ʹ�ã������� System.Net.Sockets.SocketException��
	const int SocketOptionName::MaxConnections = 2147483647;


	//ָ�� Socket ���ʵ������ʹ�õ�Э�����͡�InterNetwork ��Ӧ AF_INET
	//δ֪Э�顣
	const int ProtocolFamily::Unknown = -1;
	//δָ����Э�顣
	const int ProtocolFamily::Unspecified = 0;
	//Unix ���ص�����Э�顣
	const int ProtocolFamily::Unix = 1;
	//IP �汾 4 Э�顣
	const int ProtocolFamily::InterNetwork = 2;   //#define AF_INET         2               // internetwork: UDP, TCP, etc.                                     
	//ARPANET IMP Э�顣
	const int ProtocolFamily::ImpLink = 3;
	//PUP Э�顣
	const int ProtocolFamily::Pup = 4;
	//MIT CHAOS Э�顣
	const int ProtocolFamily::Chaos = 5;
	//IPX �� SPX Э�顣
	const int ProtocolFamily::Ipx = 6;
	//Xerox NS Э�顣
	const int ProtocolFamily::NS = 6;
	//OSI Э�顣
	const int ProtocolFamily::Osi = 7;
	//ISO Э�顣
	const int ProtocolFamily::Iso = 7;
	//ŷ�޼����������Э�� (ECMA) Э�顣
	const int ProtocolFamily::Ecma = 8;
	//DataKit Э�顣
	const int ProtocolFamily::DataKit = 9;
	//CCITT Э�飬�� X.25��
	const int ProtocolFamily::Ccitt = 10;
	//IBM SNA Э�顣
	const int ProtocolFamily::Sna = 11;
	//DECNet Э�顣
	const int ProtocolFamily::DecNet = 12;
	//ֱ����������Э�顣
	const int ProtocolFamily::DataLink = 13;
	//LAT Э�顣
	const int ProtocolFamily::Lat = 14;
	//NSC HyperChannel Э�顣
	const int ProtocolFamily::HyperChannel = 15;
	//AppleTalk Э�顣
	const int ProtocolFamily::AppleTalk = 16;
	//NetBIOS Э�顣
	const int ProtocolFamily::NetBios = 17;
	//VoiceView Э�顣
	const int ProtocolFamily::VoiceView = 18;
	//FireFox Э�顣
	const int ProtocolFamily::FireFox = 19;
	//Banyan Э�顣
	const int ProtocolFamily::Banyan = 21;
	//���� ATM ����Э�顣
	const int ProtocolFamily::Atm = 22;
	//IP �汾 6 Э�顣
	const int ProtocolFamily::InterNetworkV6 = 23;
	//Microsoft Ⱥ����ƷЭ�顣
	const int ProtocolFamily::Cluster = 24;
	//IEEE 1284.4 ������Э�顣
	const int ProtocolFamily::Ieee12844 = 25;
	//IrDA Э�顣
	const int ProtocolFamily::Irda = 26;
	//֧����������� OSI ���ص�Э�顣
	const int ProtocolFamily::NetworkDesigners = 28;
	//MAX Э�顣
	const int ProtocolFamily::Max = 29;

 
	const int SelectMode::SelectRead=0;
	const int SelectMode::SelectWrite=1;
	const int SelectMode::SelectError=2;

	//ָ��Socket ��֧�ֵ�Э�顣
	//δ֪Э�顣
	const int ProtocolType::Unknown = -1;
	//IPv6 ����ѡ��ͷ��
	const int ProtocolType::IPv6HopByHopOptions = 0;
	//δָ����Э�顣
	const int ProtocolType::Unspecified = 0;
	//����Э�顣
	const int ProtocolType::IP = 0;
	//������Ϣ����Э�顣
	const int ProtocolType::Icmp = 1;
	//���������Э�顣
	const int ProtocolType::Igmp = 2;
	//���ص�����Э�顣
	const int ProtocolType::Ggp = 3;
	//Internet Э��汾 4��
	const int ProtocolType::IPv4 = 4;
	//�������Э�顣
	const int ProtocolType::Tcp = 6;
	//PARC ͨ�����ݰ�Э�顣
	const int ProtocolType::Pup = 12;
	//�û����ݱ�Э�顣
	const int ProtocolType::Udp = 17;
	//Internet ���ݱ�Э�顣
	const int ProtocolType::Idp = 22;
	//Internet Э��汾 6 (IPv6)��
	const int ProtocolType::IPv6 = 41;
	//IPv6 ·��ͷ��
	const int ProtocolType::IPv6RoutingHeader = 43;
	//IPv6 Ƭ��ͷ��
	const int ProtocolType::IPv6FragmentHeader = 44;
	//IPv6 ��װʽ��ȫ��ʩ����ͷ��
	const int ProtocolType::IPSecEncapsulatingSecurityPayload = 50;
	//IPv6 �����֤ͷ���й���ϸ��Ϣ����μ�λ�� http://www.ietf.org �е� RFC 2292 �� 2.2.1 �ڡ�
	const int ProtocolType::IPSecAuthenticationHeader = 51;
	//���� IPv6 �� Internet ������ϢЭ�顣
	const int ProtocolType::IcmpV6 = 58;
	//IPv6 No Next ͷ��
	const int ProtocolType::IPv6NoNextHeader = 59;
	//IPv6 Ŀ��ѡ��ͷ��
	const int ProtocolType::IPv6DestinationOptions = 60;
	//�������Э�飨����ʽ����
	const int ProtocolType::ND = 77;
	//ԭʼ IP ���ݰ�Э�顣
	const int ProtocolType::Raw = 255;
	//Internet ���ݰ�����Э�顣
	const int ProtocolType::Ipx = 1000;
	//˳�������Э�顣
	const int ProtocolType::Spx = 1256;
	//˳�������Э��� 2 �档
	const int ProtocolType::SpxII = 1257;

	const int IPAddress::maxPort=0xffff;
	const int IPAddress::minPort=0;
NET_NAMESPACE_END
}
//
