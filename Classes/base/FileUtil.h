
#ifndef STD_FILEUTIL_H
#define STD_FILEUTIL_H
#include "BaseNode.h"

#include "JsonUtil.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC

#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
//#include <dirent.h> 

#elif CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include <io.h>
#elif CC_TARGET_PLATFORM == CC_PLATFORM_WP8 || CC_TARGET_PLATFORM == CC_PLATFORM_WINRT

#elif CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
//#include <dirent.h> 
#endif

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
     
    };

}

#endif
