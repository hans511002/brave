#include "FileUtil.h"
namespace std
{ 
    void FileUtil::getAllFiles(vector<string>& files, string path, bool incDir, bool incFile, bool incSubDir)
    {
        if(!incDir &&!incFile)return;
		FileUtils * fs = cocos2d::FileUtils::getInstance();
		std::vector<std::string> subs= fs->listFiles(path);
		for (int i = 0; i < subs.size(); i++)
		{
			string file = subs.at(i);
			if (fs->isDirectoryExist(file)) {
				if (incDir)
					files.push_back(file);
				if (incSubDir)
					getAllFiles(files, file, incDir, incFile, incSubDir);
			}
			else if (fs->isFileExist(file)) {
				if (incFile)
					files.push_back(file);
			}
		}


        ////文件句柄
        //long hFile = 0;
        ////文件信息
        //struct _finddata_t fileinfo;  //很少用的文件信息读取结构
        //if(path[path.length() - 1] != '/')
        //    path = path + "/";
        //string p;
        //if((hFile = _findfirst(p.assign(path).append("*").c_str(), &fileinfo)) != -1)
        //{
        //    do
        //    {
        //        if((fileinfo.attrib & _A_SUBDIR)) //比较文件类型是否是文件夹
        //        { 
        //            if(strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
        //            {
        //                if(incDir)
        //                    files.push_back(p.assign(path).append(fileinfo.name));
        //                if(incSubDir)
        //                    getAllFiles(files, p.assign(path).append(fileinfo.name), incDir, incFile, incSubDir);
        //            }
        //        }
        //        else
        //        {
        //            if(incFile)  
        //                files.push_back(p.assign(path).append(fileinfo.name));
        //        }
        //    } while(_findnext(hFile, &fileinfo) == 0);  //寻找下一个，成功返回0，否则-1
        //    _findclose(hFile);
        //}
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
			string _npath;
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



        //写到文件
    int FileUtil::writeFile(string fileName,string cnt)
    {
        std::string strPath = FileUtils::getInstance()->getWritablePath() + fileName;
        FILE* myFile = fopen(strPath.c_str(), "wb");
        if (myFile) {
            fputs(cnt.c_str(), myFile);
            fclose(myFile);
            return 0;
        }
        return -1;
    } 


	//// 删除指定文件夹内所有文件
	//JNIEXPORT void JNICALL Java_com_test_util_T_deleteFiles(JNIEnv *env, jclass obj, jstring fileFolder)
	//{
	//	const char *file_folder = (*env)->GetStringUTFChars(env, fileFolder, 0);

	//	DIR *pDir = NULL;
	//	struct dirent *dmsg;
	//	char szFileName[128];
	//	char szFolderName[128];

	//	strcpy(szFolderName, file_folder);
	//	strcat(szFolderName, "/%s");
	//	if ((pDir = opendir(file_folder)) != NULL)
	//	{
	//		// 遍历目录并删除文件
	//		while ((dmsg = readdir(pDir)) != NULL)
	//		{
	//			if (strcmp(dmsg->d_name, ".") != 0 && strcmp(dmsg->d_name, "..") != 0)
	//			{
	//				sprintf(szFileName, szFolderName, dmsg->d_name);
	//				remove(szFileName);
	//			}
	//		}
	//	}

	//	if (pDir != NULL)
	//	{
	//		closedir(pDir);
	//	}

	//	(*env)->ReleaseStringUTFChars(env, fileFolder, file_folder);
	//}
}


