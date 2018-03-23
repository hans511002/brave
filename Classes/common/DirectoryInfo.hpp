// ==============================================================
//progame      Common::Path  Directory  DirectoryInfo
//company      hans
//copyright    Copyright (c) hans  2007-4     2008-06
//version      1.0
//Author       hans
//date         2007-4     2008-06
//description  FileSystem with Directory access
//				This library is free software. Permission to use, copy,
//				modify and redistribute it for any purpose is hereby granted
//				without fee, provided that the above copyright notice appear
//				in all copies.
// ==============================================================
#ifndef __Common_DirectoryInfo__
#define __Common_DirectoryInfo__

//#include "Common.h"
namespace Common
{
	class DirectoryInfo;
	class FileInfo;
	///	<summary>
	///	�԰����ļ���Ŀ¼·����Ϣ��<see cref='String'/>ʵ��ִ�в�������Щ�������Կ�ƽ̨�ķ�ʽִ�еġ�
	///	</summary>
	///	<remarks>
	///	<code></code>
	///	</remarks>
    /// <example><code>
    /// </code></example>
	class Path
	{
		//static const char InvalidFileNameChars[];
		//static const char RealInvalidPathChars[];
		Path();
	public:
		// Fields
		static const char DirectorySeparatorChar;
		static const char  * const InvalidPathChars;
		static const char  * const InvalidFileNameChars;
		static const int MAX_DIRECTORY_PATH = 0xf8;
		static const char VolumeSeparatorChar;	// : 
		static const int MaxPath;

	public :
		static String formatPath(String &path)
		{
			if(path.Trim()=="")return path;
#if OSTYPE>10
			path=path.ReplaceAll("\\",String(DirectorySeparatorChar));
#else
			path=path.ReplaceAll("/",String(DirectorySeparatorChar));
#endif
			path=path.ReplaceAll(String(DirectorySeparatorChar)+String(DirectorySeparatorChar),String(DirectorySeparatorChar));
			return path;
		};

		// ժҪ:
		//     ����·���ַ�������չ����
		//
		// ����:
		//   extension:
		//     �µ���չ��������ǰ����㣩��ָ��null�Դ� path �Ƴ�������չ����
		//
		//   path:
		//     Ҫ�޸ĵ�·����Ϣ����·�����ܰ����� System.IO.Path.InvalidPathChars �ж�����κ��ַ���
		//
		// ���ؽ��:
		//     �����޸ĵ�·����Ϣ���ַ������ڻ��� Windows ������ƽ̨�ϣ���� path ��null ����ַ��� ("")���򷵻ص�·����Ϣ��δ�޸ĵġ����
		//     extension ��null���򷵻ص��ַ�������ָ����·��������չ�����Ƴ������ path ��������չ�������� extension ����null���򷵻ص�·���ַ�������
		//     extension����׷�ӵ� path �Ľ�β��
		//	public static string ChangeExtension(string path, string extension);
		static String ChangeExtension(String path, String extension)
		{
			if (path.empty() || extension.empty())
			{
				return path;
			}
			CheckInvalidPathChars(path);
			String str = path;
			int length = path.size();
			while (--length >= 0)
			{
				char ch = path[length];
				if (ch == '.')
				{
					str = path.SubString(0, length);
					break;
				}
				if ((ch == DirectorySeparatorChar) 
#if OSTYPE<=10
					|| (ch == VolumeSeparatorChar)
#endif
					)
				{
					break;
				}
			}
			if (extension[0] != '.')
			{
				str = str + ".";
			}
			return (str + extension);
		};
		//��֤����
		inline static void CheckInvalidPathChars(String path)
		{
			formatPath(path);
			const char * tmp=Path::InvalidPathChars;
			while(*tmp)
			{
				if(path.IndexOf(*tmp)>=0)
					EXP("Argument_InvalidPathChars");
				tmp++;
			}
		};
		//��֤����
		inline static void CheckInvalidFileNameChars(String fileName)
		{
			int len=fileName.size();
			const char * tmp=Path::InvalidFileNameChars;
			while(*tmp)
			{
				if(fileName.IndexOf(*tmp)>=0)
					EXP("Argument_InvalidFileNameChars");
				tmp++;
			}
		};
		//
		// ժҪ:
		//     �ϲ�����·���ַ�����
		//
		// ����:
		//   path2:
		//     �ڶ���·����
		//
		//   path1:
		//     ��һ��·����
		//
		// ���ؽ��:
		//     �����ϲ���·�����ַ��������ָ����·��֮һ���㳤���ַ�������÷�����������·������� path2 ��������·������÷������� path2��
		inline static String Combine(String path1, String path2)
		{
			CheckInvalidPathChars(path1);
			CheckInvalidPathChars(path2);
			if (path2.size() == 0)
			{
				return path1;
			}
			if (path1.size() == 0)
			{
				return path2;
			}
			if (IsPathRooted(path2))
			{
				return path2;
			}
			char ch = path1.at(path1.size() - 1);
			if (ch != DirectorySeparatorChar)
			{
				return (path1 + DirectorySeparatorChar + path2);
			}
			return (path1 + path2);
		};

		//
		// ժҪ:
		//     ����ָ��·���ַ�����Ŀ¼��Ϣ��
		//
		// ����:
		//   path:
		//     �ļ���Ŀ¼��·����
		//
		// ���ؽ��:
		//     ���� path Ŀ¼��Ϣ�� �ַ���������Ϊ�գ���� path ��ʾ��Ŀ¼���ǿ��ַ��� ("") ����null������� path
		//     û�а���Ŀ¼��Ϣ���򷵻� ���ַ���
		inline static String GetDirectoryName(String path)
		{
			if (!path.empty())
			{
				CheckInvalidPathChars(path);
				path = GetFullPath(path,false);
				int rootLength = GetRootLength(path);
				if (path.size() > rootLength)
				{
					int length = path.size();
					while (((length > rootLength) && (path[--length] != DirectorySeparatorChar)) )
					{
					}
					return path.SubString(0, length+1);
				}
				return "";
			}
			return "";
		};
		inline static String GetDirectoryName(String path,char splitChar)
		{
			if (!path.empty())
			{
				CheckInvalidPathChars(path);
				path = GetFullPath(path,false);
				int rootLength = GetRootLength(path);
				if (path.size() > rootLength)
				{
					int length = path.size();
					while (((length > rootLength) && (path[--length] != splitChar)) )
					{
					}
					return path.SubString(0, length+1);
				}
				return "";
			}
			return "";
		};
		//
		// ժҪ:
		//     ����ָ����·���ַ�������չ����
		//
		// ����:
		//   path:
		//     �����ȡ��չ����·���ַ�����
		//
		// ���ؽ��:
		//     ����ָ��·������չ����������.������ System.String��null �� System.String.Empty����� path Ϊnull����
		//     GetExtension ����null����� path ��������չ����Ϣ���� GetExtension ���� Empty��
		inline static String GetExtension(String path)
		{
			if (path.empty())
			{
				return path;
			}
			CheckInvalidPathChars(path);
			int length = path.size();
			int startIndex = length;
			while (--startIndex >= 0)
			{
				char ch = path[startIndex];
				if (ch == '.')
				{
					if (startIndex != (length - 1))
					{
						return path.SubString(startIndex, length - startIndex);
					}
					return "";
				}
				if ((ch == DirectorySeparatorChar)
#if OSTYPE<=10
					|| (ch == VolumeSeparatorChar)
#endif
					)
				{
					break;
				}
			}
			return "";
		};
		//
		// ժҪ:
		//     ����ָ��·���ַ������ļ�������չ����
		//
		// ����:
		//   path:
		//     �����ȡ�ļ�������չ����·���ַ�����
		//
		// ���ؽ��:
		//     һ�� System.String���� path ������Ŀ¼�ַ�����ַ���ɡ���� path �����һ���ַ���Ŀ¼���ָ�������˷������� System.String.Empty�����
		//     path Ϊnull����˷�������null��
		//	public static string GetFileName(string path);
		inline static String GetFileName(String path)
		{
			if (!path.empty())
			{
				CheckInvalidPathChars(path);
				int length = path.size();
				int num2 = length;
				while (--num2 >= 0)
				{
					char ch = path[num2];
					if ((ch == DirectorySeparatorChar)
#if OSTYPE<=10
					|| (ch == VolumeSeparatorChar)
#endif
					)
					{
						return path.SubString(num2 + 1, (length - num2) - 1);
					}
				}
			}
			return path;
		};
		inline static String GetFileName(String path,char splitChar)
		{
			if (!path.empty())
			{
				CheckInvalidPathChars(path);
				int length = path.size();
				int num2 = length;
				while (--num2 >= 0)
				{
					char ch = path[num2];
					if (ch == splitChar)
					{
						return path.SubString(num2 + 1, (length - num2) - 1);
					}
				}
			}
			return path;
		};
		//
		// ժҪ:
		//     ���ز�������չ����ָ��·���ַ������ļ�����
		//
		// ����:
		//   path:
		//     �ļ���·����
		//
		// ���ؽ��:
		//     ������ System.IO.Path.GetFileName(System.String) ���ص��ַ����� System.String�������������ľ��
		//     (.) �͸þ���������ַ���
		//	public static string GetFileNameWithoutExtension(string path);
		inline static String GetFileNameWithoutExtension(String path)
		{
			path = GetFileName(path);
			if (path.empty())
			{
				return "";
			}
			int length = path.LastIndexOf('.');
			if (length == -1)
			{
				return path;
			}
			return path.SubString(0, length);
		};
		//
		// ժҪ:
		//     ����ָ��·���ַ����ľ���·����
		//
		// ����:
		//   path:
		//     ҪΪ���ȡ����·����Ϣ���ļ���Ŀ¼
		//
		// ���ؽ��:
		//     ���� path ����ȫ�޶�λ�õ��ַ��������硰C:\MyFile.txt����
		//	public static string GetFullPath(string path);
		inline static String GetFullPath(String path,bool isDir=false)
		{
			return GetFullPathInternal(path,isDir);
		};
		//
		// ժҪ:
		//     ��ȡ�������������ļ�����ʹ�õ��ַ������顣
		//
		// ���ؽ��:
		//     �������������ļ�����ʹ�õ��ַ������顣
		//	public static char[] GetInvalidFileNameChars();
		inline static const char * GetInvalidFileNameChars(int &len)
		{
			return Path::InvalidFileNameChars;
		};
		//
		// ժҪ:
		//     ��ȡ������������·������ʹ�õ��ַ������顣
		//
		// ���ؽ��:
		//     ������������·������ʹ�õ��ַ������顣
		//	public static char[] GetInvalidPathChars();
		inline static const char * GetInvalidPathChars(int &len)
		{
			return Path::InvalidPathChars;
		};
		//
		// ժҪ:
		//     ��ȡָ��·���ĸ�Ŀ¼��Ϣ��
		//
		// ����:
		//   path:
		//     �����ȡ��Ŀ¼��Ϣ��·����
		//
		// ���ؽ��:
		//     һ������ path �ĸ�Ŀ¼���ַ��������硰C:\����������� path Ϊnull����Ϊnull��������� path ��������Ŀ¼��Ϣ����Ϊ���ַ�����
		//	public static string GetPathRoot(string path);
		inline static String GetPathRoot(String path)
		{
			if (path.empty())
			{
				return path;
			}
			path = GetFullPath(path);
			return path.SubString(0, GetRootLength(path));
		};
		//
		// ժҪ:
		//     ȷ��·���Ƿ�����ļ���չ����
		//
		// ����:
		//   path:
		//     ����������չ����·����
		//
		// ���ؽ��:
		//     ���·��������Ŀ¼�ָ�����\\ �� /�����ָ��� (:) ֮����ַ�������� (.)�����Һ������һ�������ַ�����Ϊ true������Ϊ false��
		//	public static bool HasExtension(string path);
		inline static bool HasExtension(String path)
		{
			if (path.empty())
			{
				CheckInvalidPathChars(path);
				int length = path.size();
				while (--length >= 0)
				{
					char ch = path[length];
					if (ch == '.')
					{
						return (length != (path.size() - 1));
					}
					if ((ch == DirectorySeparatorChar)
#if OSTYPE<=10
					|| (ch == VolumeSeparatorChar)
#endif
					)
					{
						break;
					}
				}
			}
			return false;
		};
		//�ϲ�����·��, path2��Ϊ��,Ҳ��Ϊ��·��
		inline static String InternalCombine(String path1, String path2)
		{
			if (path2.empty())
			{
				EXP("path2  is NULL");
			}
			CheckInvalidPathChars(path1);
			CheckInvalidPathChars(path2);
			if (IsPathRooted(path2))
			{
				EXP("path2 is Rooted");
			}
			int length = path1.size();
			if (length == 0)
			{
				return path2;
			}
			char ch = path1[length - 1];
			if ((ch != DirectorySeparatorChar)
#if OSTYPE<=10
			&& (ch != VolumeSeparatorChar)
#endif
			)
			{
				return (path1 + DirectorySeparatorChar + path2);
			}
			return (path1 + path2);
		};
		//
		// ժҪ:
		//     ��ȡһ��ֵ����ֵָʾָ����·���ַ����ǰ�������·����Ϣ���ǰ������·����Ϣ��
		//
		// ����:
		//   path:
		//     Ҫ���Ե�·����
		//
		// ���ؽ��:
		//     ��� path ��������·������Ϊ true������Ϊ false��
		inline static bool IsPathRooted(const String &path)
		{
			if (path.size() != 0)
			{
				CheckInvalidPathChars(path);
				int length = path.size();
				if ((length >= 1 && path.at(0) == Path::DirectorySeparatorChar)
#if OSTYPE<=10
				|| ((length >= 2) && (path.at(1) == Path::VolumeSeparatorChar))
#endif
				)
				{
					return true;
				}
			}
			return false;
		};
		//��Ŀ¼����
		inline static int GetRootLength(String path)
		{
			CheckInvalidPathChars(path);
			int num = 0;
			int length = path.size();
			if ((length >= 1) && IsDirectorySeparator(path[0]))
			{
				num = 1;
				if ((length >= 2) && IsDirectorySeparator(path[1]))
				{
					num = 2;
					int num3 = 2;
					while ((num < length) && (((path[num] != DirectorySeparatorChar)) || (--num3 > 0)))
					{
						num++;
					}
				}
				return num;
			}
#if OSTYPE<=10
			if ((length >= 2) && (path[1] == VolumeSeparatorChar)
				)
			{
				num = 2;
				if ((length >= 3) && IsDirectorySeparator(path[2]))
				{
					num++;
				}
			}
#endif
			return num;
		};
		//�Ƿ�Ŀ¼�ָ���
		inline static bool IsDirectorySeparator(char c)
		{
			return (c != DirectorySeparatorChar);
		};
		inline static void SafeSetStackPointerValue(char* buffer, int index, char value)
		{
			if (index >= MaxPath)
			{
				EXP("IO.PathTooLong");
			}
			buffer[index] = value;
		};
		//
		// ժҪ:
		//     ��������ļ��������ļ�����
		//
		// ���ؽ��:
		//     ����ļ��������ļ�����
		//	public static string GetRandomFileName();
		static String GetRandomFileName()
		{
			return "Random"+DateTime().ToString()+rand();
		};
		//
		// ժҪ:
		//     ����������Ψһ���������ֽڵ���ʱ�ļ������ظ��ļ�������·����
		//
		// ���ؽ��:
		//     ������ʱ�ļ�������·���� System.String��
		//	public static string GetTempFileName();
		//��ȡ��ʱ�ļ���
		static String GetTempFileName()
		{
			String tempPath = GetTempPath();
			String tmpFileName;
#if OSTYPE>10 
			char templates[]="template-XXXXXX";
			int fd=mkstemp(templates);
			if(fd==NULL)
				return "";
			else
				close(fd);
			tmpFileName=tempPath+templates;
#else
			tmpFileName=GetRandomFileName();
			tmpFileName=tempPath + tmpFileName;
			FILE * fp=fopen(tmpFileName.c_str(),"wb");
			if(fp==NULL)
				return "";
			else
				fclose(fp);
#endif
			return tmpFileName;
		};
		//
		// ժҪ:
		//     ���ص�ǰϵͳ����ʱ�ļ��е�·������ȡ��ʱ�ļ�·��,��������ڻ������� TEMP TMP ��Ĭ��Ϊ��ǰ����Ŀ¼
		//
		// ���ؽ��:
		//     ������ʱĿ¼��·����Ϣ�� System.String��
		//	public static string GetTempPath();
		static String GetTempPath()
		{
			String path=getEnv("TEMP");
			if(path=="")path=getEnv("TMP");
			return GetFullPathInternal(path,true);
		};

		//��ѯģʽ��֤
		inline static void CheckSearchPattern(String & searchPattern);
		//����Ŀ¼,���ض��ַ���β
		inline static String GetDemandDir(String &path)
		{    
			Path::formatPath(path);
			if (!path.EndsWith(Path::DirectorySeparatorChar))
			{
				return path+= Path::DirectorySeparatorChar;
			}
			return path;
		};
		//��ȡȫ·��ʵ����
		static String GetFullPathInternal(String path,bool isDir=false)
		{
			if(path=="")return "";
#if OSTYPE>10
			path=path.ReplaceAll("\\",String(DirectorySeparatorChar));
#else
			path=path.ReplaceAll("/",String(DirectorySeparatorChar));
#endif
			path=path.ReplaceAll(String(DirectorySeparatorChar)+String(DirectorySeparatorChar),String(DirectorySeparatorChar));
			char * buf=new char[Path::MaxPath+1];
			char * tmp=getcwd(buf,MaxPath);
			if(tmp==NULL){delete[] buf;return "";}
			String curDir=tmp;
			delete[] buf;
			if(curDir[curDir.size()-1] != DirectorySeparatorChar)
				curDir += DirectorySeparatorChar;
			if(path.empty())return curDir;
			if(IsPathRooted(path))
			{
#if OSTYPE<=10
				if(path.at(0) == Path::DirectorySeparatorChar)
				{
					path=curDir.SubString(0,GetRootLength(path)-1)+path;
				}
#endif
				return path;
			}
			//���ת������
			if(path.StartsWith(".."))
			{
				char * dest1[50];
				char * dest2[50];
				char * src1=new char[Path::MaxPath+1];
				char * src2=new char[Path::MaxPath+1];
				memset(dest1,0,50*sizeof(char *));
				memset(src1,0,MaxPath+1 );
				memset(dest2,0,50*sizeof(char *));
				memset(src2,0,MaxPath+1 );
				strcpy(src1,curDir.c_str());
				strcpy(src2,path.c_str());
				int len1=String::Split(dest1,src1,DirectorySeparatorChar);
				int len2=String::Split(dest2,src2,DirectorySeparatorChar);
				int index=0;
				len1--;
				while(dest2[index] && strcmp(dest2[index],"..")==0)
				{
					len1--;
					index++;
					if(index>=len2-1)break;
					if(len1<=0)break;
				}
				if(len1>0 && index<len2)
				{
					String tmp;
					for(int i=0;i<len1;i++)
					{
						tmp+=dest1[i]+String(DirectorySeparatorChar);
					}
					for(int i=index;i<len2;i++)
					{
						if(i==len2-1)
							tmp+=dest2[i];
						else
							tmp+=dest2[i]+String(DirectorySeparatorChar);
					}
					path=tmp;
				}
				else if(index==len2 && len1==0)
				{
					path=curDir.SubString(0,GetRootLength(path));
				}
				else if(len1==0)
				{
					while(strcmp(dest2[index],"..")==0)
					{
						index++;
					}
					if(index==len2)
					{
						path=curDir.SubString(0,GetRootLength(path));
					}
					else
					{
						String tmp=curDir.SubString(0,GetRootLength(path));;
						for(int i=index;i<len2;i++)
						{
							if(i==len2-1)
								tmp+=dest2[i];
							else
								tmp+=dest2[i]+String(DirectorySeparatorChar);
						}
						path=tmp;
					}
				}
				else if(index==len2)
				{
					String tmp;
					for(int i=0;i<len1;i++)
					{
						tmp+=dest1[i]+String(DirectorySeparatorChar);
					}
					path=tmp;
				}
				delete[] src1;
				delete[] src2;
			}
			else
			{
				path=curDir+path;
			}
			if(isDir)GetDemandDir(path);
			return path;
		};
	};
	//rename  unlink,  access  chmod  mktemp
	///	<summary>
	///	�������ڴ������ƶ���ö��ͨ��Ŀ¼����Ŀ¼�ľ�̬������
	///	</summary>
	///	<remarks>
	///	<code></code>
	///	</remarks>
    /// <example><code>
    /// </code></example>
	class Directory
	{
		friend class DirectoryInfo;
	public:

		// ժҪ:
		//     �� path ��ָ����������Ŀ¼����Ŀ¼.
		//
		// ����:
		//   path:
		//     Ҫ������Ŀ¼·����
		//
		// ���ؽ��:
		//     �� path ָ���� System.IO.DirectoryInfo��
		static DirectoryInfo CreateDirectory(String path);

		static bool CreateDir(String path,int mode=777)
		{
			if(!Exists(path))
			{
				Path::formatPath(path);
				if (path.empty() || path=="")
				{
					return false;
				}
		#if OSTYPE>10
				String cmd;
				if(path.IndexOf(' ')>0)
				{
					cmd=("mkdir -p -m  \""+path+"\"");
				}
				else
				{
					cmd=("mkdir -p -m "+String(mode)+" \""+path+"\"");
				}
				if(system(cmd.c_str())!=0)
				{
					printf("Ŀ¼����ʧ��:%s\n",path.c_str());
					return false;
				}
		#else
				if(system(("mkdir \""+path+"\"").c_str())!=0)
				{
					printf("Ŀ¼����ʧ��:%s\n",path.c_str());
					return false;
				}
		#endif
			}
			return true;
		};
		//
		// ժҪ:
		//     ɾ��ָ����Ŀ¼�������ָʾ��ɾ����Ŀ¼�е��κ���Ŀ¼��
		//
		// ����:
		//   recursive:
		//     ��Ҫ�Ƴ� path �е�Ŀ¼����Ŀ¼���ļ�����Ϊ true������Ϊ false��
		//
		//   path:
		//     Ҫ�Ƴ���Ŀ¼�����ơ�
		//	public static void Delete(string path, bool recursive);
		inline static void Delete(String path,bool recursive=false)
		{
			Path::formatPath(path);
			if(recursive)
			{
	#if OSTYPE>10
			system(("rm -rf \""+path+"\"").c_str());
	#else
			system(("rmdir /s /q \""+path+"\"").c_str());
	#endif
			}
			else
			{
				rmdir(path.c_str());
			}
		};		//
		// ժҪ:
		//     ȷ������·���Ƿ����ô����ϵ�����Ŀ¼��
		//
		// ����:
		//   path:
		//     Ҫ���Ե�·����
		//
		// ���ؽ��:
		//     ��� path ��������Ŀ¼����Ϊ true������Ϊ false��
		//	public static bool Exists(string path);
		inline static bool Exists(String path)
		{
			Path::formatPath(path);
			char * buf=new char[Path::MaxPath+1];
			char * tmp=getcwd(buf,Path::MaxPath);
			if(tmp==NULL){delete[] buf;return false;}
			String curDir=tmp;
			delete[] buf;
			if(curDir[curDir.size()-1] != Path::DirectorySeparatorChar)
				curDir += Path::DirectorySeparatorChar;
			int indi=chdir(path.c_str());
			chdir(curDir.c_str());
			return (indi==0);
		};
		inline static bool Mkdir(String path,int mode=777)
		{
			if(Exists(path)==true)return true;;
#if OSTYPE>10
			int indi= mkdir(path.c_str(),mode);
#else
			int indi= mkdir(path.c_str());
#endif
			return (indi==0);
		}
 
		//
		// ժҪ:
		//     ���ļ���Ŀ¼���������Ƶ���λ�á�
		//
		// ����:
		//   sourceDirName:
		//     Ҫ�ƶ����ļ���Ŀ¼��·����
		//
		//   destDirName:
		//     ָ�� sourceDirName ����λ�õ�·����
		inline static bool Move(String sourceDirName, String destDirName,bool isConvered=false)
		{
			sourceDirName = Path::GetFullPath(sourceDirName);
			destDirName = Path::GetFullPath(destDirName);
			if(Exists(sourceDirName)==false)return false;
			if(isConvered==false && Exists(destDirName)==true)return false;
	#if OSTYPE>10
			if(isConvered)
				return system(("mv -f \""+sourceDirName+"\" \""+destDirName+"\"").c_str())==0;
			else
				return system(("mv \""+sourceDirName+"\" \""+destDirName+"\"").c_str())==0;
	#else
			if(isConvered)
				return system(("move /-y \""+sourceDirName+"\" \""+destDirName+"\"").c_str())==0;
			else
				return system(("move /y \""+sourceDirName+"\" \""+destDirName+"\"").c_str())==0;
	#endif
		};
		//
		// ժҪ:
		//     ��ȡӦ�ó���ĵ�ǰ����Ŀ¼��
		//
		// ���ؽ��:
		//     ������ǰ����Ŀ¼��·�����ַ�����
		inline static String GetCurrentDirectory()
		{
			char * buf=new char[Path::MaxPath+1];
			char * tmp=getcwd(buf,Path::MaxPath);
			if(tmp==NULL){delete[] buf;return "";}
			String curDir=tmp;
			delete[] buf;
			return curDir;
		};
		//
		// ժҪ:
		//     ��ȡĿ¼�Ĵ������ں�ʱ�䡣
		//
		// ����:
		//   path:
		//     Ŀ¼��·����
		//
		// ���ؽ��:
		//     һ�� System.DateTime �ṹ��������Ϊָ��Ŀ¼�Ĵ������ں�ʱ�䡣��ֵ�ñ���ʱ���ʾ��
		inline static DateTime GetCreationTime(String path)
		{
			Path::formatPath(path);
			struct stat buf;
			if(stat(path.c_str(),&buf))
				return DateTime::MinValue;
			return DateTime((unsigned int)buf.st_ctime);
		};
		//
		// ժҪ:
		//     ��ȡĿ¼���������ں�ʱ�䣬���ʽΪЭ��ͨ��ʱ�� (UTC)��
		//
		// ����:
		//   path:
		//     Ŀ¼��·����
		//
		// ���ؽ��:
		//     һ�� System.DateTime �ṹ��������Ϊָ��Ŀ¼�Ĵ������ں�ʱ�䡣��ֵ�� UTC ʱ���ʾ��
		inline static DateTime GetCreationTimeUtc(String path)
		{
			struct stat buf;
			if(stat(path.c_str(),&buf))
				return DateTime::MinValue;
			return DateTime((unsigned int )buf.st_ctime,GMT0);
		};
		//
		// ժҪ:
		//     �����ϴη���ָ���ļ���Ŀ¼�����ں�ʱ�䡣
		//
		// ����:
		//   path:
		//     Ҫ��ȡ��������ں�ʱ����Ϣ���ļ���Ŀ¼��
		//
		// ���ؽ��:
		//     һ�� System.DateTime �ṹ��������Ϊ�ϴη���ָ���ļ���Ŀ¼�����ں�ʱ�䡣��ֵ�ñ���ʱ���ʾ��
		inline static DateTime GetLastAccessTime(String path)
		{
			struct stat buf;
			if(stat(path.c_str(),&buf))
				return DateTime::MinValue;
			return DateTime((unsigned int)buf.st_atime);
		};
		//
		// ժҪ:
		//     �����ϴη���ָ���ļ���Ŀ¼�����ں�ʱ�䣬���ʽΪЭ��ͨ��ʱ�� (UTC)��
		//
		// ����:
		//   path:
		//     Ҫ��ȡ��������ں�ʱ����Ϣ���ļ���Ŀ¼��
		//
		// ���ؽ��:
		//     һ�� System.DateTime �ṹ��������Ϊ�ϴη���ָ���ļ���Ŀ¼�����ں�ʱ�䡣��ֵ�� UTC ʱ���ʾ��
		inline static DateTime GetLastAccessTimeUtc(String path)
		{
			struct stat buf;
			if(stat(path.c_str(),&buf))
				return DateTime::MinValue;
			return DateTime((unsigned int )buf.st_atime,GMT0);
		};
		//
		// ժҪ:
		//     �����ϴ�д��ָ���ļ���Ŀ¼�����ں�ʱ�䡣
		//
		// ����:
		//   path:
		//     Ҫ��ȡ���޸����ں�ʱ����Ϣ���ļ���Ŀ¼��
		//
		// ���ؽ��:
		//     һ�� System.DateTime �ṹ��������Ϊ�ϴ�д��ָ���ļ���Ŀ¼�����ں�ʱ�䡣��ֵ�ñ���ʱ���ʾ��
		inline static DateTime GetLastWriteTime(String path)
		{
			struct stat buf;
			if(stat(path.c_str(),&buf))
				return DateTime::MinValue;
			return DateTime((unsigned int)buf.st_mtime);
		};
		//
		// ժҪ:
		//     �����ϴ�д��ָ���ļ���Ŀ¼�����ں�ʱ�䣬���ʽΪЭ��ͨ��ʱ�� (UTC)��
		//
		// ����:
		//   path:
		//     Ҫ��ȡ���޸����ں�ʱ����Ϣ���ļ���Ŀ¼��
		//
		// ���ؽ��:
		//     һ�� System.DateTime �ṹ��������Ϊ�ϴ�д��ָ���ļ���Ŀ¼�����ں�ʱ�䡣��ֵ�� UTC ʱ���ʾ��
		inline static DateTime GetLastWriteTimeUtc(String path)
		{
			struct stat buf;
			if(stat(path.c_str(),&buf))
				return DateTime::MinValue;
			return DateTime((unsigned int )buf.st_mtime,GMT0);
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
		inline static DirectoryInfo GetParent(String path);
		//
		// ժҪ:
		//     ����ָ��·���ľ���Ϣ������Ϣ������ͬʱ���ء�
		//
		// ����:
		//   path:
		//     �ļ���Ŀ¼��·����
		//
		// ���ؽ��:
		//     ����ָ��·���ľ���Ϣ������Ϣ��ͬʱ���������ߵ��ַ�����
		static String GetDirectoryRoot(String path){return Path::GetPathRoot(path);};
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
		inline static Array<String> GetDirectories(String path, String searchPattern="",bool ignoreCase=false, SearchOption searchOption=TopDirectoryOnly){return InternalGetFileDirectoryNames(path,false,true, searchPattern,ignoreCase,searchOption);};
		//
		// ժҪ:
		//     ����ָ��Ŀ¼���ļ������ƣ���Ŀ¼��ָ������ģʽƥ�䲢ʹ��ĳ��ֵȷ���Ƿ�����Ŀ¼��������
		//
		// ����:
		//   searchOption:
		//     System.IO.SearchOption ֵ֮һ��ָ����������Ӧ����������Ŀ¼���ǽ�������ǰĿ¼��
		//
		//   path:
		//     Ҫ������Ŀ¼��
		//
		//   searchPattern:
		//     Ҫ�� path �е��ļ���ƥ��������ַ������˲���������������㣨��..���������������� System.IO.Path.DirectorySeparatorChar
		//     �� System.IO.Path.AltDirectorySeparatorChar ��ǰ�����������㣨��..������Ҳ���ܰ��� System.IO.Path.InvalidPathChars
		//     �е��κ��ַ���
		//
		// ���ؽ��:
		//     һ�� String ���飬������ָ��Ŀ¼����ָ������ģʽƥ����ļ������ơ��ļ�����������·����
		inline static Array<String> GetFiles(String path, String searchPattern="",bool ignoreCase=false, SearchOption searchOption=TopDirectoryOnly){return InternalGetFileDirectoryNames(path,true,false, searchPattern,ignoreCase,searchOption);};

		//�����ļ���Ŀ¼�Ĵ���ʱ��
		//inline static void SetCreationTime(String path, DateTime creationTime);
		//�����ϴη���ָ���ļ���Ŀ¼��ʱ��
		inline static void SetLastAccessTime(String path, DateTime lastAccessTime)
		{
			struct stat buf;
			if(stat(path.c_str(),&buf))
				return ;
			utimbuf ut;
			ut.actime=(time_t)lastAccessTime.getUtcSec();
			ut.modtime=buf.st_atime;
			utime(path.c_str(),&ut);
		};
		//�����ϴ�д��ָ���ļ���Ŀ¼��ʱ��
		inline static void SetLastWriteTime(String path, DateTime lastWriteTime)
		{
			struct stat buf;
			if(stat(path.c_str(),&buf))
				return ;
			utimbuf ut;
			ut.modtime=(time_t)lastWriteTime.getUtcSec();
			ut.actime=buf.st_mtime;
			utime(path.c_str(),&ut);
		};

	protected: 
		inline static Array<String> InternalGetFileDirectoryNames(String path,bool includeFiles, bool includeDirs,String searchPattern,bool ignoreCase,SearchOption searchOption)
		{
			Array<String> res;
			InternalGetFileDirectoryNames(res,path,includeFiles, includeDirs,searchPattern,ignoreCase,searchOption);
			return res;
		};
		//��ȡ���ļ���Ŀ¼�б�ʵ����
		static void InternalGetFileDirectoryNames(Array<String> &res,String path,bool includeFiles, bool includeDirs,String searchPattern,bool ignoreCase,SearchOption searchOption);
		//
		// ժҪ:
		//     �����˼�����ϸ�ʽΪ��<��������>:\�����߼������������ơ�
		//
		// ���ؽ��:
		//     �˼�����ϵ��߼���������
		//static string[] GetLogicalDrives();
	};
	///	<summary>
	///	��ʾһ��Ŀ¼������Ϣ��
	///	</summary>
	///	<remarks>
	///	<code></code>
	///	</remarks>
    /// <example><code>
    /// </code></example>
	class DirectoryInfo
	{
		String dirPath;
	public:
		DirectoryInfo(){};
		DirectoryInfo(String path){dirPath=Path::GetFullPath(path,true);};
		void setFileName(String path){dirPath=Path::GetFullPath(path,true);};
		//����Ŀ¼
		void Create(){Directory::CreateDirectory(dirPath);};
		//������Ŀ¼
		DirectoryInfo CreateSubdirectory(String path)
		{
			path=Path::Combine(dirPath, path);
			Directory::CreateDirectory(path);
			return DirectoryInfo(path);
		};
		//ɾ��Ŀ¼
		inline void Delete(bool recursive=false){Directory::Delete(dirPath,recursive);};
		//�ƶ�Ŀ¼
		void MoveTo(String destDirName,bool isConvered=false){Directory::Move(dirPath, destDirName,isConvered);};
		//�ж�Ŀ¼�Ƿ��Ѿ�����
		bool Exists(){return Directory::Exists(dirPath);};
		//��ȡ��Ŀ¼
		DirectoryInfo getRoot(){String temp=Path::GetPathRoot(dirPath);return DirectoryInfo(temp);};
		//��ȡ�ϼ�Ŀ¼
		DirectoryInfo getParent(){String temp=dirPath.SubString(0,dirPath.LastIndexOf(Path::DirectorySeparatorChar));return DirectoryInfo(temp.SubString(0,temp.LastIndexOf(Path::DirectorySeparatorChar)));};
		//��ȡĿ¼����
		String getName(){String temp=dirPath.SubString(0,dirPath.LastIndexOf(Path::DirectorySeparatorChar));return temp.SubString(temp.LastIndexOf(Path::DirectorySeparatorChar)+1);};
		//��ȡĿ¼ȫ·������
		String getFullName(){return dirPath;};

		inline Array<String> GetDirectories(String searchPattern="",bool ignoreCase=false, SearchOption searchOption=TopDirectoryOnly)
		{
			return Directory::InternalGetFileDirectoryNames(dirPath,false,true, searchPattern,ignoreCase,searchOption);
		};
		inline Array<String> GetFiles(String searchPattern="",bool ignoreCase=false, SearchOption searchOption=TopDirectoryOnly)
		{
			return Directory::InternalGetFileDirectoryNames(dirPath,true,false, searchPattern,ignoreCase,searchOption);
		};

		//��ȡ��Ŀ¼�б�
		Array<DirectoryInfo> GetDirectoryInfos(String searchPattern="",bool ignoreCase=false, SearchOption searchOption=TopDirectoryOnly);
		//��ȡ�ļ��б�
		Array<FileInfo> GetFileInfos(String searchPattern="",bool ignoreCase=false, SearchOption searchOption=TopDirectoryOnly);
		//����ʱ��
		//void SetCreationTime(String path, DateTime creationTime);
		//void SetCreationTimeUtc(String path, DateTime creationTimeUtc);
		inline void SetLastAccessTime(String path, DateTime lastAccessTime){Directory::SetLastAccessTime(path,lastAccessTime);};
		inline void SetLastAccessTimeUtc(String path, DateTime lastAccessTimeUtc){Directory::SetLastAccessTime(path,lastAccessTimeUtc);};
		inline void SetLastWriteTime(String path, DateTime lastWriteTime){Directory::SetLastWriteTime(path,lastWriteTime);};
		inline void SetLastWriteTimeUtc(String path, DateTime lastWriteTimeUtc){Directory::SetLastWriteTime(path,lastWriteTimeUtc);};
	};
}
#endif
