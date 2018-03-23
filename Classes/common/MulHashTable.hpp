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
//funcation		��ֵhash��ģ���࣬���ļ����ݿ������洢ʵ���г��������
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
			unsigned long long lnext;					//��ֵ
			unsigned long long rnext;					//���� ��һ��λ��
			unsigned int hashCode;						//hashֵ
			unsigned int hashCode2;						//hashֵ  �����ַ���У��
			VALUET  val;								//��ǰ�ڵ�����λ��
			unsigned int hashCode3;						//hashֵ  �����ַ���У��
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

		//  ��ӽڵ㵽HashTable��  true��ʾ��һ�μ��뵽hash����,false��ʾ������
		inline bool addNode(HashNode * &node)
		{
			if(nodes==NULL)
			{
				if(this->hashSize==0)EXP("addNodeδ����hash��ʼ����С");
				try
				{
					nodes=new HashNode[this->hashSize];	//����洢�ռ�
				}
				catch(...)
				{
					EXP("hash���ڴ�ռ����ʧ��");
				}
			}
			if(node->hashCode==0){delete node;return false;}
			unsigned int curIndex=node->hashCode%this->hashSize;					//ȡ����λ��;
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
		//  ��ӽڵ㵽HashTable��
		inline bool addNode(const KEYT &key,const VALUET & val)
		{
			HashNode *node=getHashNode(key,val);
			return addNode(node);
 		};

		//	�����С,��������ǰֵ
		inline void setSize(int hashSize)
		{
			if(this->nodes==NULL)			
				this->hashSize=hashSize;
		};
		//	����hash���С
		inline int getSize(){return this->hashSize;};
		//ɾ��ֵ�ӽڵ�
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
		//ɾ�����ӽڵ��µ�����
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
		//  ��������
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
		//�Ƴ�һ���ؼ���
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
				clearLeftNode(pNode);							//��ɾ����ֵ�ڵ�
				if(pNode->rnext==0)//�޺����ڵ�
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
					clearLeftNode(pNode);							//��ɾ����ֵ�ڵ�
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

		//	����������,����ֵ����
		inline VALUET & operator[](const KEYT &key)
		{
			if(nodes==NULL)
			{
				if(this->hashSize==0)EXP("operator[]δ����hash��ʼ����С");
				try
				{
					nodes=new HashNode[this->hashSize];	//����洢�ռ�
				}
				catch(...)
				{
					EXP("hash���ڴ�ռ����ʧ��");
				}
			}
			HashNode *node=getHashNode(key);
			unsigned int curIndex=node->hashCode%this->hashSize;					//ȡ����λ��;
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
					delete node;									//�Ѿ�����
					return pNode->val;
				}
				curNode=pNode;
				pNode=(HashNode *)pNode->rnext;
			}
			curNode->rnext=(unsigned long long)node;
			return node->val;
		};
		//	���ڴ����,����ֵָ������
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
		//��inline bool find(const KEYT &key,VALUET &val,HashNode * * exp=NULL)���ʹ��
		inline bool next(VALUET &val,unsigned long long &exp)
		{
			if(exp==0)return false;
			HashNode * pNode=(HashNode *)exp;
			val=pNode->val; 
			exp=pNode->lnext;
			return true;
		};
		//����ֵ�ӽڵ�
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
		//��֤һ��KEY�Ƿ����
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
		//     ���ļ�����,��Ҫ�����Ѿ������ֵָ��
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
			if(len!=NodeSize)	EXP("��ȡkey���ݷ�������,δ��ȡ��ָ�����ȵ�����.");
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
					return false;						//δ�ҵ�
				}
			}
			return false;
		}; 
		//��inline bool find(FILE *pkeyFile,const KEYT &key,VALUET & val,unsigned long long * exp=NULL)���ʹ��
		inline bool next(FILE *pkeyFile,VALUET &val,unsigned long long &exp)
		{
			if(exp==0)return false;
			HashNode tempNode;
			long long curPos=exp;
			fseek(pkeyFile, curPos, SEEK_SET);
			int len= fread(&tempNode,1,NodeSize,pkeyFile);
			if(len!=NodeSize)	EXP("��ȡkey���ݷ�������,δ��ȡ��ָ�����ȵ�����.");
			exp=tempNode.lnext;
			val=tempNode.val;
			return true;
 		};
		//д��ڵ�
		inline void writeLeftNode(FILE *pkeyFile,HashNode * pNode)
		{
			if(pNode)return;
 			HashNode * lNext=(HashNode *)pNode->lnext;
			fseek(pkeyFile, 0, SEEK_END);
			long fileSize=ftell(pkeyFile);
			pNode->lnext=((lNext!=NULL)? fileSize+NodeSize:0 );
			int len=fwrite(pNode,1,NodeSize,pkeyFile);
 			if(len!=NodeSize)
				EXP("д��hash�ļ���������");
			writeLeftNode(pkeyFile,lNext);
			delete pNode;
		};
		//д�ҽڵ�
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
				EXP("д��hash�ļ���������");
			if(lNext)
				writeLeftNode(pkeyFile,lNext);
			if(rNext)
				writeRightNode(pkeyFile,rNext);
			delete pNode;
		};
		//дһ���ڵ�
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
				EXP("д��hash�ļ���������");
			if(lNext)
				writeLeftNode(pkeyFile,lNext);
			if(rNext)
				writeRightNode(pkeyFile,rNext);
		};
		//     ��HashTable����д���ļ�,д����ɾ��HashTable �е��ڴ�����
		inline void writeFile(FILE *pkeyFile)
		{
			if(nodes==NULL)
			{
				if(this->hashSize==0)EXP("writeFileδ����hash��ʼ����С");
				try
				{
					nodes=new HashNode[this->hashSize];	//����洢�ռ�
				}
				catch(...)
				{
					EXP("hash���ڴ�ռ����ʧ��");
				}
			}
			HashNode tempNode=HashNode();
			fseek(pkeyFile,(this->hashSize) * NodeSize-1 ,SEEK_SET);			//ֱ��д����󳤶�
			int len=fwrite("\0",1,1,pkeyFile);
			fflush(pkeyFile);
			long fileSize=ftell(pkeyFile);
			if(len!=1 || fileSize!=this->hashSize * NodeSize)
				EXP("��ʼ��hash�ļ���С��������.");
			for(int i=0;i<this->hashSize;i++)
			{
				if(nodes[i].hashCode==0)continue;
				writeNode(pkeyFile,nodes+i);
			}
			delete [] nodes;
			nodes=NULL;
		};
		//     ֱ�ӽ�KEYд���ļ�
		inline static void writeFile(FILE *pkeyFile,const KEYT &key,const VALUET &val,int hashSize)
		{
			if(!pkeyFile)EXP("key�ļ�ָ��Ϊ��.");
			fseek(pkeyFile, 0, SEEK_END);//���ж��Ƿ��Ѿ���ʼ���ļ�
			long fileSize=ftell(pkeyFile);
			if(fileSize<NodeSize * hashSize)
			{
				HashNode tempNode=HashNode();
				fseek(pkeyFile,(hashSize* NodeSize -1),SEEK_SET);			//ֱ��д����󳤶�
				int len=fwrite("\0",1,1,pkeyFile);
				fflush(pkeyFile);
				fileSize=ftell(pkeyFile);
				if(len!=1 || fileSize!=hashSize*NodeSize)
					EXP("��ʼ��hash�ļ���С��������.");
			}
			//ֱ��д���ļ�
			int len=0;
			HashNode *node=getHashNode(key,val);
			unsigned int curIndex=node->hashCode % hashSize;					//ȡ����λ��;
			long long curPos=NodeSize*curIndex;
			fseek(pkeyFile, curPos, SEEK_SET);
			HashNode tempNode;
			len= fread(&tempNode,1,NodeSize,pkeyFile);
			if(len!=NodeSize)	EXP("��ȡkey���ݷ�������,δ��ȡ��ָ�����ȵ�����.");
			if(tempNode.hashCode==0)
			{
				fseek(pkeyFile, curPos, SEEK_SET);
				len=fwrite(node,1,NodeSize,pkeyFile);
 				if(len!=NodeSize)	EXP("д��hash�ļ���������.");
				delete node;
			}
			else
			{
				//���ж��Ƿ��Ѿ�����
				if(tempNode.hashCode==node->hashCode && tempNode.hashCode2==node->hashCode2 && tempNode.hashCode3==node->hashCode3)
				{
					long pos=curPos;
					while(tempNode.lnext)
					{
						pos=tempNode.lnext;
						fseek(pkeyFile, tempNode.lnext, SEEK_SET);
						len = fread(&tempNode,1,NodeSize,pkeyFile);
						if(len!=NodeSize)	EXP("��ȡkey���ݷ�������,δ��ȡ��ָ�����ȵ�����.");
					}
					fseek(pkeyFile, 0, SEEK_END);
					fileSize=ftell(pkeyFile);
					fseek(pkeyFile, pos, SEEK_SET);//��д��һλ��
					tempNode.lnext=fileSize;
 					len=fwrite(&tempNode,1,NodeSize,pkeyFile);
					if(len!=NodeSize)	EXP("д��hash�ļ���������.");
					fseek(pkeyFile, 0, SEEK_END);//д�½ڵ�ֵ
					len=fwrite(node,1,NodeSize,pkeyFile);
 					if(len!=NodeSize)	EXP("д��hash�ļ���������.");
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
						if(len!=NodeSize)	EXP("��ȡkey���ݷ�������,δ��ȡ��ָ�����ȵ�����.");
						if(tempNode.hashCode==node->hashCode && tempNode.hashCode2==node->hashCode2 && tempNode.hashCode3==node->hashCode3)
						{
							while(tempNode.lnext)
							{
								pos=tempNode.lnext;
								fseek(pkeyFile, tempNode.lnext, SEEK_SET);
								len = fread(&tempNode,1,NodeSize,pkeyFile);
								if(len!=NodeSize)	EXP("��ȡkey���ݷ�������,δ��ȡ��ָ�����ȵ�����.");
							}
							fseek(pkeyFile, 0, SEEK_END);
							fileSize=ftell(pkeyFile);
							fseek(pkeyFile, pos, SEEK_SET);//��д��һλ��
							tempNode.lnext=fileSize;
							fseek(pkeyFile, curPos, SEEK_SET);
							len=fwrite(&tempNode,1,NodeSize,pkeyFile);
							if(len!=NodeSize)	EXP("д��hash�ļ���������.");
							fseek(pkeyFile, 0, SEEK_END);//д�½ڵ�ֵ
							len=fwrite(node,1,NodeSize,pkeyFile);
 							if(len!=NodeSize)	EXP("д��hash�ļ���������."); 
							delete node;
							return;
						}
					}
					fseek(pkeyFile, 0, SEEK_END);
					fileSize=ftell(pkeyFile);
					fseek(pkeyFile, pos, SEEK_SET);//��д��һλ��
					tempNode.lnext=fileSize;
					fseek(pkeyFile, curPos, SEEK_SET);
					len=fwrite(&tempNode,1,NodeSize,pkeyFile);
					if(len!=NodeSize)	EXP("д��hash�ļ���������.");
					fseek(pkeyFile, 0, SEEK_END);//д�½ڵ�ֵ
					len=fwrite(node,1,NodeSize,pkeyFile);
 					if(len!=NodeSize)	EXP("д��hash�ļ���������."); 
					delete node;
				}
			}
		};
		//	��ȡ��hash�ڵ��ָ��
		static HashNode * getHashNode(const KEYT &key,const VALUET & val)
		{
			HashNode *node=new HashNode(key,val);
			return node;
		};
		//	��ȡ��hash�ڵ��ָ��
		static HashNode * getHashNode(const KEYT &key)
		{
			HashNode *node=new HashNode(key);
			return node;
		};
		//	����hash��
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
				cout<<"hash�������: "<< distributing[0] <<endl;
				int countPos=0;
				for(int i=1;i<distributing.size();i++)
				{
					countPos+=distributing[i];
				}
				for(int i=1;i<distributing.size();i++)
				{
					cout<<"hash "<<i<<" �ζ�λ��: "<< distributing[i] <<" ռ��: "<< (double)distributing[i]/countPos <<endl;
				}
				cout<<"hash��ʹ����: "<< (double)distributing[1]*100/this->hashSize <<endl;
			}
			else
			{
				cout<<"������hash�ڵ�! " <<endl;
			}
			distributing.clear();
		};
		//	��ȡhash�����
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
