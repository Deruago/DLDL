/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         DLDL_LPDDEF_DFparse
#define yylex           DLDL_LPDDEF_DFlex
#define yyerror         DLDL_LPDDEF_DFerror
#define yydebug         DLDL_LPDDEF_DFdebug
#define yynerrs         DLDL_LPDDEF_DFnerrs
#define yylval          DLDL_LPDDEF_DFlval
#define yychar          DLDL_LPDDEF_DFchar

/* First part of user prologue.  */
#line 5 "./DLDL_LPDDEF_DF_parser.y"

#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <Deamer/External/Cpp/Lexer/TerminalObject.h>
#include <Deamer/External/Cpp/Ast/Node.h>
#include "DLDL_LPDDEF_DF/Bison/Parser.h"
#define YY_NO_UNISTD_H
#include "Flex/DLDL_LPDDEF_DF_lexer.h"
#undef YY_NO_UNISTD_H
#include "DLDL_LPDDEF_DF/Ast/Enum/Type.h"
#include "DLDL_LPDDEF_DF/Ast/Node/LAB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/RAB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/LSB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/RSB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/EQ.h"
#include "DLDL_LPDDEF_DF/Ast/Node/COLON.h"
#include "DLDL_LPDDEF_DF/Ast/Node/LB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/RB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/COMMA.h"
#include "DLDL_LPDDEF_DF/Ast/Node/OPTIONAL.h"
#include "DLDL_LPDDEF_DF/Ast/Node/VECTOR.h"
#include "DLDL_LPDDEF_DF/Ast/Node/DEAMER_VARNAME.h"
#include "DLDL_LPDDEF_DF/Ast/Node/COMMENT.h"
#include "DLDL_LPDDEF_DF/Ast/Node/VARNAME.h"
#include "DLDL_LPDDEF_DF/Ast/Node/NUMBER.h"
#include "DLDL_LPDDEF_DF/Ast/Node/STRING.h"
#include "DLDL_LPDDEF_DF/Ast/Node/SEMICOLON.h"
#include "DLDL_LPDDEF_DF/Ast/Node/ESCAPE_CHARS.h"


#include "DLDL_LPDDEF_DF/Ast/Node/program.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/stmt.h"
#include "DLDL_LPDDEF_DF/Ast/Node/comment_line.h"
#include "DLDL_LPDDEF_DF/Ast/Node/vector_variant.h"
#include "DLDL_LPDDEF_DF/Ast/Node/optional_variant.h"
#include "DLDL_LPDDEF_DF/Ast/Node/value_part.h"
#include "DLDL_LPDDEF_DF/Ast/Node/standard_variant.h"
#include "DLDL_LPDDEF_DF/Ast/Node/value.h"
#include "DLDL_LPDDEF_DF/Ast/Node/value_type.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_arrow__value_type__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_star__COMMA__value_type__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/var_type.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_arrow__VARNAME__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_star__COLON__VARNAME__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/var_name.h"


#ifndef YY_parse_NERRS
#define YY_parse_NERRS DLDL_LPDDEF_DFnerrs
#endif //YY_parse_NERRS
#ifndef YY_parse_LLOC
#define YY_parse_LLOC DLDL_LPDDEF_DFlloc
#endif //YY_parse_LLOC
#define YYERROR_VERBOSE

void DLDL_LPDDEF_DFerror(const char* s);
int DLDL_LPDDEF_DFlex();
static ::deamer::external::cpp::ast::Tree* outputTree = nullptr;

#line 141 "DLDL_LPDDEF_DF_parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "DLDL_LPDDEF_DF_parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LAB = 3,                        /* LAB  */
  YYSYMBOL_RAB = 4,                        /* RAB  */
  YYSYMBOL_LSB = 5,                        /* LSB  */
  YYSYMBOL_RSB = 6,                        /* RSB  */
  YYSYMBOL_EQ = 7,                         /* EQ  */
  YYSYMBOL_COLON = 8,                      /* COLON  */
  YYSYMBOL_LB = 9,                         /* LB  */
  YYSYMBOL_RB = 10,                        /* RB  */
  YYSYMBOL_COMMA = 11,                     /* COMMA  */
  YYSYMBOL_OPTIONAL = 12,                  /* OPTIONAL  */
  YYSYMBOL_VECTOR = 13,                    /* VECTOR  */
  YYSYMBOL_DEAMER_VARNAME = 14,            /* DEAMER_VARNAME  */
  YYSYMBOL_COMMENT = 15,                   /* COMMENT  */
  YYSYMBOL_VARNAME = 16,                   /* VARNAME  */
  YYSYMBOL_NUMBER = 17,                    /* NUMBER  */
  YYSYMBOL_STRING = 18,                    /* STRING  */
  YYSYMBOL_SEMICOLON = 19,                 /* SEMICOLON  */
  YYSYMBOL_ESCAPE_CHARS = 20,              /* ESCAPE_CHARS  */
  YYSYMBOL_YYACCEPT = 21,                  /* $accept  */
  YYSYMBOL_program = 22,                   /* program  */
  YYSYMBOL_deamerreserved_star__stmt__ = 23, /* deamerreserved_star__stmt__  */
  YYSYMBOL_stmt = 24,                      /* stmt  */
  YYSYMBOL_comment_line = 25,              /* comment_line  */
  YYSYMBOL_vector_variant = 26,            /* vector_variant  */
  YYSYMBOL_optional_variant = 27,          /* optional_variant  */
  YYSYMBOL_value_part = 28,                /* value_part  */
  YYSYMBOL_standard_variant = 29,          /* standard_variant  */
  YYSYMBOL_value = 30,                     /* value  */
  YYSYMBOL_value_type = 31,                /* value_type  */
  YYSYMBOL_deamerreserved_arrow__value_type__ = 32, /* deamerreserved_arrow__value_type__  */
  YYSYMBOL_deamerreserved_star__COMMA__value_type__ = 33, /* deamerreserved_star__COMMA__value_type__  */
  YYSYMBOL_var_type = 34,                  /* var_type  */
  YYSYMBOL_deamerreserved_arrow__VARNAME__ = 35, /* deamerreserved_arrow__VARNAME__  */
  YYSYMBOL_deamerreserved_star__COLON__VARNAME__ = 36, /* deamerreserved_star__COLON__VARNAME__  */
  YYSYMBOL_var_name = 37                   /* var_name  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
# define YYCOPY_NEEDED 1
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   52

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  21
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  37
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  63

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   275


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   149,   149,   160,   166,   176,   182,   188,   194,   204,
     214,   222,   230,   238,   250,   258,   266,   274,   286,   297,
     303,   313,   323,   329,   335,   341,   347,   353,   359,   369,
     379,   385,   395,   401,   411,   421,   427,   437
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "LAB", "RAB", "LSB",
  "RSB", "EQ", "COLON", "LB", "RB", "COMMA", "OPTIONAL", "VECTOR",
  "DEAMER_VARNAME", "COMMENT", "VARNAME", "NUMBER", "STRING", "SEMICOLON",
  "ESCAPE_CHARS", "$accept", "program", "deamerreserved_star__stmt__",
  "stmt", "comment_line", "vector_variant", "optional_variant",
  "value_part", "standard_variant", "value", "value_type",
  "deamerreserved_arrow__value_type__",
  "deamerreserved_star__COMMA__value_type__", "var_type",
  "deamerreserved_arrow__VARNAME__",
  "deamerreserved_star__COLON__VARNAME__", "var_name", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-38)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       8,     0,    34,   -38,   -38,    -4,    17,   -38,     8,   -38,
     -38,   -38,   -38,     2,   -38,    -3,    -3,    -3,    -3,    22,
     -38,   -38,   -38,   -38,    33,    37,    36,    39,    38,    -4,
      -2,   -38,     2,     2,     2,     2,   -38,    -8,   -38,    40,
     -38,   -38,   -38,   -38,    33,    33,    33,    33,   -38,    35,
      41,    42,   -38,   -38,   -38,   -38,    -2,   -38,   -38,    29,
      35,   -38,   -38
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,    32,     9,    36,     0,     2,     4,     5,
       6,     7,     8,     0,    33,     0,     0,     0,     0,     0,
      34,     1,     3,    37,    20,     0,     0,     0,     0,    36,
       0,    19,     0,     0,     0,     0,    35,     0,    24,    22,
      25,    26,    18,    21,    15,    17,    11,    13,    28,    31,
       0,     0,    14,    16,    10,    12,     0,    29,    27,     0,
      31,    23,    30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -38,   -38,    44,   -38,   -38,   -38,   -38,   -19,   -38,   -38,
     -37,   -38,   -13,    14,   -38,    20,     1
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     6,     7,     8,     9,    10,    11,    31,    12,    42,
      43,    50,    57,    13,    14,    20,    24
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      49,    37,    48,    15,    19,    16,    38,    37,    39,    40,
      41,     3,    38,     5,    39,    40,    41,    21,    23,    60,
       1,     2,     3,     4,     5,    52,    53,    54,    55,    25,
      26,    27,    28,    44,    45,    46,    47,    17,    29,    18,
      30,    32,    33,    34,    35,    61,    56,    62,    51,    36,
      59,    58,    22
};

static const yytype_int8 yycheck[] =
{
      37,     9,    10,     3,     8,     5,    14,     9,    16,    17,
      18,    14,    14,    16,    16,    17,    18,     0,    16,    56,
      12,    13,    14,    15,    16,    44,    45,    46,    47,    15,
      16,    17,    18,    32,    33,    34,    35,     3,    16,     5,
       7,     4,     6,     4,     6,    16,    11,    60,     8,    29,
       8,    10,     8
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    13,    14,    15,    16,    22,    23,    24,    25,
      26,    27,    29,    34,    35,     3,     5,     3,     5,     8,
      36,     0,    23,    16,    37,    34,    34,    34,    34,    16,
       7,    28,     4,     6,     4,     6,    36,     9,    14,    16,
      17,    18,    30,    31,    37,    37,    37,    37,    10,    31,
      32,     8,    28,    28,    28,    28,    11,    33,    10,     8,
      31,    16,    33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    21,    22,    23,    23,    24,    24,    24,    24,    25,
      26,    26,    26,    26,    27,    27,    27,    27,    28,    29,
      29,    30,    31,    31,    31,    31,    31,    31,    31,    32,
      33,    33,    34,    34,    35,    36,    36,    37
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       6,     5,     6,     5,     6,     5,     6,     5,     2,     3,
       2,     1,     1,     4,     1,     1,     1,     3,     2,     2,
       3,     0,     1,     1,     2,     3,     0,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        YY_LAC_DISCARD ("YYBACKUP");                              \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return YYENOMEM if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yy_state_t **yybottom,
                      yy_state_t *yybottom_no_free,
                      yy_state_t **yytop, yy_state_t *yytop_empty)
{
  YYPTRDIFF_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYPTRDIFF_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYPTRDIFF_T yyalloc = 2 * yysize_new;
      yy_state_t *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        YY_CAST (yy_state_t *,
                 YYSTACK_ALLOC (YY_CAST (YYSIZE_T,
                                         yyalloc * YYSIZEOF (*yybottom_new))));
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                                \
do {                                                                    \
  if (!yy_lac_established)                                              \
    {                                                                   \
      YYDPRINTF ((stderr,                                               \
                  "LAC: initial context established for %s\n",          \
                  yysymbol_name (yytoken)));                            \
      yy_lac_established = 1;                                           \
      switch (yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken))    \
        {                                                               \
        case YYENOMEM:                                                  \
          YYNOMEM;                                                      \
        case 1:                                                         \
          goto yyerrlab;                                                \
        }                                                               \
    }                                                                   \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      YYDPRINTF ((stderr, "LAC: initial context discarded due to "       \
                  Event "\n"));                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return YYENOMEM if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, yysymbol_kind_t yytoken)
{
  yy_state_t *yyes_prev = yyssp;
  yy_state_t *yyesp = yyes_prev;
  /* Reduce until we encounter a shift and thereby accept the token.  */
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name (yytoken)));
  if (yytoken == YYSYMBOL_YYUNDEF)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[+*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          /* Use the default action.  */
          yyrule = yydefact[+*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          /* Use the action from yytable.  */
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      /* By now we know we have to simulate a reduce.  */
      YYDPRINTF ((stderr, " R%d", yyrule - 1));
      {
        /* Pop the corresponding number of values from the stack.  */
        YYPTRDIFF_T yylen = yyr2[yyrule];
        /* First pop from the LAC stack as many tokens as possible.  */
        if (yyesp != yyes_prev)
          {
            YYPTRDIFF_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yyesp = yyes_prev;
                yylen -= yysize;
              }
          }
        /* Only afterwards look at the main stack.  */
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      /* Push the resulting state of the reduction.  */
      {
        yy_state_fast_t yystate;
        {
          const int yylhs = yyr1[yyrule] - YYNTOKENS;
          const int yyi = yypgoto[yylhs] + *yyesp;
          yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
                     ? yytable[yyi]
                     : yydefgoto[yylhs]);
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            YY_IGNORE_USELESS_CAST_BEGIN
            *yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return YYENOMEM;
              }
            YY_IGNORE_USELESS_CAST_BEGIN
            *++yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}

/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yy_state_t *yyesa;
  yy_state_t **yyes;
  YYPTRDIFF_T *yyes_capacity;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;

  int yyx;
  for (yyx = 0; yyx < YYNTOKENS; ++yyx)
    {
      yysymbol_kind_t yysym = YY_CAST (yysymbol_kind_t, yyx);
      if (yysym != YYSYMBOL_YYerror && yysym != YYSYMBOL_YYUNDEF)
        switch (yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yysym))
          {
          case YYENOMEM:
            return YYENOMEM;
          case 1:
            continue;
          default:
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else if (yyn == 0)
        YYDPRINTF ((stderr, "No expected tokens.\n"));
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store or if
   yy_lac returned YYENOMEM.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    yy_state_t yyesa[20];
    yy_state_t *yyes = yyesa;
    YYPTRDIFF_T yyes_capacity = 20 < YYMAXDEPTH ? 20 : YYMAXDEPTH;

  /* Whether LAC context is established.  A Boolean.  */
  int yy_lac_established = 0;
  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      YY_LAC_ESTABLISH;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  YY_LAC_DISCARD ("shift");
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
  case 2: /* program: deamerreserved_star__stmt__  */
#line 149 "./DLDL_LPDDEF_DF_parser.y"
                                     {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::program({::DLDL_LPDDEF_DF::ast::Type::program, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].DLDL_LPDDEF_DF_deamerreserved_star__stmt__) });
		(yyval.DLDL_LPDDEF_DF_program) = newNode;

		// Ignored, Deleted, tokens are deleted
		outputTree = new ::deamer::external::cpp::ast::Tree(newNode);
	}
#line 1713 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 3: /* deamerreserved_star__stmt__: stmt deamerreserved_star__stmt__  */
#line 160 "./DLDL_LPDDEF_DF_parser.y"
                                          {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__({::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { (yyvsp[-1].DLDL_LPDDEF_DF_stmt), (yyvsp[0].DLDL_LPDDEF_DF_deamerreserved_star__stmt__) });
		(yyval.DLDL_LPDDEF_DF_deamerreserved_star__stmt__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1724 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 4: /* deamerreserved_star__stmt__: %empty  */
#line 166 "./DLDL_LPDDEF_DF_parser.y"
           {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__({::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		(yyval.DLDL_LPDDEF_DF_deamerreserved_star__stmt__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1735 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 5: /* stmt: comment_line  */
#line 176 "./DLDL_LPDDEF_DF_parser.y"
                      {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::stmt({::DLDL_LPDDEF_DF::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].DLDL_LPDDEF_DF_comment_line) });
		(yyval.DLDL_LPDDEF_DF_stmt) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1746 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 6: /* stmt: vector_variant  */
#line 182 "./DLDL_LPDDEF_DF_parser.y"
                          {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::stmt({::DLDL_LPDDEF_DF::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].DLDL_LPDDEF_DF_vector_variant) });
		(yyval.DLDL_LPDDEF_DF_stmt) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1757 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 7: /* stmt: optional_variant  */
#line 188 "./DLDL_LPDDEF_DF_parser.y"
                            {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::stmt({::DLDL_LPDDEF_DF::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].DLDL_LPDDEF_DF_optional_variant) });
		(yyval.DLDL_LPDDEF_DF_stmt) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1768 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 8: /* stmt: standard_variant  */
#line 194 "./DLDL_LPDDEF_DF_parser.y"
                            {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::stmt({::DLDL_LPDDEF_DF::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].DLDL_LPDDEF_DF_standard_variant) });
		(yyval.DLDL_LPDDEF_DF_stmt) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1779 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 9: /* comment_line: COMMENT  */
#line 204 "./DLDL_LPDDEF_DF_parser.y"
                 {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::comment_line({::DLDL_LPDDEF_DF::ast::Type::comment_line, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::COMMENT({::DLDL_LPDDEF_DF::ast::Type::COMMENT, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.DLDL_LPDDEF_DF_comment_line) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1790 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 10: /* vector_variant: VECTOR LAB var_type RAB var_name value_part  */
#line 214 "./DLDL_LPDDEF_DF_parser.y"
                                                     {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::vector_variant({::DLDL_LPDDEF_DF::ast::Type::vector_variant, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::VECTOR({::DLDL_LPDDEF_DF::ast::Type::VECTOR, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-5].Terminal) }), (yyvsp[-3].DLDL_LPDDEF_DF_var_type), (yyvsp[-1].DLDL_LPDDEF_DF_var_name), (yyvsp[0].DLDL_LPDDEF_DF_value_part) });
		(yyval.DLDL_LPDDEF_DF_vector_variant) = newNode;

		// Ignored, Deleted, tokens are deleted
		delete (yyvsp[-4].Terminal);
		delete (yyvsp[-2].Terminal);
	}
#line 1803 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 11: /* vector_variant: VECTOR LAB var_type RAB var_name  */
#line 222 "./DLDL_LPDDEF_DF_parser.y"
                                            {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::vector_variant({::DLDL_LPDDEF_DF::ast::Type::vector_variant, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::VECTOR({::DLDL_LPDDEF_DF::ast::Type::VECTOR, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-4].Terminal) }), (yyvsp[-2].DLDL_LPDDEF_DF_var_type), (yyvsp[0].DLDL_LPDDEF_DF_var_name) });
		(yyval.DLDL_LPDDEF_DF_vector_variant) = newNode;

		// Ignored, Deleted, tokens are deleted
		delete (yyvsp[-3].Terminal);
		delete (yyvsp[-1].Terminal);
	}
#line 1816 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 12: /* vector_variant: VECTOR LSB var_type RSB var_name value_part  */
#line 230 "./DLDL_LPDDEF_DF_parser.y"
                                                       {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::vector_variant({::DLDL_LPDDEF_DF::ast::Type::vector_variant, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::VECTOR({::DLDL_LPDDEF_DF::ast::Type::VECTOR, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-5].Terminal) }), (yyvsp[-3].DLDL_LPDDEF_DF_var_type), (yyvsp[-1].DLDL_LPDDEF_DF_var_name), (yyvsp[0].DLDL_LPDDEF_DF_value_part) });
		(yyval.DLDL_LPDDEF_DF_vector_variant) = newNode;

		// Ignored, Deleted, tokens are deleted
		delete (yyvsp[-4].Terminal);
		delete (yyvsp[-2].Terminal);
	}
#line 1829 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 13: /* vector_variant: VECTOR LSB var_type RSB var_name  */
#line 238 "./DLDL_LPDDEF_DF_parser.y"
                                            {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::vector_variant({::DLDL_LPDDEF_DF::ast::Type::vector_variant, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::VECTOR({::DLDL_LPDDEF_DF::ast::Type::VECTOR, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-4].Terminal) }), (yyvsp[-2].DLDL_LPDDEF_DF_var_type), (yyvsp[0].DLDL_LPDDEF_DF_var_name) });
		(yyval.DLDL_LPDDEF_DF_vector_variant) = newNode;

		// Ignored, Deleted, tokens are deleted
		delete (yyvsp[-3].Terminal);
		delete (yyvsp[-1].Terminal);
	}
#line 1842 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 14: /* optional_variant: OPTIONAL LAB var_type RAB var_name value_part  */
#line 250 "./DLDL_LPDDEF_DF_parser.y"
                                                       {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::optional_variant({::DLDL_LPDDEF_DF::ast::Type::optional_variant, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::OPTIONAL({::DLDL_LPDDEF_DF::ast::Type::OPTIONAL, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-5].Terminal) }), (yyvsp[-3].DLDL_LPDDEF_DF_var_type), (yyvsp[-1].DLDL_LPDDEF_DF_var_name), (yyvsp[0].DLDL_LPDDEF_DF_value_part) });
		(yyval.DLDL_LPDDEF_DF_optional_variant) = newNode;

		// Ignored, Deleted, tokens are deleted
		delete (yyvsp[-4].Terminal);
		delete (yyvsp[-2].Terminal);
	}
#line 1855 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 15: /* optional_variant: OPTIONAL LAB var_type RAB var_name  */
#line 258 "./DLDL_LPDDEF_DF_parser.y"
                                              {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::optional_variant({::DLDL_LPDDEF_DF::ast::Type::optional_variant, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::OPTIONAL({::DLDL_LPDDEF_DF::ast::Type::OPTIONAL, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-4].Terminal) }), (yyvsp[-2].DLDL_LPDDEF_DF_var_type), (yyvsp[0].DLDL_LPDDEF_DF_var_name) });
		(yyval.DLDL_LPDDEF_DF_optional_variant) = newNode;

		// Ignored, Deleted, tokens are deleted
		delete (yyvsp[-3].Terminal);
		delete (yyvsp[-1].Terminal);
	}
#line 1868 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 16: /* optional_variant: OPTIONAL LSB var_type RSB var_name value_part  */
#line 266 "./DLDL_LPDDEF_DF_parser.y"
                                                         {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::optional_variant({::DLDL_LPDDEF_DF::ast::Type::optional_variant, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::OPTIONAL({::DLDL_LPDDEF_DF::ast::Type::OPTIONAL, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-5].Terminal) }), (yyvsp[-3].DLDL_LPDDEF_DF_var_type), (yyvsp[-1].DLDL_LPDDEF_DF_var_name), (yyvsp[0].DLDL_LPDDEF_DF_value_part) });
		(yyval.DLDL_LPDDEF_DF_optional_variant) = newNode;

		// Ignored, Deleted, tokens are deleted
		delete (yyvsp[-4].Terminal);
		delete (yyvsp[-2].Terminal);
	}
#line 1881 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 17: /* optional_variant: OPTIONAL LSB var_type RSB var_name  */
#line 274 "./DLDL_LPDDEF_DF_parser.y"
                                              {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::optional_variant({::DLDL_LPDDEF_DF::ast::Type::optional_variant, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::OPTIONAL({::DLDL_LPDDEF_DF::ast::Type::OPTIONAL, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-4].Terminal) }), (yyvsp[-2].DLDL_LPDDEF_DF_var_type), (yyvsp[0].DLDL_LPDDEF_DF_var_name) });
		(yyval.DLDL_LPDDEF_DF_optional_variant) = newNode;

		// Ignored, Deleted, tokens are deleted
		delete (yyvsp[-3].Terminal);
		delete (yyvsp[-1].Terminal);
	}
#line 1894 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 18: /* value_part: EQ value  */
#line 286 "./DLDL_LPDDEF_DF_parser.y"
                  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::value_part({::DLDL_LPDDEF_DF::ast::Type::value_part, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].DLDL_LPDDEF_DF_value) });
		(yyval.DLDL_LPDDEF_DF_value_part) = newNode;

		// Ignored, Deleted, tokens are deleted
		delete (yyvsp[-1].Terminal);
	}
#line 1906 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 19: /* standard_variant: var_type var_name value_part  */
#line 297 "./DLDL_LPDDEF_DF_parser.y"
                                      {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::standard_variant({::DLDL_LPDDEF_DF::ast::Type::standard_variant, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-2].DLDL_LPDDEF_DF_var_type), (yyvsp[-1].DLDL_LPDDEF_DF_var_name), (yyvsp[0].DLDL_LPDDEF_DF_value_part) });
		(yyval.DLDL_LPDDEF_DF_standard_variant) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1917 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 20: /* standard_variant: var_type var_name  */
#line 303 "./DLDL_LPDDEF_DF_parser.y"
                             {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::standard_variant({::DLDL_LPDDEF_DF::ast::Type::standard_variant, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-1].DLDL_LPDDEF_DF_var_type), (yyvsp[0].DLDL_LPDDEF_DF_var_name) });
		(yyval.DLDL_LPDDEF_DF_standard_variant) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1928 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 21: /* value: value_type  */
#line 313 "./DLDL_LPDDEF_DF_parser.y"
                    {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::value({::DLDL_LPDDEF_DF::ast::Type::value, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].DLDL_LPDDEF_DF_value_type) });
		(yyval.DLDL_LPDDEF_DF_value) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1939 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 22: /* value_type: VARNAME  */
#line 323 "./DLDL_LPDDEF_DF_parser.y"
                 {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::value_type({::DLDL_LPDDEF_DF::ast::Type::value_type, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::VARNAME({::DLDL_LPDDEF_DF::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.DLDL_LPDDEF_DF_value_type) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1950 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 23: /* value_type: VARNAME COLON COLON VARNAME  */
#line 329 "./DLDL_LPDDEF_DF_parser.y"
                                       {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::value_type({::DLDL_LPDDEF_DF::ast::Type::value_type, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::VARNAME({::DLDL_LPDDEF_DF::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-3].Terminal) }), new DLDL_LPDDEF_DF::ast::node::COLON({::DLDL_LPDDEF_DF::ast::Type::COLON, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-2].Terminal) }), new DLDL_LPDDEF_DF::ast::node::COLON({::DLDL_LPDDEF_DF::ast::Type::COLON, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), new DLDL_LPDDEF_DF::ast::node::VARNAME({::DLDL_LPDDEF_DF::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.DLDL_LPDDEF_DF_value_type) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1961 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 24: /* value_type: DEAMER_VARNAME  */
#line 335 "./DLDL_LPDDEF_DF_parser.y"
                          {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::value_type({::DLDL_LPDDEF_DF::ast::Type::value_type, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME({::DLDL_LPDDEF_DF::ast::Type::DEAMER_VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.DLDL_LPDDEF_DF_value_type) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1972 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 25: /* value_type: NUMBER  */
#line 341 "./DLDL_LPDDEF_DF_parser.y"
                  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::value_type({::DLDL_LPDDEF_DF::ast::Type::value_type, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::NUMBER({::DLDL_LPDDEF_DF::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.DLDL_LPDDEF_DF_value_type) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1983 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 26: /* value_type: STRING  */
#line 347 "./DLDL_LPDDEF_DF_parser.y"
                  {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::value_type({::DLDL_LPDDEF_DF::ast::Type::value_type, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 4, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::STRING({::DLDL_LPDDEF_DF::ast::Type::STRING, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.DLDL_LPDDEF_DF_value_type) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1994 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 27: /* value_type: LB deamerreserved_arrow__value_type__ RB  */
#line 353 "./DLDL_LPDDEF_DF_parser.y"
                                                    {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::value_type({::DLDL_LPDDEF_DF::ast::Type::value_type, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 5, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::LB({::DLDL_LPDDEF_DF::ast::Type::LB, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-2].Terminal) }), (yyvsp[-1].DLDL_LPDDEF_DF_deamerreserved_arrow__value_type__), new DLDL_LPDDEF_DF::ast::node::RB({::DLDL_LPDDEF_DF::ast::Type::RB, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.DLDL_LPDDEF_DF_value_type) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2005 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 28: /* value_type: LB RB  */
#line 359 "./DLDL_LPDDEF_DF_parser.y"
                 {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::value_type({::DLDL_LPDDEF_DF::ast::Type::value_type, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 6, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::LB({::DLDL_LPDDEF_DF::ast::Type::LB, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), new DLDL_LPDDEF_DF::ast::node::RB({::DLDL_LPDDEF_DF::ast::Type::RB, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.DLDL_LPDDEF_DF_value_type) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2016 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 29: /* deamerreserved_arrow__value_type__: value_type deamerreserved_star__COMMA__value_type__  */
#line 369 "./DLDL_LPDDEF_DF_parser.y"
                                                             {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__({::DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__value_type__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { (yyvsp[-1].DLDL_LPDDEF_DF_value_type), (yyvsp[0].DLDL_LPDDEF_DF_deamerreserved_star__COMMA__value_type__) });
		(yyval.DLDL_LPDDEF_DF_deamerreserved_arrow__value_type__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2027 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 30: /* deamerreserved_star__COMMA__value_type__: COMMA value_type deamerreserved_star__COMMA__value_type__  */
#line 379 "./DLDL_LPDDEF_DF_parser.y"
                                                                   {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__({::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COMMA__value_type__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { new DLDL_LPDDEF_DF::ast::node::COMMA({::DLDL_LPDDEF_DF::ast::Type::COMMA, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-2].Terminal) }), (yyvsp[-1].DLDL_LPDDEF_DF_value_type), (yyvsp[0].DLDL_LPDDEF_DF_deamerreserved_star__COMMA__value_type__) });
		(yyval.DLDL_LPDDEF_DF_deamerreserved_star__COMMA__value_type__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2038 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 31: /* deamerreserved_star__COMMA__value_type__: %empty  */
#line 385 "./DLDL_LPDDEF_DF_parser.y"
           {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__({::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COMMA__value_type__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		(yyval.DLDL_LPDDEF_DF_deamerreserved_star__COMMA__value_type__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2049 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 32: /* var_type: DEAMER_VARNAME  */
#line 395 "./DLDL_LPDDEF_DF_parser.y"
                        {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::var_type({::DLDL_LPDDEF_DF::ast::Type::var_type, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME({::DLDL_LPDDEF_DF::ast::Type::DEAMER_VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.DLDL_LPDDEF_DF_var_type) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2060 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 33: /* var_type: deamerreserved_arrow__VARNAME__  */
#line 401 "./DLDL_LPDDEF_DF_parser.y"
                                           {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::var_type({::DLDL_LPDDEF_DF::ast::Type::var_type, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].DLDL_LPDDEF_DF_deamerreserved_arrow__VARNAME__) });
		(yyval.DLDL_LPDDEF_DF_var_type) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2071 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 34: /* deamerreserved_arrow__VARNAME__: VARNAME deamerreserved_star__COLON__VARNAME__  */
#line 411 "./DLDL_LPDDEF_DF_parser.y"
                                                       {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__({::DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__VARNAME__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { new DLDL_LPDDEF_DF::ast::node::VARNAME({::DLDL_LPDDEF_DF::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), (yyvsp[0].DLDL_LPDDEF_DF_deamerreserved_star__COLON__VARNAME__) });
		(yyval.DLDL_LPDDEF_DF_deamerreserved_arrow__VARNAME__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2082 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 35: /* deamerreserved_star__COLON__VARNAME__: COLON VARNAME deamerreserved_star__COLON__VARNAME__  */
#line 421 "./DLDL_LPDDEF_DF_parser.y"
                                                             {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__({::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COLON__VARNAME__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { new DLDL_LPDDEF_DF::ast::node::COLON({::DLDL_LPDDEF_DF::ast::Type::COLON, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-2].Terminal) }), new DLDL_LPDDEF_DF::ast::node::VARNAME({::DLDL_LPDDEF_DF::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), (yyvsp[0].DLDL_LPDDEF_DF_deamerreserved_star__COLON__VARNAME__) });
		(yyval.DLDL_LPDDEF_DF_deamerreserved_star__COLON__VARNAME__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2093 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 36: /* deamerreserved_star__COLON__VARNAME__: %empty  */
#line 427 "./DLDL_LPDDEF_DF_parser.y"
           {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__({::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COLON__VARNAME__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		(yyval.DLDL_LPDDEF_DF_deamerreserved_star__COLON__VARNAME__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2104 "DLDL_LPDDEF_DF_parser.tab.c"
    break;

  case 37: /* var_name: VARNAME  */
#line 437 "./DLDL_LPDDEF_DF_parser.y"
                 {
		auto* const newNode = new DLDL_LPDDEF_DF::ast::node::var_name({::DLDL_LPDDEF_DF::ast::Type::var_name, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new DLDL_LPDDEF_DF::ast::node::VARNAME({::DLDL_LPDDEF_DF::ast::Type::VARNAME, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.DLDL_LPDDEF_DF_var_name) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2115 "DLDL_LPDDEF_DF_parser.tab.c"
    break;


#line 2119 "DLDL_LPDDEF_DF_parser.tab.c"

        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
  }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yyesa, &yyes, &yyes_capacity, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 447 "./DLDL_LPDDEF_DF_parser.y"


void DLDL_LPDDEF_DFerror(const char* s)
{
	std::cout << "Syntax error on line: " << s << '\n';
}

deamer::external::cpp::ast::Tree* DLDL_LPDDEF_DF::bison::parser::Parser::Parse(const std::string& text) const
{
	outputTree = nullptr;
	YY_BUFFER_STATE buf;
	buf = DLDL_LPDDEF_DF_scan_string(text.c_str());
	DLDL_LPDDEF_DFparse();
	DLDL_LPDDEF_DF_delete_buffer(buf);
	DLDL_LPDDEF_DFlex_destroy();

	return outputTree;
}
