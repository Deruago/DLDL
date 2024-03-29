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

#ifndef YY_DLDL_PRECEDENCE_DLDL_PRECEDENCE_PARSER_TAB_H_INCLUDED
# define YY_DLDL_PRECEDENCE_DLDL_PRECEDENCE_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int DLDL_PRECEDENCEdebug;
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
    PRECEDENCE = 258,              /* PRECEDENCE  */
    NUMBER = 259,                  /* NUMBER  */
    TERMINAL = 260,                /* TERMINAL  */
    SYMBOLS = 261,                 /* SYMBOLS  */
    ESCAPE_CHARS = 262             /* ESCAPE_CHARS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 68 "./DLDL_PRECEDENCE_parser.y"

	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_PRECEDENCE::ast::node::PRECEDENCE* DLDL_PRECEDENCE_PRECEDENCE;
	::DLDL_PRECEDENCE::ast::node::NUMBER* DLDL_PRECEDENCE_NUMBER;
	::DLDL_PRECEDENCE::ast::node::TERMINAL* DLDL_PRECEDENCE_TERMINAL;
	::DLDL_PRECEDENCE::ast::node::SYMBOLS* DLDL_PRECEDENCE_SYMBOLS;
	::DLDL_PRECEDENCE::ast::node::ESCAPE_CHARS* DLDL_PRECEDENCE_ESCAPE_CHARS;
	::DLDL_PRECEDENCE::ast::node::program* DLDL_PRECEDENCE_program;
	::DLDL_PRECEDENCE::ast::node::stmts* DLDL_PRECEDENCE_stmts;
	::DLDL_PRECEDENCE::ast::node::stmt* DLDL_PRECEDENCE_stmt;
	::DLDL_PRECEDENCE::ast::node::localized_precedence* DLDL_PRECEDENCE_localized_precedence;
	::DLDL_PRECEDENCE::ast::node::specific_precedence* DLDL_PRECEDENCE_specific_precedence;
	::DLDL_PRECEDENCE::ast::node::terminal_one_or_more* DLDL_PRECEDENCE_terminal_one_or_more;


#line 82 "DLDL_PRECEDENCE_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE DLDL_PRECEDENCElval;

int DLDL_PRECEDENCEparse (void);

#endif /* !YY_DLDL_PRECEDENCE_DLDL_PRECEDENCE_PARSER_TAB_H_INCLUDED  */
