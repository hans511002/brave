
#ifndef STD_FILEUTIL_H
#define STD_FILEUTIL_H
#include "BaseNode.h"
#include <io.h>
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

    };

}

#endif
