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
		#define  LH  1         // 左高                                     
		#define  EH  0         // 等高                                     
		#define  RH  -1        // 右高                                     
		#define  True 1
		#define  False 0
		#define  RET_FOUND       1
		#define  RET_NOFOUND     0
	public:
		struct BTreeNode
		{
		public:
			BTreeNode  * ptnLeft;     // 左指针
			BTreeNode  * ptnRight;    // 右指针
			int    bf;                // 平衡因子
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
		// 全局変数                                     
		int taller;
		pBTreeNode root;

		//平衡二叉树调整操作                                    
		inline void L_Rotate(pBTreeNode &p)
		{
			pBTreeNode lp;					//对以*p指向的结点为根的子树，作左单旋转处理，处理之后，*p指向的结点为子树的新根                                    
			lp=p->ptnRight;					//lp指向*p右子树根结点                                    
			p->ptnRight=lp->ptnLeft;		//lp的左子树挂接*p的右子树                                    
			lp->ptnLeft=p; 
			p=lp;							// *p指向新的根结点                                    
		}
		inline void R_Rotate(pBTreeNode &p)
		{	
			pBTreeNode lp;					//对以*p指向的结点为根的子树，作右单旋转处理，处理之后，*p指向的结点为子树的新根                                    
			lp=p->ptnLeft;					//lp指向*p左子树根结点                                    
			p->ptnLeft=lp->ptnRight;		//lp的右子树挂接*p的左子树                                    
			lp->ptnRight=p; 
			p=lp;							//  *p指向新的根结点                                    
		}

		//对以*p指向的结点为根的子树，作左平衡旋转处理，处理之后，*p指向的结点为子树的新根                                    
		inline void LeftBalance(pBTreeNode &p)
		{
			pBTreeNode lp, rc;
			lp=p->ptnLeft;						//lp指向*p左子树根结点                                    
			switch(p->bf)						//检查*p平衡度，并作相应处理                                    
			{
			case LH:							//新结点插在*p左子女的左子树上，需作单右旋转处理                                    
				p->bf=lp->bf=EH;
				R_Rotate(p);
				break;
			case EH:							//原本左、右子树等高，因左子树增高使树增高                                    
				p->bf=LH;    
				break;
			case RH:							//新结点插在*p左子女的右子树上，需作先左后右双旋处理                                    
				rc=lp->ptnRight;				//ptnRight指向*p左子女的右子树根结点                                    
				switch(rc->bf)					//修正*p及其左子女的平衡因子                                    
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
				L_Rotate(p->ptnLeft);         //对*p的左子树作左旋转处理                                    
				R_Rotate(p);						//对*t作右旋转处理                                    
				break;
			}//switch(p->bf)                                    
		}//LeftBalance                                    

		//对以*p指向的结点为根的子树，作左平衡旋转处理，处理之后，*p指向的结点为子树的新根                                    
		inline void RightBalance(pBTreeNode &p)
		{
			pBTreeNode lp, lc;
			lp=p->ptnRight;					//lp指向*p右子树根结点                                    
			switch(p->bf)					//检查*p平衡度，并作相应处理                                    
			{
			case RH:							//新结点插在*p左子女的右子树上，需作单左旋转处理                                    
				p->bf=lp->bf=EH;
				L_Rotate(p);
				break;
			case EH:							//原本左、右子树等高，因左子树增高使树增高                                    
				p->bf=RH;    
				break;
			case LH:							//新结点插在*p左子女的左子树上，需作先右后左双旋处理                                    
				lc=lp->ptnLeft;					//ptnLeft指向*p右子女的左子树根结点                                    
				switch(lc->bf)					//修正*p及其右子女的平衡因子                                    
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
				R_Rotate(p->ptnLeft);         //对*p的右子树作右旋转处理                                    
				L_Rotate(p);        //对*t作左旋转处理                                    
			}//switch(p->bf)                                    
		}//RightBalance                                    


	public:
		//添加节点
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
				if(taller)										//已插入到(*t)的左子树中，且左子树增高                                    
				{
					switch(ptnCurr->bf)							//检查*t平衡度                                    
					{
					case  LH:								//原本左子树高，需作左平衡处理                                    
						LeftBalance(pptnHead);
						taller=False;
						break;
					case  EH:								//原本左、右子树等高，因左子树增高使树增高                                    
						ptnCurr->bf=LH;
						taller=True;
						break;
					 case  RH:								//原本右子树高，使左、右子树等高                                    
						ptnCurr->bf=EH;
						taller=False;
						break;
					}
				}
			}
			else
			{
				insertNode(ptnCurr->ptnRight, value, taller);
				if(taller)									//已插入到(*t)的左子树中，且右子树增高                                    
				{
					switch(ptnCurr->bf)						//检查*t平衡度                                    
					{
					case LH:								//原本左子树高，使左、右子树等高                                    
						ptnCurr->bf=EH;
						taller=False;
						break;
					case EH:								//原本左、右子树等高，因右子树增高使树增高                                    
						ptnCurr->bf=RH;
						taller=True;
						break;
					case RH:								//原本右子树高，需作右平衡处理                                    
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
		//清除二叉树，使之变为一棵空树 */ 
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
		//输出表序列二叉树节点(前序遍历) 
		inline void print(pBTreeNode &pptnHead) 
		{ 
			if(pptnHead != NULL)// 树为空时结束递归，否则执行如下操作                                      
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

		//前序遍历
		inline void printPre(pBTreeNode &pptnHead) 
		{ 
			if(pptnHead != NULL)
			{ 
				cout<<pptnHead->value<<" ";		// 访问根结点                                      
				printPre(pptnHead->ptnLeft);	// 前序遍历左子树                                      
				printPre(pptnHead->ptnRight);	// 前序遍历右子树                                      
			}
		}
		//中序遍历 
		inline void printMid(pBTreeNode &pptnHead) 
		{ 
			if(pptnHead != NULL)
			{ 
				printMid(pptnHead->ptnLeft);		// 中序遍历左子树                                      
				cout<<pptnHead->value<<" ";		// 访问根结点                                      
				printMid(pptnHead->ptnRight);	// 中序遍历右子树                                      
			}
		} 

		//后序遍历
		inline void printPost(pBTreeNode &pptnHead) 
		{ 
			if(pptnHead != NULL)
			{
				printPost(pptnHead->ptnLeft);	// 后序遍历左子树                                      
				printPost(pptnHead->ptnRight); // 后序遍历右子树                                      
				cout<<pptnHead->value<<" ";		// 访问根结点                                      
			}
		}
		//按层遍历
		inline void printLevel(pBTreeNode &pptnHead) 
		{ 
			pBTreeNode p; 
			Common::Array<pBTreeNode> q;
			int front = 0, rear = 0;
			if(pptnHead != NULL)				// 将树根指针进队                                      
			{	
				q[rear++] = pptnHead; 
			} 
			while(front != rear)				//树非空                                      
			{
				p = q[front++];
				cout<<p->value<<" ";
				if(p->ptnLeft != NULL)			// 若结点存在左孩子，则左孩子结点指针进队                                      
				{
					q[rear++] = p->ptnLeft;
				}
				if(p->ptnRight != NULL)			// 若结点存在右孩子，则右孩子结点指针进队                                      
				{
					q[rear++] = p->ptnRight; 
				} 
			}
			cout<<endl;
			return; 
		} 
		//求二叉树深度 
		inline int getDepth(pBTreeNode &pptnHead) 
		{ 
			if(pptnHead == NULL) 
			{ 
				return 0; 
			} 
			else 
			{ 
				int dep1 = getDepth(pptnHead->ptnLeft); // 计算左子树的深度                                      
				int dep2 = getDepth(pptnHead->ptnRight); // 计算右子树的深度                                      
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

		//建立二叉树(根据a所指向的二叉树广义表字符串建立) 
		bool createBTree(pBTreeNode &pptnHead, char *a) 
		{
			Common::Array<pBTreeNode> q;
			pBTreeNode p; 
			int top = -1;			// 定义top作为s栈的栈顶指针，初值为-1,表示空栈                                      
			int k;					// 用k作为处理结点的左子树和右子树，k = 1处理左子树，k = 2处理右子树                                      
			int i = 0;				// 用i扫描数组a中存储的二叉树广义表字符串，初值为0                                      
			pptnHead= NULL;			// 把树根指针置为空，即从空树开始建立二叉树                                      
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
						printf("二叉树广义表字符串错误!\n"); 
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
		//打印表序列二叉树(前序遍历) 
		inline void print()
		{
			print(this->root);
		}
		//前序遍历
		inline void printPre()
		{
			printPre(this->root);
		}
		//中序遍历 
		inline void printMid()
		{
			printMid(this->root);
		}
		//后序遍历
		inline void printPost()
		{
			printPost(this->root);
		}
		//后序遍历
		inline void printLevel()
		{
			printLevel(this->root);
		}
		inline bool empty(){return (root == NULL);};
		inline int getDepth(){return getDepth(this->root);};
		inline bool createBTree(char *a) {return createBTree(this->root,a) ;};
		//查找节点 rebound:是否回写值到value,	只有当T为类时需要
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
//	printf("广义表\n");
//	printBTree(&root);
//	printf("\n前序\n");
//	preOrder(&root);
//	printf("\n中序\n");
//	inOrder(&root);
//	printf("\n后序\n");
//	postOrder(&root);
//	printf("\n按层\n");
//	levelOrder(&root);
//	system("pause");
//	return 0;
//}
#endif
