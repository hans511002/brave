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
//			425 Can��t open data connection.
//			226 Closing data connection.
//		USER��USERNAME������½FTP���û�����ִ�гɹ�����220��
//		PASS��PASSWORD�������룬ִ�гɹ�����230��
//		REST��POS����ָ���ļ����صĿ�ʼλ�ã�ִ�гɹ�����350��
//		SIZE��FILENAME�����ļ���С��ִ�гɹ�����213��
//		PASV�������������ӣ�ͬʱȡ��FTP�����������ļ�ʱ�õĶ˿ںţ�ִ�гɹ�����227��
//		TYPE��ָ�������ļ������ͣ�����ΪI�Ƕ������ļ���ΪA���ַ��ļ���ִ�гɹ�����200��
//		RETR��FILENAME���������ļ���ִ�гɹ�����125��
//�ȷ��͡�REST 100����������·������Ƿ�֧�ֶϵ����أ��緵�سɹ����룬�Ϳ�ʵ�ֶ��߳����أ�Ȼ���͡�SIZE����
//ȡ���ļ��Ĵ�С�������ļ���С�����ļ���Ϊ�����֣����¸����ֵ�ƫ�Ƶ�ַ������Ϊ�������������߳�ȥ���ء��������߳��У�
//�Ƚ������̴߳������Ĳ������ļ�����ƫ�Ƶ�ַ�������ַ�ȣ����ٷ��͡�PASV����������������ӣ����½�һ�׽������ӵ��µĶ˿ڣ�
//Ȼ������ļ����ͣ��������ļ����͡�TYPE  I������ı��ļ����͡�TYPE  A�����֮���͡�REST  ���ļ�ƫ�Ƶ�ַ�������
//֪ͨ�������ı佫Ҫ���ص��ļ��Ŀ�ʼ��ַ�����ִ�С�RETR ���ļ���������������ļ���������Ϻ󣬱�δ���ϲ��ļ����ɡ�
//��������CSDN���ͣ�ת�������������http://blog.csdn.net/xiaolang85/archive/2009/10/28/4738535.aspx
// ==============================================================
#ifndef __Common_FTPClient_H__
#define __Common_FTPClient_H__
//#include "Common.h"

namespace Common
{
	using namespace Common::net; 
    /// <summary>
    /// FTPClient ��ժҪ˵����
    /// </summary>
    class FTPClient
    {
        /// <summary>
        /// ȱʡ���캯��
        /// </summary>
	public:
		FTPClient();
        /// <summary>
        /// ���캯��
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
        /// FTP������IP��ַ
        /// </summary>
		String strRemoteHost;
        /// <summary>
        /// FTP�������˿�
        /// </summary>
        int strRemotePort;
        /// <summary>
        /// ��ǰ������Ŀ¼
        /// </summary>
        String strRemotePath;
        /// <summary>
        /// ��¼�û��˺�
        /// </summary>
        String strRemoteUser;
        /// <summary>
        /// �û���¼����
        /// </summary>
        String strRemotePass;
		/// <summary>
        /// �Ƿ��¼
        /// </summary>
        bool bConnected;
        /// <summary>
        /// ���������ص�Ӧ����Ϣ(����Ӧ����)
        /// </summary>
        String strMsg;
        /// <summary>
        /// ���������ص�Ӧ����Ϣ(����Ӧ����)
        /// </summary>
        String strReply;
        /// <summary>
        /// ���������ص�Ӧ����
        /// </summary>
        int iReplyCode;
        /// <summary>
        /// ���п������ӵ�socket
        /// </summary>
        Socket socketControl;
	public:
 		/// <summary>
        /// ����ģʽ:���������͡�ASCII����
        /// </summary>
        enum TransferType { Binary, ASCII }; 
 	private :
       /// <summary>
        /// ����ģʽ
        /// </summary>
        TransferType trType;
        /// <summary>
        /// ���պͷ������ݵĻ�����
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
        /// �������� 
        /// </summary>
        bool Connect();
        /// <summary>
        /// �ر�����
        /// </summary>
        void DisConnect();
		void close(){DisConnect();};
		/// <summary>
        /// ���ô���ģʽ
        /// </summary>
        /// <param name="ttType">����ģʽ</param>
        void SetTransferType(TransferType ttType);
        /// <summary>
        /// ��ô���ģʽ
        /// </summary>
        /// <returns>����ģʽ</returns>
        TransferType GetTransferType(); 
        /// <summary>
        /// ����ļ��б�
        /// </summary>
        /// <param name="strMask">�ļ�����ƥ���ַ���</param>
        /// <returns></returns>
        Array<String> Dir(String strMask);
        /// <summary>
        /// ��ȡ�ļ���С
        /// </summary>
        /// <param name="strFileName">�ļ���</param>
        /// <returns>�ļ���С</returns>
        long GetFileSize(String strFileName);
        /// <summary>
        /// ɾ��
        /// </summary>
        /// <param name="strFileName">��ɾ���ļ���</param>
        void Delete(String strFileName);
        /// <summary>
        /// ������(������ļ����������ļ�����,�����������ļ�)
        /// </summary>
        /// <param name="strOldFileName">���ļ���</param>
        /// <param name="strNewFileName">���ļ���</param>
        void Rename(String strOldFileName, String strNewFileName);
        /// <summary>
        /// ����һ���ļ�
        /// </summary>
        /// <param name="strFileNameMask">�ļ�����ƥ���ַ���</param>
        /// <param name="strFolder">����Ŀ¼(������\����)</param>
        bool Gets(String strFolder,String strFileNameMask);
        /// <summary>
        /// ����һ���ļ�
        /// </summary>
        /// <param name="remote_file">Ҫ���ص��ļ���</param>
        /// <param name="local_file">�����ڱ���ʱ���ļ���</param> 
        long Get(String remote_file,String local_file);
        /// <summary>
        /// �ϴ�һ���ļ�
        /// </summary>
        /// <param name="strFolder">����Ŀ¼(������\����)</param>
        /// <param name="strFileNameMask">�ļ���ƥ���ַ�(���԰���*��?)</param>
        bool Puts(String strFolder, String strFileNameMask);
        /// <summary>
        /// �ϴ�һ���ļ�
        /// </summary>
        /// <param name="local_file">�����ļ���</param>
        /// <param name="remote_file">Զ���ļ���</param>
		bool Put(String local_file,String remote_file);
        /// <summary>
        /// ����Ŀ¼
        /// </summary>
        /// <param name="strDirName">Ŀ¼��</param>
        bool MkDir(String strDirName);

        /// <summary>
        /// ɾ��Ŀ¼
        /// </summary>
        /// <param name="strDirName">Ŀ¼��</param>
        bool RmDir(String strDirName);

        /// <summary>
        /// �ı�Ŀ¼
        /// </summary>
        /// <param name="strDirName">�µĹ���Ŀ¼��</param>
        bool ChDir(String strDirName);

        /// <summary>
        /// ��һ��Ӧ���ַ�����¼��strReply��strMsg
        /// Ӧ�����¼��iReplyCode
        /// </summary>
        void ReadReply();
		/// <summary>
        /// ���������������ӵ�socket
        /// </summary>
        /// <returns>��������socket</returns>
        Socket CreateDataSocket();
        /// <summary>
        /// �ر�socket����(���ڵ�¼��ǰ)
        /// </summary>
        void CloseSocketConnect();
        /// <summary>
        /// ��ȡSocket���ص������ַ���
        /// </summary>
        /// <returns>����Ӧ������ַ�����</returns>
        String ReadLine();
        /// <summary>
        /// ���������ȡӦ��������һ��Ӧ���ַ���
        /// </summary>
        /// <param name="strCommand">����</param>
        void SendCommand(String strCommand);
    };
}

#endif