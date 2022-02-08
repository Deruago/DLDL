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

#ifndef YY_DLDL_LPDDEF_DF_DLDL_LPDDEF_DF_PARSER_TAB_H_INCLUDED
# define YY_DLDL_LPDDEF_DF_DLDL_LPDDEF_DF_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int DLDL_LPDDEF_DFdebug;
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
    LAB = 258,                     /* LAB  */
    RAB = 259,                     /* RAB  */
    LSB = 260,                     /* LSB  */
    RSB = 261,                     /* RSB  */
    EQ = 262,                      /* EQ  */
    COLON = 263,                   /* COLON  */
    LB = 264,                      /* LB  */
    RB = 265,                      /* RB  */
    COMMA = 266,                   /* COMMA  */
    OPTIONAL = 267,                /* OPTIONAL  */
    VECTOR = 268,                  /* VECTOR  */
    DEAMER_VARNAME = 269,          /* DEAMER_VARNAME  */
    COMMENT = 270,                 /* COMMENT  */
    VARNAME = 271,                 /* VARNAME  */
    NUMBER = 272,                  /* NUMBER  */
    STRING = 273                   /* STRING  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 98 "./DLDL_LPDDEF_DF_parser.y"

	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_LPDDEF_DF::ast::node::LAB* DLDL_LPDDEF_DF_LAB;
	::DLDL_LPDDEF_DF::ast::node::RAB* DLDL_LPDDEF_DF_RAB;
	::DLDL_LPDDEF_DF::ast::node::LSB* DLDL_LPDDEF_DF_LSB;
	::DLDL_LPDDEF_DF::ast::node::RSB* DLDL_LPDDEF_DF_RSB;
	::DLDL_LPDDEF_DF::ast::node::EQ* DLDL_LPDDEF_DF_EQ;
	::DLDL_LPDDEF_DF::ast::node::COLON* DLDL_LPDDEF_DF_COLON;
	::DLDL_LPDDEF_DF::ast::node::LB* DLDL_LPDDEF_DF_LB;
	::DLDL_LPDDEF_DF::ast::node::RB* DLDL_LPDDEF_DF_RB;
	::DLDL_LPDDEF_DF::ast::node::COMMA* DLDL_LPDDEF_DF_COMMA;
	::DLDL_LPDDEF_DF::ast::node::OPTIONAL* DLDL_LPDDEF_DF_OPTIONAL;
	::DLDL_LPDDEF_DF::ast::node::VECTOR* DLDL_LPDDEF_DF_VECTOR;
	::DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME* DLDL_LPDDEF_DF_DEAMER_VARNAME;
	::DLDL_LPDDEF_DF::ast::node::COMMENT* DLDL_LPDDEF_DF_COMMENT;
	::DLDL_LPDDEF_DF::ast::node::VARNAME* DLDL_LPDDEF_DF_VARNAME;
	::DLDL_LPDDEF_DF::ast::node::NUMBER* DLDL_LPDDEF_DF_NUMBER;
	::DLDL_LPDDEF_DF::ast::node::STRING* DLDL_LPDDEF_DF_STRING;
	::DLDL_LPDDEF_DF::ast::node::SEMICOLON* DLDL_LPDDEF_DF_SEMICOLON;
	::DLDL_LPDDEF_DF::ast::node::ESCAPE_CHARS* DLDL_LPDDEF_DF_ESCAPE_CHARS;
	::DLDL_LPDDEF_DF::ast::node::program* DLDL_LPDDEF_DF_program;
	::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__* DLDL_LPDDEF_DF_deamerreserved_star__stmt__;
	::DLDL_LPDDEF_DF::ast::node::stmt* DLDL_LPDDEF_DF_stmt;
	::DLDL_LPDDEF_DF::ast::node::comment_line* DLDL_LPDDEF_DF_comment_line;
	::DLDL_LPDDEF_DF::ast::node::vector_variant* DLDL_LPDDEF_DF_vector_variant;
	::DLDL_LPDDEF_DF::ast::node::optional_variant* DLDL_LPDDEF_DF_optional_variant;
	::DLDL_LPDDEF_DF::ast::node::value_part* DLDL_LPDDEF_DF_value_part;
	::DLDL_LPDDEF_DF::ast::node::standard_variant* DLDL_LPDDEF_DF_standard_variant;
	::DLDL_LPDDEF_DF::ast::node::value* DLDL_LPDDEF_DF_value;
	::DLDL_LPDDEF_DF::ast::node::value_type* DLDL_LPDDEF_DF_value_type;
	::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__* DLDL_LPDDEF_DF_deamerreserved_arrow__value_type__;
	::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__* DLDL_LPDDEF_DF_deamerreserved_star__COMMA__value_type__;
	::DLDL_LPDDEF_DF::ast::node::var_type* DLDL_LPDDEF_DF_var_type;
	::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__* DLDL_LPDDEF_DF_deamerreserved_arrow__VARNAME__;
	::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__* DLDL_LPDDEF_DF_deamerreserved_star__COLON__VARNAME__;
	::DLDL_LPDDEF_DF::ast::node::var_name* DLDL_LPDDEF_DF_var_name;

#line 120 "DLDL_LPDDEF_DF_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE DLDL_LPDDEF_DFlval;


int DLDL_LPDDEF_DFparse (void);


#endif /* !YY_DLDL_LPDDEF_DF_DLDL_LPDDEF_DF_PARSER_TAB_H_INCLUDED  */
