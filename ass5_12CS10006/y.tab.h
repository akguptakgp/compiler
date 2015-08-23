/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     Auto = 258,
     Break = 259,
     Case = 260,
     Char_ = 261,
     Const = 262,
     Continue = 263,
     Default = 264,
     Do = 265,
     Double_ = 266,
     Else = 267,
     Enum = 268,
     Extern = 269,
     Float = 270,
     For = 271,
     Goto = 272,
     If = 273,
     Inline = 274,
     Int_ = 275,
     Long = 276,
     Register = 277,
     Restrict = 278,
     Return = 279,
     Short = 280,
     Signed = 281,
     Sizeof = 282,
     Static = 283,
     Struct = 284,
     Switch = 285,
     Typedef = 286,
     Union = 287,
     Unsigned = 288,
     Void_ = 289,
     Volatile = 290,
     While = 291,
     Bool = 292,
     Complex = 293,
     Imaginary = 294,
     identifier = 295,
     Int_Constant = 296,
     Floating_Const = 297,
     Enumeration_Constant = 298,
     Character_Constant = 299,
     string_literal = 300,
     P1 = 301,
     P2 = 302,
     P3 = 303,
     P4 = 304,
     P5 = 305,
     P6 = 306,
     P7 = 307,
     P8 = 308,
     P9 = 309,
     P10 = 310,
     P11 = 311,
     P12 = 312,
     P13 = 313,
     P14 = 314,
     P15 = 315,
     P16 = 316,
     P17 = 317,
     P18 = 318,
     P19 = 319,
     P20 = 320,
     P21 = 321,
     P22 = 322,
     P23 = 323,
     P24 = 324,
     P25 = 325,
     P26 = 326,
     P27 = 327,
     P28 = 328,
     P29 = 329,
     P30 = 330,
     P31 = 331,
     P32 = 332,
     P33 = 333,
     P34 = 334,
     P35 = 335,
     P36 = 336,
     P37 = 337,
     P38 = 338,
     P39 = 339,
     P40 = 340,
     P41 = 341,
     P42 = 342,
     P43 = 343,
     P44 = 344,
     P45 = 345,
     P46 = 346,
     P47 = 347
   };
#endif
/* Tokens.  */
#define Auto 258
#define Break 259
#define Case 260
#define Char_ 261
#define Const 262
#define Continue 263
#define Default 264
#define Do 265
#define Double_ 266
#define Else 267
#define Enum 268
#define Extern 269
#define Float 270
#define For 271
#define Goto 272
#define If 273
#define Inline 274
#define Int_ 275
#define Long 276
#define Register 277
#define Restrict 278
#define Return 279
#define Short 280
#define Signed 281
#define Sizeof 282
#define Static 283
#define Struct 284
#define Switch 285
#define Typedef 286
#define Union 287
#define Unsigned 288
#define Void_ 289
#define Volatile 290
#define While 291
#define Bool 292
#define Complex 293
#define Imaginary 294
#define identifier 295
#define Int_Constant 296
#define Floating_Const 297
#define Enumeration_Constant 298
#define Character_Constant 299
#define string_literal 300
#define P1 301
#define P2 302
#define P3 303
#define P4 304
#define P5 305
#define P6 306
#define P7 307
#define P8 308
#define P9 309
#define P10 310
#define P11 311
#define P12 312
#define P13 313
#define P14 314
#define P15 315
#define P16 316
#define P17 317
#define P18 318
#define P19 319
#define P20 320
#define P21 321
#define P22 322
#define P23 323
#define P24 324
#define P25 325
#define P26 326
#define P27 327
#define P28 328
#define P29 329
#define P30 330
#define P31 331
#define P32 332
#define P33 333
#define P34 334
#define P35 335
#define P36 336
#define P37 337
#define P38 338
#define P39 339
#define P40 340
#define P41 341
#define P42 342
#define P43 343
#define P44 344
#define P45 345
#define P46 346
#define P47 347



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2053 of yacc.c  */
#line 24 "ass5_12CS10006.y"

 char charval;                          // to store char value returned by lexer 
 int intval;				// to store intval value returned by lexer
 float floatval;			// to store floatval value returned by lexer
 char *stringval;			// to store stringval value returned by lexer
 SYMT_ROW *symp;			// data type of declaration etc.
					// to return (by lexer) pointer to entry corresponding to some identifer  			
 type_exp t_exp;                        // type of declaration specifiers 
 list_<SYMT_ROW*>* list_ptr;            // to store list of symbol table rows
 statemnt stmt;				// type of statements 
 symtable* symtp;                       // pointer to symbol type to store symbol tabel of a function
 expression exp;                        // types of expression having two fields one boolex for boolean ex. and symbol table
                                        //  row pointer for arithemic expressions  


/* Line 2053 of yacc.c  */
#line 257 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
