// ==============================================================
//progame      Common::FileStream  File FileInfo
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
#ifndef __Common_FileInfo__
#define __Common_FileInfo__

//#include "Common.h"
namespace Common
{
#if OSTYPE>10
	//fcntl
	const static int flock_setlk=F_SETLK;
	const static int flock_getlk=F_GETLK;
	const static int flock_setlkw=F_SETLKW;
	//flock
#if SYSTYPE==2
//#  define F_RDLCK 01
//#  define F_WRLCK 02
//#  define F_UNLCK 03
	const static int flock_LOCK_SH=F_RDLCK;
	const static int flock_LOCK_EX=F_WRLCK;
	const static int flock_LOCK_UN=F_UNLCK;
	const static int flock_LOCK_NB=F_UNLCK;

	const static int flock_RDLCK=F_RDLCK;
	const static int flock_WRLCK=F_WRLCK;
	const static int flock_UNLCK=F_UNLCK;
#else
//#define	LOCK_SH		1	/* shared lock */
//#define	LOCK_EX		2	/* exclusive lock */
//#define	LOCK_NB		4	/* don't block when locking */
//#define	LOCK_UN		8	/* unlock */
	const static int flock_LOCK_SH=LOCK_SH;
	const static int flock_LOCK_EX=LOCK_EX;
	const static int flock_LOCK_UN=LOCK_UN;
	const static int flock_LOCK_NB=LOCK_NB;
	const static int flock_RDLCK=LOCK_SH;
	const static int flock_WRLCK=LOCK_EX;
	const static int flock_UNLCK=LOCK_UN;
#endif

 	//int locking(FILE * hFile, int mode, long size) {return 0;};
	//cmd���
	//F_SETFD ����close-on-exec ��ꡣ������Բ���arg ��FD_CLOEXECλ������
	//F_GETFL ȡ���ļ�������״̬��꣬�����Ϊopen�����Ĳ���flags��
	//F_SETFL �����ļ�������״̬��꣬����argΪ����꣬��ֻ����O_APPEND��O_NONBLOCK��O_ASYNCλ�ĸı䣬����λ�ĸı佫����Ӱ�졣
	//F_GETLK ȡ���ļ�������״̬��
	//F_SETLK �����ļ�������״̬����ʱflcok �ṹ��l_type ֵ������F_RDLCK��F_WRLCK��F_UNLCK������޷������������򷵻�-1���������ΪEACCES ��EAGAIN��
	//F_SETLKW F_SETLK ������ͬ�������޷���������ʱ���˵��û�һֱ�ȵ����������ɹ�Ϊֹ�����ڵȴ������Ĺ����б��ź��ж�ʱ������������-1���������ΪEINTR
	//type:
	//F_RDLCK ����һ������ȡ�õ�����
	//F_WRLCK ����һ����д���õ�����
	//F_UNLCK ɾ��֮ǰ����������
    //��ֵlock�ṹ�壬���������ļ�
    //lock.l_whence = SEEK_SET;
    //lock.l_start = 0;
    //lock.l_len = 0;
	inline int locking(FILE * hFile, int cmd, long size,int type)
	{
		int fd=fileno(hFile);
		if(type==flock_LOCK_SH || type==flock_LOCK_EX || type==flock_LOCK_UN || type==flock_LOCK_NB)
		{
			if(cmd!=flock_setlkw)
			cmd=flock_setlkw;
		}
		struct	flock llscs;
		//��ֵlock�ṹ�壬������ǰλ��ָ����С                                    
		llscs.l_whence = SEEK_SET;
		llscs.l_start = ftell(hFile);
		llscs.l_len = size;
		llscs.l_type = type;
		llscs.l_pid = getpid();
		
		return fcntl(fd,cmd,&llscs);

		//linux
		//if(size>0)
		//{
			//if(type==flock_LOCK_SH || type==flock_LOCK_EX || type==flock_LOCK_UN || type==flock_LOCK_NB)
			//{
			//	if(cmd!=flock_setlkw)
			//	cmd=flock_setlk;
			//}
		//	struct	flcok llscs;
		//	//��ֵlock�ṹ�壬������ǰλ��ָ����С                                    
		//	llscs.l_whence = SEEK_SET;
		//	llscs.l_start = ftell(hFile);
		//	llscs.l_len = size;
		//	return fcntl(fd,cmd,&llscs);
		//}
		//else
		//{
		//	if(mode==flock_setlk || mode==flock_setlkw)mode=(flock_LOCK_EX | flock_LOCK_NB);
		//	else if(cmd==flock_getlk) mode=LOCK_UN;
		//	return 0;//flock(fd,cmd);
		//}
	};

	inline int FLOCK(FILE * hFile,int cmd,int size,int type)
	{
		return locking(hFile,cmd,size,type);
	}
#define FLOCK_EXP(hFile,mode,size,type) {if(locking(hFile,mode,size,type)!=0)EXP("�����ļ���������");}
#define LOCKED_FILE(hFile,type) FLOCK(hFile,flock_setlkw,0,type)
	inline int lock_file(int fd)
	{
		struct flock lock;
		int i;
		lock.l_type=F_WRLCK;
		lock.l_whence=SEEK_SET;
		lock.l_start=0;
		lock.l_len=0;
		if((i=fcntl(fd,F_SETLKW,&lock))==-1){
			printf("lock the file failed\n");
			return -1;
		}
		return 0;
	}

	inline int unlock_file(int fd)
	{
		struct flock lock;
		int i;
		lock.l_type=F_UNLCK;
		lock.l_whence=SEEK_SET;
		lock.l_start=0;
		lock.l_len=0;
		if((i=fcntl(fd,F_SETLKW,&lock))==-1){
			printf("unlock the file failed\n");
			return -1;
		}
		return 0;
	}
#else
//#define LK_UNLCK        _LK_UNLCK   #define _LK_UNLCK       0       /* unlock the file region */
//#define LK_LOCK         _LK_LOCK    #define _LK_LOCK        1       /* lock the file region */
//#define LK_NBLCK        _LK_NBLCK   #define _LK_NBLCK       2       /* non-blocking lock */
//#define LK_RLCK         _LK_RLCK    #define _LK_RLCK        3       /* lock for writing */
//#define LK_NBRLCK       _LK_NBRLCK  #define _LK_NBRLCK      4       /* non-blocking lock for writing */
	
	const static int flock_setlk=1;
	const static int flock_getlk=2;
	const static int flock_setlkw=3;
	const static int flock_LOCK_SH=1;
	const static int flock_LOCK_EX=1;
	const static int flock_LOCK_UN=0;
	const static int flock_LOCK_NB=1;
	const static int flock_UNLCK=LK_UNLCK;
	const static int flock_RDLCK=LK_LOCK;
	const static int flock_WRLCK=LK_RLCK;

	inline int FLOCK(FILE * hFile,int cmd,int size,int type)
	{
		int fd=fileno(hFile);
		if(type)
		{
			if(cmd==flock_setlk)
				type=(type+1)&6;	//	ת�� 2 4
			else
				type=(type-1)|1;	//	ת�� 1 3
		}
		return locking(fd,type,size);
	}
#define FLOCK_EXP(hFile,mode,size,type ) {int fileNo=fileno(hFile);if(locking(fileNo,mode,size)!=0)EXP("�����ļ���������");}
#define LOCKED_FILE(hFile,type) FLOCK(hFile,flock_setlkw,-1,type)
#endif
	//int fileNo=fileno(hFile);
	//if(locking(fileNo,1,0)!=0)EXP("�����ļ�ʧ��");F_RDLCK 

	///	<summary>
	///	�ļ�������
	///	</summary>
	///	<remarks>
	///	<code></code>
	///	</remarks>
    /// <example><code>
    /// </code></example>
	class FileStream
	{
	protected:
		FILE * _file;
	public:
		FileStream(FILE * file=NULL){_file=file;};
		inline FILE * getFILE(){return _file;};
		inline void setFILE(FILE * file){_file=file;};
		inline int write(const void * buffer,int len)
		{
			return fwrite(buffer,1,len,_file);
		};
		inline int read(void * buffer,int len)
		{
			return fread(buffer,1,len,_file);
		};
		inline int writeLine(const char * buffer)
		{
			return fputs(buffer,_file);
		};
		inline int readLine(char * buffer,int size)
		{
			if(fgets(buffer,size-1, _file))
			{
				return 0;
			}
			return -1;
		};
		inline bool writeLine(const string &buffer)
		{
			return fputs(buffer.c_str(),_file)==0;
		};
		//��ȡһ�м�¼
		inline bool readLine(string &buffer)
		{
			char * szBuff=new char[10240];
			if(fgets(szBuff, sizeof(szBuff)-1, _file))
			{
				//int len=strlen(szBuff);
				//if(len==sizeof(szBuff)-1)cout<<"�ļ���¼�д�С�����Ѿ����� 10240 �ֽ�"<<endl;
				buffer=szBuff;
				return true;
			}
			return false;
		};
		inline string readLine(){string s,readLine(s);return s;};
		inline bool seek(long offset,SeekOrigin mode)
		{
			switch(mode)
			{
			case Begin:
				return fseek(_file,offset,SEEK_SET)==0;
				break;
			case Current:
				return fseek(_file,offset,SEEK_CUR)==0;
				break;
			case End:
				return fseek(_file,offset,SEEK_END)==0;
				break;
			}
			return true;
		};
		inline long tell()	{return ftell(_file);};
		inline bool isNill(){return _file==NULL;};
		inline long fileSize()	{long cur=ftell(_file); fseek(_file,0,SEEK_END);long size= ftell(_file);fseek(_file,cur,SEEK_SET);return size;};
		inline int flush(){if(_file==NULL)EXP("�ļ�ָ��Ϊ�գ�����ˢ�����ݵ��ļ���");return fflush(_file);};
		inline void close(){if(_file)fclose(_file);_file=NULL;};
		inline int lock(int type=flock_WRLCK)
		{
			fseek(_file,0,SEEK_SET);
			return FLOCK(_file,flock_setlkw,1,type);
		};
		inline int unlock()
		{
			fseek(_file,0,SEEK_SET);
			return FLOCK(_file,flock_setlk,1,flock_UNLCK);
		};
	};
	///	<summary>
	///	�̳�<see cref='FileStream'/>�ļ��������ṩ���ⷽ��,֧���ļ�д�������ûع���(����ģʽ)���Լ��ļ�ָ�����ͷš�
	///	</summary>
	///	<remarks>
	///	<code></code>
	///	</remarks>
    /// <example><code>
    /// </code></example>
	class subFileStream:public FileStream
	{
		map<String,long> pos;
		long position;
	public:
		subFileStream(FILE * file=NULL){this->_file=file;if(_file)position=ftell(this->_file);};
		subFileStream(FileStream fs):position(0){this->_file=fs.getFILE();if(_file)position=ftell(this->_file);};
		inline void setFILE(FILE * file){_file=file;if(_file)position=ftell(this->_file);};
		~subFileStream(){if(_file)close();};
		inline long curSize(){return ftell(this->_file);};
		int addRollbackSegment(String name)
		{
			if(pos.size()>=10)
			{
				pair<map<String,long>::iterator, bool> Insert_Pair;
				Insert_Pair=pos.insert(map<String,long>::value_type(name,ftell(this->_file)));
				if(Insert_Pair.second == false)
				{
					EXP("��ӻع���ʶʧ�ܣ���ȷ���Ƿ��Ѿ���ӹ�һ�Σ�"+name);
				}
			}
			else
			{
				EXP("��ӻع���ʶʧ�ܣ��Ѿ��������ع�����10");
			}
			return this->flush();
		};
		int rollbackSegment(String name)
		{
			map<String,long>::iterator itr= pos.find(name);
			if(itr!=pos.end())
			{
				long len=itr->second;
#if OSTYPE>10				//��ȡ�ļ�
				int fd=fileno(this->_file);
				int res=ftruncate(fd,len);
				if(res==0)
				{
					pos.erase(name);
					res= fseek(_file,len,SEEK_SET);		//	���õ�ǰλ�ã��Ȼع�����
				}
				return res;
#else
				pos.erase(name);
				return fseek(_file,len,SEEK_SET);		//	���õ�ǰλ�ã��Ȼع�����
#endif
			}
			else
			{
				EXP("�ļ��ع�ʧ�ܣ������ڴ˻ع��α�ʶ:"+name);
			}
		};
		int beginTransaction()
		{
			if(this->_file==NULL)EXP("�ļ�ָ��Ϊ�գ����ܿ�ʼ������");
			position=ftell(this->_file);
			return fflush(this->_file);
		};
		int commit()
		{
			if(this->_file)
			{
				int res=fflush(this->_file);
				if(res==0)
					this->position=ftell(this->_file);
				return res;
			}
			else
				EXP("�ļ�ָ��Ϊ�գ�����ˢ�����ݵ��ļ���");
		};
		int rollback()
		{
#if OSTYPE>10
			int fd=fileno(this->_file);
			int res=ftruncate(fd,position);
			if(res==0)
			{
				res= fseek(_file,position,SEEK_SET);		//	���õ�ǰλ�ã��Ȼع�����
			}
			return res;
#else
			return fseek(_file,position,SEEK_SET);		//	���õ�ǰλ�ã��Ȼع�����
#endif
		};
	};
	///	<summary>
	///	�������ڴ������ƶ��Ȳ����ļ��ľ�̬������
	///	</summary>
	///	<remarks>
	///	<code></code>
	///	</remarks>
    /// <example><code>
    /// </code></example>
	class File
	{
		inline static FILE * fopen(const String & path,const String & _mode,bool locked=false,int size=-1)
		{
			FILE * hFile= STDSPACE::fopen(path.c_str(),_mode.c_str());
			if(locked)
			{
				String __mode=_mode;
				int type=(__mode.IndexOf('w',true)>=0?flock_WRLCK:flock_RDLCK);
				FLOCK_EXP(hFile,flock_setlk,size,type);
			}
			return hFile;
		};
	public: 
		inline static int truncate(const String & file,long size)
		{
#if OSTYPE>10
			return truncate(file.c_str(),size);
#else
			int fileId=open(file.c_str(),O_RDWR);
			int res=chsize(fileId,size);
			close(fileId);
			return res;
#endif
			/*   O_RDONLY      ֻ��ģʽ 
        O_WRONLY      ֻдģʽ 
        O_RDWR        ��дģʽ

��/�����ļ�ʱ�����ٵ�ʹ���������������е�һ�������³�����ѡ�õģ�
        O_APPEND       ÿ��д������д���ļ���ĩβ 
        O_CREAT        ���ָ���ļ������ڣ��򴴽�����ļ� 
        O_EXCL         ���Ҫ�������ļ��Ѵ��ڣ��򷵻� -1�������޸� errno ��ֵ
        O_TRUNC        ����ļ����ڣ�������ֻд/��д��ʽ�򿪣�������ļ�ȫ������ 
        O_NOCTTY       ���·����ָ���ն��豸����Ҫ������豸���������նˡ�
        O_NONBLOCK     ���·����ָ�� FIFO/���ļ�/�ַ��ļ�������ļ��Ĵ򿪺ͺ�� I/O
                       ����Ϊ������ģʽ��nonblocking mode��
������������ͬ����ѡ�õģ���������ͬ���������
        O_DSYNC        �ȴ����� I/O �������� write���ڲ�Ӱ���ȡ��д������ݵ�
                       ǰ���£����ȴ��ļ����Ը��¡� 
        O_RSYNC        read �ȴ�����д��ͬһ�����д������ɺ��ٽ���
        O_SYNC         �ȴ����� I/O �������� write�����������ļ����Ե� I/O
*/
		};
		inline static int truncate(FILE * fp,long size)
		{
			int handle   =   fileno(fp);
#if OSTYPE>10
			return ftruncate(handle,size);
#else
			return chsize(handle,size);
#endif
		};
		inline static void AppendText(const String &path, const String & contents)
		{
			FileStream fs=OpenAppend(path);
			if(fs.getFILE()==NULL)EXP("���ļ�ʧ��:"+path);
			fs.write(contents.c_str(),contents.size());
			fs.close();
		};
		//�����ļ�
		inline static bool Copy(const String & sourceFileName, const String & destFileName, bool overwrite=false)
		{
			if(overwrite==false && File::Exists(destFileName))return false;
			FileStream rfs=OpenRead(sourceFileName);
			if(rfs.getFILE()==NULL)EXP("���ļ�ʧ��:"+sourceFileName);
			FileStream wfs=OpenWrite(destFileName);
			if(wfs.getFILE()==NULL)EXP("���ļ�ʧ��:"+destFileName);
			try
			{
				char buf[1024];
				int ilen=0;
				while((ilen=rfs.read(buf,sizeof(buf)-1))>0)
				{
					wfs.write(buf,ilen);
				}
				rfs.close();
				wfs.close();
				return true;
			}
			catch(...)
			{
				cout<<string(ERR_FILE_LINE)<<endl;
				return false;
			}
		};
		//�����ļ�
		inline static FileStream Create(const String & path,int flag=0)
		{
			if(flag==0 || Exists(path)==false)
				return OpenWrite(path);
			else
				return OpenRead(path);
		};
		//ɾ���ļ�
		inline static bool Delete(const String &path)
		{
			return remove(path.c_str())==0;
		};

		//�ж��ļ��Ƿ����
		inline static bool Exists(const String &path)
		{
			 FileStream fs=OpenRead(path);
			 if(fs.getFILE())
			 {
				 fs.close();
				 return true;
			 }
			 else
			 {
				 return false;
			 }
		};

		//�ƶ��ļ�
		inline static bool Move(String sourceFileName, String destFileName,bool isConvered=false)
		{
			sourceFileName = Path::GetFullPath(sourceFileName);
			destFileName = Path::GetFullPath(destFileName);
			if(Exists(sourceFileName)==false)return false;
			if(isConvered==false && Exists(destFileName)==true)return false;
	#if OSTYPE>10
			if(isConvered)
				return system(("mv -f \""+sourceFileName+"\" \""+destFileName+"\"").c_str())==0;
			else
				return system(("mv \""+sourceFileName+"\" \""+destFileName+"\"").c_str())==0;
	#else
			if(isConvered)
				return system(("move /-y \""+sourceFileName+"\" \""+destFileName+"\"").c_str())==0;
			else
				return system(("move /y \""+sourceFileName+"\" \""+destFileName+"\"").c_str())==0;
	#endif
		};
		//�ƶ��ļ�
		inline static bool Rename(const String & _OldFilename, const String & _NewFilename)
		{
			return rename(_OldFilename.c_str(), _NewFilename.c_str())==0;
		};
		//���ļ�
		inline static FileStream OpenFile(const String & path, const string & _mode,bool locked=false,int size=-1)
		{
			FILE * rfile=NULL;
			rfile=fopen(path,_mode,locked,size);
			return FileStream(rfile);
		};
		inline static FileStream OpenRead(const String & path,bool locked=false,int size=-1)
		{
			FILE * rfile=NULL;
			rfile=fopen(path,"rb+",locked,size);
			return FileStream(rfile);
		};
		inline static FileStream OpenWrite(const String & path,bool locked=false,int size=-1)
		{
			FILE * rfile=NULL;
			rfile=fopen(path,"wb+",locked,size);
			return FileStream(rfile);
		};
		inline static FileStream OpenAppend(const String &path,bool locked=false,int size=-1)
		{
			FILE * file=NULL;
			file=fopen(path,"ab+",locked,size);
			return FileStream(file);
		};
		inline static long getFileSize(const String & path)
		{
			FileStream fs=OpenRead(path);
			if(fs.isNill())return -1;
			long size=fs.fileSize();
			fs.close();
			return size;
		};
		//��ȡ�ַ�
		inline static char * ReadAllBytes(const String & path,int &len)
		{
			FileStream fs=OpenRead(path);
			if(fs.isNill())return NULL;
			long size=fs.fileSize();
			char * buf=new char[size+1];
			memset(buf,0,sizeof(buf));
			len=fs.read(buf,size);
			fs.close();
			if(len>0)
			return buf;
			else return NULL;
		};
		//�������ļ��������滻ָ���ļ�������
		inline static void Replace(const String & sourceFileName, const String & destinationFileName, const String & destinationBackupFileName)
		{
			if(Exists(destinationFileName) && destinationBackupFileName!="")
			{
				Rename(destinationFileName,destinationBackupFileName);
			}
			Copy(sourceFileName, destinationFileName, true);
		};
		//��ȡ�ļ�ʱ������
		inline static DateTime GetCreationTime(const String & path)
		{
			struct stat buf;
			if(stat(path.c_str(),&buf))
				return DateTime::MinValue;
			return DateTime((unsigned int)buf.st_ctime);
		};
		inline static DateTime GetCreationTimeUtc(const String & path)
		{
			struct stat buf;
			if(stat(path.c_str(),&buf))
				return DateTime::MinValue;
			return DateTime((unsigned int )buf.st_ctime,GMT0);
		};
		inline static DateTime GetLastAccessTime(const String & path)
		{
			struct stat buf;
			if(stat(path.c_str(),&buf))
				return DateTime::MinValue;
			return DateTime((unsigned int)buf.st_atime);
		};
		inline static DateTime GetLastAccessTimeUtc(const String & path)
		{
			struct stat buf;
			if(stat(path.c_str(),&buf))
				return DateTime::MinValue;
			return DateTime((unsigned int )buf.st_atime,GMT0);
		};
		inline static DateTime GetLastWriteTime(const String & path)
		{
			struct stat buf;
			if(stat(path.c_str(),&buf))
				return DateTime::MinValue;
			return DateTime((unsigned int )buf.st_mtime);
		};
		inline static DateTime GetLastWriteTimeUtc(const String & path)
		{
			struct stat buf;
			if(stat(path.c_str(),&buf))
				return DateTime::MinValue;
			return DateTime((unsigned int )buf.st_mtime,GMT0);
		};

		//��������ֵ
		inline static void SetAttributes(const String & path, FileAttributes fileAttributes);
		//��ȡ�ļ�������,��ʱ��ʵ��
		inline static FileAttributes GetAttributes(const String & path);
		//����ʱ��
//unixϵͳ ��ʹ������ touch��C���� utime    /�ı�����/aixcmds5/touch.htm#ohk350craw
//touch  -t Time ʹ��ָ��ʱ������ǵ�ǰʱ�䡣Time ������ʮ������ʽ [[CC]YY]MMDDhhmm[.SS] ָ�������У�  
//utime
		//inline static void SetCreationTime(const String & path, DateTime creationTime);
		inline static void SetLastAccessTime(const String & path, DateTime lastAccessTime)
		{
			struct stat buf;
			if(stat(path.c_str(),&buf))
				return ;
			utimbuf ut;
			ut.actime=(time_t)lastAccessTime.getUtcSec();
			ut.modtime=buf.st_atime;
			utime(path.c_str(),&ut);
		};
		inline static void SetLastWriteTime(const String & path, DateTime lastWriteTime)
		{
			struct stat buf;
			if(stat(path.c_str(),&buf))
				return ;
			utimbuf ut;
			ut.modtime=(time_t)lastWriteTime.getUtcSec();
			ut.actime=buf.st_mtime;
			utime(path.c_str(),&ut);
		};

		//�����ļ�
		inline static void Decrypt(const String &path,const String & password)
		{
			return cryptFile(path,path,password,0);
		};
		//�����ļ�
		inline static void Encrypt(const String &path,const String & password)
		{
			return cryptFile(path,path,password,1);
		};
		static void cryptFile(const String &sourceFileName, const String & destinationFileName,const String & password,int type);
	};
	///	<summary>
	///	��ʾһ���ļ�������Ϣ��
	///	</summary>
	///	<remarks>
	///	<code></code>
	///	</remarks>
    /// <example><code>
    /// </code></example>
	class FileInfo
	{
	protected: 
		String _fileName;
	public: 
		FileInfo(){};
		void setFileName(String path){_fileName=Path::GetFullPath(path,true);};
		FileInfo(String fileName)
		{
			_fileName = Path::GetFullPath(fileName);
		};
		inline int truncate(long size)
		{
			return File::truncate(_fileName,size);
		};
		//����׷��ģʽ�򿪵��ļ���
		inline FileStream AppendText(){return File::OpenAppend(_fileName);};
		//�����ļ�
		inline FileStream Create(){return File::Create(_fileName);};
		//�����ļ�
		inline FileInfo CopyTo(const String & destFileName, bool overwrite=false)
		{
			File::Copy(_fileName,destFileName, overwrite);
			return FileInfo(destFileName);
		};
		//�����ļ�
		inline void Decrypt(const String & password){File::Decrypt(_fileName,password);};
		//�����ļ�
		inline void Encrypt(const String & password){File::Encrypt(_fileName,password);};
		//ɾ���ļ�
		inline bool Delete(){return File::Delete(_fileName);};
		//�ƶ��ļ�
		inline bool MoveTo(const String &destFileName)
		{
			return File::Move(_fileName,destFileName);
		};
		//���ļ�
		inline FileStream OpenRead(){return File::OpenRead(_fileName);};
		inline FileStream OpenAppend(){return File::OpenAppend(_fileName);};
		inline FileStream OpenWrite(){return File::OpenWrite(_fileName);};
		//�滻�ļ�
		inline FileInfo Replace(String destinationFileName, String destinationBackupFileName)
		{
			File::Replace(_fileName, destinationFileName, destinationBackupFileName);
			return FileInfo(destinationFileName);
		};
	
		//�ļ���չ������
		inline String getExtension(){return Path::GetExtension(_fileName);};
		//�ļ�Ŀ¼��Ϣ
		inline DirectoryInfo getDirectory(){return DirectoryInfo(Path::GetDirectoryName(_fileName));};
		//�ļ�Ŀ¼����
		inline String getDirectoryName(){return Path::GetDirectoryName(_fileName);};
		//�ļ��Ƿ����
		inline bool Exists(){return File::Exists(_fileName);};
		//��ȡ�ļ�����
		inline long getLength(){return File::getFileSize(_fileName);};
		//��ȡ�ļ�����
		inline String getName(){return Path::GetFileName(_fileName);};
		//��ȡ�ļ�ȫ·������
		inline String getFullName(){return _fileName;};
		//��ȡ�ļ�ʱ������
		inline DateTime GetCreationTime(){return File::GetCreationTime(_fileName);};
		inline DateTime GetCreationTimeUtc(){return File::GetCreationTimeUtc(_fileName);};
		inline DateTime GetLastAccessTime(){return File::GetLastAccessTime(_fileName);};
		inline DateTime GetLastAccessTimeUtc(){return File::GetLastAccessTimeUtc(_fileName);};
		inline DateTime GetLastWriteTime(){return File::GetLastWriteTime(_fileName);};
		inline DateTime GetLastWriteTimeUtc(){return File::GetLastWriteTimeUtc(_fileName);};

		//�ļ��Ƿ�ֻ��
		bool getIsReadOnly()
		{
			FILE * hFile;
			char szBuff[1024];
			bool result=false;
#if OSTYPE>10
			hFile=POPEN(("ls -l \""+_fileName+"\"").c_str(),"r");
			if(!hFile)
				EXP("ִ��������ʾ����ʧ��");
			if(fgets(szBuff, sizeof(szBuff)-1, hFile))
			{
				//drwxrwxrwx 
				if(szBuff[1]=='r')
					result=true;
			}			
			PCLOSE(hFile);
			return result;
#else
			hFile=POPEN(("ATTRIB \""+_fileName+"\"").c_str(),"r");
			if(!hFile)
				EXP("ִ��������ʾ����ʧ��");
			if(fgets(szBuff, sizeof(szBuff)-1, hFile))
			{
				//A  SHR
				if(szBuff[5]=='R')
					result=true;
			}			
			PCLOSE(hFile);
			return result;
#endif
		};
#if OSTYPE>10
		String getFileAttr()
		{
			FILE * hFile;
			char szBuff[1024];
			hFile=POPEN(("ls -l \""+_fileName+"\"").c_str(),"r");
			if(!hFile)
				EXP("ִ��Ŀ¼�б�����ʧ��");
			String attr="";
			if(fgets(szBuff, sizeof(szBuff)-1, hFile))
			{
				szBuff[10]=0;
				attr=szBuff;
			}
			PCLOSE(hFile);
			return attr;
		};
		int getFileMode()
		{
			FILE * hFile;
			char szBuff[1024];
			hFile=POPEN(("ls -l \""+_fileName+"\"").c_str(),"r");
			if(!hFile)
				EXP("ִ��Ŀ¼�б�����ʧ��");
			int mode=0;
			if(fgets(szBuff, sizeof(szBuff)-1, hFile))
			{
				if(szBuff[1]=='r')
					mode+=400;
				if(szBuff[2]=='w')
					mode+=200;
				if(szBuff[3]=='x')
					mode+=100;
				if(szBuff[4]=='r')
					mode+=40;
				if(szBuff[5]=='w')
					mode+=20;
				if(szBuff[6]=='x')
					mode+=10;
				if(szBuff[7]=='r')
					mode+=4;
				if(szBuff[8]=='w')
					mode+=2;
				if(szBuff[9]=='x')
					mode+=1;
			}
			PCLOSE(hFile);
			return mode;
		};
#endif
		//�����ļ�ֻ��
		void setIsReadOnly(bool value)
		{
#if OSTYPE>10
			int mode=getFileMode();
			int tmp=mode % 100;
			int m=mode/100;
			switch(m)
			{
			case 0:
			case 1:
			case 4:
			case 5:
				break;
			case 2:
			case 3:
			case 6:
			case 7:
				m-=2;
				break;
			}
			if(value)
				m+=2;
			system(("chmod "+String(m)+" \""+_fileName+"\"").c_str());
#else
			if(value)
				system(("ATTRIB -r \""+_fileName+"\"").c_str());
			else
				system(("ATTRIB +r \""+_fileName+"\"").c_str());
#endif
		};

		//����ʱ��
		//void SetCreationTime(const String & path, DateTime creationTime);
		//void SetCreationTimeUtc(const String & path, DateTime creationTimeUtc);
		inline void SetLastAccessTime(const String & path, DateTime lastAccessTime){File::SetLastAccessTime(path,lastAccessTime);};
		inline void SetLastAccessTimeUtc(const String & path, DateTime lastAccessTimeUtc){File::SetLastAccessTime(path,lastAccessTimeUtc);};
		inline void SetLastWriteTime(const String & path, DateTime lastWriteTime){File::SetLastWriteTime(path,lastWriteTime);};
		inline void SetLastWriteTimeUtc(const String & path, DateTime lastWriteTimeUtc){File::SetLastWriteTime(path,lastWriteTimeUtc);};
	};
}
#endif
