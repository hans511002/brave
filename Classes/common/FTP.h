//==============================================================
//progame      Common::FtpClient  
//company      hans
//copyright    Copyright (c) hans  2007-4     2008-03
//version      1.0
//Author       hans
//date         2007-4     2008-03
//description  Common namespace
//				This library is free software. Permission to use, copy,
//				modify and redistribute it for any purpose is hereby granted
//				without fee, provided that the above copyright notice appear
//				in all copies.
//	CMD:   USER    LPRT    MODE    MSOM*   RNTO    SITE    RMD     AUTH 
//		   PASS    LPSV    RETR    MSAM*   ABOR    SYST    XRMD    ADAT 
//		   ACCT*   PASV    STOR    MRSQ*   DELE    STAT    PWD     PROT 
//		   SMNT*   EPSV    APPE    MRCP*   CWD     HELP    XPWD    PBSZ 
//		   REIN    EPRT    MLFL*   ALLO    XCWD    NOOP    CDUP    CCC 
//		   QUIT    TYPE    MAIL*   REST    LIST    MKD     XCUP    SIZE 
//		   PORT    STRU    MSND*   RNFR    NLST    XMKD    STOU    MDTM 
//
//RES		125 Data connection already open; Transfer starting.
//			226 Transfer complete.
//			227 Entering Passive Mode (127,0,0,1,4,18).
//			230 User xxxxx logged in.
//			331 Password required for xxxxx.
//			425 Can’t open data connection.
//			226 Closing data connection.
//		USER〈USERNAME〉：登陆FTP的用户名，执行成功返回220；
//		PASS〈PASSWORD〉：密码，执行成功返回230；
//		REST〈POS〉：指定文件下载的开始位置，执行成功返回350；
//		SIZE〈FILENAME〉：文件大小，执行成功返回213；
//		PASV：建立数据连接，同时取得FTP服务器下载文件时用的端口号，执行成功返回227；
//		TYPE：指定下载文件的类型，参数为I是二进制文件，为A是字符文件，执行成功返回200；
//		RETR〈FILENAME〉：下载文件，执行成功返回125；
//先发送“REST 100”命令，测试下服务器是否支持断点下载，如返回成功代码，就可实现多线程下载；然后发送“SIZE”，
//取得文件的大小，根据文件大小，将文件分为几部分，记下各部分的偏移地址，并作为参数，交给各线程去下载。在下载线程中，
//先接受主线程传给他的参数（文件名，偏移地址，保存地址等），再发送“PASV”命令，建立数据连接，并新建一套接字连接到新的端口；
//然后根据文件类型，二进制文件发送“TYPE  I“命令，文本文件发送”TYPE  A“命令；之后发送“REST  〈文件偏移地址〉”命令，
//通知服务器改变将要下载的文件的开始地址；最后，执行“RETR 〈文件名〉”命令，下载文件。下载完毕后，编段代码合并文件即可。
//本文来自CSDN博客，转载请标明出处：http://blog.csdn.net/xiaolang85/archive/2009/10/28/4738535.aspx
// ==============================================================
#ifndef __Common_FTPClient_H__
#define __Common_FTPClient_H__
//#include "Common.h"

namespace Common
{
	using namespace Common::net; 
    /// <summary>
    /// FTPClient 的摘要说明。
    /// </summary>
    class FTPClient
    {
        /// <summary>
        /// 缺省构造函数
        /// </summary>
	public:
		FTPClient();
        /// <summary>
        /// 构造函数
        /// </summary>
        /// <param name="remoteHost"></param>
        /// <param name="remotePath"></param>
        /// <param name="remoteUser"></param>
        /// <param name="remotePass"></param>
        /// <param name="remotePort"></param>
        FTPClient(String remoteHost, String remotePath, String remoteUser, String remotePass, int remotePort); 
	private :
		String  errMsg;
		int   DebugLevel;
		int errorCode;
		/// <summary>
        /// FTP服务器IP地址
        /// </summary>
		String strRemoteHost;
        /// <summary>
        /// FTP服务器端口
        /// </summary>
        int strRemotePort;
        /// <summary>
        /// 当前服务器目录
        /// </summary>
        String strRemotePath;
        /// <summary>
        /// 登录用户账号
        /// </summary>
        String strRemoteUser;
        /// <summary>
        /// 用户登录密码
        /// </summary>
        String strRemotePass;
		/// <summary>
        /// 是否登录
        /// </summary>
        bool bConnected;
        /// <summary>
        /// 服务器返回的应答信息(包含应答码)
        /// </summary>
        String strMsg;
        /// <summary>
        /// 服务器返回的应答信息(包含应答码)
        /// </summary>
        String strReply;
        /// <summary>
        /// 服务器返回的应答码
        /// </summary>
        int iReplyCode;
        /// <summary>
        /// 进行控制连接的socket
        /// </summary>
        Socket socketControl;
	public:
 		/// <summary>
        /// 传输模式:二进制类型、ASCII类型
        /// </summary>
        enum TransferType { Binary, ASCII }; 
 	private :
       /// <summary>
        /// 传输模式
        /// </summary>
        TransferType trType;
        /// <summary>
        /// 接收和发送数据的缓冲区
        /// </summary>
        const static int BLOCK_SIZE;// = 65535*4-1;//512;
        char buffer[65535*4];
	public:
		String & RemoteHost()
        {
			return strRemoteHost;
        }
        int & RemotePort()
        {
            return strRemotePort; 
        }
        String & RemotePath()
        {
			return strRemotePath;
        }
        String &RemoteUser()
        {
            return strRemoteUser; 
        }
        String &RemotePass()
        {
			return strRemotePass ;
        }
        bool & Connected()
        {
			return bConnected;
        } 
        /// <summary>
        /// 建立连接 
        /// </summary>
        bool Connect();
        /// <summary>
        /// 关闭连接
        /// </summary>
        void DisConnect();
		void close(){DisConnect();};
		/// <summary>
        /// 设置传输模式
        /// </summary>
        /// <param name="ttType">传输模式</param>
        void SetTransferType(TransferType ttType);
        /// <summary>
        /// 获得传输模式
        /// </summary>
        /// <returns>传输模式</returns>
        TransferType GetTransferType(); 
        /// <summary>
        /// 获得文件列表
        /// </summary>
        /// <param name="strMask">文件名的匹配字符串</param>
        /// <returns></returns>
        Array<String> Dir(String strMask);
        /// <summary>
        /// 获取文件大小
        /// </summary>
        /// <param name="strFileName">文件名</param>
        /// <returns>文件大小</returns>
        long GetFileSize(String strFileName);
        /// <summary>
        /// 删除
        /// </summary>
        /// <param name="strFileName">待删除文件名</param>
        void Delete(String strFileName);
        /// <summary>
        /// 重命名(如果新文件名与已有文件重名,将覆盖已有文件)
        /// </summary>
        /// <param name="strOldFileName">旧文件名</param>
        /// <param name="strNewFileName">新文件名</param>
        void Rename(String strOldFileName, String strNewFileName);
        /// <summary>
        /// 下载一批文件
        /// </summary>
        /// <param name="strFileNameMask">文件名的匹配字符串</param>
        /// <param name="strFolder">本地目录(不得以\结束)</param>
        bool Gets(String strFolder,String strFileNameMask);
        /// <summary>
        /// 下载一个文件
        /// </summary>
        /// <param name="remote_file">要下载的文件名</param>
        /// <param name="local_file">保存在本地时的文件名</param> 
        long Get(String remote_file,String local_file);
        /// <summary>
        /// 上传一批文件
        /// </summary>
        /// <param name="strFolder">本地目录(不得以\结束)</param>
        /// <param name="strFileNameMask">文件名匹配字符(可以包含*和?)</param>
        bool Puts(String strFolder, String strFileNameMask);
        /// <summary>
        /// 上传一个文件
        /// </summary>
        /// <param name="local_file">本地文件名</param>
        /// <param name="remote_file">远程文件名</param>
		bool Put(String local_file,String remote_file);
        /// <summary>
        /// 创建目录
        /// </summary>
        /// <param name="strDirName">目录名</param>
        bool MkDir(String strDirName);

        /// <summary>
        /// 删除目录
        /// </summary>
        /// <param name="strDirName">目录名</param>
        bool RmDir(String strDirName);

        /// <summary>
        /// 改变目录
        /// </summary>
        /// <param name="strDirName">新的工作目录名</param>
        bool ChDir(String strDirName);

        /// <summary>
        /// 将一行应答字符串记录在strReply和strMsg
        /// 应答码记录在iReplyCode
        /// </summary>
        void ReadReply();
		/// <summary>
        /// 建立进行数据连接的socket
        /// </summary>
        /// <returns>数据连接socket</returns>
        Socket CreateDataSocket();
        /// <summary>
        /// 关闭socket连接(用于登录以前)
        /// </summary>
        void CloseSocketConnect();
        /// <summary>
        /// 读取Socket返回的所有字符串
        /// </summary>
        /// <returns>包含应答码的字符串行</returns>
        String ReadLine();
        /// <summary>
        /// 发送命令并获取应答码和最后一行应答字符串
        /// </summary>
        /// <param name="strCommand">命令</param>
        void SendCommand(String strCommand);
    };
}

#endif