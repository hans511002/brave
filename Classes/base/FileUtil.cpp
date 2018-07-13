#include "FileUtil.h"
namespace std
{ 
    void FileUtil::getAllFiles(vector<string>& files, string path, bool incDir, bool incFile, bool incSubDir)
    {
        if(!incDir &&!incFile)return;
        //文件句柄
        long hFile = 0;
        //文件信息
        struct _finddata_t fileinfo;  //很少用的文件信息读取结构
        if(path[path.length() - 1] != '/')
            path = path + "/";
        string p;
        if((hFile = _findfirst(p.assign(path).append("*").c_str(), &fileinfo)) != -1)
        {
            do
            {
                if((fileinfo.attrib & _A_SUBDIR)) //比较文件类型是否是文件夹
                { 
                    if(strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                    {
                        if(incDir)
                            files.push_back(p.assign(path).append(fileinfo.name));
                        if(incSubDir)
                            getAllFiles(files, p.assign(path).append(fileinfo.name), incDir, incFile, incSubDir);
                    }
                }
                else
                {
                    if(incFile)  
                        files.push_back(p.assign(path).append(fileinfo.name));
                }
            } while(_findnext(hFile, &fileinfo) == 0);  //寻找下一个，成功返回0，否则-1
            _findclose(hFile);
        }
    }

    string FileUtil::getFileName(string path)
    {
        if(!path.empty())
        { 
            int length = path.size();
            int num2 = length;
            while(--num2 >= 0)
            {
                char ch = path[num2];
                if((ch == '/' || ch == '\\'))
                {
                    return path.substr(num2 + 1);
                    //return path.substr(num2 + 1, (length - num2) - 1);
                }
            }
        }
        return path;
    };
}


