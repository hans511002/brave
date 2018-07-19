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
    string FileUtil::getFilePath(string fileName)
    {
        if(fileName[0]=='/'){
            return fileName;
        }
        FileUtils * fu = cocos2d::FileUtils::getInstance();
        const std::vector<std::string>& spath = fu->getSearchPaths();
        for (int i = 0; i < spath.size(); i++)
	    {
			const string &sp = spath.at(i);
			if (sp[sp.size() - 1] == '/')
				_npath = spath.at(i) + fileName;
			else
				_npath = spath.at(i) + "/" + fileName;
             if(fu->isFileExist(_npath))
            {
				 return _npath;
			}
		}
		return  fu->getWritablePath() + fileName;
    };



    int FileUtil::writeFile(string fileName,string cnt)
    {
        //写到文件
        std::string strPath = FileUtils::getInstance()->getWritablePath() + fileName;
        FILE* myFile = fopen(strPath.c_str(), "wb");
        if (myFile) {
            fputs(cnt, myFile);
            fclose(myFile);
            return 0;
        }
        return -1;
    }
    
    static int readFile(rapidjson::Document * doc,string jsonFile);
    { 
        rapidjson::Document &newDoc=*doc;
        FILE* myFile = fopen(jsonFile.c_str(), "rb");   
        if (myFile) {
            rapidjson::FileStream inputStream(myFile);  //创建一个输入流
            newDoc.ParseStream<0>(inputStream); //将读取的内容转换为dom元素
            fclose(myFile); //关闭文件，很重要
        }
        if (newDoc.HasParseError()) {
            //log("Json Parse error:%d", newDoc.GetParseError()); //打印错误编号
            return newDoc.GetParseError();
        }
        return 0;
    }
}


