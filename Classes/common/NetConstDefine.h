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
	///�׽�������
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
		///	����������
		///	ԭ�ͣ�inline bool operator==(int val);
		///	</summary>
		///	<param name="val"><see cref="int"/></param>
		///	<returns>��ȷ���[true]����֮[false]</returns>
		inline bool operator==(int val){return value==val;};
		inline bool operator==(SocketType val){return value==val.value;};
		inline bool operator!=(int val){return value!=val;};
		inline bool operator!=(SocketType val){return value!=val.value;};
	};
	///	<summary>
	///	����������
	///	ԭ�ͣ�inline bool cmptest(int val,SocketType &amp;st);
	///	</summary>
	///	<param name="val">int</param>
	///	<param name="st">SocketType</param>
	///	<returns>��ȷ���[true]����֮[false]</returns>
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
	//ָ���׽��ֵķ��ͺͽ�����Ϊ��
	class SocketFlags
	{
	public :
		SocketFlags(int val=0):value(val){};
		int value;
		static const int None;//     ���Դ˵���ʹ�ñ�־��
		static const int OutOfBand;		//     ����������ݡ�//#define MSG_OOB         0x1             // process out-of-band data                                     
		static const int Peek;			//     �鿴�������Ϣ��//#define MSG_PEEK        0x2             // peek at incoming message                                     
		static const int DontRoute;		//     ��ʹ��·�ɱ��͡�//#define MSG_DONTROUTE   0x4             // send without using routing tables                                     
		static const int MaxIOVectorLength;		//     Ϊ���ͺͽ������ݵ� WSABUF �ṹ�����ṩ��׼ֵ��//#define MSG_MAXIOVLEN   16
		static const int Truncated;//     ����Ϣ̫���޷�����ָ���Ļ�������������ضϡ�
		static const int ControlDataTruncated;//     ָʾ�ؼ����ݲ��ʺ��ڲ� 64-KB �������������ѱ��ضϡ�
		static const int Broadcast;//     ָʾ�㲥���ݰ���
		static const int Multicast;
		static const int Partial;	//     ��Ϣ�Ĳ��ַ��ͻ���ա�//#define MSG_PARTIAL     0x8000          // partial send or recv for message xport                                     
		inline bool operator==(int val){return value==val;};
		inline bool operator==(SocketFlags val){return value==val.value;};
		inline bool operator!=(int val){return value!=val;};
		inline bool operator!=(SocketFlags val){return value!=val.value;};
	};
	inline bool operator==(int val,SocketFlags &st){return st.value==val;};
	inline bool operator==(SocketFlags val,SocketFlags &st){return st.value==val.value;};
	inline bool operator!=(int val,SocketFlags &st){return st.value!=val;};
	inline bool operator!=(SocketFlags val,SocketFlags &st){return st.value!=val.value;};
	// ���� Socket ��״̬��
	class SocketInformationOptions
	{
	public :
		SocketInformationOptions(int val=0):value(val){};
		int value;
		static const int Connected;//     System.Net.Sockets.Socket �����ӡ�
		static const int Listening;//     System.Net.Sockets.Socket �������������ӡ�
		static const int NonBlocking;//     System.Net.Sockets.Socket Ϊ��������
		static const int UseOnlyOverlappedIO;//     System.Net.Sockets.Socket ʹ���ص� I/O��
		inline bool operator==(int val){return value==val;};
		inline bool operator==(SocketInformationOptions val){return value==val.value;};
		inline bool operator!=(int val){return value!=val;};
		inline bool operator!=(SocketInformationOptions val){return value!=val.value;};
	};
	inline bool operator==(int val,SocketInformationOptions &st){return st.value==val;};
	inline bool operator==(SocketInformationOptions val,SocketInformationOptions &st){return st.value==val.value;};
	inline bool operator!=(int val,SocketInformationOptions &st){return st.value!=val;};
	inline bool operator!=(SocketInformationOptions val,SocketInformationOptions &st){return st.value!=val.value;};
	// Socket::Shutdown(System.Net.Sockets.SocketShutdown) ����ʹ�õĳ�����
	class SocketShutdown
	{
	public :
		SocketShutdown(int val=2):value(val){};
		int value;
		static const int Receive;//     ���ý��յ� System.Net.Sockets.Socket�����ֶ�Ϊ������
		static const int Send;//     ���÷��͵� System.Net.Sockets.Socket�����ֶ�Ϊ������
		static const int Both;//     Ϊ���ͺͽ��ս��� System.Net.Sockets.Socket�����ֶ�Ϊ������
		inline bool operator==(int val){return value==val;};
		inline bool operator==(SocketShutdown val){return value==val.value;};
		inline bool operator!=(int val){return value!=val;};
		inline bool operator!=(SocketShutdown val){return value!=val.value;};
	};
	inline bool operator==(int val,SocketShutdown &st){return st.value==val;};
	inline bool operator==(SocketShutdown val,SocketShutdown &st){return st.value==val.value;};
	inline bool operator!=(int val,SocketShutdown &st){return st.value!=val;};
	inline bool operator!=(SocketShutdown val,SocketShutdown &st){return st.value!=val.value;};
	//�����׽���ѡ���
	class SocketOptionLevel
	{
	public :
		SocketOptionLevel(int val=0):value(val){};
		int value;
		static const int IP;//     System.Net.Sockets.Socket ѡ��������� IP �׽��֡�
		static const int Tcp;//     System.Net.Sockets.Socket ѡ��������� TCP �׽��֡�
		static const int Udp;//     System.Net.Sockets.Socket ѡ��������� UDP �׽��֡�
		static const int IPv6;//     System.Net.Sockets.Socket ѡ��������� IPv6 �׽��֡�
		static const int Socket;//     System.Net.Sockets.Socket ѡ�������������׽��֡�
		inline bool operator==(int val){return value==val;};
		inline bool operator==(SocketOptionLevel val){return value==val.value;};
		inline bool operator!=(int val){return value!=val;};
		inline bool operator!=(SocketOptionLevel val){return value!=val.value;};
	};
	inline bool operator==(int val,SocketOptionLevel &st){return st.value==val;};
	inline bool operator==(SocketOptionLevel val,SocketOptionLevel &st){return st.value==val.value;};
	inline bool operator!=(int val,SocketOptionLevel &st){return st.value!=val;};
	inline bool operator!=(SocketOptionLevel val,SocketOptionLevel &st){return st.value!=val.value;};
	//��������ѡ�����ơ�
	class SocketOptionName
	{
	public :
		SocketOptionName(int val=0):value(val){};
		int value;
		//     ��ȫ�ر��׽��֣�����������
		static const int DontLinger;
		//     ʹ�׽����ܹ�Ϊ��ռ���ʽ��а󶨡�
		static const int ExclusiveAddressUse;
		//     ָ��Ҫ���뵽������ݱ��е� IP ѡ�//#define IP_OPTIONS          1           // set/get IP per-packet options                                        
		static const int IPOptions;
		//     Ϊ���ͺϲ����� Nagle �㷨��#define TCP_NODELAY     0x0001
		static const int NoDelay;
		//     ��¼������Ϣ��//#define SO_DEBUG        0x0001          // turn on debugging info recording                                     
		static const int Debug;
		//     ����У�������Ϊ��� UDP ���ݱ���
		static const int NoChecksum;
		//     ʹ�� RFC-1222 �ж���ļӼ����ݡ���ѡ��ֻ������һ�Σ����������Ժ���޷��رա�
		static const int Expedited;
		//     ָʾӦ�ó���Ϊ������ݱ��ṩ IP ͷ��
		static const int HeaderIncluded;


		//     ʹ�� RFC-1222 �ж���Ľ������ݡ���ѡ��ֻ������һ�Σ����������Ժ�Ͳ��ܹرա�
		static const int BsdUrgent;
		//     �׽�������������//#define SO_ACCEPTCONN   0x0002          // socket has had listen()                                     
		static const int AcceptConnection;
		//     ���ķ����ֶε� IP ͷ���͡�#define IP_TOS              8           // set/get IP Type Of Service                                           
		static const int TypeOfService;
		//     �����׽��ְ󶨵�����ʹ���еĵ�ַ��//#define SO_REUSEADDR    0x0004          // allow local address reuse                                     
		static const int ReuseAddress ;
		//     ���� IP ͷ����ʱ���ֶΡ�#define IP_TTL              7           // set/get IP Time To Live                                              
		static const int IpTimeToLive;
		//     ʹ�� keep-alive��//#define SO_KEEPALIVE    0x0008          // keep connections alive                                     
		static const int KeepAlive;
		//     Ϊ����Ķ�·�㲥���ݰ����ýӿڡ� #define IP_MULTICAST_IF     2           // set/get IP multicast interface                                       
		static const int MulticastInterface;
		//     IP ��·�㲥����ʱ�䡣#define IP_MULTICAST_TTL    3           // set/get IP multicast timetolive                                      
		static const int MulticastTimeToLive;
		//     IP ��·�㲥���ء� #define IP_MULTICAST_LOOP   4           // set/get IP multicast loopback                                        
		static const int MulticastLoopback;
		//     ���һ�� IP ���Ա��//#define IP_ADD_MEMBERSHIP   5           // add  an IP group membership                                          
		static const int AddMembership;
		//     ����һ�� IP ���Ա��//#define IP_DROP_MEMBERSHIP  6           // drop an IP group membership                                          
		static const int DropMembership;
		//     ���� IP ���ݱ����зֶΡ�#define IP_DONTFRAGMENT     9           // set/get IP Don't Fragment flag                                       
		static const int DontFragment;
		//     ����Դ�顣
		static const int AddSourceMembership;
		//     ����һ��Դ�顣
		static const int DropSourceMembership;
		//     ��·�ɣ������ݰ�ֱ�ӷ��͵��ӿڵ�ַ��//#define SO_DONTROUTE    0x0010          // just use interface addresses                                     
		static const int DontRoute;
		//     ��ֹԴ�е����ݡ�
		static const int BlockSource;
		//     ȡ����ֹ��ǰ����ֹ��Դ��
		static const int UnblockSource;
		//     �����йؽ��յ������ݰ�����Ϣ��
		static const int PacketInformation;
		//     ���û��ȡ UDP У��͸��ǡ�
		static const int ChecksumCoverage;
		//     ָ�� Internet Э��汾 6 (IPv6) ���ݰ������·����Ծ����Ŀ���������� Internet Э��汾 4 ������ʱ�� (TTL)��
		static const int HopLimit;
		//     �������׽����Ϸ��͹㲥��Ϣ��//#define SO_BROADCAST    0x0020          // permit sending of broadcast msgs                                     
		static const int Broadcast;
		//     ����ʱ�ܿ�Ӳ����//#define SO_USELOOPBACK  0x0040          // bypass hardware when possible                                     
		static const int UseLoopback;
		//     �������δ���͵����ݣ����ڹر�ʱ������ //#define SO_LINGER       0x0080          // linger on close if data present                                     
		static const int Linger;
		//     ���������������еĴ������ݡ�//#define SO_OOBINLINE    0x0100          // leave received OOB data in line                                     
		static const int OutOfBandInline;
		//     ָ��Ϊ���ͱ�����ÿ���׽��ֻ������ռ�����������������Ϣ��С�� TCP ���ڵĴ�С�޹ء�//#define SO_SNDBUF       0x1001          // send buffer size                                     
		static const int SendBuffer;
		//     ָ��Ϊ���ձ�����ÿ���׽��ֻ������ռ�����������������Ϣ��С�� TCP ���ڵĴ�С�޹ء�//#define SO_RCVBUF       0x1002          // receive buffer size                                     
		static const int ReceiveBuffer;
		//     Ϊ Overload:System.Net.Sockets.Socket.Send ����ָ����ˮӡ��//#define SO_SNDLOWAT     0x1003          // send low-water mark                                     
		static const int SendLowWater;
		//     Ϊ Overload:System.Net.Sockets.Socket.Receive ����ָ����ˮӡ��
		static const int ReceiveLowWater;
		//     ���ͳ�ʱ����ѡ��ֻ������ͬ�������������첽�������� System.Net.Sockets.Socket.BeginSend(System.Byte[],System.Int32,System.Int32,System.Net.Sockets.SocketFlags,System.AsyncCallback,System.Object)
		//     ��������Ч��//#define SO_SNDTIMEO     0x1005          // send timeout                                     
		static const int SendTimeout;
		//     ���ճ�ʱ����ѡ��ֻ������ͬ�������������첽�������� System.Net.Sockets.Socket.BeginSend(System.Byte[],System.Int32,System.Int32,System.Net.Sockets.SocketFlags,System.AsyncCallback,System.Object)
		//     ��������Ч��//#define SO_RCVTIMEO     0x1006          // receive timeout                                     
		static const int ReceiveTimeout;
		//     ��ȡ����״̬�������//#define SO_ERROR        0x1007          // get error status and clear                                     
		static const int Error;
		//     ��ȡ�׽������͡�//#define SO_TYPE         0x1008          // get socket type                                     
		static const int Type;
		//     ʹ�������׽��ֵ����Ը����ѽ����׽��ֵ����ԡ����Ч��ʹ�� Winsock2 SO_UPDATE_ACCEPT_CONTEXT �׽���ѡ����ҽ����������ӵ��׽�������֧�֡�
		static const int UpdateAcceptContext;
		//     ʹ�������׽��ֵ����Ը����������׽��ֵ����ԡ����Ч��ʹ�� Winsock2 SO_UPDATE_CONNECT_CONTEXT �׽���ѡ����ҽ����������ӵ��׽�������֧�֡�
		static const int UpdateConnectContext;
		//     ����֧�֣����ʹ�ã������� System.Net.Sockets.SocketException��
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

	//ָ�� Socket ���ʵ������ʹ�õ�Э�����͡�InterNetwork ��Ӧ AF_INET
	class ProtocolFamily
	{
	public :
		ProtocolFamily(int val=0):value(val){};
		int value;
		//δ֪Э�顣
		static const int Unknown;
		//δָ����Э�顣
		static const int Unspecified;
		//Unix ���ص�����Э�顣
		static const int Unix;
		//IP �汾 4 Э�顣
		static const int InterNetwork;   //#define AF_INET         2               // internetwork: UDP, TCP, etc.                                     
		//ARPANET IMP Э�顣
		static const int ImpLink;
		//PUP Э�顣
		static const int Pup;
		//MIT CHAOS Э�顣
		static const int Chaos;
		//IPX �� SPX Э�顣
		static const int Ipx;
		//Xerox NS Э�顣
		static const int NS;
		//OSI Э�顣
		static const int Osi;
		//ISO Э�顣
		static const int Iso;
		//ŷ�޼����������Э�� (ECMA) Э�顣
		static const int Ecma;
		//DataKit Э�顣
		static const int DataKit;
		//CCITT Э�飬�� X.25��
		static const int Ccitt;
		//IBM SNA Э�顣
		static const int Sna;
		//DECNet Э�顣
		static const int DecNet;
		//ֱ����������Э�顣
		static const int DataLink;
		//LAT Э�顣
		static const int Lat;
		//NSC HyperChannel Э�顣
		static const int HyperChannel;
		//AppleTalk Э�顣
		static const int AppleTalk;
		//NetBIOS Э�顣
		static const int NetBios;
		//VoiceView Э�顣
		static const int VoiceView;
		//FireFox Э�顣
		static const int FireFox;
		//Banyan Э�顣
		static const int Banyan;
		//���� ATM ����Э�顣
		static const int Atm;
		//IP �汾 6 Э�顣
		static const int InterNetworkV6;
		//Microsoft Ⱥ����ƷЭ�顣
		static const int Cluster;
		//IEEE 1284.4 ������Э�顣
		static const int Ieee12844;
		//IrDA Э�顣
		static const int Irda;
		//֧����������� OSI ���ص�Э�顣
		static const int NetworkDesigners;
		//MAX Э�顣
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

	//ָ��Socket ��֧�ֵ�Э�顣
	class ProtocolType
	{
	public :
		ProtocolType(int val=0):value(val){};
		int value;
		//δ֪Э�顣
		static const int Unknown;
		//IPv6 ����ѡ��ͷ��
		static const int IPv6HopByHopOptions;
		//δָ����Э�顣
		static const int Unspecified;
		//����Э�顣
		static const int IP;
		//������Ϣ����Э�顣
		static const int Icmp;
		//���������Э�顣
		static const int Igmp;
		//���ص�����Э�顣
		static const int Ggp;
		//Internet Э��汾 4��
		static const int IPv4;
		//�������Э�顣
		static const int Tcp;
		//PARC ͨ�����ݰ�Э�顣
		static const int Pup;
		//�û����ݱ�Э�顣
		static const int Udp;
		//Internet ���ݱ�Э�顣
		static const int Idp;
		//Internet Э��汾 6 (IPv6)��
		static const int IPv6;
		//IPv6 ·��ͷ��
		static const int IPv6RoutingHeader;
		//IPv6 Ƭ��ͷ��
		static const int IPv6FragmentHeader;
		//IPv6 ��װʽ��ȫ��ʩ����ͷ��
		static const int IPSecEncapsulatingSecurityPayload;
		//IPv6 �����֤ͷ���й���ϸ��Ϣ����μ�λ�� http://www.ietf.org �е� RFC 2292 �� 2.2.1 �ڡ�
		static const int IPSecAuthenticationHeader;
		//���� IPv6 �� Internet ������ϢЭ�顣
		static const int IcmpV6;
		//IPv6 No Next ͷ��
		static const int IPv6NoNextHeader;
		//IPv6 Ŀ��ѡ��ͷ��
		static const int IPv6DestinationOptions;
		//�������Э�飨����ʽ����
		static const int ND;
		//ԭʼ IP ���ݰ�Э�顣
		static const int Raw;
		//Internet ���ݰ�����Э�顣
		static const int Ipx;
		//˳�������Э�顣
		static const int Spx;
		//˳�������Э��� 2 �档
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
