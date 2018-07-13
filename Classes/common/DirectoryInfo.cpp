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

	// 摘要:
	//     按 path 的指定创建所有目录和子目录.
	//
	// 参数:
	//   path:
	//     要创建的目录路径。
	//
	// 返回结果:
	//     由 path 指定的 System.IO.DirectoryInfo。
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
	// 摘要:
	//     检索指定路径的父目录，包括绝对路径和相对路径。
	//
	// 参数:
	//   path:
	//     用于检索父目录的路径。
	//
	// 返回结果:
	//     父目录；或者如果 path 是根目录，包括 UNC 服务器或共享名的根，则为null。
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
	// 摘要:
	//     获取当前目录中与指定搜索模式匹配并使用某个值确定是否在子目录中搜索的目录的数组。
	//
	// 参数:
	//   searchOption:
	//     System.IO.SearchOption 值之一，指定搜索操作应包括所有子目录还是仅包括当前目录。
	//
	//   path:
	//     要搜索的路径。
	//
	//   searchPattern:
	//     要与 path 中的文件名匹配的搜索字符串。此参数不能以两个句点（“..”）结束，不能在 System.IO.Path.DirectorySeparatorChar
	//     或 System.IO.Path.AltDirectorySeparatorChar 的前面包含两个句点（“..”），也不能包含 System.IO.Path.InvalidPathChars
	//     中的任何字符。
	//
	// 返回结果:
	//     与搜索模式匹配的目录的 String 数组。
	void Directory::InternalGetFileDirectoryNames(Array<String> &res,String path,bool includeFiles,
		bool includeDirs,String searchPattern,bool ignoreCase,SearchOption searchOption)
	{
		if(includeFiles==false && includeDirs==false)return;
		path=Path::GetFullPath(path,true);
		int index=0;
		
		char szBuff[1024];
		memset(szBuff,0,sizeof(szBuff));
		String subPath;
		bool search=(searchPattern.empty()==false);
        //文件句柄
        intptr_t hFile = 0;
        //文件信息
        struct _finddata_t fileinfo;  //很少用的文件信息读取结构
        if(path[path.length() - 1] != Path::DirectorySeparatorChar)
            path = path + Path::DirectorySeparatorChar;
        string p ;  //string类很有意思的一个赋值函数:assign()，有很多重载版本
        if ((hFile = _findfirst(p.assign(path).append("*").c_str(),&fileinfo))) {
            do {
                if ((fileinfo.attrib & _A_SUBDIR)) {  //比较文件类型是否是文件夹
                    if (strcmp(fileinfo.name,".") != 0 && strcmp(fileinfo.name,"..") != 0) {
                        String subPath = path +  fileinfo.name;
                        if(searchOption == AllDirectories)
                        {
                            InternalGetFileDirectoryNames(res, subPath, includeFiles, includeDirs, searchPattern, ignoreCase, searchOption);
                        }
                        if(!includeDirs)continue;
                        if(search == false || String::IndexOf(fileinfo.name, searchPattern, ignoreCase) != -1)
                            res.push_back(subPath); 
                    }
                } else {
                    if(includeFiles == false)continue;
                    String subPath = path +  fileinfo.name;
                    res.push_back(subPath);
                }
            } while (_findnext(hFile, &fileinfo) == 0);  //寻找下一个，成功返回0，否则-1
            _findclose(hFile);
        }
        return ;
//#if OSTYPE>10
//        FILE * hFile;
//		hFile=POPEN(("ls -l \""+path+"\"").c_str(),"r");
//		if(!hFile)
//			EXP("执行目录列表命令失败");
//		char * dest[100];
//		while(fgets(szBuff, sizeof(szBuff)-1, hFile))
//		{
//			if(index++==0)continue;   //去除 total 19584
//			int len=String::Split(dest,szBuff,' ');
//			if(dest[len-1][strlen(dest[len-1])-1]=='\n')dest[len-1][strlen(dest[len-1])-1]=0;	//去除回车
//			char ch=dest[0][0];
//			switch(ch)							//If the first character is:
//			{
//			case 'd':								//d The entry is a directory.
//				subPath=path+dest[len-1]+Path::DirectorySeparatorChar;
//				if(searchOption==AllDirectories)
//				{
//					InternalGetFileDirectoryNames(res,subPath,includeFiles, includeDirs,searchPattern,ignoreCase,searchOption);
//				}
//				if(includeDirs==false)continue;
//				if(search==false || String::IndexOf(dest[len-1],searchPattern,ignoreCase)!=-1)
//					res[res.size()]=subPath;
//				break;
//			case 'b':								//b The entry is a block special file.
//			case 'c':								//c The entry is a character special file.
//			case 'l':								//l The entry is a symbolic link, and either the -N flag was specified or the symbolic link did not point to an existing file.
//			case 'p':								//p The entry is a first-in,first-out (FIFO) special file.
//			case 's':								//s The entry is a local socket.
//			case '-':								//- The entry is an ordinary file.
//                if(includeFiles==false)continue;
//				subPath=path+dest[len-1];
//				if(search==false || String::IndexOf(dest[len-1],searchPattern,ignoreCase)!=-1)
//					res[res.size()]=subPath;
//				break;
//			}
//			memset(szBuff,0,sizeof(szBuff));
//		}
//		PCLOSE(hFile);
//#else
//        FILE * hFile;
//		if(includeDirs==true && includeFiles==false)//dir /AD /B
//		{
//			hFile=POPEN(("dir /AD-S /B \""+path+"\"").c_str(),"r");
//			if(!hFile)
//				EXP("执行目录列表命令失败");
//			string filePath="";
//			while(fgets(szBuff, sizeof(szBuff)-1, hFile))
//			{
//				if(szBuff[0]==32 || szBuff[0]=='\n')continue;
//				if(szBuff[strlen(szBuff)-1]=='\n')szBuff[strlen(szBuff)-1]=0;	//去除回车
//				subPath=path+szBuff+Path::DirectorySeparatorChar;
//				if(searchOption==AllDirectories)
//				{
//					InternalGetFileDirectoryNames(res,subPath,includeFiles, includeDirs,searchPattern,ignoreCase,searchOption);
//				}
//				if(search==false || String::IndexOf(szBuff,searchPattern,ignoreCase)!=-1)
//					res[res.size()]=subPath;
//				memset(szBuff,0,sizeof(szBuff));
//			}
//		}
//		else if(includeDirs==false && includeFiles==true)
//		{
//			hFile=POPEN(("dir /A-S-D /B \""+path+"\"").c_str(),"r");
//			if(!hFile)
//				EXP("执行目录列表命令失败");
//			string filePath="";
//			while(fgets(szBuff, sizeof(szBuff)-1, hFile))
//			{
//				if(szBuff[0]==32 || szBuff[0]=='\n')continue;
//				if(szBuff[strlen(szBuff)-1]=='\n')szBuff[strlen(szBuff)-1]=0;	//去除回车
//				if (search == false || String::IndexOf(szBuff, searchPattern, ignoreCase) != -1)
//					res[res.size()] = path + szBuff;// +Path::DirectorySeparatorChar;
//				memset(szBuff,0,sizeof(szBuff));
//			}
//		}
//		else
//		{
//			hFile=POPEN(("dir /AD-S /B \""+path+"\"").c_str(),"r");
//			if(!hFile)
//				EXP("执行目录列表命令失败");
//			string filePath="";
//			while(fgets(szBuff, sizeof(szBuff)-1, hFile))
//			{
//				if(szBuff[0]==32 || szBuff[0]=='\n')continue;
//				if(szBuff[strlen(szBuff)-1]=='\n')szBuff[strlen(szBuff)-1]=0;	//去除回车
//				subPath=path+szBuff+Path::DirectorySeparatorChar;
//				if(searchOption==AllDirectories)
//				{
//					InternalGetFileDirectoryNames(res,subPath,includeFiles, includeDirs,searchPattern,ignoreCase,searchOption);
//				}
//				if(search==false || String::IndexOf(szBuff,searchPattern,ignoreCase)!=-1)
//					res[res.size()]=subPath;
//				memset(szBuff,0,sizeof(szBuff));
//			}
//			PCLOSE(hFile);
//			hFile=POPEN(("dir /A-D-S /B \""+path+"\"").c_str(),"r");
//			if(!hFile)
//				EXP("执行目录列表命令失败");
//			while(fgets(szBuff, sizeof(szBuff)-1, hFile))
//			{
//				if(szBuff[0]==32 || szBuff[0]=='\n')continue;
//				if(szBuff[strlen(szBuff)-1]=='\n')szBuff[strlen(szBuff)-1]=0;	//去除回车
//				if (search == false || String::IndexOf(szBuff, searchPattern, ignoreCase) != -1)
//					res[res.size()] = path + szBuff;// +Path::DirectorySeparatorChar;
//				memset(szBuff,0,sizeof(szBuff));
//			}
//		}
//		PCLOSE(hFile);
//#endif
	}
	//获取子目录列表
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
	//获取文件列表
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
		if(fsrcFile==NULL)EXP("文件不存在->"+srcFile);
		FILE * fdestFile=fopen(destFile.Trim().c_str(),"wb");
		if(fdestFile==NULL)EXP("创建文件失败->"+destFile);
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

//UNIX 获取目录
//opendir（打开目录） 
//相关函数  open，readdir，closedir，rewinddir，seekdir，telldir，scandir 
//windows下获取子目录和文件
//void main(int argc, char **argv)  
//{  
//    _finddata_t file;  
//    long longf;  
//
//  //_findfirst返回的是long型; long __cdecl _findfirst(const char *, struct _finddata_t *)  
//  if((longf = _findfirst("d:\\*.*", &file))==-1l)  
//  {  
//      cout<<"文件没有找到!\n";  
//  }  
//  else  
//  {  
//      cout<<"\n文件列表:\n";  
//      //int __cdecl _findnext(long, struct _finddata_t *);如果找到下个文件的名字成功的话就返回0,否则返回-1  
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
//                cout<<"  普通文件  ";  
//            }  
//            else if(file.attrib == _A_RDONLY)  
//            {  
//                cout<<"  只读文件  ";  
//            }  
//            else if(file.attrib == _A_HIDDEN )  
//            {  
//                cout<<"  隐藏文件  ";  
//            }  
//            else if(file.attrib == _A_SYSTEM )  
//            {  
//                cout<<"  系统文件  ";  
//            }  
//            else if(file.attrib == _A_SUBDIR)  
//            {  
//                cout<<"  子目录  ";  
//            }  
//            else   
//            {  
//                cout<<"  存档文件  ";  
//            }  
//            cout<<endl;  
//        }  
//    }  
//    _findclose(longf);  
//}  
