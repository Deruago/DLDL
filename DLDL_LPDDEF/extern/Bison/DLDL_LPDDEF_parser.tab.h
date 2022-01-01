/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_DLDL_LPDDEF_DLDL_LPDDEF_PARSER_TAB_H_INCLUDED
# define YY_DLDL_LPDDEF_DLDL_LPDDEF_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int DLDL_LPDDEFdebug;
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
    INDENTED_VALUE = 263           /* INDENTED_VALUE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 61 "./DLDL_LPDDEF_parser.y"

	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_LPDDEF::ast::node::COLON* DLDL_LPDDEF_COLON;
	::DLDL_LPDDEF::ast::node::LEFT_ANGLE_BRACKET* DLDL_LPDDEF_LEFT_ANGLE_BRACKET;
	::DLDL_LPDDEF::ast::node::RIGHT_ANGLE_BRACKET* DLDL_LPDDEF_RIGHT_ANGLE_BRACKET;
	::DLDL_LPDDEF::ast::node::VARNAME* DLDL_LPDDEF_VARNAME;
	::DLDL_LPDDEF::ast::node::VARNAME_EXT* DLDL_LPDDEF_VARNAME_EXT;
	::DLDL_LPDDEF::ast::node::INDENTED_VALUE* DLDL_LPDDEF_INDENTED_VALUE;
	::DLDL_LPDDEF::ast::node::ESCAPE_CHARS* DLDL_LPDDEF_ESCAPE_CHARS;
	::DLDL_LPDDEF::ast::node::program* DLDL_LPDDEF_program;
	::DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__* DLDL_LPDDEF_deamerreserved_star__stmt__;
	::DLDL_LPDDEF::ast::node::stmt* DLDL_LPDDEF_stmt;
	::DLDL_LPDDEF::ast::node::argument* DLDL_LPDDEF_argument;
	::DLDL_LPDDEF::ast::node::argument_name* DLDL_LPDDEF_argument_name;
	::DLDL_LPDDEF::ast::node::argument_block* DLDL_LPDDEF_argument_block;
	::DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__* DLDL_LPDDEF_deamerreserved_star__argument_stmt__;
	::DLDL_LPDDEF::ast::node::argument_stmt* DLDL_LPDDEF_argument_stmt;

#line 91 "DLDL_LPDDEF_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE DLDL_LPDDEFlval;


int DLDL_LPDDEFparse (void);


#endif /* !YY_DLDL_LPDDEF_DLDL_LPDDEF_PARSER_TAB_H_INCLUDED  */
