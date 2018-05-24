#ifndef EXP_EVAL_LEMON
#define EXP_EVAL_LEMON
namespace Common
{
	template< typename T > struct Token 
	{
	public:
		T val;

	};

#define DEBUG_TRACE_COUT(X) //X;

#include "ExpEval.hpp"

	static int GetToken(const char* zString,int* TokenType)
	{
		int i=0;
		if(*TokenType!=TK_NUMBER && *TokenType!=TK_RP &&( zString[0]=='-' ||zString[0]=='+'))i++;
		switch(zString[i]){
		case ' ': case '\t': case '\n': case '\f': case '\r': 
			{
				for(i=1; isspace(zString[i]); i++)
				{}
				*TokenType = TK_SPACE;
				return i;
			}
		case '1':case '2':case '3':case '4':case '5':
		case '6':case '7':case '8':case '9':case '0':{
			while(isdigit(zString[i++])){}
			if(zString[i-1]!='.'){
				*TokenType=TK_NUMBER;
				return i-1;
			}else{
			 while(isdigit(zString[i++])){}
			 *TokenType=TK_NUMBER;//TK_DOUBLE;
			 return i-1;
			 }
				 }
		case '+':{
			*TokenType=TK_PLUS;
			return 1;
				 }
		case '-':{
			*TokenType=TK_MINUS;
			return 1;
				 }
		case '*':{
			*TokenType=TK_TIMES;
			return 1;
				 }
		case '/':{
			*TokenType=TK_DIV;
			return 1;
				 }
		case '(':{
			*TokenType=TK_LP;
			return 1;
				 }
		case ')':{
			*TokenType=TK_RP;
			return 1;
				 }
		case '=':{
			if(zString[1]=='=')
			{
				*TokenType=TK_EQ;
				return 2;
			}
			else{
				*TokenType=TK_EQUAL;
				return 1;
			}
				 }
		case '!':{
			*TokenType=TK_NE;
			return 2;
				 }
		case '>':{
			if(zString[1]=='=')
			{
				*TokenType=TK_GE;
				return 2;
			}
			else{
				*TokenType=TK_GT;
				return 1;
			}
				 }
		case '<':{
			if(zString[1]=='=')
			{
				*TokenType=TK_LE;
				return 2;
			}
			else{
				*TokenType=TK_LT;
				return 1;
			}
				 }
		case '&':{
			*TokenType=TK_AND;
			return 2;
				 }
		case '|':{
			*TokenType=TK_OR;
			return 2;
				 }
		default:{
			*TokenType=TK_ILLEGAL;
			return 1;
				}
		}
	}
	static int getNextBoolOperIndex(char* zCmd,int TokenType)
	{
		const char * temp=zCmd;
		int subLp=0;
		//bool next=true;
		//cout<<"µ±Ç°£º"<<temp<<endl;
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
				if((TokenType==TK_AND && *temp=='&' && temp[1]=='&') || 
					(TokenType==TK_OR && *temp=='|' && temp[1]=='|'))
					temp++;
				else if((TokenType==TK_OR && *temp=='&' && temp[1]=='&') || 
					(TokenType==TK_AND && *temp=='|' && temp[1]=='|'))
					break;
				//else if(!isspace(*temp))
			}
			temp++;
		}
		return temp-zCmd;
	}

	template<typename T> static T expParse( char* zCmd,void** _pParser=NULL)
	{
		Token<T> pToken;
		Token<T> vParse;
		void * pParser=NULL;
		if(_pParser==NULL)
			pParser=myParseAlloc<T>(malloc);
		else
		{
			if(*_pParser==NULL)
				*_pParser=myParseAlloc<T>(malloc);
			pParser=*_pParser;
		}
		int TokenType=0;
		DEBUG_TRACE_COUT(myParseTrace<T>(stdout, "Parse_");)
		int i=0;
		while(zCmd[i]!='\0')
		{
			int cmdlen=GetToken(zCmd+i,&TokenType);
			switch(TokenType)
			{
				//case TK_EQUAL : goto end;break;
			case TK_SPACE: 
				break;
			case TK_ILLEGAL : 
				EXP("illegal token.\n");
				goto end;
			case TK_AND:
				if(sizeof(T)==4)
					pToken.val=atoi(zCmd+i);
				else
					pToken.val=atof(zCmd+i);
				myParse<T>(pParser,TokenType,pToken,&vParse);
				//getVal(pParser) ;
				if(i && !vParse.val)
				{
					int nextLen=getNextBoolOperIndex(zCmd+i+cmdlen,TokenType);
					if(nextLen)
					{
						i+=nextLen;
						myParse<T>(pParser,TK_NUMBER,Token<T>(),&vParse);
						break;
					}
				}
				break;
			case TK_OR:
				if(sizeof(T)==4)
					pToken.val=atoi(zCmd+i);
				else
					pToken.val=atof(zCmd+i);
				myParse<T>(pParser,TokenType,pToken,&vParse);
				if(i && vParse.val)
				{
					int nextLen=getNextBoolOperIndex(zCmd+i+cmdlen,TokenType);
					if(nextLen)
					{
						i+=nextLen;
						myParse<T>(pParser,TK_NUMBER,Token<T>(),&vParse);
						break;
					}
				}
				break;
			default:
				if(sizeof(T)==4)
					pToken.val=atoi(zCmd+i);
				else
					pToken.val=atof(zCmd+i);
				myParse<T>(pParser,TokenType,pToken,&vParse);
			}
			i+=cmdlen;
		}
end:
		myParse<T>(pParser,0,pToken,&vParse);
		if(!_pParser)myParseFree<T>(pParser,free);
		return vParse.val;
		//free(pToken);
	};
}
#endif //EXP_EVAL_LEMON
