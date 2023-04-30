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

#ifndef YY_DLDL_ARGUMENT_DLDL_ARGUMENT_PARSER_TAB_H_INCLUDED
# define YY_DLDL_ARGUMENT_DLDL_ARGUMENT_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int DLDL_ARGUMENTdebug;
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
    TEXT = 260,                    /* TEXT  */
    VARNAME = 261,                 /* VARNAME  */
    ESCAPE_CHARS = 262             /* ESCAPE_CHARS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 58 "./DLDL_ARGUMENT_parser.y"

	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_ARGUMENT::ast::node::SINGLE_COMMENT* DLDL_ARGUMENT_SINGLE_COMMENT;
	::DLDL_ARGUMENT::ast::node::MULTI_COMMENT* DLDL_ARGUMENT_MULTI_COMMENT;
	::DLDL_ARGUMENT::ast::node::TEXT* DLDL_ARGUMENT_TEXT;
	::DLDL_ARGUMENT::ast::node::VARNAME* DLDL_ARGUMENT_VARNAME;
	::DLDL_ARGUMENT::ast::node::ESCAPE_CHARS* DLDL_ARGUMENT_ESCAPE_CHARS;
	::DLDL_ARGUMENT::ast::node::program* DLDL_ARGUMENT_program;


#line 77 "DLDL_ARGUMENT_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE DLDL_ARGUMENTlval;

int DLDL_ARGUMENTparse (void);

#endif /* !YY_DLDL_ARGUMENT_DLDL_ARGUMENT_PARSER_TAB_H_INCLUDED  */
