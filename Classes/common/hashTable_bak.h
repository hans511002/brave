// ==============================================================
//progame      Common:hashTable 
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

#ifndef __Common_hashTable__
#define __Common_hashTable__
namespace Common
{
#ifndef EXP
#define EXP(msg) {cout<<__FILE__<<": error "<< " on line "<< __LINE__<<endl ;throw(string(msg));}
#endif
#ifndef ONE_READ_COUNT
#define ONE_READ_COUNT 5			//一次读取记录数
#endif
#ifndef HASH_CHECK_LEVEL
	#define HASH_CHECK_LEVEL 3			// hashcode 校验次数 HASH_CHECK_LEVEL=0 当为数字时不使用hash 但是必须保证KEYT在unsigned int大小内
#endif

#ifdef HASHMATH_METHOD1
#undef HASHMATH_METHOD1
#endif
#ifdef HASHMATH_METHOD2
#undef HASHMATH_METHOD2
#endif
#ifdef HASHMATH_METHOD2
#undef HASHMATH_METHOD2
#endif


#define HASHMATH_METHOD0(s)  hashMath::hashsp2(s)				// 10000000 重复率 1%
#define HASHMATH_METHOD0_1(s,len)  hashMath::hashsp2(s,len)
#if (HASH_CHECK_LEVEL>=1)
	#define HASHMATH_METHOD1(s)  hashMath::hashsp2(s)
	#define HASHMATH_METHOD1_1(s,len)  hashMath::hashsp2(s,len)
#endif
#if (HASH_CHECK_LEVEL>=2)
	#define HASHMATH_METHOD2(s)  hashMath::hashsp(s)					// 10000000 重复率 0%
	#define HASHMATH_METHOD2_1(s,len)  hashMath::hashsp(s,len)			//多次hash确定唯一性  calc_hashnr2  lh_strhash2
#endif
#if (HASH_CHECK_LEVEL>=3)
	#define HASHMATH_METHOD3(s)  hashMath::hashpjw(s)				//10000000 重复率 0%
	#define HASHMATH_METHOD3_1(s,len)  hashMath::hashpjw(s,len)		//lh_strhash  hashpjw  calc_hashnr2
#endif

	template <class KEYT,class VALUE> class hashTable
	{
	public:
		struct hashNode
		{
		public:
			unsigned long long next;					//链表 下一个位置
			VALUE  val;									// 当前节点数据位置                                    
			unsigned int hashCode;						//hash值
#if defined(HASHMATH_METHOD2)
			unsigned int hashCode2;						//hash值  用于字符串校验
#endif
#if defined(HASHMATH_METHOD3)
			unsigned int hashCode3;						//hash值  用于字符串校验
#endif
			hashNode():hashCode(0),next(0),val(VALUE())
#if defined(HASHMATH_METHOD2)
				,hashCode2(0)
#endif
#if defined(HASHMATH_METHOD3)
				,hashCode3(0)
#endif
			{
			};
			hashNode(const VALUE &val):hashCode(0),next(0),val(val)
#if defined(HASHMATH_METHOD2)
				,hashCode2(0)
#endif
#if defined(HASHMATH_METHOD3)
				,hashCode3(0)
#endif
			{
			};
		};
		hashNode * nodes;
		static bool keyIsString;
	protected:
		int size;
		char var_p[40];
		static inline unsigned int hash_sprintf(char * cp,int k){return sprintf(cp,"%d",k);};
		static inline unsigned int hash_sprintf(char * cp,long k){return sprintf(cp,"%ld",k);};
		static inline unsigned int hash_sprintf(char * cp,long long k){return sprintf(cp,"%lld",k);};
		static inline unsigned int hash_sprintf(char * cp,unsigned int k){return sprintf(cp,"%u",k);};
		static inline unsigned int hash_sprintf(char * cp,unsigned long k){return sprintf(cp,"%lu",k);};
		static inline unsigned int hash_sprintf(char * cp,unsigned long long k){return sprintf(cp,"%llu",k);};
		static inline unsigned int hash_sprintf(char * cp,const string &k){return k.size();};
		
	public:
		hashTable(int _size=0):size(_size),nodes(NULL)
		{
		};
		~hashTable()
		{
			clear();
		};
		//
		// 摘要:
		//     添加节点到hashTable中
		//
		// 参数:
		//   node:
		//     hashNode 类型指针。
		//
		inline bool addNode(hashNode * &node)
		{
			if(nodes==NULL)
			{
				if(this->size==0)EXP("addNode未设置hash初始化大小");
				try
				{
					nodes=new hashNode[this->size];	//分配存储空间
				}
				catch(...)
				{
					EXP("hash表内存空间分配失败");
				}
			}
			if(node->hashCode==0){delete node;return false;}
			unsigned int curIndex=node->hashCode%this->size;					//取索引位置;
			if(nodes[curIndex].hashCode==0)
			{
				nodes[curIndex]=*node;
				delete node;
				node=NULL;
				return true;
			}
			else
			{
				if(nodes[curIndex].hashCode==node->hashCode						//相同key不再处理
#if defined(HASHMATH_METHOD2)
					&& nodes[curIndex].hashCode2==node->hashCode2
#endif
#if defined(HASHMATH_METHOD3)
					&& nodes[curIndex].hashCode3==node->hashCode3
#endif
					)
				{
					delete node;
					return false;
				}
				hashNode * pNode;
				pNode=&(nodes[curIndex]);
				while(pNode->next)
				{
					pNode=(hashNode *)(pNode->next);
					if(pNode->hashCode==node->hashCode						//相同key不再处理
	#if defined(HASHMATH_METHOD2)
						&& pNode->hashCode2==node->hashCode2
	#endif
	#if defined(HASHMATH_METHOD3)
						&& pNode->hashCode3==node->hashCode3
	#endif
						)
					{
						delete node;
						return false;
					}
				}
				pNode->next=(unsigned long long)node;
				return true;
			}
		};
		//
		// 摘要:
		//     重新设置容器大小,每调用一次都会引起已有数据的拷贝移动
		//
		// 参数:
		//   size:
		//     要重新设置的容器大小数目。
		//
		inline void resize(int size)
		{
			if(size>this->size)
			{
				int oldSize=this->size;
				this->size=size;
				hashNode *tempNodes=nodes;
				nodes=new hashNode[this->size];
				for(int i=0;i<oldSize;i++)
				{
					if(tempNodes[i].hashCode==0)continue;									//存在数据
					unsigned int curIndex=tempNodes[i].hashCode%this->size;				//取索引位置;
					hashNode * node=new hashNode();
					(*node)=tempNodes[i];
					addNode(node);

					hashNode * pNode = (hashNode *)(tempNodes[i].next);
					hashNode * tpNode;
					while(pNode)
					{
						node=new hashNode();
						(*node)=*pNode;
						addNode(node);
						tpNode=pNode;
						pNode=(hashNode *)(pNode->next);
						delete tpNode;
					}
				}
				delete []tempNodes;
			}
		};
		//
		// 摘要:
		//	重设大小,不保留以前值
		//
		inline void setSize(int size)
		{
			if(this->size>0)
			{
				clear();
			}
			this->size=size;
		};
		
		//
		// 摘要:
		//	设置关键字类型是否为字符串,如果申明 hashTable<char *,valueT> 则必需显式设置关键字类型为字符串
		//
		inline void setKeyType(bool _isString){keyIsString=_isString;};
		inline bool getKeyType(){return keyIsString;};
		//
		// 摘要:
		//	返回hash表大小
		//
		inline int getSize(){return this->size;};
		//
		// 摘要:
		//     清理数据
		//
		inline void clear()
		{
			if(nodes)
			{
				hashNode * pNode,* nextNode;
				for(int i=0;i<this->size;i++)
				{
					if(this->nodes[i].next)
					{
						nextNode=(hashNode *)this->nodes[i].next;
						while(nextNode)
						{
							pNode=nextNode;
							nextNode=(hashNode *)nextNode->next;
							delete pNode;
						}
					}
				}
				delete []nodes;
			}
			nodes=NULL;
		}
		//
		// 摘要:
		//     添加节点到hashTable中
		//
		// 参数:
		//   key:
		//     hash关键字。
		//
		//   val:
		//     hash关键字对应值。
		//
		inline bool addNode(const KEYT &key,const VALUE &val)
		{
			if(nodes==NULL)
			{
				if(this->size==0)EXP("addNode未设置hash初始化大小");
				try
				{
					nodes=new hashNode[this->size];	//分配存储空间
				}
				catch(...)
				{
					EXP("hash表内存空间分配失败");
				}
			}
			hashNode *node=getHashNode(key,val);
			if(node->hashCode==0){delete node;return false;}
			unsigned int curIndex=node->hashCode%this->size;					//取索引位置;
			if(nodes[curIndex].hashCode==0)
			{
				nodes[curIndex]=*node;
				delete node;
				return true;
			}
			else
			{
				if(nodes[curIndex].hashCode==node->hashCode						//相同key不再处理
#if defined(HASHMATH_METHOD2)
					&& nodes[curIndex].hashCode2==node->hashCode2
#endif
#if defined(HASHMATH_METHOD3)
					&& nodes[curIndex].hashCode3==node->hashCode3
#endif
					)
				{
					delete node;
					return false;
				}
				hashNode * pNode;
				pNode=&(nodes[curIndex]);
				while(pNode->next)
				{
					pNode=(hashNode *)(pNode->next);
					if(pNode->hashCode==node->hashCode						//相同key不再处理
	#if defined(HASHMATH_METHOD2)
						&& pNode->hashCode2==node->hashCode2
	#endif
	#if defined(HASHMATH_METHOD3)
						&& pNode->hashCode3==node->hashCode3
	#endif
						)
					{
						delete node;
						return false;
					}
				}
				pNode->next=(unsigned long long)node;
				return true;
			}
		};
		//移除一个关键字
		inline bool remove(const KEYT &key)
		{
			if(nodes==NULL)return false;
			unsigned int hashCode,hashCode2,hashCode3,curIndex;
			if(keyIsString)
			{
				hashCode=HASHMATH_METHOD0(key);
#if defined(HASHMATH_METHOD2)
				hashCode2=HASHMATH_METHOD2(key);
#endif
#if defined(HASHMATH_METHOD3)
				hashCode3=HASHMATH_METHOD3(key);
#endif
			}
			else
			{
#if defined(HASHMATH_METHOD1)
				unsigned int len=hash_sprintf(var_p,key);
				hashCode=HASHMATH_METHOD1_1(var_p,len);
#if defined(HASHMATH_METHOD2)
				hashCode2=HASHMATH_METHOD2_1(var_p,len);		//校验位
#endif
#if defined(HASHMATH_METHOD3)
				hashCode3=HASHMATH_METHOD3_1(var_p,len);
#endif
#else
				hashCode=key % (unsigned int)0xFFFFFFFF;
#endif
			}
			curIndex=hashCode%this->size;
			hashNode * pNode=nodes + curIndex;
			if(pNode->hashCode==hashCode
#if defined(HASHMATH_METHOD2)
				&& pNode->hashCode2==hashCode2 
#endif
#if defined(HASHMATH_METHOD3)
				&& pNode->hashCode3==hashCode3					//三次hash相等
#endif
				)
			{
				if(pNode->next==0)//无后续节点
				{
					pNode->hashCode=0;
	#if defined(HASHMATH_METHOD2)
					pNode->hashCode2=0;
	#endif
	#if defined(HASHMATH_METHOD3)
					pNode->hashCode3=0;
	#endif
				}
				else
				{
					hashNode * priNode=pNode;
					pNode=(hashNode *)pNode->next;
					(*priNode)=(*pNode);
					delete pNode;
				}
				return true;
			}
			hashNode * priNode=pNode;
			pNode=(hashNode *)pNode->next;
			while(pNode)
			{
				if(pNode->hashCode==hashCode
#if defined(HASHMATH_METHOD2)
					&& pNode->hashCode2==hashCode2 
#endif
#if defined(HASHMATH_METHOD3)
					&& pNode->hashCode3==hashCode3					//三次hash相等
#endif
					)
				{
					if(pNode->next)
					{
						priNode->next=pNode->next;
					}
					delete pNode;
					return true;
				}
				priNode=pNode;
				pNode=(hashNode *)pNode->next;
			}
			return false;
		}

		//
		// 摘要:
		//	操作符重载,返回值引用
		//
		// 参数:
		//   key:
		//     关键字
		//
		// 返回结果:
		//     返回值引用
		//
		inline VALUE &operator[](const KEYT &key)
		{
			if(nodes==NULL)
			{
				if(this->size==0)EXP("operator[]未设置hash初始化大小");
				try
				{
					nodes=new hashNode[this->size];	//分配存储空间
				}
				catch(...)
				{
					EXP("hash表内存空间分配失败");
				}
			}
			hashNode *node=getHashNode(key);
			unsigned int curIndex=node->hashCode%this->size;					//取索引位置;
			hashNode * pNode;
			hashNode * curNode=nodes + curIndex;
			if(curNode->hashCode==0)
			{
				*curNode=*node;
				delete node;
				return curNode->val;
			}
			pNode=curNode;
			while(pNode)
			{
				if(pNode->hashCode==node->hashCode
#if defined(HASHMATH_METHOD2)
					&& pNode->hashCode2==node->hashCode2 
#endif
#if defined(HASHMATH_METHOD3)
					&& pNode->hashCode3==node->hashCode3					//三次hash相等
#endif
					)
				{
					delete node;									//已经存在
					return pNode->val;
				}
				curNode=pNode;
				pNode=(hashNode *)pNode->next;
			}
			curNode->next=(unsigned long long)node;
			return node->val;
		};
		//
		// 摘要:
		//	从内存查找
		//
		inline bool find(const KEYT &key,VALUE &val,bool exp=false)
		{
			if(nodes==NULL)if(exp)EXP("没有初始化节点数据.")else return false;
			unsigned int hashCode,hashCode2,hashCode3,curIndex;
			if(keyIsString)
			{
				hashCode=HASHMATH_METHOD0(key);
#if defined(HASHMATH_METHOD2)
				hashCode2=HASHMATH_METHOD2(key);
#endif
#if defined(HASHMATH_METHOD3)
				hashCode3=HASHMATH_METHOD3(key);
#endif
			}
			else
			{
#if defined(HASHMATH_METHOD1)
				unsigned int len=hash_sprintf(var_p,key);
				hashCode=HASHMATH_METHOD1_1(var_p,len);
#if defined(HASHMATH_METHOD2)
				hashCode2=HASHMATH_METHOD2_1(var_p,len);		//校验位
#endif
#if defined(HASHMATH_METHOD3)
				hashCode3=HASHMATH_METHOD3_1(var_p,len);
#endif
#else
				hashCode=key % (unsigned int)0xFFFFFFFF;
#endif
			}
			curIndex=hashCode%this->size;
			hashNode * pNode=nodes + curIndex;
			
			while(pNode)
			{
				if(pNode->hashCode==hashCode
#if defined(HASHMATH_METHOD2)
					&& pNode->hashCode2==hashCode2 
#endif
#if defined(HASHMATH_METHOD3)
					&& pNode->hashCode3==hashCode3					//三次hash相等
#endif
					)
				{
					val=pNode->val;
					return true;
				}
				pNode=(hashNode *)pNode->next;
			}
			return false;
		};
		inline bool contain(const KEYT &key)
		{
			if(nodes==NULL)return false;
			unsigned int hashCode,hashCode2,hashCode3,curIndex;
			if(keyIsString)
			{
				hashCode=HASHMATH_METHOD0(key);
#if defined(HASHMATH_METHOD2)
				hashCode2=HASHMATH_METHOD2(key);
#endif
#if defined(HASHMATH_METHOD3)
				hashCode3=HASHMATH_METHOD3(key);
#endif
			}
			else
			{
#if defined(HASHMATH_METHOD1)
				unsigned int len=hash_sprintf(var_p,key);
				hashCode=HASHMATH_METHOD1_1(var_p,len);
#if defined(HASHMATH_METHOD2)
				hashCode2=HASHMATH_METHOD2_1(var_p,len);		//校验位
#endif
#if defined(HASHMATH_METHOD3)
				hashCode3=HASHMATH_METHOD3_1(var_p,len);
#endif
#else
				hashCode=key % (unsigned int)0xFFFFFFFF;
#endif
			}
			curIndex=hashCode%this->size;
			hashNode * pNode=nodes + curIndex;
			
			while(pNode)
			{
				if(pNode->hashCode==hashCode
#if defined(HASHMATH_METHOD2)
					&& pNode->hashCode2==hashCode2 
#endif
#if defined(HASHMATH_METHOD3)
					&& pNode->hashCode3==hashCode3					//三次hash相等
#endif
					)
				{
					return true;
				}
				pNode=(hashNode *)pNode->next;
			}
			return false;
		};
		//
		// 摘要:
		//     从文件查找
		//
		// 参数:
		//   pkeyFile:
		//     已打开的关键字文件指针。
		//
		//   key:
		//     hash关键字。
		//
		//   val:
		//     hash关键字对应返回值。
		//
		//   size:
		//     hash大小。
		//
		// 返回结果:
		//     是否成功查找到数据。
		//
		inline static bool find(FILE *pkeyFile,const KEYT &key,VALUE &val,int size)
		{
			if(!pkeyFile)return false;
			unsigned int hashCode,hashCode2,hashCode3,curIndex;
			if(keyIsString)
			{
				hashCode=HASHMATH_METHOD0(key);
#if defined(HASHMATH_METHOD2)
				hashCode2=HASHMATH_METHOD2(key);
#endif
#if defined(HASHMATH_METHOD3)
				hashCode3=HASHMATH_METHOD3(key);
#endif
			}
			else
			{
#if defined(HASHMATH_METHOD1)
				char sta_p[41];
				unsigned int len=hash_sprintf(sta_p,key);
				hashCode=HASHMATH_METHOD1_1(sta_p,len);
#if defined(HASHMATH_METHOD2)
				hashCode2=HASHMATH_METHOD2_1(sta_p,len);		//校验位
#endif
#if defined(HASHMATH_METHOD3)
				hashCode3=HASHMATH_METHOD3_1(sta_p,len);
#endif
#else
				hashCode=key % (unsigned int)0xFFFFFFFF;
#endif
			}
			hashNode tempNode;
			curIndex=hashCode%size;			
			long long curPos=NodeSize*curIndex;
			fseek(pkeyFile, curPos, SEEK_SET);
			int len= fread(&tempNode,NodeSize,1,pkeyFile);//return false;
			if(len!=1)	EXP("读取key数据发生错误,未读取到指定长度的数据.");
			while(tempNode.hashCode%size==curIndex)
			{
				if(tempNode.hashCode==hashCode
#if defined(HASHMATH_METHOD2)
					&& tempNode.hashCode2==hashCode2 
#endif
#if defined(HASHMATH_METHOD3)
					&& tempNode.hashCode3==hashCode3					//三次hash相等
#endif
					)
				{
					val=tempNode.val;
					return true;
				}
				if(!tempNode.next)return false;
				fseek(pkeyFile, tempNode.next, SEEK_SET);
				fread(&tempNode,NodeSize,1,pkeyFile);
				if(tempNode.hashCode==0)
				{
					return false;						//未找到
				}
			}
			return false;
		};
		//
		// 摘要:
		//	从文件查找key
		//
		inline static bool find(FILE *pkeyFile,const KEYT &key,VALUE &val,int size,bool isSeries)
		{
			if(!isSeries)							//是否使用一次写入key文件
				return find(pkeyFile,key,val,size);
			if(!pkeyFile)
				return false;
			unsigned int hashCode,hashCode2,hashCode3,curIndex;
			if(keyIsString)
			{
				hashCode=HASHMATH_METHOD0(key);
#if defined(HASHMATH_METHOD2)
				hashCode2=HASHMATH_METHOD2(key);
#endif
#if defined(HASHMATH_METHOD3)
				hashCode3=HASHMATH_METHOD3(key);
#endif
			}
			else
			{
#if defined(HASHMATH_METHOD1)
				char sta_p[41];
				unsigned int len=hash_sprintf(sta_p,key);
				hashCode=HASHMATH_METHOD1_1(sta_p,len);
#if defined(HASHMATH_METHOD2)
				hashCode2=HASHMATH_METHOD2_1(sta_p,len);		//校验位
#endif
#if defined(HASHMATH_METHOD3)
				hashCode3=HASHMATH_METHOD3_1(sta_p,len);
#endif
#else
				hashCode=key % (unsigned int)0xFFFFFFFF;
#endif
			}
			hashNode tempNode;
			curIndex=hashCode%size;
			long long curPos=NodeSize*curIndex;
			fseek(pkeyFile, curPos, SEEK_SET);//return false;
			int len= fread(&tempNode,NodeSize,1,pkeyFile);//return false;
			if(len!=1)	EXP("读取key数据发生错误,未读取到指定长度的数据."+String(len));
			if(tempNode.hashCode==0)
			{
				return false;								//未找到
			}
			else if(tempNode.hashCode==hashCode
#if defined(HASHMATH_METHOD2)
				&& tempNode.hashCode2==hashCode2 
#endif
#if defined(HASHMATH_METHOD3)
				&& tempNode.hashCode3==hashCode3					//三次hash相等
#endif
				)
			{
				val=tempNode.val;
				return true;
			}
			else if(tempNode.next==0)
			{
				return false;
			}
			//读取连续位置值,减少I/O交互
			hashNode tempNodes[ONE_READ_COUNT];
			fseek(pkeyFile,tempNode.next, SEEK_SET);
			len= fread(&tempNodes,NodeSize,ONE_READ_COUNT,pkeyFile);
			if(len==0)	EXP("读取key数据发生错误,未读取到任何数据.");
			int index=0;
			while(tempNodes[index].hashCode%size==curIndex)
			{
				if(tempNodes[index].hashCode==hashCode
	#if defined(HASHMATH_METHOD2)
					&& tempNodes[index].hashCode2==hashCode2 
	#endif
	#if defined(HASHMATH_METHOD3)
					&& tempNodes[index].hashCode3==hashCode3					//三次hash相等
	#endif
					)
				{
					val=tempNodes[index].val;
					return true;
				}
				if(!tempNodes[index].next)return false;
				index++;
				if(index==ONE_READ_COUNT)
				{
					fseek(pkeyFile, tempNodes[index-1].next, SEEK_SET);
					len= fread(&tempNodes,NodeSize,ONE_READ_COUNT,pkeyFile);
					if(len==0)return false;
					index=0;
				}
			}
			return false;
		};
		//
		// 摘要:
		//	从文件查找key
		//
		inline bool find(FILE *pkeyFile,const KEYT &key,VALUE &val)
		{
			if(!pkeyFile)return false;
			unsigned int hashCode,hashCode2,hashCode3,curIndex;
			if(keyIsString)
			{
				hashCode=HASHMATH_METHOD0(key);
#if defined(HASHMATH_METHOD2)
				hashCode2=HASHMATH_METHOD2(key);
#endif
#if defined(HASHMATH_METHOD3)
				hashCode3=HASHMATH_METHOD3(key);
#endif
			}
			else
			{
#if defined(HASHMATH_METHOD1)
				unsigned int len=hash_sprintf(var_p,key);
				hashCode=HASHMATH_METHOD1_1(var_p,len);
#if defined(HASHMATH_METHOD2)
				hashCode2=HASHMATH_METHOD2_1(var_p,len);			//校验位
#endif
#if defined(HASHMATH_METHOD3)
				hashCode3=HASHMATH_METHOD3_1(var_p,len);
#endif
#else
				hashCode=key % (unsigned int)0xFFFFFFFF;
#endif
			}
			hashNode tempNode;
			curIndex=hashCode%size;			
			long long curPos=NodeSize*curIndex;
			fseek(pkeyFile, curPos, SEEK_SET);
			int len= fread(&tempNode,NodeSize,1,pkeyFile);
			if(len!=1)	EXP("读取key数据发生错误,未读取到指定长度的数据.");
			while(tempNode.hashCode%size==curIndex)
			{
				if(tempNode.hashCode==hashCode
#if defined(HASHMATH_METHOD2)
					&& tempNode.hashCode2==hashCode2 
#endif
#if defined(HASHMATH_METHOD3)
					&& tempNode.hashCode3==hashCode3					//三次hash相等
#endif
					)
				{
					val=tempNode.val;
					return true;
				}
				curPos=tempNode.next;
				fseek(pkeyFile, curPos, SEEK_SET);
				fread(&tempNode,NodeSize,1,pkeyFile);
				if(tempNode.hashCode==0)
				{
					break;								//未找到
				}
			}
			return false;
		};
		//
		// 摘要:
		//	从文件查找key
		//
		inline bool find(FILE *pkeyFile,const KEYT &key,VALUE &val,bool isSeries)
		{
			if(!isSeries)							//是否使用一次写入key文件
				return find(pkeyFile,key,val);
			if(!pkeyFile)
				return false;
			unsigned int hashCode,hashCode2,hashCode3,curIndex;
			if(keyIsString)
			{
				hashCode=HASHMATH_METHOD0(key);
#if defined(HASHMATH_METHOD2)
				hashCode2=HASHMATH_METHOD2(key);
#endif
#if defined(HASHMATH_METHOD3)
				hashCode3=HASHMATH_METHOD3(key);
#endif
			}
			else
			{
#if defined(HASHMATH_METHOD1)
				unsigned int len=hash_sprintf(var_p,key);
				hashCode=HASHMATH_METHOD1_1(var_p,len);
#if defined(HASHMATH_METHOD2)
				hashCode2=HASHMATH_METHOD2_1(var_p,len);	//校验位
#endif
#if defined(HASHMATH_METHOD3)
				hashCode3=HASHMATH_METHOD3_1(var_p,len);
#endif
#else
				hashCode=key % (unsigned int)0xFFFFFFFF;
#endif
			}
			hashNode tempNode;
			curIndex=hashCode%size;			
			long long curPos=NodeSize*curIndex;
			fseek(pkeyFile, curPos, SEEK_SET);
			int len= fread(&tempNode,NodeSize,1,pkeyFile);
			if(len!=1)	EXP("读取key数据发生错误,未读取到指定长度的数据.");
			if(tempNode.hashCode==0)
			{
				return false;								//未找到
			}
			else if(tempNode.hashCode==hashCode
#if defined(HASHMATH_METHOD2)
				&& tempNode.hashCode2==hashCode2 
#endif
#if defined(HASHMATH_METHOD3)
				&& tempNode.hashCode3==hashCode3					//三次hash相等
#endif
				)
			{
				val=tempNode.val;
				return true;
			}
			else if(tempNode.next==0)
			{
				return false;
			}
			//读取连续位置值,减少I/O交互
			hashNode tempNodes[ONE_READ_COUNT];
			fseek(pkeyFile, tempNode.next, SEEK_SET);
			len= fread(&tempNodes,NodeSize,ONE_READ_COUNT,pkeyFile);
			if(len==0)	EXP("读取key数据发生错误,未读取到任何数据.");
			int index=0;
			while(tempNodes[index].hashCode%size==curIndex)
			{
				if(tempNodes[index].hashCode==hashCode
	#if defined(HASHMATH_METHOD2)
					&& tempNodes[index].hashCode2==hashCode2 
	#endif
	#if defined(HASHMATH_METHOD3)
					&& tempNodes[index].hashCode3==hashCode3					//三次hash相等
	#endif
					)
				{
					val=tempNodes[index].val;
					return true;
				}
				if(!tempNodes[index].next)return false;
				index++;
				if(index==ONE_READ_COUNT)
				{
					fseek(pkeyFile, tempNodes[index-1].next, SEEK_SET);
					len= fread(&tempNodes,NodeSize,ONE_READ_COUNT,pkeyFile);
					if(len==0)return false;
					index=0;
				}
			}
			return false;
		};
		//
		// 摘要:
		//     将hashTable数据写成文件,写完后会删除hashTable 中的内存数据
		//
		// 参数:
		//   pkeyFile:
		//     已打开的关键字文件指针。
		//
		//   printAnalyse:
		//     是否打印hash分析结果。
		//
		inline int writeFile(FILE *pkeyFile)					//写入文件
		{
			if(nodes==NULL)
			{
				if(this->size==0)EXP("writeFile未设置hash初始化大小");
				try
				{
					nodes=new hashNode[this->size];	//分配存储空间
				}
				catch(...)
				{
					EXP("hash表内存空间分配失败");
				}
			}
			long long curPos=0;
			int repeatCount=0,len=0;
			hashNode * pNode,* curNode,*nextNode;

			hashNode tempNode=hashNode();
			fseek(pkeyFile,(this->size-1) * NodeSize ,SEEK_SET);			//直接写入最大长度
			len=fwrite(&tempNode,NodeSize,1,pkeyFile);
			fflush(pkeyFile);
			long fileSize=ftell(pkeyFile);
			if(len!=1 || fileSize!=this->size*NodeSize)
				EXP("初始化hash文件大小发生错误.");
			for(int i=0;i<this->size;i++)
			{
				if(nodes[i].hashCode==0)continue;
				curNode=&(nodes[i]);
				if(curNode->next)
				{
					nextNode=(hashNode *)(curNode->next);
					curNode->next=(repeatCount+this->size) * NodeSize;
					curPos= i * NodeSize;
					fseek(pkeyFile, curPos, SEEK_SET);
					len=fwrite(curNode,NodeSize,1,pkeyFile);
					if(len!=1)	EXP("写入hash文件发生错误.");
					while(nextNode)
					{
						repeatCount++;
						pNode=(hashNode *)(nextNode->next);
						unsigned long long nPos=((nextNode->next!=0)?1:0) * (repeatCount+this->size) * NodeSize;
						nextNode->next=nPos;
						fseek(pkeyFile, 0, SEEK_END);
						len=fwrite(nextNode,NodeSize,1,pkeyFile);
						if(len!=1)
							EXP("写入hash文件发生错误.");
						delete nextNode;
						nextNode=pNode;
					}
				}
				else
				{
					curPos= i * NodeSize;
					fseek(pkeyFile, curPos, SEEK_SET);
					len=fwrite(curNode,NodeSize,1,pkeyFile);
					if(len!=1)	EXP("写入hash文件发生错误.");
				}
			}
			delete [] nodes;
			nodes=NULL;
			return repeatCount;
		};
		//
		// 摘要:
		//	写文件
		//
		inline int writeFile(FILE *pkeyFile,bool printAnalyse)					//写入文件
		{
			if(nodes==NULL)
			{
				if(this->size==0)EXP("writeFile未设置hash初始化大小");
				try
				{
					nodes=new hashNode[this->size];	//分配存储空间
				}
				catch(...)
				{
					EXP("hash表内存空间分配失败");
				}
			}
			if(!printAnalyse)
				return writeFile(pkeyFile);
			long long curPos=0;
			int repeatCount=0,len=0;
			hashNode * pNode,* curNode,*nextNode;

			hashNode tempNode=hashNode();
			fseek(pkeyFile,(this->size-1) * NodeSize ,SEEK_SET);			//直接写入最大长度
			len=fwrite(&tempNode,NodeSize,1,pkeyFile);
			fflush(pkeyFile);
			long fileSize=ftell(pkeyFile);
			if(len!=1 || fileSize!=this->size*NodeSize)
				EXP("初始化hash文件大小发生错误.");
			vector<int> distributing;
			distributing.push_back(1);
			distributing.push_back(0);
			for(int i=0;i<this->size;i++)
			{
				if(nodes[i].hashCode==0)continue;
				distributing.at(1)++;
				curNode=&(nodes[i]);
				if(curNode->next)
				{
					nextNode=(hashNode *)(curNode->next);
					curNode->next=(repeatCount+this->size) * NodeSize;
					curPos= i * NodeSize;
					fseek(pkeyFile, curPos, SEEK_SET);
					len=fwrite(curNode,NodeSize,1,pkeyFile);
					if(len!=1)	EXP("写入hash文件发生错误.");
					int depth=1;
					while(nextNode)
					{
						depth++;
						if(depth>=distributing.size())
							distributing.push_back(1);
						else
							distributing.at(depth)++;
						repeatCount++;
						pNode=(hashNode *)(nextNode->next);
						unsigned long long nPos=((nextNode->next!=0)?1:0) * (repeatCount+this->size) * NodeSize;
						nextNode->next=nPos;
						fseek(pkeyFile, 0, SEEK_END);
						len=fwrite(nextNode,NodeSize,1,pkeyFile);
						if(len!=1)
							EXP("写入hash文件发生错误.");
						delete nextNode;
						nextNode=pNode;
					}
					if(distributing.at(0)<depth)
						distributing.at(0)=depth;
				}
				else
				{
					curPos= i * NodeSize;
					fseek(pkeyFile, curPos, SEEK_SET);
					len=fwrite(curNode,NodeSize,1,pkeyFile);
					if(len!=1)	EXP("写入hash文件发生错误.");
				}
			}
			delete [] nodes;
			nodes=NULL;
			cout<<"hash链表深度: "<< distributing[0] <<endl;
			int countPos=0;
			for(int i=1;i<distributing.size();i++)
			{
				countPos+=distributing[i];
			}
			if(countPos>0)
			{
				for(int i=1;i<distributing.size();i++)
				{
					cout<<"hash "<<i<<" 次定位数: "<< distributing[i] <<" 占比: "<< (double)distributing[i]/countPos <<endl;
				}
			}
			cout<<"hash表使用率: "<< (double)distributing[1]*100/this->size <<endl;
			distributing.clear();
			return repeatCount;
		};
		//
		// 摘要:
		//     直接将KEY写入文件
		//
		// 参数:
		//   pkeyFile:
		//     in 已打开的关键字文件指针。
		//
		//   key:
		//     in hash关键字。
		//
		//   val:
		//     in hash关键字对应返回值。
		//
		//   repeatCount:
		//     in/out hash索引重复值大小。第一次调用前置 0
		//
		inline static void writeFile(FILE *pkeyFile,const KEYT &key,const VALUE &val,int &repeatCount,int size)
		{
			if(!pkeyFile)EXP("key文件指针为空.");
			//直接写入文件
			int len=0;
			hashNode *node=getHashNode(key,val);
			unsigned int curIndex=node->hashCode % size;					//取索引位置;
			long long curPos=NodeSize*curIndex;
			fseek(pkeyFile, curPos, SEEK_SET);
			hashNode tempNode;
			len= fread(&tempNode,NodeSize,1,pkeyFile);
			if(len!=1)	EXP("读取key数据发生错误,未读取到指定长度的数据.");
			if(tempNode.hashCode==0)
			{
				fseek(pkeyFile, curPos, SEEK_SET);
				len=fwrite(node,NodeSize,1,pkeyFile);
				if(len!=1)	EXP("写入hash文件发生错误.");
				delete node;
			}
			else
			{
				if(tempNode.hashCode=node->hashCode
#if defined(HASHMATH_METHOD2)
				&& tempNode.hashCode2==node->hashCode2 
#endif
#if defined(HASHMATH_METHOD3)
				&& tempNode.hashCode3==node->hashCode3					//三次hash相等
#endif
					)
				{
					delete node;
					return ;
				}
				unsigned long long nPos=curPos;
				while(tempNode.next)
				{
					nPos=tempNode.next;
					fseek(pkeyFile, tempNode.next, SEEK_SET);
					len = fread(&tempNode,NodeSize,1,pkeyFile);
					if(tempNode.hashCode=node->hashCode
#if defined(HASHMATH_METHOD2)
					&& tempNode.hashCode2==node->hashCode2 
#endif
#if defined(HASHMATH_METHOD3)
					&& tempNode.hashCode3==node->hashCode3					//三次hash相等
#endif
						)
					{
						delete node;
						return ;
					}
				}
				fseek(pkeyFile,0, SEEK_END);
				tempNode.next=ftell(pkeyFile);
				fseek(pkeyFile, nPos, SEEK_SET);
				len=fwrite(&tempNode,NodeSize,1,pkeyFile);
				if(len!=1)
					EXP("更新hash文件中节点发生错误.");
				fseek(pkeyFile, 0, SEEK_END);
				len=fwrite(node,NodeSize,1,pkeyFile);
				if(len!=1)
					EXP("写入hash文件发生错误.");
				delete node;
				repeatCount++;
			}
		};
		//
		// 摘要:
		//	获取新hash节点的指针
		//
		static hashNode * getHashNode(const KEYT &key,const VALUE &val)
		{
			hashNode *node=new hashNode(val);
			if(keyIsString)
			{
				node->hashCode=HASHMATH_METHOD0(key);
#if defined(HASHMATH_METHOD2)
				node->hashCode2=HASHMATH_METHOD2(key);
#endif
#if defined(HASHMATH_METHOD3)
				node->hashCode3=HASHMATH_METHOD3(key);
#endif
			}
			else
			{
#if defined(HASHMATH_METHOD1)
				char sta_p[41];
				unsigned int len=hash_sprintf(sta_p,key);
				node->hashCode=HASHMATH_METHOD1_1(sta_p,len);
	#if defined(HASHMATH_METHOD2)
				node->hashCode2=HASHMATH_METHOD2_1(sta_p,len);		//校验位
	#endif
	#if defined(HASHMATH_METHOD3)
				node->hashCode3=HASHMATH_METHOD3_1(sta_p,len);
	#endif
#else
				node->hashCode=key % (unsigned int)0xFFFFFFFF;
#endif
			}
			return node;
		};
		//
		// 摘要:
		//	获取新hash节点的指针
		//
		static hashNode * getHashNode(const KEYT &key)
		{
			hashNode *node=new hashNode();
			if(keyIsString)
			{
				node->hashCode=HASHMATH_METHOD0(key);
#if defined(HASHMATH_METHOD2)
				node->hashCode2=HASHMATH_METHOD2(key);
#endif
#if defined(HASHMATH_METHOD3)
				node->hashCode3=HASHMATH_METHOD3(key);
#endif
			}
			else
			{
#if defined(HASHMATH_METHOD1)
				char sta_p[41];
				unsigned int len=hash_sprintf(sta_p,key);
				node->hashCode=HASHMATH_METHOD1_1(sta_p,len);
#if defined(HASHMATH_METHOD2)
				node->hashCode2=HASHMATH_METHOD2_1(sta_p,len);		//校验位
#endif
#if defined(HASHMATH_METHOD3)
				node->hashCode3=HASHMATH_METHOD3_1(sta_p,len);
#endif
#else
				node->hashCode=key % (unsigned int)0xFFFFFFFF;
#endif
			}
			return node;
		};
		//
		// 摘要:
		//	分析hash表
		//
		inline void analyse()
		{
			vector<int> distributing;
			distributing.push_back(1);
			if(nodes)
			{
				hashNode * pNode,* nextNode;
				for(int i=0;i<this->size;i++)
				{
					if(this->nodes[i].hashCode!=0)
					{
						int depth=1;
						if(depth>=distributing.size())
							distributing.push_back(1);
						else
							distributing.at(depth)++;
						if(this->nodes[i].next)
						{
							nextNode=(hashNode *)this->nodes[i].next;
							while(nextNode)
							{
								depth++;
								if(depth>=distributing.size())
									distributing.push_back(1);
								else
									distributing.at(depth)++;
								pNode=nextNode;
								nextNode=(hashNode *)nextNode->next;
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
				cout<<"hash表使用率: "<< (double)distributing[1]*100/this->size <<endl;
			}
			else
			{
				cout<<"不存在hash节点! " <<endl;
			}
			distributing.clear();
		};
		//
		// 摘要:
		//	获取hash表深度
		//
		inline int getDepth()
		{
			int depth=1;
			if(nodes)
			{
				hashNode * pNode,* nextNode;
				for(int i=0;i<this->size;i++)
				{
					int depth2=1;
					if(this->nodes[i].next)
					{
						nextNode=(hashNode *)this->nodes[i].next;
						while(nextNode)
						{
							depth++;
							pNode=nextNode;
							nextNode=(hashNode *)nextNode->next;
						}
						if(depth<depth2)depth=depth2;
					}
				}
			}
			return depth;
		};
		static const long NodeSize;//=sizeof(NODE);
		const static bool defKeyIsString;
	};
	template <class KEYT,class VALUE> const long hashTable<KEYT,VALUE>::NodeSize=sizeof(hashTable<KEYT,VALUE>::hashNode);
	template <class KEYT,class VALUE> const bool hashTable<KEYT,VALUE>::defKeyIsString=(sizeof(KEYT)>8);
	template <class KEYT,class VALUE>  bool hashTable<KEYT,VALUE>::keyIsString=hashTable<KEYT,VALUE>::defKeyIsString;

#undef HASHMATH_METHOD0 
#undef HASHMATH_METHOD0_1
#if defined(HASHMATH_METHOD1)
#undef HASHMATH_METHOD1
#undef HASHMATH_METHOD1_1
#endif
#if defined(HASHMATH_METHOD2)
#undef HASHMATH_METHOD2
#undef HASHMATH_METHOD2_1
#endif
#if defined(HASHMATH_METHOD3)
#undef HASHMATH_METHOD3
#undef HASHMATH_METHOD3_1
#endif

}
#endif

