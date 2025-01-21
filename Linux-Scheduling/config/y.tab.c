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
#line 3 "config.y"

#include <stdlib.h>
#include <stdio.h>

extern char * yytext;
extern int yyleng;

#define	NIL	(dvptr)0

#define	CONFIGC		"conf.c"		/* name of .c output	*/
#define	CONFIGH		"../h/conf.h"		/* name of .h output	*/
#define	CONFHREF	"<conf.h>"		/* how conf.h referenced*/
#define	CONFIGIN	"Configuration"		/* name of input file	*/

#define	IRQBASE		32

FILE	*confc;
FILE	*confh;

char	*dbstr;
int	ndevs = 0;
int	currname = -1;
int	currtname = -1;
int	currdname = -1;
int	brkcount = 0;

struct	syment	{			/* symbol table			*/
	char	*symname;
	int	symoccurs;
	} symtab[250];

int	nsym = 0;
int	lookup();
int	linectr = 1;
char	*doing = "device type declaration";
char	*s;
struct	dvtype {
	char		*dvname;	/* device name (not used in types)*/
	char		*dvtname;	/* type name			*/
	int		dvtnum;		/* symbol table index of type	*/
	char		*dvdevice;	/* device name			*/
	int		dvcsr;		/* Control Status Register addr	*/
	int		dvivec;		/* input interrupt vector	*/
	int		dvovec;		/* Output interrupt vector	*/
	char		dviint[20];	/* input interrupt routine	*/
	char		dvoint[20];	/* output interrupt routine	*/
	char		dvinit[20];	/* init routine name		*/
	char		dvopen[20];	/* open routine name		*/
	char		dvclose[20];	/* close routine name		*/
	char		dvread[20];	/* read routine name		*/
	char		dvwrite[20];	/* write routine name		*/
	char		dvcntl[20];	/* control routine name		*/
	char		dvseek[20];	/* seek routine name		*/
	char		dvgetc[20];	/* getc routine name		*/
	char		dvputc[20];	/* putc routine name		*/
	int		dvminor;	/* device number 0,1,...	*/
	struct dvtype	*dvnext;	/* next node on the list	*/
	};
typedef	struct	dvtype	*dvptr;
	dvptr	ftypes = NIL;		/* linked list of device types	*/
	dvptr	devs = NIL;		/* linked list of device decls.	*/
	dvptr	lastdv = NIL;
	dvptr	currtype = NIL;

char	*ftout[] = 
	       {"struct\tdevsw\t{\t\t\t/* device table entry */\n",
	        "\tint\tdvnum;\n",
		"\tchar\t*dvname;\n",
		"\tint\t(*dvinit)();\n",
		"\tint\t(*dvopen)();\n",
		"\tint\t(*dvclose)();\n",
		"\tint\t(*dvread)();\n",
		"\tint\t(*dvwrite)();\n",
		"\tint\t(*dvseek)();\n",
		"\tint\t(*dvgetc)();\n",
		"\tint\t(*dvputc)();\n",
		"\tint\t(*dvcntl)();\n",
		"\tint\tdvcsr;\n",
		"\tint\tdvivec;\n",
		"\tint\tdvovec;\n",
		"\tint\t(*dviint)();\n",
		"\tint\t(*dvoint)();\n",
		"\tchar\t*dvioblk;\n",
		"\tint\tdvminor;\n",
		"\t};\n\n",
		"extern\tstruct\tdevsw devtab[];",
		"\t\t/* one entry per device */\n\n",
		NULL};

int config_atoi();


#line 164 "y.tab.c"

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
    DEFBRK = 258,                  /* DEFBRK  */
    COLON = 259,                   /* COLON  */
    OCTAL = 260,                   /* OCTAL  */
    INTEGER = 261,                 /* INTEGER  */
    IDENT = 262,                   /* IDENT  */
    CSR = 263,                     /* CSR  */
    IVEC = 264,                    /* IVEC  */
    OVEC = 265,                    /* OVEC  */
    IRQ = 266,                     /* IRQ  */
    IINT = 267,                    /* IINT  */
    OINT = 268,                    /* OINT  */
    INIT = 269,                    /* INIT  */
    OPEN = 270,                    /* OPEN  */
    CLOSE = 271,                   /* CLOSE  */
    READ = 272,                    /* READ  */
    WRITE = 273,                   /* WRITE  */
    SEEK = 274,                    /* SEEK  */
    CNTL = 275,                    /* CNTL  */
    IS = 276,                      /* IS  */
    ON = 277,                      /* ON  */
    GETC = 278,                    /* GETC  */
    PUTC = 279                     /* PUTC  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define DEFBRK 258
#define COLON 259
#define OCTAL 260
#define INTEGER 261
#define IDENT 262
#define CSR 263
#define IVEC 264
#define OVEC 265
#define IRQ 266
#define IINT 267
#define OINT 268
#define INIT 269
#define OPEN 270
#define CLOSE 271
#define READ 272
#define WRITE 273
#define SEEK 274
#define CNTL 275
#define IS 276
#define ON 277
#define GETC 278
#define PUTC 279

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DEFBRK = 3,                     /* DEFBRK  */
  YYSYMBOL_COLON = 4,                      /* COLON  */
  YYSYMBOL_OCTAL = 5,                      /* OCTAL  */
  YYSYMBOL_INTEGER = 6,                    /* INTEGER  */
  YYSYMBOL_IDENT = 7,                      /* IDENT  */
  YYSYMBOL_CSR = 8,                        /* CSR  */
  YYSYMBOL_IVEC = 9,                       /* IVEC  */
  YYSYMBOL_OVEC = 10,                      /* OVEC  */
  YYSYMBOL_IRQ = 11,                       /* IRQ  */
  YYSYMBOL_IINT = 12,                      /* IINT  */
  YYSYMBOL_OINT = 13,                      /* OINT  */
  YYSYMBOL_INIT = 14,                      /* INIT  */
  YYSYMBOL_OPEN = 15,                      /* OPEN  */
  YYSYMBOL_CLOSE = 16,                     /* CLOSE  */
  YYSYMBOL_READ = 17,                      /* READ  */
  YYSYMBOL_WRITE = 18,                     /* WRITE  */
  YYSYMBOL_SEEK = 19,                      /* SEEK  */
  YYSYMBOL_CNTL = 20,                      /* CNTL  */
  YYSYMBOL_IS = 21,                        /* IS  */
  YYSYMBOL_ON = 22,                        /* ON  */
  YYSYMBOL_GETC = 23,                      /* GETC  */
  YYSYMBOL_PUTC = 24,                      /* PUTC  */
  YYSYMBOL_YYACCEPT = 25,                  /* $accept  */
  YYSYMBOL_26_config_input = 26,           /* config.input  */
  YYSYMBOL_devicetypes = 27,               /* devicetypes  */
  YYSYMBOL_ftypes = 28,                    /* ftypes  */
  YYSYMBOL_ftype = 29,                     /* ftype  */
  YYSYMBOL_30_device_list = 30,            /* device.list  */
  YYSYMBOL_devheader = 31,                 /* devheader  */
  YYSYMBOL_tname = 32,                     /* tname  */
  YYSYMBOL_id = 33,                        /* id  */
  YYSYMBOL_34_attribute_list = 34,         /* attribute.list  */
  YYSYMBOL_attribute = 35,                 /* attribute  */
  YYSYMBOL_number = 36,                    /* number  */
  YYSYMBOL_devicedescriptors = 37,         /* devicedescriptors  */
  YYSYMBOL_descriptor = 38,                /* descriptor  */
  YYSYMBOL_fspec = 39,                     /* fspec  */
  YYSYMBOL_dname = 40,                     /* dname  */
  YYSYMBOL_41_optional_on = 41             /* optional.on  */
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   53

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  25
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  36
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  61

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   279


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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    96,    96,    98,   101,   102,   104,   106,   107,   109,
     112,   115,   120,   121,   123,   125,   127,   129,   131,   133,
     135,   137,   139,   141,   143,   145,   147,   149,   151,   154,
     157,   158,   160,   162,   165,   169,   170
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
  "\"end of file\"", "error", "\"invalid token\"", "DEFBRK", "COLON",
  "OCTAL", "INTEGER", "IDENT", "CSR", "IVEC", "OVEC", "IRQ", "IINT",
  "OINT", "INIT", "OPEN", "CLOSE", "READ", "WRITE", "SEEK", "CNTL", "IS",
  "ON", "GETC", "PUTC", "$accept", "config.input", "devicetypes", "ftypes",
  "ftype", "device.list", "devheader", "tname", "id", "attribute.list",
  "attribute", "number", "devicedescriptors", "descriptor", "fspec",
  "dname", "optional.on", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-18)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -18,     2,   -18,     0,   -18,    -3,   -18,   -18,   -18,   -17,
       4,   -18,   -18,   -18,   -12,    -3,   -17,   -18,   -18,    26,
      -3,   -18,   -18,    26,     8,     8,     8,     8,    -3,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,   -18,
      -6,    26,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,
     -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,    -3,   -18,
     -18
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,    30,     0,     1,     2,     3,    11,     5,     0,
       0,    34,    31,    12,     0,     0,     6,    12,    10,    32,
       0,     9,    12,     7,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
      35,     8,    29,    14,    15,    16,    17,    18,    19,    22,
      20,    21,    25,    26,    27,    28,    23,    24,     0,    33,
      36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -18,   -18,   -18,   -18,   -18,   -18,     1,   -18,    -5,   -16,
     -18,   -14,   -18,   -18,   -18,   -18,   -18
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     3,     8,    16,    17,     9,    10,    19,
      39,    43,     5,    12,    13,    14,    59
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      11,    23,     4,     6,     7,    15,    41,     7,    18,    20,
      21,    44,    45,    46,    42,    40,    58,    22,     0,     0,
       0,     0,     0,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,     0,     0,    37,
      38,     0,     0,    60
};

static const yytype_int8 yycheck[] =
{
       5,    17,     0,     3,     7,    22,    22,     7,     4,    21,
      15,    25,    26,    27,     6,    20,    22,    16,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    -1,    23,
      24,    -1,    -1,    58
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    26,    27,    28,     0,    37,     3,     7,    29,    32,
      33,    33,    38,    39,    40,    22,    30,    31,     4,    34,
      21,    33,    31,    34,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    23,    24,    35,
      33,    34,     6,    36,    36,    36,    36,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    22,    41,
      33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    25,    26,    27,    28,    28,    29,    30,    30,    31,
      32,    33,    34,    34,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    35,    35,    35,    35,    36,
      37,    37,    38,    39,    40,    41,    41
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     2,     2,     2,     3,     2,
       2,     1,     0,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       0,     2,     2,     4,     1,     0,     2
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
  case 3: /* devicetypes: ftypes DEFBRK  */
#line 99 "config.y"
                                        {doing = "device definitions";}
#line 1309 "y.tab.c"
    break;

  case 9: /* devheader: ON id  */
#line 110 "config.y"
                                        {mktype(yyvsp[0]);}
#line 1315 "y.tab.c"
    break;

  case 10: /* tname: id COLON  */
#line 113 "config.y"
                                        {yyval = currtname = cktname(yyvsp[-1]);}
#line 1321 "y.tab.c"
    break;

  case 11: /* id: IDENT  */
#line 116 "config.y"
                                        {yyval = currname =
					 lookup(yytext,yyleng);
					}
#line 1329 "y.tab.c"
    break;

  case 14: /* attribute: CSR number  */
#line 124 "config.y"
                                        {newattr(CSR,yyvsp[0]);}
#line 1335 "y.tab.c"
    break;

  case 15: /* attribute: IVEC number  */
#line 126 "config.y"
                                        {newattr(IVEC,yyvsp[0]);}
#line 1341 "y.tab.c"
    break;

  case 16: /* attribute: OVEC number  */
#line 128 "config.y"
                                        {newattr(OVEC,yyvsp[0]);}
#line 1347 "y.tab.c"
    break;

  case 17: /* attribute: IRQ number  */
#line 130 "config.y"
                                        {newattr(IRQ,yyvsp[0] +IRQBASE);}
#line 1353 "y.tab.c"
    break;

  case 18: /* attribute: IINT id  */
#line 132 "config.y"
                                        {newattr(IINT,yyvsp[0]);}
#line 1359 "y.tab.c"
    break;

  case 19: /* attribute: OINT id  */
#line 134 "config.y"
                                        {newattr(OINT,yyvsp[0]);}
#line 1365 "y.tab.c"
    break;

  case 20: /* attribute: OPEN id  */
#line 136 "config.y"
                                        {newattr(OPEN,yyvsp[0]);}
#line 1371 "y.tab.c"
    break;

  case 21: /* attribute: CLOSE id  */
#line 138 "config.y"
                                        {newattr(CLOSE,yyvsp[0]);}
#line 1377 "y.tab.c"
    break;

  case 22: /* attribute: INIT id  */
#line 140 "config.y"
                                        {newattr(INIT,yyvsp[0]);}
#line 1383 "y.tab.c"
    break;

  case 23: /* attribute: GETC id  */
#line 142 "config.y"
                                        {newattr(GETC,yyvsp[0]);}
#line 1389 "y.tab.c"
    break;

  case 24: /* attribute: PUTC id  */
#line 144 "config.y"
                                        {newattr(PUTC,yyvsp[0]);}
#line 1395 "y.tab.c"
    break;

  case 25: /* attribute: READ id  */
#line 146 "config.y"
                                        {newattr(READ,yyvsp[0]);}
#line 1401 "y.tab.c"
    break;

  case 26: /* attribute: WRITE id  */
#line 148 "config.y"
                                        {newattr(WRITE,yyvsp[0]);}
#line 1407 "y.tab.c"
    break;

  case 27: /* attribute: SEEK id  */
#line 150 "config.y"
                                        {newattr(SEEK,yyvsp[0]);}
#line 1413 "y.tab.c"
    break;

  case 28: /* attribute: CNTL id  */
#line 152 "config.y"
                                        {newattr(CNTL,yyvsp[0]);}
#line 1419 "y.tab.c"
    break;

  case 29: /* number: INTEGER  */
#line 155 "config.y"
                                        {yyval = config_atoi(yytext,yyleng);}
#line 1425 "y.tab.c"
    break;

  case 33: /* fspec: dname IS id optional.on  */
#line 163 "config.y"
                                        {mkdev(yyvsp[-3],yyvsp[-1],yyvsp[0]);}
#line 1431 "y.tab.c"
    break;

  case 34: /* dname: id  */
#line 166 "config.y"
                                        {yyval = currdname = ckdname(yyvsp[0]);}
#line 1437 "y.tab.c"
    break;

  case 35: /* optional.on: %empty  */
#line 169 "config.y"
                                        {yyval = 0;}
#line 1443 "y.tab.c"
    break;

  case 36: /* optional.on: ON id  */
#line 171 "config.y"
                                        {yyval = yyvsp[0];}
#line 1449 "y.tab.c"
    break;


#line 1453 "y.tab.c"

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

#line 173 "config.y"

#include "lex.yy.c"
main(argc, argv)
	int	argc;
	char	*argv[];
{
	int	n, i, j, l, fcount;
	dvptr	s;
	int	verbose = 0;
	char	*p;
	char	c;

	if (argc>1 && (strcmp("-v",argv[1])==0)) {
		argc--;
		argv++;
		verbose++;
	}
	if (argc>2) {
		fprintf(stderr,"use: config [-v] [file]\n");
		exit(1);
	}
	if (verbose)
		printf("Opening input file...\n");
	if (argc == 2) {
		if (freopen(argv[1], "r", stdin) == NULL) {
			fprintf(stderr,"Can't open %s\n",argv[1]);
			exit(1);
		}
	} else {	/* try to open Configuration file */
		if (freopen(CONFIGIN, "r", stdin) == NULL) {
			fprintf(stderr,"Can't open %s\n", CONFIGIN);
			exit(1);
		}
	}

	/* Parse the Configuration file */

	if (verbose)
		printf("Parsing configuration specs...\n");
	if ((n=yyparse()) != 0)
		exit(n);

	/* write config.h and config.c */

	if (verbose)
		printf("Opening output files...\n");
	if ( (confc=fopen(CONFIGC,"w") ) == NULL) {
		fprintf(stderr, "Can't write on %s\n", CONFIGC);
		exit(1);
	}

	if ( (confh=fopen(CONFIGH,"w") ) == NULL) {
		fprintf(stderr, "Can't write on %s\n", CONFIGH);
		exit(1);
	}
	fprintf(confh,
		"/* conf.h (GENERATED FILE; DO NOT EDIT) */\n");
	fprintf(confc,
		"/* conf.c (GENERATED FILE; DO NOT EDIT) */\n");
	fprintf(confc, "\n#include %s\n", CONFHREF);
	fprintf(confh, "\n#define\tNULLPTR\t(char *)0\n");


	if (verbose)
		printf("Writing output...\n");
	fprintf(confh,"\n/* Device table declarations */\n");
	for (i=0 ; (p=ftout[i])!=NULL ; i++)
		fprintf(confh, "%s", p);

	/* write device declarations and definitions; count type refs. */

	fprintf(confh, "\n/* Device name definitions */\n\n");
	for (i=0,s=devs; s!=NIL ; s=s->dvnext,i++) {
		fprintf(confh, "#define\t%-12s%d\t\t\t/* type %-8s */\n",
			s->dvname, i, s->dvtname);
		s->dvminor = symtab[s->dvtnum].symoccurs++;
	}

	/* write count of device types */

	fprintf(confh,"\n/* Control block sizes */\n\n");
	for (i=0 ; i<nsym ; i++)
		if (symtab[i].symoccurs > 0) {
			fprintf(confh, "#define\tN%s\t%d\n",
				symtab[i].symname, symtab[i].symoccurs);
		}
	if (ndevs > 0)
		fprintf(confh, "\n#define\tNDEVS\t%d\n\n", ndevs);

	/* empty symbol table, collect, and write names of all I/O routines */

	nsym = 0;
	for (s=devs; s!=NIL ; s=s->dvnext) {
		lookup(s->dvinit,strlen(s->dvinit));
		lookup(s->dvopen,strlen(s->dvopen));
		lookup(s->dvclose,strlen(s->dvclose));
		lookup(s->dvread,strlen(s->dvread));
		lookup(s->dvwrite,strlen(s->dvwrite));
		lookup(s->dvseek,strlen(s->dvseek));
		lookup(s->dvcntl,strlen(s->dvcntl));
		lookup(s->dvgetc,strlen(s->dvgetc));
		lookup(s->dvputc,strlen(s->dvputc));
		lookup(s->dviint,strlen(s->dviint));
		lookup(s->dvoint,strlen(s->dvoint));
		
	}
	fprintf(confh,
		"/* Declarations of I/O routines referenced */\n\n");
	for (i=0 ; i<nsym ; i++)
		fprintf(confh, "extern\tint\t%s();\n", symtab[i].symname);


	/* produce devtab (giant I/O switch table) */

	fprintf(confc, "\n/* device independent I/O switch */\n\n");
	if (ndevs > 0) {
		fprintf(confc, "struct\tdevsw\tdevtab[NDEVS] = {\n");
		fprintf(confc, "\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
			"/*  Format of entries is:",
			"device-number, device-name,",
			"init, open, close,",
			"read, write, seek,",
			"getc, putc, cntl,",
			"device-csr-address, input-vector, output-vector,",
			"iint-handler, oint-handler, control-block, minor-device,",
			"*/");
	}
	for (fcount=0,s=devs ; s!=NIL ; s=s->dvnext,fcount++) {
		fprintf(confc, "\n/*  %s  is %s  */\n\n",s->dvname,s->dvtname);
		fprintf(confc, "{ %d, \"%s\",\n", fcount, s->dvname);
		fprintf(confc, "%s, %s, %s,\n",
			s->dvinit, s->dvopen, s->dvclose);
		fprintf(confc, "%s, %s, %s,\n",
			s->dvread, s->dvwrite, s->dvseek);
		fprintf(confc, "%s, %s, %s,\n",
			s->dvgetc, s->dvputc, s->dvcntl);
		fprintf(confc, "0%06o, 0%03o, 0%03o,\n",
			s->dvcsr, s->dvivec, s->dvovec);
		fprintf(confc, "%s, %s, NULLPTR, %d }",
			s->dviint, s->dvoint, s->dvminor);
		if ( s->dvnext != NIL )
			fprintf(confc, ",\n");
		else
			fprintf(confc, "\n\t};");
	}

	/* Copy definitions to output */

	if (brkcount == 2 && verbose)
		printf("Copying definitions to %s...\n", CONFIGH);
	if (brkcount == 2 )
		while ( (c=input()) > 0)	/* lex input routine */
			putc(c, confh);

	/* guarantee conf.c written later than conf.c for make */

	fclose(confh);
	fprintf(confc, "\n");
	fclose(confc);

	/* finish up and write report for user if requested */

	if (verbose) {
	    printf("\nConfiguration complete. Number of devs=%d:\n\n",ndevs);
	    for (s=devs; s!=NIL ; s=s->dvnext)
	      printf(
	        "Device %s (on %s) csr=0%-7o, ivec=0%-3o, ovec=0%-3o, minor=%d\n",
		s->dvname, s->dvdevice, s->dvcsr, s->dvivec, s->dvovec,
		s->dvminor);
	}
	

}


yyerror(s)
	char *s;
{
	fprintf(stderr,"Syntax error in %s on line %d\n",
		doing,linectr);
}


/*  lookup  --  lookup a name in the symbol table; return position */

lookup(str,len)
	char	*str;
	int	len;
{
	int	i;
	char	*s;

	if (len >= 20) {
		len = 19;
		fprintf(stderr,"warning: name %s truncated\n",str);
		}
	s = (char *)malloc(len+1);
	strncpy(s,str,len);
	s[len] = '\000';
	for (i=0 ; i<nsym ; i++)
		if (strcmp(s,symtab[i].symname) == 0){
			return(i);
		}
	symtab[nsym].symname = s;
	symtab[nsym].symoccurs = 0;
	return(nsym++);
}

int
config_atoi(p, len)
char	*p;
int	len;
{
	int	base, rv;

	if (*p == '0') {
		++p; --len;
		if (*p == 'x' || *p == 'X') {
			++p; --len;		/* skip 'x' */
			base = 16;
		} else
			base = 8;
	} else
		base = 10;
	rv = 0;
	for (; len > 0; ++p, --len) {
		rv *= base;
		if (isdigit(*p))
			rv += *p - '0';
		else if (isupper(*p))
			rv += *p - 'A' + 10;
		else
			rv += *p - 'a' + 10;
	}
	return rv;
}

/* newattr -- add a new attribute spec to current type/device description	*/

newattr(tok,val)
	int	tok;			/* token type (attribute type)	*/
	int	val;			/* symbol number of value	*/
{
	char	*c;
	dvptr	s;

	if (devs == NIL)		/* doing types			*/
		s = currtype;
	else
		s = lastdv;
	if (val>=0 && val<nsym) {
		c = symtab[val].symname;
		if (strlen(c) > 20 ) {
			fprintf(stderr,"Internal overflow\n");
			exit(1);
		}
	} else
		c = NULL;

	switch (tok) {

	case CSR:	s->dvcsr = val;
			break;
	case IVEC:	s->dvivec = val;
			break;
	case OVEC:	s->dvovec = val;
			break;
	case IRQ:	s->dvovec = s->dvivec = val;
			break;
	case IINT:	strcpy(s->dviint,c);
			break;
	case OINT:	strcpy(s->dvoint,c);
			break;
	case READ:	strcpy(s->dvread,c);
			break;
	case WRITE:	strcpy(s->dvwrite,c);
			break;
	case GETC:	strcpy(s->dvgetc,c);
			break;
	case PUTC:	strcpy(s->dvputc,c);
			break;
	case OPEN:	strcpy(s->dvopen,c);
			break;
	case CLOSE:	strcpy(s->dvclose,c);
			break;
	case INIT:	strcpy(s->dvinit,c);
			break;
	case SEEK:	strcpy(s->dvseek,c);
			break;
	case CNTL:	strcpy(s->dvcntl,c);
			break;
	default:	fprintf(stderr, "Internal error 1\n");
	}
}

/* cktname  --  check type name for duplicates */

cktname(symid)
	int symid;
{
	dvptr	s;
extern	dvptr	ftypes;
	char	*name;

	name = symtab[symid].symname;
	for (s=ftypes; s!=NIL ; s=s->dvnext) {
		if (s->dvtname == name) {
			fprintf(stderr,"Duplicate type name %s on line %d\n",
				name,linectr);
			exit(1);
			}
		}
	return(symid);
}

/* mktype  --  make a node in the type list and initialize to defaults	*/

mktype(deviceid)
	int deviceid;
{
	dvptr	s,p;
	char	*tn,*dn;

	p = NIL;
	tn = symtab[currtname].symname;
	dn = symtab[deviceid].symname;
	for (s = ftypes; s!=NIL ; s=s->dvnext) {
		if (s->dvtname == tn && s->dvdevice==dn) {
		   fprintf(stderr,
		     "Duplicate device %s for type %s on line %d\n",
		     dn, tn, linectr);
		   exit(1);
		}
		p = s;
	}
	currtype = s = (dvptr) malloc( sizeof(struct dvtype));
	if (ftypes != NIL) {
		p->dvnext = s;
	}
	else {
		ftypes = s;
	}
	initattr(s, currtname, deviceid);
}

/* initialize attributes in a type declaration node to typename...	*/

initattr(fstr, tnum, deviceid)
	dvptr	fstr;
	int	tnum;
	int	deviceid;
{
	char	*typnam;

	typnam = symtab[tnum].symname;
	fstr->dvname = NULL;
	fstr->dvtname = typnam;
	fstr->dvtnum = tnum;
	fstr->dvdevice = symtab[deviceid].symname;
	fstr->dvcsr = 0;
	fstr->dvivec = 0;
	fstr->dvovec = 0;
	strcpy(fstr->dviint,typnam);
	strcat(fstr->dviint,"iin");
	strcpy(fstr->dvoint,typnam);
	strcat(fstr->dvoint,"oin");
	strcpy(fstr->dvinit,typnam);
	strcat(fstr->dvinit,"init");
	strcpy(fstr->dvopen,typnam);
	strcat(fstr->dvopen,"open");
	strcpy(fstr->dvclose,typnam);
	strcat(fstr->dvclose,"close");
	strcpy(fstr->dvread,typnam);
	strcat(fstr->dvread,"read");
	strcpy(fstr->dvwrite,typnam);
	strcat(fstr->dvwrite,"write");
	strcpy(fstr->dvcntl,typnam);
	strcat(fstr->dvcntl,"control");
	strcpy(fstr->dvseek,typnam);
	strcat(fstr->dvseek,"seek");
	strcpy(fstr->dvgetc,typnam);
	strcat(fstr->dvgetc,"getc");
	strcpy(fstr->dvputc,typnam);
	strcat(fstr->dvputc,"putc");
	fstr->dvminor = 0;
}

mystrdup(tostr,fromstr,len)
	char	*tostr, *fromstr;
	int	len;
{
	for( ; len > 0 ; len--)
		*tostr++ = *fromstr++;
}
/* mkdev  --  make a node on the device list */

mkdev(nameid, typid, deviceid)
	int	nameid, typid, deviceid;
{
	dvptr	s;
	char	*devn,*tn,*dn;
	int	found;

	s = (dvptr) malloc(sizeof(struct dvtype));
	s->dvnext = NIL;
	if (devs == NIL) {
		devs = s;
		lastdv = s;
	} else {
		lastdv->dvnext = s;
		lastdv = s;
	}
	ndevs++;
	tn = symtab[typid].symname;
	devn = symtab[nameid].symname;
	if (deviceid >= 0)
		dn = symtab[deviceid].symname;
	else
		dn = NULL;
	found = 0;
	for (s=ftypes ; s != NULL ; s=s->dvnext)
		if (s->dvtname == tn && (dn==NULL || s->dvdevice==dn)) {
			mystrdup(lastdv,s,sizeof(struct dvtype));
			found=1;
			break;
		}
	if (found==0) {
		fprintf(stderr,
		  "Bad type or device name in declaration of %s on line %d\n",
		  devn, linectr);
		exit(1);
	}
	lastdv->dvnext = NIL;
	lastdv->dvname = devn;
}


/* chdname  -- check for duplicate device name */

ckdname(devid)
	int devid;
{
	dvptr	s;
extern	dvptr	devs;
	char	*name;

	name = symtab[devid].symname;
	for (s=devs; s!=NIL ; s=s->dvnext) {
		if (s->dvname == name) {
			fprintf(stderr,"Duplicate device name %s on line %d\n",
				name,linectr);
			exit(1);
			}
		}
	return(devid);
}

