// ==============================================================
//progame      Common::calExp  simpleness expression calculate
//company      hans
//copyright    Copyright (c) hans  2007-4     2008-03
//version      1.0
//Author       hans
//date         2007-4     2008-04
//description  simpleness expression calculate
//				This library is free software. Permission to use, copy,
//				modify and redistribute it for any purpose is hereby granted
//				without fee, provided that the above copyright notice appear
//				in all copies.
//description  动态执行表达式，可以支持函数运算以及变量引用   支持+ - * / % ~(幂 **)  && || ! & | ^
// ==============================================================

#ifndef __Common_Eval__
#define __Common_Eval__
#include "Common.h"
namespace Common
{
	namespace Eval
	{
		using namespace Common;
		template< typename N > N eval( const char* E );
		template< typename N > N eval( const char* E, hashTable< string, N >& V );
		template< typename N, typename F > N eval( const char* E, hashTable< string, N >& V, F& f );

		template< typename N > class DF
		{
		public:
			N operator()( const char*, const vector< N >& P )
			{
				throw Exception( "unexisting function called" );
			}
		};

		template< typename N > N eval( const char* E )
		{
			hashTable< string, N > V;
			DF< N > f;
			return eval( E, V, f );
		}

		template< typename N > N eval( const char* E, hashTable< string, N >& V )
		{
			DF< N > f;
			return eval( E, V, f );
		}

		template< typename N, typename F > class evaler
		{
			hashTable< string, N >& MV;
			F& MF;
			const char* MC;
			enum TT
			{
				AP = '+',
				SN = '-',
				MU = '*',
				DI = '/',
				MO = '%',
				PO = '~',
				LB = '(',
				RB = ')',
				PS = ',',

				GT = '>',		// 新加
				LT = '<', 
				EQ = '=', 
				NQ = '!',
				AND = '&',
				OR = '|',
				AR = '^',

				I = 257,
				U = 258,
				FI = 259
			};
			TT MTT;
			string MI;
			N MVA;
			void L()
			{
				for(;;)
				{
					if( isspace( *MC ) )
					{
						++MC;
						continue;
					}
					else if( *MC == '*' && *( MC + 1 ) == '*' )
						MTT = PO, MC += 2;
					else if( *MC == AP || *MC == SN ||
						*MC == MU || *MC == DI ||
						*MC == LB || *MC == RB ||
						*MC == PS || *MC == MO ||
						*MC == GT || *MC == LT ||
						*MC == EQ || *MC == NQ ||
						*MC == AND || *MC == OR ||
						*MC == AR
						)
						MTT = ( TT )*MC, ++MC;
					else if( isalpha( *MC ) )
					{
						MTT = I;
						MI.clear();
						MI += *MC;
						++MC;
						while( isalpha( *MC ) || isdigit( *MC ) )
							MI += *MC, ++MC;
					}
					else if( *MC == 0)
						MTT = FI;
					else
					{
						MTT = U;
						if(isdigit( *MC ) )MVA=atof(MC);
						else throw Exception( "error in format" );
						while(isdigit( *MC )  || *MC=='.')++MC;
						//istringstream iss( MC );
						//iss >> MVA;
						//if( ! iss )
						//	throw Exception( "error in format" );
						//MC += iss.rdbuf()->pubseekoff( 0, ios::cur, ios::in );
					}
					break;
				}
			}
			bool getNextBoolOperIndex()
			{
				const char * temp=MC;
				int subLp=0;
				while(*temp)
				{
					if(*temp=='(')
						subLp++;
					else if(*temp==')')
					{
						if(subLp)
							subLp--;
						else
							break;
					}
					else if(subLp==0)
					{
						if((MTT==AND && *temp=='&' && temp[1]=='&') || 
							(MTT==OR && *temp=='|' && temp[1]=='|'))
							temp++;
						else if((MTT==OR && *temp=='&' && temp[1]=='&') || 
							(MTT==AND && *temp=='|' && temp[1]=='|'))
							break;
						//else if(!isspace(*temp))
					}
					temp++;
				}
				subLp=temp-MC;
				MC=temp; 
				return subLp;
			}
			void M( TT TT )
			{
				if( MTT == TT )
					L();
				else
					error();
			}
			void error(){EXP("语法错误: \""+String(MC)+"\" tokenString=\""+MTT+"\" ");}
			N logic()
			{
				N tmp = bitOperation();
				while((MTT==AND && *MC==AND) || ( MTT==OR && *MC==OR ))
				{
					switch(MTT)
					{
					case AND:
						if(!tmp)
						{
							if(getNextBoolOperIndex())
								L();
							else
								return tmp;
							break;
						}
						MC++;
						M(AND);
						tmp = tmp && bitOperation();
						break;
					case OR:
						if(tmp)
						{
							if(getNextBoolOperIndex())
								L();
							else
								return tmp;
							break;
						}
						MC++;
						M(OR);
						tmp = tmp || bitOperation();
	 					break;
					}
				}
				return tmp;
			};
			N bitOperation()
			{
				N tmp = condition();
				while((MTT == AND || MTT == OR || MTT == AR) && *MC!=AND && *MC!=OR)
				{
					switch(MTT)
					{
					case AND: 
						M(AND);
						tmp = (long)tmp & (long)condition();
						break;
					case OR:
						M(OR);
						tmp = (long)tmp | (long)condition();
						break;
					case AR:
						M(AR);
						tmp = (long)tmp ^ (long)condition();
						break;
					}
				}
				return tmp;
			};
			N condition()
			{
				N tmp = plusOperation();
				while((MTT == GT || MTT == LT || MTT == EQ || MTT == NQ) && *MC!=AND && *MC!=OR)
				{
					switch(MTT)
					{
					case GT: 
						{
							if(*MC==EQ)
							{
								MC++;
								M(GT);
								tmp = tmp>= plusOperation();
							}
							else
							{
								M(GT);
								tmp = tmp> plusOperation();
							}
							break;
						}
					case LT:
						{
							if(MTT==EQ)
							{
								MC++;
								M(LT);
								tmp = tmp<= plusOperation();
							}
							else
							{
								M(LT);
								tmp = tmp< plusOperation();
							}
							break;
						}
					case EQ:
					case NQ:
						{
							if(*MC!=EQ)
							{
								error();
							}
							MC++;
							if(MTT==EQ)
							{
								M(EQ);
								tmp = tmp== plusOperation();
								break;
							}
							else
							{
								M(NQ);
								tmp = tmp!= plusOperation();
								break;
							}
						}
					}
				}
				return tmp;
			}
			N plusOperation()
			{
				N tmp = multiplication();
				while(MTT == AP || MTT == SN)
				{
					switch(MTT)
					{
					case AP: 
						{
							M(AP);
							tmp += multiplication();
							break;
						}
					case SN:
						{
							M(SN);
							tmp -= multiplication();
							break;
						}
					}
				}
				return tmp;
			}
			N multiplication()
			{
				N tmp = powerOperation();
				while(MTT == MU || MTT == DI || MTT == MO)
				{
					switch(MTT)
					{
					case '*':
						{
							M(MU);
							tmp *= powerOperation();
							break;
						}
					case '/':
						{
							M(DI);
							tmp /= powerOperation();
							break;
						}
					case '%':
						{
							M(MO);
							tmp = abs((long)tmp) %abs((long)(powerOperation()));
							break;
						}
					}
				}
				return tmp;
			}
			N powerOperation()
			{
				N tmp = bracket();
				while(MTT == PO)
				{
					switch(MTT)
					{
					case PO:
						{
							M(PO);
							tmp = pow( tmp, static_cast< int >( bracket() ) );
							break;
						}
					}
				}
				return tmp;
			};
			N bracket()
			{
				N tmp;
				if(MTT == LB)
				{
					M(LB);
					tmp = logic();
					M(RB);
				}
				else if(MTT==U)
					tmp=MVA,M(U);
				else if(MTT=='-'|| MTT=='+' )
				{
					if(isdigit(*MC))
					{

						tmp =((MTT==SN)?-atof(MC):atof(MC));
						MC++;
						while(isdigit( *MC )  || *MC=='.')++MC;
						M(MTT);
					}
					else
					{
 						if(MTT==SN)
						{
							M(SN);
							if(MTT==I)
								tmp = - LS();
							else
								error();
						}
						else
						{
							M(AP);
							if(MTT==I)
								tmp = LS();
							else
								error();
						}
					}
				}
				else if( MTT == I )
					tmp = LS();
				else
					error();
				return tmp;
			}
			N LS()	//函数，标识符运算
			{
				string id = MI;
				M( I );
				return FUNC( id );
			}
			N FUNC( const string& id )  //函数，标识符运算
			{
				N R;
				if( MTT == LB )
				{
					M( LB );
					vector< N > P = PL();
					R = MF( id.c_str(), P );
				}
				else
				{
					if(MV.find(id,R)==false)
						throw Exception( "cannot find variable" );
				}
				return R;
			}
			vector< N > PL()
			{
				vector< N > R;
				for(;;)
				{
					if( MTT == RB )
					{
						M( RB );
						break;
					}
					R.push_back( logic() );
					PT( R );
				}
				return R;
			}
			void PT( vector< N >& P )
			{
				if( MTT == PS )
					M( PS ), P.push_back( logic() ), PT( P );
			}
		public:
			evaler( hashTable< string, N >& V, F& f ): MV( V ), MF( f ){}
			N operator()( const char* expr )
			{
				MC = expr;
				L();
				N R = logic();
				if( MTT != FI )
					error();
				return R;
			}
		};

		template< typename N, typename F > N eval( const char* E, hashTable< string, N >& V, F& f )
		{
			return evaler< N, F >( V, f )( E );
		}
	};
}
#endif
