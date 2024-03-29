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

#ifndef YY_DLDL_GENERATION_DLDL_GENERATION_PARSER_TAB_H_INCLUDED
# define YY_DLDL_GENERATION_DLDL_GENERATION_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int DLDL_GENERATIONdebug;
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
    GENERATE = 258,                /* GENERATE  */
    INTEGRATE = 259,               /* INTEGRATE  */
    ARGUMENT = 260,                /* ARGUMENT  */
    VALUE = 261,                   /* VALUE  */
    SYMBOLS = 262,                 /* SYMBOLS  */
    ESCAPE_CHARS = 263             /* ESCAPE_CHARS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 76 "./DLDL_GENERATION_parser.y"

	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_GENERATION::ast::node::GENERATE* DLDL_GENERATION_GENERATE;
	::DLDL_GENERATION::ast::node::INTEGRATE* DLDL_GENERATION_INTEGRATE;
	::DLDL_GENERATION::ast::node::ARGUMENT* DLDL_GENERATION_ARGUMENT;
	::DLDL_GENERATION::ast::node::VALUE* DLDL_GENERATION_VALUE;
	::DLDL_GENERATION::ast::node::SYMBOLS* DLDL_GENERATION_SYMBOLS;
	::DLDL_GENERATION::ast::node::ESCAPE_CHARS* DLDL_GENERATION_ESCAPE_CHARS;
	::DLDL_GENERATION::ast::node::program* DLDL_GENERATION_program;
	::DLDL_GENERATION::ast::node::stmts* DLDL_GENERATION_stmts;
	::DLDL_GENERATION::ast::node::stmt* DLDL_GENERATION_stmt;
	::DLDL_GENERATION::ast::node::generate_declaration* DLDL_GENERATION_generate_declaration;
	::DLDL_GENERATION::ast::node::integrate_declaration* DLDL_GENERATION_integrate_declaration;
	::DLDL_GENERATION::ast::node::argument_declaration* DLDL_GENERATION_argument_declaration;
	::DLDL_GENERATION::ast::node::type* DLDL_GENERATION_type;
	::DLDL_GENERATION::ast::node::tool* DLDL_GENERATION_tool;
	::DLDL_GENERATION::ast::node::argument_data* DLDL_GENERATION_argument_data;


#line 87 "DLDL_GENERATION_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE DLDL_GENERATIONlval;

int DLDL_GENERATIONparse (void);

#endif /* !YY_DLDL_GENERATION_DLDL_GENERATION_PARSER_TAB_H_INCLUDED  */
