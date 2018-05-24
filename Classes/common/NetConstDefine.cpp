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
//网络通信类常量定义//
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
	//指定套接字的发送和接收行为。
	const int SocketFlags::None = 0;//     不对此调用使用标志。
	const int SocketFlags::OutOfBand = 1;		//     处理带外数据。//#define MSG_OOB         0x1             // process out-of-band data                                     
	const int SocketFlags::Peek = 2;			//     查看传入的消息。//#define MSG_PEEK        0x2             // peek at incoming message                                     
	const int SocketFlags::DontRoute = 4;		//     不使用路由表发送。//#define MSG_DONTROUTE   0x4             // send without using routing tables                                     
	const int SocketFlags::MaxIOVectorLength = 0x10;		//     为发送和接收数据的 WSABUF 结构数量提供标准值。//#define MSG_MAXIOVLEN   16
	const int SocketFlags::Truncated = 0x100;//     该消息太大，无法放入指定的缓冲区，因而被截断。
	const int SocketFlags::ControlDataTruncated = 0x200;//     指示控件数据不适合内部 64-KB 缓冲区，并且已被截断。
	const int SocketFlags::Broadcast = 0x400;//     指示广播数据包。
	const int SocketFlags::Multicast = 0x800;
	const int SocketFlags::Partial = 0x8000;	//     消息的部分发送或接收。//#define MSG_PARTIAL     0x8000          // partial send or recv for message xport                                     
	// 描述 Socket 的状态。
	const int SocketInformationOptions::Connected = 2;//     System.Net.Sockets.Socket 已连接。
	const int SocketInformationOptions::Listening = 4;//     System.Net.Sockets.Socket 正在侦听新连接。
	const int SocketInformationOptions::NonBlocking = 1;//     System.Net.Sockets.Socket 为非阻塞。
	const int SocketInformationOptions::UseOnlyOverlappedIO = 8;//     System.Net.Sockets.Socket 使用重叠 I/O。

	const int SocketShutdown::Receive=1;//     禁用接收的 System.Net.Sockets.Socket。此字段为常数。
	const int SocketShutdown::Send=2;//     禁用发送的 System.Net.Sockets.Socket。此字段为常数。
	const int SocketShutdown::Both=3;//     为发送和接收禁用 System.Net.Sockets.Socket。此字段为常数。
	//定义套接字选项级别。
	const int SocketOptionLevel::IP = 0;//     System.Net.Sockets.Socket 选项仅适用于 IP 套接字。
	const int SocketOptionLevel::Tcp = 6;//     System.Net.Sockets.Socket 选项仅适用于 TCP 套接字。
	const int SocketOptionLevel::Udp = 0x11;//     System.Net.Sockets.Socket 选项仅适用于 UDP 套接字。
	const int SocketOptionLevel::IPv6 = 0x29;//     System.Net.Sockets.Socket 选项仅适用于 IPv6 套接字。
	const int SocketOptionLevel::Socket = 0xffff;//     System.Net.Sockets.Socket 选项适用于所有套接字。
	//定义配置选项名称。
	//     完全关闭套接字，不做逗留。
	const int SocketOptionName::DontLinger = -129;
	//     使套接字能够为独占访问进行绑定。
	const int SocketOptionName::ExclusiveAddressUse = -5;
	//     指定要插入到输出数据报中的 IP 选项。//#define IP_OPTIONS          1           // set/get IP per-packet options                                        
	const int SocketOptionName::IPOptions = 1;
	//     为发送合并禁用 Nagle 算法。#define TCP_NODELAY     0x0001
	const int SocketOptionName::NoDelay = 1;
	//     记录调试信息。//#define SO_DEBUG        0x0001          // turn on debugging info recording                                     
	const int SocketOptionName::Debug = 1;
	//     发送校验和设置为零的 UDP 数据报。
	const int SocketOptionName::NoChecksum = 1;
	//     使用 RFC-1222 中定义的加急数据。此选项只能设置一次，而且设置以后就无法关闭。
	const int SocketOptionName::Expedited = 2;
	//     指示应用程序为输出数据报提供 IP 头。
	const int SocketOptionName::HeaderIncluded = 2;


	//     使用 RFC-1222 中定义的紧急数据。此选项只能设置一次，而且设置以后就不能关闭。
#ifdef SUNIX
	const int SocketOptionName::BsdUrgent = 2;
#else
	const int SocketOptionName::BsdUrgent = 0x7000;//#define TCP_BSDURGENT   0x7000
#endif
	//     套接字正在侦听。//#define SO_ACCEPTCONN   0x0002          // socket has had listen()                                     
	const int SocketOptionName::AcceptConnection = 2;
	//     更改服务字段的 IP 头类型。#define IP_TOS              8           // set/get IP Type Of Service                                           
#ifdef SUNIX
	const int SocketOptionName::TypeOfService = 3;
#else
	const int SocketOptionName::TypeOfService = 8;
#endif
	//     允许将套接字绑定到已在使用中的地址。//#define SO_REUSEADDR    0x0004          // allow local address reuse                                     
	const int SocketOptionName::ReuseAddress = 4;
	//     设置 IP 头生存时间字段。#define IP_TTL              7           // set/get IP Time To Live                                              
#ifdef SUNIX
	const int SocketOptionName::IpTimeToLive = 4;
#else
	const int SocketOptionName::IpTimeToLive = 7;
#endif
	//     使用 keep-alive。//#define SO_KEEPALIVE    0x0008          // keep connections alive                                     
	const int SocketOptionName::KeepAlive = 8;
	//     为输出的多路广播数据包设置接口。 #define IP_MULTICAST_IF     2           // set/get IP multicast interface                                       
#ifdef SUNIX
	const int SocketOptionName::MulticastInterface = 9;
#else
	const int SocketOptionName::MulticastInterface = 2;
#endif
	//     IP 多路广播生存时间。#define IP_MULTICAST_TTL    3           // set/get IP multicast timetolive                                      
#ifdef SUNIX
	const int SocketOptionName::MulticastTimeToLive = 10;
#else
	const int SocketOptionName::MulticastTimeToLive = 3;
#endif
	//     IP 多路广播环回。 #define IP_MULTICAST_LOOP   4           // set/get IP multicast loopback                                        
#ifdef SUNIX
	const int SocketOptionName::MulticastLoopback = 11;
#else
	const int SocketOptionName::MulticastLoopback = 4;
#endif
	//     添加一个 IP 组成员。//#define IP_ADD_MEMBERSHIP   5           // add  an IP group membership                                          
#ifdef SUNIX
	const int SocketOptionName::AddMembership = 12;
#else
	const int SocketOptionName::AddMembership = 5;
#endif
	//     放置一个 IP 组成员。//#define IP_DROP_MEMBERSHIP  6           // drop an IP group membership                                          
#ifdef SUNIX
	const int SocketOptionName::DropMembership = 13;
#else
	const int SocketOptionName::DropMembership = 6;
#endif
	//     不对 IP 数据报进行分段。#define IP_DONTFRAGMENT     9           // set/get IP Don't Fragment flag                                       
#ifdef SUNIX
	const int SocketOptionName::DontFragment = 14;
#else
	const int SocketOptionName::DontFragment = 6;
#endif
	//     联接源组。
	const int SocketOptionName::AddSourceMembership = 15;
	//     放置一个源组。
	const int SocketOptionName::DropSourceMembership = 16;
	//     不路由，将数据包直接发送到接口地址。//#define SO_DONTROUTE    0x0010          // just use interface addresses                                     
	const int SocketOptionName::DontRoute = 16;
	//     阻止源中的数据。
	const int SocketOptionName::BlockSource = 17;
	//     取消阻止先前被阻止的源。
	const int SocketOptionName::UnblockSource = 18;
	//     返回有关接收到的数据包的信息。
	const int SocketOptionName::PacketInformation = 19;
	//     设置或获取 UDP 校验和覆盖。
	const int SocketOptionName::ChecksumCoverage = 20;
	//     指定 Internet 协议版本 6 (IPv6) 数据包的最大路由器跃点数目。这类似于 Internet 协议版本 4 的生存时间 (TTL)。
	const int SocketOptionName::HopLimit = 21;
	//     允许在套接字上发送广播消息。//#define SO_BROADCAST    0x0020          // permit sending of broadcast msgs                                     
	const int SocketOptionName::Broadcast = 0x0020;
	//     可能时避开硬件。//#define SO_USELOOPBACK  0x0040          // bypass hardware when possible                                     
	const int SocketOptionName::UseLoopback = 0x0040;
	//     如果存在未发送的数据，则在关闭时逗留。 //#define SO_LINGER       0x0080          // linger on close if data present                                     
	const int SocketOptionName::Linger = 0x0080;
	//     接收正常数据流中的带外数据。//#define SO_OOBINLINE    0x0100          // leave received OOB data in line                                     
	const int SocketOptionName::OutOfBandInline = 0x0100;
	//     指定为发送保留的每个套接字缓冲区空间的总量。这与最大消息大小或 TCP 窗口的大小无关。//#define SO_SNDBUF       0x1001          // send buffer size                                     
	const int SocketOptionName::SendBuffer = 0x1001;
	//     指定为接收保留的每个套接字缓冲区空间的总量。这与最大消息大小或 TCP 窗口的大小无关。//#define SO_RCVBUF       0x1002          // receive buffer size                                     
	const int SocketOptionName::ReceiveBuffer = 0x1002;
	//     为 Overload:System.Net.Sockets.Socket.Send 操作指定低水印。//#define SO_SNDLOWAT     0x1003          // send low-water mark                                     
	const int SocketOptionName::SendLowWater = 0x1003;
	//     为 Overload:System.Net.Sockets.Socket.Receive 操作指定低水印。
	const int SocketOptionName::ReceiveLowWater = 4100;
	//     发送超时。此选项只适用于同步方法，它对异步方法（如 System.Net.Sockets.Socket.BeginSend(System.Byte[],System.Int32,System.Int32,System.Net.Sockets.SocketFlags,System.AsyncCallback,System.Object)
	//     方法）无效。//#define SO_SNDTIMEO     0x1005          // send timeout                                     
	const int SocketOptionName::SendTimeout = 0x1005;
	//     接收超时。此选项只适用于同步方法，它对异步方法（如 System.Net.Sockets.Socket.BeginSend(System.Byte[],System.Int32,System.Int32,System.Net.Sockets.SocketFlags,System.AsyncCallback,System.Object)
	//     方法）无效。//#define SO_RCVTIMEO     0x1006          // receive timeout                                     
	const int SocketOptionName::ReceiveTimeout = 0x1006;
	//     获取错误状态并清除。//#define SO_ERROR        0x1007          // get error status and clear                                     
	const int SocketOptionName::Error = 0x1007;
	//     获取套接字类型。//#define SO_TYPE         0x1008          // get socket type                                     
	const int SocketOptionName::Type = 0x1008;
	//     使用现有套接字的属性更新已接受套接字的属性。这等效于使用 Winsock2 SO_UPDATE_ACCEPT_CONTEXT 套接字选项，并且仅在面向连接的套接字上受支持。
	const int SocketOptionName::UpdateAcceptContext = 28683;
	//     使用现有套接字的属性更新已连接套接字的属性。这等效于使用 Winsock2 SO_UPDATE_CONNECT_CONTEXT 套接字选项，并且仅在面向连接的套接字上受支持。
	const int SocketOptionName::UpdateConnectContext = 28688;
	//     不受支持；如果使用，将引发 System.Net.Sockets.SocketException。
	const int SocketOptionName::MaxConnections = 2147483647;


	//指定 Socket 类的实例可以使用的协议类型。InterNetwork 对应 AF_INET
	//未知协议。
	const int ProtocolFamily::Unknown = -1;
	//未指定的协议。
	const int ProtocolFamily::Unspecified = 0;
	//Unix 本地到主机协议。
	const int ProtocolFamily::Unix = 1;
	//IP 版本 4 协议。
	const int ProtocolFamily::InterNetwork = 2;   //#define AF_INET         2               // internetwork: UDP, TCP, etc.                                     
	//ARPANET IMP 协议。
	const int ProtocolFamily::ImpLink = 3;
	//PUP 协议。
	const int ProtocolFamily::Pup = 4;
	//MIT CHAOS 协议。
	const int ProtocolFamily::Chaos = 5;
	//IPX 或 SPX 协议。
	const int ProtocolFamily::Ipx = 6;
	//Xerox NS 协议。
	const int ProtocolFamily::NS = 6;
	//OSI 协议。
	const int ProtocolFamily::Osi = 7;
	//ISO 协议。
	const int ProtocolFamily::Iso = 7;
	//欧洲计算机制造商协会 (ECMA) 协议。
	const int ProtocolFamily::Ecma = 8;
	//DataKit 协议。
	const int ProtocolFamily::DataKit = 9;
	//CCITT 协议，如 X.25。
	const int ProtocolFamily::Ccitt = 10;
	//IBM SNA 协议。
	const int ProtocolFamily::Sna = 11;
	//DECNet 协议。
	const int ProtocolFamily::DecNet = 12;
	//直接数据链接协议。
	const int ProtocolFamily::DataLink = 13;
	//LAT 协议。
	const int ProtocolFamily::Lat = 14;
	//NSC HyperChannel 协议。
	const int ProtocolFamily::HyperChannel = 15;
	//AppleTalk 协议。
	const int ProtocolFamily::AppleTalk = 16;
	//NetBIOS 协议。
	const int ProtocolFamily::NetBios = 17;
	//VoiceView 协议。
	const int ProtocolFamily::VoiceView = 18;
	//FireFox 协议。
	const int ProtocolFamily::FireFox = 19;
	//Banyan 协议。
	const int ProtocolFamily::Banyan = 21;
	//本机 ATM 服务协议。
	const int ProtocolFamily::Atm = 22;
	//IP 版本 6 协议。
	const int ProtocolFamily::InterNetworkV6 = 23;
	//Microsoft 群集产品协议。
	const int ProtocolFamily::Cluster = 24;
	//IEEE 1284.4 工作组协议。
	const int ProtocolFamily::Ieee12844 = 25;
	//IrDA 协议。
	const int ProtocolFamily::Irda = 26;
	//支持网络设计器 OSI 网关的协议。
	const int ProtocolFamily::NetworkDesigners = 28;
	//MAX 协议。
	const int ProtocolFamily::Max = 29;

 
	const int SelectMode::SelectRead=0;
	const int SelectMode::SelectWrite=1;
	const int SelectMode::SelectError=2;

	//指定Socket 类支持的协议。
	//未知协议。
	const int ProtocolType::Unknown = -1;
	//IPv6 逐跳选项头。
	const int ProtocolType::IPv6HopByHopOptions = 0;
	//未指定的协议。
	const int ProtocolType::Unspecified = 0;
	//网际协议。
	const int ProtocolType::IP = 0;
	//网际消息控制协议。
	const int ProtocolType::Icmp = 1;
	//网际组管理协议。
	const int ProtocolType::Igmp = 2;
	//网关到网关协议。
	const int ProtocolType::Ggp = 3;
	//Internet 协议版本 4。
	const int ProtocolType::IPv4 = 4;
	//传输控制协议。
	const int ProtocolType::Tcp = 6;
	//PARC 通用数据包协议。
	const int ProtocolType::Pup = 12;
	//用户数据报协议。
	const int ProtocolType::Udp = 17;
	//Internet 数据报协议。
	const int ProtocolType::Idp = 22;
	//Internet 协议版本 6 (IPv6)。
	const int ProtocolType::IPv6 = 41;
	//IPv6 路由头。
	const int ProtocolType::IPv6RoutingHeader = 43;
	//IPv6 片段头。
	const int ProtocolType::IPv6FragmentHeader = 44;
	//IPv6 封装式安全措施负载头。
	const int ProtocolType::IPSecEncapsulatingSecurityPayload = 50;
	//IPv6 身份验证头。有关详细信息，请参见位于 http://www.ietf.org 中的 RFC 2292 的 2.2.1 节。
	const int ProtocolType::IPSecAuthenticationHeader = 51;
	//用于 IPv6 的 Internet 控制消息协议。
	const int ProtocolType::IcmpV6 = 58;
	//IPv6 No Next 头。
	const int ProtocolType::IPv6NoNextHeader = 59;
	//IPv6 目标选项头。
	const int ProtocolType::IPv6DestinationOptions = 60;
	//网络磁盘协议（非正式）。
	const int ProtocolType::ND = 77;
	//原始 IP 数据包协议。
	const int ProtocolType::Raw = 255;
	//Internet 数据包交换协议。
	const int ProtocolType::Ipx = 1000;
	//顺序包交换协议。
	const int ProtocolType::Spx = 1256;
	//顺序包交换协议第 2 版。
	const int ProtocolType::SpxII = 1257;

	const int IPAddress::maxPort=0xffff;
	const int IPAddress::minPort=0;
NET_NAMESPACE_END
}
//
