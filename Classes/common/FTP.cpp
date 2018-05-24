//=========================================================
//progame      Common::FtpClient  
//company      hans
//copyright    Copyright (c) hans  2007-4     2008-03
//version      1.0
//Author       hans
//date         2007 - 2010
//description  Common namespace
//				This library is free software. Permission to use, copy,
//				modify and redistribute it for any purpose is hereby granted
//				without fee, provided that the above copyright notice appear
//				in all copies.
// ==============================================================
//#include "Common.h"
#define CPP_FILE 3
#include "Common.h" // "includeHead.h"	//unix FTP

namespace Common
{
	const int FTPClient::BLOCK_SIZE = 65535*4-1;//512;
	FTPClient::FTPClient()
    {
        strRemoteHost = "";
        strRemotePath = "";
        strRemoteUser = "";
        strRemotePass = "";
        strRemotePort = 21;
        bConnected = false;
    };
        
	FTPClient::FTPClient(String remoteHost, String remotePath, String remoteUser, String remotePass, int remotePort)
    {
        strRemoteHost = remoteHost;
        strRemotePath = remotePath;
        strRemoteUser = remoteUser;
        strRemotePass = remotePass;
        strRemotePort = remotePort;
        Connect();
    };
	bool FTPClient::Connect()
    {
		socketControl = Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
 		IPAddress ep(RemoteHost(), strRemotePort);
        try
        {
            socketControl.Connect(ep);        // 链接
        }
        catch (Exception)
        {
            EXP("Couldn't connect to remote server");
			return false;
        }   // 获取应答码
        ReadReply();
        if (iReplyCode != 220)
        {
            DisConnect();
            EXP(strReply.SubString(4));
			return false;
        }   // 登陆
        SendCommand("USER " + strRemoteUser);
        if (!(iReplyCode == 331 || iReplyCode == 230))
        {
            CloseSocketConnect();//关闭连接
            EXP(strReply.SubString(4));
			return false;
        }
        if (iReplyCode != 230)
        {
            SendCommand("PASS " + strRemotePass);
            if (!(iReplyCode == 230 || iReplyCode == 202))
            {
                CloseSocketConnect();//关闭连接
                EXP(strReply.SubString(4));
				return false;
            }
        }
        bConnected = true;   // 切换到目录
        ChDir(strRemotePath);
		return true;
    };
	void FTPClient::DisConnect()
    {
        if (socketControl.isNull()==false)
        {
            SendCommand("QUIT");
        }
        CloseSocketConnect();
    };
	void FTPClient::SetTransferType(TransferType ttType)
    {
		if (ttType == Binary)
        {
            SendCommand("TYPE I");//binary类型传输
        }
        else
        {
            SendCommand("TYPE A");//ASCII类型传输
        }
        if (iReplyCode != 200)
        {
            EXP(strReply.SubString(4));
        }
        else
        {
            trType = ttType;
        }
    };
	FTPClient::TransferType FTPClient::GetTransferType()
    {
        return trType;
    };
	Array<String> FTPClient::Dir(String strMask)
    {
        // 建立链接
        if (!bConnected)
        {
            Connect();
        }   //建立进行数据连接的socket
        Socket socketData = CreateDataSocket();

        //传送命令
        SendCommand("NLST " + strMask);   //分析应答代码
        if (!(iReplyCode == 150 || iReplyCode == 125 || iReplyCode == 226))
        {
            EXP(strReply.SubString(4));
        }   //获得结果
        strMsg = "";
        while (true)
        {
            int iBytes = socketData.Receive(buffer, BLOCK_SIZE, 0);
			if(iBytes<0)EXP("接收数据错误");
			buffer[iBytes]=0;
            strMsg += buffer;
            if (iBytes < BLOCK_SIZE)
            {
                break;
            }
        }
        socketData.Close();//数据socket关闭时也会有返回码
        if (iReplyCode != 226)
        {
            ReadReply();
            if (iReplyCode != 226)
            {
                EXP(strReply.SubString(4));
            }
        }
        Array<String> strsFileList = strMsg.Split('\n');
        return strsFileList;
    };
	long FTPClient::GetFileSize(String strFileName)
    {
        if (!bConnected)
        {
            Connect();
        }
		SendCommand("SIZE " + Path::GetFileName(strFileName));
        long lSize = 0;
        if (iReplyCode == 213)
        {
            lSize = atol(strReply.SubString(4).c_str());
        }
        else
        {
            EXP(strReply.SubString(4));
        }
        return lSize;
    };
	void FTPClient::Delete(String strFileName)
    {
        if (!bConnected)
        {
            Connect();
        }
        SendCommand("DELE " + strFileName);
        if (iReplyCode != 250)
        {
            EXP(strReply.SubString(4));
        }
    }
	void FTPClient::Rename(String strOldFileName, String strNewFileName)
    {
        if (!bConnected)
        {
            Connect();
        }
        SendCommand("RNFR " + strOldFileName);
        if (iReplyCode != 350)
        {
            EXP(strReply.SubString(4));
        }
        // 如果新文件名与原有文件重名,将覆盖原有文件
        SendCommand("RNTO " + strNewFileName);
        if (iReplyCode != 250)
        {
            EXP(strReply.SubString(4));
        }
    };
	bool FTPClient::Gets(String strFolder,String strFileNameMask)
    {
        if (!bConnected)
        {
            Connect();
        }
        Array<String> strFiles = Dir(strFileNameMask);
        for(int i=0;i<strFiles.size();i++)// String strFile in strFiles)
        {
			String &strFile =strFiles[i];
            if (strFile.Trim()!="")//一般来说strFiles的最后一个元素可能是空字符串
            {
                if(Get(strFile, strFolder+strFile)==-1)
					return false;
            }
        }
		return true;
    };
	long FTPClient::Get(String remote_file,String local_file)
    {
        if (!bConnected)
        {
            Connect();
        }
		long fileSize=0;
		FILE *localfile = NULL;
		if(local_file=="")local_file=remote_file;
		localfile=fopen(local_file.c_str(), "wb+");
		if (localfile==NULL)
		{
			EXP(String("本地文件打开失败：")+local_file+"\t"+strerror(errno));
		}
		subFileStream output=File::OpenWrite(local_file); //	会自动关闭
        Socket socketData = CreateDataSocket();
        SendCommand("RETR " + remote_file);
        if (!(iReplyCode == 150 || iReplyCode == 125 || iReplyCode == 226 || iReplyCode == 250))
        {
            EXP(strReply.SubString(4));
        }
		int iBytes=0;
		while ((iBytes=socketData.Receive(buffer,BLOCK_SIZE,0)) > 0)
        { 
			buffer[iBytes]=0;
			if (output.write(buffer, iBytes)<= 0)
			{
				EXP(String("本地文件打开失败：")+local_file+"\t"+strerror(errno));
				errorCode=errno;
				fileSize=-1;break;
			}
        }
 		if(fileSize!=-1)
			fileSize=output.fileSize() ;
        output.close();
        if (socketData.Connected())
        {
            socketData.Close();
        }
        if (!(iReplyCode == 226 || iReplyCode == 250))
        {
            ReadReply();
            if (!(iReplyCode == 226 || iReplyCode == 250))
            {
                EXP(strReply.SubString(4));
            }
        }
		return fileSize;
    };
     
	bool FTPClient::Puts(String strFolder, String strFileNameMask)
    {
		Array<String> strFiles = Directory::GetFiles(strFolder, strFileNameMask);
        for(int i=0;i<strFiles.size();i++)// String strFile in strFiles)
        {
			String &strFile =strFiles[i];
            if (strFile.Trim()!="")//一般来说strFiles的最后一个元素可能是空字符串
            {
                if(Put(strFile, strFile)==false)
					return false;
            }
        }
		return true;
    }
	bool FTPClient::Put(String local_file,String remote_file)
    {
        if (!bConnected)
        {
            Connect();
        }
        Socket socketData = CreateDataSocket();
		SendCommand("STOR " + Path::GetFileName(remote_file));
        if (!(iReplyCode == 125 || iReplyCode == 150))
        {
            EXP(strReply.SubString(4));
        }
		subFileStream input=File::OpenRead(local_file); //	会自动关闭
        int iBytes = 0;
        while ((iBytes = input.read(buffer, BLOCK_SIZE)) > 0)
        {
            socketData.Send(buffer, iBytes, 0);
        }
        input.close();
        if (socketData.Connected())
        {
            socketData.Close();
        }
        if (!(iReplyCode == 226 || iReplyCode == 250))
        {
            ReadReply();
            if (!(iReplyCode == 226 || iReplyCode == 250))
            {
                EXP(strReply.SubString(4));
				return false;
            }
        }
		return true;
    };
	bool FTPClient::MkDir(String strDirName)
    {
        if (!bConnected)
        {
            Connect();
        }
        SendCommand("MKD " + strDirName);
        if (iReplyCode != 257)
        {
            EXP(strReply.SubString(4));
			return false;
        }
		return true;
    };
	bool FTPClient::RmDir(String strDirName)
    {
        if (!bConnected)
        {
            Connect();
        }
        SendCommand("RMD " + strDirName);
        if (iReplyCode != 250)
        {
            EXP(strReply.SubString(4));
			return false;
        }
		return true;
    }; 
	bool FTPClient::ChDir(String strDirName)
    {
        if (strDirName.Trim()=="" || strDirName==".")
        {
            return true;
        }
        if (!bConnected)
        {
            Connect();
        }
        SendCommand("CWD " + strDirName);
        if (iReplyCode != 250)
        {
            EXP(strReply.SubString(4));
			return false;
        }
        this->strRemotePath = strDirName;
		return true;
    };   
    void FTPClient::ReadReply()
    {
        strMsg = "";
        strReply = ReadLine();
        iReplyCode = atoi(strReply.SubString(0, 3).c_str());
    };
	Socket FTPClient::CreateDataSocket()
    {
        SendCommand("PASV");
        if (iReplyCode != 227)
        {
            EXP(strReply.SubString(4));
        }
        int index1 = strReply.IndexOf('(');
        int index2 = strReply.IndexOf(')');
        String ipData =strReply.SubString(index1 + 1, index2 - index1 - 1);
        int parts[6];
        int len = ipData.size();
        int partCount = 0;
        String buf = "";
        for (int i = 0; i < len && partCount <= 6; i++)
        {
            char ch = ipData[i];
            if (isdigit(ch))
                buf += ch;
            else if (ch != ',')
            {
                EXP("Malformed PASV strReply: " +strReply);
            }
            if (ch == ',' || i + 1 == len)
            {
                try
                {
                    parts[partCount++] = atoi(buf.c_str());
                    buf = "";
                }
                catch (Exception)
                {
                    EXP("Malformed PASV strReply: " +strReply);
                }
            }
        }
        String ipAddress = String(parts[0]) + "." + parts[1] + "." +parts[2] + "." + parts[3];
        int port = (parts[4] << 8) + parts[5];
		Socket s (AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
        IPAddress ep (ipAddress, port);
        try
        {
            s.Connect(ep);
        }
        catch (Exception)
        {
            EXP("Can't connect to remote server");
        }
        return s;
    }
	void FTPClient::CloseSocketConnect()
    {
        if (socketControl.isNull()==false)
        {
            socketControl.Close(); 
        }
        bConnected = false;
    };
	String FTPClient::ReadLine()
    {
        while (true)
        {
            int iBytes = socketControl.Receive(buffer, BLOCK_SIZE, 0);
			buffer[iBytes]=0;
            strMsg += buffer;
            if (iBytes < BLOCK_SIZE)
            {
                break;
            }
        } 
		Array<String> mess = strMsg.Split('\n',RemoveEmptyEntries);
        if (mess.size() > 2)
        {
            strMsg = mess[mess.size() - 2];
            //seperator[0]是10,换行符是由13和10组成的,分隔后10后面虽没有字符串,
            //但也会分配为空字符串给后面(也是最后一个)字符串数组,
            //所以最后一个mess是没用的空字符串
            //但为什么不直接取mess[0],因为只有最后一行字符串应答码与信息之间有空格
        }
        else
        {
            strMsg = mess[0];
        }
        if (strMsg.size()<4 || strMsg[3]!=' ')//返回字符串正确的是以应答码(如220开头,后面接一空格,再接问候字符串)
        {
            return ReadLine();
        }
        return strMsg;
    };

	void FTPClient::SendCommand(String strCommand)
    {
		strCommand+= "\r\n";
        socketControl.Send((void *)strCommand.c_str(), strCommand.size(), 0);
        ReadReply();
    }
}
//
