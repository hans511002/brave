// ==============================================================
//progame      Common:MulHashTable 
//company      hans
//copyright    Copyright (c) hans  2007-2010
//version      1.0
//Author       hans
//date         2010-06-07
//description  Common namespace
//				This library is free software. Permission to use, copy,
//				modify and redistribute it for any purpose is hereby granted
//				without fee, provided that the above copyright notice appear
//				in all copies.
//funcation		多值hash表模板类，从文件数据库索引存储实现中抽象出来。
// ==============================================================

#ifndef __Common_MulHashTable_HPP__
#define __Common_MulHashTable_HPP__
#include "hashMath.h"
#include "HashTable.hpp"
namespace Common
{
 	template <class KEYT,class VALUET> class MulHashTable
	{
	public:
		class HashNode
		{
		public:
			unsigned long long lnext;					//左值
			unsigned long long rnext;					//链表 下一个位置
			unsigned int hashCode;						//hash值
			unsigned int hashCode2;						//hash值  用于字符串校验
			VALUET  val;								//当前节点数据位置
			unsigned int hashCode3;						//hash值  用于字符串校验
			HashNode():hashCode(0),rnext(0),lnext(0),val(VALUET()),hashCode2(0),hashCode3(0){};
			HashNode(const KEYT &key):rnext(0),lnext(0),val(VALUET())
			{
				hashCode=HASHMATH_METHOD1(key);
				hashCode2=HASHMATH_METHOD2(key);
				hashCode3=HASHMATH_METHOD3(key);
			};
			HashNode(const KEYT &key,const VALUET &val):rnext(0),lnext(0),val(val)
			{
				hashCode=HASHMATH_METHOD1(key);
				hashCode2=HASHMATH_METHOD2(key);
				hashCode3=HASHMATH_METHOD3(key);
			};
		};
		HashNode * nodes;
		unsigned int hashSize;
		MulHashTable(int _size=0){this->hashSize=_size;nodes=NULL;};
		~MulHashTable(){clear();};

		//  添加节点到HashTable中  true表示第一次加入到hash表中,false表示后续的
		inline bool addNode(HashNode * &node)
		{
			if(nodes==NULL)
			{
				if(this->hashSize==0)EXP("addNode未设置hash初始化大小");
				try
				{
					nodes=new HashNode[this->hashSize];	//分配存储空间
				}
				catch(...)
				{
					EXP("hash表内存空间分配失败");
				}
			}
			if(node->hashCode==0){delete node;return false;}
			unsigned int curIndex=node->hashCode%this->hashSize;					//取索引位置;
			if(nodes[curIndex].hashCode==0)
			{
				nodes[curIndex]=*node;
				delete node;
				node=NULL;
				return true;
			}
			else
			{
				HashNode * pNode;
				pNode=&(nodes[curIndex]);
				if(nodes[curIndex].hashCode==node->hashCode && nodes[curIndex].hashCode2==node->hashCode2 && nodes[curIndex].hashCode3==node->hashCode3 )
				{
					while(pNode->lnext)
					{
						pNode=(HashNode *)(pNode->lnext);
					}
					pNode->lnext=(unsigned long long)node;
					return false;
				}
				while(pNode->rnext)
				{
					pNode=(HashNode *)(pNode->rnext);
					if(pNode->hashCode==node->hashCode && pNode->hashCode2==node->hashCode2 && pNode->hashCode3==node->hashCode3 )
					{
						while(pNode->lnext)
						{
							pNode=(HashNode *)(pNode->lnext);
						}
						pNode->lnext=(unsigned long long)node;
						return false;
					}
				}
				pNode->rnext=(unsigned long long)node;
				return true;
			}
		};
		//  添加节点到HashTable中
		inline bool addNode(const KEYT &key,const VALUET & val)
		{
			HashNode *node=getHashNode(key,val);
			return addNode(node);
 		};

		//	重设大小,不保留以前值
		inline void setSize(int hashSize)
		{
			if(this->nodes==NULL)			
				this->hashSize=hashSize;
		};
		//	返回hash表大小
		inline int getSize(){return this->hashSize;};
		//删除值子节点
		inline void clearLeftNode(HashNode * pnode)
		{
			if(pnode==NULL)return;
			if(pnode->lnext)
			{
				pnode=(HashNode *)pnode->lnext;
				clearLeftNode(pnode);
				delete pnode;
			}
		}
		//删除右子节点下的数据
		inline void clearRightNode(HashNode * pnode)
		{
			if(pnode==NULL)return;
			if(pnode->rnext)
			{
				clearLeftNode(pnode);
				pnode=(HashNode *)pnode->rnext;
				clearRightNode(pnode);
				delete pnode;
			}
		};
		//  清理数据
		inline void clear()
		{
			if(nodes)
			{
				for(int i=0;i<this->hashSize;i++)
				{
					clearLeftNode(this->nodes+i);
					clearRightNode(this->nodes+i);
				}
				delete []nodes;
			}
			nodes=NULL;
		};
		//移除一个关键字
		inline bool remove(const KEYT &key)
		{
			if(nodes==NULL)return false;
			unsigned int hashCode,hashCode2,hashCode3,curIndex;
			hashCode=HASHMATH_METHOD1(key);
			hashCode2=HASHMATH_METHOD2(key);
			hashCode3=HASHMATH_METHOD3(key);
			curIndex=hashCode%this->hashSize;
			HashNode * pNode=nodes + curIndex;
			if(pNode->hashCode==hashCode && pNode->hashCode2==hashCode2 && pNode->hashCode3==hashCode3)
			{
				clearLeftNode(pNode);							//先删除等值节点
				if(pNode->rnext==0)//无后续节点
				{
					pNode->hashCode=0;
					pNode->hashCode2=0;
					pNode->hashCode3=0;
					pNode->lnext=0;
				}
				else
				{
					HashNode * priNode=pNode;
					pNode=(HashNode *)pNode->rnext;
					(*priNode)=(*pNode);
					delete pNode;
				}
				return true;
			}
			HashNode * priNode=pNode;
			pNode=(HashNode *)pNode->rnext;
			while(pNode)
			{
				if(pNode->hashCode==hashCode && pNode->hashCode2==hashCode2 && pNode->hashCode3==hashCode3)
				{
					clearLeftNode(pNode);							//先删除等值节点
					if(pNode->rnext)
					{
						priNode->rnext=pNode->rnext;
					}
					delete pNode;
					return true;
				}
				priNode=pNode;
				pNode=(HashNode *)pNode->rnext;
			}
			return false;
		}

		//	操作符重载,返回值引用
		inline VALUET & operator[](const KEYT &key)
		{
			if(nodes==NULL)
			{
				if(this->hashSize==0)EXP("operator[]未设置hash初始化大小");
				try
				{
					nodes=new HashNode[this->hashSize];	//分配存储空间
				}
				catch(...)
				{
					EXP("hash表内存空间分配失败");
				}
			}
			HashNode *node=getHashNode(key);
			unsigned int curIndex=node->hashCode%this->hashSize;					//取索引位置;
			HashNode * pNode;
			HashNode * curNode=nodes + curIndex;
			if(curNode->hashCode==0)
			{
				*curNode=*node;
				delete node;
				return curNode->val;
			}
			pNode=curNode;
			while(pNode)
			{
				if(pNode->hashCode==node->hashCode && pNode->hashCode2==node->hashCode2 && pNode->hashCode3==node->hashCode3)
				{
					delete node;									//已经存在
					return pNode->val;
				}
				curNode=pNode;
				pNode=(HashNode *)pNode->rnext;
			}
			curNode->rnext=(unsigned long long)node;
			return node->val;
		};
		//	从内存查找,传入值指针引用
		inline bool find(const KEYT &key,VALUET &val,unsigned long long * exp=NULL)
		{
			if(nodes==NULL)return false;
			unsigned int hashCode,hashCode2,hashCode3,curIndex;
			hashCode=HASHMATH_METHOD1(key);
			hashCode2=HASHMATH_METHOD2(key);
			hashCode3=HASHMATH_METHOD3(key);
			curIndex=hashCode%this->hashSize;
			HashNode * pNode=nodes + curIndex;
			while(pNode)
			{
				if(pNode->hashCode==hashCode && pNode->hashCode2==hashCode2 && pNode->hashCode3==hashCode3)
				{
					val=pNode->val;
					if(exp)*exp=(unsigned long long)pNode->lnext;
					return true;
				}
				pNode=(HashNode *)pNode->rnext;
			}
			if(exp)*exp=0;
			return false;
		};
		//与inline bool find(const KEYT &key,VALUET &val,HashNode * * exp=NULL)组合使用
		inline bool next(VALUET &val,unsigned long long &exp)
		{
			if(exp==0)return false;
			HashNode * pNode=(HashNode *)exp;
			val=pNode->val; 
			exp=pNode->lnext;
			return true;
		};
		//查找值子节点
		inline void findLeftNode(HashNode * pnode,Array<unsigned long long> &clearIds)
		{
			if(pnode==NULL)return;
			while(pnode->lnext)
			{
				clearIds.push_back(pnode->lnext);
				pnode=(HashNode *)pnode->lnext;
			}
		}
		inline bool findAll(const KEYT &key,Array<VALUET> &vals)
		{
			vals.clear();
			unsigned long long exp=0;
			VALUET val;
			bool res=find(key,val,&exp);
			if(res==false)return false;
			vals.push_back(val);
			while(exp>0)
			{
				vals.push_back(((HashNode *)exp)->val);
				exp=((HashNode *)exp)->lnext;
			}
			return true;
		};
		//验证一个KEY是否存在
		inline bool contain(const KEYT &key)
		{
			if(nodes==NULL)return false;
			unsigned int hashCode,hashCode2,hashCode3,curIndex;
			hashCode=HASHMATH_METHOD1(key);
			hashCode2=HASHMATH_METHOD2(key);
			hashCode3=HASHMATH_METHOD3(key);
			curIndex=hashCode%this->hashSize;
			HashNode * pNode=nodes + curIndex;
			while(pNode)
			{
				if(pNode->hashCode==hashCode && pNode->hashCode2==hashCode2 && pNode->hashCode3==hashCode3)
				{
					return true;
				}
				pNode=(HashNode *)pNode->rnext;
			}
			return false;
		};
		//     从文件查找,需要传入已经定义的值指针
		inline static bool find(FILE *pkeyFile,const KEYT &key,VALUET &val,int hashSize)
		{
			if(!pkeyFile)return false;
 			unsigned int hashCode,hashCode2,hashCode3,curIndex;
			hashCode=HASHMATH_METHOD1(key);
			hashCode2=HASHMATH_METHOD2(key);
			hashCode3=HASHMATH_METHOD3(key);
			HashNode tempNode;
			curIndex=hashCode%hashSize;
			long long curPos=NodeSize*curIndex;
			fseek(pkeyFile, curPos, SEEK_SET);
			int len= fread(&tempNode,1,NodeSize,pkeyFile);//return false;
			if(len!=NodeSize)	EXP("读取key数据发生错误,未读取到指定长度的数据.");
			while(tempNode.hashCode%hashSize==curIndex)
			{
				if(tempNode.hashCode==hashCode && tempNode.hashCode2==hashCode2 && tempNode.hashCode3==hashCode3)
				{
					val=tempNode.val;
 					return true;
				}
				if(!tempNode.rnext)return false;
				fseek(pkeyFile, tempNode.rnext, SEEK_SET);
				fread(&tempNode,1,NodeSize,pkeyFile);
				if(tempNode.hashCode==0)
				{
					return false;						//未找到
				}
			}
			return false;
		}; 
		//与inline bool find(FILE *pkeyFile,const KEYT &key,VALUET & val,unsigned long long * exp=NULL)组合使用
		inline bool next(FILE *pkeyFile,VALUET &val,unsigned long long &exp)
		{
			if(exp==0)return false;
			HashNode tempNode;
			long long curPos=exp;
			fseek(pkeyFile, curPos, SEEK_SET);
			int len= fread(&tempNode,1,NodeSize,pkeyFile);
			if(len!=NodeSize)	EXP("读取key数据发生错误,未读取到指定长度的数据.");
			exp=tempNode.lnext;
			val=tempNode.val;
			return true;
 		};
		//写左节点
		inline void writeLeftNode(FILE *pkeyFile,HashNode * pNode)
		{
			if(pNode)return;
 			HashNode * lNext=(HashNode *)pNode->lnext;
			fseek(pkeyFile, 0, SEEK_END);
			long fileSize=ftell(pkeyFile);
			pNode->lnext=((lNext!=NULL)? fileSize+NodeSize:0 );
			int len=fwrite(pNode,1,NodeSize,pkeyFile);
 			if(len!=NodeSize)
				EXP("写入hash文件发生错误");
			writeLeftNode(pkeyFile,lNext);
			delete pNode;
		};
		//写右节点
		inline void writeRightNode(FILE *pkeyFile,HashNode * pNode)
		{
			if(pNode)return ;
			HashNode * lNext=(HashNode *)pNode->lnext;
			HashNode * rNext=(HashNode *)pNode->rnext;
			fseek(pkeyFile, 0, SEEK_END);
			long fileSize=ftell(pkeyFile);
			fileSize += NodeSize;
			pNode->lnext=((lNext!=NULL)? fileSize:0 );
			HashNode * leftNext=lNext;
			while(leftNext)
			{
				fileSize+=NodeSize;
				leftNext=(HashNode *)leftNext->lnext;
			}
			pNode->rnext=((rNext!=NULL)? fileSize:0 );

			int len=fwrite(pNode,1,NodeSize,pkeyFile);
 			if(len!=NodeSize)
				EXP("写入hash文件发生错误");
			if(lNext)
				writeLeftNode(pkeyFile,lNext);
			if(rNext)
				writeRightNode(pkeyFile,rNext);
			delete pNode;
		};
		//写一个节点
		inline void writeNode(FILE *pkeyFile,HashNode * pNode)
		{
			if(pNode)return;
			HashNode * lNext=(HashNode *)pNode->lnext;
			HashNode * rNext=(HashNode *)pNode->rnext;
			fseek(pkeyFile, 0, SEEK_END);
			long fileSize=ftell(pkeyFile);
			long curPos= ((pNode->hashCode % hashSize) * NodeSize);

			pNode->lnext=((lNext!=NULL)? fileSize:0 );
			HashNode * leftNext=lNext;
			while(leftNext)
			{
				fileSize+=NodeSize;
				leftNext=(HashNode *)leftNext->lnext;
			}
			pNode->rnext=((rNext!=NULL)? fileSize:0 );

			fseek(pkeyFile, curPos, SEEK_SET);
			int len=fwrite(pNode,1,NodeSize,pkeyFile);
 			if(len!=NodeSize)
				EXP("写入hash文件发生错误");
			if(lNext)
				writeLeftNode(pkeyFile,lNext);
			if(rNext)
				writeRightNode(pkeyFile,rNext);
		};
		//     将HashTable数据写成文件,写完后会删除HashTable 中的内存数据
		inline void writeFile(FILE *pkeyFile)
		{
			if(nodes==NULL)
			{
				if(this->hashSize==0)EXP("writeFile未设置hash初始化大小");
				try
				{
					nodes=new HashNode[this->hashSize];	//分配存储空间
				}
				catch(...)
				{
					EXP("hash表内存空间分配失败");
				}
			}
			HashNode tempNode=HashNode();
			fseek(pkeyFile,(this->hashSize) * NodeSize-1 ,SEEK_SET);			//直接写入最大长度
			int len=fwrite("\0",1,1,pkeyFile);
			fflush(pkeyFile);
			long fileSize=ftell(pkeyFile);
			if(len!=1 || fileSize!=this->hashSize * NodeSize)
				EXP("初始化hash文件大小发生错误.");
			for(int i=0;i<this->hashSize;i++)
			{
				if(nodes[i].hashCode==0)continue;
				writeNode(pkeyFile,nodes+i);
			}
			delete [] nodes;
			nodes=NULL;
		};
		//     直接将KEY写入文件
		inline static void writeFile(FILE *pkeyFile,const KEYT &key,const VALUET &val,int hashSize)
		{
			if(!pkeyFile)EXP("key文件指针为空.");
			fseek(pkeyFile, 0, SEEK_END);//先判断是否已经初始化文件
			long fileSize=ftell(pkeyFile);
			if(fileSize<NodeSize * hashSize)
			{
				HashNode tempNode=HashNode();
				fseek(pkeyFile,(hashSize* NodeSize -1),SEEK_SET);			//直接写入最大长度
				int len=fwrite("\0",1,1,pkeyFile);
				fflush(pkeyFile);
				fileSize=ftell(pkeyFile);
				if(len!=1 || fileSize!=hashSize*NodeSize)
					EXP("初始化hash文件大小发生错误.");
			}
			//直接写入文件
			int len=0;
			HashNode *node=getHashNode(key,val);
			unsigned int curIndex=node->hashCode % hashSize;					//取索引位置;
			long long curPos=NodeSize*curIndex;
			fseek(pkeyFile, curPos, SEEK_SET);
			HashNode tempNode;
			len= fread(&tempNode,1,NodeSize,pkeyFile);
			if(len!=NodeSize)	EXP("读取key数据发生错误,未读取到指定长度的数据.");
			if(tempNode.hashCode==0)
			{
				fseek(pkeyFile, curPos, SEEK_SET);
				len=fwrite(node,1,NodeSize,pkeyFile);
 				if(len!=NodeSize)	EXP("写入hash文件发生错误.");
				delete node;
			}
			else
			{
				//先判断是否已经存在
				if(tempNode.hashCode==node->hashCode && tempNode.hashCode2==node->hashCode2 && tempNode.hashCode3==node->hashCode3)
				{
					long pos=curPos;
					while(tempNode.lnext)
					{
						pos=tempNode.lnext;
						fseek(pkeyFile, tempNode.lnext, SEEK_SET);
						len = fread(&tempNode,1,NodeSize,pkeyFile);
						if(len!=NodeSize)	EXP("读取key数据发生错误,未读取到指定长度的数据.");
					}
					fseek(pkeyFile, 0, SEEK_END);
					fileSize=ftell(pkeyFile);
					fseek(pkeyFile, pos, SEEK_SET);//回写上一位置
					tempNode.lnext=fileSize;
 					len=fwrite(&tempNode,1,NodeSize,pkeyFile);
					if(len!=NodeSize)	EXP("写入hash文件发生错误.");
					fseek(pkeyFile, 0, SEEK_END);//写新节点值
					len=fwrite(node,1,NodeSize,pkeyFile);
 					if(len!=NodeSize)	EXP("写入hash文件发生错误.");
					delete node;
					return;
				}
				else
				{
					unsigned long long pos=curPos;
					while(tempNode.rnext)
					{
						pos=tempNode.rnext;
						fseek(pkeyFile, tempNode.rnext, SEEK_SET);
						len = fread(&tempNode,1,NodeSize,pkeyFile);
						if(len!=NodeSize)	EXP("读取key数据发生错误,未读取到指定长度的数据.");
						if(tempNode.hashCode==node->hashCode && tempNode.hashCode2==node->hashCode2 && tempNode.hashCode3==node->hashCode3)
						{
							while(tempNode.lnext)
							{
								pos=tempNode.lnext;
								fseek(pkeyFile, tempNode.lnext, SEEK_SET);
								len = fread(&tempNode,1,NodeSize,pkeyFile);
								if(len!=NodeSize)	EXP("读取key数据发生错误,未读取到指定长度的数据.");
							}
							fseek(pkeyFile, 0, SEEK_END);
							fileSize=ftell(pkeyFile);
							fseek(pkeyFile, pos, SEEK_SET);//回写上一位置
							tempNode.lnext=fileSize;
							fseek(pkeyFile, curPos, SEEK_SET);
							len=fwrite(&tempNode,1,NodeSize,pkeyFile);
							if(len!=NodeSize)	EXP("写入hash文件发生错误.");
							fseek(pkeyFile, 0, SEEK_END);//写新节点值
							len=fwrite(node,1,NodeSize,pkeyFile);
 							if(len!=NodeSize)	EXP("写入hash文件发生错误."); 
							delete node;
							return;
						}
					}
					fseek(pkeyFile, 0, SEEK_END);
					fileSize=ftell(pkeyFile);
					fseek(pkeyFile, pos, SEEK_SET);//回写上一位置
					tempNode.lnext=fileSize;
					fseek(pkeyFile, curPos, SEEK_SET);
					len=fwrite(&tempNode,1,NodeSize,pkeyFile);
					if(len!=NodeSize)	EXP("写入hash文件发生错误.");
					fseek(pkeyFile, 0, SEEK_END);//写新节点值
					len=fwrite(node,1,NodeSize,pkeyFile);
 					if(len!=NodeSize)	EXP("写入hash文件发生错误."); 
					delete node;
				}
			}
		};
		//	获取新hash节点的指针
		static HashNode * getHashNode(const KEYT &key,const VALUET & val)
		{
			HashNode *node=new HashNode(key,val);
			return node;
		};
		//	获取新hash节点的指针
		static HashNode * getHashNode(const KEYT &key)
		{
			HashNode *node=new HashNode(key);
			return node;
		};
		//	分析hash表
		inline void analyse()
		{
			vector<int> distributing;
			distributing.push_back(1);
			if(nodes)
			{
				HashNode * pNode,* nextNode;
				for(int i=0;i<this->hashSize;i++)
				{
					if(this->nodes[i].hashCode!=0)
					{
						int depth=1;
						if(depth>=distributing.size())
							distributing.push_back(1);
						else
							distributing.at(depth)++;
						if(this->nodes[i].rnext)
						{
							nextNode=(HashNode *)this->nodes[i].rnext;
							while(nextNode)
							{
								depth++;
								if(depth>=distributing.size())
									distributing.push_back(1);
								else
									distributing.at(depth)++;
								pNode=nextNode;
								nextNode=(HashNode *)nextNode->rnext;
							}
							if(distributing.at(0)<depth)
								distributing.at(0)=depth;
						}
					}
				}
				cout<<"hash链表深度: "<< distributing[0] <<endl;
				int countPos=0;
				for(int i=1;i<distributing.size();i++)
				{
					countPos+=distributing[i];
				}
				for(int i=1;i<distributing.size();i++)
				{
					cout<<"hash "<<i<<" 次定位数: "<< distributing[i] <<" 占比: "<< (double)distributing[i]/countPos <<endl;
				}
				cout<<"hash表使用率: "<< (double)distributing[1]*100/this->hashSize <<endl;
			}
			else
			{
				cout<<"不存在hash节点! " <<endl;
			}
			distributing.clear();
		};
		//	获取hash表深度
		inline int getDepth()
		{
			int depth=1;
			if(nodes)
			{
				HashNode * pNode,* nextNode;
				for(int i=0;i<this->hashSize;i++)
				{
					int depth2=1;
					if(this->nodes[i].rnext)
					{
						nextNode=(HashNode *)this->nodes[i].rnext;
						while(nextNode)
						{
							depth++;
							pNode=nextNode;
							nextNode=(HashNode *)nextNode->rnext;
						}
						if(depth<depth2)depth=depth2;
					}
				}
			}
			return depth;
		};
		static const long long NodeSize;//=sizeof(NODE);
		static const int hashType;
	};
//#if OSTYPE>10
	template <class KEYT,class VALUET> const long long MulHashTable<KEYT,VALUET>::NodeSize=sizeof(MulHashTable<KEYT,VALUET>::HashNode);
	template <class KEYT,class VALUET> const int  MulHashTable<KEYT,VALUET>::hashType=13;
//#endif



	//
}
#endif
