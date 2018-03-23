// ==============================================================
//progame      Common::strCoding
//company      hans
//copyright    Copyright (c) hans  2007-4     2011-07
//version      1.0
//Author       hans
//date         2007-4     2011-07
//description  Common namespace
//				This library is free software. Permission to use, copy,
//				modify and redistribute it for any purpose is hereby granted
//				without fee, provided that the above copyright notice appear
//				in all copies.
// ==============================================================
#include "Common.h"

namespace Common
{
	strCoding::GB2312DATA strCoding::gb2312Map[94*94] ;		//	GB2312DATA��unicode �� UTF8ӳ��
	short int strCoding::UnicodeMap[65536] ;		//	GB2312DATA��unicode �� UTF8ӳ��
	bool strCoding::inited=false;

	void strCoding::init(char * file)
	{
		if(inited)return;
		if(file==NULL)
		{
			inited=true;
			for(int i=0;i<gb2312CharsCount;i++)
			{
				const char * data=gb2312Chars[i];
				if(data==0 || data[0]==0)return;
				int index=((unsigned char)data[5]-161)*94+(unsigned char)data[6]-161;
				if(index>=94*94){EXP("����GB2312DATA����������Χ");};
				GB2312DATA &gb=gb2312Map[index];
				gb.qw[0]=StrToBin(data);
				gb.qw[1]=StrToBin(data+2);
				gb.gb[0]=StrToBin(data+8);
				gb.gb[1]=StrToBin(data+10);
#ifdef WIN32
 				gb.uni[1]=StrToBin(data+13);
				gb.uni[0]=StrToBin(data+15);
#else
				gb.uni[0]=StrToBin(data+13);
				gb.uni[1]=StrToBin(data+15);
#endif
 				gb.utf8[0]=StrToBin(data+18);
				gb.utf8[1]=StrToBin(data+20);
				gb.utf8[2]=StrToBin(data+22);
				int ui=0;
				ui=gb.uni[0]*256+gb.uni[1];
				UnicodeMap[ui]=index;
			}
		}
		else
		{
			FILE * fp=fopen(file,"rb");
			if(fp==NULL)EXP("��GB2312����ӳ�������ļ�ʧ��,�ļ���"+String(file)+"��");
			char data[256];
			while(fgets(data,256,fp))
			{
				if(strlen(data)>=24)
				{
					int index=((unsigned char)data[5]-161)*94+(unsigned char)data[6]-161;
					if(index>=94*94){EXP("����GB2312DATA����������Χ");};
					GB2312DATA &gb=gb2312Map[index];
					gb.qw[0]=StrToBin(data);
					gb.qw[1]=StrToBin(data+2);
					gb.gb[0]=StrToBin(data+8);
					gb.gb[1]=StrToBin(data+10);
#ifdef WIN32
 					gb.uni[1]=StrToBin(data+13);
					gb.uni[0]=StrToBin(data+15);
#else
					gb.uni[0]=StrToBin(data+13);
					gb.uni[1]=StrToBin(data+15);
#endif
					gb.utf8[0]=StrToBin(data+18);
					gb.utf8[1]=StrToBin(data+20);
					gb.utf8[2]=StrToBin(data+22);
					int ui=0;
					ui=gb.uni[0]*256+gb.uni[1];
					UnicodeMap[ui]=index;
				}
			}
		}
	};

	bool strCoding::isGBCode(char * strIn)
	{
		unsigned char ch1;
		unsigned char ch2;
		if (strlen(strIn) >= 2)
		{
			ch1 = (unsigned char)strIn[0];
			ch2 = (unsigned char)strIn[1];
			if (ch1>=176 && ch1<=247 && ch2>=160 && ch2<=254)
				return true;
			else return false;
		}
		else return false;
	};
	//2���ж��Ƿ���GBK����
	bool strCoding::isGBKCode(char * strIn)
	{
		unsigned char ch1;
		unsigned char ch2;
		if (strlen(strIn)  >= 2)
		{
			ch1 = (unsigned char)strIn[0];
			ch2 = (unsigned char)strIn[1];
			if (ch1>=129 && ch1<=254 && ch2>=64 && ch2<=254)
				return true;
			else return false;
		}
		else return false;
	}
	//3���ж�BIG5
	bool strCoding::isBIG5Code(char * strIn)
	{
		unsigned char ch1;
		unsigned char ch2;
		if (strlen(strIn) >= 2)
		{
			ch1 = (unsigned char)strIn[0];
			ch2 = (unsigned char)strIn[1];
			if (ch1>=0xA0 && ch1<=0xFE && ((ch2>=0x40 && ch2<=0x7E) || (ch2>=0xA1 && ch2<=0xFE)))
				return true;
			else return false;
		}
		else return false;
	};
	void strCoding::__GB2312ToUnicode(char * pOut,char *data)
	{
		if(!inited)init();
		if(isGBCode(data))
		{
			int index=((unsigned char)data[0]-161)*94+(unsigned char)data[1]-161;
			GB2312DATA &gb=gb2312Map[index];
			pOut[0]=gb.uni[0];
			pOut[1]=gb.uni[1];
		}
	};
	void strCoding::__UnicodeToGB2312(char* pOut,char * data)
	{
		if(!inited)init();
		GB2312DATA &gb2=gb2312Map[UnicodeMap[(unsigned char)data[0]*256+(unsigned char)data[1]]];
		pOut[0]=gb2.gb[0];
		pOut[1]=gb2.gb[1];
	};
	void strCoding::__UTF8ToUnicode(char* pOut,char *data)
	{
		unsigned char* uchar = (unsigned char *)pOut;
		unsigned char* pText = (unsigned char *)data;
#ifdef WIN32
		uchar[1] = ((pText[0] & 0x0F) << 4) + ((pText[1] >> 2) & 0x0F);
		uchar[0] = ((pText[1] & 0x03) << 6) + (pText[2] & 0x3F);
#else
		uchar[0] = ((pText[0] & 0x0F) << 4) + ((pText[1] >> 2) & 0x0F);
		uchar[1] = ((pText[1] & 0x03) << 6) + (pText[2] & 0x3F);
#endif
	}
	void strCoding::__UnicodeToUTF8(char* pOut,char* pText)
	{
		char* pchar = (char *)pText;		// ע�� WCHAR�ߵ��ֵ�˳��,���ֽ���ǰ�����ֽ��ں�
#ifdef WIN32
		pOut[0] = (0xE0 | ((pchar[1] & 0xF0) >> 4));
		pOut[1] = (0x80 | ((pchar[1] & 0x0F) << 2)) + ((pchar[0] & 0xC0) >> 6);
		pOut[2] = (0x80 | (pchar[0] & 0x3F));
#else
		pOut[0] = (0xE0 | ((pchar[0] & 0xF0) >> 4));
		pOut[1] = (0x80 | ((pchar[0] & 0x0F) << 2)) + ((pchar[1] & 0xC0) >> 6);
		pOut[2] = (0x80 | (pchar[1] & 0x3F));
#endif
		return;
	}
	void strCoding::__GB2312ToUTF8(char *pOut,char *data)
	{
		if(!inited)init();
		if(isGBCode(data))
		{
			int index=((unsigned char)data[0]-161)*94+(unsigned char)data[1]-161;
			GB2312DATA &gb=gb2312Map[index];
			pOut[0]=gb.utf8[0];
			pOut[1]=gb.utf8[1];
			pOut[2]=gb.utf8[2];
		}
	};
	void strCoding::__UTF8ToGB2312(char *pOut,char *uData)
	{
		if(!inited)init();
		__UTF8ToUnicode(pOut,uData);
		__UnicodeToGB2312(pOut,pOut);
	};
	//�ַ�ת������
	char strCoding::CharToInt(char ch)
	{
		if(ch>='0' && ch<='9')return (char)(ch-'0');
		if(ch>='a' && ch<='f')return (char)(ch-'a'+10);
		if(ch>='A' && ch<='F')return (char)(ch-'A'+10);
		return -1;
	}
	//16�����ַ�ת�����ַ�
	char strCoding::StrToBin(const char *str)
	{
		char tempWord[2];
		char chn;
		tempWord[0] = CharToInt(str[0]);                         //make the B to 11 -- 00001011
		tempWord[1] = CharToInt(str[1]);                         //make the 0 to 0  -- 00000000
		chn = (tempWord[0] << 4) | tempWord[1];                //to change the BO to 10110000
		return chn;
	};
	//UTF_8 תunicode
	int strCoding::UTF8ToUnicode(char *pOut,char *pText)
	{
		unsigned char buf[4];
		memset(buf,0,4);
		int i =0;
		int j = 0;      
		while(pText[i])
		{
			if( pText[i] >= 0 && pText[i]<128)
			{
#ifdef WIN32
				pOut[j++]=pText[i++];
				pOut[j++]=0;
#else
				pOut[j++]=0;
				pOut[j++]=pText[i++];
#endif
 			}
			else
			//if(pText[i] < 0)	//if(pText[i]&0xE0==0xE0)	//	
			{
				__UTF8ToUnicode((char *)buf,pText + i); 
				pOut[j] = buf[0];
				pOut[j+1] = buf[1];
				i += 3;
				j += 2;
			}
		}
		pOut[j]='\0';
		return j;
	};
	//UTF_8 תgb2312
	void strCoding::UTF8ToGB2312(char *pOut,char *pText)
	{
		unsigned char buf[4];
		memset(buf,0,4);
		int i =0;
		int j = 0;      
		while(pText[i])
		{
			if( pText[i] >= 0 && pText[i]<128)
			{
				pOut[j++] = pText[i++];
			}
			else
			//if(pText[i] < 0)	//if(pText[i]&0xE0==0xE0)	//	
			{
				__UTF8ToGB2312((char *)buf,pText + i); 
				pOut[j] = buf[0];
				pOut[j+1] = buf[1];
				i += 3;
				j += 2;
			}
		}
		pOut[j]='\0';
	};
	//GB2312 תΪ UTF-8
	void strCoding::GB2312ToUTF8(char *pOut,char *pText)
	{
		char buf[4];
		memset(buf,0,4);
		int i = 0;
		int j=0;
		while(pText[i])
		{
			//�����Ӣ��ֱ�Ӹ��ƾͿ���
			if( pText[i] >= 0 && pText[i]<128)
			{
				pOut[j++]=pText[i++];
			}
			else
			{
				__GB2312ToUTF8(buf,pText+i);
				pOut[j++]=buf[0];
				pOut[j++]=buf[1];
				pOut[j++]=buf[2];
				i += 2;
			}
		}
		return;
	}

	//GB2312 תΪ Unicode
	int strCoding::GB2312ToUnicode(char *pOut,char *pText)
	{
		char buf[4];
		memset(buf,0,4);
		int i = 0;
		int j=0;
		while(pText[i])
		{
			//�����Ӣ��ֱ�Ӹ��ƾͿ���
			if( pText[i] >= 0 && pText[i]<128)
			{
#ifdef WIN32
				pOut[j++]=pText[i++];
				pOut[j++]=0;
#else
				pOut[j++]=0;
				pOut[j++]=pText[i++];
#endif
			}
			else
			{
				__GB2312ToUnicode(buf,pText+i);
				pOut[j++]=buf[0];
				pOut[j++]=buf[1];
				i += 2;
			}
		}
		return j;
	}

	//Unicode תΪ GB2312
	void strCoding::UnicodeToGB2312(char *pOut,char *pText,int len)
	{
		char buf[4];
		memset(buf,0,4);
		int i = 0;
		int j=0;
		while(i<len)
		{
			if(pText[i]==0 && pText[i+1]<128)
			{
				pOut[j++] = pText[i+1];
			}
			else
			{
				__UnicodeToGB2312(buf,pText+i);
				pOut[j++]=buf[0];
				pOut[j++]=buf[1];
			}
			i += 2;
		}
		return;
	}

	//Unicode תΪ UTF8
	void strCoding::UnicodeToUTF8(char *pOut,char *pText,int len)
	{
		unsigned char buf[4];
		memset(buf,0,4);
		int i =0;
		int j = 0;      
		while(i<len)
		{
#ifdef WIN32
			if(pText[i+1]==0 && pText[i]<128)
			{
				pOut[j++] = pText[i];
			}
			else
#else
			if(pText[i]==0 && pText[i+1]<128)
			{
				pOut[j++] = pText[i+1];
			}
			else
#endif
			{
				__UnicodeToUTF8((char *)buf,pText + i); 
				pOut[j++] = buf[0];
				pOut[j++] = buf[1];
				pOut[j++] = buf[2];
			}
			i+=2;
		}
		pOut[j]='\0';
	};
	//gb2312תutf8
	bool strCoding::GB2312ToUTF8(char* pstrOut, size_t dwOutLen, const char* pstrIn, size_t dwInLen)
	{
		if (NULL == pstrOut)
		{
			return false;
		}
#ifdef WIN32
		int i = MultiByteToWideChar(CP_ACP, 0, pstrIn, -1, NULL, 0);
		wchar_t * strSrc = new wchar_t[i+1];
		MultiByteToWideChar(CP_ACP, 0, pstrIn, -1, strSrc, i);
		i = WideCharToMultiByte(CP_UTF8, 0, strSrc, -1, NULL, 0, NULL, NULL);
		if (i >= dwOutLen)
		{
			i = dwOutLen - 1;
		}
		WideCharToMultiByte(CP_UTF8, 0, strSrc, -1, pstrOut, i, NULL, NULL);
		delete strSrc;
#else
		iconv_t iConv = iconv_open("UTF-8","GBK"); 
		if(iConv == (iconv_t)(-1))
		{
			EXP("iconv_open error");
			return false;
		}

		if(-1== iconv(iConv, (char **)&pstrIn, (size_t *)&dwInLen, (char **)&pstrOut, (size_t *)&dwOutLen) )
		{
			EXP("iconv error");
			iconv_close(iConv);
			return false;
		}
		iconv_close(iConv);
#endif
		return true;
	}

	//utf8תgb2312
	bool strCoding::UTF8ToGB2312(char* pstrOut, size_t dwOutLen, const char* pstrIn, size_t dwInLen)
	{
		if (NULL == pstrOut)
		{
			return false;
		}
#ifdef WIN32
		int i = MultiByteToWideChar(CP_UTF8, 0, pstrIn, -1, NULL, 0);
		wchar_t * strSrc = new wchar_t[i+1];
		MultiByteToWideChar(CP_UTF8, 0, pstrIn, -1, strSrc, i);
		i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
		if (i >= dwOutLen)
		{
			i = dwOutLen - 1;
		}
		WideCharToMultiByte(CP_ACP, 0, strSrc, -1, pstrOut, i, NULL, NULL);
		delete strSrc;
#else
		iconv_t iConv = iconv_open("GBK","UTF-8"); 
		if(iConv == (iconv_t)(-1))
		{
			EXP("iconv_open error\n");
		}
		if(-1== iconv(iConv, (char **)&pstrIn, (size_t *)&dwInLen, (char **)&pstrOut, (size_t *)&dwOutLen) )
		{
			EXP("iconv error\n");
			iconv_close(iConv);
			return false;
		}
		iconv_close(iConv);
#endif
		return true;
	}

	//��str����Ϊ��ҳ�е� GB2312DATA url encode ,Ӣ�Ĳ��䣬����˫�ֽ�  ��%3D%AE
	string strCoding::UrlGB2312(char * str)
	{
		string dd;
		size_t len = strlen(str);
		for (size_t i=0;i<len;i++)
		{
			if(isalnum(str[i]))
			{
				char tempbuff[2];
				sprintf(tempbuff,"%c",str[i]);
				dd.append(tempbuff);
			}
			else if (isspace(str[i]))
			{
				dd.append("+");
			}
			else
			{
				char tempbuff[4];
				sprintf(tempbuff,"%%%X%X",str[i] >>4,str[i] %16);
				dd.append(tempbuff);
			}
		}
		return dd;
	};
	//��str����Ϊ��ҳ�е� UTF-8 url encode ,Ӣ�Ĳ��䣬�������ֽ�  ��%3D%AE%88
	string strCoding::UrlUTF8(char * str)
	{
		string tt;
		string dd;
		char buf[4];memset(buf,0,4);
		GB2312ToUTF8(buf,str);
		size_t len=strlen(buf);
		const char *s=tt.data();
		for (size_t i=0;i<len;i++)
		{
			if(isalnum(s[i]))
			{
				char tempbuff[2]={0};
				sprintf(tempbuff,"%c",s[i]);
				dd.append(tempbuff);
			}
			else if (isspace(s[i]))
			{
				dd.append("+");
			}
			else
			{
				char tempbuff[4];
				sprintf(tempbuff,"%%%X%X",s[i] >>4,s[i] %16);
				dd.append(tempbuff);
			}

		}
		return dd;
	}
	//��url GB2312DATA����
	string strCoding::UrlGB2312Decode(string str)
	{
		string output="";
		char tmp[2];
		int i=0,idx=0,ndx,len=str.length();
		while(i<len)
		{
			if(str[i]=='%')
			{
				tmp[0]=str[i+1];
				tmp[1]=str[i+2];
				output += StrToBin(tmp);
				i=i+3;
			}
			else if(str[i]=='+')
			{
				output+=' ';
				i++;
			}
			else
			{
				output+=str[i];
				i++;
			}
		}
		return output;
	}
	//��url utf8����
	string strCoding::UrlUTF8Decode(string str)
	{
		string output="";
		char *data=new char[str.size()];
		string temp =UrlGB2312Decode(str);
		UTF8ToGB2312(data,(char *)temp.data());
		output=data;
		delete []data;
		return output;
	};
}
//
