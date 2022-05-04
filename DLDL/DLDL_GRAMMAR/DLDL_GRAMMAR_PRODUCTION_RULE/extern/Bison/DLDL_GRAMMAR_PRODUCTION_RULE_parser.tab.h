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

#ifndef YY_DLDL_GRAMMAR_PRODUCTION_RULE_DLDL_GRAMMAR_PRODUCTION_RULE_PARSER_TAB_H_INCLUDED
# define YY_DLDL_GRAMMAR_PRODUCTION_RULE_DLDL_GRAMMAR_PRODUCTION_RULE_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int DLDL_GRAMMAR_PRODUCTION_RULEdebug;
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
    ENDING_USELESS_SYMBOLS = 258,  /* ENDING_USELESS_SYMBOLS  */
    VERTICAL_SLASH = 259,          /* VERTICAL_SLASH  */
    LEFT_PARANTHESIS = 260,        /* LEFT_PARANTHESIS  */
    RIGHT_PARANTHESIS = 261,       /* RIGHT_PARANTHESIS  */
    LEFT_BRACKET = 262,            /* LEFT_BRACKET  */
    RIGHT_BRACKET = 263,           /* RIGHT_BRACKET  */
    LEFT_SQUARE_BRACKET = 264,     /* LEFT_SQUARE_BRACKET  */
    RIGHT_SQUARE_BRACKET = 265,    /* RIGHT_SQUARE_BRACKET  */
    QUESTION_MARK = 266,           /* QUESTION_MARK  */
    EXCLAMATION_MARK = 267,        /* EXCLAMATION_MARK  */
    ARROW = 268,                   /* ARROW  */
    STAR = 269,                    /* STAR  */
    PLUS = 270,                    /* PLUS  */
    MINUS = 271,                   /* MINUS  */
    VALUE = 272,                   /* VALUE  */
    NUMBER = 273,                  /* NUMBER  */
    SINGLE_LINE_COMMENT = 274,     /* SINGLE_LINE_COMMENT  */
    MULTI_LINE_COMMENT = 275,      /* MULTI_LINE_COMMENT  */
    SYMBOLS = 276,                 /* SYMBOLS  */
    ESCAPE_CHARS = 277             /* ESCAPE_CHARS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 100 "./DLDL_GRAMMAR_PRODUCTION_RULE_parser.y"

	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ENDING_USELESS_SYMBOLS* DLDL_GRAMMAR_PRODUCTION_RULE_ENDING_USELESS_SYMBOLS;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VERTICAL_SLASH* DLDL_GRAMMAR_PRODUCTION_RULE_VERTICAL_SLASH;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_PARANTHESIS* DLDL_GRAMMAR_PRODUCTION_RULE_LEFT_PARANTHESIS;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_PARANTHESIS* DLDL_GRAMMAR_PRODUCTION_RULE_RIGHT_PARANTHESIS;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_BRACKET* DLDL_GRAMMAR_PRODUCTION_RULE_LEFT_BRACKET;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_BRACKET* DLDL_GRAMMAR_PRODUCTION_RULE_RIGHT_BRACKET;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_SQUARE_BRACKET* DLDL_GRAMMAR_PRODUCTION_RULE_LEFT_SQUARE_BRACKET;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_SQUARE_BRACKET* DLDL_GRAMMAR_PRODUCTION_RULE_RIGHT_SQUARE_BRACKET;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::QUESTION_MARK* DLDL_GRAMMAR_PRODUCTION_RULE_QUESTION_MARK;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::EXCLAMATION_MARK* DLDL_GRAMMAR_PRODUCTION_RULE_EXCLAMATION_MARK;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ARROW* DLDL_GRAMMAR_PRODUCTION_RULE_ARROW;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR* DLDL_GRAMMAR_PRODUCTION_RULE_STAR;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS* DLDL_GRAMMAR_PRODUCTION_RULE_PLUS;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MINUS* DLDL_GRAMMAR_PRODUCTION_RULE_MINUS;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VALUE* DLDL_GRAMMAR_PRODUCTION_RULE_VALUE;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER* DLDL_GRAMMAR_PRODUCTION_RULE_NUMBER;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SINGLE_LINE_COMMENT* DLDL_GRAMMAR_PRODUCTION_RULE_SINGLE_LINE_COMMENT;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MULTI_LINE_COMMENT* DLDL_GRAMMAR_PRODUCTION_RULE_MULTI_LINE_COMMENT;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SYMBOLS* DLDL_GRAMMAR_PRODUCTION_RULE_SYMBOLS;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ESCAPE_CHARS* DLDL_GRAMMAR_PRODUCTION_RULE_ESCAPE_CHARS;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::program* DLDL_GRAMMAR_PRODUCTION_RULE_program;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts* DLDL_GRAMMAR_PRODUCTION_RULE_stmts;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt* DLDL_GRAMMAR_PRODUCTION_RULE_stmt;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group* DLDL_GRAMMAR_PRODUCTION_RULE_group;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group* DLDL_GRAMMAR_PRODUCTION_RULE_nested_group;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group* DLDL_GRAMMAR_PRODUCTION_RULE_optional_group;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group* DLDL_GRAMMAR_PRODUCTION_RULE_zero_or_more_group;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group* DLDL_GRAMMAR_PRODUCTION_RULE_one_or_more_group;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group* DLDL_GRAMMAR_PRODUCTION_RULE_or_group;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group* DLDL_GRAMMAR_PRODUCTION_RULE_min_max_group;
	::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group* DLDL_GRAMMAR_PRODUCTION_RULE_extension_group;


#line 122 "DLDL_GRAMMAR_PRODUCTION_RULE_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE DLDL_GRAMMAR_PRODUCTION_RULElval;


int DLDL_GRAMMAR_PRODUCTION_RULEparse (void);


#endif /* !YY_DLDL_GRAMMAR_PRODUCTION_RULE_DLDL_GRAMMAR_PRODUCTION_RULE_PARSER_TAB_H_INCLUDED  */
