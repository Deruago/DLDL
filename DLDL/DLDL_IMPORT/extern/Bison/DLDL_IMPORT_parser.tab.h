/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Skeleton interface for Bison GLR parsers in C

   Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_DLDL_IMPORT_DLDL_IMPORT_PARSER_TAB_H_INCLUDED
# define YY_DLDL_IMPORT_DLDL_IMPORT_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int DLDL_IMPORTdebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SINGLE_COMMENT = 258,          /* SINGLE_COMMENT  */
    MULTI_COMMENT = 259,           /* MULTI_COMMENT  */
    LEFT_PARANTHESIS = 260,        /* LEFT_PARANTHESIS  */
    RIGHT_PARANTHESIS = 261,       /* RIGHT_PARANTHESIS  */
    LEFT_SQUARE_BRACKET = 262,     /* LEFT_SQUARE_BRACKET  */
    RIGHT_SQUARE_BRACKET = 263,    /* RIGHT_SQUARE_BRACKET  */
    COLON = 264,                   /* COLON  */
    DOT = 265,                     /* DOT  */
    IMPORT_FILE = 266,             /* IMPORT_FILE  */
    IMPORT_MODULE = 267,           /* IMPORT_MODULE  */
    IMPORT = 268,                  /* IMPORT  */
    TEXT = 269,                    /* TEXT  */
    VARNAME = 270,                 /* VARNAME  */
    ESCAPE_CHARS = 271             /* ESCAPE_CHARS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 102 "./DLDL_IMPORT_parser.y"

	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_IMPORT::ast::node::SINGLE_COMMENT* DLDL_IMPORT_SINGLE_COMMENT;
	::DLDL_IMPORT::ast::node::MULTI_COMMENT* DLDL_IMPORT_MULTI_COMMENT;
	::DLDL_IMPORT::ast::node::LEFT_PARANTHESIS* DLDL_IMPORT_LEFT_PARANTHESIS;
	::DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS* DLDL_IMPORT_RIGHT_PARANTHESIS;
	::DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET* DLDL_IMPORT_LEFT_SQUARE_BRACKET;
	::DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET* DLDL_IMPORT_RIGHT_SQUARE_BRACKET;
	::DLDL_IMPORT::ast::node::COLON* DLDL_IMPORT_COLON;
	::DLDL_IMPORT::ast::node::DOT* DLDL_IMPORT_DOT;
	::DLDL_IMPORT::ast::node::IMPORT_FILE* DLDL_IMPORT_IMPORT_FILE;
	::DLDL_IMPORT::ast::node::IMPORT_MODULE* DLDL_IMPORT_IMPORT_MODULE;
	::DLDL_IMPORT::ast::node::IMPORT* DLDL_IMPORT_IMPORT;
	::DLDL_IMPORT::ast::node::TEXT* DLDL_IMPORT_TEXT;
	::DLDL_IMPORT::ast::node::VARNAME* DLDL_IMPORT_VARNAME;
	::DLDL_IMPORT::ast::node::ESCAPE_CHARS* DLDL_IMPORT_ESCAPE_CHARS;
	::DLDL_IMPORT::ast::node::program* DLDL_IMPORT_program;
	::DLDL_IMPORT::ast::node::deamerreserved_star__stmt__* DLDL_IMPORT_deamerreserved_star__stmt__;
	::DLDL_IMPORT::ast::node::stmt* DLDL_IMPORT_stmt;
	::DLDL_IMPORT::ast::node::import_declaration* DLDL_IMPORT_import_declaration;
	::DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__* DLDL_IMPORT_deamerreserved_arrow__import_context__;
	::DLDL_IMPORT::ast::node::deamerreserved_long_40* DLDL_IMPORT_deamerreserved_long_40;
	::DLDL_IMPORT::ast::node::deamerreserved_long_43* DLDL_IMPORT_deamerreserved_long_43;
	::DLDL_IMPORT::ast::node::specialization* DLDL_IMPORT_specialization;
	::DLDL_IMPORT::ast::node::import_abstraction* DLDL_IMPORT_import_abstraction;
	::DLDL_IMPORT::ast::node::value* DLDL_IMPORT_value;
	::DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__* DLDL_IMPORT_deamerreserved_optional__VARNAME__;
	::DLDL_IMPORT::ast::node::abstraction* DLDL_IMPORT_abstraction;
	::DLDL_IMPORT::ast::node::import_context* DLDL_IMPORT_import_context;
	::DLDL_IMPORT::ast::node::import_rule_name* DLDL_IMPORT_import_rule_name;


#line 108 "DLDL_IMPORT_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE DLDL_IMPORTlval;

int DLDL_IMPORTparse (void);

#endif /* !YY_DLDL_IMPORT_DLDL_IMPORT_PARSER_TAB_H_INCLUDED  */
