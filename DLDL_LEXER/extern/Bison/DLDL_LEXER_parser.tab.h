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

#ifndef YY_DLDL_LEXER_DLDL_LEXER_PARSER_TAB_H_INCLUDED
# define YY_DLDL_LEXER_DLDL_LEXER_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int DLDL_LEXERdebug;
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
    DELETE_ABSTRACTION = 258,      /* DELETE_ABSTRACTION  */
    IGNORE_ABSTRACTION = 259,      /* IGNORE_ABSTRACTION  */
    NOVALUE_ABSTRACTION = 260,     /* NOVALUE_ABSTRACTION  */
    CRASH_ABSTRACTION = 261,       /* CRASH_ABSTRACTION  */
    STANDARD_ABSTRACTION = 262,    /* STANDARD_ABSTRACTION  */
    UNKNOWN_ABSTRACTION = 263,     /* UNKNOWN_ABSTRACTION  */
    TERMINAL = 264,                /* TERMINAL  */
    REGEX = 265                    /* REGEX  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 60 "./DLDL_LEXER_parser.y"

	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_LEXER::ast::node::DELETE_ABSTRACTION* DLDL_LEXER_DELETE_ABSTRACTION;
	::DLDL_LEXER::ast::node::IGNORE_ABSTRACTION* DLDL_LEXER_IGNORE_ABSTRACTION;
	::DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION* DLDL_LEXER_NOVALUE_ABSTRACTION;
	::DLDL_LEXER::ast::node::CRASH_ABSTRACTION* DLDL_LEXER_CRASH_ABSTRACTION;
	::DLDL_LEXER::ast::node::STANDARD_ABSTRACTION* DLDL_LEXER_STANDARD_ABSTRACTION;
	::DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION* DLDL_LEXER_UNKNOWN_ABSTRACTION;
	::DLDL_LEXER::ast::node::TERMINAL* DLDL_LEXER_TERMINAL;
	::DLDL_LEXER::ast::node::REGEX* DLDL_LEXER_REGEX;
	::DLDL_LEXER::ast::node::ESCAPE_CHARS* DLDL_LEXER_ESCAPE_CHARS;
	::DLDL_LEXER::ast::node::COMMENT* DLDL_LEXER_COMMENT;
	::DLDL_LEXER::ast::node::program* DLDL_LEXER_program;
	::DLDL_LEXER::ast::node::stmts* DLDL_LEXER_stmts;
	::DLDL_LEXER::ast::node::stmt* DLDL_LEXER_stmt;
	::DLDL_LEXER::ast::node::tokendeclaration* DLDL_LEXER_tokendeclaration;
	::DLDL_LEXER::ast::node::abstraction* DLDL_LEXER_abstraction;

#line 93 "DLDL_LEXER_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE DLDL_LEXERlval;


int DLDL_LEXERparse (void);


#endif /* !YY_DLDL_LEXER_DLDL_LEXER_PARSER_TAB_H_INCLUDED  */
