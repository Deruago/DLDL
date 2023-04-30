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

#ifndef YY_DLDL_LPDSTRUCT_DLDL_LPDSTRUCT_PARSER_TAB_H_INCLUDED
# define YY_DLDL_LPDSTRUCT_DLDL_LPDSTRUCT_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int DLDL_LPDSTRUCTdebug;
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
    COLON = 258,                   /* COLON  */
    LEFT_ANGLE_BRACKET = 259,      /* LEFT_ANGLE_BRACKET  */
    RIGHT_ANGLE_BRACKET = 260,     /* RIGHT_ANGLE_BRACKET  */
    VARNAME = 261,                 /* VARNAME  */
    VARNAME_EXT = 262,             /* VARNAME_EXT  */
    INDENTED_VALUE = 263,          /* INDENTED_VALUE  */
    ESCAPE_CHARS = 264             /* ESCAPE_CHARS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 78 "./DLDL_LPDSTRUCT_parser.y"

	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_LPDSTRUCT::ast::node::COLON* DLDL_LPDSTRUCT_COLON;
	::DLDL_LPDSTRUCT::ast::node::LEFT_ANGLE_BRACKET* DLDL_LPDSTRUCT_LEFT_ANGLE_BRACKET;
	::DLDL_LPDSTRUCT::ast::node::RIGHT_ANGLE_BRACKET* DLDL_LPDSTRUCT_RIGHT_ANGLE_BRACKET;
	::DLDL_LPDSTRUCT::ast::node::VARNAME* DLDL_LPDSTRUCT_VARNAME;
	::DLDL_LPDSTRUCT::ast::node::VARNAME_EXT* DLDL_LPDSTRUCT_VARNAME_EXT;
	::DLDL_LPDSTRUCT::ast::node::INDENTED_VALUE* DLDL_LPDSTRUCT_INDENTED_VALUE;
	::DLDL_LPDSTRUCT::ast::node::ESCAPE_CHARS* DLDL_LPDSTRUCT_ESCAPE_CHARS;
	::DLDL_LPDSTRUCT::ast::node::program* DLDL_LPDSTRUCT_program;
	::DLDL_LPDSTRUCT::ast::node::deamerreserved_star__stmt__* DLDL_LPDSTRUCT_deamerreserved_star__stmt__;
	::DLDL_LPDSTRUCT::ast::node::stmt* DLDL_LPDSTRUCT_stmt;
	::DLDL_LPDSTRUCT::ast::node::argument* DLDL_LPDSTRUCT_argument;
	::DLDL_LPDSTRUCT::ast::node::argument_name* DLDL_LPDSTRUCT_argument_name;
	::DLDL_LPDSTRUCT::ast::node::argument_block* DLDL_LPDSTRUCT_argument_block;
	::DLDL_LPDSTRUCT::ast::node::deamerreserved_long_60* DLDL_LPDSTRUCT_deamerreserved_long_60;
	::DLDL_LPDSTRUCT::ast::node::deamerreserved_long_63* DLDL_LPDSTRUCT_deamerreserved_long_63;
	::DLDL_LPDSTRUCT::ast::node::deamerreserved_long_66* DLDL_LPDSTRUCT_deamerreserved_long_66;


#line 89 "DLDL_LPDSTRUCT_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE DLDL_LPDSTRUCTlval;

int DLDL_LPDSTRUCTparse (void);

#endif /* !YY_DLDL_LPDSTRUCT_DLDL_LPDSTRUCT_PARSER_TAB_H_INCLUDED  */
