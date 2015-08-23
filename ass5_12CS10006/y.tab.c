/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 7 "ass5_12CS10006.y"
 
 #include <string.h>                    // for string library functions like strdup         
 #include "ass5_12CS10006_translator.h" // for symbol table and quadarray data type and member function implementation
 extern int yylex();                    // to be called by yyparse()
 void yyerror(char *s);                 // to throw symtex error 
 extern int no_lines;                   // to keep count of number of lines parsed so that can be used while throwing syntex error 
 symtable ST_gl;                        //global symbol table declaration
 symtable* ST_funt=&ST_gl;		//current symbol table pointer declaration for lookup in current function's symbol table  					        //initilized with global symbol table
 qArray qarr;			        //quad array declaration
 bool flag=false;                        // to check whether certain identifier already existed before lookup
					// in a particular symbol tabel will be set during lookup call
 int pointer_no;			// number of times * has occured while pointer declaration

/* Line 371 of yacc.c  */
#line 82 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
/* Line 387 of yacc.c  */
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


/* Line 387 of yacc.c  */
#line 325 "y.tab.c"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 353 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1079

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  202
/* YYNRULES -- Number of states.  */
#define YYNSTATES  358

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   347

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    13,    15,    20,    25,
      29,    33,    37,    40,    43,    50,    58,    60,    64,    66,
      69,    72,    75,    79,    82,    85,    88,    91,    94,    99,
     101,   106,   108,   112,   116,   120,   122,   126,   130,   132,
     136,   140,   142,   146,   150,   154,   158,   160,   164,   168,
     170,   174,   176,   181,   183,   187,   188,   189,   191,   196,
     198,   203,   205,   215,   217,   221,   223,   225,   227,   229,
     231,   233,   235,   237,   239,   241,   243,   245,   249,   251,
     253,   255,   257,   259,   263,   266,   268,   269,   272,   275,
     278,   281,   283,   285,   289,   291,   295,   297,   299,   301,
     303,   305,   307,   309,   311,   313,   315,   317,   319,   321,
     323,   325,   327,   329,   331,   332,   335,   338,   340,   341,
     347,   354,   357,   359,   363,   365,   369,   371,   373,   375,
     377,   379,   380,   383,   387,   390,   392,   393,   395,   396,
     398,   404,   409,   413,   417,   424,   431,   437,   439,   442,
     444,   448,   450,   454,   457,   459,   461,   463,   467,   472,
     474,   475,   478,   483,   486,   488,   491,   495,   498,   500,
     502,   504,   506,   508,   510,   514,   519,   523,   525,   526,
     530,   532,   536,   538,   540,   542,   543,   546,   553,   564,
     570,   579,   589,   604,   613,   617,   620,   623,   627,   629,
     632,   634,   636
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     161,     0,    -1,    40,    -1,   116,    -1,    45,    -1,    69,
     114,    70,    -1,    94,    -1,    95,    67,   114,    68,    -1,
      95,    69,    96,    70,    -1,    95,    69,    70,    -1,    95,
      73,    40,    -1,    95,    74,    40,    -1,    95,    75,    -1,
      95,    76,    -1,    69,   143,    70,    71,   146,    72,    -1,
      69,   143,    70,    71,   146,    91,    72,    -1,   112,    -1,
      96,    91,   112,    -1,    95,    -1,    75,    97,    -1,    76,
      97,    -1,    61,    98,    -1,    62,   107,    98,    -1,    63,
      98,    -1,    64,    98,    -1,    65,    98,    -1,    66,    98,
      -1,    27,    97,    -1,    27,    69,   143,    70,    -1,    97,
      -1,    69,   143,    70,    98,    -1,    98,    -1,    99,    62,
      98,    -1,    99,    77,    98,    -1,    99,    78,    98,    -1,
      99,    -1,   100,    63,    99,    -1,   100,    64,    99,    -1,
     100,    -1,   101,    79,   100,    -1,   101,    80,   100,    -1,
     101,    -1,   102,    81,   101,    -1,   102,    82,   101,    -1,
     102,    46,   101,    -1,   102,    47,   101,    -1,   102,    -1,
     103,    48,   102,    -1,   103,    49,   102,    -1,   103,    -1,
     104,    61,   103,    -1,   104,    -1,   105,    83,   107,   104,
      -1,   105,    -1,   106,    84,   105,    -1,    -1,    -1,   106,
      -1,   109,    85,   107,   106,    -1,   109,    -1,   110,    86,
     107,   109,    -1,   110,    -1,   110,   108,    87,   107,   114,
     108,    88,   107,   111,    -1,   111,    -1,    97,   113,   112,
      -1,    50,    -1,    51,    -1,    52,    -1,    53,    -1,    54,
      -1,    55,    -1,    56,    -1,    57,    -1,    58,    -1,    59,
      -1,    60,    -1,   112,    -1,   114,    91,   112,    -1,   111,
      -1,    41,    -1,    42,    -1,    43,    -1,    44,    -1,   119,
     120,    89,    -1,   119,    89,    -1,   119,    -1,    -1,   123,
     118,    -1,   124,   118,    -1,   131,   118,    -1,   132,   118,
      -1,   121,    -1,   122,    -1,   121,    91,   122,    -1,   135,
      -1,   135,    50,   144,    -1,    14,    -1,    28,    -1,     3,
      -1,    22,    -1,    34,    -1,     6,    -1,    25,    -1,    20,
      -1,    21,    -1,    15,    -1,    11,    -1,    26,    -1,    33,
      -1,    37,    -1,    38,    -1,    39,    -1,   128,    -1,   126,
      -1,    -1,   124,   125,    -1,   131,   125,    -1,    40,    -1,
      -1,    13,   127,    71,   129,    72,    -1,    13,   127,    71,
     129,    91,    72,    -1,    13,    40,    -1,   130,    -1,   129,
      91,   130,    -1,    43,    -1,    43,    50,   115,    -1,     7,
      -1,    23,    -1,    35,    -1,    19,    -1,   134,    -1,    -1,
      62,   136,    -1,    62,   136,   134,    -1,   133,   138,    -1,
     139,    -1,    -1,   112,    -1,    -1,    40,    -1,   138,    67,
     136,   137,    68,    -1,   138,    69,   140,    70,    -1,   138,
      69,    70,    -1,    69,   135,    70,    -1,   138,    67,    28,
     136,   112,    68,    -1,   138,    67,   139,    28,   112,    68,
      -1,   138,    67,   136,    62,    68,    -1,   131,    -1,   139,
     131,    -1,   141,    -1,   141,    91,    90,    -1,   142,    -1,
     141,    91,   142,    -1,   119,   135,    -1,   119,    -1,   126,
      -1,   112,    -1,    71,   146,    72,    -1,    71,   146,    91,
      72,    -1,   147,    -1,    -1,   145,   144,    -1,   146,    91,
     145,   144,    -1,   148,    50,    -1,   149,    -1,   148,   149,
      -1,    67,   115,    68,    -1,    73,    40,    -1,   151,    -1,
     153,    -1,   157,    -1,   158,    -1,   159,    -1,   160,    -1,
      40,    88,   150,    -1,     5,   115,    88,   150,    -1,     9,
      88,   150,    -1,   154,    -1,    -1,    71,   152,    72,    -1,
     155,    -1,   154,   107,   155,    -1,   117,    -1,   150,    -1,
     114,    -1,    -1,   156,    89,    -1,    18,    69,   114,    70,
     107,   150,    -1,    18,    69,   114,    70,   107,   150,   108,
      12,   107,   150,    -1,    30,    69,   114,    70,   150,    -1,
      36,   108,   107,    69,   114,    70,   107,   150,    -1,    10,
     107,   150,   107,    36,    69,   114,    70,    89,    -1,    16,
      69,   156,    89,   107,   108,   156,    89,   107,   156,   108,
      70,   107,   150,    -1,    16,    69,   117,   156,    89,   156,
      70,   150,    -1,    17,    40,    89,    -1,     8,    89,    -1,
       4,    89,    -1,    24,   156,    89,    -1,   162,    -1,   161,
     162,    -1,   163,    -1,   117,    -1,   119,   135,   153,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   224,   224,   225,   226,   232,   239,   240,   263,   285,
     292,   293,   294,   301,   308,   309,   313,   314,   319,   320,
     327,   334,   341,   350,   351,   358,   364,   370,   371,   375,
     376,   380,   381,   395,   409,   426,   427,   441,   457,   458,
     464,   471,   472,   481,   492,   501,   512,   513,   522,   533,
     534,   542,   543,   577,   578,   585,   586,   588,   589,   601,
     602,   614,   615,   636,   637,   682,   682,   682,   682,   682,
     682,   682,   682,   682,   682,   682,   686,   687,   689,   693,
     700,   707,   708,   722,   744,   748,   749,   752,   753,   754,
     755,   759,   763,   767,   774,   775,   794,   795,   796,   797,
     800,   801,   802,   803,   804,   805,   806,   807,   808,   809,
     810,   811,   812,   816,   817,   820,   821,   824,   825,   828,
     829,   830,   833,   834,   837,   838,   841,   842,   843,   846,
     849,   850,   853,   854,   857,   873,   874,   877,   878,   885,
     886,   891,   899,   905,   906,   907,   908,   911,   912,   915,
     916,   919,   932,   950,   973,   981,   984,   985,   986,   989,
     990,   993,   994,   997,  1000,  1001,  1004,  1005,  1009,  1010,
    1011,  1012,  1013,  1014,  1017,  1018,  1019,  1022,  1024,  1027,
    1030,  1031,  1034,  1035,  1038,  1039,  1042,  1050,  1069,  1076,
    1079,  1094,  1116,  1145,  1148,  1149,  1150,  1151,  1160,  1161,
    1164,  1165,  1169
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Auto", "Break", "Case", "Char_",
  "Const", "Continue", "Default", "Do", "Double_", "Else", "Enum",
  "Extern", "Float", "For", "Goto", "If", "Inline", "Int_", "Long",
  "Register", "Restrict", "Return", "Short", "Signed", "Sizeof", "Static",
  "Struct", "Switch", "Typedef", "Union", "Unsigned", "Void_", "Volatile",
  "While", "Bool", "Complex", "Imaginary", "identifier", "Int_Constant",
  "Floating_Const", "Enumeration_Constant", "Character_Constant",
  "string_literal", "P1", "P2", "P3", "P4", "P5", "P6", "P7", "P8", "P9",
  "P10", "P11", "P12", "P13", "P14", "P15", "P16", "P17", "P18", "P19",
  "P20", "P21", "P22", "P23", "P24", "P25", "P26", "P27", "P28", "P29",
  "P30", "P31", "P32", "P33", "P34", "P35", "P36", "P37", "P38", "P39",
  "P40", "P41", "P42", "P43", "P44", "P45", "P46", "P47", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "cast_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "AND_expression", "exclusive_OR_expression",
  "inclusive_OR_expression", "M", "N", "logical_AND_expression",
  "logical_OR_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "Constant_expression", "Constant", "declaration",
  "declaration_specifiers_opt", "declaration_specifiers",
  "init_declarator_list_opt", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier",
  "specifier_qualifier_list_opt", "specifier_qualifier_list",
  "identifier_opt", "Enum_specifier", "Enumerator_list", "Enumerator",
  "type_qualifier", "function_specifier", "pointer_opt", "pointer",
  "declarator", "type_qualifier_list_opt", "assignment_expression_opt",
  "direct_declarator", "type_qualifier_list", "parameter_type_list",
  "parameter_list", "parameter_declaration", "type_name", "initializer",
  "designation_opt", "initializer_list", "designation", "designator_list",
  "designator", "statement", "labeled_statement", "block_item_list_opt",
  "compound_statement", "block_item_list", "block_item", "expression_opt",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "External_declaration",
  "function_definition", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    93,    94,    94,    94,    94,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    96,    96,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    98,
      98,    99,    99,    99,    99,   100,   100,   100,   101,   101,
     101,   102,   102,   102,   102,   102,   103,   103,   103,   104,
     104,   105,   105,   106,   106,   107,   108,   109,   109,   110,
     110,   111,   111,   112,   112,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   114,   114,   115,   116,
     116,   116,   116,   117,   117,   118,   118,   119,   119,   119,
     119,   120,   121,   121,   122,   122,   123,   123,   123,   123,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   125,   125,   126,   126,   127,   127,   128,
     128,   128,   129,   129,   130,   130,   131,   131,   131,   132,
     133,   133,   134,   134,   135,   136,   136,   137,   137,   138,
     138,   138,   138,   138,   138,   138,   138,   139,   139,   140,
     140,   141,   141,   142,   142,   143,   144,   144,   144,   145,
     145,   146,   146,   147,   148,   148,   149,   149,   150,   150,
     150,   150,   150,   150,   151,   151,   151,   152,   152,   153,
     154,   154,   155,   155,   156,   156,   157,   158,   158,   158,
     159,   159,   159,   159,   160,   160,   160,   160,   161,   161,
     162,   162,   163
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     4,     3,
       3,     3,     2,     2,     6,     7,     1,     3,     1,     2,
       2,     2,     3,     2,     2,     2,     2,     2,     4,     1,
       4,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     4,     1,     3,     0,     0,     1,     4,     1,
       4,     1,     9,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     3,     2,     1,     0,     2,     2,     2,
       2,     1,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     2,     2,     1,     0,     5,
       6,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     0,     2,     3,     2,     1,     0,     1,     0,     1,
       5,     4,     3,     3,     6,     6,     5,     1,     2,     1,
       3,     1,     3,     2,     1,     1,     1,     3,     4,     1,
       0,     2,     4,     2,     1,     2,     3,     2,     1,     1,
       1,     1,     1,     1,     3,     4,     3,     1,     0,     3,
       1,     3,     1,     1,     1,     0,     2,     6,    10,     5,
       8,     9,    14,     8,     3,     2,     2,     3,     1,     2,
       1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    98,   101,   126,   106,   118,    96,   105,   129,   103,
     104,    99,   127,   102,   107,    97,   108,   100,   128,   109,
     110,   111,   201,   131,    86,    86,   112,    86,    86,     0,
     198,   200,   121,     0,   136,    84,     0,    91,    92,     0,
     130,    94,    87,    85,    88,    89,    90,     1,   199,     0,
     147,   132,   135,    83,   131,   139,   131,   134,     0,   178,
     202,   124,     0,   122,   133,   148,    93,    94,     0,   136,
       0,     0,     2,    79,    80,    81,    82,     4,     0,    55,
       0,     0,     0,     0,     0,   160,     0,     0,     6,    18,
      29,    31,    35,    38,    41,    46,    49,    51,    53,    57,
      59,    61,    63,   156,     3,    95,     0,     0,     0,     0,
      55,     0,     0,     0,   185,     0,    56,     2,    76,   184,
     182,   131,   183,   168,     0,   169,    55,   180,     0,   170,
     171,   172,   173,     0,   119,     0,   143,   136,   138,   135,
     142,   131,     0,   149,   151,     0,    27,    29,    21,     0,
      23,    24,    25,    26,     0,   114,   155,   114,     0,     0,
       0,     0,     0,   159,     0,   164,     0,    19,    20,     0,
       0,     0,     0,    12,    13,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,    55,    55,     0,   196,    78,     0,   195,
     185,   185,   185,     0,     0,     0,     0,    55,   185,     0,
     179,   185,   186,   125,   120,   123,     0,    55,   137,     0,
       0,   153,   141,     0,     0,    22,     5,   115,   113,   116,
       0,     0,   167,   161,   157,   160,   163,   165,     0,     0,
       9,     0,    16,    10,    11,    64,    32,    33,    34,    36,
      37,    39,    40,    44,    45,    42,    43,    47,    48,    50,
       0,    54,     0,     0,    55,   185,   176,    55,   185,     0,
     194,     0,   197,     0,     0,   174,    77,   181,     0,   146,
     140,     0,   150,   152,    28,   160,    30,   166,   158,     0,
       0,     7,     8,     0,    52,    58,    60,     0,   175,     0,
       0,    55,    55,   185,     0,   144,   145,     0,   162,    17,
      56,     0,   185,    56,   185,   189,     0,    14,   160,     0,
       0,     0,   185,   187,    55,    15,    55,     0,   185,     0,
       0,   185,     0,     0,   193,    55,    55,   190,    62,   191,
     185,   185,    56,   188,     0,    55,   185,   192
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    88,    89,   251,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   149,   205,   100,   101,   102,   118,
     186,   119,   208,   104,    22,    42,    43,    36,    37,    38,
      24,    25,   237,   156,    33,    26,    62,    63,    27,    28,
      39,    40,    67,    51,   229,    57,    52,   142,   143,   144,
     158,   105,   161,   162,   163,   164,   165,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    29,    30,
      31
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -233
static const yytype_int16 yypact[] =
{
    1006,  -233,  -233,  -233,  -233,   -14,  -233,  -233,  -233,  -233,
    -233,  -233,  -233,  -233,  -233,  -233,  -233,  -233,  -233,  -233,
    -233,  -233,  -233,   -41,  1006,  1006,  -233,  1006,  1006,   969,
    -233,  -233,   -30,     6,    37,  -233,    -9,   -56,  -233,   -12,
    -233,    -5,  -233,  -233,  -233,  -233,  -233,  -233,  -233,    47,
    -233,    53,    37,  -233,    53,  -233,    53,    41,   662,   320,
    -233,   102,    14,  -233,  -233,  -233,  -233,   114,   107,    26,
     660,   782,  -233,  -233,  -233,  -233,  -233,  -233,   822,  -233,
     822,   822,   822,   822,   593,   -36,   862,   862,  -233,   111,
     393,  -233,   120,    87,    60,   -23,    54,   129,    98,   119,
     133,   108,  -233,  -233,  -233,  -233,   123,   822,   131,   134,
    -233,   152,   184,   157,   822,   160,  -233,   143,  -233,   142,
    -233,   -41,  -233,  -233,   163,  -233,   169,  -233,   147,  -233,
    -233,  -233,  -233,   822,  -233,   -16,  -233,    37,   902,    78,
    -233,   -45,   174,   154,  -233,   593,  -233,  -233,  -233,   822,
    -233,  -233,  -233,  -233,    13,  1040,  -233,  1040,   176,   822,
     207,   662,    75,  -233,   -20,  -233,   593,  -233,  -233,   822,
     702,   210,   211,  -233,  -233,  -233,  -233,  -233,  -233,  -233,
    -233,  -233,  -233,  -233,  -233,  -233,   822,   822,   822,   822,
     822,   822,   822,   822,   822,   822,   822,   822,   822,   822,
     822,  -233,   822,  -233,  -233,   165,  -233,  -233,   166,  -233,
     527,   527,   464,   167,   822,   168,   822,  -233,   527,   822,
    -233,   397,  -233,  -233,  -233,  -233,   822,   185,  -233,   190,
     822,  -233,  -233,   283,   189,  -233,  -233,  -233,  -233,  -233,
     742,   192,  -233,  -233,  -233,   -33,  -233,  -233,   191,     3,
    -233,    23,  -233,  -233,  -233,  -233,  -233,  -233,  -233,   120,
     120,    87,    87,    60,    60,    60,    60,   -23,   -23,    54,
     822,    98,   822,   822,  -233,   527,  -233,  -233,   822,   173,
    -233,    39,  -233,    63,   194,  -233,  -233,  -233,   197,  -233,
    -233,   199,  -233,  -233,   198,   -36,  -233,  -233,  -233,   662,
     198,  -233,  -233,   822,   129,   119,   133,   822,  -233,   232,
     181,  -233,  -233,   527,   822,  -233,  -233,    81,  -233,  -233,
     142,   205,   822,  -233,   527,  -233,    68,  -233,    76,   187,
     822,   206,   822,   266,  -233,  -233,  -233,    71,   527,   196,
     267,   527,   822,   202,  -233,  -233,  -233,  -233,  -233,  -233,
     822,   527,  -233,  -233,   213,  -233,   527,  -233
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -233,  -233,  -233,  -233,   -71,   -13,    17,    24,  -121,    16,
      80,    11,    85,    20,  -106,  -110,    15,  -233,  -104,   -26,
    -233,   -82,   -95,  -233,   -54,   164,    22,  -233,  -233,   241,
    -233,   -66,   144,     0,  -233,  -233,  -233,   172,   127,  -233,
    -233,   248,    -4,   -55,  -233,  -233,   231,  -233,  -233,    77,
      -3,  -153,  -232,    18,  -233,  -233,   148,  -168,  -233,  -233,
     273,  -233,    94,  -113,  -233,  -233,  -233,  -233,  -233,   290,
    -233
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -186
static const yytype_int16 yytable[] =
{
     146,   215,   154,   207,   211,   120,   217,   147,   243,   147,
     147,   147,   147,   299,   138,   167,   168,    34,   155,    41,
     221,    34,    23,   194,   195,  -154,    32,    61,    55,   207,
     246,   159,   103,     3,   159,    54,   147,   160,   223,   298,
     160,  -117,   276,   277,     3,    58,  -154,   159,    35,    12,
     285,    23,    68,   160,   137,   207,   224,    56,   196,   197,
      12,    18,   147,   154,   241,   148,    59,   150,   151,   152,
     153,   301,    18,   263,   264,   265,   266,    49,   147,   155,
      53,   121,   226,   236,   154,     3,   134,   249,   147,   155,
      61,   155,   141,   302,   219,   270,   299,   272,   273,   279,
     155,    12,   198,   199,   219,   135,   230,   308,    69,   312,
      70,   284,   228,    18,   303,    34,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     219,   147,   281,   313,   283,   103,   235,   231,   334,   192,
     193,   343,   234,   159,   252,   325,   318,   244,   335,   160,
     190,   191,   133,   327,   219,   238,   333,   238,   278,   219,
     255,    50,   219,   248,    58,   310,   245,   120,   307,   147,
     344,   309,   328,   347,   256,   257,   258,   136,   169,    65,
     170,   201,   187,   353,   171,   172,   173,   174,   357,    44,
     200,    45,    46,   286,   204,   -56,    50,   188,   189,   147,
     288,   147,   147,   202,   291,   323,   324,   259,   260,   331,
     329,   157,   206,   332,   267,   268,   261,   262,   203,   339,
     209,   212,   210,   340,   213,   320,   214,   296,   341,   216,
     342,   218,   326,   219,   121,   220,   222,   352,   348,   350,
     351,  -177,   354,   121,   232,   233,   240,   242,   337,   356,
     253,   254,   274,   289,   275,   141,   280,   282,   290,   294,
     297,   300,   311,   314,    50,   315,    65,   316,   321,   295,
     322,   147,   157,   103,   330,   336,   338,   319,   -56,   346,
     269,   304,   157,   355,   157,   345,     1,   271,   306,     2,
       3,   349,   305,   157,     4,    66,     5,     6,     7,    64,
     139,   239,     8,     9,    10,    11,    12,   225,    13,    14,
     293,    15,   247,   317,    60,   287,    16,    17,    18,    48,
      19,    20,    21,     1,   106,   107,     2,     3,   108,   109,
     110,     4,     0,     5,     6,     7,   111,   112,   113,     8,
       9,    10,    11,    12,   114,    13,    14,    71,    15,     0,
     115,     0,     0,    16,    17,    18,   116,    19,    20,    21,
     117,    73,    74,    75,    76,    77,     0,     0,     0,     0,
       0,     0,     0,   292,     0,     0,     0,     0,     0,     0,
       0,    78,    79,    80,    81,    82,    83,     0,     0,    84,
       0,    59,     0,     0,     0,    86,    87,     0,     0,     0,
       1,   106,   107,     2,     3,   108,   109,   110,     4,  -185,
       5,     6,     7,   111,   112,   113,     8,     9,    10,    11,
      12,   114,    13,    14,    71,    15,     0,   115,     0,     0,
      16,    17,    18,   116,    19,    20,    21,   117,    73,    74,
      75,    76,    77,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,     0,     0,     0,     0,    78,    79,
      80,    81,    82,    83,     0,     0,    84,     1,    59,     0,
       2,     3,    86,    87,     0,     4,     0,     5,     6,     7,
       0,     0,     0,     8,     9,    10,    11,    12,     0,    13,
      14,    71,    15,     0,     0,     0,     0,    16,    17,    18,
       0,    19,    20,    21,    72,    73,    74,    75,    76,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,    79,    80,    81,    82,
      83,   106,   107,    84,     0,   108,   109,   110,     0,    86,
      87,     0,     0,   111,   112,   113,     0,     0,     0,     0,
       0,   114,     0,     0,    71,     0,     0,   115,     0,     0,
       0,     0,     0,   116,     0,     0,     0,   117,    73,    74,
      75,    76,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,    79,
      80,    81,    82,    83,     0,     0,    84,     0,    59,     2,
       3,     0,    86,    87,     4,     0,     5,     0,     7,     0,
       0,     0,     0,     9,    10,     0,    12,     0,    13,    14,
      71,     0,     0,     0,     0,     0,    16,    17,    18,     0,
      19,    20,    21,    72,    73,    74,    75,    76,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    78,    79,    80,    81,    82,    83,
       0,     0,    84,     1,     0,     0,     2,     3,    86,    87,
       0,     4,     0,     5,     6,     7,     0,     0,     0,     8,
       9,    10,    11,    12,     0,    13,    14,     0,    15,    71,
       0,     0,     0,    16,    17,    18,     0,    19,    20,    21,
       0,     0,    72,    73,    74,    75,    76,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    71,
     140,    84,     0,    85,     0,     0,     0,    86,    87,     0,
       0,     0,    72,    73,    74,    75,    76,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    71,
       0,    84,   250,     0,     0,     0,     0,    86,    87,     0,
       0,     0,    72,    73,    74,    75,    76,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    71,
       0,    84,     0,   295,     0,     0,     0,    86,    87,     0,
       0,     0,    72,    73,    74,    75,    76,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    71,
       0,   145,     0,     0,     0,     0,     0,    86,    87,     0,
       0,     0,    72,    73,    74,    75,    76,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    71,
       0,    84,     0,     0,     0,     0,     0,    86,    87,     0,
       0,     0,    72,    73,    74,    75,    76,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    71,
       0,   166,     0,     0,     0,     0,     0,    86,    87,     0,
       0,     0,    72,    73,    74,    75,    76,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,   227,    80,    81,    82,    83,    47,
       0,    84,     1,     0,     0,     2,     3,    86,    87,     0,
       4,     0,     5,     6,     7,     0,     0,     0,     8,     9,
      10,    11,    12,     0,    13,    14,     0,    15,     0,     0,
       0,     0,    16,    17,    18,     0,    19,    20,    21,     1,
       0,     0,     2,     3,     0,     0,     0,     4,     0,     5,
       6,     7,     0,     0,     0,     8,     9,    10,    11,    12,
       0,    13,    14,     0,    15,     0,     0,     0,     0,    16,
      17,    18,     0,    19,    20,    21,     2,     3,     0,     0,
       0,     4,     0,     5,     0,     7,     0,     0,     0,     0,
       9,    10,     0,    12,     0,    13,    14,     0,     0,     0,
       0,     0,     0,    16,    17,    18,     0,    19,    20,    21
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-233)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      71,   114,    84,   107,   110,    59,   116,    78,   161,    80,
      81,    82,    83,   245,    69,    86,    87,    62,    84,    23,
     126,    62,     0,    46,    47,    70,    40,    43,    40,   133,
      50,    67,    58,     7,    67,    91,   107,    73,   133,    72,
      73,    71,   210,   211,     7,    50,    91,    67,    89,    23,
     218,    29,    56,    73,    28,   159,    72,    69,    81,    82,
      23,    35,   133,   145,   159,    78,    71,    80,    81,    82,
      83,    68,    35,   194,   195,   196,   197,    71,   149,   145,
      89,    59,   137,    70,   166,     7,    72,   169,   159,   155,
      43,   157,    70,    70,    91,   201,   328,   203,   204,   212,
     166,    23,    48,    49,    91,    91,    28,   275,    67,    70,
      69,   217,   138,    35,    91,    62,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
      91,   202,   214,    70,   216,   161,   149,   141,    70,    79,
      80,    70,   145,    67,   170,   313,   299,    72,    72,    73,
      63,    64,    50,    72,    91,   155,   324,   157,   212,    91,
     186,    34,    91,   166,    50,   278,    91,   221,   274,   240,
     338,   277,    91,   341,   187,   188,   189,    70,    67,    52,
      69,    83,    62,   351,    73,    74,    75,    76,   356,    25,
      61,    27,    28,   219,    86,    87,    69,    77,    78,   270,
     226,   272,   273,    84,   230,   311,   312,   190,   191,   322,
     320,    84,    89,   323,   198,   199,   192,   193,    85,   332,
      89,    69,    88,   333,    40,   307,    69,   240,   334,    69,
     336,    88,   314,    91,   212,    72,    89,   350,   342,   345,
     346,    72,   352,   221,    70,    91,    70,    40,   330,   355,
      40,    40,    87,    68,    88,   233,    89,    89,    68,    70,
      68,    70,    89,    69,   137,    68,   139,    68,    36,    71,
      89,   342,   145,   299,    69,    88,    70,   303,    12,    12,
     200,   270,   155,    70,   157,    89,     3,   202,   273,     6,
       7,    89,   272,   166,    11,    54,    13,    14,    15,    51,
      69,   157,    19,    20,    21,    22,    23,   135,    25,    26,
     233,    28,   164,   295,    41,   221,    33,    34,    35,    29,
      37,    38,    39,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    -1,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    62,    63,    64,    65,    66,    -1,    -1,    69,
      -1,    71,    -1,    -1,    -1,    75,    76,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    89,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    -1,    -1,    -1,    61,    62,
      63,    64,    65,    66,    -1,    -1,    69,     3,    71,    -1,
       6,     7,    75,    76,    -1,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    -1,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    33,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,
      66,     4,     5,    69,    -1,     8,     9,    10,    -1,    75,
      76,    -1,    -1,    16,    17,    18,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    27,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      63,    64,    65,    66,    -1,    -1,    69,    -1,    71,     6,
       7,    -1,    75,    76,    11,    -1,    13,    -1,    15,    -1,
      -1,    -1,    -1,    20,    21,    -1,    23,    -1,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,    66,
      -1,    -1,    69,     3,    -1,    -1,     6,     7,    75,    76,
      -1,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    -1,    25,    26,    -1,    28,    27,
      -1,    -1,    -1,    33,    34,    35,    -1,    37,    38,    39,
      -1,    -1,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    64,    65,    66,    27,
      70,    69,    -1,    71,    -1,    -1,    -1,    75,    76,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    64,    65,    66,    27,
      -1,    69,    70,    -1,    -1,    -1,    -1,    75,    76,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    64,    65,    66,    27,
      -1,    69,    -1,    71,    -1,    -1,    -1,    75,    76,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    64,    65,    66,    27,
      -1,    69,    -1,    -1,    -1,    -1,    -1,    75,    76,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    64,    65,    66,    27,
      -1,    69,    -1,    -1,    -1,    -1,    -1,    75,    76,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    64,    65,    66,    27,
      -1,    69,    -1,    -1,    -1,    -1,    -1,    75,    76,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    64,    65,    66,     0,
      -1,    69,     3,    -1,    -1,     6,     7,    75,    76,    -1,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    -1,    25,    26,    -1,    28,    -1,    -1,
      -1,    -1,    33,    34,    35,    -1,    37,    38,    39,     3,
      -1,    -1,     6,     7,    -1,    -1,    -1,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      -1,    25,    26,    -1,    28,    -1,    -1,    -1,    -1,    33,
      34,    35,    -1,    37,    38,    39,     6,     7,    -1,    -1,
      -1,    11,    -1,    13,    -1,    15,    -1,    -1,    -1,    -1,
      20,    21,    -1,    23,    -1,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    -1,    37,    38,    39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,    11,    13,    14,    15,    19,    20,
      21,    22,    23,    25,    26,    28,    33,    34,    35,    37,
      38,    39,   117,   119,   123,   124,   128,   131,   132,   161,
     162,   163,    40,   127,    62,    89,   120,   121,   122,   133,
     134,   135,   118,   119,   118,   118,   118,     0,   162,    71,
     131,   136,   139,    89,    91,    40,    69,   138,    50,    71,
     153,    43,   129,   130,   134,   131,   122,   135,   135,    67,
      69,    27,    40,    41,    42,    43,    44,    45,    61,    62,
      63,    64,    65,    66,    69,    71,    75,    76,    94,    95,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     109,   110,   111,   112,   116,   144,     4,     5,     8,     9,
      10,    16,    17,    18,    24,    30,    36,    40,   112,   114,
     117,   119,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,    50,    72,    91,    70,    28,   136,   139,
      70,   119,   140,   141,   142,    69,    97,    97,    98,   107,
      98,    98,    98,    98,   114,   124,   126,   131,   143,    67,
      73,   145,   146,   147,   148,   149,    69,    97,    97,    67,
      69,    73,    74,    75,    76,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,   113,    62,    77,    78,
      63,    64,    79,    80,    46,    47,    81,    82,    48,    49,
      61,    83,    84,    85,    86,   108,    89,   111,   115,    89,
      88,   107,    69,    40,    69,   156,    69,   108,    88,    91,
      72,   107,    89,   115,    72,   130,   136,    62,   112,   137,
      28,   135,    70,    91,   143,    98,    70,   125,   126,   125,
      70,   115,    40,   144,    72,    91,    50,   149,   143,   114,
      70,    96,   112,    40,    40,   112,    98,    98,    98,    99,
      99,   100,   100,   101,   101,   101,   101,   102,   102,   103,
     107,   105,   107,   107,    87,    88,   150,   150,   117,   156,
      89,   114,    89,   114,   107,   150,   112,   155,   112,    68,
      68,   112,    90,   142,    70,    71,    98,    68,    72,   145,
      70,    68,    70,    91,   104,   106,   109,   107,   150,   107,
     156,    89,    70,    70,    69,    68,    68,   146,   144,   112,
     114,    36,    89,   107,   107,   150,   114,    72,    91,   108,
      69,   156,   108,   150,    70,    72,    88,   114,    70,   156,
     108,   107,   107,    70,   150,    89,    12,   150,   111,    89,
     107,   107,   156,   150,   108,    70,   107,   150
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1787 of yacc.c  */
#line 224 "ass5_12CS10006.y"
    {   (yyval.exp).symptr=(yyvsp[(1) - (1)].symp); (yyval.exp).boolex=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL;}
    break;

  case 3:
/* Line 1787 of yacc.c  */
#line 225 "ass5_12CS10006.y"
    {  (yyval.exp).symptr=(yyvsp[(1) - (1)].symp); (yyval.exp).boolex=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL;}
    break;

  case 4:
/* Line 1787 of yacc.c  */
#line 227 "ass5_12CS10006.y"
    {
 			  (yyval.exp).symptr=ST_funt->gentemp(new Type_Data(Pointer,0,new Type_Data(Char)),yylval.stringval); 
			  qarr.emit(ASSIGN,(yyval.exp).symptr->name,yylval.stringval);
                          (yyval.exp).boolex=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL;
		       }
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 233 "ass5_12CS10006.y"
    {
			        (yyval.exp)=(yyvsp[(2) - (3)].exp); 
 			}
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 241 "ass5_12CS10006.y"
    {
                                         if((yyvsp[(1) - (4)].exp).array==NULL)
                                         {
 					  (yyval.exp).array=(yyvsp[(1) - (4)].exp).symptr;
					  (yyval.exp).type=(yyvsp[(1) - (4)].exp).symptr->type->right;
                                          (yyval.exp).symptr=ST_gl.gentemp(new Type_Data(Int),NULL);
                                          char *buffer=new char[30]; 
					  sprintf(buffer,"%d",(yyval.exp).type->size());
					  qarr.emit(MULT,(yyval.exp).symptr->name,(yyvsp[(3) - (4)].exp).symptr->name,buffer);
                                         }
					else
					 {
						(yyval.exp).array=(yyvsp[(1) - (4)].exp).array;
					        (yyval.exp).type= (yyvsp[(1) - (4)].exp).type->right;
						(yyval.exp).symptr=ST_gl.gentemp(new Type_Data(Int),NULL);		
						SYMT_ROW* tmp=ST_gl.gentemp(new Type_Data(Int),NULL);
						char *buffer=new char[30]; sprintf(buffer,"%d",(yyval.exp).type->size());
 						qarr.emit(MULT,tmp->name,(yyvsp[(3) - (4)].exp).symptr->name,buffer);
                                                qarr.emit(PLUS,(yyval.exp).symptr->name,(yyvsp[(1) - (4)].exp).symptr->name,tmp->name);
					 }
						(yyval.exp).boolex=NULL;
					 }
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 263 "ass5_12CS10006.y"
    { //function call in Expressions
                          	list_<SYMT_ROW*>* p=(yyvsp[(3) - (4)].list_ptr);
				 int c=0;
                                 bool b;
                                 SYMT_ROW *st=ST_gl.lookup((yyvsp[(1) - (4)].exp).symptr->name)->stptr->head;
                                 while(p){ 
				//printf("calling %s %s\n\n\n",p->data->name,st->name);     
				 //SYMT_ROW* type=typecheck(p->data,st,b);   // type check every param
				 //printf("c=%d",c);
                                 //if(!type)
 				 qarr.emit(PARAM,p->data->name);
				 p=p->next;st=st->next;c++;
				 }
				// printf("calling %s %s\n\n\n",p->data->name,st->name); 
				 symtable* ST=ST_gl.lookup((yyvsp[(1) - (4)].exp).symptr->name)->stptr;
				 if(st!=ST->last) yyerror("to few arguments\n");
				 else {
				 Type_Data *t=st->type;
				 (yyval.exp).symptr=ST_gl.gentemp(t,NULL);
                                 char *buffer = new char[30]; sprintf(buffer,"%d",c);	
				 qarr.emit(CALL,(yyval.exp).symptr->name,(yyvsp[(1) - (4)].exp).symptr->name,buffer);}	
                                }
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 285 "ass5_12CS10006.y"
    { //function call in Expressions
                                   
         			 symtable* ST=ST_funt->lookup((yyvsp[(1) - (3)].exp).symptr->name)->stptr;
                                 Type_Data *t=ST->last->type;
                                 (yyval.exp).symptr=ST_funt->gentemp(t,NULL);
			         qarr.emit(CALL,(yyval.exp).symptr->name,(yyvsp[(1) - (3)].exp).symptr->name,"0");
				 }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 292 "ass5_12CS10006.y"
    { }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 293 "ass5_12CS10006.y"
    { }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 295 "ass5_12CS10006.y"
    { 
				 (yyval.exp).symptr=ST_funt->gentemp((yyvsp[(1) - (2)].exp).symptr->type,NULL); 
				 qarr.emit(ASSIGN,(yyval.exp).symptr->name,(yyvsp[(1) - (2)].exp).symptr->name); 
				 qarr.emit(PLUS,(yyvsp[(1) - (2)].exp).symptr->name,(yyvsp[(1) - (2)].exp).symptr->name,"1");
                                 (yyval.exp).boolex=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL;
                             }
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 302 "ass5_12CS10006.y"
    {
					 (yyval.exp).symptr=ST_funt->gentemp((yyvsp[(1) - (2)].exp).symptr->type,NULL); 
                                         qarr.emit(ASSIGN,(yyval.exp).symptr->name,(yyvsp[(1) - (2)].exp).symptr->name);
					 qarr.emit(MINUS,(yyvsp[(1) - (2)].exp).symptr->name,(yyvsp[(1) - (2)].exp).symptr->name,"1");
                                         (yyval.exp).boolex=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL;
				}
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 308 "ass5_12CS10006.y"
    { }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 309 "ass5_12CS10006.y"
    { }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 313 "ass5_12CS10006.y"
    { (yyval.list_ptr)=makelist<SYMT_ROW*>((yyvsp[(1) - (1)].exp).symptr);}
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 314 "ass5_12CS10006.y"
    {(yyval.list_ptr)=merge<SYMT_ROW*>((yyvsp[(1) - (3)].list_ptr),makelist<SYMT_ROW*>((yyvsp[(3) - (3)].exp).symptr)); }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 321 "ass5_12CS10006.y"
    { 
				       (yyval.exp).symptr=ST_funt->gentemp((yyvsp[(2) - (2)].exp).symptr->type,NULL); 
				       qarr.emit(PLUS,(yyvsp[(2) - (2)].exp).symptr->name,(yyvsp[(2) - (2)].exp).symptr->name,"1"); 
                                       qarr.emit(ASSIGN,(yyval.exp).symptr->name,(yyvsp[(2) - (2)].exp).symptr->name);
                                       (yyval.exp).boolex=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL;
        			}
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 328 "ass5_12CS10006.y"
    {
				      (yyval.exp).symptr=ST_funt->gentemp((yyvsp[(2) - (2)].exp).symptr->type,NULL); 
                                      qarr.emit(MINUS,(yyvsp[(2) - (2)].exp).symptr->name,(yyvsp[(2) - (2)].exp).symptr->name,"1"); 
				      qarr.emit(ASSIGN,(yyval.exp).symptr->name,(yyvsp[(2) - (2)].exp).symptr->name);
				      (yyval.exp).boolex=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL;
				}
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 335 "ass5_12CS10006.y"
    {
					 (yyval.exp).symptr=ST_funt->gentemp(new Type_Data(Pointer,0,(yyvsp[(2) - (2)].exp).symptr->type)); 
					 qarr.emit(ADDR,(yyval.exp).symptr->name,(yyvsp[(2) - (2)].exp).symptr->name);
					 (yyval.exp).boolex=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL;
					}
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 342 "ass5_12CS10006.y"
    {
					 (yyval.exp).symptr=ST_funt->gentemp((yyvsp[(3) - (3)].exp).symptr->type->right,NULL); 
					 qarr.emit(DREF,(yyval.exp).symptr->name,(yyvsp[(3) - (3)].exp).symptr->name);
					 (yyval.exp).array=(yyvsp[(3) - (3)].exp).symptr;
					 (yyval.exp).array->initial_value=new char[30];
					 sprintf((yyval.exp).array->initial_value,"%d",(yyvsp[(2) - (3)].intval))  ;
					 (yyval.exp).boolex=NULL;(yyval.exp).type=NULL;
				}
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 350 "ass5_12CS10006.y"
    { (yyval.exp)=(yyvsp[(2) - (2)].exp); }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 352 "ass5_12CS10006.y"
    {
					 (yyval.exp).symptr=ST_funt->gentemp((yyvsp[(2) - (2)].exp).symptr->type,NULL);
					 qarr.emit(UMINUS,(yyval.exp).symptr->name,(yyvsp[(2) - (2)].exp).symptr->name);
					 (yyval.exp).boolex=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL;
				}
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 359 "ass5_12CS10006.y"
    {	
					 (yyval.exp).symptr=ST_funt->gentemp((yyvsp[(2) - (2)].exp).symptr->type,NULL); 
					 qarr.emit(UBNEG,(yyval.exp).symptr->name,(yyvsp[(2) - (2)].exp).symptr->name);
					 (yyval.exp).boolex=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL;
				}
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 365 "ass5_12CS10006.y"
    {
				  (yyval.exp).symptr=ST_funt->gentemp((yyvsp[(2) - (2)].exp).symptr->type,NULL); 
				  qarr.emit(UNOT,(yyval.exp).symptr->name,(yyvsp[(2) - (2)].exp).symptr->name);
				  (yyval.exp).boolex=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL;
				}
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 370 "ass5_12CS10006.y"
    { }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 371 "ass5_12CS10006.y"
    { }
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 376 "ass5_12CS10006.y"
    { }
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 382 "ass5_12CS10006.y"
    { 
					SYMT_ROW *st1,*st2;
					if((yyvsp[(1) - (3)].exp).symptr->type->type_name==Int && (yyvsp[(3) - (3)].exp).symptr->type->type_name==Double)
					 {	st1=convInt2Double((yyvsp[(1) - (3)].exp).symptr); st2=(yyvsp[(3) - (3)].exp).symptr;  }	
					else
					if((yyvsp[(3) - (3)].exp).symptr->type->type_name==Int && (yyvsp[(1) - (3)].exp).symptr->type->type_name==Double)
					 {	st2=convInt2Double((yyvsp[(3) - (3)].exp).symptr); st1=(yyvsp[(1) - (3)].exp).symptr;  }
					else {	st1=(yyvsp[(1) - (3)].exp).symptr;st2=(yyvsp[(3) - (3)].exp).symptr;}

					(yyval.exp).symptr=ST_funt->gentemp(st1->type,NULL); 
					qarr.emit(MULT,(yyval.exp).symptr->name,st1->name,st2->name); 
					(yyval.exp).boolex=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL;
				}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 396 "ass5_12CS10006.y"
    {
				     SYMT_ROW *st1,*st2;
					if((yyvsp[(1) - (3)].exp).symptr->type->type_name==Int && (yyvsp[(3) - (3)].exp).symptr->type->type_name==Double)
					 {	st1=convInt2Double((yyvsp[(1) - (3)].exp).symptr); st2=(yyvsp[(3) - (3)].exp).symptr;  }	
					else
					if((yyvsp[(3) - (3)].exp).symptr->type->type_name==Int && (yyvsp[(1) - (3)].exp).symptr->type->type_name==Double)
					 {	st2=convInt2Double((yyvsp[(3) - (3)].exp).symptr); st1=(yyvsp[(1) - (3)].exp).symptr;  }
					else {	st1=(yyvsp[(1) - (3)].exp).symptr;st2=(yyvsp[(3) - (3)].exp).symptr;}

					(yyval.exp).symptr=ST_funt->gentemp(st1->type,NULL); 
					qarr.emit(DIV,(yyval.exp).symptr->name,st1->name,st2->name); 
					(yyval.exp).boolex=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL; 
				}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 410 "ass5_12CS10006.y"
    { 
			            SYMT_ROW *st1,*st2;
					if((yyvsp[(1) - (3)].exp).symptr->type->type_name==Int && (yyvsp[(3) - (3)].exp).symptr->type->type_name==Double)
					 {	st1=convInt2Double((yyvsp[(1) - (3)].exp).symptr); st2=(yyvsp[(3) - (3)].exp).symptr;  }	
					else
					if((yyvsp[(3) - (3)].exp).symptr->type->type_name==Int && (yyvsp[(1) - (3)].exp).symptr->type->type_name==Double)
					 {	st2=convInt2Double((yyvsp[(3) - (3)].exp).symptr); st1=(yyvsp[(1) - (3)].exp).symptr;  }
					else {	st1=(yyvsp[(1) - (3)].exp).symptr;st2=(yyvsp[(3) - (3)].exp).symptr;}

					(yyval.exp).symptr=ST_funt->gentemp(st1->type,NULL); 
					qarr.emit(MOD,(yyval.exp).symptr->name,st1->name,st2->name); 
					(yyval.exp).boolex=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL;
				}
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 428 "ass5_12CS10006.y"
    { 	
					SYMT_ROW *st1,*st2;
					if((yyvsp[(1) - (3)].exp).symptr->type->type_name==Int && (yyvsp[(3) - (3)].exp).symptr->type->type_name==Double)
					 {	st1=convInt2Double((yyvsp[(1) - (3)].exp).symptr); st2=(yyvsp[(3) - (3)].exp).symptr;  }	
					else
					if((yyvsp[(3) - (3)].exp).symptr->type->type_name==Int && (yyvsp[(1) - (3)].exp).symptr->type->type_name==Double)
					 {	st2=convInt2Double((yyvsp[(3) - (3)].exp).symptr); st1=(yyvsp[(1) - (3)].exp).symptr;  }
					else {	st1=(yyvsp[(1) - (3)].exp).symptr;st2=(yyvsp[(3) - (3)].exp).symptr;}

					(yyval.exp).symptr=ST_funt->gentemp(st1->type,NULL); 
					qarr.emit(PLUS,(yyval.exp).symptr->name,st1->name,st2->name); 
					(yyval.exp).boolex=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL;
				}
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 442 "ass5_12CS10006.y"
    {
					 SYMT_ROW *st1,*st2;
					if((yyvsp[(1) - (3)].exp).symptr->type->type_name==Int && (yyvsp[(3) - (3)].exp).symptr->type->type_name==Double)
					 {	st1=convInt2Double((yyvsp[(1) - (3)].exp).symptr); st2=(yyvsp[(3) - (3)].exp).symptr;  }	
					else
					if((yyvsp[(3) - (3)].exp).symptr->type->type_name==Int && (yyvsp[(1) - (3)].exp).symptr->type->type_name==Double)
					 {	st2=convInt2Double((yyvsp[(3) - (3)].exp).symptr); st1=(yyvsp[(1) - (3)].exp).symptr;  }
					else {	st1=(yyvsp[(1) - (3)].exp).symptr;st2=(yyvsp[(3) - (3)].exp).symptr;}

					(yyval.exp).symptr=ST_funt->gentemp(st1->type,NULL); 
					qarr.emit(MINUS,(yyval.exp).symptr->name,st1->name,st2->name); 
					(yyval.exp).boolex=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL;
				}
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 459 "ass5_12CS10006.y"
    {
					 (yyval.exp).symptr=ST_funt->gentemp((yyvsp[(1) - (3)].exp).symptr->type,NULL); 
					 qarr.emit(LSHFT,(yyval.exp).symptr->name,(yyvsp[(1) - (3)].exp).symptr->name,(yyvsp[(3) - (3)].exp).symptr->name);
					 (yyval.exp).boolex=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL;
				}
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 465 "ass5_12CS10006.y"
    {       (yyval.exp).symptr=ST_funt->gentemp((yyvsp[(1) - (3)].exp).symptr->type,NULL); 
				 	qarr.emit(RSHFT,(yyval.exp).symptr->name,(yyvsp[(1) - (3)].exp).symptr->name,(yyvsp[(3) - (3)].exp).symptr->name); 
					(yyval.exp).boolex=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL;	
				}
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 473 "ass5_12CS10006.y"
    {
					 (yyval.exp).boolex=new boolexp;
          			         (yyval.exp).boolex->TL=makelist<int>(nextinstr());
				         (yyval.exp).boolex->FL=makelist<int>(nextinstr()+1);
					 qarr.emit(LT_,0,(yyvsp[(1) - (3)].exp).symptr->name,(yyvsp[(3) - (3)].exp).symptr->name);
					 qarr.emit(GOTO,0);
				      	 (yyval.exp).symptr=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL;
				}
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 482 "ass5_12CS10006.y"
    {
					 (yyval.exp).boolex=new boolexp;
    				         (yyval.exp).boolex->TL=makelist<int>(nextinstr());
					 (yyval.exp).boolex->FL=makelist<int>(nextinstr()+1);
					 qarr.emit(GT_,0,(yyvsp[(1) - (3)].exp).symptr->name,(yyvsp[(3) - (3)].exp).symptr->name);
					 qarr.emit(GOTO,0);
                                         //qarr.print();
					//printf("executed\n");
					 (yyval.exp).symptr=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL;
				 }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 493 "ass5_12CS10006.y"
    {
					  (yyval.exp).boolex=new boolexp;
            				  (yyval.exp).boolex->TL=makelist<int>(nextinstr());
				          (yyval.exp).boolex->FL=makelist<int>(nextinstr()+1);
					  qarr.emit(LEQ_,0,(yyvsp[(1) - (3)].exp).symptr->name,(yyvsp[(3) - (3)].exp).symptr->name);
					  qarr.emit(GOTO,0);
					  (yyval.exp).symptr=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL;
				}
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 502 "ass5_12CS10006.y"
    {
					  (yyval.exp).boolex=new boolexp;
         				  (yyval.exp).boolex->TL=makelist<int>(nextinstr());
				          (yyval.exp).boolex->FL=makelist<int>(nextinstr()+1);
					  qarr.emit(GEQ_,0,(yyvsp[(1) - (3)].exp).symptr->name,(yyvsp[(3) - (3)].exp).symptr->name);				
					  qarr.emit(GOTO,0);
					  (yyval.exp).symptr=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL;
				}
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 514 "ass5_12CS10006.y"
    {
	       				 (yyval.exp).boolex=new boolexp;
           				 (yyval.exp).boolex->TL=makelist<int>(nextinstr());
					 (yyval.exp).boolex->FL=makelist<int>(nextinstr()+1);
					 qarr.emit(EQ_,0,(yyvsp[(1) - (3)].exp).symptr->name,(yyvsp[(3) - (3)].exp).symptr->name); 
					 qarr.emit(GOTO,0);
					 (yyval.exp).symptr=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL;
				}
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 523 "ass5_12CS10006.y"
    { 
				  	  (yyval.exp).boolex=new boolexp;
           				  (yyval.exp).boolex->TL=makelist<int>(nextinstr());
				    	  (yyval.exp).boolex->FL=makelist<int>(nextinstr()+1);
					  qarr.emit(NEQ_,0,(yyvsp[(1) - (3)].exp).symptr->name,(yyvsp[(3) - (3)].exp).symptr->name);
					  qarr.emit(GOTO,0);
					  (yyval.exp).symptr=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL;
				}
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 535 "ass5_12CS10006.y"
    {
					 (yyval.exp).symptr=ST_funt->gentemp((yyvsp[(1) - (3)].exp).symptr->type,NULL); 
					 qarr.emit(UAND,(yyval.exp).symptr->name,(yyvsp[(1) - (3)].exp).symptr->name,(yyvsp[(3) - (3)].exp).symptr->name); 
					 (yyval.exp).boolex=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL;
				}
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 544 "ass5_12CS10006.y"
    {
					 (yyval.exp).symptr=ST_funt->gentemp((yyvsp[(1) - (4)].exp).symptr->type,NULL); 
					 qarr.emit(XOR,(yyval.exp).symptr->name,(yyvsp[(1) - (4)].exp).symptr->name,(yyvsp[(4) - (4)].exp).symptr->name);
					 (yyval.exp).boolex=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL;

                               /*         char *buffer=new char[30];
                                        sprintf(buffer,"%d",$3);              

					backpatch($1.boolex->TL,nextinstr());
					qaar.emit(ASSIGN,$1.symptr->name,"true");  
					qaar.emit(GOTO,buffer);
					backpatch($1.boolex->TL,nextinstr());
					qaar.emit(ASSIGN,$1.symptr->name,"false");
  					qaar.emit(GOTO,buffer);

					$$.boolex->TL=makelist(nextinstr());
					backpatch($2.boolex->FL,nextinstr());
					qaar.emit(EQ_,0,$1.symptr->name,"true"); 
					$$.boolex->FL=makelist(nextinstr());
					qaar.emit(GOTO,"0"); 
		
					list<int> *temp1 = makelist(nextinstr());
					$$.boolex->FL=merge($$.boolex->FL,temp);
					backpatch(B 2 .truelist, nextinstr );
					qaar.emit(EQ_,0,$1.symptr->name,"true"); 
					list<int> *temp2=makelist(nextinstr());
					$$.boolex->TL = merge(B.truelist, temp);
					qaar.emit(”goto”, ”.....”);*/


				 }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 579 "ass5_12CS10006.y"
    {
				    (yyval.exp).symptr=ST_funt->gentemp((yyvsp[(1) - (3)].exp).symptr->type,NULL); 
				    qarr.emit(UOR,(yyval.exp).symptr->name,(yyvsp[(1) - (3)].exp).symptr->name,(yyvsp[(3) - (3)].exp).symptr->name);
				    (yyval.exp).boolex=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL; 
				}
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 585 "ass5_12CS10006.y"
    { (yyval.intval)=nextinstr();}
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 586 "ass5_12CS10006.y"
    { (yyval.stmt).NL=makelist<int>(nextinstr()); qarr.emit(GOTO,0); }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 590 "ass5_12CS10006.y"
    {
							expression e1=conv2Bool((yyvsp[(1) - (4)].exp));
							expression e2=conv2Bool((yyvsp[(4) - (4)].exp));
						        backpatch(e1.boolex->TL,(yyvsp[(3) - (4)].intval)+PC);
		  			                (yyval.exp).boolex=new boolexp; 
						        (yyval.exp).boolex->FL=merge<int>(e1.boolex->FL,e2.boolex->FL); 
						        (yyval.exp).boolex->TL=e2.boolex->TL; 
							(yyval.exp).symptr=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL;
						}
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 603 "ass5_12CS10006.y"
    {
						     expression e1=conv2Bool((yyvsp[(1) - (4)].exp));
						     expression e2=conv2Bool((yyvsp[(4) - (4)].exp));
						     backpatch(e1.boolex->FL,(yyvsp[(3) - (4)].intval)+PC);
					             (yyval.exp).boolex=new boolexp; 
						     (yyval.exp).boolex->TL=merge<int>(e1.boolex->TL,e2.boolex->TL); 
						     (yyval.exp).boolex->FL=e2.boolex->FL; 
						     (yyval.exp).symptr=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL;
						}
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 616 "ass5_12CS10006.y"
    {
							  
						          expression e1=(yyvsp[(1) - (9)].exp);//conv2Bool($1);
		          				  (yyval.exp).symptr=ST_funt->gentemp((yyvsp[(5) - (9)].exp).symptr->type); 
						  	  qarr.emit(ASSIGN,(yyval.exp).symptr->name,(yyvsp[(9) - (9)].exp).symptr->name);
		          				  list_<int> *l=makelist<int>(nextinstr());
							  qarr.emit(GOTO,0);
							  backpatch((yyvsp[(6) - (9)].stmt).NL,nextinstr()+PC);
		         				  qarr.emit(ASSIGN,(yyval.exp).symptr->name,(yyvsp[(5) - (9)].exp).symptr->name);
		       					  l=merge<int>(l,makelist<int>(nextinstr()));
		        				  qarr.emit(GOTO,0);
			  				  backpatch((yyvsp[(2) - (9)].stmt).NL,nextinstr()+PC);
			  				  backpatch(e1.boolex->TL,(yyvsp[(4) - (9)].intval)+PC);
					 	          backpatch(e1.boolex->FL,(yyvsp[(8) - (9)].intval)+PC);
					 	  	  backpatch(l,nextinstr()+PC);
							  (yyval.exp).boolex=NULL;(yyval.exp).array=NULL;(yyval.exp).type=NULL;
						}
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 638 "ass5_12CS10006.y"
    { 

				       if(!(yyvsp[(1) - (3)].exp).type && !(yyvsp[(3) - (3)].exp).type){
						if((yyvsp[(1) - (3)].exp).array)           // it is a arithemic expression  assignment 
				                   {
						
						            qarr.delete_(); 
							    qarr.emit(STR,(yyvsp[(1) - (3)].exp).array->name,(yyvsp[(3) - (3)].exp).symptr->name); 
							    (yyvsp[(3) - (3)].exp).symptr->stptr=new symtable();   
/*////////////////////////////////                    */    ST_funt->shift((yyvsp[(1) - (3)].exp).symptr,(yyvsp[(3) - (3)].exp).symptr->stptr); free((yyvsp[(3) - (3)].exp).symptr->stptr);
						   }
						else{
						   if((yyvsp[(3) - (3)].exp).boolex){
							    convBool2Int((yyvsp[(3) - (3)].exp));
						            qarr.emit(ASSIGN,(yyvsp[(1) - (3)].exp).symptr->name,(yyvsp[(3) - (3)].exp).symptr->name);
							}
					       	  else{
					           bool e; 
						   SYMT_ROW *st=typecheck((yyvsp[(3) - (3)].exp).symptr,(yyvsp[(1) - (3)].exp).symptr,e);
						   if(e)
                                                   qarr.emit(ASSIGN,(yyvsp[(1) - (3)].exp).symptr->name,(yyvsp[(3) - (3)].exp).symptr->name);
						   else 
						   qarr.emit(ASSIGN,(yyvsp[(1) - (3)].exp).symptr->name,st->name);	
							}			
               					}
					}
                                       if((yyvsp[(1) - (3)].exp).type && !(yyvsp[(3) - (3)].exp).type) // it is array refrence assignement
                                        {
                                           qarr.emit(ARR_REF,(yyvsp[(1) - (3)].exp).array->name,(yyvsp[(1) - (3)].exp).symptr->name,(yyvsp[(3) - (3)].exp).symptr->name);                             
					}
					if(!(yyvsp[(1) - (3)].exp).type && (yyvsp[(3) - (3)].exp).type) // it is array refrence assignement
                                        {
					  //printf("\n\n\nyes\n\n\n");
                                           qarr.emit(ARR_DREF,(yyvsp[(1) - (3)].exp).symptr->name,(yyvsp[(3) - (3)].exp).array->name,(yyvsp[(3) - (3)].exp).symptr->name);                             
					}
                                       else if((yyvsp[(1) - (3)].exp).type && (yyvsp[(3) - (3)].exp).type) // it is array derefrence assignement
					     {
                                              SYMT_ROW* tmp=ST_funt->gentemp((yyvsp[(3) - (3)].exp).type);
                                              qarr.emit(ARR_DREF,tmp->name,(yyvsp[(3) - (3)].exp).array->name,(yyvsp[(3) - (3)].exp).symptr->name); //$3.symptr->name); 
					      qarr.emit(ARR_REF,(yyvsp[(1) - (3)].exp).array->name,(yyvsp[(1) - (3)].exp).symptr->name,tmp->name); 
					}
                                       (yyval.exp)=(yyvsp[(1) - (3)].exp);
				 }
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 682 "ass5_12CS10006.y"
    { }
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 682 "ass5_12CS10006.y"
    { }
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 682 "ass5_12CS10006.y"
    { }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 682 "ass5_12CS10006.y"
    { }
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 682 "ass5_12CS10006.y"
    { }
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 682 "ass5_12CS10006.y"
    { }
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 682 "ass5_12CS10006.y"
    { }
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 682 "ass5_12CS10006.y"
    { }
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 682 "ass5_12CS10006.y"
    { }
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 682 "ass5_12CS10006.y"
    { }
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 682 "ass5_12CS10006.y"
    { }
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 687 "ass5_12CS10006.y"
    { }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 694 "ass5_12CS10006.y"
    {  		
					char *buffer=new char[30];
					sprintf(buffer,"%d",yylval.intval);
					(yyval.symp)=ST_funt->gentemp(new Type_Data(Int),buffer);
			  		qarr.emit(ASSIGN,(yyval.symp)->name,buffer);		
				 }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 701 "ass5_12CS10006.y"
    {
					char *buffer=new char[30];
					sprintf(buffer,"%lf",yylval.floatval);
					(yyval.symp)=ST_funt->gentemp(new Type_Data(Double),buffer);
				  	qarr.emit(ASSIGN,(yyval.symp)->name,buffer);
				 }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 707 "ass5_12CS10006.y"
    { }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 709 "ass5_12CS10006.y"
    {
		  			char *buffer=new char[30];
					sprintf(buffer,"%c",yylval.charval);
   		  	  		(yyval.symp)=ST_funt->gentemp(new Type_Data(Char),buffer); 
         				char *buffer1=new char[30];
         				buffer1[0]=buffer1[2]='\''; buffer1[1]=yylval.charval;buffer1[3]='\0';
				    	qarr.emit(ASSIGN,(yyval.symp)->name,buffer1); 
				}
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 723 "ass5_12CS10006.y"
    {                      
			    list_<SYMT_ROW*>* p=(yyvsp[(2) - (3)].list_ptr);
			       do{
                                   Type_Data *t=new Type_Data((yyvsp[(1) - (3)].t_exp).type);
                                   if(p->data->type){ 
                                   if(p->data->type->type_name==Function) 
				   {
				  	 SYMT_ROW* l=p->data->stptr->lookup("retval");
                                    	 p->data->stptr->update(t,l);
                                   }
                                   else          // it is array or pointer declaration
						ST_funt->update(t,p->data);		                                        
					 }
				  else  // it is SIMPLE declaration
                                        ST_funt->update(t,p->data);

                                  p=p->next;
				}while(p);
				ST_funt=&ST_gl;
	
    	 			}
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 744 "ass5_12CS10006.y"
    { }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 748 "ass5_12CS10006.y"
    { }
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 749 "ass5_12CS10006.y"
    { }
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 752 "ass5_12CS10006.y"
    { }
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 754 "ass5_12CS10006.y"
    { }
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 755 "ass5_12CS10006.y"
    { }
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 764 "ass5_12CS10006.y"
    {
				   (yyval.list_ptr)=makelist((yyvsp[(1) - (1)].symp));
				}
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 768 "ass5_12CS10006.y"
    {
				(yyval.list_ptr)=merge((yyvsp[(1) - (3)].list_ptr),makelist((yyvsp[(3) - (3)].symp))); 
				}
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 776 "ass5_12CS10006.y"
    {
			     	if((yyvsp[(3) - (3)].exp).type)
					qarr.emit(ARR_DREF,(yyvsp[(1) - (3)].symp)->name,(yyvsp[(3) - (3)].exp).array->name,(yyvsp[(3) - (3)].exp).symptr->name);
                                if((yyvsp[(3) - (3)].exp).symptr->initial_value)
				{
                                    qarr.delete_();
	                            (yyvsp[(1) - (3)].symp)->initial_value=(yyvsp[(3) - (3)].exp).symptr->initial_value; 
				    qarr.emit(ASSIGN,(yyvsp[(1) - (3)].symp)->name,(yyvsp[(3) - (3)].exp).symptr->initial_value); 
	                            (yyvsp[(1) - (3)].symp)->stptr=new symtable();   
				    ST_funt->shift((yyvsp[(3) - (3)].exp).symptr,(yyvsp[(1) - (3)].symp)->stptr); free((yyvsp[(1) - (3)].symp)->stptr);
				}
                                else
				{
	                              qarr.emit(ASSIGN,(yyvsp[(1) - (3)].symp)->name,(yyvsp[(3) - (3)].exp).symptr->name);
			        }
                         }
    break;

  case 100:
/* Line 1787 of yacc.c  */
#line 800 "ass5_12CS10006.y"
    { (yyval.t_exp).type=Void; (yyval.t_exp).width=0;}
    break;

  case 101:
/* Line 1787 of yacc.c  */
#line 801 "ass5_12CS10006.y"
    { (yyval.t_exp).type=Char; (yyval.t_exp).width=size_of_char;}
    break;

  case 102:
/* Line 1787 of yacc.c  */
#line 802 "ass5_12CS10006.y"
    { }
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 803 "ass5_12CS10006.y"
    { (yyval.t_exp).type=Int; (yyval.t_exp).width=size_of_int;}
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 804 "ass5_12CS10006.y"
    { }
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 805 "ass5_12CS10006.y"
    { }
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 806 "ass5_12CS10006.y"
    { (yyval.t_exp).type=Double; (yyval.t_exp).width=size_of_double;}
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 807 "ass5_12CS10006.y"
    { }
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 808 "ass5_12CS10006.y"
    { }
    break;

  case 109:
/* Line 1787 of yacc.c  */
#line 809 "ass5_12CS10006.y"
    { }
    break;

  case 110:
/* Line 1787 of yacc.c  */
#line 810 "ass5_12CS10006.y"
    { }
    break;

  case 111:
/* Line 1787 of yacc.c  */
#line 811 "ass5_12CS10006.y"
    { }
    break;

  case 112:
/* Line 1787 of yacc.c  */
#line 812 "ass5_12CS10006.y"
    { }
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 820 "ass5_12CS10006.y"
    { }
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 821 "ass5_12CS10006.y"
    { }
    break;

  case 118:
/* Line 1787 of yacc.c  */
#line 825 "ass5_12CS10006.y"
    { }
    break;

  case 119:
/* Line 1787 of yacc.c  */
#line 828 "ass5_12CS10006.y"
    { }
    break;

  case 120:
/* Line 1787 of yacc.c  */
#line 829 "ass5_12CS10006.y"
    { }
    break;

  case 121:
/* Line 1787 of yacc.c  */
#line 830 "ass5_12CS10006.y"
    { }
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 833 "ass5_12CS10006.y"
    { }
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 834 "ass5_12CS10006.y"
    { }
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 837 "ass5_12CS10006.y"
    { }
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 838 "ass5_12CS10006.y"
    { }
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 841 "ass5_12CS10006.y"
    { }
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 842 "ass5_12CS10006.y"
    { }
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 843 "ass5_12CS10006.y"
    { }
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 846 "ass5_12CS10006.y"
    { }
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 849 "ass5_12CS10006.y"
    { (yyval.intval)=(yyvsp[(1) - (1)].intval); }
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 850 "ass5_12CS10006.y"
    {  (yyval.intval)=0;}
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 853 "ass5_12CS10006.y"
    {(yyval.intval)=1;   }
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 854 "ass5_12CS10006.y"
    {(yyval.intval)=(yyvsp[(3) - (3)].intval)+1;  }
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 858 "ass5_12CS10006.y"
    { 
			   (yyval.symp)=(yyvsp[(2) - (2)].symp);
				SYMT_ROW* l=NULL;
                           if((yyvsp[(2) - (2)].symp)->stptr) 
                                 l=(yyvsp[(2) - (2)].symp)->stptr->lookup("retval");
			   while((yyvsp[(1) - (2)].intval)--)
				{
                                 if(l)
					(yyvsp[(2) - (2)].symp)->stptr->update(new Type_Data(Pointer,0,NULL),l);
				else{
				         ST_gl.update(new Type_Data(Pointer,0,NULL),(yyval.symp));}
				}
			}
    break;

  case 135:
/* Line 1787 of yacc.c  */
#line 873 "ass5_12CS10006.y"
    { }
    break;

  case 138:
/* Line 1787 of yacc.c  */
#line 878 "ass5_12CS10006.y"
    { }
    break;

  case 140:
/* Line 1787 of yacc.c  */
#line 887 "ass5_12CS10006.y"
    {
					(yyval.symp)=(yyvsp[(1) - (5)].symp);	
                                        ST_funt->update(new Type_Data(Array,atoi((yyvsp[(4) - (5)].exp).symptr->initial_value),NULL),(yyvsp[(1) - (5)].symp));
                                }
    break;

  case 141:
/* Line 1787 of yacc.c  */
#line 892 "ass5_12CS10006.y"
    {
						(yyval.symp)=(yyvsp[(1) - (4)].symp);
						ST_funt=(yyvsp[(3) - (4)].symtp);
						//$$->type=sym_to_type($3);  
						(yyval.symp)->type=new Type_Data(Function,0,NULL);
						(yyval.symp)->stptr=(yyvsp[(3) - (4)].symtp);		
				}
    break;

  case 142:
/* Line 1787 of yacc.c  */
#line 900 "ass5_12CS10006.y"
    {
                                        (yyval.symp)=(yyvsp[(1) - (3)].symp);
					(yyval.symp)->stptr=new symtable();  ST_funt=(yyvsp[(1) - (3)].symp)->stptr;
					(yyval.symp)->type=new Type_Data(Function,0,NULL);
				}
    break;

  case 143:
/* Line 1787 of yacc.c  */
#line 905 "ass5_12CS10006.y"
    { }
    break;

  case 151:
/* Line 1787 of yacc.c  */
#line 920 "ass5_12CS10006.y"
    {
				 (yyval.symtp)=new symtable;
				 //$$->insert($1);
					//printf("\n\n\n%s\n",$1->name);	
				 if(!flag) { ST_funt->shift((yyvsp[(1) - (1)].symp),(yyval.symtp));} 
				else{	
                                      flag=false;
                                      Type_Data* t=(yyvsp[(1) - (1)].symp)->type;
       				      (yyvsp[(1) - (1)].symp)=(yyval.symtp)->lookup((yyvsp[(1) - (1)].symp)->name,1);ST_funt->update(t,(yyvsp[(1) - (1)].symp));
				      //$$->insert($1);
				  }//printf("existed \n\n\n");	
 	         }
    break;

  case 152:
/* Line 1787 of yacc.c  */
#line 933 "ass5_12CS10006.y"
    { 
                              //  printf("type is\n");
                               // $3->head->type->print(); 
				(yyval.symtp)=(yyvsp[(1) - (3)].symtp);
				if(!flag) { ST_funt->shift((yyvsp[(3) - (3)].symp),(yyval.symtp));} 
				else{	
                                      flag=false;
				Type_Data* t=(yyvsp[(3) - (3)].symp)->type;
                                SYMT_ROW* tmp=(yyval.symtp)->lookup((yyvsp[(3) - (3)].symp)->name,1);  (yyval.symtp)->update(t,tmp);
				      //$$->insert($3);
				  }
				//$$->insert($3); 
				//*$$=merge_symtab(*$1,*$$);
				//if(flag) flag=false;
 			}
    break;

  case 153:
/* Line 1787 of yacc.c  */
#line 951 "ass5_12CS10006.y"
    {
			           
				    //ST_funt->update(new Type_Data($1.type),$$);	                                              
                                   /*$$=new symtable;*/
                                       if(!flag)
					{
					     ST_funt->update(new Type_Data((yyvsp[(1) - (2)].t_exp).type),(yyvsp[(2) - (2)].symp));
					    // ST_gl.shift($2,$$);
					      (yyval.symp)=(yyvsp[(2) - (2)].symp);
					}
                                     else
                                       {
				
				  	        (yyval.symp)= new SYMT_ROW;
						(yyval.symp)->name=(yyvsp[(2) - (2)].symp)->name;
						ST_funt->update(new Type_Data((yyvsp[(1) - (2)].t_exp).type),(yyval.symp));
					        //$$->type=new Type_Data($1.type),tmp);
					
					}
                                      
				//     ST=$$;			
			}
    break;

  case 154:
/* Line 1787 of yacc.c  */
#line 973 "ass5_12CS10006.y"
    { }
    break;

  case 156:
/* Line 1787 of yacc.c  */
#line 984 "ass5_12CS10006.y"
    {}
    break;

  case 157:
/* Line 1787 of yacc.c  */
#line 985 "ass5_12CS10006.y"
    { }
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 986 "ass5_12CS10006.y"
    { }
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 993 "ass5_12CS10006.y"
    {}
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 1009 "ass5_12CS10006.y"
    { }
    break;

  case 174:
/* Line 1787 of yacc.c  */
#line 1017 "ass5_12CS10006.y"
    {}
    break;

  case 175:
/* Line 1787 of yacc.c  */
#line 1018 "ass5_12CS10006.y"
    {}
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 1019 "ass5_12CS10006.y"
    {}
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 1022 "ass5_12CS10006.y"
    {  (yyval.stmt).NL=(yyvsp[(1) - (1)].stmt).NL; if((yyval.stmt).NL) backpatch((yyval.stmt).NL,nextinstr()+PC); 
						  		}
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 1024 "ass5_12CS10006.y"
    { (yyval.stmt).NL=NULL;}
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 1027 "ass5_12CS10006.y"
    {  (yyval.stmt)=(yyvsp[(2) - (3)].stmt); }
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 1030 "ass5_12CS10006.y"
    {  (yyval.stmt)=(yyvsp[(1) - (1)].stmt); }
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 1031 "ass5_12CS10006.y"
    {backpatch((yyvsp[(1) - (3)].stmt).NL,(yyvsp[(2) - (3)].intval)+PC); (yyval.stmt).NL=(yyvsp[(3) - (3)].stmt).NL; }
    break;

  case 182:
/* Line 1787 of yacc.c  */
#line 1034 "ass5_12CS10006.y"
    {}
    break;

  case 183:
/* Line 1787 of yacc.c  */
#line 1035 "ass5_12CS10006.y"
    {(yyval.stmt).NL=(yyvsp[(1) - (1)].stmt).NL; }
    break;

  case 185:
/* Line 1787 of yacc.c  */
#line 1039 "ass5_12CS10006.y"
    { (yyval.exp).symptr=NULL;}
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 1042 "ass5_12CS10006.y"
    { 
			  if((yyvsp[(1) - (2)].exp).boolex) {
			     (yyval.stmt).NL=merge((yyvsp[(1) - (2)].exp).boolex->TL,(yyvsp[(1) - (2)].exp).boolex->FL);
				} 
				 else{ (yyval.stmt).NL=NULL;} 
			}
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 1051 "ass5_12CS10006.y"
    {
			/*if(!$3.boolex)
			 $3=conv2Bool($3); 
			 backpatch($3.boolex->TL,PC+$5); 
			 $6.NL=merge<int>($3.boolex->FL,$6.NL); 
			 $$.NL=$6.NL; //printf("exited\n\n\n\n");
			*/if(!(yyvsp[(3) - (6)].exp).boolex)
			 (yyvsp[(3) - (6)].exp)=conv2Bool((yyvsp[(3) - (6)].exp)); 
			 backpatch((yyvsp[(3) - (6)].exp).boolex->TL,PC+(yyvsp[(5) - (6)].intval)); 
			 (yyvsp[(6) - (6)].stmt).NL=merge<int>((yyvsp[(3) - (6)].exp).boolex->FL,(yyvsp[(6) - (6)].stmt).NL); 
			 (yyval.stmt).NL=(yyvsp[(6) - (6)].stmt).NL;
			/*\	
		        if(!$4.boolex)
			 $4=conv2Bool($4); 
			 backpatch($4.boolex->TL,PC+$6); 
			 $7.NL=merge<int>($4.boolex->FL,$7.NL); 
			 $$.NL=$7.NL; //printf("hid \n");*/
		}
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 1070 "ass5_12CS10006.y"
    { 
			 backpatch((yyvsp[(3) - (10)].exp).boolex->TL,PC+(yyvsp[(5) - (10)].intval)); 
			 backpatch((yyvsp[(3) - (10)].exp).boolex->FL,PC+(yyvsp[(9) - (10)].intval));
	  		 list_<int>* temp=merge<int>((yyvsp[(6) - (10)].stmt).NL,(yyvsp[(7) - (10)].stmt).NL); 
			 (yyval.stmt).NL=merge<int>(temp,(yyvsp[(10) - (10)].stmt).NL); 
		}
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 1076 "ass5_12CS10006.y"
    {}
    break;

  case 190:
/* Line 1787 of yacc.c  */
#line 1080 "ass5_12CS10006.y"
    {       
			if(!(yyvsp[(5) - (8)].exp).boolex) {
			backpatch((yyvsp[(2) - (8)].stmt).NL,PC+nextinstr());
			(yyvsp[(5) - (8)].exp)=conv2Bool((yyvsp[(5) - (8)].exp));
			}
			else 
			backpatch((yyvsp[(2) - (8)].stmt).NL,PC+(yyvsp[(3) - (8)].intval));
			backpatch((yyvsp[(8) - (8)].stmt).NL,PC+(yyvsp[(3) - (8)].intval));			 
			backpatch((yyvsp[(5) - (8)].exp).boolex->TL,PC+(yyvsp[(7) - (8)].intval)); 
			(yyvsp[(8) - (8)].stmt).NL=(yyvsp[(5) - (8)].exp).boolex->FL; 
			char *buffer=new char[30]; 
			sprintf(buffer,"%d",PC+(yyvsp[(3) - (8)].intval));qarr.emit(GOTO,buffer);
			(yyval.stmt).NL=(yyvsp[(8) - (8)].stmt).NL;
		}
    break;

  case 191:
/* Line 1787 of yacc.c  */
#line 1095 "ass5_12CS10006.y"
    { 
			if(!(yyvsp[(7) - (9)].exp).boolex) {
			(yyvsp[(7) - (9)].exp)=conv2Bool((yyvsp[(7) - (9)].exp));
			}
			backpatch((yyvsp[(7) - (9)].exp).boolex->TL,PC+(yyvsp[(2) - (9)].intval)); 
			backpatch((yyvsp[(3) - (9)].stmt).NL,PC+(yyvsp[(4) - (9)].intval)); 
			(yyvsp[(3) - (9)].stmt).NL=(yyvsp[(7) - (9)].exp).boolex->FL; 
			(yyval.stmt).NL=(yyvsp[(3) - (9)].stmt).NL;
		}
    break;

  case 192:
/* Line 1787 of yacc.c  */
#line 1117 "ass5_12CS10006.y"
    {
			if(!(yyvsp[(7) - (14)].exp).boolex)	
			{
				backpatch((yyvsp[(6) - (14)].stmt).NL,PC+nextinstr()+1);
				char *buffer=new char[30]; 
				sprintf(buffer,"%d",PC+(yyvsp[(9) - (14)].intval)); 
				qarr.emit(GOTO,buffer); 
				(yyvsp[(7) - (14)].exp)=conv2Bool((yyvsp[(7) - (14)].exp));
				backpatch((yyvsp[(7) - (14)].exp).boolex->TL,PC+(yyvsp[(13) - (14)].intval));  
				backpatch((yyvsp[(11) - (14)].stmt).NL,PC+(yyvsp[(5) - (14)].intval)); 
				backpatch((yyvsp[(14) - (14)].stmt).NL,PC+(yyvsp[(9) - (14)].intval));	
				(yyvsp[(14) - (14)].stmt).NL=(yyvsp[(7) - (14)].exp).boolex->FL; 
				(yyval.stmt).NL=(yyvsp[(14) - (14)].stmt).NL;
			}
			else  
			{
				backpatch((yyvsp[(6) - (14)].stmt).NL,PC+(yyvsp[(5) - (14)].intval)+1); 
	 	                backpatch((yyvsp[(7) - (14)].exp).boolex->TL,PC+(yyvsp[(13) - (14)].intval));  
				backpatch((yyvsp[(11) - (14)].stmt).NL,PC+(yyvsp[(5) - (14)].intval)); 
				backpatch((yyvsp[(14) - (14)].stmt).NL,PC+(yyvsp[(9) - (14)].intval));
			 	char *buffer=new char[30]; 
				sprintf(buffer,"%d",PC+(yyvsp[(9) - (14)].intval)); 
				qarr.emit(GOTO,buffer); 	
				(yyvsp[(14) - (14)].stmt).NL=(yyvsp[(7) - (14)].exp).boolex->FL; 
				(yyval.stmt).NL=(yyvsp[(14) - (14)].stmt).NL;
			}
		}
    break;

  case 193:
/* Line 1787 of yacc.c  */
#line 1145 "ass5_12CS10006.y"
    {}
    break;

  case 194:
/* Line 1787 of yacc.c  */
#line 1148 "ass5_12CS10006.y"
    { }
    break;

  case 195:
/* Line 1787 of yacc.c  */
#line 1149 "ass5_12CS10006.y"
    { }
    break;

  case 196:
/* Line 1787 of yacc.c  */
#line 1150 "ass5_12CS10006.y"
    { }
    break;

  case 197:
/* Line 1787 of yacc.c  */
#line 1151 "ass5_12CS10006.y"
    { 
				
					if((yyvsp[(2) - (3)].exp).symptr) qarr.emit(RETURN,(yyvsp[(2) - (3)].exp).symptr->name);  
					else qarr.emit(RETURN);
					(yyval.stmt).NL=NULL; }
    break;

  case 198:
/* Line 1787 of yacc.c  */
#line 1160 "ass5_12CS10006.y"
    {}
    break;

  case 199:
/* Line 1787 of yacc.c  */
#line 1161 "ass5_12CS10006.y"
    { }
    break;

  case 200:
/* Line 1787 of yacc.c  */
#line 1164 "ass5_12CS10006.y"
    {}
    break;

  case 201:
/* Line 1787 of yacc.c  */
#line 1165 "ass5_12CS10006.y"
    {}
    break;

  case 202:
/* Line 1787 of yacc.c  */
#line 1170 "ass5_12CS10006.y"
    {  
                         //printf("\ndddddddddfffffddddddddn\n\n");
			ST_funt=&ST_gl;
			ST_funt->update(new Type_Data((yyvsp[(1) - (3)].t_exp).type),(yyvsp[(2) - (3)].symp)); 
                        if(!(yyvsp[(2) - (3)].symp)->stptr) (yyvsp[(2) - (3)].symp)->stptr=new symtable; 
		        SYMT_ROW* l=(yyvsp[(2) - (3)].symp)->stptr->lookup("retval");
                        (yyvsp[(2) - (3)].symp)->stptr->update(new Type_Data((yyvsp[(1) - (3)].t_exp).type),l); 	
			//backpatch($3.NL,PC+$4);                           
		   }
    break;


/* Line 1787 of yacc.c  */
#line 3483 "y.tab.c"
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2050 of yacc.c  */
#line 1184 "ass5_12CS10006.y"

void yyerror(char *s) {
  printf("%s at line no.:%d\n",s,no_lines);
}

