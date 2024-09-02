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

#line 167 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
