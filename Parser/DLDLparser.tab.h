#ifndef YY_parse_h_included
#define YY_parse_h_included
/*#define YY_USE_CLASS 
*/
#line 1 "/usr/share/bison++/bison.h"
/* before anything */
#ifdef c_plusplus
 #ifndef __cplusplus
  #define __cplusplus
 #endif
#endif


 #line 8 "/usr/share/bison++/bison.h"

#line 88 "Parser/DLDLparser.y"
typedef union{
    deamer::AstInformation* DeamerNode;
    deamer::AstInformation* DeamerType;
    deamer::AstNode* ASTNODE;
    DLDL::AstTree_PROG* DLDL_PROG;
    std::vector<DLDL::AstNode_STMTS*>* DLDL_STMTS;
    DLDL::AstNode_STMT* DLDL_STMT;
    DLDL::AstNode_ABSTRACTION* DLDL_ABSTRACTION;
    std::vector<DLDL::AstNode_TERMINALS*>* DLDL_TERMINALS;
    DLDL::AstNode_TERMINAL_DECL* DLDL_TERMINAL_DECL;
    DLDL::AstNode_NONTERMINAL_DECL* DLDL_NONTERMINAL_DECL;
    DLDL::AstNode_ABSTRACTION_DECL* DLDL_ABSTRACTION_DECL;
    DLDL::AstNode_RULE_DECL* DLDL_RULE_DECL;
    DLDL::AstNode_TERMINAL_BLOCK* DLDL_TERMINAL_BLOCK;
    DLDL::AstNode_NONTERMINAL_BLOCK* DLDL_NONTERMINAL_BLOCK;
    std::vector<DLDL::AstNode_RULES*>* DLDL_RULES;
    DLDL::AstNode_ABSTRACTION_BLOCK* DLDL_ABSTRACTION_BLOCK;
    std::vector<DLDL::AstNode_ABSTRACTION_INPUTS*>* DLDL_ABSTRACTION_INPUTS;
    DLDL::AstNode_ABSTRACTION_INPUT* DLDL_ABSTRACTION_INPUT;
    DLDL::AstNode_GENERAL_BLOCK* DLDL_GENERAL_BLOCK;
    std::vector<DLDL::AstNode_VARLIST*>* DLDL_VARLIST;
    DLDL::AstNode_DELETE* DLDL_DELETE;
    DLDL::AstNode_IGNORE* DLDL_IGNORE;
    DLDL::AstNode_TERMINAL* DLDL_TERMINAL;
    DLDL::AstNode_NONTERMINAL* DLDL_NONTERMINAL;
    DLDL::AstNode_GROUP* DLDL_GROUP;
    DLDL::AstNode_ALIAS* DLDL_ALIAS;
    DLDL::AstNode_START* DLDL_START;
    DLDL::AstNode_COMMENT* DLDL_COMMENT;
    DLDL::AstNode_UNIQUE* DLDL_UNIQUE;
    DLDL::AstNode_TYPE* DLDL_TYPE;
    DLDL::AstNode_VARNAME* DLDL_VARNAME;
} yy_parse_stype;
#define YY_parse_STYPE yy_parse_stype
#ifndef YY_USE_CLASS
#define YYSTYPE yy_parse_stype
#endif

#line 21 "/usr/share/bison++/bison.h"
 /* %{ and %header{ and %union, during decl */
#ifndef YY_parse_COMPATIBILITY
 #ifndef YY_USE_CLASS
  #define  YY_parse_COMPATIBILITY 1
 #else
  #define  YY_parse_COMPATIBILITY 0
 #endif
#endif

#if YY_parse_COMPATIBILITY != 0
/* backward compatibility */
 #ifdef YYLTYPE
  #ifndef YY_parse_LTYPE
   #define YY_parse_LTYPE YYLTYPE
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
/* use %define LTYPE */
  #endif
 #endif
/*#ifdef YYSTYPE*/
  #ifndef YY_parse_STYPE
   #define YY_parse_STYPE YYSTYPE
  /* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
   /* use %define STYPE */
  #endif
/*#endif*/
 #ifdef YYDEBUG
  #ifndef YY_parse_DEBUG
   #define  YY_parse_DEBUG YYDEBUG
   /* WARNING obsolete !!! user defined YYDEBUG not reported into generated header */
   /* use %define DEBUG */
  #endif
 #endif 
 /* use goto to be compatible */
 #ifndef YY_parse_USE_GOTO
  #define YY_parse_USE_GOTO 1
 #endif
#endif

/* use no goto to be clean in C++ */
#ifndef YY_parse_USE_GOTO
 #define YY_parse_USE_GOTO 0
#endif

#ifndef YY_parse_PURE

 #line 65 "/usr/share/bison++/bison.h"

#line 65 "/usr/share/bison++/bison.h"
/* YY_parse_PURE */
#endif


 #line 68 "/usr/share/bison++/bison.h"
#define YY_parse_PARSE DLDLparse
#define YY_parse_LEX DLDLlex
#define YY_parse_ERROR DLDLerror
#define YY_parse_LVAL DLDLlval
#define YY_parse_CHAR DLDLchar
#define YY_parse_DEBUG DLDLdebug

#line 68 "/usr/share/bison++/bison.h"
/* prefix */

#ifndef YY_parse_DEBUG

 #line 71 "/usr/share/bison++/bison.h"

#line 71 "/usr/share/bison++/bison.h"
/* YY_parse_DEBUG */
#endif

#ifndef YY_parse_LSP_NEEDED

 #line 75 "/usr/share/bison++/bison.h"

#line 75 "/usr/share/bison++/bison.h"
 /* YY_parse_LSP_NEEDED*/
#endif

/* DEFAULT LTYPE*/
#ifdef YY_parse_LSP_NEEDED
 #ifndef YY_parse_LTYPE
  #ifndef BISON_YYLTYPE_ISDECLARED
   #define BISON_YYLTYPE_ISDECLARED
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;
  #endif

  #define YY_parse_LTYPE yyltype
 #endif
#endif

/* DEFAULT STYPE*/
#ifndef YY_parse_STYPE
 #define YY_parse_STYPE int
#endif

/* DEFAULT MISCELANEOUS */
#ifndef YY_parse_PARSE
 #define YY_parse_PARSE yyparse
#endif

#ifndef YY_parse_LEX
 #define YY_parse_LEX yylex
#endif

#ifndef YY_parse_LVAL
 #define YY_parse_LVAL yylval
#endif

#ifndef YY_parse_LLOC
 #define YY_parse_LLOC yylloc
#endif

#ifndef YY_parse_CHAR
 #define YY_parse_CHAR yychar
#endif

#ifndef YY_parse_NERRS
 #define YY_parse_NERRS yynerrs
#endif

#ifndef YY_parse_DEBUG_FLAG
 #define YY_parse_DEBUG_FLAG yydebug
#endif

#ifndef YY_parse_ERROR
 #define YY_parse_ERROR yyerror
#endif

#ifndef YY_parse_PARSE_PARAM
 #ifndef __STDC__
  #ifndef __cplusplus
   #ifndef YY_USE_CLASS
    #define YY_parse_PARSE_PARAM
    #ifndef YY_parse_PARSE_PARAM_DEF
     #define YY_parse_PARSE_PARAM_DEF
    #endif
   #endif
  #endif
 #endif
 #ifndef YY_parse_PARSE_PARAM
  #define YY_parse_PARSE_PARAM void
 #endif
#endif

/* TOKEN C */
#ifndef YY_USE_CLASS

 #ifndef YY_parse_PURE
  #ifndef yylval
   extern YY_parse_STYPE YY_parse_LVAL;
  #else
   #if yylval != YY_parse_LVAL
    extern YY_parse_STYPE YY_parse_LVAL;
   #else
    #warning "Namespace conflict, disabling some functionality (bison++ only)"
   #endif
  #endif
 #endif


 #line 169 "/usr/share/bison++/bison.h"
#define	NEWLINE	258
#define	SPACES	259
#define	CR	260
#define	TAB	261
#define	LEFT_CURLY_BRACKET	262
#define	RIGHT_CURLY_BRACKET	263
#define	LEFT_BRACKET	264
#define	RIGHT_BRACKET	265
#define	LEFT_SQUARE_BRACKET	266
#define	RIGHT_SQUARE_BRACKET	267
#define	DELETE	268
#define	IGNORE	269
#define	TERMINAL	270
#define	NONTERMINAL	271
#define	GROUP	272
#define	ALIAS	273
#define	START	274
#define	COMMENT	275
#define	UNIQUE	276
#define	TYPE	277
#define	VARNAME	278


#line 169 "/usr/share/bison++/bison.h"
 /* #defines token */
/* after #define tokens, before const tokens S5*/
#else
 #ifndef YY_parse_CLASS
  #define YY_parse_CLASS parse
 #endif

 #ifndef YY_parse_INHERIT
  #define YY_parse_INHERIT
 #endif

 #ifndef YY_parse_MEMBERS
  #define YY_parse_MEMBERS 
 #endif

 #ifndef YY_parse_LEX_BODY
  #define YY_parse_LEX_BODY  
 #endif

 #ifndef YY_parse_ERROR_BODY
  #define YY_parse_ERROR_BODY  
 #endif

 #ifndef YY_parse_CONSTRUCTOR_PARAM
  #define YY_parse_CONSTRUCTOR_PARAM
 #endif
 /* choose between enum and const */
 #ifndef YY_parse_USE_CONST_TOKEN
  #define YY_parse_USE_CONST_TOKEN 0
  /* yes enum is more compatible with flex,  */
  /* so by default we use it */ 
 #endif
 #if YY_parse_USE_CONST_TOKEN != 0
  #ifndef YY_parse_ENUM_TOKEN
   #define YY_parse_ENUM_TOKEN yy_parse_enum_token
  #endif
 #endif

class YY_parse_CLASS YY_parse_INHERIT
{
public: 
 #if YY_parse_USE_CONST_TOKEN != 0
  /* static const int token ... */
  
 #line 212 "/usr/share/bison++/bison.h"
static const int NEWLINE;
static const int SPACES;
static const int CR;
static const int TAB;
static const int LEFT_CURLY_BRACKET;
static const int RIGHT_CURLY_BRACKET;
static const int LEFT_BRACKET;
static const int RIGHT_BRACKET;
static const int LEFT_SQUARE_BRACKET;
static const int RIGHT_SQUARE_BRACKET;
static const int DELETE;
static const int IGNORE;
static const int TERMINAL;
static const int NONTERMINAL;
static const int GROUP;
static const int ALIAS;
static const int START;
static const int COMMENT;
static const int UNIQUE;
static const int TYPE;
static const int VARNAME;


#line 212 "/usr/share/bison++/bison.h"
 /* decl const */
 #else
  enum YY_parse_ENUM_TOKEN { YY_parse_NULL_TOKEN=0
  
 #line 215 "/usr/share/bison++/bison.h"
	,NEWLINE=258
	,SPACES=259
	,CR=260
	,TAB=261
	,LEFT_CURLY_BRACKET=262
	,RIGHT_CURLY_BRACKET=263
	,LEFT_BRACKET=264
	,RIGHT_BRACKET=265
	,LEFT_SQUARE_BRACKET=266
	,RIGHT_SQUARE_BRACKET=267
	,DELETE=268
	,IGNORE=269
	,TERMINAL=270
	,NONTERMINAL=271
	,GROUP=272
	,ALIAS=273
	,START=274
	,COMMENT=275
	,UNIQUE=276
	,TYPE=277
	,VARNAME=278


#line 215 "/usr/share/bison++/bison.h"
 /* enum token */
     }; /* end of enum declaration */
 #endif
public:
 int YY_parse_PARSE(YY_parse_PARSE_PARAM);
 virtual void YY_parse_ERROR(char *msg) YY_parse_ERROR_BODY;
 #ifdef YY_parse_PURE
  #ifdef YY_parse_LSP_NEEDED
   virtual int  YY_parse_LEX(YY_parse_STYPE *YY_parse_LVAL,YY_parse_LTYPE *YY_parse_LLOC) YY_parse_LEX_BODY;
  #else
   virtual int  YY_parse_LEX(YY_parse_STYPE *YY_parse_LVAL) YY_parse_LEX_BODY;
  #endif
 #else
  virtual int YY_parse_LEX() YY_parse_LEX_BODY;
  YY_parse_STYPE YY_parse_LVAL;
  #ifdef YY_parse_LSP_NEEDED
   YY_parse_LTYPE YY_parse_LLOC;
  #endif
  int YY_parse_NERRS;
  int YY_parse_CHAR;
 #endif
 #if YY_parse_DEBUG != 0
  public:
   int YY_parse_DEBUG_FLAG;	/*  nonzero means print parse trace	*/
 #endif
public:
 YY_parse_CLASS(YY_parse_CONSTRUCTOR_PARAM);
public:
 YY_parse_MEMBERS 
};
/* other declare folow */
#endif


#if YY_parse_COMPATIBILITY != 0
 /* backward compatibility */
 /* Removed due to bison problems
 /#ifndef YYSTYPE
 / #define YYSTYPE YY_parse_STYPE
 /#endif*/

 #ifndef YYLTYPE
  #define YYLTYPE YY_parse_LTYPE
 #endif
 #ifndef YYDEBUG
  #ifdef YY_parse_DEBUG 
   #define YYDEBUG YY_parse_DEBUG
  #endif
 #endif

#endif
/* END */

 #line 267 "/usr/share/bison++/bison.h"
#endif
