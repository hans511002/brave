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
			string fileName=getFileName(file);
			if (fileName == "." || fileName == "..") {
				continue;
			}
			file=fs->fullPathForFilename(file);
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

    string FileUtil::getFileDir(string path){
        FileUtils * fs = cocos2d::FileUtils::getInstance();
        //fs->filen
        if(!path.empty())
        {
            int length = path.size();
            int num2 = length;
            char ch = path[num2-1];
            if ((ch == '/' || ch == '\\'))
            {
                length--;
                num2--;
            }
            while(--num2 >= 0)
            {
                ch = path[num2];
                if((ch == '/' || ch == '\\'))
                {
                    // return path.substr(num2 + 1);
                    return path.substr(0,num2 );
                }
            }
        }
        return path;
    }
    string FileUtil::getFileName(string path)
    {
        if(!path.empty())
        { 
            int length = path.size();
            int num2 = length;
			char ch = path[num2-1];
			if ((ch == '/' || ch == '\\'))
			{
				length--;
				num2--;
			}
            while(--num2 >= 0)
            {
                ch = path[num2];
                if((ch == '/' || ch == '\\'))
                {
					// return path.substr(num2 + 1);
                    return path.substr(num2 + 1, (length - num2) - 1);
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
        std::string defPath=fu->getDefaultResourceRootPath();
        const std::vector<std::string>& spath = fu->getSearchPaths();
        for (int i = 0; i < spath.size(); i++)
	    {
			const string &sp = spath.at(i);
			string _npath;
			if (sp[sp.size() - 1] == '/')
				_npath = sp + fileName;
			else
				_npath = sp + "/" + fileName;
             if(fu->isFileExist(_npath))
            {
				 return fu->fullPathForFilename(_npath);
			}
		}
		return  fu->getWritablePath() + fileName;
    };



        //写到文件
    int FileUtil::writeFile(string fileName,string cnt)
    {
        FileUtils * fs = cocos2d::FileUtils::getInstance();
            std::string strPath =fileName;
        if(fileName != fs->fullPathForFilename(fileName)){
            strPath = fs->getWritablePath() + fileName;
        }
        string dir=getFileDir(strPath);
        bool ok=true;
        // Check whether dir can be created
        if(!fs->isDirectoryExist(dir)){
            ok = fs->createDirectory(dir);
        }
        if (ok && fs->isDirectoryExist(dir)){
            FILE* myFile = fopen(strPath.c_str(), "wb");
            if (myFile) {
                fputs(cnt.c_str(), myFile);
                fclose(myFile);
                return 0;
            }
        } 
        return -1;
    } 

    int FileUtil::writeData(string fileName,string writeDataStr)
    {
        Data writeData;
        FileUtils * fs = cocos2d::FileUtils::getInstance();
        writeData.copy((unsigned char *)writeDataStr.c_str(), writeDataStr.size());
        std::string fullPath =fs->getWritablePath() + fileName;
        return  !FileUtils::getInstance()->writeDataToFile(writeData, fullPath );
    }
//unsigned short FileUtil::File_Open(FILE_HANDLE** FileHandle, char* name,
//        unsigned short flag, unsigned short mode) {
// 
//    if (FileHandle == NULL) {
//        return 100;
//    }
//    if (name == NULL) {
//        return 100;
//    }
//    char type[128] = "";
// 
//    if (flag == FO_OREAD) {
//        if (mode != FO_CREATE) {
//            strcpy(type, "r"); //只读，不建文件
//        } else {
//            strcpy(type, "r+");
//        }
//    } else if (flag == FO_OWRITE) {
//        if (mode != FO_CREATE) {
//            strcpy(type, "w"); //只写，不建文件
//        } else {
//            strcpy(type, "w+");
//        }
//    } else if (flag == FO_RW) {
//        if (mode != FO_CREATE) {
//            strcpy(type, "a");
//        } else {
//            strcpy(type, "a+");
//        }
//    } else if (flag == FO_APPEND) {
//        if (mode != FO_CREATE) {
//            strcpy(type, "a");
//        } else {
//            strcpy(type, "a+");
//        }
//    }
// 
//    *FileHandle = fopen(name, type);
//    return 0;
//}
// 
///**
// * File_Close--关闭文件
// * 返回值
// * 0--关闭成功;否则失败
// */
//unsigned short FileUtil::File_Close(FILE_HANDLE* FileHandle) {
//    if (FileHandle == NULL) {
//        return 100;
//    }
//    return fclose(FileHandle);
//}
// 
///**
// * File_GetSize--得到文件长度
// * FileSize--返回文件长度
// */
//unsigned short FileUtil::File_GetSize(FILE_HANDLE* FileHandle, unsigned long* FileSize) {
//    if (FileHandle == NULL) {
//        return 100;
//    }
//    fseek(FileHandle, 0L, SEEK_END);
//    *FileSize = ftell(FileHandle);
//    return 0;
//}
// 
///**
// * File_Read--读取文件到buf
// * count--读取的长度
// * ReadCount--返回已读取的长度
// */
//unsigned short FileUtil::File_Read(FILE_HANDLE* FileHandle, char* buf,
//        unsigned long count, unsigned long* ReadCount) {
//    if (FileHandle == NULL) {
//        return 100;
//    }
//    *ReadCount = fread(buf, 1, count, FileHandle);
//    __android_log_print(ANDROID_LOG_INFO, "JNIMsg",
//            "File_Read           ReadCount=%d", *ReadCount);
//    return 0;
//}
// 
///**
// * File_Write--从buf中写入文件
// * count--写入的长度
// * WriteCount--返回已写入的长度
// */
//unsigned short FileUtil::File_Write(FILE_HANDLE* FileHandle, char* buf,
//        unsigned long count, unsigned long* WriteCount) {
//    if (FileHandle == NULL) {
//        return 100;
//    }
//    unsigned short write_result = fwrite(buf, count, 1, FileHandle); // 返回值是成功写入的项目数
//    if(write_result == 1) {
//        *WriteCount = write_result * count;
//    }
//    return write_result;
//}
// 
///**
// * File_Seek--给文件偏移量
// * offset--偏移量
// * origin--偏移方向
// * SeekLen--返回已偏移的长度
// * 返回值0--成功,其他失败
// */
//unsigned short FileUtil::File_Seek(FILE_HANDLE* FileHandle, long offset, short origin,
//        unsigned long* SeekLen) {
//    unsigned short seek_result = fseek(FileHandle, offset, origin);
//    if(seek_result == 0) {
//        *SeekLen = offset;
//    }
//    return seek_result;
//}
// 
///**
// * File_Delete--删除文件
// * 0--删除成功  -1--删除失败
// */
//unsigned short FileUtil::File_Delete(char* name) {
//    if (name == NULL) {
//        return 100;
//    }
//    return remove(name);
//}
// 
///**
// * File_ISExist--判断文件是否存在
// * 0存在  -1不存在
// */
//unsigned short FileUtil::File_ISExist(char* path) {
//    if (path == NULL) {
//        return 100;
//    }
//    return access(path, 0);
//}
// 
///**
// * File_Create_Dir--创建文件目录
// * 返回0--成功
// */
//unsigned short FileUtil::File_Create_Dir(char* dirName) {
//    if (dirName == NULL) {
//        return 100;
//    }
//    return mkdir(dirName, S_IRWXU);
//}
// 
///**
// * File_Delete_Dir--删除文件目录
// */
//unsigned short FileUtil::File_Delete_Dir(char* dirName) {
//    if (dirName == NULL) {
//        return 100;
//    }
//    DIR* dp = NULL;
//    DIR* dpin = NULL;
//    char *pathname = (char*) malloc(256);
//    memset(pathname, 0, 256);
//    struct dirent* dirp;
//    dp = opendir(dirName);
//    if (dp == NULL) {
//        __android_log_print(ANDROID_LOG_INFO, "JNIMsg",
//                "File_Delete_Dir      your input directory is not exist!");
//        return 100;
//    }
//    while ((dirp = readdir(dp)) != NULL) {
//        if (strcmp(dirp->d_name, "..") == 0 || strcmp(dirp->d_name, ".") == 0)
//            continue;
//        strcpy(pathname, dirName);
//        strcat(pathname, "/");
//        strcat(pathname, dirp->d_name);
//        dpin = opendir(pathname);
//        if (dpin != NULL) {
//            closedir(dpin);
//            dpin = NULL;
//            File_Delete_Dir(pathname);
//        } else {
//            remove(pathname);
//        }
//    }
//    rmdir(dirName);
//    closedir(dp);
//    free(pathname);
//    pathname = NULL;
//    dirp = NULL;
// 
//    return 0;
//}
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

//
////测试方法sayHello
//jstring Java_com_scan_file_MainActivity_sayHello(JNIEnv* env, jobject thiz) {
//    //打印信息出来
//    __android_log_print(ANDROID_LOG_INFO, "JNIMsg", "SayHello");
//    return (*env)->NewStringUTF(env, "Hello from JNI ! sayHello");
//}
//
////执行C底层方法
//jstring Java_com_scan_file_MainActivity_doCMethod(JNIEnv* env, jobject thiz) {
//    //打印信息出来
//    __android_log_print(ANDROID_LOG_INFO, "JNIMsg", "doCMethod");
//
//    SyncmlStart();
//
//    return (*env)->NewStringUTF(env, "Do C Method OK!");
//}


//void ANativeActivity_onCreate(ANativeActivity* app, void*, size_t) {
//    const jclass contextClass = app->env->GetObjectClass(app->clazz);
//    const jmethodID getApplicationContextMethod =app->env->GetMethodID(contextClass, "getApplicationContext", "()Landroid/content/Context;");
//    const jobject contextObject =app->env->CallObjectMethod(app->clazz, getApplicationContextMethod);
//    const jmethodID getApplicationInfoMethod = app->env->GetMethodID(contextClass, "getApplicationInfo", "()Landroid/content/pm/ApplicationInfo;");
//    const jobject applicationInfoObject =app->env->CallObjectMethod(contextObject, getApplicationInfoMethod);
//    const jfieldID nativeLibraryDirField = app->env->GetFieldID(app->env->GetObjectClass(applicationInfoObject), "nativeLibraryDir", "Ljava/lang/String;");
//    const jobject nativeLibraryDirObject =app->env->GetObjectField(applicationInfoObject, nativeLibraryDirField);
//    const jmethodID getBytesMethod = app->env->GetMethodID(app->env->GetObjectClass(nativeLibraryDirObject), "getBytes", "(Ljava/lang/String;)[B");
//    const auto bytesObject = static_cast<jbyteArray>(app->env->CallObjectMethod(nativeLibraryDirObject, getBytesMethod, app->env->NewStringUTF("UTF-8")));
//    const size_t length = app->env->GetArrayLength(bytesObject);
//    const jbyte* const bytes = app->env->GetByteArrayElements(bytesObject, nullptr);
//    const std::string libDir(reinterpret_cast<const char*>(bytes), length);
//    }