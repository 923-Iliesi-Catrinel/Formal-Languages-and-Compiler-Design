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




/* First part of user prologue.  */
#line 1 "cat.y"

#include <stdio.h>
#include <stdlib.h>

#include "cat.h"

void yyerror(const char *s);

#define YYDEBUG 1

#line 82 "cat.tab.c"

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

#include "cat.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_READ = 3,                       /* READ  */
  YYSYMBOL_WRITE = 4,                      /* WRITE  */
  YYSYMBOL_IF = 5,                         /* IF  */
  YYSYMBOL_OTHERWISE = 6,                  /* OTHERWISE  */
  YYSYMBOL_LOOPWHILE = 7,                  /* LOOPWHILE  */
  YYSYMBOL_LOOPFOR = 8,                    /* LOOPFOR  */
  YYSYMBOL_INTEGER = 9,                    /* INTEGER  */
  YYSYMBOL_BOOLEAN = 10,                   /* BOOLEAN  */
  YYSYMBOL_CHARACTER = 11,                 /* CHARACTER  */
  YYSYMBOL_ARRAY = 12,                     /* ARRAY  */
  YYSYMBOL_STRING = 13,                    /* STRING  */
  YYSYMBOL_ARROW = 14,                     /* ARROW  */
  YYSYMBOL_ADD = 15,                       /* ADD  */
  YYSYMBOL_SUB = 16,                       /* SUB  */
  YYSYMBOL_MUL = 17,                       /* MUL  */
  YYSYMBOL_DIV = 18,                       /* DIV  */
  YYSYMBOL_MOD = 19,                       /* MOD  */
  YYSYMBOL_LT = 20,                        /* LT  */
  YYSYMBOL_LE = 21,                        /* LE  */
  YYSYMBOL_EQ = 22,                        /* EQ  */
  YYSYMBOL_NEQ = 23,                       /* NEQ  */
  YYSYMBOL_GE = 24,                        /* GE  */
  YYSYMBOL_GT = 25,                        /* GT  */
  YYSYMBOL_AND = 26,                       /* AND  */
  YYSYMBOL_OR = 27,                        /* OR  */
  YYSYMBOL_IDENTIFIER = 28,                /* IDENTIFIER  */
  YYSYMBOL_INTCONSTANT = 29,               /* INTCONSTANT  */
  YYSYMBOL_CHARCONSTANT = 30,              /* CHARCONSTANT  */
  YYSYMBOL_STRINGCONSTANT = 31,            /* STRINGCONSTANT  */
  YYSYMBOL_SQUAREBRACKET_OPEN = 32,        /* SQUAREBRACKET_OPEN  */
  YYSYMBOL_SQUAREBRACKET_CLOSE = 33,       /* SQUAREBRACKET_CLOSE  */
  YYSYMBOL_CURLYBRACKET_OPEN = 34,         /* CURLYBRACKET_OPEN  */
  YYSYMBOL_CURLYBRACKET_CLOSE = 35,        /* CURLYBRACKET_CLOSE  */
  YYSYMBOL_PARENTHESIS_OPEN = 36,          /* PARENTHESIS_OPEN  */
  YYSYMBOL_PARENTHESIS_CLOSE = 37,         /* PARENTHESIS_CLOSE  */
  YYSYMBOL_COMMA = 38,                     /* COMMA  */
  YYSYMBOL_COLON = 39,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 40,                 /* SEMICOLON  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_program = 42,                   /* program  */
  YYSYMBOL_constant = 43,                  /* constant  */
  YYSYMBOL_var = 44,                       /* var  */
  YYSYMBOL_arr = 45,                       /* arr  */
  YYSYMBOL_value = 46,                     /* value  */
  YYSYMBOL_stmt = 47,                      /* stmt  */
  YYSYMBOL_stmttail = 48,                  /* stmttail  */
  YYSYMBOL_stmtlist = 49,                  /* stmtlist  */
  YYSYMBOL_stmtlisttail = 50,              /* stmtlisttail  */
  YYSYMBOL_type = 51,                      /* type  */
  YYSYMBOL_primitive_type = 52,            /* primitive_type  */
  YYSYMBOL_declaration = 53,               /* declaration  */
  YYSYMBOL_assign = 54,                    /* assign  */
  YYSYMBOL_arraydecl = 55,                 /* arraydecl  */
  YYSYMBOL_cmpstmt = 56,                   /* cmpstmt  */
  YYSYMBOL_expression = 57,                /* expression  */
  YYSYMBOL_expressiontail = 58,            /* expressiontail  */
  YYSYMBOL_term = 59,                      /* term  */
  YYSYMBOL_termtail = 60,                  /* termtail  */
  YYSYMBOL_factor = 61,                    /* factor  */
  YYSYMBOL_iostmt = 62,                    /* iostmt  */
  YYSYMBOL_readstmt = 63,                  /* readstmt  */
  YYSYMBOL_writestmt = 64,                 /* writestmt  */
  YYSYMBOL_ifstmt = 65,                    /* ifstmt  */
  YYSYMBOL_elsestmt = 66,                  /* elsestmt  */
  YYSYMBOL_whilestmt = 67,                 /* whilestmt  */
  YYSYMBOL_assignstmt = 68,                /* assignstmt  */
  YYSYMBOL_forstmt = 69,                   /* forstmt  */
  YYSYMBOL_RELATION = 70,                  /* RELATION  */
  YYSYMBOL_condition = 71,                 /* condition  */
  YYSYMBOL_conditiontail = 72,             /* conditiontail  */
  YYSYMBOL_simplecond = 73,                /* simplecond  */
  YYSYMBOL_conditions = 74,                /* conditions  */
  YYSYMBOL_conditionstail = 75             /* conditionstail  */
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

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   106

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  128

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    58,    58,    61,    62,    63,    66,    69,    70,    73,
      74,    77,    78,    79,    80,    81,    84,    85,    88,    91,
      92,    95,    96,    99,   100,   101,   102,   105,   108,   109,
     112,   115,   118,   121,   122,   123,   125,   128,   129,   130,
     131,   134,   135,   138,   139,   142,   145,   148,   151,   152,
     155,   158,   161,   164,   165,   166,   167,   168,   169,   170,
     171,   174,   177,   178,   181,   184,   187,   188
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "READ", "WRITE", "IF",
  "OTHERWISE", "LOOPWHILE", "LOOPFOR", "INTEGER", "BOOLEAN", "CHARACTER",
  "ARRAY", "STRING", "ARROW", "ADD", "SUB", "MUL", "DIV", "MOD", "LT",
  "LE", "EQ", "NEQ", "GE", "GT", "AND", "OR", "IDENTIFIER", "INTCONSTANT",
  "CHARCONSTANT", "STRINGCONSTANT", "SQUAREBRACKET_OPEN",
  "SQUAREBRACKET_CLOSE", "CURLYBRACKET_OPEN", "CURLYBRACKET_CLOSE",
  "PARENTHESIS_OPEN", "PARENTHESIS_CLOSE", "COMMA", "COLON", "SEMICOLON",
  "$accept", "program", "constant", "var", "arr", "value", "stmt",
  "stmttail", "stmtlist", "stmtlisttail", "type", "primitive_type",
  "declaration", "assign", "arraydecl", "cmpstmt", "expression",
  "expressiontail", "term", "termtail", "factor", "iostmt", "readstmt",
  "writestmt", "ifstmt", "elsestmt", "whilestmt", "assignstmt", "forstmt",
  "RELATION", "condition", "conditiontail", "simplecond", "conditions",
  "conditionstail", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-83)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       2,   -24,   -18,     3,     9,    26,    -8,    59,    20,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,    35,    -3,    -3,    -3,
      36,    -3,    34,    48,   -83,   -83,     2,    32,    37,   -83,
     -83,   -83,    -3,   -83,   -83,   -83,    33,    17,    -6,    -4,
      40,    45,    41,    42,    63,    43,    46,   -83,   -83,   -83,
      44,   -83,    64,   -83,   -83,   -83,    -3,   -83,   -83,   -83,
     -83,    49,   -83,    -3,    -3,   -83,    -3,    -3,    -3,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,    -3,    -3,
     -83,    -3,   -83,    39,    39,    -3,    -3,   -83,    27,    -3,
     -83,   -83,   -83,    17,    17,    -6,    -6,    -6,   -83,    40,
      45,     2,    77,   -83,   -83,    47,    50,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,    51,    39,   -83,    36,    52,
     -83,   -83,    55,    -3,    39,    56,   -83,   -83
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     8,     0,     0,     2,
      12,    43,    44,    13,    14,    15,     0,     0,     0,     0,
       0,     0,     0,     0,    11,     1,    20,     0,     8,     3,
       4,     5,     0,     9,    10,    42,     0,    35,    40,     0,
      67,    63,     0,     0,     0,     0,     0,    23,    24,    25,
       0,    26,    29,    21,    16,    22,     0,    19,    18,    45,
       6,     0,    46,     0,     0,    32,     0,     0,     0,    36,
      56,    54,    57,    58,    53,    55,    59,    60,     0,     0,
      65,     0,    61,     0,     0,     0,     0,     7,     0,     0,
      27,    17,    41,    35,    35,    40,    40,    40,    64,    67,
      63,     0,    49,    50,    51,     0,     0,    28,    33,    34,
      37,    38,    39,    66,    62,     0,     0,    47,     0,     0,
      31,    48,     0,     0,     0,     0,    52,    30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -83,   -83,   -83,   -83,    62,   -83,   -83,   -83,   -25,   -83,
     -83,     4,   -83,   -83,   -83,   -82,   -17,   -39,    -7,   -47,
     -15,   -83,   -83,   -83,   -83,   -83,   -83,   -27,   -83,   -83,
      14,    -5,    13,   -16,    -2
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     7,    33,    34,    23,    35,     8,    24,     9,    58,
      52,    53,    54,    90,    55,   102,    39,    65,    37,    69,
      38,    10,    11,    12,    13,   117,    14,    45,    15,    78,
      40,    82,    41,    42,    80
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      36,    57,   103,    43,    46,     1,     2,     3,    16,     4,
       5,    66,    67,    68,    17,    61,    70,    71,    72,    73,
      74,    75,    76,    77,    21,    28,    29,    30,    31,    32,
       6,    22,    63,    64,   121,    18,    47,    48,    49,    91,
      51,    19,   126,    47,    48,    49,    50,    51,   110,   111,
     112,    95,    96,    97,   108,   109,    93,    94,    20,    25,
      26,    98,    56,    27,    44,    59,    62,    79,   104,    21,
     105,    81,   107,   101,    83,    84,   115,    85,    89,    87,
      88,    86,    92,   116,   123,   118,   120,   119,   124,   127,
      60,   122,   106,    99,   100,   114,     0,   113,     0,     0,
       0,     0,     0,     0,     0,     0,   125
};

static const yytype_int8 yycheck[] =
{
      17,    26,    84,    19,    21,     3,     4,     5,    32,     7,
       8,    17,    18,    19,    32,    32,    20,    21,    22,    23,
      24,    25,    26,    27,    32,    28,    29,    30,    31,    32,
      28,    39,    15,    16,   116,    32,     9,    10,    11,    56,
      13,    32,   124,     9,    10,    11,    12,    13,    95,    96,
      97,    66,    67,    68,    93,    94,    63,    64,    32,     0,
      40,    78,    14,    28,    28,    33,    33,    27,    85,    32,
      86,    26,    89,    34,    33,    33,   101,    14,    14,    33,
      36,    38,    33,     6,    32,    38,    35,    37,    33,    33,
      28,   118,    88,    79,    81,   100,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   123
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     7,     8,    28,    42,    47,    49,
      62,    63,    64,    65,    67,    69,    32,    32,    32,    32,
      32,    32,    39,    45,    48,     0,    40,    28,    28,    29,
      30,    31,    32,    43,    44,    46,    57,    59,    61,    57,
      71,    73,    74,    74,    28,    68,    57,     9,    10,    11,
      12,    13,    51,    52,    53,    55,    14,    49,    50,    33,
      45,    57,    33,    15,    16,    58,    17,    18,    19,    60,
      20,    21,    22,    23,    24,    25,    26,    27,    70,    27,
      75,    26,    72,    33,    33,    14,    38,    33,    36,    14,
      54,    57,    33,    59,    59,    61,    61,    61,    57,    71,
      73,    34,    56,    56,    57,    74,    52,    57,    58,    58,
      60,    60,    60,    75,    72,    49,     6,    66,    38,    37,
      35,    56,    68,    32,    33,    57,    56,    33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    43,    44,    45,    45,    46,
      46,    47,    47,    47,    47,    47,    48,    48,    49,    50,
      50,    51,    51,    52,    52,    52,    52,    53,    54,    54,
      55,    56,    57,    58,    58,    58,    59,    60,    60,    60,
      60,    61,    61,    62,    62,    63,    64,    65,    66,    66,
      67,    68,    69,    70,    70,    70,    70,    70,    70,    70,
      70,    71,    72,    72,    73,    74,    75,    75
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     3,     0,     1,
       1,     2,     1,     1,     1,     1,     2,     3,     3,     1,
       0,     1,     1,     1,     1,     1,     1,     2,     2,     0,
       7,     3,     2,     3,     3,     0,     2,     3,     3,     3,
       0,     3,     1,     1,     1,     4,     4,     6,     2,     0,
       5,     3,     9,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     0,     3,     2,     3,     0
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



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
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
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
  switch (yyn)
    {
  case 2: /* program: stmtlist  */
#line 58 "cat.y"
                    { printf("program -> stmtlist\n"); }
#line 1226 "cat.tab.c"
    break;

  case 3: /* constant: INTCONSTANT  */
#line 61 "cat.y"
                            { printf("constant -> intconstant\n"); }
#line 1232 "cat.tab.c"
    break;

  case 4: /* constant: CHARCONSTANT  */
#line 62 "cat.y"
                            { printf("constant -> charconstant\n"); }
#line 1238 "cat.tab.c"
    break;

  case 5: /* constant: STRINGCONSTANT  */
#line 63 "cat.y"
                            { printf("constant -> stringconstant\n"); }
#line 1244 "cat.tab.c"
    break;

  case 6: /* var: IDENTIFIER arr  */
#line 66 "cat.y"
                     { printf("Variable -> IDENTIFIER OptionalArray\n"); }
#line 1250 "cat.tab.c"
    break;

  case 7: /* arr: SQUAREBRACKET_OPEN expression SQUAREBRACKET_CLOSE  */
#line 69 "cat.y"
                                                             { printf("arr -> [ expression ]\n"); }
#line 1256 "cat.tab.c"
    break;

  case 8: /* arr: %empty  */
#line 70 "cat.y"
                                                             { printf("arr -> epsilon\n"); }
#line 1262 "cat.tab.c"
    break;

  case 9: /* value: constant  */
#line 73 "cat.y"
                 { printf("value -> constant\n"); }
#line 1268 "cat.tab.c"
    break;

  case 10: /* value: var  */
#line 74 "cat.y"
                 { printf("value -> var\n"); }
#line 1274 "cat.tab.c"
    break;

  case 11: /* stmt: IDENTIFIER stmttail  */
#line 77 "cat.y"
                           { printf("stmt -> IDENTIFIER stmttail\n"); }
#line 1280 "cat.tab.c"
    break;

  case 12: /* stmt: iostmt  */
#line 78 "cat.y"
                           { printf("stmt -> iostmt\n"); }
#line 1286 "cat.tab.c"
    break;

  case 13: /* stmt: ifstmt  */
#line 79 "cat.y"
                           { printf("stmt -> ifstmt\n"); }
#line 1292 "cat.tab.c"
    break;

  case 14: /* stmt: whilestmt  */
#line 80 "cat.y"
                           { printf("stmt -> whilestmt\n"); }
#line 1298 "cat.tab.c"
    break;

  case 15: /* stmt: forstmt  */
#line 81 "cat.y"
                           { printf("stmt -> forstmt\n"); }
#line 1304 "cat.tab.c"
    break;

  case 16: /* stmttail: COLON declaration  */
#line 84 "cat.y"
                                          { printf("stmttail -> : declaration\n"); }
#line 1310 "cat.tab.c"
    break;

  case 17: /* stmttail: arr ARROW expression  */
#line 85 "cat.y"
                                    { printf("stmttail -> arr -> expression\n"); }
#line 1316 "cat.tab.c"
    break;

  case 18: /* stmtlist: stmt SEMICOLON stmtlisttail  */
#line 88 "cat.y"
                                       { printf("stmtlist -> stmt ; stmtlisttail\n"); }
#line 1322 "cat.tab.c"
    break;

  case 19: /* stmtlisttail: stmtlist  */
#line 91 "cat.y"
                        { printf("stmtlist -> stmtlist\n"); }
#line 1328 "cat.tab.c"
    break;

  case 20: /* stmtlisttail: %empty  */
#line 92 "cat.y"
                        { printf("stmtlist -> epsilon\n"); }
#line 1334 "cat.tab.c"
    break;

  case 21: /* type: primitive_type  */
#line 95 "cat.y"
                                     { printf("type -> primitive_type\n"); }
#line 1340 "cat.tab.c"
    break;

  case 22: /* type: arraydecl  */
#line 96 "cat.y"
                                     { printf("type -> arraydecl\n"); }
#line 1346 "cat.tab.c"
    break;

  case 23: /* primitive_type: INTEGER  */
#line 99 "cat.y"
                                     { printf("primitive_type -> integer\n"); }
#line 1352 "cat.tab.c"
    break;

  case 24: /* primitive_type: BOOLEAN  */
#line 100 "cat.y"
                                     { printf("primitive_type -> boolean\n"); }
#line 1358 "cat.tab.c"
    break;

  case 25: /* primitive_type: CHARACTER  */
#line 101 "cat.y"
                                     { printf("primitive_type -> character\n"); }
#line 1364 "cat.tab.c"
    break;

  case 26: /* primitive_type: STRING  */
#line 102 "cat.y"
                                     { printf("primitive_type -> string\n"); }
#line 1370 "cat.tab.c"
    break;

  case 27: /* declaration: type assign  */
#line 105 "cat.y"
                          { printf("declaration -> type assign\n"); }
#line 1376 "cat.tab.c"
    break;

  case 28: /* assign: ARROW expression  */
#line 108 "cat.y"
                          { printf("assign -> -> expression\n"); }
#line 1382 "cat.tab.c"
    break;

  case 29: /* assign: %empty  */
#line 109 "cat.y"
                          { printf("assign -> epsilon\n"); }
#line 1388 "cat.tab.c"
    break;

  case 30: /* arraydecl: ARRAY PARENTHESIS_OPEN primitive_type PARENTHESIS_CLOSE SQUAREBRACKET_OPEN expression SQUAREBRACKET_CLOSE  */
#line 112 "cat.y"
                                                                                                                      { printf("arraydecl -> identifier : array (primitive_type) [expression]"); }
#line 1394 "cat.tab.c"
    break;

  case 31: /* cmpstmt: CURLYBRACKET_OPEN stmtlist CURLYBRACKET_CLOSE  */
#line 115 "cat.y"
                                                        { printf("cmpstmt -> { stmtlist }\n"); }
#line 1400 "cat.tab.c"
    break;

  case 32: /* expression: term expressiontail  */
#line 118 "cat.y"
                                 { printf("expression -> term expressiontail\n"); }
#line 1406 "cat.tab.c"
    break;

  case 33: /* expressiontail: ADD term expressiontail  */
#line 121 "cat.y"
                                         { printf("expressiontail -> ADD term expressiontail\n"); }
#line 1412 "cat.tab.c"
    break;

  case 34: /* expressiontail: SUB term expressiontail  */
#line 122 "cat.y"
                                         { printf("expressiontail -> SUB term expressiontail\n"); }
#line 1418 "cat.tab.c"
    break;

  case 35: /* expressiontail: %empty  */
#line 123 "cat.y"
                            { printf("expressiontail -> epsilon\n"); }
#line 1424 "cat.tab.c"
    break;

  case 36: /* term: factor termtail  */
#line 125 "cat.y"
                       { printf("term -> factor termtail\n"); }
#line 1430 "cat.tab.c"
    break;

  case 37: /* termtail: MUL factor termtail  */
#line 128 "cat.y"
                               { printf("termtail -> MUL factor termtail\n"); }
#line 1436 "cat.tab.c"
    break;

  case 38: /* termtail: DIV factor termtail  */
#line 129 "cat.y"
                              { printf("termtail -> DIV factor termtail\n"); }
#line 1442 "cat.tab.c"
    break;

  case 39: /* termtail: MOD factor termtail  */
#line 130 "cat.y"
                              { printf("termtail -> MOD factor termtail\n"); }
#line 1448 "cat.tab.c"
    break;

  case 40: /* termtail: %empty  */
#line 131 "cat.y"
                              { printf("termtail -> epsilon\n"); }
#line 1454 "cat.tab.c"
    break;

  case 41: /* factor: SQUAREBRACKET_OPEN expression SQUAREBRACKET_CLOSE  */
#line 134 "cat.y"
                                                          { printf("factor -> [ Expression ]\n"); }
#line 1460 "cat.tab.c"
    break;

  case 42: /* factor: value  */
#line 135 "cat.y"
                                                          { printf("factor -> value\n"); }
#line 1466 "cat.tab.c"
    break;

  case 43: /* iostmt: readstmt  */
#line 138 "cat.y"
                   { printf("iostmt -> readstmt\n"); }
#line 1472 "cat.tab.c"
    break;

  case 44: /* iostmt: writestmt  */
#line 139 "cat.y"
                   { printf("iostmt -> writestmt\n"); }
#line 1478 "cat.tab.c"
    break;

  case 45: /* readstmt: READ SQUAREBRACKET_OPEN IDENTIFIER SQUAREBRACKET_CLOSE  */
#line 142 "cat.y"
                                                                  { printf("readstmt -> read [ IDENTIFIER ]\n"); }
#line 1484 "cat.tab.c"
    break;

  case 46: /* writestmt: WRITE SQUAREBRACKET_OPEN expression SQUAREBRACKET_CLOSE  */
#line 145 "cat.y"
                                                                        { printf("writestmt -> write [ IDENTIFIER ]\n"); }
#line 1490 "cat.tab.c"
    break;

  case 47: /* ifstmt: IF SQUAREBRACKET_OPEN conditions SQUAREBRACKET_CLOSE cmpstmt elsestmt  */
#line 148 "cat.y"
                                                                                 { printf("ifstmt -> if [ conditions ] cmpstmt \n"); }
#line 1496 "cat.tab.c"
    break;

  case 48: /* elsestmt: OTHERWISE cmpstmt  */
#line 151 "cat.y"
                             { printf("elsestmt -> OTHERWISE cmpstmt\n"); }
#line 1502 "cat.tab.c"
    break;

  case 49: /* elsestmt: %empty  */
#line 152 "cat.y"
                       { printf("elsestmt -> epsilon\n"); }
#line 1508 "cat.tab.c"
    break;

  case 50: /* whilestmt: LOOPWHILE SQUAREBRACKET_OPEN conditions SQUAREBRACKET_CLOSE cmpstmt  */
#line 155 "cat.y"
                                                                                { printf("whilestmt -> while [ conditions ] cmpstmt\n"); }
#line 1514 "cat.tab.c"
    break;

  case 51: /* assignstmt: IDENTIFIER ARROW expression  */
#line 158 "cat.y"
                                         { printf("assignstmt -> IDENTIFIER -> expression\n"); }
#line 1520 "cat.tab.c"
    break;

  case 52: /* forstmt: LOOPFOR SQUAREBRACKET_OPEN assignstmt COMMA conditions COMMA assignstmt SQUAREBRACKET_CLOSE cmpstmt  */
#line 161 "cat.y"
                                                                                                              { printf("forstmt -> for [assignstmt, conditions, assignstmt] cmpstmt \n"); }
#line 1526 "cat.tab.c"
    break;

  case 53: /* RELATION: GE  */
#line 164 "cat.y"
                        { printf("RELATION -> >=\n"); }
#line 1532 "cat.tab.c"
    break;

  case 54: /* RELATION: LE  */
#line 165 "cat.y"
                        { printf("RELATION -> <=\n"); }
#line 1538 "cat.tab.c"
    break;

  case 55: /* RELATION: GT  */
#line 166 "cat.y"
                        { printf("RELATION -> >\n"); }
#line 1544 "cat.tab.c"
    break;

  case 56: /* RELATION: LT  */
#line 167 "cat.y"
                        { printf("RELATION -> <\n"); }
#line 1550 "cat.tab.c"
    break;

  case 57: /* RELATION: EQ  */
#line 168 "cat.y"
                        { printf("RELATION -> =\n"); }
#line 1556 "cat.tab.c"
    break;

  case 58: /* RELATION: NEQ  */
#line 169 "cat.y"
                        { printf("RELATION -> !=\n"); }
#line 1562 "cat.tab.c"
    break;

  case 59: /* RELATION: AND  */
#line 170 "cat.y"
                        { printf("RELATION -> &&\n"); }
#line 1568 "cat.tab.c"
    break;

  case 60: /* RELATION: OR  */
#line 171 "cat.y"
                        { printf("RELATION -> ||\n"); }
#line 1574 "cat.tab.c"
    break;

  case 61: /* condition: simplecond conditiontail  */
#line 174 "cat.y"
                                    { printf("condition -> simplecond conditiontail\n"); }
#line 1580 "cat.tab.c"
    break;

  case 62: /* conditiontail: AND simplecond conditiontail  */
#line 177 "cat.y"
                                            { printf("conditiontail -> AND simplecond conditiontail\n"); }
#line 1586 "cat.tab.c"
    break;

  case 63: /* conditiontail: %empty  */
#line 178 "cat.y"
                                                 { printf("conditiontail -> epsilon\n"); }
#line 1592 "cat.tab.c"
    break;

  case 64: /* simplecond: expression RELATION expression  */
#line 181 "cat.y"
                                           { printf("simplecond -> expression RELATION expression\n"); }
#line 1598 "cat.tab.c"
    break;

  case 65: /* conditions: condition conditionstail  */
#line 184 "cat.y"
                                     { printf("conditions -> condition conditiontail\n"); }
#line 1604 "cat.tab.c"
    break;

  case 66: /* conditionstail: OR condition conditionstail  */
#line 187 "cat.y"
                                            { printf("conditionstail -> OR condition conditionstail\n"); }
#line 1610 "cat.tab.c"
    break;

  case 67: /* conditionstail: %empty  */
#line 188 "cat.y"
                                            { printf("conditionstail -> epsilon\n"); }
#line 1616 "cat.tab.c"
    break;


#line 1620 "cat.tab.c"

      default: break;
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
      yyerror (YY_("syntax error"));
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

  return yyresult;
}

#line 191 "cat.y"


extern FILE *yyin;
extern int yyparse(void);

void yyerror(const char *s) {
    printf("Parsing error: %s\n", s);

    fclose(yyin);
    exit(1);
}

int main(int argc, char** argv) {
    if (argc > 2) {
        printf("Too many arguments!\n");
        return 1;
    }

    if (argc == 2) {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL) {
            printf("Unable to open %s\n", argv[1]);
            exit(1);
        }
    } else {
        yyin = stdin;
    }

    yyparse();
    fclose(yyin);
    return 0;
}
