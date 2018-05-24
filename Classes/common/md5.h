// ==============================================================
//progame      Common::md5 md5 hash encrypt
//company      hans
//copyright    Copyright (c) hans  2007-4     2008-03
//version      1.0
//Author       hans
//date         2007-4     2008-03
//description  Common namespace
//				This library is free software. Permission to use, copy,
//				modify and redistribute it for any purpose is hereby granted
//				without fee, provided that the above copyright notice appear
//				in all copies.
// ==============================================================

#ifndef __Common_md5_H__  
#define __Common_md5_H__
namespace Common
{
	//
	// 摘要:
	//	散列MD5
	//
    // 作 者: 邹远贵
    // 日 期: 2007-4-25
    // 版 本: 1.0
	//
	class md5
	{
		typedef unsigned char *POINTER;  
		typedef unsigned long int UINT4;  

		// MD5 context.                                       
		typedef struct
		{  
			UINT4 state[4]; // state (ABCD)                                       
			UINT4 count[2]; // number of bits, modulo 2^64 (lsb first)                                       
			unsigned char buffer[64]; // input buffer                                       
		} MD5_CTX;


		static unsigned char PADDING[64];

		static void MD5Transform (UINT4 [4], unsigned char [64]);
		static void Encode (unsigned char *, UINT4 *, unsigned int);
		static void Decode (UINT4 *, unsigned char *, unsigned int);
		static void MD5_memcpy (POINTER, POINTER, unsigned int);
		static void MD5_memset (POINTER, int, unsigned int);

		static void MD5Init(MD5_CTX *);  
		static void MD5Update(MD5_CTX * , unsigned char * , unsigned int);  
		static void MD5Final(unsigned char [16], MD5_CTX *);
		static string  ConvertChar(unsigned char [16],int);
	public:
		// 摘要:
		//     32位的MD5加密字符串。
		//
		// 参数:
		//   要加密的字符串:
		//     要效验的文件路径。
		// 返回结果:
		//     32位MD5效验字符串。
		static string  md5_32(string s);
		// 摘要:
		//     16位的MD5加密字符串。
		//
		// 参数:
		//   要加密的字符串:
		//     要效验的文件路径。
		// 返回结果:
		//     16位MD5效验字符串。
		static string  md5_16(string s);
		// 摘要:
		//     将文件进行MD5效验。
		//
		// 参数:
		//   filename:
		//     要效验的文件路径。
		// 返回结果:
		//     MD5效验字符串。
		static string  mdFile(string s);
	};
}
#endif 

