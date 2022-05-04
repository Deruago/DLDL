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

#ifndef YY_DLDL_OOPSYNTAX_DLDL_OOPSYNTAX_PARSER_TAB_H_INCLUDED
# define YY_DLDL_OOPSYNTAX_DLDL_OOPSYNTAX_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int DLDL_OOPSYNTAXdebug;
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
    ARROW = 258,                   /* ARROW  */
    LEFT_BRACKET = 259,            /* LEFT_BRACKET  */
    RIGHT_BRACKET = 260,           /* RIGHT_BRACKET  */
    DOT = 261,                     /* DOT  */
    EQ = 262,                      /* EQ  */
    STAR = 263,                    /* STAR  */
    VARNAME = 264,                 /* VARNAME  */
    NUMBER = 265,                  /* NUMBER  */
    COMMENT = 266,                 /* COMMENT  */
    ESCAPE_CHAR = 267              /* ESCAPE_CHAR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 90 "./DLDL_OOPSYNTAX_parser.y"

	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_OOPSYNTAX::ast::node::ARROW* DLDL_OOPSYNTAX_ARROW;
	::DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET* DLDL_OOPSYNTAX_LEFT_BRACKET;
	::DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET* DLDL_OOPSYNTAX_RIGHT_BRACKET;
	::DLDL_OOPSYNTAX::ast::node::DOT* DLDL_OOPSYNTAX_DOT;
	::DLDL_OOPSYNTAX::ast::node::EQ* DLDL_OOPSYNTAX_EQ;
	::DLDL_OOPSYNTAX::ast::node::STAR* DLDL_OOPSYNTAX_STAR;
	::DLDL_OOPSYNTAX::ast::node::VARNAME* DLDL_OOPSYNTAX_VARNAME;
	::DLDL_OOPSYNTAX::ast::node::NUMBER* DLDL_OOPSYNTAX_NUMBER;
	::DLDL_OOPSYNTAX::ast::node::COMMENT* DLDL_OOPSYNTAX_COMMENT;
	::DLDL_OOPSYNTAX::ast::node::ESCAPE_CHAR* DLDL_OOPSYNTAX_ESCAPE_CHAR;
	::DLDL_OOPSYNTAX::ast::node::program* DLDL_OOPSYNTAX_program;
	::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__* DLDL_OOPSYNTAX_deamerreserved_star__stmt__;
	::DLDL_OOPSYNTAX::ast::node::stmt* DLDL_OOPSYNTAX_stmt;
	::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion* DLDL_OOPSYNTAX_nonterminal_conversion;
	::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__production_rule_conversion__* DLDL_OOPSYNTAX_deamerreserved_star__production_rule_conversion__;
	::DLDL_OOPSYNTAX::ast::node::production_rule_conversion* DLDL_OOPSYNTAX_production_rule_conversion;
	::DLDL_OOPSYNTAX::ast::node::numbered_pr_convert* DLDL_OOPSYNTAX_numbered_pr_convert;
	::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__property_assignment__* DLDL_OOPSYNTAX_deamerreserved_star__property_assignment__;
	::DLDL_OOPSYNTAX::ast::node::property_assignment* DLDL_OOPSYNTAX_property_assignment;
	::DLDL_OOPSYNTAX::ast::node::direct_property_assignment* DLDL_OOPSYNTAX_direct_property_assignment;
	::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment* DLDL_OOPSYNTAX_direct_any_property_assignment;
	::DLDL_OOPSYNTAX::ast::node::embedded_assignment* DLDL_OOPSYNTAX_embedded_assignment;
	::DLDL_OOPSYNTAX::ast::node::nonterminal_name* DLDL_OOPSYNTAX_nonterminal_name;
	::DLDL_OOPSYNTAX::ast::node::oop_type* DLDL_OOPSYNTAX_oop_type;
	::DLDL_OOPSYNTAX::ast::node::property* DLDL_OOPSYNTAX_property;
	::DLDL_OOPSYNTAX::ast::node::terminal_name* DLDL_OOPSYNTAX_terminal_name;


#line 107 "DLDL_OOPSYNTAX_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE DLDL_OOPSYNTAXlval;


int DLDL_OOPSYNTAXparse (void);


#endif /* !YY_DLDL_OOPSYNTAX_DLDL_OOPSYNTAX_PARSER_TAB_H_INCLUDED  */
