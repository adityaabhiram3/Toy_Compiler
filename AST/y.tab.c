/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     HASH = 258,
     INCLUDE = 259,
     IOSTREAM = 260,
     STDLIB = 261,
     MATH = 262,
     STRING = 263,
     TIME = 264,
     STRING_LITERAL = 265,
     HEADER_LITERAL = 266,
     COUT = 267,
     RETURN = 268,
     INTEGER_LITERAL = 269,
     CHARACTER_LITERAL = 270,
     FLOAT_LITERAL = 271,
     IDENTIFIER = 272,
     INC_OP = 273,
     DEC_OP = 274,
     LE_OP = 275,
     GE_OP = 276,
     EQ_OP = 277,
     NE_OP = 278,
     MUL_ASSIGN = 279,
     DIV_ASSIGN = 280,
     MOD_ASSIGN = 281,
     ADD_ASSIGN = 282,
     SUB_ASSIGN = 283,
     CHAR = 284,
     INT = 285,
     FLOAT = 286,
     VOID = 287,
     FOR = 288,
     WHILE = 289,
     IF = 290,
     ELSE = 291
   };
#endif
/* Tokens.  */
#define HASH 258
#define INCLUDE 259
#define IOSTREAM 260
#define STDLIB 261
#define MATH 262
#define STRING 263
#define TIME 264
#define STRING_LITERAL 265
#define HEADER_LITERAL 266
#define COUT 267
#define RETURN 268
#define INTEGER_LITERAL 269
#define CHARACTER_LITERAL 270
#define FLOAT_LITERAL 271
#define IDENTIFIER 272
#define INC_OP 273
#define DEC_OP 274
#define LE_OP 275
#define GE_OP 276
#define EQ_OP 277
#define NE_OP 278
#define MUL_ASSIGN 279
#define DIV_ASSIGN 280
#define MOD_ASSIGN 281
#define ADD_ASSIGN 282
#define SUB_ASSIGN 283
#define CHAR 284
#define INT 285
#define FLOAT 286
#define VOID 287
#define FOR 288
#define WHILE 289
#define IF 290
#define ELSE 291




/* Copy the first part of user declarations.  */
#line 1 "ast.y"

#include <iostream>
#include <stdio.h>
using namespace std;
	#include <stdlib.h>
	#include <string.h>
	#include <limits.h>
	void yyerror(const char*);
	int yylex();
	extern FILE * yyin, *yyout;

	int x=0;	

	extern int line;
	
	int scope = 0;

	int unaryop = -1;		
	int assignop = -1;		
	int datatype = -1;		
	int assigntype = -1;	
	int idcheck = -1;		
	int check_un = 0;		


	char tempStr[100];

	struct node{
		char token[20];
		char name[20];
		int dtype;
		int scope;
		int lineno;
		int valid;
		union value{
			float f;
			int i;
			char c;
		}val;
		
		struct node *link;

	}*first = NULL, *tmp, *crt, *lhs;

	typedef struct Node{
		struct Node *left;
		struct Node *right;
		char token[100];
		struct Node *val;
		int level;
	}Node;

	typedef struct tree_stack{
		Node *node;
		struct tree_stack *next;
	}tree_stack;
	tree_stack *tree_top = NULL;
	char preBuf[1000000];
	struct node * checksym(char *);
	void addsymbol(struct node *,char *);	
	void addInt(struct node *, int, int);
	void addFloat(struct node *, int, float);
	void addChar(struct node *, int, char);
	void addfunc(struct node *t, int, char *);
	struct node * addtosymbol(struct node * n);
	void cleansymbol();
	void printtable();
	//AST 
	void create_node(char *token, int leaf);
	void push_tree(Node *newnode);
	Node *pop_tree();
	void preorder(Node* root);




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 83 "ast.y"
{
	int ival;
	float fval;
	char cval;
	char string[128];
	struct node *ptr;
}
/* Line 193 of yacc.c.  */
#line 252 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 265 "y.tab.c"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   250

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNRULES -- Number of states.  */
#define YYNSTATES  175

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,     2,     2,    18,     2,     2,
      48,    49,    17,    14,    50,    15,     2,    16,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,    47,
      43,    19,    44,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,    54,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    55,    56
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,    12,    17,    19,    21,    24,    26,
      28,    30,    32,    34,    36,    38,    41,    45,    47,    50,
      52,    54,    57,    60,    63,    68,    73,    75,    79,    81,
      83,    85,    87,    95,   101,   107,   115,   117,   119,   121,
     123,   125,   129,   130,   135,   137,   139,   140,   145,   147,
     149,   151,   153,   155,   157,   159,   165,   167,   170,   172,
     176,   178,   180,   182,   184,   188,   190,   193,   196,   198,
     201,   203,   205,   207,   209,   211,   213,   215,   219,   223,
     225,   229,   233,   237,   241,   243,   247,   251,   253,   257,
     261,   265,   269,   272,   277,   281,   283,   288,   293,   297,
     299,   303,   306,   308,   310
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,    59,    -1,     3,     4,    43,    62,    44,
      59,    -1,     3,     4,    11,    59,    -1,    60,    -1,    61,
      -1,    60,    61,    -1,    68,    -1,    90,    -1,     5,    -1,
       6,    -1,     7,    -1,     8,    -1,     9,    -1,    45,    46,
      -1,    45,    64,    46,    -1,    65,    -1,    64,    65,    -1,
      68,    -1,    69,    -1,    91,    47,    -1,    13,    80,    -1,
      66,    47,    -1,    12,    43,    43,    67,    -1,    10,    43,
      43,    67,    -1,    10,    -1,    72,    73,    47,    -1,    63,
      -1,    80,    -1,    70,    -1,    71,    -1,    39,    48,    80,
      80,    81,    49,    69,    -1,    40,    48,    81,    49,    69,
      -1,    41,    48,    81,    49,    69,    -1,    41,    48,    81,
      49,    69,    42,    69,    -1,    38,    -1,    35,    -1,    36,
      -1,    37,    -1,    74,    -1,    73,    50,    74,    -1,    -1,
      23,    75,    19,    76,    -1,    23,    -1,    79,    -1,    -1,
      84,    77,    78,    76,    -1,    19,    -1,    33,    -1,    34,
      -1,    30,    -1,    31,    -1,    32,    -1,    86,    -1,    86,
      51,    81,    52,    79,    -1,    47,    -1,    81,    47,    -1,
      76,    -1,    81,    50,    76,    -1,    23,    -1,    20,    -1,
      22,    -1,    21,    -1,    48,    81,    49,    -1,    82,    -1,
      83,    24,    -1,    83,    25,    -1,    83,    -1,    85,    84,
      -1,    14,    -1,    15,    -1,    53,    -1,    54,    -1,    55,
      -1,    56,    -1,    87,    -1,    86,    28,    87,    -1,    86,
      29,    87,    -1,    88,    -1,    87,    43,    88,    -1,    87,
      44,    88,    -1,    87,    26,    88,    -1,    87,    27,    88,
      -1,    89,    -1,    88,    14,    89,    -1,    88,    15,    89,
      -1,    84,    -1,    89,    17,    84,    -1,    89,    16,    84,
      -1,    89,    18,    84,    -1,    72,    92,    63,    -1,    92,
      63,    -1,    92,    48,    95,    49,    -1,    92,    48,    49,
      -1,    23,    -1,    92,    48,    93,    49,    -1,    92,    48,
      95,    49,    -1,    92,    48,    49,    -1,    94,    -1,    93,
      50,    94,    -1,    72,    23,    -1,    72,    -1,    23,    -1,
      95,    50,    23,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   119,   119,   128,   129,   130,   135,   136,   141,   142,
     147,   148,   149,   150,   151,   156,   157,   162,   163,   171,
     172,   173,   174,   175,   180,   183,   183,   186,   191,   203,
     204,   205,   211,   216,   220,   221,   224,   225,   226,   227,
     232,   233,   238,   238,   328,   393,   394,   394,   589,   590,
     591,   592,   593,   594,   599,   600,   615,   616,   621,   622,
     627,   657,   666,   684,   702,   709,   710,   711,   716,   717,
     745,   746,   747,   748,   749,   750,   755,   756,   765,   777,
     778,   787,   796,   805,   818,   819,   824,   833,   834,   839,
     850,   866,   884,   908,   909,   914,   920,   921,   922,   927,
     928,   933,   934,   939,   940
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "HASH", "INCLUDE", "IOSTREAM", "STDLIB",
  "MATH", "STRING", "TIME", "STRING_LITERAL", "HEADER_LITERAL", "COUT",
  "RETURN", "'+'", "'-'", "'/'", "'*'", "'%'", "'='", "INTEGER_LITERAL",
  "CHARACTER_LITERAL", "FLOAT_LITERAL", "IDENTIFIER", "INC_OP", "DEC_OP",
  "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "CHAR", "INT", "FLOAT", "VOID",
  "FOR", "WHILE", "IF", "ELSE", "'<'", "'>'", "'{'", "'}'", "';'", "'('",
  "')'", "','", "'?'", "':'", "'!'", "'~'", "\"INC_OP\"", "\"DEC_OP\"",
  "$accept", "S", "program", "translation_unit", "ext_dec", "libraries",
  "compound_statement", "block_item_list", "block_item", "printstat", "a",
  "declaration", "statement", "iteration_statement", "basic_loop",
  "type_specifier", "init_declarator_list", "init_declarator", "@1",
  "assignment_expression", "@2", "assignment_operator",
  "conditional_expression", "expression_statement", "expression",
  "primary_expression", "postfix_expression", "unary_expression",
  "unary_operator", "equality_expression", "relational_expression",
  "additive_expression", "multiplicative_expression",
  "function_definition", "function_call", "declarator", "parameter_list",
  "parameter_declaration", "identifier_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,    43,    45,    47,    42,    37,    61,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,    60,    62,   123,   125,    59,    40,    41,
      44,    63,    58,    33,   126,   292,   293
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    59,    60,    60,    61,    61,
      62,    62,    62,    62,    62,    63,    63,    64,    64,    65,
      65,    65,    65,    65,    66,    67,    67,    68,    69,    69,
      69,    69,    70,    70,    71,    71,    72,    72,    72,    72,
      73,    73,    75,    74,    74,    76,    77,    76,    78,    78,
      78,    78,    78,    78,    79,    79,    80,    80,    81,    81,
      82,    82,    82,    82,    82,    83,    83,    83,    84,    84,
      85,    85,    85,    85,    85,    85,    86,    86,    86,    87,
      87,    87,    87,    87,    88,    88,    88,    89,    89,    89,
      89,    90,    90,    91,    91,    92,    92,    92,    92,    93,
      93,    94,    94,    95,    95
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     6,     4,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     1,     2,     1,
       1,     2,     2,     2,     4,     4,     1,     3,     1,     1,
       1,     1,     7,     5,     5,     7,     1,     1,     1,     1,
       1,     3,     0,     4,     1,     1,     0,     4,     1,     1,
       1,     1,     1,     1,     1,     5,     1,     2,     1,     3,
       1,     1,     1,     1,     3,     1,     2,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     2,     4,     3,     1,     4,     4,     3,     1,
       3,     2,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    95,    37,    38,    39,    36,     0,     2,     5,
       6,     8,     0,     9,     0,     0,     1,     7,    44,     0,
      40,     0,     0,     0,    92,     0,     0,     0,    27,     0,
      91,     0,     0,    70,    71,    61,    63,    62,    60,     0,
       0,     0,    15,    56,     0,    72,    73,    74,    75,    28,
       0,    17,     0,    19,    20,    30,    31,     0,    58,    45,
      29,     0,    65,    68,    87,     0,    54,    76,    79,    84,
       0,     0,   103,    98,   102,     0,    99,     0,     4,    10,
      11,    12,    13,    14,     0,     0,    44,    41,     0,    60,
      22,     0,     0,     0,     0,    16,    18,    23,    57,     0,
      66,    67,     0,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,   101,    96,
       0,    97,     0,     0,    43,     0,     0,     0,     0,    64,
      59,    48,    51,    52,    53,    49,    50,     0,    87,    77,
      78,     0,    82,    83,    80,    81,    85,    86,    89,    88,
      90,    94,     0,   100,   104,     3,    26,    24,     0,     0,
       0,    47,     0,    93,     0,     0,    33,    34,    55,     0,
       0,     0,    25,    32,    35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    84,    49,    50,    51,    52,
     157,    11,    54,    55,    56,    12,    19,    20,    27,    58,
     102,   137,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    13,    70,    14,    75,    76,    77
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -144
static const yytype_int16 yypact[] =
{
      44,     5,  -144,  -144,  -144,  -144,  -144,    19,  -144,   195,
    -144,  -144,     7,  -144,    52,     9,  -144,  -144,   -14,   109,
    -144,    52,    90,    83,  -144,    44,    78,    88,  -144,    86,
    -144,    73,    18,  -144,  -144,  -144,  -144,  -144,    76,   103,
     113,   121,  -144,  -144,    22,  -144,  -144,  -144,  -144,  -144,
     127,  -144,   111,  -144,  -144,  -144,  -144,    86,  -144,  -144,
    -144,   110,  -144,   -10,    -9,    22,    40,   172,   108,    72,
     145,   146,  -144,  -144,   177,    84,  -144,   135,  -144,  -144,
    -144,  -144,  -144,  -144,   158,    22,   198,  -144,   186,  -144,
    -144,    18,    22,    22,   137,  -144,  -144,  -144,  -144,    22,
    -144,  -144,   194,  -144,    22,    22,    22,    22,    22,    22,
      22,    22,    22,    22,    22,    22,  -144,   170,  -144,  -144,
      57,  -144,   191,    44,  -144,   228,    18,   139,   141,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,    22,  -144,   172,
     172,    65,   108,   108,   108,   108,    72,    72,  -144,  -144,
    -144,   192,   171,  -144,  -144,  -144,   196,  -144,    22,   156,
     156,  -144,    22,   193,   199,   173,  -144,   201,  -144,   228,
     156,   156,  -144,  -144,  -144
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,   -22,  -144,   235,  -144,    -8,  -144,   197,  -144,
      77,   -15,  -143,  -144,  -144,   -21,  -144,   216,  -144,   -73,
    -144,  -144,    87,   -28,   -44,  -144,  -144,   -54,  -144,  -144,
     130,    45,   125,  -144,  -144,    -4,  -144,   128,   133
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -99
static const yytype_int16 yytable[] =
{
      94,    57,    74,    78,    90,   -42,    24,    53,    21,    15,
     -46,   103,   124,    30,   100,   101,   166,   167,    71,    16,
      25,   -46,   -46,   -46,   -46,   -46,   130,   173,   174,    57,
      18,   -95,    33,    34,   -95,    53,    33,    34,    35,    36,
      37,    89,    35,    36,    37,    89,    71,     1,   127,   128,
     138,   138,    26,   138,   138,   138,   138,   138,   138,   148,
     149,   150,   141,   126,   161,    43,    44,     2,   104,   105,
      44,    45,    46,    47,    48,    45,    46,    47,    48,     3,
       4,     5,     6,    79,    80,    81,    82,    83,   113,   114,
     115,   106,     3,     4,     5,     6,    74,    22,   158,    74,
      23,   155,    31,    32,    33,    34,    72,    85,   138,    86,
      35,    36,    37,    38,   165,    99,    88,   162,     3,     4,
       5,     6,   111,   112,   -95,     3,     4,     5,     6,    39,
      40,    41,    73,   119,   120,    22,    42,    43,    44,    31,
      32,    33,    34,    45,    46,    47,    48,    35,    36,    37,
      38,    91,   142,   143,   144,   145,    28,    98,    97,    29,
      99,    92,     3,     4,     5,     6,    39,    40,    41,    93,
      33,    34,    22,    95,    43,    44,    35,    36,    37,    89,
      45,    46,    47,    48,   121,   122,   129,    99,   159,    99,
     160,    99,   116,    72,   117,    39,    40,    41,   107,   108,
     118,    22,   123,    43,    44,     3,     4,     5,     6,    45,
      46,    47,    48,   131,   154,   109,   110,   -42,     2,   151,
     163,   122,   170,    99,   132,   133,   134,   135,   136,   125,
       3,     4,     5,     6,   139,   140,   146,   147,   156,   164,
     -98,   -97,   169,   171,    17,    87,   172,    96,   153,   168,
     152
};

static const yytype_uint8 yycheck[] =
{
      44,    22,    23,    25,    32,    19,    14,    22,    12,     4,
      19,    65,    85,    21,    24,    25,   159,   160,    22,     0,
      11,    30,    31,    32,    33,    34,    99,   170,   171,    50,
      23,    45,    14,    15,    48,    50,    14,    15,    20,    21,
      22,    23,    20,    21,    22,    23,    50,     3,    92,    93,
     104,   105,    43,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   106,    91,   137,    47,    48,    23,    28,    29,
      48,    53,    54,    55,    56,    53,    54,    55,    56,    35,
      36,    37,    38,     5,     6,     7,     8,     9,    16,    17,
      18,    51,    35,    36,    37,    38,   117,    45,   126,   120,
      48,   123,    12,    13,    14,    15,    23,    19,   162,    23,
      20,    21,    22,    23,   158,    50,    43,    52,    35,    36,
      37,    38,    14,    15,    48,    35,    36,    37,    38,    39,
      40,    41,    49,    49,    50,    45,    46,    47,    48,    12,
      13,    14,    15,    53,    54,    55,    56,    20,    21,    22,
      23,    48,   107,   108,   109,   110,    47,    47,    47,    50,
      50,    48,    35,    36,    37,    38,    39,    40,    41,    48,
      14,    15,    45,    46,    47,    48,    20,    21,    22,    23,
      53,    54,    55,    56,    49,    50,    49,    50,    49,    50,
      49,    50,    47,    23,    48,    39,    40,    41,    26,    27,
      23,    45,    44,    47,    48,    35,    36,    37,    38,    53,
      54,    55,    56,    19,    23,    43,    44,    19,    23,    49,
      49,    50,    49,    50,    30,    31,    32,    33,    34,    43,
      35,    36,    37,    38,   104,   105,   111,   112,    10,    43,
      48,    48,    43,    42,     9,    29,   169,    50,   120,   162,
     117
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    23,    35,    36,    37,    38,    58,    59,    60,
      61,    68,    72,    90,    92,     4,     0,    61,    23,    73,
      74,    92,    45,    48,    63,    11,    43,    75,    47,    50,
      63,    12,    13,    14,    15,    20,    21,    22,    23,    39,
      40,    41,    46,    47,    48,    53,    54,    55,    56,    63,
      64,    65,    66,    68,    69,    70,    71,    72,    76,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      91,    92,    23,    49,    72,    93,    94,    95,    59,     5,
       6,     7,     8,     9,    62,    19,    23,    74,    43,    23,
      80,    48,    48,    48,    81,    46,    65,    47,    47,    50,
      24,    25,    77,    84,    28,    29,    51,    26,    27,    43,
      44,    14,    15,    16,    17,    18,    47,    48,    23,    49,
      50,    49,    50,    44,    76,    43,    80,    81,    81,    49,
      76,    19,    30,    31,    32,    33,    34,    78,    84,    87,
      87,    81,    88,    88,    88,    88,    89,    89,    84,    84,
      84,    49,    95,    94,    23,    59,    10,    67,    80,    49,
      49,    76,    52,    49,    43,    81,    69,    69,    79,    43,
      49,    42,    67,    69,    69
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
#line 119 "ast.y"
    {
		cleansymbol();
		printtable();
          
                return 0;
            }
    break;

  case 18:
#line 164 "ast.y"
    {
				create_node("stmt", 0);
			}
    break;

  case 28:
#line 191 "ast.y"
    {
						struct node *ftp;
						ftp = first;
						while(ftp!=NULL){
							if(ftp->scope == scope && ftp->valid == 1){
								ftp->valid = 0;
							}
							ftp=ftp->link;
						}
						scope--;

					}
    break;

  case 32:
#line 212 "ast.y"
    { 
				
				create_node("for", 0); 
			}
    break;

  case 33:
#line 216 "ast.y"
    {create_node("while",0);}
    break;

  case 34:
#line 220 "ast.y"
    {create_node("if",0);}
    break;

  case 35:
#line 221 "ast.y"
    {create_node("if-else",0);}
    break;

  case 36:
#line 224 "ast.y"
    {	datatype = (yyvsp[(1) - (1)].ival); }
    break;

  case 37:
#line 225 "ast.y"
    {	datatype = (yyvsp[(1) - (1)].ival); }
    break;

  case 38:
#line 226 "ast.y"
    {	datatype = (yyvsp[(1) - (1)].ival); }
    break;

  case 39:
#line 227 "ast.y"
    {	datatype = (yyvsp[(1) - (1)].ival); }
    break;

  case 42:
#line 238 "ast.y"
    { create_node((yyvsp[(1) - (1)].ptr)->name, 1); }
    break;

  case 43:
#line 239 "ast.y"
    {	


						if((yyvsp[(1) - (4)].ptr)->dtype !=- 1 && (yyvsp[(1) - (4)].ptr)->scope < scope && (yyvsp[(1) - (4)].ptr)->valid == 1){
						
																		
							struct node *ftp, *nnode;
							nnode = (struct node *)malloc(sizeof(struct node));
							ftp = first;
							while(ftp->link!=NULL){
								ftp = ftp->link;
							}
							addsymbol(nnode,(yyvsp[(1) - (4)].ptr)->name);	
							ftp->link = nnode;
							nnode->link = NULL;
							(yyvsp[(1) - (4)].ptr) = nnode;

							if (datatype == 0){	
								
								addInt((yyvsp[(1) - (4)].ptr), 0, (yyvsp[(4) - (4)].fval));
								if(assigntype == 1){
									cout<<"Line:"<<line<<"\n";
									cout<<"implicit conversion from \'float\' to \'int\' \n\n";
								}
							}
							else if(datatype == 1){
								
								addFloat((yyvsp[(1) - (4)].ptr), 1, (yyvsp[(4) - (4)].fval));
								if(assigntype == 2){
									cout<<"Line:"<<line<<"\n";
									cout<<"implicit conversion from \'char\' to \'float\' \n\n";
								}
							}
							else if(datatype == 2){
								float tempf = (float)(yyvsp[(4) - (4)].fval);
								addChar((yyvsp[(1) - (4)].ptr), 2, (int)tempf);

								if(assigntype == 1){
									cout<<"Line:"<<line<<"\n";
									cout<<"implicit conversion from \'float\' to \'char\' \n\n";
								}
							}
							x = datatype;
							
							create_node("=", 0);

						}

						
						else if((yyvsp[(1) - (4)].ptr)->dtype !=- 1){

							cout<<"Line:"<<line<<"\n";
							cout<<"redefinition of "<< (yyvsp[(1) - (4)].ptr)->name<<"\n";
						}
						else{
							
							
							create_node("=", 0);

							if (datatype == 0){	
								
								addInt((yyvsp[(1) - (4)].ptr), 0, (yyvsp[(4) - (4)].fval));
								if(assigntype == 1){
									cout<<"Line:"<<line<<"\n";
										cout<<"implicit conversion from \'float\' to \'int\' \n\n";
								}
							}
							else if(datatype == 1){
								
								addFloat((yyvsp[(1) - (4)].ptr), 1, (yyvsp[(4) - (4)].fval));
								if(assigntype == 2){
									cout<<"Line:"<<line<<"\n";
									cout<<"implicit conversion from \'char\' to \'float\' \n\n";
								}
							}
							else if(datatype == 2){
								float tempf = (float)(yyvsp[(4) - (4)].fval);
								addChar((yyvsp[(1) - (4)].ptr), 2, (int)tempf);

								if(assigntype == 1){
									cout<<"Line:"<<line<<"\n";
									cout<<"implicit conversion from \'float\' to \'char\' \n\n";
								}
							}
							x = datatype;
							
						}
					}
    break;

  case 44:
#line 328 "ast.y"
    {	
						if((yyvsp[(1) - (1)].ptr)->dtype !=- 1 && (yyvsp[(1) - (1)].ptr)->scope < scope && (yyvsp[(1) - (1)].ptr)->valid == 1){
							
																		
							struct node *ftp, *nnode;
							nnode = (struct node *)malloc(sizeof(struct node));
							ftp = first;
							while(ftp->link!=NULL){
								ftp = ftp->link;
							}
							addsymbol(nnode,(yyvsp[(1) - (1)].ptr)->name);	
							ftp->link = nnode;
							nnode->link = NULL;							
							(yyvsp[(1) - (1)].ptr) = nnode;
							
							if (datatype == 0){	
								addInt((yyvsp[(1) - (1)].ptr), 0, INT_MIN);
							}
							else if(datatype == 1){
								addFloat((yyvsp[(1) - (1)].ptr), 1, INT_MIN);
							}
							else if(datatype == 2){
								addChar((yyvsp[(1) - (1)].ptr), 2, '-');
		
							}
							x = datatype;

							char buff[20];
							strcpy(buff, "Declaration ");
							strcat(buff, (yyvsp[(1) - (1)].ptr)->name);
						
							create_node(buff, 1);
							

						}
						else if((yyvsp[(1) - (1)].ptr)->dtype !=- 1 ){
							cout<<"Line:"<<line<<"\n";
							cout<<"redefinition of "<< (yyvsp[(1) - (1)].ptr)->name<<"\n";
						
						}else{
							

							if (datatype == 0){	
								addInt((yyvsp[(1) - (1)].ptr), 0, INT_MIN);
							}
							else if(datatype == 1){
								addFloat((yyvsp[(1) - (1)].ptr), 1, INT_MIN);
							}
							else if(datatype == 2){
								addChar((yyvsp[(1) - (1)].ptr), 2, '-');
		
							}
							x = datatype;

							char buff[20];
							strcpy(buff, "Declaration ");
							strcat(buff, (yyvsp[(1) - (1)].ptr)->name);
							create_node(buff, 1);
						
						}
					}
    break;

  case 45:
#line 393 "ast.y"
    {	(yyval.fval) = (yyvsp[(1) - (1)].fval); }
    break;

  case 46:
#line 394 "ast.y"
    { crt = lhs; }
    break;

  case 47:
#line 395 "ast.y"
    {							
				switch(assignop){
					case 0: if(idcheck == 1){
								create_node("=", 0);
								if(crt->dtype == 0){
									if(assigntype == 1){
										cout<<"Line:"<<line<<"\n";
										cout<<"implicit conversion from \'float\' to \'int\' \n\n";
									}
									crt->val.i = (int)(yyvsp[(4) - (4)].fval);
									
								}
								else if(crt->dtype == 1){
									if(assigntype == 2){
										cout<<"Line:"<<line<<"\n";
										cout<<"implicit conversion from \'char\' to \'float\' \n\n";
									}
									crt->val.f = (yyvsp[(4) - (4)].fval);
								}
								else if(crt->dtype == 2){
									if(assigntype == 1){
										cout<<"Line:"<<line<<"\n";
										cout<<"implicit conversion from \'float\' to \'char\' \n\n";
									}
									crt->val.c = (char)((int)(yyvsp[(4) - (4)].fval));
								}
							}
							else{
								cout<<"We'll see later\n";
							}
							crt = NULL;
							break;

					case 1: if(idcheck == 1){
								create_node("+=", 0);
								if(crt->dtype == 0){
									if(assigntype == 1){
										cout<<"Line:"<<line<<"\n";
										cout<<"implicit conversion from \'float\' to \'int\' \n\n";
									}
									crt->val.i = (int)(yyvsp[(1) - (4)].fval) + (int)(yyvsp[(4) - (4)].fval);
								}
								else if(crt->dtype == 1){
									if(assigntype == 2){
										cout<<"Line:"<<line<<"\n";
										cout<<"implicit conversion from \'char\' to \'float\' \n\n";
									}
									crt->val.f = (yyvsp[(1) - (4)].fval)+ (yyvsp[(4) - (4)].fval);
								}
								else if(crt->dtype == 2){
									if(assigntype == 1){
										cout<<"Line:"<<line<<"\n";
										cout<<"implicit conversion from \'float\' to \'char\' \n\n";
									}
									crt->val.c = (char)((int)(yyvsp[(1) - (4)].fval) + (int)(yyvsp[(4) - (4)].fval));
								}
							}
							else{
								cout<<"We'll see later\n";
							}
							crt = NULL;
							break;

					case 2:	if(idcheck == 1){
							create_node("-=", 0);
								if(crt->dtype == 0){
									if(assigntype == 1){
										cout<<"Line:"<<line<<"\n";
										cout<<"implicit conversion from \'float\' to \'int\' \n\n";
									}
									crt->val.i = (int)(yyvsp[(1) - (4)].fval) - (int)(yyvsp[(4) - (4)].fval);
								}
								else if(crt->dtype == 1){
									if(assigntype == 2){
										cout<<"Line:"<<line<<"\n";
										cout<<"implicit conversion from \'char\' to \'float\' \n\n";
									}
									crt->val.f = (yyvsp[(1) - (4)].fval) - (yyvsp[(4) - (4)].fval);
								}
								else if(crt->dtype == 2){
									if(assigntype == 1){
										cout<<"Line:"<<line<<"\n";
										cout<<"implicit conversion from \'float\' to \'char\' \n\n";
									}
									crt->val.c = (char)((int)(yyvsp[(1) - (4)].fval) - (int)(yyvsp[(4) - (4)].fval));
								}
							}
							else{
								cout<<"We'll see later\n";
							}
							crt = NULL;
							break;

					case 3:	if(idcheck == 1){
								create_node("*=", 0);
								if(crt->dtype == 0){
									if(assigntype == 1){
										cout<<"Line:"<<line<<"\n";
										cout<<"implicit conversion from \'float\' to \'int\' \n\n";
									}
									crt->val.i = (int)(yyvsp[(1) - (4)].fval) * (int)(yyvsp[(4) - (4)].fval);
								}
								else if(crt->dtype == 1){
									if(assigntype == 2){
										cout<<"Line:"<<line<<"\n";
										cout<<"implicit conversion from \'char\' to \'float\' \n\n";
									}
									crt->val.f = (yyvsp[(1) - (4)].fval) * (yyvsp[(4) - (4)].fval);
								}
								else if(crt->dtype == 2){
									if(assigntype == 1){
										cout<<"Line:"<<line<<"\n";
										cout<<"implicit conversion from \'float\' to \'char\' \n\n";
									}
									crt->val.c = (char)((int)(yyvsp[(1) - (4)].fval) * (int)(yyvsp[(4) - (4)].fval));
								}
							}
							else{
								cout<<"We'll see later\n";
							}
							crt = NULL;
							break;

					case 4:	if(idcheck == 1){
								create_node("/=", 0);
								if(crt->dtype == 0){
									if(assigntype == 1){
										cout<<"Line:"<<line<<"\n";
										cout<<"implicit conversion from \'float\' to \'int\' \n\n";
									}
									crt->val.i = (int)(yyvsp[(1) - (4)].fval) / (int)(yyvsp[(4) - (4)].fval);
								}
								else if(crt->dtype == 1){
									if(assigntype == 2){
										cout<<"Line:"<<line<<"\n";
										cout<<"implicit conversion from \'char\' to \'float\' \n\n";
									}
									crt->val.f = (yyvsp[(1) - (4)].fval) / (yyvsp[(4) - (4)].fval);
								}
								else if(crt->dtype == 2){
									if(assigntype == 1){
										cout<<"Line:"<<line<<"\n";
										cout<<"implicit conversion from \'float\' to \'char\' \n\n";
									}
									crt->val.c = (char)((int)(yyvsp[(1) - (4)].fval) / (int)(yyvsp[(4) - (4)].fval));
								}
							}
							else{
								cout<<"We'll see later\n";
							}
							crt = NULL;
							break;

					case 5:	if(idcheck == 1){
								create_node("%=", 0);
								if(crt->dtype == 0){
									if(assigntype == 1){
										cout<<"Line:"<<line<<"\n";
										cout<<"implicit conversion from \'float\' to \'int\' \n\n";
									}
									crt->val.i = (int)(yyvsp[(1) - (4)].fval) % (int)(yyvsp[(4) - (4)].fval);
								}
								else if(crt->dtype == 1){
									if(assigntype == 2){
										cout<<"Line:"<<line<<"\n";
										cout<<"implicit conversion from \'char\' to \'float\' \n\n";
									}
									crt->val.f = (int)(yyvsp[(1) - (4)].fval) % (int)(yyvsp[(4) - (4)].fval);
								}
								else if(crt->dtype == 2){
									if(assigntype == 1){
										cout<<"Line:"<<line<<"\n";
										cout<<"implicit conversion from \'float\' to \'char\' \n\n";
									}
									crt->val.c = (char)((int)(yyvsp[(1) - (4)].fval) % (int)(yyvsp[(4) - (4)].fval));
								}
							}
							else{
								cout<<"We'll see later\n";
							}
							crt = NULL;
							break;


				}
				assignop = -1;
				assigntype = -1;
			}
    break;

  case 48:
#line 589 "ast.y"
    {	assignop = 0;	}
    break;

  case 49:
#line 590 "ast.y"
    {	assignop = 1;	}
    break;

  case 50:
#line 591 "ast.y"
    {	assignop = 2;	}
    break;

  case 51:
#line 592 "ast.y"
    {	assignop = 3;	}
    break;

  case 52:
#line 593 "ast.y"
    {	assignop = 4;	}
    break;

  case 53:
#line 594 "ast.y"
    {	assignop = 5;	}
    break;

  case 54:
#line 599 "ast.y"
    {	(yyval.fval) = (yyvsp[(1) - (1)].fval);	}
    break;

  case 55:
#line 601 "ast.y"
    {
				create_node("else", 0);
				create_node("if", 0);
				if((yyvsp[(1) - (5)].fval) == 1){
					(yyval.fval) = (yyvsp[(3) - (5)].fval);

				}else{
					(yyval.fval) = (yyvsp[(5) - (5)].fval);
				}
			}
    break;

  case 56:
#line 615 "ast.y"
    {				}
    break;

  case 57:
#line 616 "ast.y"
    {				}
    break;

  case 58:
#line 621 "ast.y"
    {		}
    break;

  case 59:
#line 622 "ast.y"
    {		}
    break;

  case 60:
#line 628 "ast.y"
    {					
					idcheck = 1;
					lhs = (yyvsp[(1) - (1)].ptr);

					if((yyvsp[(1) - (1)].ptr)->dtype == -1 && check_un == 0){
						cout<<"Line:"<<line;
						cout<<"use of undeclared identifier"<<(yyvsp[(1) - (1)].ptr)->name<<"\n\n";

						check_un = 0;	

					}
					else if((yyvsp[(1) - (1)].ptr)->dtype == 0){
						(yyval.fval) = (yyvsp[(1) - (1)].ptr)->val.i;
						assigntype = 0;
						create_node((yyvsp[(1) - (1)].ptr)->name, 1);
					}
					else if((yyvsp[(1) - (1)].ptr)->dtype == 1){
						(yyval.fval) = (yyvsp[(1) - (1)].ptr)->val.f;
						assigntype = 1;
						create_node((yyvsp[(1) - (1)].ptr)->name, 1);
					}
					else if((yyvsp[(1) - (1)].ptr)->dtype == 2){
						(yyval.fval) = (yyvsp[(1) - (1)].ptr)->val.c;
						assigntype = 2;
						create_node((yyvsp[(1) - (1)].ptr)->name, 1);
					}
						
									
				}
    break;

  case 61:
#line 658 "ast.y"
    {
					(yyval.fval) = (yyvsp[(1) - (1)].ival);
					assigntype = 0;
				
					sprintf(tempStr, "%d", (int)(yyvsp[(1) - (1)].ival));
					create_node(tempStr, 1);
				}
    break;

  case 62:
#line 667 "ast.y"
    {	
					assigntype = 1;
					if(datatype == 1){
						(yyval.fval) = (yyvsp[(1) - (1)].fval);
					}
					else if(datatype == 0){
						
						(yyval.fval) = (int)(yyvsp[(1) - (1)].fval);
					}
					else if(datatype == 2){

						(yyval.fval) = (int)(yyvsp[(1) - (1)].fval);
					}

					sprintf(tempStr, "%f", (yyvsp[(1) - (1)].fval));
					create_node(tempStr, 1);
				}
    break;

  case 63:
#line 685 "ast.y"
    {	
					assigntype = 2;
					if(datatype == 2){
						int tempc = (int)(yyvsp[(1) - (1)].cval);
						(yyval.fval) =  (float)tempc;
					}
					else if(datatype == 0){
						(yyval.fval) = (int)(yyvsp[(1) - (1)].cval);
					}
					else if(datatype == 1){
						
						(yyval.fval) = (int)(yyvsp[(1) - (1)].cval);
					}

					sprintf(tempStr, "%c", (yyvsp[(1) - (1)].cval));
					create_node(tempStr, 1);
				}
    break;

  case 64:
#line 703 "ast.y"
    {
					(yyval.fval) = (yyvsp[(2) - (3)].fval);
				}
    break;

  case 65:
#line 709 "ast.y"
    {	(yyval.fval) = (yyvsp[(1) - (1)].fval);	}
    break;

  case 66:
#line 710 "ast.y"
    {	(yyvsp[(1) - (2)].fval)++; (yyval.fval) = (yyvsp[(1) - (2)].fval);	create_node("++", 0); }
    break;

  case 67:
#line 711 "ast.y"
    {	(yyvsp[(1) - (2)].fval)--; (yyval.fval) = (yyvsp[(1) - (2)].fval);	create_node("--", 0); }
    break;

  case 68:
#line 716 "ast.y"
    {	(yyval.fval) = (yyvsp[(1) - (1)].fval);	}
    break;

  case 69:
#line 718 "ast.y"
    {
					switch(unaryop){
						case 1:	(yyval.fval) = (yyvsp[(2) - (2)].fval);
								create_node("'+'", 0);
								break;
						case 2:	(yyval.fval) = -(yyvsp[(2) - (2)].fval);
								create_node("'+'", 0);
								break;
						case 3:	(yyval.fval) = !(yyvsp[(2) - (2)].fval);
								create_node("!", 0);
								break;
						case 4:	(yyval.fval) = ~((int)(yyvsp[(2) - (2)].fval));
								create_node("~", 0);
								break;	
						case 5:	(yyval.fval) = ++(yyvsp[(2) - (2)].fval);
								create_node("++", 0);							
								break;
						case 6:	(yyval.fval) = --(yyvsp[(2) - (2)].fval);
								create_node("--", 0);
								break;		
					}
					unaryop = -1;
				}
    break;

  case 70:
#line 745 "ast.y"
    {	unaryop = 1;	}
    break;

  case 71:
#line 746 "ast.y"
    {	unaryop = 2;	}
    break;

  case 72:
#line 747 "ast.y"
    {	unaryop = 3;	}
    break;

  case 73:
#line 748 "ast.y"
    {	unaryop = 4;	}
    break;

  case 74:
#line 749 "ast.y"
    {	unaryop = 5;	}
    break;

  case 75:
#line 750 "ast.y"
    {	unaryop = 6;	}
    break;

  case 76:
#line 755 "ast.y"
    {	(yyval.fval) = (yyvsp[(1) - (1)].fval);	}
    break;

  case 77:
#line 757 "ast.y"
    { 
					create_node("==", 0);
					if((yyvsp[(1) - (3)].fval) == (yyvsp[(3) - (3)].fval))
						(yyval.fval) = 1;
					else
						(yyval.fval) = 0;

				}
    break;

  case 78:
#line 766 "ast.y"
    { 
					create_node("!=", 0);
					if((yyvsp[(1) - (3)].fval) != (yyvsp[(3) - (3)].fval))
						(yyval.fval) = 1;
					else
						(yyval.fval) = 0;
				}
    break;

  case 79:
#line 777 "ast.y"
    {	(yyval.fval) = (yyvsp[(1) - (1)].fval);	}
    break;

  case 80:
#line 779 "ast.y"
    { 
					create_node("<", 0);
					if((yyvsp[(1) - (3)].fval) < (yyvsp[(3) - (3)].fval))
						(yyval.fval) = 1;
					else
						(yyval.fval) = 0;

				}
    break;

  case 81:
#line 788 "ast.y"
    { 
					create_node(">", 0);
					if((yyvsp[(1) - (3)].fval) > (yyvsp[(3) - (3)].fval))
						(yyval.fval) = 1;
					else
						(yyval.fval) = 0;

				}
    break;

  case 82:
#line 797 "ast.y"
    { 
					create_node("<=", 0);
					if((yyvsp[(1) - (3)].fval) <= (yyvsp[(3) - (3)].fval))
						(yyval.fval) = 1;
					else
						(yyval.fval) = 0;

				}
    break;

  case 83:
#line 806 "ast.y"
    { 
					create_node(">=", 0);
					if((yyvsp[(1) - (3)].fval) >= (yyvsp[(3) - (3)].fval))
						(yyval.fval) = 1;
					else
						(yyval.fval) = 0;

				}
    break;

  case 84:
#line 818 "ast.y"
    {	(yyval.fval) = (yyvsp[(1) - (1)].fval);	}
    break;

  case 85:
#line 820 "ast.y"
    {	
				create_node("+", 0);
				(yyval.fval) = (yyvsp[(1) - (3)].fval) + (yyvsp[(3) - (3)].fval);	
			}
    break;

  case 86:
#line 825 "ast.y"
    {	
				create_node("-", 0);
				(yyval.fval) = (yyvsp[(1) - (3)].fval) - (yyvsp[(3) - (3)].fval);	
			}
    break;

  case 87:
#line 833 "ast.y"
    {	(yyval.fval) = (yyvsp[(1) - (1)].fval);	}
    break;

  case 88:
#line 835 "ast.y"
    {	
						create_node("*", 0);	
						(yyval.fval) = (yyvsp[(1) - (3)].fval) * (yyvsp[(3) - (3)].fval);	
					}
    break;

  case 89:
#line 840 "ast.y"
    {	
						if((yyvsp[(3) - (3)].fval) == 0){
							cout<<"Line:"<<line<<"\n";
							cout<<"division by zero is undefined\n\n";
							(yyval.fval) = INT_MAX;	
						}else{
							(yyval.fval) = (yyvsp[(1) - (3)].fval) / (yyvsp[(3) - (3)].fval);	
							create_node("/", 0);
						}
					}
    break;

  case 90:
#line 851 "ast.y"
    {	
						if(assigntype == 1){
							cout<<"Line:"<<line<<"\n";
							cout<<"invalid operands to binary expression (\'float\' and \'float\') \n\n";
							}else{								
								(yyval.fval) = (int)(yyvsp[(1) - (3)].fval) % (int)(yyvsp[(3) - (3)].fval);	
								create_node("%", 0);
							}
						}
    break;

  case 91:
#line 867 "ast.y"
    {
					create_node((yyvsp[(2) - (3)].string), 3);
					struct node *ftp;
					ftp = first;
					while(ftp!=NULL){
						if(ftp->scope == scope && ftp->valid == 1){
							ftp->valid = 0;
						}
						else if(strcmp(ftp->token, "param") == 0 && ftp->valid == 1){
							ftp->valid = 0;
						}

						ftp=ftp->link;
					}
					scope--;

				}
    break;

  case 92:
#line 885 "ast.y"
    {	
					create_node((yyvsp[(1) - (2)].string), 3);
					cout<<"Line: "<<line<<"\n";
					cout<<"type specifier missing, defaults to \'int\' \n";

					struct node *ftp;
					ftp = first;
					while(ftp!=NULL){
						if(ftp->scope == scope && ftp->valid == 1){
							ftp->valid = 0;
						}
						else if(strcmp(ftp->token, "param") == 0 && ftp->valid == 1){
							ftp->valid = 0;
						}

						ftp=ftp->link;
					}
					scope--;
				}
    break;

  case 95:
#line 915 "ast.y"
    {	
					
					addfunc((yyvsp[(1) - (1)].ptr), datatype, "function");	
					strcpy((yyval.string), (yyvsp[(1) - (1)].ptr)->name); 								
				}
    break;

  case 96:
#line 920 "ast.y"
    { }
    break;

  case 97:
#line 921 "ast.y"
    { }
    break;

  case 98:
#line 922 "ast.y"
    { }
    break;

  case 99:
#line 927 "ast.y"
    {}
    break;

  case 100:
#line 928 "ast.y"
    {}
    break;

  case 101:
#line 933 "ast.y"
    {	addfunc((yyvsp[(2) - (2)].ptr), datatype, "param");	}
    break;

  case 102:
#line 934 "ast.y"
    {}
    break;

  case 103:
#line 939 "ast.y"
    {		}
    break;

  case 104:
#line 940 "ast.y"
    {		}
    break;


/* Line 1267 of yacc.c.  */
#line 2567 "y.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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


#line 944 "ast.y"



void yyerror(const char *str){
	fflush(stdout);
	cout<<"Line:"<<line<<"\n";
	cout<<"error: ";
	cout<<str<<"\n";
}


int main(){
	tree_top = (tree_stack*)malloc(sizeof(tree_stack));
	tree_top->node = NULL;
	tree_top->next = NULL;
	struct Node *root;
	cout<<"\n";
	yyparse();
	root = pop_tree();
	preorder(root);
	cout<<"\n\nPreorder Traversal\n\n";
	cout<<preBuf<<"\n";
	return 0;
}


void addfunc(struct node *t,int type, char *s){
	if(t->dtype == -1) {
        t->dtype = type;
        t->val.i = 0;
        strcpy(t->token, s);
    }
}


void addInt(struct node *t,int type,int val) {
    if(t->dtype == -1) {
        t->dtype = type;
        t->val.i = val;
        strcpy(t->token, "identifier");
    }
}


void addFloat(struct node *t,int type,float val) {
    if(t->dtype == -1) {
        t->dtype = type;
        t->val.f = (float)val;
        strcpy(t->token, "identifier");
    }
}


void addChar(struct node *t,int type, char val) {
   	if(t->dtype == -1) {
   	    t->dtype = type;
   	    t->val.c = (char)val;
   	    strcpy(t->token, "identifier");
   	}
}


struct node * addtosymbol(struct node * n){
	if(first == NULL){
		first = n;
	}
	else{
		struct  node * ftp = first;
		while(ftp->link !=NULL) {
			ftp = ftp->link;
		}
		ftp->link = n;
	}
	return n;
}


struct node * checksym(char *vname) {
	struct node *ftp;
	struct node *rp;
	struct node *nnode;
	struct node *same;
	if(first == NULL) {
		nnode = (struct node *)malloc(sizeof(struct node));
		addsymbol(nnode,vname);
	    first = nnode;
	}
	else {
	    ftp = first;
	    while(ftp!=NULL) {

	        if(strcmp(vname,ftp->name) == 0){
	            if(ftp->scope > scope && ftp->valid == 1) {	          	
					same = ftp; 
	            	return same;
	            }	
	            else if(ftp->scope == scope && ftp->valid == 1){
	            	same = ftp;
	            	return same;
	            }          	
	            else if(ftp->scope < scope && ftp->valid == 1){
	         		check_un = 1;
	         		same = ftp;
	            	return same;
	         			            		         				         		       	         
	            } 
	          	else if(ftp->scope > scope && ftp->valid == 0){
	          		check_un = 0;
	          	}

	        }            
	        rp = ftp;
	        ftp = ftp->link;
	    }
	    nnode = (struct node *)malloc(sizeof(struct node));
		addsymbol(nnode,vname);

	    rp->link = nnode;
	}
	return nnode;
}


void addsymbol(struct node *tp, char *vname) {
    strcpy(tp->name,vname);
    tp->dtype = -1;
    tp->link = NULL;
    tp->scope = scope;
    tp->valid = 1;
    tp->lineno = line;
}


void cleansymbol(){
	struct node** pp = &first; 
    while (*pp) { 
  
        struct node* entry = *pp; 
 
        if (entry->dtype == -1  ) { 
            *pp = entry->link; 
            free(entry); 
        }
        else if(strcmp(entry->name,"main")== 0 && strcmp(entry->token, "function")==0){	
        	*pp = entry->link; 
            free(entry); 
        }
        else
            pp = &(entry->link); 
    } 
}


void create_node(char *token, int leaf) {
	Node *l;
	Node *r;
	if(leaf==0) {

		r = pop_tree();
		l = pop_tree();
	}
	else if(leaf ==1) {
		l = NULL;
		r = NULL;
	}
	else {
		l = pop_tree();
		r = NULL;
	}

	Node *newnode = (Node*)malloc(sizeof(Node));
	strcpy(newnode->token, token);
	newnode->left = l;
	newnode->right = r;
	push_tree(newnode);
}


void push_tree(Node *newnode){
	tree_stack *temp= (tree_stack*)malloc(sizeof(tree_stack));
	temp->node = newnode;
	temp->next = tree_top;
	tree_top = temp;
}


Node* pop_tree(){
	tree_stack *temp = tree_top;
	tree_top = tree_top->next;
	Node *retnode = temp->node;
	if(temp != NULL)
		free(temp);
	return retnode;
}



void preorder(Node * node){
	if (node == NULL)
		return;

	if(node->left!=NULL && node->right!=NULL)
		strcat(preBuf, "   ( ");
	strcat(preBuf, node->token);
	strcat(preBuf, "   ");

	preorder(node-> left);

	
	if(node->right){
		preorder(node-> right);
	}
	
	if(node->left!=NULL && node->right!=NULL)
		strcat(preBuf, ")   ");	
}
void printtable(){
	struct node *ftp;
    ftp=first;
    //blue
    cout<<"\n\nSymbol Table\n\n";
    //white

	cout<<"   Symbol\t\tName\t  Type\t      Scope\t   Line Number\t       Value \n";
	cout<<"-------------------------------------------------------------------------------------------------\n";
   
    while(ftp!=NULL) {
        char data_type[10];
        if(ftp->dtype==0)
        	strcpy(data_type,"int");
        if(ftp->dtype==1)
        	strcpy(data_type,"float");
        if(ftp->dtype==2)
        	strcpy(data_type,"char");
        if(ftp->dtype==3)
        	strcpy(data_type,"void");

	cout<<ftp->token<<"\t\t"<<ftp->name<<"\t  "<<data_type<<"\t\t"<<ftp->scope<<"\t\t"<<ftp->lineno<<"\t\t";
        if(ftp->dtype == 0){
        	if(ftp->val.i == INT_MIN)
        		cout<<"-\n";
        	else
           		cout<<ftp->val.i<<"\n";
        }
        else if(ftp->dtype == 1){
        	if(ftp->val.f == INT_MIN)
        		cout<<"-\n";
        	else
           		cout<<ftp->val.f<<"\n";
       	}
        else if(ftp->dtype == 2){
            cout<<ftp->val.c<<"\n";
        }
        else if(strcmp(ftp->token, "function")==0){
        	cout<<"-\n";
        }
        else{
	        cout<<"-	Delete it\n";
	    }
        ftp=ftp->link;
    }
    cout<<"\n\n\n";
}


