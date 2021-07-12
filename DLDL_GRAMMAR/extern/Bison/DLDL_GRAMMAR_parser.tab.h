/* A Bison parser, made by GNU Bison 3.7.5.  */

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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_DLDL_GRAMMAR_DLDL_GRAMMAR_PARSER_TAB_H_INCLUDED
# define YY_DLDL_GRAMMAR_DLDL_GRAMMAR_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int DLDL_GRAMMARdebug;
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
    START_ABSTRACTION = 258,       /* START_ABSTRACTION  */
    GROUP_ABSTRACTION = 259,       /* GROUP_ABSTRACTION  */
    INLINE_ABSTRACTION = 260,      /* INLINE_ABSTRACTION  */
    INLINE_GROUP_ABSTRACTION = 261, /* INLINE_GROUP_ABSTRACTION  */
    UNKNOWN_ABSTRACTION = 262,     /* UNKNOWN_ABSTRACTION  */
    NONTERMINAL = 263,             /* NONTERMINAL  */
    PRODUCTION_RULE = 264          /* PRODUCTION_RULE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 63 "./DLDL_GRAMMAR_parser.y"

	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::DLDL_GRAMMAR::ast::node::COMMENT* DLDL_GRAMMAR_COMMENT;
	::DLDL_GRAMMAR::ast::node::MULTI_LINE_COMMENT* DLDL_GRAMMAR_MULTI_LINE_COMMENT;
	::DLDL_GRAMMAR::ast::node::START_ABSTRACTION* DLDL_GRAMMAR_START_ABSTRACTION;
	::DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION* DLDL_GRAMMAR_GROUP_ABSTRACTION;
	::DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION* DLDL_GRAMMAR_INLINE_ABSTRACTION;
	::DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION* DLDL_GRAMMAR_INLINE_GROUP_ABSTRACTION;
	::DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION* DLDL_GRAMMAR_UNKNOWN_ABSTRACTION;
	::DLDL_GRAMMAR::ast::node::NONTERMINAL* DLDL_GRAMMAR_NONTERMINAL;
	::DLDL_GRAMMAR::ast::node::PRODUCTION_RULE* DLDL_GRAMMAR_PRODUCTION_RULE;
	::DLDL_GRAMMAR::ast::node::ESCAPE_CHARS* DLDL_GRAMMAR_ESCAPE_CHARS;
	::DLDL_GRAMMAR::ast::node::program* DLDL_GRAMMAR_program;
	::DLDL_GRAMMAR::ast::node::stmts* DLDL_GRAMMAR_stmts;
	::DLDL_GRAMMAR::ast::node::stmt* DLDL_GRAMMAR_stmt;
	::DLDL_GRAMMAR::ast::node::abstraction_declaration* DLDL_GRAMMAR_abstraction_declaration;
	::DLDL_GRAMMAR::ast::node::abstraction* DLDL_GRAMMAR_abstraction;
	::DLDL_GRAMMAR::ast::node::definition* DLDL_GRAMMAR_definition;
	::DLDL_GRAMMAR::ast::node::production_rules* DLDL_GRAMMAR_production_rules;

#line 94 "DLDL_GRAMMAR_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE DLDL_GRAMMARlval;

int DLDL_GRAMMARparse (void);

#endif /* !YY_DLDL_GRAMMAR_DLDL_GRAMMAR_PARSER_TAB_H_INCLUDED  */
