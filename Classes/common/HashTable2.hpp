// ==============================================================
//progame      Common:HashTable2 
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

#ifndef __Common_HashTable2_H__
#define __Common_HashTable2_H__

namespace Common
{
  
	static const int primeNumbers[] = {
		17,             /* 0 */
		37,             /* 1 */
		79,             /* 2 */
		163,            /* 3 */
		331,            /* 4 */
		673,            /* 5 */
		1361,           /* 6 */
		2729,           /* 7 */
		5471,           /* 8 */
		10949,          /* 9 */
		21911,          /* 10 */
		43853,          /* 11 */
		87719,          /* 12 */
		175447,         /* 13 */
		350899,         /* 14 */
		701819,         /* 15 */
		1403641,        /* 16 */
		2807303,        /* 17 */
		5614657,        /* 18 */
		11229331,       /* 19 */
		22458671,       /* 20 */
		44917381,       /* 21 */
		89834777,       /* 22 */
		179669557,      /* 23 */
		359339171,      /* 24 */
		718678369,      /* 25 */
		1437356741,     /* 26 */
		2147483647      /* 27 (largest signed int prime) */
	};

#define itemsof(array) (sizeof(array)/sizeof*(array))

	template <class KEYT,class VALUET> class HashTable2
	{
	public:
		struct HashNode
		{
		public:
			unsigned long next;							//���� ��һ��λ��
			unsigned int hashCode;						//hashֵ
			unsigned int hashCode2;						//hashֵ  �����ַ���У��
			VALUET  val;								//��ǰ�ڵ�����λ��
			unsigned int hashCode3;						//hashֵ  �����ַ���У��
			HashNode():hashCode(0),next(0),val(VALUET()),hashCode2(0),hashCode3(0){};
			HashNode(const KEYT &key):next(0),val(VALUET())
			{
				hashCode=HASHMATH_METHOD1(key);
				hashCode2=HASHMATH_METHOD2(key);
				hashCode3=HASHMATH_METHOD3(key);
			};
			HashNode(const KEYT &key,const VALUET &val):next(0),val(val)
			{
				hashCode=HASHMATH_METHOD1(key);
				hashCode2=HASHMATH_METHOD2(key);
				hashCode3=HASHMATH_METHOD3(key);
			};
		};
		int hashSize;	//	Ͱ��С fixSize= hashSize * sizeof(int *)
		int used;		//	Ͱʹ�ô�С,����������
		int nodeNum;	//	autoRise && nodeNum>hashSize && used*1.4>hashSize
		bool mulVal;	//	�Ƿ�洢��ֵ
		bool autoRise;	//	�Ƿ��Զ�����hash��С
		long * tab ;//hdidx;
	public:
		HashTable2(int _size=17):hashSize(_size),nodeNum(0),used(0),autoRise(false),mulVal(false),tab(NULL){};
		~HashTable2(){clear();};
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
			if(mulVal)	//	��ֵ���ж��Ƿ��ظ�
			{
				node->next = tab[curIndex];
				tab[curIndex]=(long long)node;
				if(node->next==0)
					this->used++;
				nodeNum++;
				return 1;
			}
			else
			{
				HashNode * pNode=(HashNode *)tab[curIndex];
				while(pNode)
				{
					if(pNode->hashCode==node->hashCode && pNode->hashCode2==node->hashCode2 && pNode->hashCode3==node->hashCode3)
					{
						delete node;
						return 2;
					}
					pNode=(HashNode *)pNode->next;;
				}
				node->next = tab[curIndex];
				tab[curIndex]=(long long)node;
				if(node->next==0)
					this->used++;
				nodeNum++;
				return 1;
			}
		};
		//  ��ӽڵ㵽HashTable2��
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
						HashNode * nNode=(HashNode *)pNode->next;
						unsigned h = pNode->hashCode % hashSize;
						if(pNode->next!=tab[h])
						{
							pNode->next=tab[h];
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
						nextNode=(HashNode *)pNode->next;
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
			HashNode * priNode=NULL,*nNode=NULL;
			while(pNode)
			{
				if(pNode->hashCode==hashCode && pNode->hashCode2==hashCode2 && pNode->hashCode3==hashCode3)
				{
					res=true;
					nodeNum--;
					if(tab[curIndex]==(long)pNode && priNode==NULL)
					{
						tab[curIndex]=pNode->next;
						if(tab[curIndex]==0)used--;
					}
					else
					{
						priNode->next=pNode->next;
					}
					nNode=(HashNode *)pNode->next;
					delete pNode;
					pNode=nNode;
					if(this->mulVal==false)
						return res;
				}
				else
				{
					priNode=pNode;
					pNode=(HashNode *)pNode->next;
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
				if(pNode->hashCode==hashCode && pNode->hashCode2==hashCode2 && pNode->hashCode3==hashCode3 && val==pNode->val)
				{
					res=true;
					nodeNum--;
					if(tab[curIndex]==(long)pNode && priNode==NULL)
					{
						tab[curIndex]=pNode->next;
						if(tab[curIndex]==0)used--;
					}
					else
					{
						priNode->next=pNode->next;
					}
					nNode=(HashNode *)pNode->next;
					delete pNode;
					pNode=nNode;
					if(this->mulVal==false)
						return res;
				}
				else
				{
					priNode=pNode;
					pNode=(HashNode *)pNode->next;
				}				
			}
			return res;
			//if(pNode->hashCode==hashCode && pNode->hashCode2==hashCode2 && pNode->hashCode3==hashCode3)
			//{
			//	if(val==pNode->val)
			//	{
			//		tab[curIndex]=pNode->next;
			//		delete pNode;
			//		nodeNum--;
			//		if(tab[curIndex]==0)used--;
			//		return true;
			//	}
			//}
			//HashNode * priNode=pNode;
			//pNode=(HashNode *)pNode->next;
			//while(pNode)
			//{
			//	if(pNode->hashCode==hashCode && pNode->hashCode2==hashCode2 && pNode->hashCode3==hashCode3)
			//	{
			//		if(val==pNode->val)
			//		{
			//			priNode->next=pNode->next;
			//			delete pNode;
			//			nodeNum--;
			//			return true;
			//		}
			//	}
			//	priNode=pNode;
			//	pNode=(HashNode *)pNode->next;
			//}
			//return false;
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
			HashNode *node=getHashNode(key);
			unsigned int curIndex=node->hashCode%this->hashSize;
			HashNode * pNode=(HashNode *)tab[curIndex];
			while(pNode)
			{
				if(pNode->hashCode==node->hashCode && pNode->hashCode2==node->hashCode2 && pNode->hashCode3==node->hashCode3)
				{
					delete node;
					return pNode->val;
				}
				pNode=(HashNode *)pNode->next;
			}
			node->next=tab[curIndex];
			tab[curIndex]=(long long)node;
			return node->val;
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
					if(exp)*exp=pNode->next;
					return true;
				}
				pNode=(HashNode *)pNode->next;
			}
			return false;
		};
		inline bool next(const KEYT &key,VALUET &val,long &exp)
		{
			if(exp==0)return false;
			unsigned int hashCode=HASHMATH_METHOD1(key);
			unsigned int hashCode2=HASHMATH_METHOD2(key);
			unsigned int hashCode3=HASHMATH_METHOD3(key);
			HashNode* pNode=(HashNode *)(exp);
			while(pNode)
			{
				exp=pNode->next;
				if(pNode->hashCode==hashCode && pNode->hashCode2==hashCode2 && pNode->hashCode3==hashCode3)
				{
					val=pNode->val;
					return true;
				}
				pNode=(HashNode *)(exp);
			}
			return false;
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
					res.push_back(pNode->val);
					result= true;
				}
				pNode=(HashNode *)pNode->next;
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
					if(pNode->val==oldVal)
					{
						pNode->val=newVal;
						if(exp)*exp=(long)pNode;
						return true;
					}
				}
				pNode=(HashNode *)pNode->next;
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
				pNode=(HashNode *)(pNode->next);
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
				pNode=(HashNode *)(pNode->next);
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
				pNode=(HashNode *)pNode->next;
			}
			return false;
		};
		//
		// ժҪ:
		//	���ļ�����key
		//
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
				addres=tempNode.next;
				if(tempNode.hashCode==hashCode && tempNode.hashCode2==hashCode2 && tempNode.hashCode3==hashCode3)
				{
					val=tempNode.val;
					if(expAddr)*expAddr=addres;
					return true;
				}
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
				}
				addres=tempNode.next;
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
				addres=tempNode.next;
			}
			return false;
		};
		inline static bool next(FILE *pkeyFile,const KEYT &key,VALUET &val,long & addres)
		{
			unsigned int hashCode,hashCode2,hashCode3;
			HashNode tempNode;
			while(addres)
			{
				fseek(pkeyFile, addres, SEEK_SET);
				int len= fread(&tempNode,1,NodeSize,pkeyFile);//return false;
				assert(len==NodeSize);
				addres=tempNode.next;
				if(tempNode.hashCode==hashCode && tempNode.hashCode2==hashCode2 && tempNode.hashCode3==hashCode3)
				{
					val=tempNode.val;
					return true;
				}
			}
			return false;
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
				addres=tempNode.next;
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
				if(tempNode.hashCode==hashCode && tempNode.hashCode2==hashCode2 && tempNode.hashCode3==hashCode3 && oldVal==tempNode.val )
				{
					tempNode.val=newVal;
					fseek(pkeyFile, addres, SEEK_SET);
					len= fwrite(&tempNode,1,NodeSize,pkeyFile);//return false;
					assert(len==NodeSize);
					return true;
				}
				addres=tempNode.next;
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
						priPos=tempNode.next;
						fseek(pkeyFile, curPos, SEEK_SET);
						len= fwrite(&priPos,1,sizeof(long),pkeyFile);
					}
					else
					{
						addres=tempNode.next;
						fseek(pkeyFile, priPos, SEEK_SET);
						len= fread(&tempNode,NodeSize,1,pkeyFile);
						tempNode.next=addres;
						fseek(pkeyFile, priPos, SEEK_SET);
						len= fwrite(&tempNode,1,NodeSize,pkeyFile);
					}
					return true;
				}
				priPos=addres;
				addres=tempNode.next;
			}
			return false;
		};
		//	��HashTable2����д���ļ�,д����ɾ��HashTable2 �е��ڴ�����
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
			HashNode * pNode=NULL,*nNode=NULL;
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
					nNode=(HashNode *)pNode->next;
					fseek(pkeyFile,0,SEEK_END);
					fileSize=ftell(pkeyFile);
					if(nNode)
						pNode->next=fileSize+NodeSize;
					len=fwrite(pNode,1,NodeSize,pkeyFile);
					assert(len==NodeSize);
					delete pNode;
					pNode=nNode;
				}
			}
			delete [] tab;
			tab=NULL;
			fflush(pkeyFile);
		};
		//     ֱ�ӽ�KEYд���ļ�
		inline static int writeFile(FILE *pkeyFile,const KEYT &key,const VALUET &val,int hashSize,const bool & muVal=false,const bool &overlay=false,int fixedSize=0)
		{
			HashNode node(key,val);
			return writeFile(pkeyFile,node,hashSize,muVal,overlay,fixedSize);
		}
		//	ֱ�ӽ�KEYд���ļ�overlay:��ֵʱ�Ƿ񸲸�
		inline static int writeFile(FILE *pkeyFile,HashNode &node,int hashSize,const bool & mulVal=false,const bool &overlay=false,int fixedSize=0)
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
			int addres=0;
			fseek(pkeyFile, curPos, SEEK_SET);
			int len= fread(&addres,1,sizeof(long),pkeyFile);//return false;
			assert(len==sizeof(long));
			node.next=addres;
			if(mulVal)	//	��ֵ��ֱ�����
			{
				fseek(pkeyFile, 0, SEEK_END);
				len=fwrite(&node,1,NodeSize,pkeyFile);
				assert(len==NodeSize);
				addres=fileSize;
				fseek(pkeyFile, curPos, SEEK_SET);
				len=fwrite(&addres,sizeof(long),1,pkeyFile);
				assert(len==1);
				return 1;
			}
			else
			{
				long pos=addres;
				HashNode tnode;
				while(pos)
				{
					fseek(pkeyFile, pos, SEEK_SET);
					len= fread(&tnode,1,NodeSize,pkeyFile);
					if(node.hashCode==tnode.hashCode && node.hashCode2==tnode.hashCode2 && node.hashCode3==tnode.hashCode3)
					{
						if(overlay)
						{
							tnode.val=node.val;
							fseek(pkeyFile, pos, SEEK_SET);
							len= fwrite(&tnode,1,NodeSize,pkeyFile);
							return 2;
						}
						return 0;
					}
					pos=tnode.next;
				}  
				fseek(pkeyFile, 0, SEEK_END);
				len=fwrite(&node,1,NodeSize,pkeyFile);
				assert(len==NodeSize);
				addres=fileSize;
				fseek(pkeyFile, curPos, SEEK_SET);
				len=fwrite(&addres,sizeof(long),1,pkeyFile);
				assert(len==1);
				return 1;				
			}
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
	template <class KEYT,class VALUET> const long long HashTable2<KEYT,VALUET>::NodeSize=sizeof(HashTable2<KEYT,VALUET>::HashNode);
	template <class KEYT,class VALUET> const int HashTable2<KEYT,VALUET>::hashType=21;


}
#endif

