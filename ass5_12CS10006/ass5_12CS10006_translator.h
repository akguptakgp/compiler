#include<stdio.h>
const int size_of_char=1;
const int size_of_int=4;
const int size_of_double=8;
const int size_of_pointer=4;
const int NSYMS=2000 ;/* max # of symbols */
static int offset_=0;
const int PC=1000;
 
enum Type{
  PChar=-10,
  PInt,
  PDouble, 
  Char,
  Int,
  Double,
  Void,
  Array,
  Pointer,
  Function
};

class Type_Data
{
public:
Type type_name;
int no_;
Type_Data *right;
public:
Type_Data(Type t,int n=0,Type_Data *td=0)
:type_name(t),no_(n),right(td){}
//Type_Data(const Type_Data& ref):
int size();
void print();
};

class symtable;
/* Symbol Table data structure declaration */
typedef struct symt_row {
  char *name;
  Type_Data *type;
  char *initial_value;
  int size,offset;
   symtable *stptr;
 struct symt_row *next;
} SYMT_ROW;

symtable merge_symtab(symtable a,symtable b);

class symtable{
public:
   SYMT_ROW *head;
   SYMT_ROW *last;   
public:
  symtable()
  :head(NULL),last(NULL){};
SYMT_ROW *lookup(char *s,bool to_look=false);  /* Look-up Symbol Table */
SYMT_ROW *gentemp(Type_Data *t,char *init_val=NULL); /* Generate temporary variable */
void update(Type_Data *t,SYMT_ROW * tab);/* A method to update different fields of an existing entry */
void print(char *s); /* A method to print the Symbol Table in a suitable format */
void insert(SYMT_ROW *row);
void shift(SYMT_ROW *row,symtable *a);
friend symtable merge_symtab(symtable a,symtable b);
void update_offset();
};


template <class data_type>
class list_
{
public:
char *name;
data_type data;
list_<data_type> *next;
};


typedef struct boolexp_
{
bool value;
list_<int> *TL,*FL;
}boolexp;

typedef struct type_exp_
{
int width;
Type type;
}type_exp;

typedef struct statemnt_
{
list_<int> *NL;
}statemnt;

typedef struct expression_ 
{
SYMT_ROW* symptr;
boolexp* boolex;
SYMT_ROW* array;
Type_Data *type;
}expression;
 
enum opcodeType{
PLUS=0,  // binary add
MINUS,   // binary minus
MULT,	// binary mult
DIV,	// binary div
MOD,	// binary mod
ASSIGN,	// assignment
LEQ,    // binary less than equal to
GEQ,  
EQ,  // equal to 
NEQ, 
LT, // less than
GT,
UMINUS, // unary minus
UBNEG, //bit negation
UNOT, // unary not
INC, //increment
DEC,
LSHFT, //left shift
RSHFT,
XOR, //xor
UOR, // unary or
UAND, //unary and
AND, // logical and
OR,
GOTO, // goto
IF,  //if
LEQ_, //if a<b goto
GEQ_,
EQ_,
NEQ_,
LT_,
GT_,
PARAM, //paramter
CALL,  // call
RETURN, // return
ARR_DREF,  // x=y[z]
ARR_REF,   //x[z]=y
ADDR,    //x=&y
DREF,    //x=*y
STR     //*x=y
};

class quad {
  private:
  opcodeType op;
  char *result, *arg1, *arg2;
 public:
 quad(opcodeType op1, char *s1=0, char *s2=0,char *s3=0):
  op(op1), result(s1), arg1(s2), arg2(s3) { }
   void print(int a);
friend void backpatch(list_<int> *p,int i);
};

int nextinstr();
class qArray{
private:
quad* qarr_[NSYMS]; 
public:
static int quadPtr;
void emit(opcodeType op, char *result=0, char *arg1=0, char *arg2=0);
void print(); 
friend int nextinstr();
void delete_(int a=-1);
friend void backpatch(list_<int> *p,int i);
};

template<typename data_type>
list_<data_type> *makelist(data_type i,char *name=NULL);
template<typename data_type>
list_<data_type> *merge(list_<data_type> *p1,list_<data_type> *p2);

void backpatch(list_<int> *p,int i);
void convInt2Bool(SYMT_ROW *E);
Type_Data *sym_to_type(symtable* tab);

template <typename data_type>
list_<data_type> *makelist(data_type i,char *name)
{
   list_<data_type>* p=new list_<data_type>;
   p->data=i;
   p->name=name;
   p->next=NULL;
  return p;
}

template<typename data_type>
list_<data_type> *merge(list_<data_type> *p1,list_<data_type> *p2)
{
//printf("\n\n\n\nYES\n\n\n");
  list_<data_type>* q=p1;
  if(!p1) return p2;
  if(!p2) return p1;
  while(q->next) q=q->next;
  q->next=p2;
  return p1;
}

SYMT_ROW* typecheck(SYMT_ROW* E1,SYMT_ROW* E2,bool& e);
expression conv2Bool(expression e);
SYMT_ROW* convInt2Double(SYMT_ROW* e);
SYMT_ROW* convInt2Char(SYMT_ROW* e);
SYMT_ROW* convChar2Int(SYMT_ROW* e);
SYMT_ROW* convChar2Int(SYMT_ROW* e);
SYMT_ROW* convChar2Double(SYMT_ROW* e);
SYMT_ROW* convDouble2Int(SYMT_ROW* e);
SYMT_ROW* convDouble2Char(SYMT_ROW* e);
void convBool2Int(expression& e);
Type_Data *sym_to_type(symtable* tab);
