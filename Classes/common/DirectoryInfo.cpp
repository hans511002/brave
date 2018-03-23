// ==============================================================
//progame      Common::Directory  File
//company      hans
//copyright    Copyright (c) hans  2007-4     2008-06
//version      1.0
//Author       hans
//date         2007-4     2008-06
//description  FileSystem with file access
//				This library is free software. Permission to use, copy,
//				modify and redistribute it for any purpose is hereby granted
//				without fee, provided that the above copyright notice appear
//				in all copies.
// ==============================================================
#include "Common.h"
//#define CPP_FILE 2
//#include "Common.h" // "includeHead.h"	//unix FTP

namespace Common
{
//DirectoryInfo const var//
#ifdef __Common_DirectoryInfo__
	const int MAX_DIRECTORY_PATH = 0xf8;
#if OSTYPE>10
	const char * const Path::InvalidPathChars="*";
	const char * const Path::InvalidFileNameChars="\\/*";
	const char Path::DirectorySeparatorChar='/';
	const char Path::VolumeSeparatorChar=0;
#else
	const char * const Path::InvalidPathChars="?*|\"<>";
	const char * const Path::InvalidFileNameChars="?*|\"<>\\:/";
	const char Path::DirectorySeparatorChar='\\';
	const char Path::VolumeSeparatorChar=':';
#endif
	const int Path::MaxPath=260;
#endif
//FileInfo const var//
#ifdef __Common_FileInfo__

#endif

	// ժҪ:
	//     �� path ��ָ����������Ŀ¼����Ŀ¼.
	//
	// ����:
	//   path:
	//     Ҫ������Ŀ¼·����
	//
	// ���ؽ��:
	//     �� path ָ���� System.IO.DirectoryInfo��
	DirectoryInfo Directory::CreateDirectory(String path)
	{
		if (path.empty())
		{
			EXP("path is null");
		}
		if(Directory::CreateDir(path)==true)
		{
			return DirectoryInfo(path);
		}
		return DirectoryInfo("");
	};
	//
	// ժҪ:
	//     ����ָ��·���ĸ�Ŀ¼����������·�������·����
	//
	// ����:
	//   path:
	//     ���ڼ�����Ŀ¼��·����
	//
	// ���ؽ��:
	//     ��Ŀ¼��������� path �Ǹ�Ŀ¼������ UNC �������������ĸ�����Ϊnull��
	DirectoryInfo Directory::GetParent(String path)
	{
		path=Path::GetFullPath(path);
		if(path[path.size()-1]==Path::DirectorySeparatorChar)
		{
			path[path.size()-1]=0;
		}
		path=path.SubString(0,path.LastIndexOf(Path::DirectorySeparatorChar));
		return DirectoryInfo(path);
	};

 	//
	// ժҪ:
	//     ��ȡ��ǰĿ¼����ָ������ģʽƥ�䲢ʹ��ĳ��ֵȷ���Ƿ�����Ŀ¼��������Ŀ¼�����顣
	//
	// ����:
	//   searchOption:
	//     System.IO.SearchOption ֵ֮һ��ָ����������Ӧ����������Ŀ¼���ǽ�������ǰĿ¼��
	//
	//   path:
	//     Ҫ������·����
	//
	//   searchPattern:
	//     Ҫ�� path �е��ļ���ƥ��������ַ������˲���������������㣨��..���������������� System.IO.Path.DirectorySeparatorChar
	//     �� System.IO.Path.AltDirectorySeparatorChar ��ǰ�����������㣨��..������Ҳ���ܰ��� System.IO.Path.InvalidPathChars
	//     �е��κ��ַ���
	//
	// ���ؽ��:
	//     ������ģʽƥ���Ŀ¼�� String ���顣
	void Directory::InternalGetFileDirectoryNames(Array<String> &res,String path,bool includeFiles,
		bool includeDirs,String searchPattern,bool ignoreCase,SearchOption searchOption)
	{
		if(includeFiles==false && includeDirs==false)return;
		path=Path::GetFullPath(path,true);
		int index=0;
		FILE * hFile;
		char szBuff[1024];
		memset(szBuff,0,sizeof(szBuff));
		String subPath;
		bool search=(searchPattern.empty()==false);
#if OSTYPE>10
		hFile=POPEN(("ls -l \""+path+"\"").c_str(),"r");
		if(!hFile)
			EXP("ִ��Ŀ¼�б�����ʧ��");
		char * dest[100];
		while(fgets(szBuff, sizeof(szBuff)-1, hFile))
		{
			if(index++==0)continue;   //ȥ�� total 19584
			int len=String::Split(dest,szBuff,' ');
			if(dest[len-1][strlen(dest[len-1])-1]=='\n')dest[len-1][strlen(dest[len-1])-1]=0;	//ȥ���س�
			char ch=dest[0][0];
			switch(ch)							//If the first character is:
			{
			case 'd':								//d The entry is a directory.
				subPath=path+dest[len-1]+Path::DirectorySeparatorChar;
				if(searchOption==AllDirectories)
				{
					InternalGetFileDirectoryNames(res,subPath,includeFiles, includeDirs,searchPattern,ignoreCase,searchOption);
				}
				if(includeDirs==false)break;
				if(search==false || String::IndexOf(dest[len-1],searchPattern,ignoreCase)!=-1)
					res[res.size()]=subPath;
				break;
			case 'b':								//b The entry is a block special file.
			case 'c':								//c The entry is a character special file.
			case 'l':								//l The entry is a symbolic link, and either the -N flag was specified or the symbolic link did not point to an existing file.
			case 'p':								//p The entry is a first-in,first-out (FIFO) special file.
			case 's':								//s The entry is a local socket.
			case '-':								//- The entry is an ordinary file.
				if(includeFiles==false)break;
				subPath=path+dest[len-1];
				if(search==false || String::IndexOf(dest[len-1],searchPattern,ignoreCase)!=-1)
					res[res.size()]=subPath;
				break;
			}
			memset(szBuff,0,sizeof(szBuff));
		}
		PCLOSE(hFile);
#else
		if(includeDirs==true && includeFiles==false)//dir /AD /B
		{
			hFile=POPEN(("dir /AD-S /B \""+path+"\"").c_str(),"r");
			if(!hFile)
				EXP("ִ��Ŀ¼�б�����ʧ��");
			string filePath="";
			while(fgets(szBuff, sizeof(szBuff)-1, hFile))
			{
				if(szBuff[0]==32 || szBuff[0]=='\n')continue;
				if(szBuff[strlen(szBuff)-1]=='\n')szBuff[strlen(szBuff)-1]=0;	//ȥ���س�
				subPath=path+szBuff+Path::DirectorySeparatorChar;
				if(searchOption==AllDirectories)
				{
					InternalGetFileDirectoryNames(res,subPath,includeFiles, includeDirs,searchPattern,ignoreCase,searchOption);
				}
				if(search==false || String::IndexOf(szBuff,searchPattern,ignoreCase)!=-1)
					res[res.size()]=subPath;
				memset(szBuff,0,sizeof(szBuff));
			}
		}
		else if(includeDirs==false && includeFiles==true)
		{
			hFile=POPEN(("dir /A-S-D /B \""+path+"\"").c_str(),"r");
			if(!hFile)
				EXP("ִ��Ŀ¼�б�����ʧ��");
			string filePath="";
			while(fgets(szBuff, sizeof(szBuff)-1, hFile))
			{
				if(szBuff[0]==32 || szBuff[0]=='\n')continue;
				if(szBuff[strlen(szBuff)-1]=='\n')szBuff[strlen(szBuff)-1]=0;	//ȥ���س�
				if(search==false || String::IndexOf(szBuff,searchPattern,ignoreCase)!=-1)
					res[res.size()]=path+szBuff+Path::DirectorySeparatorChar;
				memset(szBuff,0,sizeof(szBuff));
			}
		}
		else
		{
			hFile=POPEN(("dir /AD-S /B \""+path+"\"").c_str(),"r");
			if(!hFile)
				EXP("ִ��Ŀ¼�б�����ʧ��");
			string filePath="";
			while(fgets(szBuff, sizeof(szBuff)-1, hFile))
			{
				if(szBuff[0]==32 || szBuff[0]=='\n')continue;
				if(szBuff[strlen(szBuff)-1]=='\n')szBuff[strlen(szBuff)-1]=0;	//ȥ���س�
				subPath=path+szBuff+Path::DirectorySeparatorChar;
				if(searchOption==AllDirectories)
				{
					InternalGetFileDirectoryNames(res,subPath,includeFiles, includeDirs,searchPattern,ignoreCase,searchOption);
				}
				if(search==false || String::IndexOf(szBuff,searchPattern,ignoreCase)!=-1)
					res[res.size()]=subPath;
				memset(szBuff,0,sizeof(szBuff));
			}
			PCLOSE(hFile);
			hFile=POPEN(("dir /A-D-S /B \""+path+"\"").c_str(),"r");
			if(!hFile)
				EXP("ִ��Ŀ¼�б�����ʧ��");
			while(fgets(szBuff, sizeof(szBuff)-1, hFile))
			{
				if(szBuff[0]==32 || szBuff[0]=='\n')continue;
				if(szBuff[strlen(szBuff)-1]=='\n')szBuff[strlen(szBuff)-1]=0;	//ȥ���س�
				if(search==false || String::IndexOf(szBuff,searchPattern,ignoreCase)!=-1)
					res[res.size()]=path+szBuff+Path::DirectorySeparatorChar;
				memset(szBuff,0,sizeof(szBuff));
			}
		}
		PCLOSE(hFile);
#endif
	}
	//��ȡ��Ŀ¼�б�
	Array<DirectoryInfo> DirectoryInfo::GetDirectoryInfos(String searchPattern,bool ignoreCase, SearchOption searchOption)
	{
		Array<String> dires=GetDirectories(searchPattern,ignoreCase,searchOption);
		int len=dires.size();
		Array<DirectoryInfo> res(len);
		for(int i=0;i<len;i++)
		{
			res[i]=DirectoryInfo(dires[i]);
		}
		return res;
	}
	//��ȡ�ļ��б�
	Array<FileInfo> DirectoryInfo::GetFileInfos(String searchPattern,bool ignoreCase, SearchOption searchOption)
	{
		Array<String> dires=GetFiles(searchPattern,ignoreCase,searchOption);
		int len=dires.size();
		Array<FileInfo> res(len);
		for(int i=0;i<len;i++)
		{
			res[i]=FileInfo(dires[i]);
		}
		return res;
	}

#ifdef __Common_Decoding__
	//file //
	void File::cryptFile(const String &sourceFileName, const String & destinationFileName,const String & password,int type)
	{
		String srcFile=sourceFileName,destFile=destinationFileName;
		if(destFile==srcFile)
			destFile+=".temp";
		FILE * fsrcFile=fopen(srcFile.Trim().c_str(),"rb");
		if(fsrcFile==NULL)EXP("�ļ�������->"+srcFile);
		FILE * fdestFile=fopen(destFile.Trim().c_str(),"wb");
		if(fdestFile==NULL)EXP("�����ļ�ʧ��->"+destFile);
		char src[1024];
		char dest[1024];
		int readLen=0;
		memset(src,0,1024);
		if(type==0)
		{
			while((readLen=fread(src,1,1023,fsrcFile))>0)
			{
				memset(dest,0,1024);
				Decoding::matrixDecode(src,dest,password.c_str());
				fwrite(dest,1,strlen(dest),fdestFile);
				memset(src,0,1024);
			}
		}
		else if(type==1)
		{
			while((readLen=fread(src,1,1023,fsrcFile))>0)
			{
				memset(dest,0,1024);
				Encoding::matrixEncode(src,dest,password.c_str());
				fwrite(dest,1,strlen(dest),fdestFile);
				memset(src,0,1024);
			}
		}
		fclose(fsrcFile);
		fclose(fdestFile);
		if(destinationFileName==srcFile)
		{
			File::Delete(srcFile);
			File::Rename(destFile,srcFile);
		}
	}
#endif
}

//UNIX ��ȡĿ¼
//opendir����Ŀ¼�� 
//��غ���  open��readdir��closedir��rewinddir��seekdir��telldir��scandir 
//windows�»�ȡ��Ŀ¼���ļ�
//void main(int argc, char **argv)  
//{  
//    _finddata_t file;  
//    long longf;  
//
//  //_findfirst���ص���long��; long __cdecl _findfirst(const char *, struct _finddata_t *)  
//  if((longf = _findfirst("d:\\*.*", &file))==-1l)  
//  {  
//      cout<<"�ļ�û���ҵ�!\n";  
//  }  
//  else  
//  {  
//      cout<<"\n�ļ��б�:\n";  
//      //int __cdecl _findnext(long, struct _finddata_t *);����ҵ��¸��ļ������ֳɹ��Ļ��ͷ���0,���򷵻�-1  
//      string tempName;  
//      while( _findnext( longf, &file ) == 0 )  
//      {  
//          tempName = "";  
//          tempName = file.name;  
//          if (tempName == "..")  
//          {  
//              continue;  
//          }  
//
//          cout<<file.name;  
//
//          if(file.attrib == _A_NORMAL)  
//          {  
//                cout<<"  ��ͨ�ļ�  ";  
//            }  
//            else if(file.attrib == _A_RDONLY)  
//            {  
//                cout<<"  ֻ���ļ�  ";  
//            }  
//            else if(file.attrib == _A_HIDDEN )  
//            {  
//                cout<<"  �����ļ�  ";  
//            }  
//            else if(file.attrib == _A_SYSTEM )  
//            {  
//                cout<<"  ϵͳ�ļ�  ";  
//            }  
//            else if(file.attrib == _A_SUBDIR)  
//            {  
//                cout<<"  ��Ŀ¼  ";  
//            }  
//            else   
//            {  
//                cout<<"  �浵�ļ�  ";  
//            }  
//            cout<<endl;  
//        }  
//    }  
//    _findclose(longf);  
//}  
