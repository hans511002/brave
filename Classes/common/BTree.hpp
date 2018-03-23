// ==============================================================
//progame      Common::BTree
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
#ifndef __Common_BTree_H__
#define __Common_BTree_H__

#include "Common.h"
namespace Common
{
	template <class T> class BTree
	{
		#define  LH  1         // ���                                     
		#define  EH  0         // �ȸ�                                     
		#define  RH  -1        // �Ҹ�                                     
		#define  True 1
		#define  False 0
		#define  RET_FOUND       1
		#define  RET_NOFOUND     0
	public:
		struct BTreeNode
		{
		public:
			BTreeNode  * ptnLeft;     // ��ָ��
			BTreeNode  * ptnRight;    // ��ָ��
			int    bf;                // ƽ������
			T   value;
		};
		typedef BTreeNode TNode;
		typedef BTreeNode * pBTreeNode;
		BTree()
		{
			this->root=NULL;
		};
		~BTree(){clear();};
	protected:
		// ȫ�։���                                     
		int taller;
		pBTreeNode root;

		//ƽ���������������                                    
		inline void L_Rotate(pBTreeNode &p)
		{
			pBTreeNode lp;					//����*pָ��Ľ��Ϊ����������������ת��������֮��*pָ��Ľ��Ϊ�������¸�                                    
			lp=p->ptnRight;					//lpָ��*p�����������                                    
			p->ptnRight=lp->ptnLeft;		//lp���������ҽ�*p��������                                    
			lp->ptnLeft=p; 
			p=lp;							// *pָ���µĸ����                                    
		}
		inline void R_Rotate(pBTreeNode &p)
		{	
			pBTreeNode lp;					//����*pָ��Ľ��Ϊ�������������ҵ���ת��������֮��*pָ��Ľ��Ϊ�������¸�                                    
			lp=p->ptnLeft;					//lpָ��*p�����������                                    
			p->ptnLeft=lp->ptnRight;		//lp���������ҽ�*p��������                                    
			lp->ptnRight=p; 
			p=lp;							//  *pָ���µĸ����                                    
		}

		//����*pָ��Ľ��Ϊ��������������ƽ����ת��������֮��*pָ��Ľ��Ϊ�������¸�                                    
		inline void LeftBalance(pBTreeNode &p)
		{
			pBTreeNode lp, rc;
			lp=p->ptnLeft;						//lpָ��*p�����������                                    
			switch(p->bf)						//���*pƽ��ȣ�������Ӧ����                                    
			{
			case LH:							//�½�����*p����Ů���������ϣ�����������ת����                                    
				p->bf=lp->bf=EH;
				R_Rotate(p);
				break;
			case EH:							//ԭ�����������ȸߣ�������������ʹ������                                    
				p->bf=LH;    
				break;
			case RH:							//�½�����*p����Ů���������ϣ������������˫������                                    
				rc=lp->ptnRight;				//ptnRightָ��*p����Ů�������������                                    
				switch(rc->bf)					//����*p��������Ů��ƽ������                                    
				{ 
				case LH:
					p->bf=RH;
					lp->bf=EH;
					break;
				case EH:
					p->bf=lp->bf=EH;
					break;
				case RH:
					p->bf=EH;
					lp->bf=LH;
					break;
				}//switch(ptnRight->bf)                                    
				rc->bf=EH;        
				L_Rotate(p->ptnLeft);         //��*p��������������ת����                                    
				R_Rotate(p);						//��*t������ת����                                    
				break;
			}//switch(p->bf)                                    
		}//LeftBalance                                    

		//����*pָ��Ľ��Ϊ��������������ƽ����ת��������֮��*pָ��Ľ��Ϊ�������¸�                                    
		inline void RightBalance(pBTreeNode &p)
		{
			pBTreeNode lp, lc;
			lp=p->ptnRight;					//lpָ��*p�����������                                    
			switch(p->bf)					//���*pƽ��ȣ�������Ӧ����                                    
			{
			case RH:							//�½�����*p����Ů���������ϣ�����������ת����                                    
				p->bf=lp->bf=EH;
				L_Rotate(p);
				break;
			case EH:							//ԭ�����������ȸߣ�������������ʹ������                                    
				p->bf=RH;    
				break;
			case LH:							//�½�����*p����Ů���������ϣ��������Һ���˫������                                    
				lc=lp->ptnLeft;					//ptnLeftָ��*p����Ů�������������                                    
				switch(lc->bf)					//����*p��������Ů��ƽ������                                    
				{ 
				case RH:
					p->bf=LH;
					lp->bf=EH;
					break;
				case EH:
					p->bf=lp->bf=EH;
					break;
				case LH:
					 p->bf=EH;
					 lp->bf=RH;
					 break;
				}//switch(ptnLeft->bf)                                    
				lc->bf=EH;        
				R_Rotate(p->ptnLeft);         //��*p��������������ת����                                    
				L_Rotate(p);        //��*t������ת����                                    
			}//switch(p->bf)                                    
		}//RightBalance                                    


	public:
		//��ӽڵ�
		inline void  insertNode(pBTreeNode & pptnHead,const T &value,int &taller)
		{
			pBTreeNode ptnCurr;
			ptnCurr = pptnHead;
			if(ptnCurr == NULL)
			{
				ptnCurr = new BTreeNode();//(pBTreeNode)malloc(sizeof(struct BTreeNode)); 
				ptnCurr->value = value;
				ptnCurr->ptnLeft = NULL;
				ptnCurr->ptnRight = NULL;
				ptnCurr->bf = EH;
				taller = True;
				pptnHead = ptnCurr;
			}
			else if(ptnCurr->value > value)
			{
				insertNode(ptnCurr->ptnLeft, value,taller);
				if(taller)										//�Ѳ��뵽(*t)���������У�������������                                    
				{
					switch(ptnCurr->bf)							//���*tƽ���                                    
					{
					case  LH:								//ԭ���������ߣ�������ƽ�⴦��                                    
						LeftBalance(pptnHead);
						taller=False;
						break;
					case  EH:								//ԭ�����������ȸߣ�������������ʹ������                                    
						ptnCurr->bf=LH;
						taller=True;
						break;
					 case  RH:								//ԭ���������ߣ�ʹ���������ȸ�                                    
						ptnCurr->bf=EH;
						taller=False;
						break;
					}
				}
			}
			else
			{
				insertNode(ptnCurr->ptnRight, value, taller);
				if(taller)									//�Ѳ��뵽(*t)���������У�������������                                    
				{
					switch(ptnCurr->bf)						//���*tƽ���                                    
					{
					case LH:								//ԭ���������ߣ�ʹ���������ȸ�                                    
						ptnCurr->bf=EH;
						taller=False;
						break;
					case EH:								//ԭ�����������ȸߣ�������������ʹ������                                    
						ptnCurr->bf=RH;
						taller=True;
						break;
					case RH:								//ԭ���������ߣ�������ƽ�⴦��                                    
						RightBalance(pptnHead);
						taller=False;
						break;
					}
				}
			}
		}

		inline void  insertNode(const T &value,int &taller)
		{
			insertNode(this->root,value,taller);
		}
		inline void  insertNode(const T &value)
		{
			insertNode(this->root,value,taller);
		}
		inline pBTreeNode &getRoot(){return root;};
		//�����������ʹ֮��Ϊһ�ÿ��� */ 
		inline void clear(pBTreeNode &pptnHead) 
		{
			if(pptnHead != NULL)
			{ 
				clear(pptnHead->ptnLeft);
				clear(pptnHead->ptnRight);
				delete pptnHead;
				pptnHead = NULL; 
			}
		}
		//��������ж������ڵ�(ǰ�����) 
		inline void print(pBTreeNode &pptnHead) 
		{ 
			if(pptnHead != NULL)// ��Ϊ��ʱ�����ݹ飬����ִ�����²���                                      
			{ 
				cout<<pptnHead->value;
				if(pptnHead->ptnLeft != NULL || pptnHead->ptnRight != NULL)
				{ 
					cout<<"(";
					print(pptnHead->ptnLeft); 
					if(pptnHead->ptnRight != NULL)
					{ 
						cout<<",";
					} 
					print(pptnHead->ptnRight); 
					cout<<")"; 
				} 
			} 
		} 

		//ǰ�����
		inline void printPre(pBTreeNode &pptnHead) 
		{ 
			if(pptnHead != NULL)
			{ 
				cout<<pptnHead->value<<" ";		// ���ʸ����                                      
				printPre(pptnHead->ptnLeft);	// ǰ�����������                                      
				printPre(pptnHead->ptnRight);	// ǰ�����������                                      
			}
		}
		//������� 
		inline void printMid(pBTreeNode &pptnHead) 
		{ 
			if(pptnHead != NULL)
			{ 
				printMid(pptnHead->ptnLeft);		// �������������                                      
				cout<<pptnHead->value<<" ";		// ���ʸ����                                      
				printMid(pptnHead->ptnRight);	// �������������                                      
			}
		} 

		//�������
		inline void printPost(pBTreeNode &pptnHead) 
		{ 
			if(pptnHead != NULL)
			{
				printPost(pptnHead->ptnLeft);	// �������������                                      
				printPost(pptnHead->ptnRight); // �������������                                      
				cout<<pptnHead->value<<" ";		// ���ʸ����                                      
			}
		}
		//�������
		inline void printLevel(pBTreeNode &pptnHead) 
		{ 
			pBTreeNode p; 
			Common::Array<pBTreeNode> q;
			int front = 0, rear = 0;
			if(pptnHead != NULL)				// ������ָ�����                                      
			{	
				q[rear++] = pptnHead; 
			} 
			while(front != rear)				//���ǿ�                                      
			{
				p = q[front++];
				cout<<p->value<<" ";
				if(p->ptnLeft != NULL)			// �����������ӣ������ӽ��ָ�����                                      
				{
					q[rear++] = p->ptnLeft;
				}
				if(p->ptnRight != NULL)			// ���������Һ��ӣ����Һ��ӽ��ָ�����                                      
				{
					q[rear++] = p->ptnRight; 
				} 
			}
			cout<<endl;
			return; 
		} 
		//���������� 
		inline int getDepth(pBTreeNode &pptnHead) 
		{ 
			if(pptnHead == NULL) 
			{ 
				return 0; 
			} 
			else 
			{ 
				int dep1 = getDepth(pptnHead->ptnLeft); // ���������������                                      
				int dep2 = getDepth(pptnHead->ptnRight); // ���������������                                      
				if(dep1 > dep2) 
				{ 
					return dep1 + 1; 
				} 
				else 
				{ 
					return dep2 + 1; 
				} 
			} 
		} 

		//����������(����a��ָ��Ķ�����������ַ�������) 
		bool createBTree(pBTreeNode &pptnHead, char *a) 
		{
			Common::Array<pBTreeNode> q;
			pBTreeNode p; 
			int top = -1;			// ����top��Ϊsջ��ջ��ָ�룬��ֵΪ-1,��ʾ��ջ                                      
			int k;					// ��k��Ϊ�����������������������k = 1������������k = 2����������                                      
			int i = 0;				// ��iɨ������a�д洢�Ķ�����������ַ�������ֵΪ0                                      
			pptnHead= NULL;			// ������ָ����Ϊ�գ����ӿ�����ʼ����������                                      
			vector<pBTreeNode> s;
			while(a[i] != '\0') 
			{ 
				switch(a[i]) 
				{ 
				case ' ': 
					break; 

				case '(': 
					top++; 
					s[top] = p; 
					k = 1; 
					break;
				case ')': 
					if(top == -1) 
					{ 
						printf("������������ַ�������!\n"); 
						return false; 
					} 
					top--; 
					break;

				case ',': 
					k = 2; 
					break;
				default: 
					p = (pBTreeNode)malloc(sizeof(struct BTreeNode));
					p->value = a[i]; 
					p->ptnLeft = p->ptnRight = NULL;
					if(pptnHead == NULL) 
					{ 
						pptnHead = p; 
					} 
					else 
					{ 
						if( k == 1) 
						{ 
							s[top]->ptnLeft = p; 
						}else 
						{ 
							s[top]->ptnRight = p; 
						} 
					} 
				} 
				i++; 
			} 
			return true; 
		} 

		inline void clear()
		{
			clear(this->root);
		};
		//��ӡ�����ж�����(ǰ�����) 
		inline void print()
		{
			print(this->root);
		}
		//ǰ�����
		inline void printPre()
		{
			printPre(this->root);
		}
		//������� 
		inline void printMid()
		{
			printMid(this->root);
		}
		//�������
		inline void printPost()
		{
			printPost(this->root);
		}
		//�������
		inline void printLevel()
		{
			printLevel(this->root);
		}
		inline bool empty(){return (root == NULL);};
		inline int getDepth(){return getDepth(this->root);};
		inline bool createBTree(char *a) {return createBTree(this->root,a) ;};
		//���ҽڵ� rebound:�Ƿ��дֵ��value,	ֻ�е�TΪ��ʱ��Ҫ
		inline int search(T &value,bool rebound=false)
		{
			return search(this->root,value,rebound);
		}
		inline int search(pBTreeNode &pptnHead, T &value,bool rebound=false)
		{
			pBTreeNode ptnCurr = pptnHead;
			if (NULL == ptnCurr)
			{
				return RET_NOFOUND;
			}
			while(ptnCurr != NULL)
			{
				if(ptnCurr->value == value)
				{
					if(rebound)value=ptnCurr->value;
					return RET_FOUND;
				}
				else if(ptnCurr->value > value)
				{
					ptnCurr = ptnCurr->ptnLeft;
				}
				else
				{
					ptnCurr = ptnCurr->ptnRight;
				}
			}
			return RET_NOFOUND;
		}
	};
#undef  LH
#undef  EH
#undef  RH
#undef  True
#undef  False
#undef  RET_FOUND
#undef  RET_NOFOUND
}
//int main(int argc, char *argv[])
//{
//	pBTreeNode root=NULL;
//	insertNode(&root,1,&taller);
//	insertNode(&root,2,&taller);
//	insertNode(&root,3,&taller);
//	insertNode(&root,4,&taller);
//	insertNode(&root,5,&taller);
//	insertNode(&root,6,&taller);
//	insertNode(&root,7,&taller);
//	insertNode(&root,8,&taller);
//	insertNode(&root,9,&taller);
//	insertNode(&root,10,&taller);
//	insertNode(&root,11,&taller);
//	insertNode(&root,12,&taller);
//	insertNode(&root,13,&taller);
//	insertNode(&root,14,&taller);
//	insertNode(&root,15,&taller);
//	//insertNode(&root,16,&taller);
//	printf("�����\n");
//	printBTree(&root);
//	printf("\nǰ��\n");
//	preOrder(&root);
//	printf("\n����\n");
//	inOrder(&root);
//	printf("\n����\n");
//	postOrder(&root);
//	printf("\n����\n");
//	levelOrder(&root);
//	system("pause");
//	return 0;
//}
#endif
