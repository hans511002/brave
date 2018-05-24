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
	///	对包含文件或目录路径信息的<see cref='String'/>实例执行操作。这些操作是以跨平台的方式执行的。
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

		// 摘要:
		//     更改路径字符串的扩展名。
		//
		// 参数:
		//   extension:
		//     新的扩展名（具有前导句点）。指定null以从 path 移除现有扩展名。
		//
		//   path:
		//     要修改的路径信息。该路径不能包含在 System.IO.Path.InvalidPathChars 中定义的任何字符。
		//
		// 返回结果:
		//     包含修改的路径信息的字符串。在基于 Windows 的桌面平台上，如果 path 是null 或空字符串 ("")，则返回的路径信息是未修改的。如果
		//     extension 是null，则返回的字符串包含指定的路径，其扩展名已移除。如果 path 不具有扩展名，并且 extension 不是null，则返回的路径字符串包含
		//     extension，它追加到 path 的结尾。
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
		//验证名称
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
		//验证名称
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
		// 摘要:
		//     合并两个路径字符串。
		//
		// 参数:
		//   path2:
		//     第二个路径。
		//
		//   path1:
		//     第一个路径。
		//
		// 返回结果:
		//     包含合并的路径的字符串。如果指定的路径之一是零长度字符串，则该方法返回其他路径。如果 path2 包含绝对路径，则该方法返回 path2。
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
		// 摘要:
		//     返回指定路径字符串的目录信息。
		//
		// 参数:
		//   path:
		//     文件或目录的路径。
		//
		// 返回结果:
		//     包含 path 目录信息的 字符串；或者为空（如果 path 表示根目录、是空字符串 ("") 或是null）。如果 path
		//     没有包含目录信息，则返回 空字符。
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
		// 摘要:
		//     返回指定的路径字符串的扩展名。
		//
		// 参数:
		//   path:
		//     从其获取扩展名的路径字符串。
		//
		// 返回结果:
		//     包含指定路径的扩展名（包括“.”）的 System.String、null 或 System.String.Empty。如果 path 为null，则
		//     GetExtension 返回null。如果 path 不具有扩展名信息，则 GetExtension 返回 Empty。
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
		// 摘要:
		//     返回指定路径字符串的文件名和扩展名。
		//
		// 参数:
		//   path:
		//     从其获取文件名和扩展名的路径字符串。
		//
		// 返回结果:
		//     一个 System.String，由 path 中最后的目录字符后的字符组成。如果 path 的最后一个字符是目录或卷分隔符，则此方法返回 System.String.Empty。如果
		//     path 为null，则此方法返回null。
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
		// 摘要:
		//     返回不具有扩展名的指定路径字符串的文件名。
		//
		// 参数:
		//   path:
		//     文件的路径。
		//
		// 返回结果:
		//     包含由 System.IO.Path.GetFileName(System.String) 返回的字符串的 System.String，但不包括最后的句点
		//     (.) 和该句点后的所有字符。
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
		// 摘要:
		//     返回指定路径字符串的绝对路径。
		//
		// 参数:
		//   path:
		//     要为其获取绝对路径信息的文件或目录
		//
		// 返回结果:
		//     包含 path 的完全限定位置的字符串，例如“C:\MyFile.txt”。
		//	public static string GetFullPath(string path);
		inline static String GetFullPath(String path,bool isDir=false)
		{
			return GetFullPathInternal(path,isDir);
		};
		//
		// 摘要:
		//     获取包含不允许在文件名中使用的字符的数组。
		//
		// 返回结果:
		//     包含不允许在文件名中使用的字符的数组。
		//	public static char[] GetInvalidFileNameChars();
		inline static const char * GetInvalidFileNameChars(int &len)
		{
			return Path::InvalidFileNameChars;
		};
		//
		// 摘要:
		//     获取包含不允许在路径名中使用的字符的数组。
		//
		// 返回结果:
		//     包含不允许在路径名中使用的字符的数组。
		//	public static char[] GetInvalidPathChars();
		inline static const char * GetInvalidPathChars(int &len)
		{
			return Path::InvalidPathChars;
		};
		//
		// 摘要:
		//     获取指定路径的根目录信息。
		//
		// 参数:
		//   path:
		//     从其获取根目录信息的路径。
		//
		// 返回结果:
		//     一个包含 path 的根目录的字符串，例如“C:\”；或者如果 path 为null，则为null；或者如果 path 不包含根目录信息，则为空字符串。
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
		// 摘要:
		//     确定路径是否包括文件扩展名。
		//
		// 参数:
		//   path:
		//     用于搜索扩展名的路径。
		//
		// 返回结果:
		//     如果路径中最后的目录分隔符（\\ 或 /）或卷分隔符 (:) 之后的字符包括句点 (.)，并且后面跟有一个或多个字符，则为 true；否则为 false。
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
		//合并二个路径, path2不为空,也不为根路径
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
		// 摘要:
		//     获取一个值，该值指示指定的路径字符串是包含绝对路径信息还是包含相对路径信息。
		//
		// 参数:
		//   path:
		//     要测试的路径。
		//
		// 返回结果:
		//     如果 path 包含绝对路径，则为 true；否则为 false。
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
		//根目录长度
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
		//是否目录分隔符
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
		// 摘要:
		//     返回随机文件夹名或文件名。
		//
		// 返回结果:
		//     随机文件夹名或文件名。
		//	public static string GetRandomFileName();
		static String GetRandomFileName()
		{
			return "Random"+DateTime().ToString()+rand();
		};
		//
		// 摘要:
		//     创建磁盘上唯一命名的零字节的临时文件并返回该文件的完整路径。
		//
		// 返回结果:
		//     包含临时文件的完整路径的 System.String。
		//	public static string GetTempFileName();
		//获取临时文件名
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
		// 摘要:
		//     返回当前系统的临时文件夹的路径。获取临时文件路径,如果不存在环境变量 TEMP TMP 则默认为当前工作目录
		//
		// 返回结果:
		//     包含临时目录的路径信息的 System.String。
		//	public static string GetTempPath();
		static String GetTempPath()
		{
			String path=getEnv("TEMP");
			if(path=="")path=getEnv("TMP");
			return GetFullPathInternal(path,true);
		};

		//查询模式验证
		inline static void CheckSearchPattern(String & searchPattern);
		//返回目录,以特定字符结尾
		inline static String GetDemandDir(String &path)
		{    
			Path::formatPath(path);
			if (!path.EndsWith(Path::DirectorySeparatorChar))
			{
				return path+= Path::DirectorySeparatorChar;
			}
			return path;
		};
		//获取全路径实现体
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
			//相对转换绝对
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
	///	公开用于创建、移动和枚举通过目录和子目录的静态方法。
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

		// 摘要:
		//     按 path 的指定创建所有目录和子目录.
		//
		// 参数:
		//   path:
		//     要创建的目录路径。
		//
		// 返回结果:
		//     由 path 指定的 System.IO.DirectoryInfo。
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
					printf("目录创建失败:%s\n",path.c_str());
					return false;
				}
		#else
				if(system(("mkdir \""+path+"\"").c_str())!=0)
				{
					printf("目录创建失败:%s\n",path.c_str());
					return false;
				}
		#endif
			}
			return true;
		};
		//
		// 摘要:
		//     删除指定的目录并（如果指示）删除该目录中的任何子目录。
		//
		// 参数:
		//   recursive:
		//     若要移除 path 中的目录、子目录和文件，则为 true；否则为 false。
		//
		//   path:
		//     要移除的目录的名称。
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
		// 摘要:
		//     确定给定路径是否引用磁盘上的现有目录。
		//
		// 参数:
		//   path:
		//     要测试的路径。
		//
		// 返回结果:
		//     如果 path 引用现有目录，则为 true；否则为 false。
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
		// 摘要:
		//     将文件或目录及其内容移到新位置。
		//
		// 参数:
		//   sourceDirName:
		//     要移动的文件或目录的路径。
		//
		//   destDirName:
		//     指向 sourceDirName 的新位置的路径。
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
		// 摘要:
		//     获取应用程序的当前工作目录。
		//
		// 返回结果:
		//     包含当前工作目录的路径的字符串。
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
		// 摘要:
		//     获取目录的创建日期和时间。
		//
		// 参数:
		//   path:
		//     目录的路径。
		//
		// 返回结果:
		//     一个 System.DateTime 结构，它设置为指定目录的创建日期和时间。该值用本地时间表示。
		inline static DateTime GetCreationTime(String path)
		{
			Path::formatPath(path);
			struct stat buf;
			if(stat(path.c_str(),&buf))
				return DateTime::MinValue;
			return DateTime((unsigned int)buf.st_ctime);
		};
		//
		// 摘要:
		//     获取目录创建的日期和时间，其格式为协调通用时间 (UTC)。
		//
		// 参数:
		//   path:
		//     目录的路径。
		//
		// 返回结果:
		//     一个 System.DateTime 结构，它设置为指定目录的创建日期和时间。该值用 UTC 时间表示。
		inline static DateTime GetCreationTimeUtc(String path)
		{
			struct stat buf;
			if(stat(path.c_str(),&buf))
				return DateTime::MinValue;
			return DateTime((unsigned int )buf.st_ctime,GMT0);
		};
		//
		// 摘要:
		//     返回上次访问指定文件或目录的日期和时间。
		//
		// 参数:
		//   path:
		//     要获取其访问日期和时间信息的文件或目录。
		//
		// 返回结果:
		//     一个 System.DateTime 结构，它设置为上次访问指定文件或目录的日期和时间。该值用本地时间表示。
		inline static DateTime GetLastAccessTime(String path)
		{
			struct stat buf;
			if(stat(path.c_str(),&buf))
				return DateTime::MinValue;
			return DateTime((unsigned int)buf.st_atime);
		};
		//
		// 摘要:
		//     返回上次访问指定文件或目录的日期和时间，其格式为协调通用时间 (UTC)。
		//
		// 参数:
		//   path:
		//     要获取其访问日期和时间信息的文件或目录。
		//
		// 返回结果:
		//     一个 System.DateTime 结构，它设置为上次访问指定文件或目录的日期和时间。该值用 UTC 时间表示。
		inline static DateTime GetLastAccessTimeUtc(String path)
		{
			struct stat buf;
			if(stat(path.c_str(),&buf))
				return DateTime::MinValue;
			return DateTime((unsigned int )buf.st_atime,GMT0);
		};
		//
		// 摘要:
		//     返回上次写入指定文件或目录的日期和时间。
		//
		// 参数:
		//   path:
		//     要获取其修改日期和时间信息的文件或目录。
		//
		// 返回结果:
		//     一个 System.DateTime 结构，它设置为上次写入指定文件或目录的日期和时间。该值用本地时间表示。
		inline static DateTime GetLastWriteTime(String path)
		{
			struct stat buf;
			if(stat(path.c_str(),&buf))
				return DateTime::MinValue;
			return DateTime((unsigned int)buf.st_mtime);
		};
		//
		// 摘要:
		//     返回上次写入指定文件或目录的日期和时间，其格式为协调通用时间 (UTC)。
		//
		// 参数:
		//   path:
		//     要获取其修改日期和时间信息的文件或目录。
		//
		// 返回结果:
		//     一个 System.DateTime 结构，它设置为上次写入指定文件或目录的日期和时间。该值用 UTC 时间表示。
		inline static DateTime GetLastWriteTimeUtc(String path)
		{
			struct stat buf;
			if(stat(path.c_str(),&buf))
				return DateTime::MinValue;
			return DateTime((unsigned int )buf.st_mtime,GMT0);
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
		inline static DirectoryInfo GetParent(String path);
		//
		// 摘要:
		//     返回指定路径的卷信息、根信息或两者同时返回。
		//
		// 参数:
		//   path:
		//     文件或目录的路径。
		//
		// 返回结果:
		//     包含指定路径的卷信息、根信息或同时包括这两者的字符串。
		static String GetDirectoryRoot(String path){return Path::GetPathRoot(path);};
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
		inline static Array<String> GetDirectories(String path, String searchPattern="",bool ignoreCase=false, SearchOption searchOption=TopDirectoryOnly){return InternalGetFileDirectoryNames(path,false,true, searchPattern,ignoreCase,searchOption);};
		//
		// 摘要:
		//     返回指定目录中文件的名称，该目录与指定搜索模式匹配并使用某个值确定是否在子目录中搜索。
		//
		// 参数:
		//   searchOption:
		//     System.IO.SearchOption 值之一，指定搜索操作应包括所有子目录还是仅包括当前目录。
		//
		//   path:
		//     要搜索的目录。
		//
		//   searchPattern:
		//     要与 path 中的文件名匹配的搜索字符串。此参数不能以两个句点（“..”）结束，不能在 System.IO.Path.DirectorySeparatorChar
		//     或 System.IO.Path.AltDirectorySeparatorChar 的前面包含两个句点（“..”），也不能包含 System.IO.Path.InvalidPathChars
		//     中的任何字符。
		//
		// 返回结果:
		//     一个 String 数组，它包含指定目录中与指定搜索模式匹配的文件的名称。文件名包含完整路径。
		inline static Array<String> GetFiles(String path, String searchPattern="",bool ignoreCase=false, SearchOption searchOption=TopDirectoryOnly){return InternalGetFileDirectoryNames(path,true,false, searchPattern,ignoreCase,searchOption);};

		//设置文件或目录的创建时间
		//inline static void SetCreationTime(String path, DateTime creationTime);
		//设置上次访问指定文件或目录的时间
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
		//设置上次写入指定文件或目录的时间
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
		//获取子文件或目录列表实现体
		static void InternalGetFileDirectoryNames(Array<String> &res,String path,bool includeFiles, bool includeDirs,String searchPattern,bool ignoreCase,SearchOption searchOption);
		//
		// 摘要:
		//     检索此计算机上格式为“<驱动器号>:\”的逻辑驱动器的名称。
		//
		// 返回结果:
		//     此计算机上的逻辑驱动器。
		//static string[] GetLogicalDrives();
	};
	///	<summary>
	///	表示一个目录对象信息。
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
		//创建目录
		void Create(){Directory::CreateDirectory(dirPath);};
		//创建子目录
		DirectoryInfo CreateSubdirectory(String path)
		{
			path=Path::Combine(dirPath, path);
			Directory::CreateDirectory(path);
			return DirectoryInfo(path);
		};
		//删除目录
		inline void Delete(bool recursive=false){Directory::Delete(dirPath,recursive);};
		//移动目录
		void MoveTo(String destDirName,bool isConvered=false){Directory::Move(dirPath, destDirName,isConvered);};
		//判断目录是否已经存在
		bool Exists(){return Directory::Exists(dirPath);};
		//获取根目录
		DirectoryInfo getRoot(){String temp=Path::GetPathRoot(dirPath);return DirectoryInfo(temp);};
		//获取上级目录
		DirectoryInfo getParent(){String temp=dirPath.SubString(0,dirPath.LastIndexOf(Path::DirectorySeparatorChar));return DirectoryInfo(temp.SubString(0,temp.LastIndexOf(Path::DirectorySeparatorChar)));};
		//获取目录名称
		String getName(){String temp=dirPath.SubString(0,dirPath.LastIndexOf(Path::DirectorySeparatorChar));return temp.SubString(temp.LastIndexOf(Path::DirectorySeparatorChar)+1);};
		//获取目录全路径名称
		String getFullName(){return dirPath;};

		inline Array<String> GetDirectories(String searchPattern="",bool ignoreCase=false, SearchOption searchOption=TopDirectoryOnly)
		{
			return Directory::InternalGetFileDirectoryNames(dirPath,false,true, searchPattern,ignoreCase,searchOption);
		};
		inline Array<String> GetFiles(String searchPattern="",bool ignoreCase=false, SearchOption searchOption=TopDirectoryOnly)
		{
			return Directory::InternalGetFileDirectoryNames(dirPath,true,false, searchPattern,ignoreCase,searchOption);
		};

		//获取子目录列表
		Array<DirectoryInfo> GetDirectoryInfos(String searchPattern="",bool ignoreCase=false, SearchOption searchOption=TopDirectoryOnly);
		//获取文件列表
		Array<FileInfo> GetFileInfos(String searchPattern="",bool ignoreCase=false, SearchOption searchOption=TopDirectoryOnly);
		//设置时间
		//void SetCreationTime(String path, DateTime creationTime);
		//void SetCreationTimeUtc(String path, DateTime creationTimeUtc);
		inline void SetLastAccessTime(String path, DateTime lastAccessTime){Directory::SetLastAccessTime(path,lastAccessTime);};
		inline void SetLastAccessTimeUtc(String path, DateTime lastAccessTimeUtc){Directory::SetLastAccessTime(path,lastAccessTimeUtc);};
		inline void SetLastWriteTime(String path, DateTime lastWriteTime){Directory::SetLastWriteTime(path,lastWriteTime);};
		inline void SetLastWriteTimeUtc(String path, DateTime lastWriteTimeUtc){Directory::SetLastWriteTime(path,lastWriteTimeUtc);};
	};
}
#endif
