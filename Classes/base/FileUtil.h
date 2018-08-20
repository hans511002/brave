
#ifndef STD_FILEUTIL_H
#define STD_FILEUTIL_H
#include "BaseNode.h"
#include "JsonUtil.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC

#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include <dirent.h> 
#include <unistd.h>
#include <jni.h> 
#include <assert.h> 
#include <android/asset_manager.h> 
#include <android/asset_manager_jni.h> 
 
#elif CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include <io.h>
#elif CC_TARGET_PLATFORM == CC_PLATFORM_WP8 || CC_TARGET_PLATFORM == CC_PLATFORM_WINRT

#elif CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
//#include <dirent.h> 
#endif
#define FILE_HANDLE FILE

namespace std
{
    class FileUtil
    {
    public:
        static void getAllFiles(vector<string>& files, string path, bool incDir = true, bool incFile = true, bool incSubDir = false);
        static string getFileName(string path);
        inline static vector<string> getAllFiles(string path, bool incDir = true, bool incFile = true, bool incSubDir = false)
        {
            vector<string> files;
            getAllFiles(files, path, incDir, incFile, incSubDir);
            return files;
        };
        static string getFilePath(string fileName);
        static int writeFile(string fileName,string cnt);
        static string getFileDir(string path);
        static int writeData(string fileName,string writeDataStr);

       //unsigned short File_Open(FILE_HANDLE** FileHandle, char* name, unsigned short flag,unsigned short mode);
       // 
       //unsigned short File_Close(FILE_HANDLE* FileHandle);
       // 
       //unsigned short File_GetSize(FILE_HANDLE* FileHandle, unsigned long* FileSize);
       // 
       //unsigned short File_Read(FILE_HANDLE* FileHandle, char* buf, unsigned long count,unsigned long* ReadCount);
       // 
       //unsigned short File_Write(FILE_HANDLE* FileHandle, char* buf, unsigned long count,unsigned long* WriteCount);
       // 
       //unsigned short File_Seek(FILE_HANDLE* FileHandle, long offset, short origin,unsigned long* SeekLen);
       // 
       //unsigned short File_Delete(char* name);
       // 
       //unsigned short File_ISExist(char* path);
       // 
       //unsigned short File_Create_Dir(char* dirName);
       // 
       //unsigned short File_Delete_Dir(char* dirName);     
    };

}

#endif
