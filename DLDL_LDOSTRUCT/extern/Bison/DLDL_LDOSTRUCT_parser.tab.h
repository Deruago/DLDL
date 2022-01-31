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

#ifndef YY_DLDL_LDOSTRUCT_DLDL_LDOSTRUCT_PARSER_TAB_H_INCLUDED
# define YY_DLDL_LDOSTRUCT_DLDL_LDOSTRUCT_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int DLDL_LDOSTRUCTdebug;
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
#line 61 "./DLDL_LDOSTRUCT_parser.y"

	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_LDOSTRUCT::ast::node::COLON* DLDL_LDOSTRUCT_COLON;
	::DLDL_LDOSTRUCT::ast::node::LEFT_ANGLE_BRACKET* DLDL_LDOSTRUCT_LEFT_ANGLE_BRACKET;
	::DLDL_LDOSTRUCT::ast::node::RIGHT_ANGLE_BRACKET* DLDL_LDOSTRUCT_RIGHT_ANGLE_BRACKET;
	::DLDL_LDOSTRUCT::ast::node::VARNAME* DLDL_LDOSTRUCT_VARNAME;
	::DLDL_LDOSTRUCT::ast::node::VARNAME_EXT* DLDL_LDOSTRUCT_VARNAME_EXT;
	::DLDL_LDOSTRUCT::ast::node::INDENTED_VALUE* DLDL_LDOSTRUCT_INDENTED_VALUE;
	::DLDL_LDOSTRUCT::ast::node::ESCAPE_CHARS* DLDL_LDOSTRUCT_ESCAPE_CHARS;
	::DLDL_LDOSTRUCT::ast::node::program* DLDL_LDOSTRUCT_program;
	::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__stmt__* DLDL_LDOSTRUCT_deamerreserved_star__stmt__;
	::DLDL_LDOSTRUCT::ast::node::stmt* DLDL_LDOSTRUCT_stmt;
	::DLDL_LDOSTRUCT::ast::node::argument* DLDL_LDOSTRUCT_argument;
	::DLDL_LDOSTRUCT::ast::node::argument_name* DLDL_LDOSTRUCT_argument_name;
	::DLDL_LDOSTRUCT::ast::node::argument_block* DLDL_LDOSTRUCT_argument_block;
	::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__argument_stmt__* DLDL_LDOSTRUCT_deamerreserved_star__argument_stmt__;
	::DLDL_LDOSTRUCT::ast::node::argument_stmt* DLDL_LDOSTRUCT_argument_stmt;

#line 91 "DLDL_LDOSTRUCT_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE DLDL_LDOSTRUCTlval;


int DLDL_LDOSTRUCTparse (void);


#endif /* !YY_DLDL_LDOSTRUCT_DLDL_LDOSTRUCT_PARSER_TAB_H_INCLUDED  */
