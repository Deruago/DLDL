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

#ifndef YY_DLDL_LPDDEF_EF_DLDL_LPDDEF_EF_PARSER_TAB_H_INCLUDED
# define YY_DLDL_LPDDEF_EF_DLDL_LPDDEF_EF_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int DLDL_LPDDEF_EFdebug;
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
    COMMENT = 258,                 /* COMMENT  */
    VARNAME = 259,                 /* VARNAME  */
    NUMBER = 260,                  /* NUMBER  */
    COLON = 261,                   /* COLON  */
    SEMICOLON = 262,               /* SEMICOLON  */
    ESCAPE_CHARS = 263             /* ESCAPE_CHARS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 74 "./DLDL_LPDDEF_EF_parser.y"

	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_LPDDEF_EF::ast::node::COMMENT* DLDL_LPDDEF_EF_COMMENT;
	::DLDL_LPDDEF_EF::ast::node::VARNAME* DLDL_LPDDEF_EF_VARNAME;
	::DLDL_LPDDEF_EF::ast::node::NUMBER* DLDL_LPDDEF_EF_NUMBER;
	::DLDL_LPDDEF_EF::ast::node::COLON* DLDL_LPDDEF_EF_COLON;
	::DLDL_LPDDEF_EF::ast::node::SEMICOLON* DLDL_LPDDEF_EF_SEMICOLON;
	::DLDL_LPDDEF_EF::ast::node::ESCAPE_CHARS* DLDL_LPDDEF_EF_ESCAPE_CHARS;
	::DLDL_LPDDEF_EF::ast::node::program* DLDL_LPDDEF_EF_program;
	::DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__* DLDL_LPDDEF_EF_deamerreserved_star__stmt__;
	::DLDL_LPDDEF_EF::ast::node::stmt* DLDL_LPDDEF_EF_stmt;
	::DLDL_LPDDEF_EF::ast::node::comment_line* DLDL_LPDDEF_EF_comment_line;
	::DLDL_LPDDEF_EF::ast::node::standard_variant* DLDL_LPDDEF_EF_standard_variant;
	::DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number* DLDL_LPDDEF_EF_standard_variant_specific_number;
	::DLDL_LPDDEF_EF::ast::node::value* DLDL_LPDDEF_EF_value;
	::DLDL_LPDDEF_EF::ast::node::enum_name* DLDL_LPDDEF_EF_enum_name;


#line 86 "DLDL_LPDDEF_EF_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE DLDL_LPDDEF_EFlval;

int DLDL_LPDDEF_EFparse (void);

#endif /* !YY_DLDL_LPDDEF_EF_DLDL_LPDDEF_EF_PARSER_TAB_H_INCLUDED  */
