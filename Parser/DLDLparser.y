%{
#include <AstNodes.h>
#include <Deamer/AstGen/AstInformation.h>
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstTree.h>
#include "./DLDLParser.h"
#include <vector>
#include <iostream>
#include <cstring>
#include <stdio.h>

#ifndef YY_parse_NERRS
#define YY_parse_NERRS DLDLnerrs
#endif //YY_parse_NERRS
#ifndef YY_parse_LLOC
#define YY_parse_LLOC DLDLlloc
#endif //YY_parse_LLOC

#define YYERROR_VERBOSE

extern "C" void DLDLerror(char* s);
extern "C" int DLDLparse();
extern "C" FILE* DLDLin;
int DLDLlex();
%}

%token NEWLINE
%token SPACES
%token CR
%token TAB
%token LEFT_CURLY_BRACKET
%token RIGHT_CURLY_BRACKET
%token LEFT_BRACKET
%token RIGHT_BRACKET
%token LEFT_SQUARE_BRACKET
%token RIGHT_SQUARE_BRACKET
%token DELETE
%token IGNORE
%token TERMINAL
%token NONTERMINAL
%token GROUP
%token ALIAS
%token START
%token COMMENT
%token UNIQUE
%token TYPE
%token VARNAME

%type <DeamerNode> NEWLINE
%type <DeamerNode> SPACES
%type <DeamerNode> CR
%type <DeamerNode> TAB
%type <DeamerNode> LEFT_CURLY_BRACKET
%type <DeamerNode> RIGHT_CURLY_BRACKET
%type <DeamerNode> LEFT_BRACKET
%type <DeamerNode> RIGHT_BRACKET
%type <DeamerNode> LEFT_SQUARE_BRACKET
%type <DeamerNode> RIGHT_SQUARE_BRACKET
%type <DeamerNode> DELETE
%type <DeamerNode> IGNORE
%type <DeamerNode> TERMINAL
%type <DeamerNode> NONTERMINAL
%type <DeamerNode> GROUP
%type <DeamerNode> ALIAS
%type <DeamerNode> START
%type <DeamerNode> COMMENT
%type <DeamerNode> UNIQUE
%type <DeamerNode> TYPE
%type <DeamerNode> VARNAME
%type <DLDL_PROG> PROG
%type <DLDL_STMTS> STMTS
%type <DLDL_STMT> STMT
%type <DLDL_ABSTRACTION> ABSTRACTION
%type <DLDL_TERMINALS> TERMINALS
%type <DLDL_TERMINAL_DECL> TERMINAL_DECL
%type <DLDL_NONTERMINAL_DECL> NONTERMINAL_DECL
%type <DLDL_ABSTRACTION_DECL> ABSTRACTION_DECL
%type <DLDL_RULE_DECL> RULE_DECL
%type <DLDL_TERMINAL_BLOCK> TERMINAL_BLOCK
%type <DLDL_NONTERMINAL_BLOCK> NONTERMINAL_BLOCK
%type <DLDL_RULES> RULES
%type <DLDL_ABSTRACTION_BLOCK> ABSTRACTION_BLOCK
%type <DLDL_ABSTRACTION_INPUTS> ABSTRACTION_INPUTS
%type <DLDL_ABSTRACTION_INPUT> ABSTRACTION_INPUT
%type <DLDL_GENERAL_BLOCK> GENERAL_BLOCK
%type <DLDL_VARLIST> VARLIST

%union{
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
}



%%


PROG:
      STMTS {
      DLDL::AstTree_PROG* ASTTREE_PROG = new DLDL::AstTree_PROG($1);
      ASTTREE_PROG->SetCurrentTree(ASTTREE_PROG);
    }
;

STMTS:
      STMT STMTS {
      $$ = $2;
      $$->push_back(new DLDL::AstNode_STMTS($1));
    }
    | {
          $$ = new std::vector<DLDL::AstNode_STMTS*>();
    }
;

STMT:
      TERMINAL_DECL {
      $$ = $1
    }
    | NONTERMINAL_DECL {
      $$ = $1
    }
    | ABSTRACTION_DECL {
      $$ = $1
    }
;

ABSTRACTION:
      DELETE {
      $$ = new DLDL::AstNode_DELETE($1);
    }
    | IGNORE {
      $$ = new DLDL::AstNode_IGNORE($1);
    }
    | TERMINAL {
      $$ = new DLDL::AstNode_TERMINAL($1);
    }
    | NONTERMINAL {
      $$ = new DLDL::AstNode_NONTERMINAL($1);
    }
    | GROUP {
      $$ = new DLDL::AstNode_GROUP($1);
    }
    | ALIAS {
      $$ = new DLDL::AstNode_ALIAS($1);
    }
    | START {
      $$ = new DLDL::AstNode_START($1);
    }
    | COMMENT {
      $$ = new DLDL::AstNode_COMMENT($1);
    }
    | UNIQUE {
      $$ = new DLDL::AstNode_UNIQUE($1);
    }
    | TYPE {
      $$ = new DLDL::AstNode_TYPE($1);
    }
;

TERMINALS:
      TERMINAL_DECL TERMINALS {
      $$ = $2;
      $$->push_back(new DLDL::AstNode_TERMINALS($1));
    }
    | {
          $$ = new std::vector<DLDL::AstNode_TERMINALS*>();
    }
;

TERMINAL_DECL:
      VARNAME VARLIST LEFT_BRACKET TERMINAL_BLOCK RIGHT_BRACKET {
      $$ = new DLDL::AstNode_TERMINAL_DECL(new DLDL::AstNode_VARNAME($1), $2, $4);
    }
;

NONTERMINAL_DECL:
      VARNAME LEFT_BRACKET NONTERMINAL_BLOCK RIGHT_BRACKET {
      $$ = new DLDL::AstNode_NONTERMINAL_DECL(new DLDL::AstNode_VARNAME($1), $3);
    }
;

ABSTRACTION_DECL:
      ABSTRACTION VARLIST LEFT_BRACKET ABSTRACTION_BLOCK RIGHT_BRACKET {
      $$ = new DLDL::AstNode_ABSTRACTION_DECL($1, $2, $4);
    }
;

RULE_DECL:
      VARLIST LEFT_BRACKET GENERAL_BLOCK RIGHT_BRACKET {
      $$ = new DLDL::AstNode_RULE_DECL($1, $3);
    }
;

TERMINAL_BLOCK:
      GENERAL_BLOCK {
      $$ = new DLDL::AstNode_TERMINAL_BLOCK($1);
    }
;

NONTERMINAL_BLOCK:
      RULES {
      $$ = new DLDL::AstNode_NONTERMINAL_BLOCK($1);
    }
;

RULES:
      RULE_DECL RULES {
      $$ = $2;
      $$->push_back(new DLDL::AstNode_RULES($1));
    }
    | RULE_DECL {
      $$ = new std::vector<DLDL::AstNode_RULES*>();
      $$->push_back(new DLDL::AstNode_RULES($1));
    }
;

ABSTRACTION_BLOCK:
      ABSTRACTION_INPUTS {
      $$ = new DLDL::AstNode_ABSTRACTION_BLOCK($1);
    }
;

ABSTRACTION_INPUTS:
      ABSTRACTION_INPUT LEFT_BRACKET RIGHT_BRACKET ABSTRACTION_INPUTS {
      $$ = $4;
      $$->push_back(new DLDL::AstNode_ABSTRACTION_INPUTS($1));
    }
    | {
          $$ = new std::vector<DLDL::AstNode_ABSTRACTION_INPUTS*>();
    }
;

ABSTRACTION_INPUT:
      VARLIST {
      $$ = new DLDL::AstNode_ABSTRACTION_INPUT($1);
    }
;

GENERAL_BLOCK:
      VARLIST {
      $$ = new DLDL::AstNode_GENERAL_BLOCK($1);
    }
    | {
      $$ = new DLDL::AstNode_GENERAL_BLOCK();
    }
;

VARLIST:
      VARNAME VARLIST {
      $$ = $2;
      $$->push_back(new DLDL::AstNode_VARLIST(new DLDL::AstNode_VARNAME($1)));
    }
    | VARNAME {
      $$ = new std::vector<DLDL::AstNode_VARLIST*>();
      $$->push_back(new DLDL::AstNode_VARLIST(new DLDL::AstNode_VARNAME($1)));
    }
;




%%


void DLDLerror(char *s)
{
    printf("Syntax error on line %s\n", s);
}

deamer::AstNode* DLDL::DLDLParser::ParseText(std::string inputText)
{
    FILE* tmpFile = fmemopen((void*)inputText.c_str(), inputText.size(), "r");
    if (tmpFile == nullptr)
    {
        return nullptr;
    }
    DLDLin = tmpFile;
    DLDLparse();
    return AstTree_PROG::currentTree;
}

deamer::AstNode* DLDL::DLDLParser::ParseFile(FILE* inputFile)
{
    if (inputFile == nullptr)
    {
        return nullptr;
    }
    DLDLin = inputFile;
    DLDLparse();
    return AstTree_PROG::currentTree;
}

deamer::AstNode* DLDL::DLDLParser::ParseFile(std::string fileLocation)
{
    FILE* inputFile = fopen(fileLocation.c_str(), "r");;
    if (inputFile == nullptr)
    {
        return nullptr;
    }
    DLDLin = inputFile;
    DLDLparse();
    return AstTree_PROG::currentTree;
}

DLDL::DLDLParser::DLDLParser()
{
}

DLDL::DLDLParser::~DLDLParser()
{
}


