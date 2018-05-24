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

#ifndef __Common_net_NetConstDefine__
#define __Common_net_NetConstDefine__
//#include "Common.h"
namespace Common
{
NET_NAMESPACE_BEGIN
	typedef  char byte;
	///<summary>
	///套接字类型
	///</summary>
	 ///<see cref="Socket"/>
	class SocketType
	{
	public :
		SocketType(int val=1):value(val){};
		int value;
		static const int Stream;         // stream socket                                     
		static const int Dgram;		    // datagram socket                                     
		static const int Raw;		    // raw-protocol interface                                     
		static const int Rdm;		    // reliably-delivered message                                     
		static const int Seqpacket;	    // sequenced packet stream                                     
		static const int Unknown;

		///	<summary>
		///	操作符重载
		///	原型：inline bool operator==(int val);
		///	</summary>
		///	<param name="val"><see cref="int"/></param>
		///	<returns>相等返回[true]，反之[false]</returns>
		inline bool operator==(int val){return value==val;};
		inline bool operator==(SocketType val){return value==val.value;};
		inline bool operator!=(int val){return value!=val;};
		inline bool operator!=(SocketType val){return value!=val.value;};
	};
	///	<summary>
	///	操作符重载
	///	原型：inline bool cmptest(int val,SocketType &amp;st);
	///	</summary>
	///	<param name="val">int</param>
	///	<param name="st">SocketType</param>
	///	<returns>相等返回[true]，反之[false]</returns>
	inline bool operator==(int val,SocketType &st){return st.value==val;};
	inline bool operator==(SocketType val,SocketType &st){return st.value==val.value;};
	inline bool operator!=(int val,SocketType &st){return st.value!=val;};
	inline bool operator!=(SocketType val,SocketType &st){return st.value!=val.value;};
	class SocketAsyncOperation
	{
	public :
		SocketAsyncOperation(int val=0):value(val){};
		int value;
		static const int None;
		static const int Accept;
		static const int Connect;
		static const int Disconnect;
		static const int Receive;
		static const int ReceiveFrom;
		static const int ReceiveMessageFrom;
		static const int Send;
		static const int SendPackets;
		static const int SendTo;
		inline bool operator==(int val){return value==val;};
		inline bool operator==(SocketAsyncOperation val){return value==val.value;};
		inline bool operator!=(int val){return value!=val;};
		inline bool operator!=(SocketAsyncOperation val){return value!=val.value;};
	};
	inline bool operator==(int val,SocketAsyncOperation &st){return st.value==val;};
	inline bool operator==(SocketAsyncOperation val,SocketAsyncOperation &st){return st.value==val.value;};
	inline bool operator!=(int val,SocketAsyncOperation &st){return st.value!=val;};
	inline bool operator!=(SocketAsyncOperation val,SocketAsyncOperation &st){return st.value!=val.value;};
	//指定套接字的发送和接收行为。
	class SocketFlags
	{
	public :
		SocketFlags(int val=0):value(val){};
		int value;
		static const int None;//     不对此调用使用标志。
		static const int OutOfBand;		//     处理带外数据。//#define MSG_OOB         0x1             // process out-of-band data                                     
		static const int Peek;			//     查看传入的消息。//#define MSG_PEEK        0x2             // peek at incoming message                                     
		static const int DontRoute;		//     不使用路由表发送。//#define MSG_DONTROUTE   0x4             // send without using routing tables                                     
		static const int MaxIOVectorLength;		//     为发送和接收数据的 WSABUF 结构数量提供标准值。//#define MSG_MAXIOVLEN   16
		static const int Truncated;//     该消息太大，无法放入指定的缓冲区，因而被截断。
		static const int ControlDataTruncated;//     指示控件数据不适合内部 64-KB 缓冲区，并且已被截断。
		static const int Broadcast;//     指示广播数据包。
		static const int Multicast;
		static const int Partial;	//     消息的部分发送或接收。//#define MSG_PARTIAL     0x8000          // partial send or recv for message xport                                     
		inline bool operator==(int val){return value==val;};
		inline bool operator==(SocketFlags val){return value==val.value;};
		inline bool operator!=(int val){return value!=val;};
		inline bool operator!=(SocketFlags val){return value!=val.value;};
	};
	inline bool operator==(int val,SocketFlags &st){return st.value==val;};
	inline bool operator==(SocketFlags val,SocketFlags &st){return st.value==val.value;};
	inline bool operator!=(int val,SocketFlags &st){return st.value!=val;};
	inline bool operator!=(SocketFlags val,SocketFlags &st){return st.value!=val.value;};
	// 描述 Socket 的状态。
	class SocketInformationOptions
	{
	public :
		SocketInformationOptions(int val=0):value(val){};
		int value;
		static const int Connected;//     System.Net.Sockets.Socket 已连接。
		static const int Listening;//     System.Net.Sockets.Socket 正在侦听新连接。
		static const int NonBlocking;//     System.Net.Sockets.Socket 为非阻塞。
		static const int UseOnlyOverlappedIO;//     System.Net.Sockets.Socket 使用重叠 I/O。
		inline bool operator==(int val){return value==val;};
		inline bool operator==(SocketInformationOptions val){return value==val.value;};
		inline bool operator!=(int val){return value!=val;};
		inline bool operator!=(SocketInformationOptions val){return value!=val.value;};
	};
	inline bool operator==(int val,SocketInformationOptions &st){return st.value==val;};
	inline bool operator==(SocketInformationOptions val,SocketInformationOptions &st){return st.value==val.value;};
	inline bool operator!=(int val,SocketInformationOptions &st){return st.value!=val;};
	inline bool operator!=(SocketInformationOptions val,SocketInformationOptions &st){return st.value!=val.value;};
	// Socket::Shutdown(System.Net.Sockets.SocketShutdown) 方法使用的常量。
	class SocketShutdown
	{
	public :
		SocketShutdown(int val=2):value(val){};
		int value;
		static const int Receive;//     禁用接收的 System.Net.Sockets.Socket。此字段为常数。
		static const int Send;//     禁用发送的 System.Net.Sockets.Socket。此字段为常数。
		static const int Both;//     为发送和接收禁用 System.Net.Sockets.Socket。此字段为常数。
		inline bool operator==(int val){return value==val;};
		inline bool operator==(SocketShutdown val){return value==val.value;};
		inline bool operator!=(int val){return value!=val;};
		inline bool operator!=(SocketShutdown val){return value!=val.value;};
	};
	inline bool operator==(int val,SocketShutdown &st){return st.value==val;};
	inline bool operator==(SocketShutdown val,SocketShutdown &st){return st.value==val.value;};
	inline bool operator!=(int val,SocketShutdown &st){return st.value!=val;};
	inline bool operator!=(SocketShutdown val,SocketShutdown &st){return st.value!=val.value;};
	//定义套接字选项级别。
	class SocketOptionLevel
	{
	public :
		SocketOptionLevel(int val=0):value(val){};
		int value;
		static const int IP;//     System.Net.Sockets.Socket 选项仅适用于 IP 套接字。
		static const int Tcp;//     System.Net.Sockets.Socket 选项仅适用于 TCP 套接字。
		static const int Udp;//     System.Net.Sockets.Socket 选项仅适用于 UDP 套接字。
		static const int IPv6;//     System.Net.Sockets.Socket 选项仅适用于 IPv6 套接字。
		static const int Socket;//     System.Net.Sockets.Socket 选项适用于所有套接字。
		inline bool operator==(int val){return value==val;};
		inline bool operator==(SocketOptionLevel val){return value==val.value;};
		inline bool operator!=(int val){return value!=val;};
		inline bool operator!=(SocketOptionLevel val){return value!=val.value;};
	};
	inline bool operator==(int val,SocketOptionLevel &st){return st.value==val;};
	inline bool operator==(SocketOptionLevel val,SocketOptionLevel &st){return st.value==val.value;};
	inline bool operator!=(int val,SocketOptionLevel &st){return st.value!=val;};
	inline bool operator!=(SocketOptionLevel val,SocketOptionLevel &st){return st.value!=val.value;};
	//定义配置选项名称。
	class SocketOptionName
	{
	public :
		SocketOptionName(int val=0):value(val){};
		int value;
		//     完全关闭套接字，不做逗留。
		static const int DontLinger;
		//     使套接字能够为独占访问进行绑定。
		static const int ExclusiveAddressUse;
		//     指定要插入到输出数据报中的 IP 选项。//#define IP_OPTIONS          1           // set/get IP per-packet options                                        
		static const int IPOptions;
		//     为发送合并禁用 Nagle 算法。#define TCP_NODELAY     0x0001
		static const int NoDelay;
		//     记录调试信息。//#define SO_DEBUG        0x0001          // turn on debugging info recording                                     
		static const int Debug;
		//     发送校验和设置为零的 UDP 数据报。
		static const int NoChecksum;
		//     使用 RFC-1222 中定义的加急数据。此选项只能设置一次，而且设置以后就无法关闭。
		static const int Expedited;
		//     指示应用程序为输出数据报提供 IP 头。
		static const int HeaderIncluded;


		//     使用 RFC-1222 中定义的紧急数据。此选项只能设置一次，而且设置以后就不能关闭。
		static const int BsdUrgent;
		//     套接字正在侦听。//#define SO_ACCEPTCONN   0x0002          // socket has had listen()                                     
		static const int AcceptConnection;
		//     更改服务字段的 IP 头类型。#define IP_TOS              8           // set/get IP Type Of Service                                           
		static const int TypeOfService;
		//     允许将套接字绑定到已在使用中的地址。//#define SO_REUSEADDR    0x0004          // allow local address reuse                                     
		static const int ReuseAddress ;
		//     设置 IP 头生存时间字段。#define IP_TTL              7           // set/get IP Time To Live                                              
		static const int IpTimeToLive;
		//     使用 keep-alive。//#define SO_KEEPALIVE    0x0008          // keep connections alive                                     
		static const int KeepAlive;
		//     为输出的多路广播数据包设置接口。 #define IP_MULTICAST_IF     2           // set/get IP multicast interface                                       
		static const int MulticastInterface;
		//     IP 多路广播生存时间。#define IP_MULTICAST_TTL    3           // set/get IP multicast timetolive                                      
		static const int MulticastTimeToLive;
		//     IP 多路广播环回。 #define IP_MULTICAST_LOOP   4           // set/get IP multicast loopback                                        
		static const int MulticastLoopback;
		//     添加一个 IP 组成员。//#define IP_ADD_MEMBERSHIP   5           // add  an IP group membership                                          
		static const int AddMembership;
		//     放置一个 IP 组成员。//#define IP_DROP_MEMBERSHIP  6           // drop an IP group membership                                          
		static const int DropMembership;
		//     不对 IP 数据报进行分段。#define IP_DONTFRAGMENT     9           // set/get IP Don't Fragment flag                                       
		static const int DontFragment;
		//     联接源组。
		static const int AddSourceMembership;
		//     放置一个源组。
		static const int DropSourceMembership;
		//     不路由，将数据包直接发送到接口地址。//#define SO_DONTROUTE    0x0010          // just use interface addresses                                     
		static const int DontRoute;
		//     阻止源中的数据。
		static const int BlockSource;
		//     取消阻止先前被阻止的源。
		static const int UnblockSource;
		//     返回有关接收到的数据包的信息。
		static const int PacketInformation;
		//     设置或获取 UDP 校验和覆盖。
		static const int ChecksumCoverage;
		//     指定 Internet 协议版本 6 (IPv6) 数据包的最大路由器跃点数目。这类似于 Internet 协议版本 4 的生存时间 (TTL)。
		static const int HopLimit;
		//     允许在套接字上发送广播消息。//#define SO_BROADCAST    0x0020          // permit sending of broadcast msgs                                     
		static const int Broadcast;
		//     可能时避开硬件。//#define SO_USELOOPBACK  0x0040          // bypass hardware when possible                                     
		static const int UseLoopback;
		//     如果存在未发送的数据，则在关闭时逗留。 //#define SO_LINGER       0x0080          // linger on close if data present                                     
		static const int Linger;
		//     接收正常数据流中的带外数据。//#define SO_OOBINLINE    0x0100          // leave received OOB data in line                                     
		static const int OutOfBandInline;
		//     指定为发送保留的每个套接字缓冲区空间的总量。这与最大消息大小或 TCP 窗口的大小无关。//#define SO_SNDBUF       0x1001          // send buffer size                                     
		static const int SendBuffer;
		//     指定为接收保留的每个套接字缓冲区空间的总量。这与最大消息大小或 TCP 窗口的大小无关。//#define SO_RCVBUF       0x1002          // receive buffer size                                     
		static const int ReceiveBuffer;
		//     为 Overload:System.Net.Sockets.Socket.Send 操作指定低水印。//#define SO_SNDLOWAT     0x1003          // send low-water mark                                     
		static const int SendLowWater;
		//     为 Overload:System.Net.Sockets.Socket.Receive 操作指定低水印。
		static const int ReceiveLowWater;
		//     发送超时。此选项只适用于同步方法，它对异步方法（如 System.Net.Sockets.Socket.BeginSend(System.Byte[],System.Int32,System.Int32,System.Net.Sockets.SocketFlags,System.AsyncCallback,System.Object)
		//     方法）无效。//#define SO_SNDTIMEO     0x1005          // send timeout                                     
		static const int SendTimeout;
		//     接收超时。此选项只适用于同步方法，它对异步方法（如 System.Net.Sockets.Socket.BeginSend(System.Byte[],System.Int32,System.Int32,System.Net.Sockets.SocketFlags,System.AsyncCallback,System.Object)
		//     方法）无效。//#define SO_RCVTIMEO     0x1006          // receive timeout                                     
		static const int ReceiveTimeout;
		//     获取错误状态并清除。//#define SO_ERROR        0x1007          // get error status and clear                                     
		static const int Error;
		//     获取套接字类型。//#define SO_TYPE         0x1008          // get socket type                                     
		static const int Type;
		//     使用现有套接字的属性更新已接受套接字的属性。这等效于使用 Winsock2 SO_UPDATE_ACCEPT_CONTEXT 套接字选项，并且仅在面向连接的套接字上受支持。
		static const int UpdateAcceptContext;
		//     使用现有套接字的属性更新已连接套接字的属性。这等效于使用 Winsock2 SO_UPDATE_CONNECT_CONTEXT 套接字选项，并且仅在面向连接的套接字上受支持。
		static const int UpdateConnectContext;
		//     不受支持；如果使用，将引发 System.Net.Sockets.SocketException。
		static const int MaxConnections;
//	//Options for use with [gs]etsockopt at the IP level.
//#define IP_OPTIONS          1           // set/get IP per-packet options    
//#define IP_MULTICAST_IF     2           // set/get IP multicast interface   
//#define IP_MULTICAST_TTL    3           // set/get IP multicast timetolive  
//#define IP_MULTICAST_LOOP   4           // set/get IP multicast loopback    
//#define IP_ADD_MEMBERSHIP   5           // add  an IP group membership      
//#define IP_DROP_MEMBERSHIP  6           // drop an IP group membership      
//#define IP_TTL              7           // set/get IP Time To Live          
//#define IP_TOS              8           // set/get IP Type Of Service       
//#define IP_DONTFRAGMENT     9           // set/get IP Don't Fragment flag   
		inline bool operator==(int val){return value==val;};
		inline bool operator==(SocketOptionName val){return value==val.value;};
		inline bool operator!=(int val){return value!=val;};
		inline bool operator!=(SocketOptionName val){return value!=val.value;};
	};
	inline bool operator==(int val,SocketOptionName &st){return st.value==val;};
	inline bool operator==(SocketOptionName val,SocketOptionName &st){return st.value==val.value;};
	inline bool operator!=(int val,SocketOptionName &st){return st.value!=val;};
	inline bool operator!=(SocketOptionName val,SocketOptionName &st){return st.value!=val.value;};

	//指定 Socket 类的实例可以使用的协议类型。InterNetwork 对应 AF_INET
	class ProtocolFamily
	{
	public :
		ProtocolFamily(int val=0):value(val){};
		int value;
		//未知协议。
		static const int Unknown;
		//未指定的协议。
		static const int Unspecified;
		//Unix 本地到主机协议。
		static const int Unix;
		//IP 版本 4 协议。
		static const int InterNetwork;   //#define AF_INET         2               // internetwork: UDP, TCP, etc.                                     
		//ARPANET IMP 协议。
		static const int ImpLink;
		//PUP 协议。
		static const int Pup;
		//MIT CHAOS 协议。
		static const int Chaos;
		//IPX 或 SPX 协议。
		static const int Ipx;
		//Xerox NS 协议。
		static const int NS;
		//OSI 协议。
		static const int Osi;
		//ISO 协议。
		static const int Iso;
		//欧洲计算机制造商协会 (ECMA) 协议。
		static const int Ecma;
		//DataKit 协议。
		static const int DataKit;
		//CCITT 协议，如 X.25。
		static const int Ccitt;
		//IBM SNA 协议。
		static const int Sna;
		//DECNet 协议。
		static const int DecNet;
		//直接数据链接协议。
		static const int DataLink;
		//LAT 协议。
		static const int Lat;
		//NSC HyperChannel 协议。
		static const int HyperChannel;
		//AppleTalk 协议。
		static const int AppleTalk;
		//NetBIOS 协议。
		static const int NetBios;
		//VoiceView 协议。
		static const int VoiceView;
		//FireFox 协议。
		static const int FireFox;
		//Banyan 协议。
		static const int Banyan;
		//本机 ATM 服务协议。
		static const int Atm;
		//IP 版本 6 协议。
		static const int InterNetworkV6;
		//Microsoft 群集产品协议。
		static const int Cluster;
		//IEEE 1284.4 工作组协议。
		static const int Ieee12844;
		//IrDA 协议。
		static const int Irda;
		//支持网络设计器 OSI 网关的协议。
		static const int NetworkDesigners;
		//MAX 协议。
		static const int Max;
		inline bool operator==(int val){return value==val;};
		inline bool operator==(ProtocolFamily val){return value==val.value;};
		inline bool operator!=(int val){return value!=val;};
		inline bool operator!=(ProtocolFamily val){return value!=val.value;};
	};
	inline bool operator==(int val,ProtocolFamily &st){return st.value==val;};
	inline bool operator==(ProtocolFamily val,ProtocolFamily &st){return st.value==val.value;};
	inline bool operator!=(int val,ProtocolFamily &st){return st.value!=val;};
	inline bool operator!=(ProtocolFamily val,ProtocolFamily &st){return st.value!=val.value;};
	typedef ProtocolFamily AddressFamily ;
	class SelectMode
	{
	public:
		SelectMode(int val=0):value(val){};
		int value;
		static const int SelectRead;
		static const int SelectWrite;
		static const int SelectError;
		inline bool operator==(int val){return value==val;};
		inline bool operator==(SelectMode val){return value==val.value;};
		inline bool operator!=(int val){return value!=val;};
		inline bool operator!=(SelectMode val){return value!=val.value;};
	};
	inline bool operator==(int val,SelectMode& st){return st.value==val;};
	inline bool operator==(SelectMode val,SelectMode& st){return st.value==val.value;};
	inline bool operator!=(int val,SelectMode& st){return st.value!=val;};
	inline bool operator!=(SelectMode val,SelectMode& st){return st.value!=val.value;};

	//指定Socket 类支持的协议。
	class ProtocolType
	{
	public :
		ProtocolType(int val=0):value(val){};
		int value;
		//未知协议。
		static const int Unknown;
		//IPv6 逐跳选项头。
		static const int IPv6HopByHopOptions;
		//未指定的协议。
		static const int Unspecified;
		//网际协议。
		static const int IP;
		//网际消息控制协议。
		static const int Icmp;
		//网际组管理协议。
		static const int Igmp;
		//网关到网关协议。
		static const int Ggp;
		//Internet 协议版本 4。
		static const int IPv4;
		//传输控制协议。
		static const int Tcp;
		//PARC 通用数据包协议。
		static const int Pup;
		//用户数据报协议。
		static const int Udp;
		//Internet 数据报协议。
		static const int Idp;
		//Internet 协议版本 6 (IPv6)。
		static const int IPv6;
		//IPv6 路由头。
		static const int IPv6RoutingHeader;
		//IPv6 片段头。
		static const int IPv6FragmentHeader;
		//IPv6 封装式安全措施负载头。
		static const int IPSecEncapsulatingSecurityPayload;
		//IPv6 身份验证头。有关详细信息，请参见位于 http://www.ietf.org 中的 RFC 2292 的 2.2.1 节。
		static const int IPSecAuthenticationHeader;
		//用于 IPv6 的 Internet 控制消息协议。
		static const int IcmpV6;
		//IPv6 No Next 头。
		static const int IPv6NoNextHeader;
		//IPv6 目标选项头。
		static const int IPv6DestinationOptions;
		//网络磁盘协议（非正式）。
		static const int ND;
		//原始 IP 数据包协议。
		static const int Raw;
		//Internet 数据包交换协议。
		static const int Ipx;
		//顺序包交换协议。
		static const int Spx;
		//顺序包交换协议第 2 版。
		static const int SpxII;
		inline bool operator==(int val){return value==val;};
		inline bool operator==(ProtocolType val){return value==val.value;};
		inline bool operator!=(int val){return value!=val;};
		inline bool operator!=(ProtocolType val){return value!=val.value;};
	};
	inline bool operator==(int val,ProtocolType &st){return st.value==val;};
	inline bool operator==(ProtocolType val,ProtocolType &st){return st.value==val.value;};
	inline bool operator!=(int val,ProtocolType &st){return st.value!=val;};
	inline bool operator!=(ProtocolType val,ProtocolType &st){return st.value!=val.value;};

NET_NAMESPACE_END
}
#endif
//
