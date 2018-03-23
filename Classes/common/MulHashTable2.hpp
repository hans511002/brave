// ==============================================================
//progame      Common:MulHashTable2 
//company      hans
//copyright    Copyright (c) hans  2007-2010
//version      1.0
//Author       hans
//date         2010-08-16
//description  Common namespace
//				This library is free software. Permission to use, copy,
//				modify and redistribute it for any purpose is hereby granted
//				without fee, provided that the above copyright notice appear
//				in all copies.
//funcation		hashͰֻ�洢���ָ�룬���ݽڵ���洢���ɶ�̬����hash��С��
// ==============================================================

#ifndef __Common_MulHashTable2_H__
#define __Common_MulHashTable2_H__

namespace Common
{
	template <class KEYT,class VALUET> class MulHashTable2
	{
	public:
		struct HashNode
		{
		public:
			unsigned long rnext;					//���� ��һ��λ��
			unsigned long lnext;					//���� ��һ��λ��
			unsigned int hashCode;					//hashֵ
			unsigned int hashCode2;					//hashֵ
			VALUET val;								//��ǰ�ڵ�����λ��
			unsigned int hashCode3;					//hashֵ
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
		int hashSize;	//	Ͱ��С fixSize= hashSize * sizeof(int *)
		int used;		//	Ͱʹ�ô�С,����������
		int nodeNum;	//	autoRise && nodeNum>hashSize && used*1.4>hashSize
		bool autoRise;	//	�Ƿ��Զ�����hash��С
		long * tab ;//hdidx;
	public:
		MulHashTable2(int _size=17):hashSize(_size),nodeNum(0),used(0),autoRise(false),tab(NULL){};
		~MulHashTable2(){clear();};
		///	<returns>���״̬��1���ɹ���2���Ѿ�����,-1���ռ䲻�� ,0��node��Ч</returns> 
		inline int addNode(HashNode * node)
		{
			if(tab==NULL)
			{
				if(this->hashSize==0)EXP("addNodeδ����hash��ʼ����С");
				try
				{
					tab=new long[this->hashSize];	//�����ռ�
					memset(tab,0,sizeof(long)*hashSize);
				}
				catch(...)
				{
					delete node;
					EXP("hash���ڴ�ռ����ʧ��");
				}
			}
			if(node->hashCode==0){delete node;return 0;}
			if(autoRise && nodeNum>hashSize && used*1.33>hashSize)	//	����hashͰ 75%�ݻ�
			{
				int oldSize=this->hashSize;
				int i;
				for (i = 0; i < itemsof(primeNumbers)-1 && primeNumbers[i] < hashSize; i++);
				if (i < itemsof(primeNumbers)-1){ i += 1;}
				int _hashSize = primeNumbers[i];
				resize(_hashSize);
			}
			unsigned int curIndex=node->hashCode%this->hashSize;					//ȡ����λ��;
			HashNode * pNode=(HashNode *)tab[curIndex];
			HashNode * priNode=pNode;
			while(pNode)
			{
				if(pNode->hashCode==node->hashCode && pNode->hashCode2==node->hashCode2 && pNode->hashCode3==node->hashCode3)
				{
					if(priNode==pNode)
					{
						tab[curIndex]=(long long)node;
					}
					else
					{
						priNode->rnext=(long long)node;
					}
					node->rnext=pNode->rnext;
					node->lnext=(long long)pNode;
					pNode->rnext=0;
					return 2;
				}
				priNode=pNode;
				pNode=(HashNode *)pNode->rnext;
			}
			node->next = tab[curIndex];
			tab[curIndex]=(long long)node;
			if(tab[curIndex]==0)
				this->used++;
			nodeNum++;
			return 1;
		};
		//  ��ӽڵ㵽MulHashTable2��
		inline int addNode(const KEYT &key,const VALUET &val)
		{
			HashNode *node=getHashNode(key,val);
			return addNode(node);
		};
		//  ��������������С,ÿ����һ�ζ��������������ݵĿ����ƶ�
		inline void resize(int _hashSize)
		{
			if(_hashSize>this->hashSize)
			{
				int oldSize=this->hashSize;
				this->hashSize=_hashSize;
				long * tmpTab = tab;
				tab=new long[hashSize];
				memset(tab,0,sizeof(long)*hashSize);
				for(int i= 0;i<oldSize;i++)
				{
					HashNode * pNode=(HashNode *)tmpTab[i];
					while(pNode)
					{
						HashNode * nNode=(HashNode *)pNode->rnext;
						unsigned h = pNode->hashCode % hashSize;
						if(pNode->rnext!=tab[h])
						{
							pNode->rnext=tab[h];
						}
						tab[h]=(long long)pNode;
						pNode=nNode;
					}
				}
				delete [] tmpTab;
			}
		};
		//	�����С
		inline void setSize(int hashSize)
		{
			if(this->tab==NULL)
				this->hashSize=hashSize;
		};
		//	����hash���С
		inline int getSize(){return this->hashSize;};
		//  ��������
		inline void clear()
		{
			if(tab)
			{
				HashNode * pNode,* nextNode;
				for(int i=0;i<this->hashSize;i++)
				{
					pNode=(HashNode *)tab[i];
					while(pNode)
					{
						HashNode *ln=(HashNode *)pNode->lnext;
						while(ln)
						{
							nextNode=(HashNode *)pNode->lnext;
							delete ln;
							ln=nextNode;
						}
						nextNode=(HashNode *)pNode->rnext;
						delete pNode;
						pNode=nextNode;
					}
				}
				delete [] tab;
			}
			tab=NULL;
			nodeNum=0;
			used=0;
		}
		//�Ƴ�һ���ؼ���
		inline bool remove(const KEYT &key)
		{
			if(tab==NULL)return false;
			unsigned int hashCode,hashCode2,hashCode3,curIndex;
			hashCode=HASHMATH_METHOD1(key);
			curIndex=hashCode%this->hashSize;
			HashNode * pNode=(HashNode *)tab[curIndex];
			if(pNode==0)return false;
			hashCode2=HASHMATH_METHOD2(key);
			hashCode3=HASHMATH_METHOD3(key);
			bool res=false;
			HashNode * priNode=NULL,nNode=NULL;
			while(pNode)
			{
				if(pNode->hashCode==hashCode && pNode->hashCode2==hashCode2 && pNode->hashCode3==hashCode3)
				{
					res=true;
					nodeNum--;
					if(priNode==NULL)
					{
						tab[curIndex]=pNode->rnext;
						if(tab[curIndex]==0)used--;
					}
					else
					{
						priNode->rnext=pNode->rnext;
					}
					nNode=(HashNode *)pNode->lnext;
					delete pNode;
					while(nNode)
					{
						pNode=(HashNode *)pNode->lnext;
						delete pNode;
						nNode=pNode;
					}
					return res;
				}
				else
				{
					priNode=pNode;
					pNode=(HashNode *)pNode->rnext;
				}				
			}
			return res;
		}

		//�Ƴ�һ���ؼ��ֶ�Ӧָ��ֵ
		inline bool remove(const KEYT &key,const VALUET &val)
		{
			if(tab==NULL)return false;
			unsigned int hashCode,hashCode2,hashCode3,curIndex;
			hashCode=HASHMATH_METHOD1(key);
			curIndex=hashCode%this->hashSize;
			HashNode * pNode=(HashNode *)tab[curIndex];
			if(pNode==0)return false;
			hashCode2=HASHMATH_METHOD2(key);
			hashCode3=HASHMATH_METHOD3(key);
			bool res=false;
			HashNode * priNode=NULL,*nNode=NULL;
			while(pNode)
			{
				if(pNode->hashCode==hashCode && pNode->hashCode2==hashCode2 && pNode->hashCode3==hashCode3)
				{
					if(val==pNode->val)
					{
						nodeNum--;
						if(priNode==NULL)
						{
							if(pNode->lnext)
							{
								tab[curIndex]=pNode->lnext;
								nNode=(HashNode *)pNode->lnext;
								nNode->rnext=pNode->rnext;
							}
							else
							{
								tab[curIndex]=pNode->rnext;
								if(tab[curIndex]==0)used--;
							}
						}
						else
						{
							if(pNode->lnext)
							{
								priNode->rnext=pNode->lnext;
								nNode=(HashNode *)pNode->lnext;
								nNode->rnext=pNode->rnext;
							}
							else
							{
								priNode->rnext=pNode->rnext;
							}
						}
						delete pNode;
						return true;
					}
					nNode=(HashNode *)pNode->lnext;
					while(nNode)
					{
						if(val==nNode->val)
						{
							pNode->lnext=nNode->lnext;
							delete nNode;
							return true;
						}
						pNode=nNode;
						pNode=(HashNode *)pNode->lnext;
					}
				}
				else
				{
					priNode=pNode;
					pNode=(HashNode *)pNode->rnext;
				}				
			}
			return res;
		}

		//	����������,����ֵ����
		inline VALUET &operator[](const KEYT &key)
		{
			if(tab==NULL)
			{
				if(this->hashSize==0)EXP("operator[]δ����hash��ʼ����С");
				try
				{
					tab=new long[this->hashSize];	//�����ռ�
					memset(tab,0,sizeof(long)*hashSize);
				}
				catch(...)
				{
					EXP("hash���ڴ�ռ����ʧ��");
				}
			}
			HashNode node(key);
			unsigned int curIndex=node->hashCode%this->hashSize;
			HashNode * pNode=(HashNode *)tab[curIndex];
			while(pNode)
			{
				if(pNode->hashCode==node->hashCode && pNode->hashCode2==node->hashCode2 && pNode->hashCode3==node->hashCode3)
				{
					return pNode->val;
				}
				pNode=(HashNode *)pNode->rnext;
			}
			pNode=new HashNode(key);
			pNode->rnext=tab[curIndex];
			tab[curIndex]=(long)(pNode);
			return pNode->val;
		};
		//	���ڴ����
		inline bool find(const KEYT &key,VALUET &val,long * exp=NULL)
		{
			if(tab==NULL)return false;
			unsigned int hashCode,hashCode2,hashCode3,curIndex;
			hashCode=HASHMATH_METHOD1(key);
			hashCode2=HASHMATH_METHOD2(key);
			hashCode3=HASHMATH_METHOD3(key);
			curIndex=hashCode%this->hashSize;
			HashNode * pNode=(HashNode *)tab[curIndex];
			while(pNode)
			{
				if(pNode->hashCode==hashCode && pNode->hashCode2==hashCode2 && pNode->hashCode3==hashCode3)
				{
					val=pNode->val;
					if(exp)*exp=pNode->lnext;
					return true;
				}
				pNode=(HashNode *)pNode->rnext;
			}
			return false;
		};
		inline bool next(VALUET &val,long &exp)
		{
			if(exp==0)return false;
			HashNode* pNode=(HashNode *)(exp);
			exp=pNode->lnext;
			val=pNode->val;
			return true;
		};
		inline bool findAll(const KEYT &key,Array<VALUET> &res)
		{
			res.clear();
			if(tab==NULL)return false;
			unsigned int hashCode,hashCode2,hashCode3,curIndex;
			hashCode=HASHMATH_METHOD1(key);
			hashCode2=HASHMATH_METHOD2(key);
			hashCode3=HASHMATH_METHOD3(key);
			curIndex=hashCode%this->hashSize;
			HashNode * pNode=(HashNode *)tab[curIndex];
			bool result=false;
			while(pNode)
			{
				if(pNode->hashCode==hashCode && pNode->hashCode2==hashCode2 && pNode->hashCode3==hashCode3)
				{
					while(pNode)
					{
						res.push_back(pNode->val);
						pNode=(HashNode)pNode->lnext;
					}
					return true;
				}
				pNode=(HashNode *)pNode->rnext;
			}
			return result;
		};
		inline bool update(const KEYT &key,const VALUET &oldVal,const VALUET &newVal,long *exp=NULL)
		{
			if(tab==NULL)return false;
			unsigned int hashCode,hashCode2,hashCode3,curIndex;
			hashCode=HASHMATH_METHOD1(key);
			curIndex=hashCode%this->hashSize;
			HashNode * pNode=(HashNode *)tab[curIndex];
			if(pNode==NULL)return false;
			hashCode2=HASHMATH_METHOD2(key);
			hashCode3=HASHMATH_METHOD3(key);
			while(pNode)
			{
				if(pNode->hashCode==hashCode && pNode->hashCode2==hashCode2 && pNode->hashCode3==hashCode3)
				{
					while(pNode)
					{
						if(pNode->val==oldVal)
						{
							pNode->val=newVal;
							if(exp)*exp=(long)pNode;
							return true;
						}
						pNode=(HashNode *)pNode->lnext;
					}
					return false;
				}
				pNode=(HashNode *)pNode->rnext;
			}
			return false;
		};
		inline bool findLastNode(const KEYT &key,VALUET &val,VALUET * * pval=NULL)
		{
			if(tab==NULL)return false;
			unsigned int hashCode,hashCode2,hashCode3,curIndex;
			hashCode=HASHMATH_METHOD1(key);
			curIndex=hashCode%this->pcfmInfo->hashSize;
			HashNode * pNode=(HashNode *)tab[curIndex];
			if(pNode==NULL)return false;
			hashCode2=HASHMATH_METHOD2(key);
			hashCode3=HASHMATH_METHOD3(key);
			bool res=false;
			while(pNode)
			{
				if(pNode->hashCode==hashCode && pNode->hashCode2==hashCode2 && pNode->hashCode3==hashCode3)
				{
					val=pNode->val;
					if(pval)*pval=&(pNode->val);
					return true;
				}
				pNode=(HashNode *)(pNode->rnext);
			}
			return res;
		};
		inline VALUET * findLastNode(const KEYT &key)
		{
			if(tab==NULL)return false;
			unsigned int hashCode,hashCode2,hashCode3,curIndex;
			hashCode=HASHMATH_METHOD1(key);
			curIndex=hashCode%this->pcfmInfo->hashSize;
			HashNode * pNode=(HashNode *)tab[curIndex];
			if(pNode==NULL)return NULL;
			hashCode2=HASHMATH_METHOD2(key);
			hashCode3=HASHMATH_METHOD3(key);
			VALUET * pval=NULL;
			while(pNode)
			{
				if(pNode->hashCode==hashCode && pNode->hashCode2==hashCode2 && pNode->hashCode3==hashCode3)
				{
					pval=&(pNode->val);
				}
				pNode=(HashNode *)(pNode->rnext);
			}
			return pval;
		};
	//��֤һ��KEY�Ƿ����
		inline bool contain(const KEYT &key)
		{
			if(tab==NULL)return false;
			unsigned int hashCode,hashCode2,hashCode3,curIndex;
			hashCode=HASHMATH_METHOD1(key);
			hashCode2=HASHMATH_METHOD2(key);
			hashCode3=HASHMATH_METHOD3(key);
			curIndex=hashCode%this->hashSize;
			HashNode * pNode=(HashNode *)tab[curIndex];
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
		//	���ļ�����key
		inline bool find(FILE *pkeyFile,const KEYT &key,VALUET &val)
		{
			return find(pkeyFile,key,val,this->hashSize);
		};
		//     ���ļ�����  expAddr:��һλ��
		inline static bool find(FILE *pkeyFile,const KEYT &key,VALUET &val,int hashSize,long * expAddr=NULL)
		{
			if(!pkeyFile)return false;
			unsigned int hashCode,hashCode2,hashCode3,curIndex;
			hashCode=HASHMATH_METHOD1(key);
			hashCode2=HASHMATH_METHOD2(key);
			hashCode3=HASHMATH_METHOD3(key);
			HashNode tempNode;
			curIndex=hashCode%hashSize;
			long curPos=sizeof(long)*curIndex;
			long addres=0;
			fseek(pkeyFile, curPos, SEEK_SET);
			int len= fread(&addres,1,sizeof(long),pkeyFile);//return false;
			assert(len==sizeof(long));
			while(addres)
			{
				fseek(pkeyFile, addres, SEEK_SET);
				len= fread(&tempNode,NodeSize,1,pkeyFile);//return false;
				assert(len==1);
				if(tempNode.hashCode==hashCode && tempNode.hashCode2==hashCode2 && tempNode.hashCode3==hashCode3)
				{
					val=tempNode.val;
					if(expAddr)*expAddr=tempNode.lnext;
					return true;
				}
				addres=tempNode.rnext;
			}
			return false;
		};
		inline static bool findAll(FILE *pkeyFile,const KEYT &key,Array<VALUET> &res,int hashSize)
		{
			res.clear();
			if(!pkeyFile)return false;
			unsigned int hashCode,hashCode2,hashCode3,curIndex;
			hashCode=HASHMATH_METHOD1(key);
			hashCode2=HASHMATH_METHOD2(key);
			hashCode3=HASHMATH_METHOD3(key);
			HashNode tempNode;
			curIndex=hashCode%hashSize;
 			long curPos=sizeof(long)*curIndex;
			long addres=0;
			fseek(pkeyFile, curPos, SEEK_SET);
			int len= fread(&addres,1,sizeof(long),pkeyFile);//return false;
			assert(len==sizeof(long));
			while(addres)
			{
				fseek(pkeyFile, addres, SEEK_SET);
				len= fread(&tempNode,1,NodeSize,pkeyFile);//return false;
				assert(len==NodeSize);
				if(tempNode.hashCode==hashCode && tempNode.hashCode2==hashCode2 && tempNode.hashCode3==hashCode3)
				{
					res.push_back(tempNode.val);
					addres=tempNode.lnext;
					while(addres)
					{
						fseek(pkeyFile, addres, SEEK_SET);
						len= fread(&tempNode,1,NodeSize,pkeyFile);//return false;
						assert(len==NodeSize);
						res.push_back(tempNode.val);
						addres=tempNode.lnext;
					}
					return true;
				}
				addres=tempNode.rnext;
			}
			return res.size()>0;
		};
		//expAddr;��ǰ�ڵ�λ��
		inline static bool findLastNode(FILE *pkeyFile,const KEYT &key,VALUET &val,int hashSize,long * expAddr=NULL)
		{
			if(!pkeyFile)return false;
			unsigned int hashCode,hashCode2,hashCode3,curIndex;
			hashCode=HASHMATH_METHOD1(key);
			hashCode2=HASHMATH_METHOD2(key);
			hashCode3=HASHMATH_METHOD3(key);
			HashNode tempNode;
			curIndex=hashCode%hashSize;
			long curPos=sizeof(long)*curIndex;
			long addres=0;
			fseek(pkeyFile, curPos, SEEK_SET);
			int len= fread(&addres,1,sizeof(long),pkeyFile);//return false;
			assert(len==sizeof(long));
			while(addres)
			{
				fseek(pkeyFile, addres, SEEK_SET);
				len= fread(&tempNode,1,NodeSize,pkeyFile);//return false;
				assert(len==NodeSize);
				if(tempNode.hashCode==hashCode && tempNode.hashCode2==hashCode2 && tempNode.hashCode3==hashCode3)
				{
					val=tempNode.val;
					if(expAddr)*expAddr=addres;
					return true;
				}
				addres=tempNode.rnext;
			}
			return false;
		};
		inline static bool next(FILE *pkeyFile,VALUET &val,long & addres)
		{
			if(addres)return false;
			HashNode tempNode;
			fseek(pkeyFile, addres, SEEK_SET);
			int len= fread(&tempNode,1,NodeSize,pkeyFile);//return false;
			assert(len==NodeSize);
			addres=tempNode.next;
			val=tempNode.val;
			return true;
		};
		inline static bool update(FILE *pkeyFile,const KEYT &key,const VALUET &val,int hashSize)
		{
			if(!pkeyFile)return false;
			unsigned int hashCode,hashCode2,hashCode3,curIndex;
			hashCode=HASHMATH_METHOD1(key);
			hashCode2=HASHMATH_METHOD2(key);
			hashCode3=HASHMATH_METHOD3(key);
			HashNode tempNode;
			curIndex=hashCode%hashSize;
 			long curPos=sizeof(long)*curIndex;
			long addres=0;
			fseek(pkeyFile, curPos, SEEK_SET);
			int len= fread(&addres,1,sizeof(long),pkeyFile);//return false;
			assert(len==sizeof(long));
			while(addres)
			{
				fseek(pkeyFile, addres, SEEK_SET);
				len= fread(&tempNode,1,NodeSize,pkeyFile);//return false;
				assert(len==NodeSize);
				if(tempNode.hashCode==hashCode && tempNode.hashCode2==hashCode2 && tempNode.hashCode3==hashCode3)
				{
					tempNode.val=val;
					fseek(pkeyFile, addres, SEEK_SET);
					len= fwrite(&tempNode,1,NodeSize,pkeyFile);//return false;
					assert(len==NodeSize);
					return true;
				}
				addres=tempNode.rnext;
			}
			return false;
		};
		inline static bool update(FILE *pkeyFile,const KEYT &key,const VALUET &oldVal,const VALUET &newVal,int hashSize)
		{
			if(!pkeyFile)return false;
			unsigned int hashCode,hashCode2,hashCode3,curIndex;
			hashCode=HASHMATH_METHOD1(key);
			hashCode2=HASHMATH_METHOD2(key);
			hashCode3=HASHMATH_METHOD3(key);
			HashNode tempNode;
			curIndex=hashCode%hashSize;
 			long curPos=sizeof(long)*curIndex;
			long addres=0;
			fseek(pkeyFile, curPos, SEEK_SET);
			int len= fread(&addres,1,sizeof(long),pkeyFile);//return false;
			assert(len==sizeof(long));
			while(addres)
			{
				fseek(pkeyFile, addres, SEEK_SET);
				len= fread(&tempNode,1,NodeSize,pkeyFile);//return false;
				assert(len==NodeSize);
				if(tempNode.hashCode==hashCode && tempNode.hashCode2==hashCode2 && tempNode.hashCode3==hashCode3)
				{
					while(true)
					{
						if(oldVal==tempNode.val)
						{
							tempNode.val=newVal;
							fseek(pkeyFile, addres, SEEK_SET);
							len= fwrite(&tempNode,1,NodeSize,pkeyFile);//return false;
							assert(len==NodeSize);
							addres=tempNode.lnext;
							return true;
						}
						addres=tempNode.lnext;
						if(addres)break;
						fseek(pkeyFile, addres, SEEK_SET);
						len= fread(&tempNode,1,NodeSize,pkeyFile);//return false;
					}
					return false;
				}
				addres=tempNode.rnext;
			}
			return false;
		};
		inline static bool updateVal(FILE *pkeyFile,const VALUET &val,long long nodePos)
		{
			if(!pkeyFile)return false;
			fseek(pkeyFile, nodePos, SEEK_SET);
			HashNode node;
			int len=fread(&node,NodeSize,1,pkeyFile);
			assert(len==1);
			node.val=val;
			fseek(pkeyFile, nodePos, SEEK_SET);
			len=fwrite(&node,1,NodeSize,pkeyFile);
			assert(len==NodeSize);
			return true;
		};
		inline static bool remove(FILE *pkeyFile,const KEYT &key,const int & hashSize)
		{
			if(!pkeyFile)return false;
			unsigned int hashCode,hashCode2,hashCode3,curIndex;
			hashCode=HASHMATH_METHOD1(key);
			hashCode2=HASHMATH_METHOD2(key);
			hashCode3=HASHMATH_METHOD3(key);
			HashNode tempNode,empty;
			curIndex=hashCode%hashSize;
			long curPos=sizeof(long)*curIndex;
			long addres=0;
			fseek(pkeyFile, curPos, SEEK_SET);
			int len= fread(&addres,1,sizeof(long),pkeyFile);
			assert(len==sizeof(long));
			long priPos=curPos;
			while(addres)
			{
				fseek(pkeyFile, addres, SEEK_SET);
				len= fread(&tempNode,NodeSize,1,pkeyFile);
				assert(len==1);
				if(tempNode.hashCode==hashCode && tempNode.hashCode2==hashCode2 && tempNode.hashCode3==hashCode3)
				{
					fseek(pkeyFile, addres, SEEK_SET);
					len= fwrite(&empty,1,NodeSize,pkeyFile);
					if(priPos==curPos)
					{
						priPos=tempNode.rnext;
						fseek(pkeyFile, curPos, SEEK_SET);
						len= fwrite(&priPos,1,sizeof(long),pkeyFile);
					}
					else
					{
						addres=tempNode.rnext;
						fseek(pkeyFile, priPos, SEEK_SET);
						len= fread(&tempNode,NodeSize,1,pkeyFile);
						tempNode.rnext=addres;
						fseek(pkeyFile, priPos, SEEK_SET);
						len= fwrite(&tempNode,1,NodeSize,pkeyFile);
					}
					addres=tempNode.lnext;
					while(addres)
					{
						fseek(pkeyFile, addres, SEEK_SET);
						len= fwrite(&empty,1,NodeSize,pkeyFile);
					}
					return true;
				}
				priPos=addres;
				addres=tempNode.rnext;
			}
			return false;
		};
		inline static bool remove(FILE *pkeyFile,const KEYT &key,const VALUET &val,const int & hashSize)
		{
			if(!pkeyFile)return false;
			unsigned int hashCode,hashCode2,hashCode3,curIndex;
			hashCode=HASHMATH_METHOD1(key);
			hashCode2=HASHMATH_METHOD2(key);
			hashCode3=HASHMATH_METHOD3(key);
			HashNode tempNode,empty;
			curIndex=hashCode%hashSize;
			long curPos=sizeof(long)*curIndex;
			long addres=0;
			fseek(pkeyFile, curPos, SEEK_SET);
			int len= fread(&addres,1,sizeof(long),pkeyFile);
			assert(len==sizeof(long));
			long priPos=curPos;
			while(addres)
			{
				fseek(pkeyFile, addres, SEEK_SET);
				len= fread(&tempNode,NodeSize,1,pkeyFile);
				assert(len==1);
				if(tempNode.hashCode==hashCode && tempNode.hashCode2==hashCode2 && tempNode.hashCode3==hashCode3)
				{
					while(addres)
					{
						fseek(pkeyFile, addres, SEEK_SET);
						len= fread(&tempNode,NodeSize,1,pkeyFile);
						if(tempNode.val==val)
						{
							fseek(pkeyFile, addres, SEEK_SET);
							len= fwrite(&empty,1,NodeSize,pkeyFile);
							if(priPos==curPos)
							{
								if(tempNode.lnext)
									priPos=tempNode.lnext;
								else
									priPos=tempNode.rnext;

								fseek(pkeyFile, curPos, SEEK_SET);
								len= fwrite(&priPos,1,sizeof(long),pkeyFile);
							}
							else
							{
								if(tempNode.lnext)
									addres=tempNode.lnext;
								else
									addres=tempNode.rnext;
								fseek(pkeyFile, priPos, SEEK_SET);
								len= fread(&tempNode,NodeSize,1,pkeyFile);
								if(tempNode.hashCode==hashCode && tempNode.hashCode2==hashCode2 && tempNode.hashCode3==hashCode3)
								{
									tempNode.lnext=addres;
									fseek(pkeyFile, priPos, SEEK_SET);
									len= fwrite(&tempNode,1,NodeSize,pkeyFile);	//	�޸���һ�ڵ�
								}
								else
								{
									tempNode.rnext=addres;
									fseek(pkeyFile, priPos, SEEK_SET);
									len= fwrite(&tempNode,1,NodeSize,pkeyFile);	//	�޸���һ�ڵ�

									fseek(pkeyFile, addres, SEEK_SET);			//	�޸���һ�ڵ�ָ��
									len= fread(&empty,NodeSize,1,pkeyFile);
									empty.rnext=tempNode.rnext;
									fseek(pkeyFile, addres, SEEK_SET);
									len= fwrite(&empty,1,NodeSize,pkeyFile);
								}
							} 
							return true;
						}
						priPos=addres;
						addres=tempNode.lnext;
					}
					return false;
				}
				priPos=addres;
				addres=tempNode.rnext;
			}
			return false;
		};
		//	��MulHashTable2����д���ļ�,д����ɾ��MulHashTable2 �е��ڴ�����
		inline void writeFile(FILE *pkeyFile,Array<int> *distributing=NULL,int fixedSize=0)					//д���ļ�
		{
			if(tab==NULL)
			{
				if(this->hashSize==0)EXP("writeFileδ����hash��ʼ����С");
				try
				{
					tab=new long[this->hashSize];	//����洢�ռ�
					memset(tab,0,sizeof(long)*hashSize);
				}
				catch(...)
				{
					EXP("hash���ڴ�ռ����ʧ��");
				}
			}
			fseek(pkeyFile,hashSize*sizeof(long)-1+fixedSize,SEEK_SET);
			int len=fwrite("\0",1,1,pkeyFile);
			assert(len==1);
			HashNode * pNode=NULL,*nNode=NULL,*lNode=NULL,*rNode=NULL;
			for(int i=0;i<this->hashSize;i++)
			{
				if(tab[i]==0)continue;
				fseek(pkeyFile,0,SEEK_END);
				long fileSize=ftell(pkeyFile);
				fseek(pkeyFile,i*sizeof(long)+fixedSize,SEEK_SET);
				len=fwrite(&fileSize,sizeof(long),1,pkeyFile);
				assert(len==1);
				pNode=(HashNode *)tab[i];
				int depth=0;
				while(pNode)
				{
					if(distributing)(*distributing)[depth++]++;
					nNode=(HashNode *)pNode->rnext;
					fseek(pkeyFile,0,SEEK_END);
					fileSize=ftell(pkeyFile);
					long pPos=fileSize;
					rNode=pNode;
					while(rNode)
					{
						lNode=(HashNode *)rNode->lnext;
						fseek(pkeyFile,0,SEEK_END);
						fileSize=ftell(pkeyFile);
						if(lNode)rNode->lnext=fileSize+NodeSize;
						len=fwrite(rNode,1,NodeSize,pkeyFile);
						assert(len==NodeSize);
						delete rNode;
						rNode=lNode;
					}
					fseek(pkeyFile,0,SEEK_END);
					fileSize=ftell(pkeyFile);
					pNode->rnext=fileSize;
					fseek(pkeyFile,pPos,SEEK_SET);
					len=fwrite(pNode,1,NodeSize,pkeyFile);
					delete pNode;
					pNode=nNode;
				}
			}
			delete [] tab;
			tab=NULL;
			fflush(pkeyFile);
		};
		//     ֱ�ӽ�KEYд���ļ�
		inline static int writeFile(FILE *pkeyFile,const KEYT &key,const VALUET &val,int hashSize,int fixedSize=0)
		{
			HashNode node(key,val);
			return writeFile(pkeyFile,node,hashSize,fixedSize);
		}
		//	ֱ�ӽ�KEYд���ļ�overlay:��ֵʱ�Ƿ񸲸�
		inline static int writeFile(FILE *pkeyFile,HashNode &node,int hashSize,int fixedSize=0)
		{
			if(!pkeyFile)EXP("key�ļ�ָ��Ϊ��.");
			fseek(pkeyFile, 0, SEEK_END);//���ж��Ƿ��Ѿ���ʼ���ļ�
			long fileSize=ftell(pkeyFile);
			long fsize=sizeof(long) * hashSize+fixedSize;
			if(fileSize<fsize)
			{
				fseek(pkeyFile, fsize-1, SEEK_SET);
				fwrite("\0",1,1,pkeyFile);
				fileSize=ftell(pkeyFile);
				fseek(pkeyFile, 0, SEEK_SET);
			}
			if(node.hashCode==0){return -1;}
			unsigned int curIndex=node.hashCode % hashSize;					//ȡ����λ��
			long curPos=sizeof(long)*curIndex+fixedSize;
			long addres=0;
			fseek(pkeyFile, curPos, SEEK_SET);
			int len= fread(&addres,1,sizeof(long),pkeyFile);
			assert(len==sizeof(long));
			node.rnext=addres;
			long pos=addres;
			HashNode tnode;
			long priPos=curPos;
			while(pos)
			{
				fseek(pkeyFile, pos, SEEK_SET);
				len= fread(&tnode,1,NodeSize,pkeyFile);
				if(node.hashCode==tnode.hashCode && node.hashCode2==tnode.hashCode2 && node.hashCode3==tnode.hashCode3)
				{
					node.lnext=pos;
					node.rnext=tnode.rnext;
					if(priPos==curPos)
					{
						fseek(pkeyFile, curPos, SEEK_SET);
						len=fwrite(&fileSize,sizeof(long),1,pkeyFile);
						fseek(pkeyFile, 0, SEEK_END);
						len=fwrite(&node,1,NodeSize,pkeyFile);
						assert(len==NodeSize);
					}
					else
					{
						fseek(pkeyFile, priPos, SEEK_SET);
						len= fread(&tnode,NodeSize,1,pkeyFile);
						tnode.rnext=fileSize;
						fseek(pkeyFile, priPos, SEEK_SET);
						len= fwrite(&tnode,1,NodeSize,pkeyFile);	//	�޸���һ�ڵ�
						fseek(pkeyFile, 0, SEEK_END);
						len=fwrite(&node,1,NodeSize,pkeyFile);
						assert(len==NodeSize);
					}
					return 2;
				}
				priPos=pos;
				pos=tnode.rnext;
			}  
			fseek(pkeyFile, 0, SEEK_END);
			len=fwrite(&node,1,NodeSize,pkeyFile);
			assert(len==NodeSize);
			fseek(pkeyFile, curPos, SEEK_SET);
			len=fwrite(&fileSize,sizeof(long),1,pkeyFile);
			assert(len==1);
			return 1;
		};

		//	��ȡ��hash�ڵ��ָ��
		inline static HashNode * getHashNode(const KEYT &key,const VALUET &val)
		{
			HashNode *node=new HashNode(key,val);
			return node;
		};
		//	��ȡ��hash�ڵ��ָ��
		inline static HashNode * getHashNode(const KEYT &key)
		{
			HashNode *node=new HashNode(key);
			return node;
		};
		//	����hash��
		inline void analyse()
		{
			Array<int> distributing;
			if(tab)
			{
				HashNode * pNode,* nextNode;
				for(int i=0;i<this->hashSize;i++)
				{
					pNode=(HashNode *)tab[i];
					int depth=0;
					while(pNode)
					{
						distributing[depth++]++;
						pNode=(HashNode *)nextNode->next;
					}
				}
				cout<<"hash�������: "<< distributing.size() <<endl;
				int countPos=0;
				for(int i=0;i<distributing.size();i++)
				{
					countPos+=distributing[i];
				}
				for(int i=0;i<distributing.size();i++)
				{
					cout<<"hash "<<i<<" �ζ�λ��: "<< distributing[i] <<" ռ��: "<< (double)distributing[i]/countPos <<endl;
				}
				cout<<"hash��ʹ����: "<< (double)distributing[1]*100/this->hashSize <<" ==== "<< used/hashSize<<endl;
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
			if(tab)
			{
				HashNode * pNode,*nextNode;
				for(int i=0;i<this->hashSize;i++)
				{
					int depth2=0;
					pNode=(HashNode *)tab[i];
					while(pNode)
					{
						depth2++;
						nextNode=(HashNode *)pNode->next; 
						if(depth<depth2)
							depth=depth2;
					}
				}
			}
			return depth;
		};
		static const long long NodeSize;//=sizeof(NODE);
		static const int hashType;
	};
	template <class KEYT,class VALUET> const long long MulHashTable2<KEYT,VALUET>::NodeSize=sizeof(MulHashTable2<KEYT,VALUET>::HashNode);
	template <class KEYT,class VALUET> const int  MulHashTable2<KEYT,VALUET>::hashType=23;

}
#endif

