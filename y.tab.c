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
#line 1 "proiect.y"

#include <string.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

extern FILE *yyin;
extern int yylex();

void yyerror(const char* s);

// Inlocuieste toate aparitiile unui substring cu alt substring.
static inline void ReplaceAllOccurrences(string &str, const string &from, const string &to) {
    size_t position = 0;
    // Cauta toate aparitiile substringului 'from' in stringul 'str'.
    while((position = str.find(from, position)) != string::npos) {
        // Inlocuieste aparitia gasita a substringului 'from' cu substringul 'to'.
        str.replace(position, from.length(), to);
        // Actualizeaza pozitia pentru a continua cautarea dupa inlocuire.
        position += to.length(); 
    }
}

// Elimina spatiile suplimentare reprezentate de linii goale consecutive intr-un string.
static inline void TrimSpaces(string &str) {
    size_t position = 0;
    // Cauta toate aparitiile secventei "\n\n" in stringul 'str'.
    while((position = str.find("\n\n", position)) != string::npos) {
        // Inlocuieste aparitia gasita a secventei "\n\n" cu un singur caracter de newline "\n".
        str.replace(position, 2, "\n");
    }
}


#line 108 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
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
    INTEGER = 258,                 /* INTEGER  */
    IDENT = 259,                   /* IDENT  */
    CHARVAL = 260,                 /* CHARVAL  */
    VOID = 261,                    /* VOID  */
    SCNF = 262,                    /* SCNF  */
    PRTF = 263,                    /* PRTF  */
    IF = 264,                      /* IF  */
    ELSE = 265,                    /* ELSE  */
    GREATER = 266,                 /* GREATER  */
    EQEQ = 267,                    /* EQEQ  */
    LESSEQ = 268,                  /* LESSEQ  */
    GREATEREQ = 269,               /* GREATEREQ  */
    LESS = 270,                    /* LESS  */
    INCREMENT = 271,               /* INCREMENT  */
    DECREMENT = 272,               /* DECREMENT  */
    INCL = 273,                    /* INCL  */
    MULTIPLICATION = 274,          /* MULTIPLICATION  */
    DIVIDE = 275,                  /* DIVIDE  */
    RETURN = 276,                  /* RETURN  */
    PLUSEQ = 277,                  /* PLUSEQ  */
    MINUSEQ = 278,                 /* MINUSEQ  */
    FLOATVAL = 279,                /* FLOATVAL  */
    PLUS = 280,                    /* PLUS  */
    EQ = 281,                      /* EQ  */
    MINUS = 282,                   /* MINUS  */
    SEMICOLON = 283,               /* SEMICOLON  */
    COMMA = 284,                   /* COMMA  */
    OPPARENTH = 285,               /* OPPARENTH  */
    OPENCURL = 286,                /* OPENCURL  */
    SCANF = 287,                   /* SCANF  */
    DEN = 288,                     /* DEN  */
    QUOTES = 289,                  /* QUOTES  */
    INTRESERVE = 290,              /* INTRESERVE  */
    DOUBLERESERVE = 291,           /* DOUBLERESERVE  */
    FLOATRESERVE = 292,            /* FLOATRESERVE  */
    CHARRESERVE = 293,             /* CHARRESERVE  */
    DOT = 294,                     /* DOT  */
    QUOTE = 295,                   /* QUOTE  */
    CLPARENTH = 296,               /* CLPARENTH  */
    CLOSECURL = 297,               /* CLOSECURL  */
    MODULO = 298,                  /* MODULO  */
    AND = 299,                     /* AND  */
    FOR = 300,                     /* FOR  */
    WHILE = 301,                   /* WHILE  */
    DO = 302                       /* DO  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INTEGER 258
#define IDENT 259
#define CHARVAL 260
#define VOID 261
#define SCNF 262
#define PRTF 263
#define IF 264
#define ELSE 265
#define GREATER 266
#define EQEQ 267
#define LESSEQ 268
#define GREATEREQ 269
#define LESS 270
#define INCREMENT 271
#define DECREMENT 272
#define INCL 273
#define MULTIPLICATION 274
#define DIVIDE 275
#define RETURN 276
#define PLUSEQ 277
#define MINUSEQ 278
#define FLOATVAL 279
#define PLUS 280
#define EQ 281
#define MINUS 282
#define SEMICOLON 283
#define COMMA 284
#define OPPARENTH 285
#define OPENCURL 286
#define SCANF 287
#define DEN 288
#define QUOTES 289
#define INTRESERVE 290
#define DOUBLERESERVE 291
#define FLOATRESERVE 292
#define CHARRESERVE 293
#define DOT 294
#define QUOTE 295
#define CLPARENTH 296
#define CLOSECURL 297
#define MODULO 298
#define AND 299
#define FOR 300
#define WHILE 301
#define DO 302

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 46 "proiect.y"

    int number;
    char* str;
    double doubflt;

#line 261 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEGER = 3,                    /* INTEGER  */
  YYSYMBOL_IDENT = 4,                      /* IDENT  */
  YYSYMBOL_CHARVAL = 5,                    /* CHARVAL  */
  YYSYMBOL_VOID = 6,                       /* VOID  */
  YYSYMBOL_SCNF = 7,                       /* SCNF  */
  YYSYMBOL_PRTF = 8,                       /* PRTF  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_GREATER = 11,                   /* GREATER  */
  YYSYMBOL_EQEQ = 12,                      /* EQEQ  */
  YYSYMBOL_LESSEQ = 13,                    /* LESSEQ  */
  YYSYMBOL_GREATEREQ = 14,                 /* GREATEREQ  */
  YYSYMBOL_LESS = 15,                      /* LESS  */
  YYSYMBOL_INCREMENT = 16,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 17,                 /* DECREMENT  */
  YYSYMBOL_INCL = 18,                      /* INCL  */
  YYSYMBOL_MULTIPLICATION = 19,            /* MULTIPLICATION  */
  YYSYMBOL_DIVIDE = 20,                    /* DIVIDE  */
  YYSYMBOL_RETURN = 21,                    /* RETURN  */
  YYSYMBOL_PLUSEQ = 22,                    /* PLUSEQ  */
  YYSYMBOL_MINUSEQ = 23,                   /* MINUSEQ  */
  YYSYMBOL_FLOATVAL = 24,                  /* FLOATVAL  */
  YYSYMBOL_PLUS = 25,                      /* PLUS  */
  YYSYMBOL_EQ = 26,                        /* EQ  */
  YYSYMBOL_MINUS = 27,                     /* MINUS  */
  YYSYMBOL_SEMICOLON = 28,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 29,                     /* COMMA  */
  YYSYMBOL_OPPARENTH = 30,                 /* OPPARENTH  */
  YYSYMBOL_OPENCURL = 31,                  /* OPENCURL  */
  YYSYMBOL_SCANF = 32,                     /* SCANF  */
  YYSYMBOL_DEN = 33,                       /* DEN  */
  YYSYMBOL_QUOTES = 34,                    /* QUOTES  */
  YYSYMBOL_INTRESERVE = 35,                /* INTRESERVE  */
  YYSYMBOL_DOUBLERESERVE = 36,             /* DOUBLERESERVE  */
  YYSYMBOL_FLOATRESERVE = 37,              /* FLOATRESERVE  */
  YYSYMBOL_CHARRESERVE = 38,               /* CHARRESERVE  */
  YYSYMBOL_DOT = 39,                       /* DOT  */
  YYSYMBOL_QUOTE = 40,                     /* QUOTE  */
  YYSYMBOL_CLPARENTH = 41,                 /* CLPARENTH  */
  YYSYMBOL_CLOSECURL = 42,                 /* CLOSECURL  */
  YYSYMBOL_MODULO = 43,                    /* MODULO  */
  YYSYMBOL_AND = 44,                       /* AND  */
  YYSYMBOL_FOR = 45,                       /* FOR  */
  YYSYMBOL_WHILE = 46,                     /* WHILE  */
  YYSYMBOL_DO = 47,                        /* DO  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_program = 49,                   /* program  */
  YYSYMBOL_fncns = 50,                     /* fncns  */
  YYSYMBOL_fncn = 51,                      /* fncn  */
  YYSYMBOL_b_for_funs = 52,                /* b_for_funs  */
  YYSYMBOL_b_for_fun = 53,                 /* b_for_fun  */
  YYSYMBOL_typ_f = 54,                     /* typ_f  */
  YYSYMBOL_parameter = 55,                 /* parameter  */
  YYSYMBOL_assgns = 56,                    /* assgns  */
  YYSYMBOL_assgn = 57,                     /* assgn  */
  YYSYMBOL_assgn_type = 58,                /* assgn_type  */
  YYSYMBOL_decl_body = 59,                 /* decl_body  */
  YYSYMBOL_ifelse = 60,                    /* ifelse  */
  YYSYMBOL_forLoop = 61,                   /* forLoop  */
  YYSYMBOL_whileLoop = 62,                 /* whileLoop  */
  YYSYMBOL_doWhile = 63,                   /* doWhile  */
  YYSYMBOL_incordec = 64,                  /* incordec  */
  YYSYMBOL_comparetype = 65,               /* comparetype  */
  YYSYMBOL_identOrInt = 66,                /* identOrInt  */
  YYSYMBOL_call = 67,                      /* call  */
  YYSYMBOL_callBody = 68,                  /* callBody  */
  YYSYMBOL_prtf = 69,                      /* prtf  */
  YYSYMBOL_scnf = 70                       /* scnf  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   342

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  230

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    62,    62,    62,    62,    67,    67,    71,    75,    88,
     101,   114,   130,   133,   138,   141,   144,   147,   169,   172,
     175,   182,   182,   182,   182,   182,   187,   189,   194,   197,
     202,   205,   208,   211,   214,   217,   220,   223,   226,   229,
     232,   235,   238,   241,   244,   247,   250,   253,   256,   259,
     264,   264,   264,   264,   270,   273,   276,   279,   282,   285,
     288,   291,   294,   299,   306,   314,   320,   326,   332,   338,
     345,   355,   364,   373,   378,   385,   392,   399,   408,   411,
     416,   419,   422,   425,   428,   433,   436,   441,   444,   449,
     452,   457,   462
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
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER", "IDENT",
  "CHARVAL", "VOID", "SCNF", "PRTF", "IF", "ELSE", "GREATER", "EQEQ",
  "LESSEQ", "GREATEREQ", "LESS", "INCREMENT", "DECREMENT", "INCL",
  "MULTIPLICATION", "DIVIDE", "RETURN", "PLUSEQ", "MINUSEQ", "FLOATVAL",
  "PLUS", "EQ", "MINUS", "SEMICOLON", "COMMA", "OPPARENTH", "OPENCURL",
  "SCANF", "DEN", "QUOTES", "INTRESERVE", "DOUBLERESERVE", "FLOATRESERVE",
  "CHARRESERVE", "DOT", "QUOTE", "CLPARENTH", "CLOSECURL", "MODULO", "AND",
  "FOR", "WHILE", "DO", "$accept", "program", "fncns", "fncn",
  "b_for_funs", "b_for_fun", "typ_f", "parameter", "assgns", "assgn",
  "assgn_type", "decl_body", "ifelse", "forLoop", "whileLoop", "doWhile",
  "incordec", "comparetype", "identOrInt", "call", "callBody", "prtf",
  "scnf", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-193)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-63)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     166,  -193,   110,  -193,  -193,  -193,  -193,     9,   110,  -193,
      14,   110,  -193,  -193,    -3,    47,    71,  -193,  -193,  -193,
    -193,  -193,   -12,    94,  -193,    38,    49,    57,    30,    64,
    -193,    44,    41,    78,    80,    87,   187,    89,    91,    93,
       3,    83,   106,  -193,  -193,  -193,  -193,    52,    76,   131,
     146,     2,   156,  -193,  -193,  -193,    81,    97,   125,     6,
     136,  -193,   143,   175,   182,   -17,   230,    94,  -193,  -193,
    -193,  -193,  -193,  -193,   198,   212,   218,   220,   203,  -193,
     222,   223,   224,   225,   226,   227,   228,   229,   232,   233,
    -193,   207,   235,   236,   237,   238,   254,   239,    54,   240,
     255,   257,   230,   269,  -193,  -193,   270,   270,   270,   270,
     165,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
     274,  -193,  -193,  -193,   250,   251,   231,   277,  -193,   174,
     278,   258,   231,   241,   -11,   259,  -193,  -193,  -193,  -193,
     150,     1,   157,   159,  -193,   242,   283,  -193,  -193,  -193,
    -193,  -193,   188,   231,  -193,   247,   286,   188,   244,   249,
     288,   289,   253,  -193,  -193,   256,   188,   267,   268,   260,
     272,  -193,   262,   263,   271,   275,   264,   265,   294,   279,
     296,   280,   281,  -193,    67,   282,  -193,   231,   116,   231,
     273,  -193,  -193,   276,   129,   194,  -193,   284,   188,  -193,
     190,  -193,   285,   291,   292,  -193,   287,  -193,   190,   307,
     308,   293,  -193,   219,   219,  -193,  -193,  -193,   290,   295,
     298,   299,   173,   186,  -193,   297,  -193,   300,  -193,  -193
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,    21,     0,    25,    22,    23,    24,     0,     3,     6,
       0,     2,     1,     5,     0,     0,     0,    26,    53,    50,
      51,    52,     0,    27,    29,     0,     0,     0,     0,     0,
      28,    31,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,    48,    49,    34,     0,     0,     0,
       0,     0,     0,    36,    35,    47,     0,     0,     0,     0,
       0,     7,     0,     0,     0,     0,    13,    14,    17,    18,
      19,    20,    16,    15,    54,    61,    56,    55,    62,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,    12,     0,     0,     0,     0,
       0,    33,    40,    39,    44,    43,    38,    37,    42,    41,
       0,    87,    46,    45,     0,     0,     0,     0,    68,     0,
       0,     0,     0,     0,     0,    62,    57,    60,    59,    58,
       0,    61,     0,     0,    90,     0,     0,    80,    81,    84,
      83,    82,     0,     0,    67,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    85,     0,     0,     0,     0,     0,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,     0,     0,    10,     0,     0,     0,
       0,    92,    64,     0,     0,     0,    76,     0,     0,    11,
      63,    66,     0,     0,     0,    75,     0,    69,    65,     0,
       0,     0,    70,     0,     0,    77,    78,    79,     0,     0,
       0,     0,     0,     0,    73,     0,    74,     0,    71,    72
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -193,  -193,   312,    70,   -66,  -193,  -193,  -193,   301,   -20,
    -193,   -41,  -192,  -193,  -193,  -193,   103,  -130,  -152,  -193,
     202,  -193,  -193
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,     8,     9,    65,    66,    10,    22,    67,    24,
      25,    32,    68,    69,    70,    71,   218,   152,   165,    39,
      91,    72,    73
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     105,    80,   157,    30,   103,   169,    89,    16,   207,    12,
      56,    57,    58,    59,   176,    97,   212,   159,    14,   160,
      47,    48,    79,   166,    60,   104,    49,    15,    50,    29,
     107,    51,   129,    35,    36,    37,   133,    98,    18,    19,
      20,    21,    31,    90,    52,    61,   206,    30,    62,    63,
      64,    16,    33,    17,    38,    81,    82,   195,    16,   198,
      34,    56,    57,    58,    59,   136,   137,   138,   139,    43,
      41,    16,   -62,    42,    56,    57,    58,    59,    13,    83,
      84,    13,    18,    19,    20,    21,    74,    75,    76,    18,
      19,    20,    21,    26,    27,    40,   128,    28,    16,    62,
      63,    64,    18,    19,    20,    21,    44,    77,    45,   192,
      78,    94,    62,    63,    64,    46,     1,    53,   193,    54,
      16,    55,   197,    56,    57,    58,    59,    95,   202,    18,
      19,    20,    21,    16,    85,    86,    56,    57,    58,    59,
      99,    18,    19,    20,    21,     3,     4,     5,     6,    87,
      88,    18,    19,    20,    21,    96,   225,   227,   196,    92,
      93,    62,    63,    64,    18,    19,    20,    21,   140,   141,
     142,   201,     1,   100,    62,    63,    64,    16,    46,   106,
      56,    57,    58,    59,     2,    53,   108,    54,   109,   143,
      16,   163,   164,    56,    57,    58,    59,   203,   204,    58,
      59,     3,     4,     5,     6,   101,    47,    48,    18,    19,
      20,    21,    49,   102,    50,   224,   154,    51,    62,    63,
      64,    18,    19,    20,    21,    26,    27,   106,   226,   110,
      52,    62,    63,    64,    16,   216,   217,    56,    57,    58,
      59,   107,   147,   148,   149,   150,   151,   108,   121,   109,
     111,   112,   113,   114,   115,   116,   117,   118,   126,   131,
     119,   132,   120,   122,   123,    18,    19,    20,    21,   127,
     130,   124,   125,   134,   135,    62,    63,    64,    89,   145,
     146,   153,   155,   158,   156,    41,   161,   162,   167,   168,
     170,   171,   172,   173,   174,   177,   178,   175,   187,   183,
     189,   179,   180,   181,   182,   185,   184,   186,   190,   191,
     188,   213,   214,   194,    11,   199,    23,   219,   200,   209,
     210,   215,   144,     0,     0,     0,   205,   208,   211,   222,
     223,   220,     0,     0,     0,     0,   221,     0,     0,   228,
       0,     0,   229
};

static const yytype_int16 yycheck[] =
{
      66,    42,   132,    23,    21,   157,     4,     4,   200,     0,
       7,     8,     9,    10,   166,     9,   208,    28,     4,    30,
      19,    20,    42,   153,    21,    42,    25,    30,    27,    41,
      29,    30,    98,     3,     4,     5,   102,    31,    35,    36,
      37,    38,     4,    41,    43,    42,   198,    67,    45,    46,
      47,     4,     3,     6,    24,     3,     4,   187,     4,   189,
       3,     7,     8,     9,    10,   106,   107,   108,   109,    28,
      26,     4,    28,    29,     7,     8,     9,    10,     8,     3,
       4,    11,    35,    36,    37,    38,     3,     4,     5,    35,
      36,    37,    38,    22,    23,    31,    42,    26,     4,    45,
      46,    47,    35,    36,    37,    38,    28,    24,    28,    42,
       4,    30,    45,    46,    47,    28,     6,    28,   184,    28,
       4,    28,   188,     7,     8,     9,    10,    30,   194,    35,
      36,    37,    38,     4,     3,     4,     7,     8,     9,    10,
       4,    35,    36,    37,    38,    35,    36,    37,    38,     3,
       4,    35,    36,    37,    38,    30,   222,   223,    42,     3,
       4,    45,    46,    47,    35,    36,    37,    38,     3,     4,
       5,    42,     6,    30,    45,    46,    47,     4,    28,    29,
       7,     8,     9,    10,    18,    28,    29,    28,    29,    24,
       4,     3,     4,     7,     8,     9,    10,     3,     4,     9,
      10,    35,    36,    37,    38,    30,    19,    20,    35,    36,
      37,    38,    25,    31,    27,    42,    42,    30,    45,    46,
      47,    35,    36,    37,    38,    22,    23,    29,    42,    26,
      43,    45,    46,    47,     4,    16,    17,     7,     8,     9,
      10,    29,    11,    12,    13,    14,    15,    29,    41,    29,
      28,    28,    28,    28,    28,    28,    28,    28,     4,     4,
      28,     4,    29,    28,    28,    35,    36,    37,    38,    30,
      30,    34,    34,     4,     4,    45,    46,    47,     4,    29,
      29,     4,     4,    42,    26,    26,    44,     4,    41,     3,
      46,    42,     4,     4,    41,    28,    28,    41,     4,    28,
       4,    41,    30,    41,    41,    41,    31,    42,    28,    28,
      31,     4,     4,    31,     2,    42,    15,   214,    42,    28,
      28,    28,   120,    -1,    -1,    -1,    42,    42,    41,    31,
      31,    41,    -1,    -1,    -1,    -1,    41,    -1,    -1,    42,
      -1,    -1,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    18,    35,    36,    37,    38,    49,    50,    51,
      54,    50,     0,    51,     4,    30,     4,     6,    35,    36,
      37,    38,    55,    56,    57,    58,    22,    23,    26,    41,
      57,     4,    59,     3,     3,     3,     4,     5,    24,    67,
      31,    26,    29,    28,    28,    28,    28,    19,    20,    25,
      27,    30,    43,    28,    28,    28,     7,     8,     9,    10,
      21,    42,    45,    46,    47,    52,    53,    56,    60,    61,
      62,    63,    69,    70,     3,     4,     5,    24,     4,    57,
      59,     3,     4,     3,     4,     3,     4,     3,     4,     4,
      41,    68,     3,     4,    30,    30,    30,     9,    31,     4,
      30,    30,    31,    21,    42,    52,    29,    29,    29,    29,
      26,    28,    28,    28,    28,    28,    28,    28,    28,    28,
      29,    41,    28,    28,    34,    34,     4,    30,    42,    52,
      30,     4,     4,    52,     4,     4,    59,    59,    59,    59,
       3,     4,     5,    24,    68,    29,    29,    11,    12,    13,
      14,    15,    65,     4,    42,     4,    26,    65,    42,    28,
      30,    44,     4,     3,     4,    66,    65,    41,     3,    66,
      46,    42,     4,     4,    41,    41,    66,    28,    28,    41,
      30,    41,    41,    28,    31,    41,    42,     4,    31,     4,
      28,    28,    42,    52,    31,    65,    42,    52,    65,    42,
      42,    42,    52,     3,     4,    42,    66,    60,    42,    28,
      28,    41,    60,     4,     4,    28,    16,    17,    64,    64,
      41,    41,    31,    31,    42,    52,    42,    52,    42,    42
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    49,    49,    50,    50,    51,    51,    51,
      51,    51,    52,    52,    53,    53,    53,    53,    53,    53,
      53,    54,    54,    54,    54,    54,    55,    55,    56,    56,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      58,    58,    58,    58,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    60,    60,    60,    60,    60,    60,    60,
      60,    61,    61,    61,    61,    62,    62,    63,    64,    64,
      65,    65,    65,    65,    65,    66,    66,    67,    67,    68,
      68,    69,    70
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     0,     2,     1,     7,     8,    11,
      13,    14,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     2,     4,     5,     4,     4,     4,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     4,     4,     4,
       1,     1,     1,     1,     3,     3,     3,     5,     5,     5,
       5,     3,     1,     9,     8,    10,     9,     4,     3,    10,
      11,    16,    16,    15,    15,     9,     8,    11,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     3,     1,
       3,     7,     8
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
  case 4: /* program: %empty  */
#line 62 "proiect.y"
                     {cout<<"Enter a valid input"<<endl;}
#line 1476 "y.tab.c"
    break;

  case 7: /* fncn: typ_f IDENT OPPARENTH parameter CLPARENTH OPENCURL CLOSECURL  */
#line 72 "proiect.y"
        { cout << "FUNCTIE " << (yyvsp[-5].str) << " " << (yyvsp[-3].str) << "\nSFARSIT FUNCTIE " << (yyvsp[-5].str) << "\n\n"; }
#line 1482 "y.tab.c"
    break;

  case 8: /* fncn: typ_f IDENT OPPARENTH parameter CLPARENTH OPENCURL b_for_funs CLOSECURL  */
#line 75 "proiect.y"
                                                                            {    
        string s = "FUNCTIE " + string((yyvsp[-6].str)) + " " + string((yyvsp[-4].str)) + "\n" + string((yyvsp[-1].str));
        // Inlocuieste toate newline-urile cu newline urmate de tab
        ReplaceAllOccurrences(s, string("\n"), string("\n\t"));
        // Elimina tab-urile care preced newline-urile
        ReplaceAllOccurrences(s, string("\t\n"), string("\n")); 
        // Elimina liniile goale consecutive
        TrimSpaces(s); 
        cout << s;
        cout << "\nSFARSIT FUNCTIE " << (yyvsp[-6].str) << "\n\n";
        }
#line 1498 "y.tab.c"
    break;

  case 9: /* fncn: typ_f IDENT OPPARENTH parameter CLPARENTH OPENCURL b_for_funs RETURN IDENT SEMICOLON CLOSECURL  */
#line 88 "proiect.y"
                                                                                                   {    
        string s = "FUNCTIE " + string((yyvsp[-9].str)) + " " + string((yyvsp[-7].str)) + "\n" + string((yyvsp[-4].str)) + "\n" + string((yyvsp[-9].str)) + "=" + string((yyvsp[-2].str));
        // Inlocuieste toate newline-urile cu newline urmate de tab
        ReplaceAllOccurrences(s, string("\n"), string("\n\t"));
        // Elimina tab-urile care preced newline-urile
        ReplaceAllOccurrences(s, string("\t\n"), string("\n")); 
        // Elimina liniile goale consecutive
        TrimSpaces(s);
        cout << s;
        cout << "\nSFARSIT FUNCTIE " << (yyvsp[-9].str) << "\n\n";
        }
#line 1514 "y.tab.c"
    break;

  case 10: /* fncn: typ_f IDENT OPPARENTH parameter CLPARENTH OPENCURL RETURN IDENT OPPARENTH IDENT CLPARENTH SEMICOLON CLOSECURL  */
#line 101 "proiect.y"
                                                                                                                  {    
        string s = "FUNCTIE " + string((yyvsp[-11].str)) + " " + string((yyvsp[-9].str)) + "\n " + string((yyvsp[-6].str)) + " " + string((yyvsp[-11].str)) + "=" + string((yyvsp[-3].str));
        // Inlocuieste toate newline-urile cu newline urmate de tab
        ReplaceAllOccurrences(s, string("\n"), string("\n\t"));
        // Elimina tab-urile care preced newline-urile
        ReplaceAllOccurrences(s, string("\t\n"), string("\n")); 
        // Elimina liniile goale consecutive
        TrimSpaces(s);
        cout << s;
        cout << "\nSFARSIT FUNCTIE " << (yyvsp[-11].str) << "\n\n";
        }
#line 1530 "y.tab.c"
    break;

  case 11: /* fncn: typ_f IDENT OPPARENTH parameter CLPARENTH OPENCURL b_for_funs RETURN IDENT OPPARENTH IDENT CLPARENTH SEMICOLON CLOSECURL  */
#line 114 "proiect.y"
                                                                                                                             {    
        string s = "FUNCTIE " + string((yyvsp[-12].str)) + " " + string((yyvsp[-10].str)) + "\n" + string((yyvsp[-7].str)) + "\nreturn " + string((yyvsp[-12].str)) + "=" + string((yyvsp[-3].str));
        // Inlocuieste toate newline-urile cu newline urmate de tab
        ReplaceAllOccurrences(s, string("\n"), string("\n\t"));
        // Elimina tab-urile care preced newline-urile
        ReplaceAllOccurrences(s, string("\t\n"), string("\n")); 
        // Elimina liniile goale consecutive
        TrimSpaces(s);
        cout << s;
        cout << "\nSFARSIT FUNCTIE " << (yyvsp[-12].str) << "\n\n";
        }
#line 1546 "y.tab.c"
    break;

  case 12: /* b_for_funs: b_for_fun b_for_funs  */
#line 130 "proiect.y"
                         { (yyval.str) = strdup((string((yyvsp[-1].str)) + "\n" + string((yyvsp[0].str))).c_str()); }
#line 1552 "y.tab.c"
    break;

  case 13: /* b_for_funs: b_for_fun  */
#line 133 "proiect.y"
              { (yyval.str) = (yyvsp[0].str); }
#line 1558 "y.tab.c"
    break;

  case 14: /* b_for_fun: assgns  */
#line 138 "proiect.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 1564 "y.tab.c"
    break;

  case 15: /* b_for_fun: scnf  */
#line 141 "proiect.y"
         { (yyval.str) = (yyvsp[0].str); }
#line 1570 "y.tab.c"
    break;

  case 16: /* b_for_fun: prtf  */
#line 144 "proiect.y"
         { (yyval.str) = (yyvsp[0].str); }
#line 1576 "y.tab.c"
    break;

  case 17: /* b_for_fun: ifelse  */
#line 147 "proiect.y"
           {
        string s = string((yyvsp[0].str));
        // Inlocuieste toate newline-urile cu newline urmate de tab
        ReplaceAllOccurrences(s, string("\n"), string("\n"));
        // Inlocuieste "ELSEIF" urmat de tab cu "ALTFELIF"
        ReplaceAllOccurrences(s, string("\nELSEIF"), string("\nALTFELIF"));
        // Inlocuieste "ELSE" urmat de tab cu "ALTFEL"
        ReplaceAllOccurrences(s, string("\n\tELSE"), string("\nALTFEL"));
        // Elimina tab-urile care preced newline-urile
       // ReplaceAllOccurrences(s, string("\t\n"), string("\n")); 
        // Elimina liniile goale consecutive
        TrimSpaces(s); 
        if (s[0] == 'D') {
            // Adauga "SFARSIT DACA" la sfarsitul instructiunii daca incepe cu 'D'
            string a = "\nSFARSIT DACA";
            (yyval.str) = strdup((s + a).c_str());
        } else {
            (yyval.str) = strdup(s.c_str());
        }
    }
#line 1601 "y.tab.c"
    break;

  case 18: /* b_for_fun: forLoop  */
#line 169 "proiect.y"
            { (yyval.str) = (yyvsp[0].str); }
#line 1607 "y.tab.c"
    break;

  case 19: /* b_for_fun: whileLoop  */
#line 172 "proiect.y"
              { (yyval.str) = (yyvsp[0].str); }
#line 1613 "y.tab.c"
    break;

  case 20: /* b_for_fun: doWhile  */
#line 175 "proiect.y"
            { (yyval.str) = (yyvsp[0].str); }
#line 1619 "y.tab.c"
    break;

  case 26: /* parameter: VOID  */
#line 187 "proiect.y"
         { (yyval.str) = strdup(""); }
#line 1625 "y.tab.c"
    break;

  case 28: /* assgns: assgns assgn  */
#line 194 "proiect.y"
                 { (yyval.str) = strdup((string((yyvsp[-1].str)) + "\n" + string((yyvsp[0].str))).c_str()); }
#line 1631 "y.tab.c"
    break;

  case 29: /* assgns: assgn  */
#line 197 "proiect.y"
          { (yyval.str) = (yyvsp[0].str); }
#line 1637 "y.tab.c"
    break;

  case 30: /* assgn: assgn_type decl_body SEMICOLON  */
#line 202 "proiect.y"
                                   { (yyval.str) = (yyvsp[-1].str); }
#line 1643 "y.tab.c"
    break;

  case 31: /* assgn: assgn_type IDENT  */
#line 205 "proiect.y"
                     { (yyval.str) = (yyvsp[0].str); }
#line 1649 "y.tab.c"
    break;

  case 32: /* assgn: assgn_type IDENT COMMA assgn  */
#line 208 "proiect.y"
                                 { (yyval.str) = strdup((string((yyvsp[-2].str)) + " " + string((yyvsp[0].str))).c_str()); }
#line 1655 "y.tab.c"
    break;

  case 33: /* assgn: assgn_type IDENT COMMA decl_body SEMICOLON  */
#line 211 "proiect.y"
                                               { (yyval.str) = strdup((string((yyvsp[-1].str))).c_str()); }
#line 1661 "y.tab.c"
    break;

  case 34: /* assgn: IDENT EQ INTEGER SEMICOLON  */
#line 214 "proiect.y"
                               { (yyval.str) = strdup((string((yyvsp[-3].str)) + "=" + to_string((yyvsp[-1].number))).c_str()); }
#line 1667 "y.tab.c"
    break;

  case 35: /* assgn: IDENT EQ FLOATVAL SEMICOLON  */
#line 217 "proiect.y"
                                { (yyval.str) = strdup((string((yyvsp[-3].str)) + "=" + to_string((yyvsp[-1].doubflt))).c_str()); }
#line 1673 "y.tab.c"
    break;

  case 36: /* assgn: IDENT EQ CHARVAL SEMICOLON  */
#line 220 "proiect.y"
                               { (yyval.str) = strdup((string((yyvsp[-3].str)) + "=" + string((yyvsp[-1].str))).c_str()); }
#line 1679 "y.tab.c"
    break;

  case 37: /* assgn: IDENT EQ IDENT PLUS IDENT SEMICOLON  */
#line 223 "proiect.y"
                                        { (yyval.str) = strdup((string((yyvsp[-5].str)) + "=" + string((yyvsp[-3].str)) + "+" + string((yyvsp[-1].str))).c_str()); }
#line 1685 "y.tab.c"
    break;

  case 38: /* assgn: IDENT EQ IDENT PLUS INTEGER SEMICOLON  */
#line 226 "proiect.y"
                                          { (yyval.str) = strdup((string((yyvsp[-5].str)) + "=" + string((yyvsp[-3].str)) + "+" + to_string((yyvsp[-1].number))).c_str()); }
#line 1691 "y.tab.c"
    break;

  case 39: /* assgn: IDENT EQ IDENT MULTIPLICATION IDENT SEMICOLON  */
#line 229 "proiect.y"
                                                  { (yyval.str) = strdup((string((yyvsp[-5].str)) + "=" + string((yyvsp[-3].str)) + " mul " + string((yyvsp[-1].str))).c_str()); }
#line 1697 "y.tab.c"
    break;

  case 40: /* assgn: IDENT EQ IDENT MULTIPLICATION INTEGER SEMICOLON  */
#line 232 "proiect.y"
                                                    { (yyval.str) = strdup((string((yyvsp[-5].str)) + "=" + string((yyvsp[-3].str)) + " mul " + to_string((yyvsp[-1].number))).c_str()); }
#line 1703 "y.tab.c"
    break;

  case 41: /* assgn: IDENT EQ IDENT MINUS IDENT SEMICOLON  */
#line 235 "proiect.y"
                                         { (yyval.str) = strdup((string((yyvsp[-5].str)) + "=" + string((yyvsp[-3].str)) + "-" + string((yyvsp[-1].str))).c_str()); }
#line 1709 "y.tab.c"
    break;

  case 42: /* assgn: IDENT EQ IDENT MINUS INTEGER SEMICOLON  */
#line 238 "proiect.y"
                                           { (yyval.str) = strdup((string((yyvsp[-5].str)) + "=" + string((yyvsp[-3].str)) + "-" + to_string((yyvsp[-1].number))).c_str()); }
#line 1715 "y.tab.c"
    break;

  case 43: /* assgn: IDENT EQ IDENT DIVIDE IDENT SEMICOLON  */
#line 241 "proiect.y"
                                          { (yyval.str) = strdup((string((yyvsp[-5].str)) + "=" + string((yyvsp[-3].str)) + " div " + string((yyvsp[-1].str))).c_str()); }
#line 1721 "y.tab.c"
    break;

  case 44: /* assgn: IDENT EQ IDENT DIVIDE INTEGER SEMICOLON  */
#line 244 "proiect.y"
                                            { (yyval.str) = strdup((string((yyvsp[-5].str)) + "=" + string((yyvsp[-3].str)) + " div " + to_string((yyvsp[-1].number))).c_str()); }
#line 1727 "y.tab.c"
    break;

  case 45: /* assgn: IDENT EQ IDENT MODULO IDENT SEMICOLON  */
#line 247 "proiect.y"
                                          { (yyval.str) = strdup((string((yyvsp[-5].str)) + "=" + string((yyvsp[-3].str)) + " mod " + string((yyvsp[-1].str))).c_str()); }
#line 1733 "y.tab.c"
    break;

  case 46: /* assgn: IDENT EQ IDENT MODULO INTEGER SEMICOLON  */
#line 250 "proiect.y"
                                            { (yyval.str) = strdup((string((yyvsp[-5].str)) + "=" + string((yyvsp[-3].str)) + " mod " + to_string((yyvsp[-1].number))).c_str()); }
#line 1739 "y.tab.c"
    break;

  case 47: /* assgn: IDENT EQ call SEMICOLON  */
#line 253 "proiect.y"
                            { (yyval.str) = strdup((string((yyvsp[-3].str)) + "=" + string((yyvsp[-1].str))).c_str()); }
#line 1745 "y.tab.c"
    break;

  case 48: /* assgn: IDENT PLUSEQ INTEGER SEMICOLON  */
#line 256 "proiect.y"
                                   { (yyval.str) = strdup((string((yyvsp[-3].str)) + "+=" + to_string((yyvsp[-1].number))).c_str()); }
#line 1751 "y.tab.c"
    break;

  case 49: /* assgn: IDENT MINUSEQ INTEGER SEMICOLON  */
#line 259 "proiect.y"
                                    { (yyval.str) = strdup((string((yyvsp[-3].str)) + "-=" + to_string((yyvsp[-1].number))).c_str()); }
#line 1757 "y.tab.c"
    break;

  case 54: /* decl_body: IDENT EQ INTEGER  */
#line 270 "proiect.y"
                     { (yyval.str) = strdup((string((yyvsp[-2].str)) + "=" + to_string((yyvsp[0].number))).c_str()); }
#line 1763 "y.tab.c"
    break;

  case 55: /* decl_body: IDENT EQ FLOATVAL  */
#line 273 "proiect.y"
                      { (yyval.str) = strdup((string((yyvsp[-2].str)) + "=" + to_string((yyvsp[0].doubflt))).c_str()); }
#line 1769 "y.tab.c"
    break;

  case 56: /* decl_body: IDENT EQ CHARVAL  */
#line 276 "proiect.y"
                     { (yyval.str) = strdup((string((yyvsp[-2].str)) + "=" + string((yyvsp[0].str))).c_str()); }
#line 1775 "y.tab.c"
    break;

  case 57: /* decl_body: IDENT EQ INTEGER COMMA decl_body  */
#line 279 "proiect.y"
                                     { (yyval.str) = strdup((string((yyvsp[-4].str)) + "=" + to_string((yyvsp[-2].number)) + "\n" + string((yyvsp[0].str))).c_str()); }
#line 1781 "y.tab.c"
    break;

  case 58: /* decl_body: IDENT EQ FLOATVAL COMMA decl_body  */
#line 282 "proiect.y"
                                      { (yyval.str) = strdup((string((yyvsp[-4].str)) + "=" + to_string((yyvsp[-2].doubflt)) + "\n" + string((yyvsp[0].str))).c_str()); }
#line 1787 "y.tab.c"
    break;

  case 59: /* decl_body: IDENT EQ CHARVAL COMMA decl_body  */
#line 285 "proiect.y"
                                     { (yyval.str) = strdup((string((yyvsp[-4].str)) + "=" + string((yyvsp[-2].str)) + "\n" + string((yyvsp[0].str))).c_str()); }
#line 1793 "y.tab.c"
    break;

  case 60: /* decl_body: IDENT EQ IDENT COMMA decl_body  */
#line 288 "proiect.y"
                                   { (yyval.str) = strdup((string((yyvsp[-4].str)) + "=" + string((yyvsp[-2].str)) + "\n" + string((yyvsp[0].str))).c_str()); }
#line 1799 "y.tab.c"
    break;

  case 61: /* decl_body: IDENT EQ IDENT  */
#line 291 "proiect.y"
                   { (yyval.str) = strdup((string((yyvsp[-2].str)) + "=" + string((yyvsp[0].str))).c_str()); }
#line 1805 "y.tab.c"
    break;

  case 62: /* decl_body: IDENT  */
#line 294 "proiect.y"
          { (yyval.str) = strdup(""); }
#line 1811 "y.tab.c"
    break;

  case 63: /* ifelse: IF OPPARENTH IDENT comparetype identOrInt CLPARENTH OPENCURL b_for_funs CLOSECURL  */
#line 299 "proiect.y"
                                                                                      {
        string s = string("DACA") + " " + string((yyvsp[-6].str)) + " " + string((yyvsp[-5].str)) + " " + string((yyvsp[-4].str)) + " ATUNCI" + "\n" + string((yyvsp[-1].str));
        ReplaceAllOccurrences(s, string("\n"), string("\n\t"));
        (yyval.str) = strdup(s.c_str());
    }
#line 1821 "y.tab.c"
    break;

  case 64: /* ifelse: IF OPPARENTH IDENT comparetype identOrInt CLPARENTH OPENCURL CLOSECURL  */
#line 306 "proiect.y"
                                                                           {
        string s=(string("DACA ") + string((yyvsp[-5].str)) + " " + string((yyvsp[-4].str)) + " " + string((yyvsp[-3].str)) + string(" ATUNCI")).c_str();
        ReplaceAllOccurrences(s, string("\n"), string("\n\t"));
        (yyval.str) = strdup(s.c_str());
        
    }
#line 1832 "y.tab.c"
    break;

  case 65: /* ifelse: ELSE IF OPPARENTH IDENT comparetype identOrInt CLPARENTH OPENCURL b_for_funs CLOSECURL  */
#line 314 "proiect.y"
                                                                                           {
       string s=(string("\r\t\t\tALTFEL DACA ") + string((yyvsp[-6].str)) + " " + string((yyvsp[-5].str)) + " " + string((yyvsp[-4].str)) + " ATUNCI" + "\n" + string((yyvsp[-1].str))).c_str();
        (yyval.str) = strdup(s.c_str());
    }
#line 1841 "y.tab.c"
    break;

  case 66: /* ifelse: ELSE IF OPPARENTH IDENT comparetype identOrInt CLPARENTH OPENCURL CLOSECURL  */
#line 320 "proiect.y"
                                                                                {
        string s=(string("\r\t\t\tALTFEL DACA ") + string((yyvsp[-5].str)) + " " + string((yyvsp[-4].str)) + " " + string((yyvsp[-3].str)) + string(" ATUNCI")).c_str();
        (yyval.str) = strdup(s.c_str());
    }
#line 1850 "y.tab.c"
    break;

  case 67: /* ifelse: ELSE OPENCURL b_for_funs CLOSECURL  */
#line 326 "proiect.y"
                                       {
        string s=(string("\r\t\t\tALTFEL ") + string((yyvsp[-1].str))).c_str();
        (yyval.str) = strdup(s.c_str());
    }
#line 1859 "y.tab.c"
    break;

  case 68: /* ifelse: ELSE OPENCURL CLOSECURL  */
#line 332 "proiect.y"
                            {
        string s=(string("\r\t\t\tALTFEL ") + string("ATUNCI")).c_str();
        (yyval.str) = strdup(s.c_str());
    }
#line 1868 "y.tab.c"
    break;

  case 69: /* ifelse: IF OPPARENTH IDENT comparetype identOrInt CLPARENTH OPENCURL b_for_funs CLOSECURL ifelse  */
#line 338 "proiect.y"
                                                                                             {
        string s = string("DACA") + " " + string((yyvsp[-7].str)) + " " + string((yyvsp[-6].str)) + " " + string((yyvsp[-5].str)) + " ATUNCI" + "\n" + string((yyvsp[-2].str)) + "\n" + string((yyvsp[0].str));
        ReplaceAllOccurrences(s, string("\n"), string("\n\t"));
        (yyval.str) = strdup(s.c_str());
    }
#line 1878 "y.tab.c"
    break;

  case 70: /* ifelse: ELSE IF OPPARENTH IDENT comparetype identOrInt CLPARENTH OPENCURL b_for_funs CLOSECURL ifelse  */
#line 345 "proiect.y"
                                                                                                  {
        string s =(string("\r\t\t\tALTFEL DACA") + " " + string((yyvsp[-7].str)) + " " + string((yyvsp[-6].str)) + " " + string((yyvsp[-5].str)) + " ATUNCI" + "\n" + string((yyvsp[-2].str)) + "\n" + string((yyvsp[0].str))).c_str();
        (yyval.str) = strdup(s.c_str());
        
    }
#line 1888 "y.tab.c"
    break;

  case 71: /* forLoop: FOR OPPARENTH IDENT EQ INTEGER SEMICOLON IDENT comparetype INTEGER SEMICOLON IDENT incordec CLPARENTH OPENCURL b_for_funs CLOSECURL  */
#line 355 "proiect.y"
                                                                                                                                        {
        string a = "PENTRU " + string((yyvsp[-13].str)) + " ← " + to_string((yyvsp[-11].number)) + ", " + to_string((yyvsp[-7].number)) + " EXECUTA\n\t";
        string b = (yyvsp[-1].str);
        ReplaceAllOccurrences(b, string("\n"), string("\n\t"));
        string c = "\nSFARSIT PENTRU";
        (yyval.str) = strdup((a + b + c).c_str());
    }
#line 1900 "y.tab.c"
    break;

  case 72: /* forLoop: FOR OPPARENTH IDENT EQ INTEGER SEMICOLON IDENT comparetype IDENT SEMICOLON IDENT incordec CLPARENTH OPENCURL b_for_funs CLOSECURL  */
#line 364 "proiect.y"
                                                                                                                                      {
        string a = "PENTRU " + string((yyvsp[-13].str)) + " ← " + to_string((yyvsp[-11].number)) + ", " + string((yyvsp[-7].str)) + " EXECUTA\n\t";
        string b = (yyvsp[-1].str);
        ReplaceAllOccurrences(b, string("\n"), string("\n\t"));
        string c = "\nSFARSIT PENTRU";
        (yyval.str) = strdup((a + b + c).c_str());
    }
#line 1912 "y.tab.c"
    break;

  case 73: /* forLoop: FOR OPPARENTH IDENT EQ INTEGER SEMICOLON IDENT comparetype INTEGER SEMICOLON IDENT incordec CLPARENTH OPENCURL CLOSECURL  */
#line 373 "proiect.y"
                                                                                                                             {
        (yyval.str) = strdup(("PENTRU " + string((yyvsp[-12].str)) + " ← " + to_string((yyvsp[-10].number)) + ", " + to_string((yyvsp[-6].number)) + " EXECUTA\n\t").c_str());
    }
#line 1920 "y.tab.c"
    break;

  case 74: /* forLoop: FOR OPPARENTH IDENT EQ INTEGER SEMICOLON IDENT comparetype IDENT SEMICOLON IDENT incordec CLPARENTH OPENCURL CLOSECURL  */
#line 378 "proiect.y"
                                                                                                                           {
        (yyval.str) = strdup(("PENTRU " + string((yyvsp[-12].str)) + " ← " + to_string((yyvsp[-10].number)) + ", " + string((yyvsp[-6].str)) + " EXECUTA\n\t").c_str());
    }
#line 1928 "y.tab.c"
    break;

  case 75: /* whileLoop: WHILE OPPARENTH IDENT comparetype identOrInt CLPARENTH OPENCURL b_for_funs CLOSECURL  */
#line 385 "proiect.y"
                                                                                         {
        string s = string("CAT TIMP ") + string((yyvsp[-6].str)) + string((yyvsp[-5].str)) + string((yyvsp[-4].str)) + "\n" + string((yyvsp[-1].str)) + "\n\r\tSFARSIT CAT TIMP";
        ReplaceAllOccurrences(s, string("\n"), string("\n\t"));
        (yyval.str) = strdup(s.c_str());
    }
#line 1938 "y.tab.c"
    break;

  case 76: /* whileLoop: WHILE OPPARENTH IDENT comparetype identOrInt CLPARENTH OPENCURL CLOSECURL  */
#line 392 "proiect.y"
                                                                              {
        (yyval.str) = strdup((string("CAT TIMP ") + string((yyvsp[-5].str)) + string((yyvsp[-4].str)) + string((yyvsp[-3].str)) + "\b\nSFARSIT CAT TIMP").c_str());
    }
#line 1946 "y.tab.c"
    break;

  case 77: /* doWhile: DO OPENCURL b_for_funs CLOSECURL WHILE OPPARENTH IDENT comparetype identOrInt CLPARENTH SEMICOLON  */
#line 399 "proiect.y"
                                                                                                      {
        string s = string("REPETA\n") + string((yyvsp[-8].str)) + "\n\r\t\tCAT TIMP " + string((yyvsp[-4].str)) + string((yyvsp[-3].str)) + string((yyvsp[-2].str)) + "\n\r\t\tSFARSIT REPETA";
        ReplaceAllOccurrences(s, string("\n"), string("\n\t"));
        (yyval.str) = strdup(s.c_str());
    }
#line 1956 "y.tab.c"
    break;

  case 78: /* incordec: INCREMENT  */
#line 408 "proiect.y"
              { (yyval.str) = strdup("+"); }
#line 1962 "y.tab.c"
    break;

  case 79: /* incordec: DECREMENT  */
#line 411 "proiect.y"
              { (yyval.str) = strdup("-"); }
#line 1968 "y.tab.c"
    break;

  case 80: /* comparetype: GREATER  */
#line 416 "proiect.y"
            { (yyval.str) = strdup((string((yyvsp[0].str))).c_str()); }
#line 1974 "y.tab.c"
    break;

  case 81: /* comparetype: EQEQ  */
#line 419 "proiect.y"
         { (yyval.str) = strdup((string((yyvsp[0].str))).c_str()); }
#line 1980 "y.tab.c"
    break;

  case 82: /* comparetype: LESS  */
#line 422 "proiect.y"
         { (yyval.str) = strdup((string((yyvsp[0].str))).c_str()); }
#line 1986 "y.tab.c"
    break;

  case 83: /* comparetype: GREATEREQ  */
#line 425 "proiect.y"
              { (yyval.str) = strdup((string((yyvsp[0].str))).c_str()); }
#line 1992 "y.tab.c"
    break;

  case 84: /* comparetype: LESSEQ  */
#line 428 "proiect.y"
           { (yyval.str) = strdup((string((yyvsp[0].str))).c_str()); }
#line 1998 "y.tab.c"
    break;

  case 85: /* identOrInt: IDENT  */
#line 433 "proiect.y"
          { (yyval.str) = strdup((string((yyvsp[0].str))).c_str()); }
#line 2004 "y.tab.c"
    break;

  case 86: /* identOrInt: INTEGER  */
#line 436 "proiect.y"
            { (yyval.str) = strdup(to_string((yyvsp[0].number)).c_str()); }
#line 2010 "y.tab.c"
    break;

  case 87: /* call: IDENT OPPARENTH callBody CLPARENTH  */
#line 441 "proiect.y"
                                       { (yyval.str) = strdup((string((yyvsp[-3].str)) + " " + string((yyvsp[-1].str))).c_str()); }
#line 2016 "y.tab.c"
    break;

  case 88: /* call: IDENT OPPARENTH CLPARENTH  */
#line 444 "proiect.y"
                              { (yyval.str) = (yyvsp[-2].str); }
#line 2022 "y.tab.c"
    break;

  case 89: /* callBody: IDENT  */
#line 449 "proiect.y"
          { (yyval.str) = strdup((string((yyvsp[0].str))).c_str()); }
#line 2028 "y.tab.c"
    break;

  case 90: /* callBody: IDENT COMMA callBody  */
#line 452 "proiect.y"
                         { (yyval.str) = strdup((string((yyvsp[-2].str)) + " " + string((yyvsp[0].str))).c_str()); }
#line 2034 "y.tab.c"
    break;

  case 91: /* prtf: PRTF OPPARENTH QUOTES COMMA IDENT CLPARENTH SEMICOLON  */
#line 457 "proiect.y"
                                                          { (yyval.str) = strdup(("AFISEAZA " + string((yyvsp[-2].str))).c_str()); }
#line 2040 "y.tab.c"
    break;

  case 92: /* scnf: SCNF OPPARENTH QUOTES COMMA AND IDENT CLPARENTH SEMICOLON  */
#line 462 "proiect.y"
                                                              { (yyval.str) = strdup(("CITESTE " + string((yyvsp[-2].str))).c_str()); }
#line 2046 "y.tab.c"
    break;


#line 2050 "y.tab.c"

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

#line 465 "proiect.y"


void yyerror(const char* s){
    cout<<"eroare: "<<s<<endl;
}

int yywrap(){
    return 1;
}

int main(int argc, char *argv[])
{
    yyin=fopen(argv[1],"r");
    yyparse();
    fclose(yyin);
    return 0;
}

