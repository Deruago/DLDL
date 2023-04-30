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

#ifndef YY_DLDL_COMMENT_DLDL_COMMENT_PARSER_TAB_H_INCLUDED
# define YY_DLDL_COMMENT_DLDL_COMMENT_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int DLDL_COMMENTdebug;
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
    COMMENT_VALUE = 260,           /* COMMENT_VALUE  */
    LEFT_SQUARE_BRACKET = 261,     /* LEFT_SQUARE_BRACKET  */
    RIGHT_SQUARE_BRACKET = 262,    /* RIGHT_SQUARE_BRACKET  */
    START = 263,                   /* START  */
    END = 264,                     /* END  */
    TEXT = 265,                    /* TEXT  */
    VARNAME = 266,                 /* VARNAME  */
    ESCAPE_CHARS = 267             /* ESCAPE_CHARS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 92 "./DLDL_COMMENT_parser.y"

	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_COMMENT::ast::node::SINGLE_COMMENT* DLDL_COMMENT_SINGLE_COMMENT;
	::DLDL_COMMENT::ast::node::MULTI_COMMENT* DLDL_COMMENT_MULTI_COMMENT;
	::DLDL_COMMENT::ast::node::COMMENT_VALUE* DLDL_COMMENT_COMMENT_VALUE;
	::DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET* DLDL_COMMENT_LEFT_SQUARE_BRACKET;
	::DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET* DLDL_COMMENT_RIGHT_SQUARE_BRACKET;
	::DLDL_COMMENT::ast::node::START* DLDL_COMMENT_START;
	::DLDL_COMMENT::ast::node::END* DLDL_COMMENT_END;
	::DLDL_COMMENT::ast::node::TEXT* DLDL_COMMENT_TEXT;
	::DLDL_COMMENT::ast::node::VARNAME* DLDL_COMMENT_VARNAME;
	::DLDL_COMMENT::ast::node::ESCAPE_CHARS* DLDL_COMMENT_ESCAPE_CHARS;
	::DLDL_COMMENT::ast::node::program* DLDL_COMMENT_program;
	::DLDL_COMMENT::ast::node::deamerreserved_star__stmt__* DLDL_COMMENT_deamerreserved_star__stmt__;
	::DLDL_COMMENT::ast::node::stmt* DLDL_COMMENT_stmt;
	::DLDL_COMMENT::ast::node::comment_value_declaration* DLDL_COMMENT_comment_value_declaration;
	::DLDL_COMMENT::ast::node::deamerreserved_long_3* DLDL_COMMENT_deamerreserved_long_3;
	::DLDL_COMMENT::ast::node::deamerreserved_long_6* DLDL_COMMENT_deamerreserved_long_6;
	::DLDL_COMMENT::ast::node::comment_abstraction* DLDL_COMMENT_comment_abstraction;
	::DLDL_COMMENT::ast::node::start_abstraction* DLDL_COMMENT_start_abstraction;
	::DLDL_COMMENT::ast::node::end_abstraction* DLDL_COMMENT_end_abstraction;
	::DLDL_COMMENT::ast::node::start_sequence* DLDL_COMMENT_start_sequence;
	::DLDL_COMMENT::ast::node::end_sequence* DLDL_COMMENT_end_sequence;
	::DLDL_COMMENT::ast::node::sequence* DLDL_COMMENT_sequence;
	::DLDL_COMMENT::ast::node::syntactic_reference* DLDL_COMMENT_syntactic_reference;


#line 99 "DLDL_COMMENT_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE DLDL_COMMENTlval;

int DLDL_COMMENTparse (void);

#endif /* !YY_DLDL_COMMENT_DLDL_COMMENT_PARSER_TAB_H_INCLUDED  */
