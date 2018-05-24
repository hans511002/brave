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
// ==============================================================

#ifndef __Common_CalExpr__
#define __Common_CalExpr__
#include "Common.h"

namespace Common
{
	//支持 + - * / % & | ^ > >= < <= == !=
	template <class T > class calcExp
	{
#define CALEXPR_MAX_TOKEN_LEN 256
	protected:
		typedef enum
		{
			// 文件结尾
			ENDFILE,
			// 表达式错误
			EXPERROR,
			// + - * / % ( )符号之一
			SYMBOL,
			// 数字
			NUM,
		} TokenType;
		typedef enum
		{
			START,		// 开始状态
			INUM,		// 数字的中间状态
			DOT,		// 接受到符号.的状态
			END			// 结束状态
		} StateType;
		const char * buffer;
		unsigned int bufIndex;
		unsigned int bufferLen;
		char tokenString[CALEXPR_MAX_TOKEN_LEN];
		inline char getNextChar()
		{
			if(bufIndex<bufferLen) return buffer[bufIndex++];
			return EOF;
		}
		// 输出错误信息
		inline void error(){EXP("语法错误: \""+String(buffer)+"\" tokenString=\""+tokenString+"\" bufIndex="+String((int)bufIndex) + " bufferLen="+(int)bufferLen);}
		// 缓冲区回退一个字符
		inline void ungetNextChar(){bufIndex--;}

		//match函数
		inline void match(const char* expectedToken)
		{
			if(strcmp(expectedToken, tokenString) == 0)
				getToken();
			else if((expectedToken[0]=='-' && tokenString[0] =='-')||(expectedToken[0]=='+' && tokenString[0] =='+'))
			{
				int i=1;
				while(tokenString[i])
				{
					tokenString[i-1]=tokenString[i++];
				}
				tokenString[i-1]=0;
			}
			else
				error();
		}
		// 获取缓冲区下一个token，并返回token的类型
		inline TokenType getToken()
		{
			int tokenIndex = 0;
			TokenType currentType;
			StateType state = START;
			bool save;
			while(state != END)
			{
				char c = getNextChar();
				save = true;
				switch(state) 
				{
				case START:
					{
						if(c==32 || c=='\t')
						{
							continue;
						}
						if(isdigit(c))
						{
							state = INUM;
							break;
						}
						switch(c)
						{
						case '+':
						case '-':
						case '*':
						case '/': 
						case '%': 
						case '~': 
						case '(': 
						case ')': 
						case '>': 
						case '<': 
						case '=': 
						case '!':
						case '&':
						case '|':
						case '^':
							{
								currentType = SYMBOL;
								char nc = getNextChar();
								ungetNextChar();
								if((c=='-' && isdigit(nc))||(c=='+' && isdigit(nc)))
								{
									currentType = NUM;
									state = INUM;break;
								}
								if(c == '>' || c == '<' || c == '=' || c == '!')
								{
									if(tokenIndex == 0 && nc == '=')break;
								}
								else if(c == '&' || c == '|')
								{
									if(tokenIndex == 0 && nc == c)break;
								}
								state = END;
								break;
							}
						case EOF:
							{
								currentType = ENDFILE;
								state = END;
								break;
							}
						default:
							currentType = EXPERROR;
							state = END;
							break;
						}
						break;
					}
				case INUM:
					{
						if(c == '.')
							state = DOT;
						else if(c == EOF)
						{
							currentType = NUM;
							state = END;
						}
						else if(!isdigit(c))
						{
							ungetNextChar();
							save = false;
							currentType = NUM;
							state = END;
						}
						break;
					}
				case DOT:
					{
						if(isdigit(c))
							state = INUM;
						else
						{
							currentType = EXPERROR;
							state = END;
						}
						break;
					}
				}
				if(save && tokenIndex < CALEXPR_MAX_TOKEN_LEN && c!= EOF)
					tokenString[tokenIndex++] = c;
				if(state == END)
					tokenString[tokenIndex] = '\0';

			}
			return currentType;
		}

		inline bool getNextBoolOperIndex()
		{
			const char * temp=buffer+bufIndex;
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
					if(strncmp(tokenString,temp,2)==0)
						temp++;
					else if((strncmp(tokenString,"||",2)==0 && *temp=='&' && temp[1]=='&') || 
						(strncmp(tokenString,"&&",2)==0 && *temp=='|' && temp[1]=='|'))
						break;
					//else if(!isspace(*temp))
				}
				temp++;
			}
			subLp=bufferLen-bufIndex;
			bufIndex=temp-buffer;
			return subLp;
		}
		//计算逻辑表达式
		inline T logic()
		{
			T tmp = bitOperation();
			while((tokenString[0] == '&' && tokenString[1]=='&') || (tokenString[0] == '|' && tokenString[1] == '|'))
			{
				switch(tokenString[0])
				{
				case '&': 
					
					if(!tmp)
					{
						if(getNextBoolOperIndex())
							getToken();
						else
							return tmp;
						break;
					}
					if(bufIndex<bufferLen)
					{
						match("&&");
						tmp = tmp && bitOperation();
					}
					break;
				case '|':
					if(tmp)
					{
						if(getNextBoolOperIndex())
							getToken();
						else
							return tmp;
						break;
					}
					if(bufIndex<bufferLen)
					{
						match("||");
						tmp = tmp || bitOperation();
					}
	 				break;
				}
			}
			return tmp;
		};
		//计算位运算表达式  & | ^ 
		inline T bitOperation()
		{
			T tmp = condition();
			while((tokenString[0] == '&' || tokenString[0] == '|' || tokenString[0] == '^') && tokenString[1]==0)
			{
				switch(tokenString[0])
				{
				case '&': 
					match("&");
					tmp = (long)tmp & (long)condition();
					break;
				case '|':
					match("|");
					tmp = (long)tmp | (long)condition();
					break;
				case '^':
					match("^");
					tmp = (long)tmp ^ (long)condition();
					break;
				}
			}
			return tmp;
		};
		//计算条件表达式 > >= < <= == !=
		inline T condition()
		{
			T tmp = plusOperation();
			while(tokenString[0] == '>' || tokenString[0] == '<' || tokenString[0] == '=' || tokenString[0] == '!')
			{
				switch(tokenString[0])
				{
				case '>': 
					{
						if(tokenString[1]=='=')
						{
							match(">=");
							tmp = tmp>= plusOperation();
						}
						else
						{
							match(">");
							tmp = tmp> plusOperation();
						}
						break;
					}
				case '<':
					{
						if(tokenString[1]=='=')
						{
							match("<=");
							tmp = tmp<= plusOperation();
						}
						else
						{
							match("<");
							tmp = tmp< plusOperation();
						}
						break;
					}
				case '=':
				case '!':
					{
						if(tokenString[1]==0)
							tokenString[1]='=';
						else if(tokenString[1]!='=')
						{
							error();
						}
						if(tokenString[0]=='=')
						{
							match("==");
							tmp = tmp== plusOperation();
							break;
						}
						else
						{
							match("!=");
							tmp = tmp!= plusOperation();
							break;
						}
					}
				}
			}
			return tmp;
		}
		//计算加减
		inline T plusOperation()
		{
			T tmp = multiplication();
			while(tokenString[0] == '+' || tokenString[0] == '-')
			{
				switch(tokenString[0])
				{
				case '+': 
					{
						match("+");
						tmp += multiplication();
						break;
					}
				case '-':
					{
						match("-");
						tmp -= multiplication();
						break;
					}
				}
			}
			return tmp;
		}
		//计算乘法
		inline T multiplication()
		{
			T tmp = powerOperation();
			while(tokenString[0] == '*' || tokenString[0] == '/' || tokenString[0] == '%')
			{
				switch(tokenString[0])
				{
				case '*':
					{
						match("*");
						tmp *= powerOperation();
						break;
					}
				case '/':
					{
						match("/");
						tmp /= powerOperation();
						break;
					}
				case '%':
					{
						match("%");
						tmp = abs((long)tmp) %abs((long)(powerOperation()));
						break;
					}
				}
			}
			return tmp;
		}
		inline T powerOperation()
		{
			T tmp = bracket();
			while(tokenString[0] == '~')
			{
				switch(tokenString[0])
				{
				case '~':
					{
						match("~");
						tmp = pow( tmp, static_cast< int >( bracket() ) );
						break;
					}
				}
			}
			return tmp;
		};
		//使用逻辑运算的()操作
		inline T bracket()
		{
			T tmp;
			if(tokenString[0] == '(')
			{
				match("(");
				tmp = logic();
				match(")");
			}
			else if(isdigit(tokenString[0]) || (tokenString[0]=='-' && isdigit(tokenString[1])) || (tokenString[0]=='+' && isdigit(tokenString[1])))
			{
				if(sizeof(T)==4)
				tmp = atoi(tokenString);
				else
				tmp = atof(tokenString);
				getToken();
			}
			else
				error();
			return tmp;
		}
	public:
		calcExp(){};
		inline bool calBool(const char * s,unsigned len)
		{
			bufIndex=0;
			bufferLen=len;
			buffer=s;getToken();
			return (int)logic();
		};
		inline bool calBool(const string & s)
		{
			bufIndex=0;
			bufferLen=s.size();
			buffer=s.c_str();
			getToken();
			return (int)logic();
		};
		inline T cal(const char * s,unsigned len)
		{
			bufIndex=0;
			bufferLen=len;
			buffer=s;
			getToken();
			return logic();
		};
		inline T cal(const string & s)
		{
			bufIndex=0;
			bufferLen=s.size();
			buffer=s.c_str();
			getToken();
			return logic();
		};
	};
}
#endif
