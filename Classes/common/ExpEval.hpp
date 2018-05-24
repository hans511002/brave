/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is included that follows the "include" declaration
** in the input grammar file. */
#include <stdio.h>
#line 55 "ExpEval.y"
//   
//#include <iostream>  
//#include <stdio.h>
//#include <assert.h>
//#line 13 "ExpEval.hpp"
//#include "ExpEval.h"
/* Next is all token values, in a form suitable for use by makeheaders.
** This section will be null unless lemon is run with the -m switch.
*/
/* Make sure the INTERFACE_TOKEN macro is defined.
*/
#ifndef INTERFACE_TOKEN
# define INTERFACE_TOKEN 1
#endif
/* 
** These constants (all generated automatically by the parser generator)
** specify the various kinds of tokens (terminals) that the parser
** understands. 
**
** Each symbol here is a terminal symbol in the grammar.
*/
#if INTERFACE_TOKEN
#define TK_NUMBER                          1
#define TK_AND                             2
#define TK_OR                              3
#define TK_EQ                              4
#define TK_NE                              5
#define TK_GT                              6
#define TK_GE                              7
#define TK_LT                              8
#define TK_LE                              9
#define TK_PLUS                           10
#define TK_MINUS                          11
#define TK_TIMES                          12
#define TK_DIV                            13
#define TK_MOD                            14
#define TK_EXP                            15
#define TK_NOT                            16
#define TK_LP                             17
#define TK_RP                             18
#define TK_SPACE                          19
#define TK_ILLEGAL                        20
#define TK_EQUAL                          21
#endif
/* The next thing included is series of defines which control
** various aspects of the generated parser.
**    YYCODETYPE         is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 terminals
**                       and nonterminals.  "int" is used otherwise.
**    YYNOCODE           is a number of type YYCODETYPE which corresponds
**                       to no legal terminal or nonterminal number.  This
**                       number is used to fill in empty slots of the hash 
**                       table.
**    YYFALLBACK         If defined, this indicates that one or more tokens
**                       have fall-back values which should be used if the
**                       original value of the token will not parse.
**    YYACTIONTYPE       is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 rules and
**                       states combined.  "int" is used otherwise.
**    myParseTOKENTYPE     is the data type used for minor tokens given 
**                       directly to the parser from the tokenizer.
**    YYMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is myParseTOKENTYPE.  The entry in the union
**                       for base tokens is called "yy0".
**    YYSTACKDEPTH       is the maximum depth of the parser's stack.  If
**                       zero the stack is dynamically sized using realloc()
**    myParseARG_SDECL     A static variable declaration for the %extra_argument
**    myParseARG_PDECL     A parameter declaration for the %extra_argument
**    myParseARG_STORE     Code to store %extra_argument into yypParser
**    myParseARG_FETCH     Code to extract %extra_argument from yypParser
**    YYNSTATE           the combined number of states.
**    YYNRULE            the number of rules in the grammar
**    YYERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
*/
#define YYCODETYPE unsigned char
#define YYNOCODE 26
#define YYACTIONTYPE unsigned char
#if INTERFACE_TOKEN
#define myParseTOKENTYPE Token<T>
#endif
template <typename T=int>struct YYMINORTYPE{
  int yyinit;
  myParseTOKENTYPE yy0;
YYMINORTYPE(){memset(this,0,sizeof(YYMINORTYPE<T>));};} ;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#if INTERFACE_TOKEN
#define myParseARG_SDECL Token<T> *pParse;
#define myParseARG_PDECL ,Token<T> *pParse
#define myParseARG_FETCH Token<T> *pParse = yypParser->pParse
#define myParseARG_STORE yypParser->pParse = pParse
#endif
#define YYNSTATE 30
#define YYNRULE 15
#define YY_NO_ACTION      (YYNSTATE+YYNRULE+2)
#define YY_ACCEPT_ACTION  (YYNSTATE+YYNRULE+1)
#define YY_ERROR_ACTION   (YYNSTATE+YYNRULE)

 
/* The yyzerominor constant is used to initialize instances of
** YYMINORTYPE objects to zero. */
//static const YYMINORTYPE<> yyzerominor = { 0 };

/* Define the yytestcase() macro to be a no-op if is not already defined
** otherwise.
**
** Applications can choose to define yytestcase() in the %include section
** to a macro that can assist in verifying code coverage.  For production
** code the yytestcase() macro should be turned off.  But it is useful
** for testing.
*/
#ifndef yytestcase
# define yytestcase(X)
#endif


/* Next are the tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.  
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N < YYNSTATE                  Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   YYNSTATE <= N < YYNSTATE+YYNRULE   Reduce by rule N-YYNSTATE.
**
**   N == YYNSTATE+YYNRULE              A syntax error has occurred.
**
**   N == YYNSTATE+YYNRULE+1            The parser accepts its input.
**
**   N == YYNSTATE+YYNRULE+2            No such action.  Denotes unused
**                                      slots in the yy_action[] table.
**
** The action table is constructed as a single large table named yy_action[].
** Given state S and lookahead X, the action is computed as
**
**      yy_action[ yy_shift_ofst[S] + X ]
**
** If the index value yy_shift_ofst[S]+X is out of range or if the value
** yy_lookahead[yy_shift_ofst[S]+X] is not equal to X or if yy_shift_ofst[S]
** is equal to YY_SHIFT_USE_DFLT, it means that the action is not in the table
** and that yy_default[S] should be used instead.  
**
** The formula above is for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the yy_reduce_ofst[] array is used in place of
** the yy_shift_ofst[] array and YY_REDUCE_USE_DFLT is used in place of
** YY_SHIFT_USE_DFLT.
**
** The following are the tables generated in this section:
**
**  yy_action[]        A single table containing all actions.
**  yy_lookahead[]     A table containing the lookahead for each entry in
**                     yy_action.  Used to detect hash collisions.
**  yy_shift_ofst[]    For each state, the offset into yy_action for
**                     shifting terminals.
**  yy_reduce_ofst[]   For each state, the offset into yy_action for
**                     shifting non-terminals after a reduce.
**  yy_default[]       Default action for each state.
*/
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    30,   18,    2,    4,    6,    8,   10,   13,    1,   11,
 /*    10 */     7,    9,    3,   12,    2,    4,    6,    8,   10,   13,
 /*    20 */     1,   11,    7,    9,    3,   12,    7,    9,    3,   12,
 /*    30 */    27,   28,   46,   15,   26,    6,    8,   10,   13,    1,
 /*    40 */    11,    7,    9,    3,   12,    3,   12,    5,   17,   21,
 /*    50 */    29,   23,   16,   25,   47,   47,   14,   47,   20,   19,
 /*    60 */    24,   22,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     0,   24,    2,    3,    4,    5,    6,    7,    8,    9,
 /*    10 */    10,   11,   12,   13,    2,    3,    4,    5,    6,    7,
 /*    20 */     8,    9,   10,   11,   12,   13,   10,   11,   12,   13,
 /*    30 */    18,    1,   23,   24,   24,    4,    5,    6,    7,    8,
 /*    40 */     9,   10,   11,   12,   13,   12,   13,   17,   24,   24,
 /*    50 */    24,   24,   24,   24,   25,   25,   24,   25,   24,   24,
 /*    60 */    24,   24,
};
#define YY_SHIFT_USE_DFLT (-1)
#define YY_SHIFT_MAX 25
static const signed char yy_shift_ofst[] = {
 /*     0 */    30,   30,   30,   30,   30,   30,   30,   30,   30,   30,
 /*    10 */    30,   30,   30,   30,   12,    0,   31,   31,   16,   16,
 /*    20 */    16,   16,   16,   16,   33,   33,
};
#define YY_REDUCE_USE_DFLT (-24)
#define YY_REDUCE_MAX 13
static const signed char yy_reduce_ofst[] = {
 /*     0 */     9,   37,   24,   26,   28,   32,   35,   36,   34,   29,
 /*    10 */    27,   25,   10,  -23,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */    45,   45,   45,   45,   45,   45,   45,   45,   45,   45,
 /*    10 */    45,   45,   45,   45,   45,   45,   32,   31,   37,   33,
 /*    20 */    34,   38,   36,   35,   41,   40,   43,   39,   44,   42,
};
#define YY_SZ_ACTTAB (int)(sizeof(yy_action)/sizeof(yy_action[0]))

/* The next table maps tokens into fallback tokens.  If a construct
** like the following:
** 
**      %fallback ID X Y Z.
**
** appears in the grammar, then ID becomes a fallback token for X, Y,
** and Z.  Whenever one of the tokens X, Y, or Z is input to the parser
** but it does not parse, the type of the token is changed to ID and
** the parse is retried before an error is thrown.
*/
#ifdef YYFALLBACK
static const YYCODETYPE yyFallback[] = {
};
#endif /* YYFALLBACK */

/* The following structure represents a single element of the
** parser's stack.  Information stored includes:
**
**   +  The state number for the parser at this level of the stack.
**
**   +  The value of the token stored at this level of the stack.
**      (In other words, the "major" token.)
**
**   +  The semantic value stored at this level of the stack.  This is
**      the information used by the action routines in the grammar.
**      It is sometimes called the "minor" token.
*/
template< typename T >struct yyStackEntry {
  YYACTIONTYPE stateno;  /* The state-number */
  YYCODETYPE major;      /* The major token value.  This is the code
                         ** number for the token at this stack level */
  YYMINORTYPE <T> minor;     /* The user-supplied minor token value.  This
                         ** is the value of the token  */
};
//typedef struct yyStackEntry yyStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
template< typename T >struct yyParser {
  int yyidx;                    /* Index of top element in stack */
#ifdef YYTRACKMAXSTACKDEPTH
  int yyidxMax;                 /* Maximum value of yyidx */
#endif
  int yyerrcnt;                 /* Shifts left before out of the error */
  myParseARG_SDECL                /* A place to hold %extra_argument */
#if YYSTACKDEPTH<=0
  int yystksz;                  /* Current side of the stack */
  yyStackEntry<T>  *yystack;        /* The parser's stack */
#else
  yyStackEntry<T>  yystack[YYSTACKDEPTH];  /* The parser's stack */
#endif
};
//typedef struct yyParser yyParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *yyTraceFILE = 0;
static char *yyTracePrompt = 0;
#endif /* NDEBUG */

#ifndef NDEBUG
/* 
** Turn parser tracing on by giving a stream to which to write the trace
** and a prompt to preface each trace message.  Tracing is turned off
** by making either argument NULL 
**
** Inputs:
** <ul>
** <li> A FILE* to which trace output should be written.
**      If NULL, then tracing is turned off.
** <li> A prefix string written at the beginning of every
**      line of trace output.  If NULL, then tracing is
**      turned off.
** </ul>
**
** Outputs:
** None.
*/
template< typename T >void myParseTrace(FILE *TraceFILE, char *zTracePrompt){
  yyTraceFILE = TraceFILE;
  yyTracePrompt = zTracePrompt;
  if( yyTraceFILE==0 ) yyTracePrompt = 0;
  else if( yyTracePrompt==0 ) yyTraceFILE = 0;
}
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *const yyTokenName[] = { 
  "$",             "NUMBER",        "AND",           "OR",          
  "EQ",            "NE",            "GT",            "GE",          
  "LT",            "LE",            "PLUS",          "MINUS",       
  "TIMES",         "DIV",           "MOD",           "EXP",         
  "NOT",           "LP",            "RP",            "SPACE",       
  "ILLEGAL",       "EQUAL",         "error",         "program",     
  "expr",        
};
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *const yyRuleName[] = {
 /*   0 */ "program ::= expr",
 /*   1 */ "expr ::= expr AND expr",
 /*   2 */ "expr ::= expr OR expr",
 /*   3 */ "expr ::= expr EQ expr",
 /*   4 */ "expr ::= expr NE expr",
 /*   5 */ "expr ::= expr GT expr",
 /*   6 */ "expr ::= expr LT expr",
 /*   7 */ "expr ::= expr GE expr",
 /*   8 */ "expr ::= expr LE expr",
 /*   9 */ "expr ::= LP expr RP",
 /*  10 */ "expr ::= expr MINUS expr",
 /*  11 */ "expr ::= expr PLUS expr",
 /*  12 */ "expr ::= expr TIMES expr",
 /*  13 */ "expr ::= expr DIV expr",
 /*  14 */ "expr ::= NUMBER",
};
#endif /* NDEBUG */


#if YYSTACKDEPTH<=0
/*
** Try to increase the size of the parser stack.
*/
template <typename T>static void yyGrowStack(yyParser <T>*p){
  int newSize;
  yyStackEntry <T>*pNew;

  newSize = p->yystksz*2 + 100;
  pNew = realloc(p->yystack, newSize*sizeof(pNew[0]));
  if( pNew ){
    p->yystack = pNew;
    p->yystksz = newSize;
#ifndef NDEBUG
    if( yyTraceFILE ){
      fprintf(yyTraceFILE,"%sStack grows to %d entries!\n",
              yyTracePrompt, p->yystksz);
    }
#endif
  }
}
#endif

/* 
** This function allocates a new parser.
** The only argument is a pointer to a function which works like
** malloc.
**
** Inputs:
** A pointer to the function used to allocate memory.
**
** Outputs:
** A pointer to a parser.  This pointer is used in subsequent calls
** to myParse and myParseFree.
*/
template <typename T>void *myParseAlloc(void *(*mallocProc)(size_t)){
  yyParser<T> *pParser;
  pParser = (yyParser<T>*)(*mallocProc)( (size_t)sizeof(yyParser<T>) );
  if( pParser ){
    pParser->yyidx = -1;
#ifdef YYTRACKMAXSTACKDEPTH
    pParser->yyidxMax = 0;
#endif
#if YYSTACKDEPTH<=0
    pParser->yystack = NULL;
    pParser->yystksz = 0;
    yyGrowStack<T>(pParser);
#endif
  }
  return pParser;
}

/* The following function deletes the value associated with a
** symbol.  The symbol can be either a terminal or nonterminal.
** "yymajor" is the symbol code, and "yypminor" is a pointer to
** the value.
*/
template <typename T>static void yy_destructor(
  yyParser<T> *yypParser,    /* The parser */
  YYCODETYPE yymajor,     /* Type code for object to destroy */
  YYMINORTYPE<T> *yypminor   /* The object to be destroyed */
){
  myParseARG_FETCH;
  switch( yymajor ){
    /* Here is inserted the actions which take place when a
    ** terminal or non-terminal is destroyed.  This can happen
    ** when the symbol is popped from the stack during a
    ** reduce or during error processing or when a parser is 
    ** being destroyed before it is finished parsing.
    **
    ** Note: during a reduce, the only symbols destroyed are those
    ** which appear on the RHS of the rule, but which are not used
    ** inside the C code.
    */
    default:  break;   /* If no destructor action specified: do nothing */
  }
}

/*
** Pop the parser's stack once.
**
** If there is a destructor routine associated with the token which
** is popped from the stack, then call it.
**
** Return the major token number for the symbol popped.
*/
template <typename T>static int yy_pop_parser_stack(yyParser<T> *pParser){
  YYCODETYPE yymajor;
  yyStackEntry<T> *yytos = &pParser->yystack[pParser->yyidx];

  if( pParser->yyidx<0 ) return 0;
#ifndef NDEBUG
  if( yyTraceFILE && pParser->yyidx>=0 ){
    fprintf(yyTraceFILE,"%sPopping %s\n",
      yyTracePrompt,
      yyTokenName[yytos->major]);
  }
#endif
  yymajor = yytos->major;
  yy_destructor<T>(pParser, yymajor, &yytos->minor);
  pParser->yyidx--;
  return yymajor;
}

/* 
** Deallocate and destroy a parser.  Destructors are all called for
** all stack elements before shutting the parser down.
**
** Inputs:
** <ul>
** <li>  A pointer to the parser.  This should be a pointer
**       obtained from myParseAlloc.
** <li>  A pointer to a function used to reclaim memory obtained
**       from malloc.
** </ul>
*/
template <typename T>void myParseFree(
  void *p,                    /* The parser to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */
){
  yyParser<T> *pParser = (yyParser<T>*)p;
  if( pParser==0 ) return;
  while( pParser->yyidx>=0 ) yy_pop_parser_stack<T>(pParser);
#if YYSTACKDEPTH<=0
  free(pParser->yystack);
#endif
  (*freeProc)((void*)pParser);
}

/*
** Return the peak depth of the stack for a parser.
*/
#ifdef YYTRACKMAXSTACKDEPTH
template <typename T>int myParseStackPeak(void *p){
  yyParser<T> *pParser = (yyParser<T>*)p;
  return pParser->yyidxMax;
}
#endif

/*
** Find the appropriate action for a parser given the terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
template <typename T>static int yy_find_shift_action(
  yyParser<T> *pParser,        /* The parser */
  YYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
  int stateno = pParser->yystack[pParser->yyidx].stateno;
 
  if( stateno>YY_SHIFT_MAX || (i = yy_shift_ofst[stateno])==YY_SHIFT_USE_DFLT ){
    return yy_default[stateno];
  }
  assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
  if( i<0 || i>=YY_SZ_ACTTAB || yy_lookahead[i]!=iLookAhead ){
    if( iLookAhead>0 ){
#ifdef YYFALLBACK
      YYCODETYPE iFallback;            /* Fallback token */
      if( iLookAhead<sizeof(yyFallback)/sizeof(yyFallback[0])
             && (iFallback = yyFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE, "%sFALLBACK %s => %s\n",
             yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[iFallback]);
        }
#endif
        return yy_find_shift_action<T>(pParser, iFallback);
      }
#endif
#ifdef YYWILDCARD
      {
        int j = i - iLookAhead + YYWILDCARD;
        if( j>=0 && j<YY_SZ_ACTTAB && yy_lookahead[j]==YYWILDCARD ){
#ifndef NDEBUG
          if( yyTraceFILE ){
            fprintf(yyTraceFILE, "%sWILDCARD %s => %s\n",
               yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[YYWILDCARD]);
          }
#endif /* NDEBUG */
          return yy_action[j];
        }
      }
#endif /* YYWILDCARD */
    }
    return yy_default[stateno];
  }else{
    return yy_action[i];
  }
};

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
inline int yy_find_reduce_action(
	int stateno,              /* Current state number */
  YYCODETYPE iLookAhead)     /* The look-ahead token */
{
  int i;
#ifdef YYERRORSYMBOL
  if( stateno>YY_REDUCE_MAX ){
    return yy_default[stateno];
  }
#else
  assert( stateno<=YY_REDUCE_MAX );
#endif
  i = yy_reduce_ofst[stateno];
  assert( i!=YY_REDUCE_USE_DFLT );
  assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
#ifdef YYERRORSYMBOL
  if( i<0 || i>=YY_SZ_ACTTAB || yy_lookahead[i]!=iLookAhead ){
    return yy_default[stateno];
  }
#else
  assert( i>=0 && i<YY_SZ_ACTTAB );
  assert( yy_lookahead[i]==iLookAhead );
#endif
  return yy_action[i];
};

/*
** The following routine is called if the stack overflows.
*/
template <typename T>static void yyStackOverflow(yyParser<T> *yypParser, YYMINORTYPE<T> *yypMinor){
   myParseARG_FETCH;
   yypParser->yyidx--;
#ifndef NDEBUG
   if( yyTraceFILE ){
     fprintf(yyTraceFILE,"%sStack Overflow!\n",yyTracePrompt);
   }
#endif
   while( yypParser->yyidx>=0 ) yy_pop_parser_stack<T>(yypParser);
   /* Here code is inserted which will execute if the parser
   ** stack every overflows */
   myParseARG_STORE; /* Suppress warning about unused %extra_argument var */
}

/*
** Perform a shift action.
*/
template <typename T>static void yy_shift(
  yyParser<T> *yypParser,          /* The parser to be shifted */
  int yyNewState,               /* The new state to shift in */
  int yyMajor,                  /* The major token to shift in */
  YYMINORTYPE<T> *yypMinor         /* Pointer to the minor token to shift in */
){
  yyStackEntry<T> *yytos;
  yypParser->yyidx++;
#ifdef YYTRACKMAXSTACKDEPTH
  if( yypParser->yyidx>yypParser->yyidxMax ){
    yypParser->yyidxMax = yypParser->yyidx;
  }
#endif
#if YYSTACKDEPTH>0 
  if( yypParser->yyidx>=YYSTACKDEPTH ){
    yyStackOverflow<T>(yypParser, yypMinor);
    return;
  }
#else
  if( yypParser->yyidx>=yypParser->yystksz ){
    yyGrowStack<T>(yypParser);
    if( yypParser->yyidx>=yypParser->yystksz ){
      yyStackOverflow<T>(yypParser, yypMinor);
      return;
    }
  }
#endif
  yytos = &yypParser->yystack[yypParser->yyidx];
  yytos->stateno = (YYACTIONTYPE)yyNewState;
  yytos->major = (YYCODETYPE)yyMajor;
  yytos->minor = *yypMinor;
#ifndef NDEBUG
  if( yyTraceFILE && yypParser->yyidx>0 ){
    int i;
    fprintf(yyTraceFILE,"%sShift %d\n",yyTracePrompt,yyNewState);
    fprintf(yyTraceFILE,"%sStack:",yyTracePrompt);
    for(i=1; i<=yypParser->yyidx; i++)
      fprintf(yyTraceFILE," %s",yyTokenName[yypParser->yystack[i].major]);
    fprintf(yyTraceFILE,"\n");
  }
#endif
}

/* The following table contains information about every rule that
** is used during the reduce.
*/
static const struct {
  YYCODETYPE lhs;         /* Symbol on the left-hand side of the rule */
  unsigned char nrhs;     /* Number of right-hand side symbols in the rule */
} yyRuleInfo[] = {
  { 23, 1 },
  { 24, 3 },
  { 24, 3 },
  { 24, 3 },
  { 24, 3 },
  { 24, 3 },
  { 24, 3 },
  { 24, 3 },
  { 24, 3 },
  { 24, 3 },
  { 24, 3 },
  { 24, 3 },
  { 24, 3 },
  { 24, 3 },
  { 24, 1 },
};

template <typename T>static void yy_accept(yyParser<T>*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
*/
template <typename T>static void yy_reduce(
  yyParser<T> *yypParser,         /* The parser */
  int yyruleno                 /* Number of the rule by which to reduce */
){
  int yygoto;                     /* The next state */
  int yyact;                      /* The next action */
  YYMINORTYPE<T> yygotominor;        /* The LHS of the rule reduced */
  yyStackEntry<T> *yymsp;            /* The top of the parser's stack */
  int yysize;                     /* Amount to pop the stack */
  myParseARG_FETCH;
  yymsp = &yypParser->yystack[yypParser->yyidx];
#ifndef NDEBUG
  if( yyTraceFILE && yyruleno>=0 
        && yyruleno<(int)(sizeof(yyRuleName)/sizeof(yyRuleName[0])) ){
    fprintf(yyTraceFILE, "%sReduce [%s].\n", yyTracePrompt,
      yyRuleName[yyruleno]);
  }
#endif /* NDEBUG */

  /* Silence complaints from purify about yygotominor being uninitialized
  ** in some cases when it is copied into the stack after the following
  ** switch.  yygotominor is uninitialized when a rule reduces that does
  ** not set the value of its left-hand side nonterminal.  Leaving the
  ** value of the nonterminal uninitialized is utterly harmless as long
  ** as the value is never used.  So really the only thing this code
  ** accomplishes is to quieten purify.  
  **
  ** 2007-01-16:  The wireshark project (www.wireshark.org) reports that
  ** without this code, their parser segfaults.  I'm not sure what there
  ** parser is doing to make this happen.  This is the second bug report
  ** from wireshark this week.  Clearly they are stressing Lemon in ways
  ** that it has not been previously stressed...  (SQLite ticket #2172)
  */
  memset(&yygotominor, 0, sizeof(yygotominor));
  //yygotominor = yyzerominor;


  switch( yyruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  #line <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  #line <lineno> <thisfile>
  **     break;
  */
      case 0: /* program ::= expr */
#line 68 "ExpEval.y"
{DEBUG_TRACE_COUT( std::cout << "Result=" << yymsp[0].minor.yy0.val << std::endl;) *pParse=yymsp[0].minor.yy0;  }
#line 710 "ExpEval.hpp"
        break;
      case 1: /* expr ::= expr AND expr */
#line 70 "ExpEval.y"
{yygotominor.yy0.val=yymsp[-2].minor.yy0.val && yymsp[0].minor.yy0.val; *pParse=yygotominor.yy0; DEBUG_TRACE_COUT(std::cout << "yymsp[-2].minor.yy0=" << yymsp[-2].minor.yy0.val<<"\t yymsp[0].minor.yy0="<<yymsp[0].minor.yy0.val << std::endl;) }
#line 715 "ExpEval.hpp"
        break;
      case 2: /* expr ::= expr OR expr */
#line 71 "ExpEval.y"
{yygotominor.yy0.val=yymsp[-2].minor.yy0.val || yymsp[0].minor.yy0.val; *pParse=yygotominor.yy0; DEBUG_TRACE_COUT(std::cout << "yymsp[-2].minor.yy0=" << yymsp[-2].minor.yy0.val<<"\t yymsp[0].minor.yy0="<<yymsp[0].minor.yy0.val << std::endl;)}
#line 720 "ExpEval.hpp"
        break;
      case 3: /* expr ::= expr EQ expr */
#line 72 "ExpEval.y"
{yygotominor.yy0.val=yymsp[-2].minor.yy0.val == yymsp[0].minor.yy0.val; *pParse=yygotominor.yy0;}
#line 725 "ExpEval.hpp"
        break;
      case 4: /* expr ::= expr NE expr */
#line 73 "ExpEval.y"
{yygotominor.yy0.val=yymsp[-2].minor.yy0.val != yymsp[0].minor.yy0.val;*pParse=yygotominor.yy0;}
#line 730 "ExpEval.hpp"
        break;
      case 5: /* expr ::= expr GT expr */
#line 74 "ExpEval.y"
{yygotominor.yy0.val=yymsp[-2].minor.yy0.val > yymsp[0].minor.yy0.val; *pParse=yygotominor.yy0;}
#line 735 "ExpEval.hpp"
        break;
      case 6: /* expr ::= expr LT expr */
#line 75 "ExpEval.y"
{yygotominor.yy0.val=yymsp[-2].minor.yy0.val < yymsp[0].minor.yy0.val; *pParse=yygotominor.yy0;}
#line 740 "ExpEval.hpp"
        break;
      case 7: /* expr ::= expr GE expr */
#line 76 "ExpEval.y"
{yygotominor.yy0.val=yymsp[-2].minor.yy0.val >= yymsp[0].minor.yy0.val;*pParse=yygotominor.yy0;}
#line 745 "ExpEval.hpp"
        break;
      case 8: /* expr ::= expr LE expr */
#line 77 "ExpEval.y"
{yygotominor.yy0.val=yymsp[-2].minor.yy0.val <= yymsp[0].minor.yy0.val;*pParse=yygotominor.yy0;}
#line 750 "ExpEval.hpp"
        break;
      case 9: /* expr ::= LP expr RP */
#line 79 "ExpEval.y"
{ yygotominor.yy0.val = yymsp[-1].minor.yy0.val;*pParse=yygotominor.yy0; DEBUG_TRACE_COUT(cout<<yygotominor.yy0.val<<"="<<yygotominor.yy0.val<<endl;)}
#line 755 "ExpEval.hpp"
        break;
      case 10: /* expr ::= expr MINUS expr */
#line 80 "ExpEval.y"
{ yygotominor.yy0.val = yymsp[-2].minor.yy0.val - yymsp[0].minor.yy0.val;  }
#line 760 "ExpEval.hpp"
        break;
      case 11: /* expr ::= expr PLUS expr */
#line 81 "ExpEval.y"
{ yygotominor.yy0.val = yymsp[-2].minor.yy0.val + yymsp[0].minor.yy0.val; }
#line 765 "ExpEval.hpp"
        break;
      case 12: /* expr ::= expr TIMES expr */
#line 82 "ExpEval.y"
{ yygotominor.yy0.val = yymsp[-2].minor.yy0.val * yymsp[0].minor.yy0.val;  }
#line 770 "ExpEval.hpp"
        break;
      case 13: /* expr ::= expr DIV expr */
#line 83 "ExpEval.y"
{ 

         if(yymsp[0].minor.yy0.val != 0){
           yygotominor.yy0 .val= yymsp[-2].minor.yy0.val / yymsp[0].minor.yy0.val;
          }else{
           EXP( "divide by zero");
           }*pParse=yygotominor.yy0; 
}
#line 782 "ExpEval.hpp"
        break;
      case 14: /* expr ::= NUMBER */
#line 92 "ExpEval.y"
{ yygotominor.yy0.val = yymsp[0].minor.yy0.val;}
#line 787 "ExpEval.hpp"
        break;
      default:
        break;
  };
  yygoto = yyRuleInfo[yyruleno].lhs;
  yysize = yyRuleInfo[yyruleno].nrhs;
  yypParser->yyidx -= yysize;
  yyact = yy_find_reduce_action(yymsp[-yysize].stateno,(YYCODETYPE)yygoto);
  if( yyact < YYNSTATE ){
#ifdef NDEBUG
    /* If we are not debugging and the reduce action popped at least
    ** one element off the stack, then we can push the new element back
    ** onto the stack here, and skip the stack overflow test in yy_shift().
    ** That gives a significant speed improvement. */
    if( yysize ){
      yypParser->yyidx++;
      yymsp -= yysize-1;
      yymsp->stateno = (YYACTIONTYPE)yyact;
      yymsp->major = (YYCODETYPE)yygoto;
      yymsp->minor = yygotominor;
    }else
#endif
    {
      yy_shift<T>(yypParser,yyact,yygoto,&yygotominor);
    }
  }else{
    assert( yyact == YYNSTATE + YYNRULE + 1 );
    yy_accept<T>(yypParser);
  }
}

/*
** The following code executes when the parse fails
*/
#ifndef YYNOERRORRECOVERY
template <typename T>static void yy_parse_failed(
  yyParser<T> *yypParser           /* The parser */
){
  myParseARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sFail!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack<T>(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
  myParseARG_STORE; /* Suppress warning about unused %extra_argument variable */
}
#endif /* YYNOERRORRECOVERY */

/*
** The following code executes when a syntax error first occurs.
*/
template <typename T>static void yy_syntax_error(
  yyParser<T> *yypParser,           /* The parser */
  int yymajor,                   /* The major type of the error token */
  YYMINORTYPE<T> yyminor            /* The minor type of the error token */
){
  myParseARG_FETCH;
#define TOKEN (yyminor.yy0)
#line 64 "ExpEval.y"
  
  EXP("Syntax error!");
#line 852 "ExpEval.hpp"
  myParseARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
template <typename T>static void yy_accept(
  yyParser<T> *yypParser           /* The parser */
){
  myParseARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sAccept!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack<T>(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser accepts */
#line 61 "ExpEval.y"

  //printf("parsing complete!\n");
#line 874 "ExpEval.hpp"
  myParseARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/* The main parser program.
** The first argument is a pointer to a structure obtained from
** "myParseAlloc" which describes the current state of the parser.
** The second argument is the major token number.  The third is
** the minor token.  The fourth optional argument is whatever the
** user wants (and specified in the grammar) and is available for
** use by the action routines.
**
** Inputs:
** <ul>
** <li> A pointer to the parser (an opaque structure.)
** <li> The major token number.
** <li> The minor token number.
** <li> An option argument of a grammar-specified type.
** </ul>
**
** Outputs:
** None.
*/
template <typename T>void myParse(
  void *yyp,                   /* The parser */
  int yymajor,                 /* The major token code number */
  myParseTOKENTYPE yyminor       /* The value for the token */
  myParseARG_PDECL               /* Optional %extra_argument parameter */
){
  YYMINORTYPE<T> yyminorunion;
  int yyact;            /* The parser action. */
  int yyendofinput;     /* True if we are at the end of input */
#ifdef YYERRORSYMBOL
  int yyerrorhit = 0;   /* True if yymajor has invoked an error */
#endif
  yyParser<T> *yypParser;  /* The parser */

  /* (re)initialize the parser, if necessary */
  yypParser = (yyParser<T>*)yyp;
  if( yypParser->yyidx<0 ){
#if YYSTACKDEPTH<=0
    if( yypParser->yystksz <=0 ){
      memset(&yyminorunion, 0, sizeof(yyminorunion));
      //yyminorunion = yyzerominor;
      yyStackOverflow<T>(yypParser, &yyminorunion);
      return;
    }
#endif
    yypParser->yyidx = 0;
    yypParser->yyerrcnt = -1;
    yypParser->yystack[0].stateno = 0;
    yypParser->yystack[0].major = 0;
  }
  yyminorunion.yy0 = yyminor;
  yyendofinput = (yymajor==0);
  myParseARG_STORE;

#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sInput %s\n",yyTracePrompt,yyTokenName[yymajor]);
  }
#endif

  do{
    yyact = yy_find_shift_action<T>(yypParser,(YYCODETYPE)yymajor);
    if( yyact<YYNSTATE ){
      assert( !yyendofinput );  /* Impossible to shift the $ token */
      yy_shift<T>(yypParser,yyact,yymajor,&yyminorunion);
      yypParser->yyerrcnt--;
      yymajor = YYNOCODE;
    }else if( yyact < YYNSTATE + YYNRULE ){
      yy_reduce<T>(yypParser,yyact-YYNSTATE);
    }else{
      assert( yyact == YY_ERROR_ACTION );
#ifdef YYERRORSYMBOL
      int yymx;
#endif
#ifndef NDEBUG
      if( yyTraceFILE ){
        fprintf(yyTraceFILE,"%sSyntax Error!\n",yyTracePrompt);
      }
#endif
#ifdef YYERRORSYMBOL
      /* A syntax error has occurred.
      ** The response to an error depends upon whether or not the
      ** grammar defines an error token "ERROR".  
      **
      ** This is what we do if the grammar does define ERROR:
      **
      **  * Call the %syntax_error function.
      **
      **  * Begin popping the stack until we enter a state where
      **    it is legal to shift the error symbol, then shift
      **    the error symbol.
      **
      **  * Set the error count to three.
      **
      **  * Begin accepting and shifting new tokens.  No new error
      **    processing will occur until three tokens have been
      **    shifted successfully.
      **
      */
      if( yypParser->yyerrcnt<0 ){
        yy_syntax_error<T>(yypParser,yymajor,yyminorunion);
      }
      yymx = yypParser->yystack[yypParser->yyidx].major;
      if( yymx==YYERRORSYMBOL || yyerrorhit ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE,"%sDiscard input token %s\n",
             yyTracePrompt,yyTokenName[yymajor]);
        }
#endif
        yy_destructor<T>(yypParser, (YYCODETYPE)yymajor,&yyminorunion);
        yymajor = YYNOCODE;
      }else{
         while(
          yypParser->yyidx >= 0 &&
          yymx != YYERRORSYMBOL &&
          (yyact = yy_find_reduce_action(
                        yypParser->yystack[yypParser->yyidx].stateno,
                        YYERRORSYMBOL)) >= YYNSTATE
        ){
          yy_pop_parser_stack<T>(yypParser);
        }
        if( yypParser->yyidx < 0 || yymajor==0 ){
          yy_destructor<T>(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
          yy_parse_failed<T>(yypParser);
          yymajor = YYNOCODE;
        }else if( yymx!=YYERRORSYMBOL ){
          YYMINORTYPE<T> u2;
          u2.YYERRSYMDT = 0;
          yy_shift<T>(yypParser,yyact,YYERRORSYMBOL,&u2);
        }
      }
      yypParser->yyerrcnt = 3;
      yyerrorhit = 1;
#elif defined(YYNOERRORRECOVERY)
      /* If the YYNOERRORRECOVERY macro is defined, then do not attempt to
      ** do any kind of error recovery.  Instead, simply invoke the syntax
      ** error routine and continue going as if nothing had happened.
      **
      ** Applications can set this macro (for example inside %include) if
      ** they intend to abandon the parse upon the first syntax error seen.
      */
      yy_syntax_error<T>(yypParser,yymajor,yyminorunion);
      yy_destructor<T>(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
      yymajor = YYNOCODE;
      
#else  /* YYERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( yypParser->yyerrcnt<=0 ){
        yy_syntax_error<T>(yypParser,yymajor,yyminorunion);
      }
      yypParser->yyerrcnt = 3;
      yy_destructor<T>(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
      if( yyendofinput ){
        yy_parse_failed<T>(yypParser);
      }
      yymajor = YYNOCODE;
#endif
    }
  }while( yymajor!=YYNOCODE && yypParser->yyidx>=0 );
  return;
}
