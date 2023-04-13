#ifndef _PROTO_H
#define	_PROTO_H

#ifdef CPU_DEFINED
/* analyze.c */
BOOL is_equalnode P_ ((const EXPR *, const EXPR *));
CSE    *globalopt P_ ((STMT *));
EXPR   *unsymbolexpr P_ ((EXPR *));
USES desire P_ ((const CSE *));
void addoptinfo P_ ((SYM *, STORAGE));
void deloptinfo P_ ((EXPR *));

#endif /* CPU_DEFINED */

/* cmain.c */
int main P_ ((int, char **));
void options P_ ((const char *, BOOL));
void chip_option P_ ((BOOL, OPTION *, const char *));
void enumeration_option P_ ((BOOL, OPTION *, const char *));
void numeric_option P_ ((BOOL, OPTION *, const char *));
void set_option P_ ((BOOL, OPTION *, const char *));
void string_option P_ ((BOOL, OPTION *, const char *));

/* decl.c */
BOOL is_type_name P_ ((TOKEN));
SIZE declaration_list P_ ((STORAGE, SIZE));
SYM    *identifier P_ ((void));
TYP    *type_name P_ ((void));
void translation_unit P_ ((void));

/* expr.c */
BOOL is_constant_in_range P_ ((EXPR *, TYP *));
BOOL is_lvalue P_ ((const EXPR *));
EXPR   *expression P_ ((void));
EXPR   *condition_expression P_ ((void));
EXPR   *copynode P_ ((const EXPR *));
EXPR   *exprnc P_ ((void));
EXPR   *implicit_castop P_ ((EXPR *, TYP *));
EXPR   *integral_expression P_ ((void));
EXPR   *mk_autocon P_ ((SIZE));
EXPR   *mk_icon P_ ((IVAL, TYP *));
EXPR   *mk_lcon P_ ((LABEL));
EXPR   *mk_node P_ ((EXPRTYPE, EXPR *, EXPR *, TYP *));
EXPR   *mk_ref P_ ((EXPR *, TYP *));
EXPR   *mk_symnode P_ ((SYM *));
EXPR   *transform_assign P_ ((EXPR *, const CHAR *, const CHAR *, const CHAR *));
EXPR   *transform_binary P_ ((EXPR *, const CHAR *));
EXPR   *walkexpr P_ ((EXPR *, EXPR *(*)(EXPR *)));
void check_discard P_ ((const EXPR *));

#ifdef FLOAT_SUPPORT
EXPR   *transform_assign2 P_ ((EXPR *, const CHAR *));
EXPR   *transform_binary_ref P_ ((EXPR *, const CHAR *));
EXPR   *transform_unary P_ ((EXPR *, const CHAR *));
EXPR   *transform_unary_ref P_ ((EXPR *, const CHAR *));

#endif /* FLOAT_SUPPORT */

#ifdef ASM
EXPR   *asm_expression P_ ((void));

#endif /* ASM */
#ifdef TMS320C30
#ifdef FLOAT_SUPPORT
EXPR   *mk_fcon P_ ((RVAL *, TYP *));

#endif /* FLOAT_SUPPORT */

#endif /* TMS320C30 */
#ifdef SEQUENCE
void sequence_point P_ ((void));

#else
#define	sequence_point()
#endif
#ifdef TRACE
EXPR   *traceexpr P_ ((void));

#endif /* TRACE */

#ifdef EXTERNAL
/* extern */
void funclist P_ ((SYM *));

#endif /* EXTERNAL */

#ifdef CPU_DEFINED
/* gen*.c */
#ifndef MULTIPLE_PROCESSORS
BOOL g_is_ascending_stack P_ ((void));
BOOL g_is_bigendian P_ ((void));
void g_allocate P_ ((CSE *));
void g_auto_align P_ ((void));
void g_branch P_ ((LABEL));
void g_entry P_ ((SIZE));
void g_epilogue P_ ((void));
void g_expression P_ ((const EXPR *));
void g_flush P_ ((SYM *));
void g_jfalse P_ ((const EXPR *, LABEL));
void g_jtrue P_ ((const EXPR *, LABEL));
void g_label P_ ((LABEL));

#ifdef DEBUGOPT
void g_line P_ ((LINE, const CHAR *));

#endif /*DEBUGOPT */
void g_preload P_ ((CSE *));
void g_return P_ ((const EXPR *, TYP *));
void g_stack P_ ((SIZE));
void g_switch_compare P_ ((const EXPR *, STMT *));
void g_switch_table P_ ((const EXPR *, SWITCH *, UVAL, UVAL));
EXPR   *g_order P_ ((EXPR *));
EXPR   *g_transform P_ ((EXPR *));
void g_initialize P_ ((void));
void g_terminate P_ ((void));

#endif /* MULTIPLE_PROCESSORS */

/* genffp.c */
#ifdef MC680X0
#ifdef FLOAT_MFFP
unsigned long genffp P_ ((const RVAL *));

#endif /* FLOAT_MFFP */
#endif /* MC680X0 */

#ifdef ICODE
/* genicode.c */
void genicse P_ ((CSE *));
void genicode P_ ((STMT *, int));

#endif /* ICODE */

/* genieee.c */
#ifdef FLOAT_IEEE
void ieee_single P_ ((const RVAL *, unsigned long *));
void ieee_double P_ ((const RVAL *, unsigned long *, BOOL));
void ieee_longdouble P_ ((const RVAL *, unsigned long *, BOOL));

#endif /* FLOAT_IEEE */

/* genstmt.c */
void genfunc P_ ((SYM *, STMT *, CSE *, LINE, const CHAR *));

/* genutil.c */
#ifdef FLOAT_SUPPORT
#ifndef FLOAT_BOOTSTRAP
LABEL mk_flabel P_ ((const RVAL *, const TYP *));

#endif /* FLOAT_BOOTSTRAP */
#endif /* FLOAT_SUPPORT */
EXPR   *mk_add P_ ((EXPR *, EXPR *));
EXPR   *mk_const P_ ((IVAL));
EXPR   *mk_global P_ ((const CHAR *, const EXPR *));
void sync_stack P_ ((void));

#endif /* CPU_DEFINED */
UVAL bitmask P_ ((BITSIZE));
BOOL tst_const P_ ((const EXPR *));
void swap_nodes P_ ((EXPR *));

#ifdef DEBUGOPT
const CHAR *mk_string P_ ((const CHAR *));

#endif /* DEBUGOPT */


/* getsym.c */
BOOL is_label P_ ((TOKEN));
void getsym P_ ((void));
void initsym P_ ((void));
void needpunc P_ ((TOKEN));

#ifdef EXTENSION
BOOL is_visibility_specifier P_ ((void));
BOOL is_class_scope P_ ((void));

#endif /* EXTENSION */

/* init.c */
SIZE align P_ ((const TYP *, SIZE));
SIZE doinit P_ ((SYM *, SIZE));

#ifdef CPU_DEFINED
SIZE calculate_offset P_ ((SYM *, SIZE, STORAGE, BOOL));

#endif /* CPU_DEFINED */

/* intexpr.c */
#ifdef FLOAT_SUPPORT
void floatexpr P_ ((TYP *, RVAL *));

#endif /* FLOAT_SUPPORT */
IVAL arithexpr P_ ((TYP *));
IVAL intexpr P_ ((void));

#ifdef LIST
/* list.c */
void summary P_ ((BLOCK *, LEVEL));

#endif

/* memmgt.c */
VOIDSTAR xalloc P_ ((size_t));
VOIDSTAR galloc P_ ((size_t));
void rel_local P_ ((void));
void rel_global P_ ((void));

/* msgout.c */
void eprintf P_ ((const char *,...));

#ifdef ICODE
void iprintf P_ ((const char *,...));

#endif
#ifdef LIST
void lprintf P_ ((const char *,...));

#endif /* LIST */
void message P_ ((int,...));
void fatal P_ ((const char *, const char *, const char *,...));

#ifdef CPU_DEFINED
#ifdef DEBUG
void dprintf P_ ((int, const char *,...));

#endif /* DEBUG */
void oprintf P_ ((const char *,...));

#endif /* CPU_DEFINED */

/* optimize.c */
EXPR   *opt0 P_ ((EXPR *));
EXPR   *constantopt P_ ((EXPR *));
int pwrof2 P_ ((IVAL));

#ifdef CPU_DEFINED
/* outgen.c */
const CHAR *outlate P_ ((const CHAR *));

#endif /* CPU_DEFINED */

/* stmt.c */
void funcbody P_ ((SYM *, BLOCK *));

/* symbol.c */
BLOCK  *endparamblock P_ ((void));
BLOCK  *endstructblock P_ ((void));
BLOCK  *mk_block P_ ((void));
LABEL lab_define P_ ((const CHAR *));
LABEL lab_search P_ ((const CHAR *));
SYM    *internal_symbol P_ ((const CHAR *, TYP *));
SYM    *mk_sym P_ ((const CHAR *, STORAGE, TYP *));
SYM    *search P_ ((const CHAR *, const TABLE *));
SYM    *sym_search P_ ((const CHAR *));
SYM    *tag_search P_ ((const CHAR *));
int is_local_scope P_ ((const SYM *));
void beginblock P_ ((void));
void beginfuncblock P_ ((BLOCK *));
void beginparamblock P_ ((void));
void beginstructblock P_ ((BLOCK *));
void check_labels P_ ((void));
void endblock P_ ((void));
void endfuncblock P_ ((void));
void field_append P_ ((SYM **));
void sym_append P_ ((SYM **));
void tag_append P_ ((SYM **));

/* system.c */
const char *message_text P_ ((MSGNUM));
void openerror P_ ((void));
void openfiles P_ ((int, char **));

#ifdef EPOC
VOID CommandLineParameters P_ ((int *, char ***));
size_t fread P_ ((char *, size_t, size_t, FHANDLE));
int vfprintf P_ ((FHANDLE, char *, va_list));
int atoi P_ ((const char *));

#endif /* EPOC */

/* types.c */
BOOL is_arithmetic_type P_ ((const TYP *));
BOOL is_array_type P_ ((const TYP *));
BOOL is_compatible_type P_ ((const TYP *, const TYP *));
BOOL is_constant_in_type_range P_ ((IVAL, const TYP *, const TYP *));

#ifdef FLOAT_SUPPORT
BOOL is_floating_type P_ ((const TYP *));

#endif /* FLOAT_SUPPORT */
BOOL is_function_type P_ ((const TYP *));
BOOL is_incomplete_type P_ ((TYP *));
BOOL is_integral_type P_ ((const TYP *));
BOOL is_object_type P_ ((const TYP *));
BOOL is_pointer_type P_ ((const TYP *));
BOOL is_equal_type P_ ((const TYP *, const TYP *));
BOOL is_scalar_type P_ ((const TYP *));
BOOL is_signed_type P_ ((const TYP *));
BOOL is_structure_type P_ ((const TYP *));
BOOL is_subtype P_ ((const TYP *, const TYP *));
BOOL is_unsigned_type P_ ((const TYP *));
SIZE alignment_of_type P_ ((const TYP *));
TYP    *composite_type P_ ((TYP *, TYP *));
TYP    *copy_type P_ ((const TYP *));
TYP    *mk_type P_ ((const TYP *, TYP *));
TYP    *promote_type P_ ((TYP *));
TYP    *qualify_type P_ ((TYP *, QUALIFIER));
TYP    *unary_conversion P_ ((TYP *));
void check_complete P_ ((TYP *));
void check_qualifiers P_ ((TYP *, TYP *));
void initialize_types P_ ((void));
void size_type P_ ((TYP *));

#ifdef EPOC
/*
 *   The following defines map ANSI routines onto their PLIB equivalents.
 *   This allows the compiler to be built without linking in the C library.
 */
#define	strlen(s)		p_slen((s))
#define	exit(r)			p_exit(r)
#define	free(s)			p_free(s)
#define	malloc(s)		p_alloc(s)
#define	realloc(p,s)		p_realloc((p),(s))
#define isdigit(c)		p_isdigit(c)
#define	memmove(s,d,l)		p_bcpy((s),(d),(l))
#define	memcmp(s,d,l)		p_bcmp((s),(l),(d),(l))
#endif /* EPOC */

#endif /* _PROTO_H */
