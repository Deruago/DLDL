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

#ifndef YY_DLDL_VALUE_DLDL_VALUE_PARSER_TAB_H_INCLUDED
# define YY_DLDL_VALUE_DLDL_VALUE_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int DLDL_VALUEdebug;
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
    LEFT_PARANTHESIS = 260,        /* LEFT_PARANTHESIS  */
    RIGHT_PARANTHESIS = 261,       /* RIGHT_PARANTHESIS  */
    LEFT_BRACKET = 262,            /* LEFT_BRACKET  */
    RIGHT_BRACKET = 263,           /* RIGHT_BRACKET  */
    LEFT_SQUARE_BRACKET = 264,     /* LEFT_SQUARE_BRACKET  */
    RIGHT_SQUARE_BRACKET = 265,    /* RIGHT_SQUARE_BRACKET  */
    DOT = 266,                     /* DOT  */
    VALUE_CHARACTERISTIC = 267,    /* VALUE_CHARACTERISTIC  */
    VALUE_RULE = 268,              /* VALUE_RULE  */
    NUMBER = 269,                  /* NUMBER  */
    TEXT = 270,                    /* TEXT  */
    VARNAME = 271,                 /* VARNAME  */
    ESCAPE_CHARS = 272             /* ESCAPE_CHARS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 112 "./DLDL_VALUE_parser.y"

	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_VALUE::ast::node::SINGLE_COMMENT* DLDL_VALUE_SINGLE_COMMENT;
	::DLDL_VALUE::ast::node::MULTI_COMMENT* DLDL_VALUE_MULTI_COMMENT;
	::DLDL_VALUE::ast::node::LEFT_PARANTHESIS* DLDL_VALUE_LEFT_PARANTHESIS;
	::DLDL_VALUE::ast::node::RIGHT_PARANTHESIS* DLDL_VALUE_RIGHT_PARANTHESIS;
	::DLDL_VALUE::ast::node::LEFT_BRACKET* DLDL_VALUE_LEFT_BRACKET;
	::DLDL_VALUE::ast::node::RIGHT_BRACKET* DLDL_VALUE_RIGHT_BRACKET;
	::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET* DLDL_VALUE_LEFT_SQUARE_BRACKET;
	::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET* DLDL_VALUE_RIGHT_SQUARE_BRACKET;
	::DLDL_VALUE::ast::node::DOT* DLDL_VALUE_DOT;
	::DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC* DLDL_VALUE_VALUE_CHARACTERISTIC;
	::DLDL_VALUE::ast::node::VALUE_RULE* DLDL_VALUE_VALUE_RULE;
	::DLDL_VALUE::ast::node::NUMBER* DLDL_VALUE_NUMBER;
	::DLDL_VALUE::ast::node::TEXT* DLDL_VALUE_TEXT;
	::DLDL_VALUE::ast::node::VARNAME* DLDL_VALUE_VARNAME;
	::DLDL_VALUE::ast::node::ESCAPE_CHARS* DLDL_VALUE_ESCAPE_CHARS;
	::DLDL_VALUE::ast::node::program* DLDL_VALUE_program;
	::DLDL_VALUE::ast::node::deamerreserved_star__stmt__* DLDL_VALUE_deamerreserved_star__stmt__;
	::DLDL_VALUE::ast::node::stmt* DLDL_VALUE_stmt;
	::DLDL_VALUE::ast::node::value_charactersitic_declaration* DLDL_VALUE_value_charactersitic_declaration;
	::DLDL_VALUE::ast::node::deamerreserved_long_82* DLDL_VALUE_deamerreserved_long_82;
	::DLDL_VALUE::ast::node::deamerreserved_long_85* DLDL_VALUE_deamerreserved_long_85;
	::DLDL_VALUE::ast::node::deamerreserved_long_88* DLDL_VALUE_deamerreserved_long_88;
	::DLDL_VALUE::ast::node::value_declaration* DLDL_VALUE_value_declaration;
	::DLDL_VALUE::ast::node::deamerreserved_long_91* DLDL_VALUE_deamerreserved_long_91;
	::DLDL_VALUE::ast::node::value_characteristic_abstraction* DLDL_VALUE_value_characteristic_abstraction;
	::DLDL_VALUE::ast::node::value_declaration_abstraction* DLDL_VALUE_value_declaration_abstraction;
	::DLDL_VALUE::ast::node::value_abstraction* DLDL_VALUE_value_abstraction;
	::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__* DLDL_VALUE_deamerreserved_star__value_abstraction__;
	::DLDL_VALUE::ast::node::deamerreserved_long_96* DLDL_VALUE_deamerreserved_long_96;
	::DLDL_VALUE::ast::node::value* DLDL_VALUE_value;
	::DLDL_VALUE::ast::node::syntactic_context* DLDL_VALUE_syntactic_context;
	::DLDL_VALUE::ast::node::abstraction_name* DLDL_VALUE_abstraction_name;
	::DLDL_VALUE::ast::node::value_rule_name* DLDL_VALUE_value_rule_name;


#line 114 "DLDL_VALUE_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE DLDL_VALUElval;

int DLDL_VALUEparse (void);

#endif /* !YY_DLDL_VALUE_DLDL_VALUE_PARSER_TAB_H_INCLUDED  */
