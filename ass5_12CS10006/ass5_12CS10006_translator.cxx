/*************************       Compilers Laboratory Assignment 5             ****************************/
/************************      Written by:Ankit Kumar Gupta (12CS10006)        ***************************/
/************************          Intermediate Code Generation                **************************/ 

// header files inclusions
#include <iostream>
#include <fstream>
#include <iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include"ass5_12CS10006_translator.h"
extern bool flag;
list_<symtable*> *stbl;

extern FILE* yyin;
extern FILE* yyout;
extern int yyparse();
extern symtable ST_gl;
extern symtable* ST_funt;
extern qArray qarr;

using namespace std;
ofstream out;

/* Look-up function for Symbol Table
        if to_look ==1 we will not lookup in the ST_gl and only lookup in ST_funt
        we need to keep the restrict variable to consider for local variables
        It returns a pointer to a symbol table row        
*/
SYMT_ROW* symtable::lookup(char s[],bool to_look) // if to_look==true look in function symbol 
 {

    SYMT_ROW *sp=head;	
   while(sp!=NULL){  	                                     		   
	if (sp->name && !strcmp(sp->name,s))		{/* is it already here? */ 
      	flag=true;return sp; }
     sp=sp->next;
    }

     if(!to_look && this!=&ST_gl){ // then check in the global symbol table
            sp=ST_gl.head;
            while(sp!=NULL)
	  {                  
                 if (sp->name && !strcmp(sp->name,s)){/* is it already here? */
                       flag=true;return sp;
                         }
                    sp=sp->next;
             }
  	   }    

        flag=false; 
        sp=new SYMT_ROW;			 
    	sp->name = strdup(s);
	sp->type=NULL;
	sp->stptr=NULL;
	sp->initial_value=NULL;
	sp->next=NULL;
        sp->size=sp->offset=0;
        if(last!=NULL)
      		last->next=sp;
	else
  	  head=sp;	
     last=sp; 
    return sp;						
} 


int Type_Data::size()
{
  if(type_name==Array) return no_*right->size();
  else
  switch(type_name)
 { 
     case Void: return size_of_pointer;
	break;	
     case Char: return size_of_char;
	break;
     case Int: return size_of_int;
	break;
     case Double: return size_of_double;
	break;
    case Pointer: return size_of_pointer;
	break;
    case Function: return 0;
	break;		
  }
}

/* Generate temporary variable */
/*
   function to Generate temporary variable given a Type_Data and init_val
    returns pointer to SYMT_ROW for the newly generated temporary variable
*/
SYMT_ROW* symtable::gentemp(Type_Data *t,char *init_val)
 {
  static int c = 0; /* Temp counter */
  char str[10]; /* Temp name */
  /* Generate temp name */
  sprintf(str, "t%03d", c++);
  /* Add temporary to symtab */
 
  SYMT_ROW* tmp =lookup(str);
  tmp->type=t;
  //printf("init_val=%d\n",*((int*)(tmp->initial_value)));  
  tmp->initial_value=init_val;
  if(t){
 	  tmp->size=t->size();

	  tmp->offset=offset_;		// edit
  	  offset_+=tmp->size;
	}
 else {
       tmp->size=0;
       tmp->offset=offset_;
}

return tmp;
}

void symtable::update(Type_Data *t,SYMT_ROW * tab)
{
 
 if(tab->type==NULL)
  {
    tab->type=t;
    if(t->type_name!=Array && t->type_name!=Pointer)
    { 
	tab->size=t->size();
        tab->offset=offset_;	
        offset_+=tab->size;			
    }
   return;
  }

  if(tab->type->type_name==Pointer)
   { 
	 
    if(t->type_name==Function) 
	{
          t->no_=Pointer;
          tab->type=t;
          tab->size=0;
	  tab->offset=offset_;
        }
     else
     {	
	Type_Data *tmp=tab->type;
           while(tmp->right) tmp=tmp->right; 
           tmp->right=t;
         tab->size=tab->type->size();
	 tab->offset=tab->size+offset_;	
	offset_+=tab->size; 
     }
    return;
   }

  if(tab->type->type_name==Function)
  {
    if(tab->type->type_name==Pointer)
        {
	tab->type->no_=t->type_name-3;}
     else
     tab->type->no_=t->type_name;
  return;
  }
  
  if(tab->type->type_name==Array)	
  {
  		Type_Data* p=tab->type;
  		while(p->right) p=p->right;
		  p->right=t;
		if(t->type_name!=Array)  { tab->size=tab->type->size(); tab->offset=tab->size+offset_; offset_+=tab->size;}
  }
}

int count=0;
void Type_Data::print()
{

 switch(type_name)
    {
     case Void:  out<<left<<"void"; count+=4;  // printf("%-s","void");
	break; 
     case Char:  out<<left<<"char"; count+=4; //printf("%-s","char"); 
	break;
     case Int:   out<<left<<"int"; count+=3; //printf("%-s","int");
	break;
     case Double: out<<left<<"double";  count+=6; //printf("%-s","double");
	break;
     case Array:  count+=9;    out<<left<<"array("<<no_<<",";    //printf("array(%d,",no_);
                  right->print();  out<<")";  //printf(")");
        break; 
    case Pointer: /*printf("ptr(");*/  out<<"ptr("; count+=5; right->print();  /*printf(")");*/  out<<")";
	 break;
    case Function:   out<<"function";     count+=8;    //printf("%s","function");
	 break;
   }
 
  return;
}


void symtable::print(char *name)
{
 //printf("\n                            SYMBOL TABLE %s                            \n",name);
 out<<"\n                            SYMBOL TABLE "<<name<<"                            \n";
 //printf("\n\t%-10s%-40s%-15s%-8s%-8s%-13s\n","Name","Type","Initial_Value","Size","Offset","Nested ptr");	
 out<<"\n\t"<<left<<setw(10)<<"Name"<<left<<setw(40)<<"Type"<<left<<setw(15)<<"Initial_Value";
  out<<left<<setw(8)<<"Size"<<left<<setw(8)<<"Offset"<<left<<setw(13)<<"Nested ptr\n";
 SYMT_ROW *sp=head;
   while(sp!=NULL)
   {  	                                     		                   
      //printf("\t%-10s ",sp->name);  // print name
          out<<"\t"<<left<<setw(10)<<sp->name;
      if(sp->type)                // it type not null print it
	 {
		count=0;
    		sp->type->print(); //print type
    	         while(count++<40) {out<<" ";}
    		if(sp->type->type_name==Function)
		{
			 //printf("%-15s%-8s%-8dptr-to-ST(%s) \n ","null","0",sp->offset,sp->name); 
                        out<<setw(15)<<left<<"null"<<setw(8)<<left<<"0"<<setw(8)<<left<<sp->offset<<"ptr-to-ST("<<sp->name<<")"<<endl;
   			 if(sp->stptr && sp->stptr->last)
				{     
					list_<symtable*> *list=makelist<symtable*>(sp->stptr,sp->name);	
				        stbl=merge<symtable*>(stbl,list);  
				} 
	  	} 
   	      else if(sp->initial_value){
     		           //printf("%-15s",sp->initial_value);
			  out<<left<<setw(15)<<sp->initial_value;
			   //printf("%-8d%-8d%-13s\n",sp->size,sp->offset,"null");
			  out<<left<<setw(8)<<sp->size<<left<<setw(8)<<sp->offset<<left<<setw(13)<<"null"<<endl;
			}
   		else  
		//printf("%-15s%-8d%-8d%-13s\n","null",sp->size,sp->offset,"null"); 
		out<<left<<setw(15)<<"null"<<left<<setw(8)<<sp->size<<left<<setw(8)<<sp->offset<<left<<setw(13)<<"null"<<endl;
		}
	else        // type is not known 
	//printf("%-40s%-15s%-8s%-8d%-13s\n","null","null","null",sp->offset,"null"); 
	out<<left<<setw(40)<<"null"<<left<<setw(15)<<"null"<<left<<setw(8)<<sp->size<<left<<setw(8)<<sp->offset<<left<<setw(13)<<"null"<<endl;
   	sp=sp->next;
 }
}

void symtable::insert(SYMT_ROW *row)
{
 if(head==NULL)
  {
   head=last=row; return ;
   }
  last->next=row;
  last=row;
 return;
}

void symtable::shift(SYMT_ROW *row,symtable *a)
{
   if(head==row) //head need to be modified 
   {
    if(head==last) //only 1 entry last needed to modified
    {
     	head=last=NULL;
    	row->next=NULL;
    	a->insert(row); 
    	return;
     }
    head=head->next;
    row->next=NULL;
    a->insert(row);
    return;
   }
 
   if(last==row) // last need to modified 
   {
    SYMT_ROW *p=head;
    while(p->next!=row) // p can not be NULL because atleast one entry is there
      	p=p->next;

    	p->next=p->next->next;
        row->next=NULL;
        a->insert(row);
        last=p;
    return;
     
    }
        SYMT_ROW *sp=new SYMT_ROW;	
        sp->name =row->name;
	sp->type=row->type;
	sp->stptr=row->stptr;
	sp->initial_value=row->initial_value;
        sp->size=row->size;
        sp->offset=row->offset;
        sp->next=NULL;
        a->insert(sp);
        row->name =row->next->name;
	row->type=row->next->type;
	row->stptr=row->next->stptr;
	row->initial_value=row->next->initial_value;
        row->size=row->next->size;
        row->offset=row->next->offset;
        SYMT_ROW *tmp=row->next; 
        row->next=row->next->next;
        free(tmp);
   return ;
}

int off=0;
void symtable::update_offset()
{

SYMT_ROW *sp=head;
while(sp)
{
sp->offset=off;
off+=sp->size;
sp=sp->next;
}
return;
}

symtable merge_symtab(symtable a,symtable b)
{
  if(a.head==NULL) return b;
  if(b.head==NULL) return a;
  //SYMT_ROW* sp=a.head;
 /// while(sp->)
  a.last->next=b.head;
  a.last=b.last;
 return a;
}

void quad::print(int a) 
{

	//printf("%d : ",PC+a);
        out<<PC+a<<" : ";
	if(arg2!=0) //Binary Operator
	{ 
		switch(op)
		{
			case PLUS : out<<result<<"="<<arg1<<"+"<<arg2<<endl;          // printf("%s=%s%s%s\n",result,arg1,"+",arg2);
			break;
			case MINUS: out<<result<<"="<<arg1<<"-"<<arg2<<endl; //printf("%s=%s%s%s\n",result,arg1,"-",arg2);
			break;
			case MULT: out<<result<<"="<<arg1<<"*"<<arg2<<endl; //printf("%s=%s%s%s\n",result,arg1,"*",arg2);
			break;
			case DIV: out<<result<<"="<<arg1<<"/"<<arg2<<endl; //printf("%s=%s%s%s\n",result,arg1,"/",arg2);
			break;
			case MOD: out<<result<<"="<<arg1<<"%"<<arg2<<endl; //printf("%s=%s%s%s\n",result,arg1,"%",arg2);
			break;
			case LEQ: out<<result<<"="<<arg1<<"<="<<arg2<<endl;     //printf("%s=%s%s%s\n",result,arg1,"<=",arg2);
			break;
			case GEQ: out<<result<<"="<<arg1<<">="<<arg2<<endl; //printf("%s=%s%s%s\n",result,arg1,">=",arg2);
			break;
			case EQ: out<<result<<"="<<arg1<<"=="<<arg2<<endl; //printf("%s=%s%s%s\n",result,arg1,"==",arg2);
			break;
			case NEQ: out<<result<<"!="<<arg1<<"%"<<arg2<<endl;  //printf("%s=%s%s%s\n",result,arg1,"!=",arg2);
			break;
			case LT: out<<result<<"="<<arg1<<"<"<<arg2<<endl; //printf("%s=%s%s%s\n",result,arg1,"<",arg2);
			break;
			case GT: out<<result<<"="<<arg1<<">"<<arg2<<endl; //printf("%s=%s%s%s\n",result,arg1,">",arg2);
			break;
			case  UAND: out<<result<<"="<<arg1<<"&"<<arg2<<endl; //printf("%s=%s%s%s\n",result,arg1,"&",arg2);
			break;
			case XOR: out<<result<<"="<<arg1<<"^"<<arg2<<endl; //printf("%s=%s%s%s\n",result,arg1,"^",arg2);
			break;
			case  UOR: out<<result<<"="<<arg1<<"|"<<arg2<<endl; //printf("%s=%s%s%s\n",result,arg1,"|",arg2);
			break;  
			case AND: out<<result<<"="<<arg1<<"&&"<<arg2<<endl;  //printf("%s=%s%s%s\n",result,arg1,"&&",arg2);
			break;
			case OR: out<<result<<"="<<arg1<<"||"<<arg2<<endl;  //printf("%s=%s%s%s\n",result,arg1,"||",arg2);
			break;
			case LEQ_: out<<"if "<<arg1<<"<="<<arg2<<" goto "<<result<<endl; //printf("if %s%s%s goto %s\n",arg1,"<=",arg2,result);
			break;
			case GEQ_: out<<"if "<<arg1<<">="<<arg2<<" goto "<<result<<endl; //printf("if %s%s%s goto %s\n",arg1,">=",arg2,result);
			break;
			case EQ_: out<<"if "<<arg1<<"=="<<arg2<<" goto "<<result<<endl; //printf("if %s%s%s goto %s\n",arg1,"==",arg2,result);
			break;
			case NEQ_: out<<"if "<<arg1<<"!="<<arg2<<" goto "<<result<<endl; //printf("if %s%s%s goto %s\n",arg1,"!=",arg2,result);
			break;
			case LT_ : out<<"if "<<arg1<<"<"<<arg2<<" goto "<<result<<endl; //printf("if %s%s%s goto %s\n",arg1,"<",arg2,result);
			break;
			case GT_: out<<"if "<<arg1<<">"<<arg2<<" goto "<<result<<endl; //printf("if %s%s%s goto %s\n",arg1,">",arg2,result);
			break;
			case CALL : out<<result<<"=call "<<arg1<<","<<arg2<<endl; //printf("%s=call %s,%s\n",result,arg1,arg2);
			break;
			case ARR_DREF:  out<<result<<"="<<arg1<<"["<<arg2<<"]"<<endl;    //  printf("%s=%s[%s]\n",result,arg1,arg2);
			break;
			case ARR_REF: out<<result<<"["<<arg1<<"]="<<arg2<<endl; //printf("%s[%s]=%s\n",result,arg1,arg2);
			break;
			case  LSHFT: out<<result<<"="<<arg1<<"<<"<<arg2<<endl; //printf("%s=%s%s%s\n",result,arg1,"<<",arg2);
			break;
			case  RSHFT: out<<result<<"="<<arg1<<">>"<<arg2<<endl; //printf("%s=%s%s%s\n",result,arg1,">>",arg2);
			break;
		}
	}
	else if(arg1!=0) //Unary Operator
	{
		switch(op)
		{
			//printf("ASSign called with %s %s\n",result,arg1);
			case ASSIGN : out<<result<<"="<<arg1<<endl;;       //  printf("%s=%s\n",result,arg1);
			break;
			case  UMINUS: out<<result<<"= -"<<arg1<<endl;       //printf("%s=%s%s\n",result,"-",arg1);
			break;
			case  UBNEG: out<<result<<"= ~"<<arg1<<endl;       //printf("%s=%s%s\n",result,"~",arg1);
			break;
			case  UNOT: out<<result<<"= !"<<arg1<<endl;       //printf("%s=%s%s\n",result,"!",arg1);
			break;
			case  INC: out<<result<<"= ++"<<arg1<<endl;       //printf("%s=%s%s\n",result,"++",arg1);
			break;
			case  DEC: out<<result<<"= --"<<arg1<<endl;       //printf("%s=%s%s\n",result,"--",arg1);
			break;
			case  IF: out<<"if "<<arg1<<" goto "<<result<<endl;       //printf("if %s goto %s\n",arg1,result);
			break;
			case  ADDR: out<<result<<"= &"<<arg1<<endl;       //printf("%s=%s%s\n",result,"&",arg1);
			break;
			case  DREF: out<<result<<"= *"<<arg1<<endl;       //printf("%s=%s%s\n",result,"*",arg1);
			break;
			case  STR: out<<"*"<<result<<"="<<arg1<<endl;       //printf("*%s=%s\n",result,arg1);
			break;
		}
	}
	else 
         if(result!=NULL)  // Not an Operator
	{ 
               
		switch(op)
		{
			case  GOTO: out<<"goto "<<result<<endl;      //   printf("goto %s\n",result);
			break;
			case  PARAM: out<<"param "<<result<<endl;            //printf("param %s\n",result);
			break;
			case  RETURN: out<<"return "<<result<<endl;        // printf("return %s\n",result);
			break;
		}
	}
        else
	{ 
		switch(op)
		{
			case  RETURN: out<<"return"<<endl;            //printf("return\n");
			break;
			case  GOTO:   out<<"goto null"<<endl;                                 //printf("goto %s\n","null");
			break;
		}
	}	
}

int qArray::quadPtr=0;
void qArray::emit(opcodeType op, char *result, char *arg1, char *arg2)
{
  qarr_[quadPtr++]=new quad(op,result,arg1,arg2); 
}

void qArray::print()
{
//printf("no of elemnts %d\n\n\nhhhhhhhhnn\n",quadPtr);
for(int i=0;i<quadPtr;i++)
{ if(!qarr_[i]) out<<"error"; else qarr_[i]->print(i); }
}

void qArray::delete_(int a){ free(qarr_[quadPtr-1]);quadPtr--;}
int nextinstr()
{

 return qArray::quadPtr;
}

void backpatch(list_<int> *p,int i)
{
      list_<int> *q=p;	
      while(q)
	{ 
              if(q->data>=0 && q->data<qArray::quadPtr ) {
                
		qarr.qarr_[q->data]->result=new char[30];
		sprintf(qarr.qarr_[q->data]->result,"%d",i);
		}
  		  q=q->next;
  	}
}

int main(int argc,char *argv[])
{
//ST_gl;
 
/**************************        Testing first input file            ************************************/
  stbl=makelist<symtable*>(&ST_gl,"Global");
  yyin=fopen("ass5_12CS10006_test1.c","r");
  yyout=fopen("ass5_12CS10006_result1.c","w");       // tokens are generated in this file
  int rtn;
  rtn=yyparse();
  if(rtn==0) out<<"Parsed Successfully..\n";
  fclose(yyin);
  fclose(yyout);

/************************      printing output of first input file   ********************************/
  out.open("ass5_12CS10006_quads1.out");
  out<<endl<<endl;
  out<<"\t\tIntermediate code file generated by compiler\t"<<endl;
  out<<"\t\t\t\t\tSymbol Tables \n";
   while(stbl){
  stbl->data->update_offset();	
  stbl->data->print(stbl->name);
  stbl=stbl->next;
   }
   out<<endl<<endl<<"\t\t\t\t\tQuad Array"<<endl<<endl;
  qarr.print();
  out<<endl<<endl;
  out.close();

/**************************  Testing second input file            ************************************/
  ST_gl.head=NULL; ST_gl.last=NULL; 
   qArray::quadPtr=0;
   off=0;
   stbl=makelist<symtable*>(&ST_gl,"Global");
  yyin=fopen("ass5_12CS10006_test2.c","r");
  yyout=fopen("ass5_12CS10006_result2.c","w");       // tokens are generated in this file
   rtn;
  rtn=yyparse();
  if(rtn==0) out<<"Parsed Successfully..\n";
  fclose(yyin);
  fclose(yyout);

 /************************      printing output of second input file   ********************************/
  out.open("ass5_12CS10006_quads2.out");
  out<<endl<<endl;
  out<<"\t\tIntermediate code file generated by compiler\t"<<endl;
  out<<"\t\t\t\t\tSymbol Tables \n";
   while(stbl){
  stbl->data->update_offset();	
  stbl->data->print(stbl->name);
  stbl=stbl->next;
   }
   out<<endl<<endl<<"\t\t\t\t\tQuad Array"<<endl<<endl;
  qarr.print();
  out<<endl<<endl;
 out.close();

/**************************  Testing third input file            ************************************/
 ST_gl.head=NULL; ST_gl.last=NULL; 
   qArray::quadPtr=0;
   off=0;
  stbl=makelist<symtable*>(&ST_gl,"Global");
   yyin=fopen("ass5_12CS10006_test3.c","r");
  yyout=fopen("ass5_12CS10006_result3.c","w");       // tokens are generated in this file
   rtn;
  rtn=yyparse();
  if(rtn==0) out<<"Parsed Successfully..\n";
  fclose(yyin);
  fclose(yyout);

  /************************      printing output of third input file   ********************************/
   out.open("ass5_12CS10006_quads3.out");
  out<<endl<<endl;
  out<<"\t\tIntermediate code file generated by compiler\t"<<endl;
  out<<"\t\t\t\t\tSymbol Tables \n";
   while(stbl){
  stbl->data->update_offset();	
  stbl->data->print(stbl->name);
  stbl=stbl->next;
   }
   out<<endl<<endl<<"\t\t\t\t\tQuad Array"<<endl<<endl;
  qarr.print();
  out<<endl<<endl;
   out.close();

 /************************      printing output of fourth input file   ********************************/
  ST_gl.head=NULL; ST_gl.last=NULL; 
   qArray::quadPtr=0;
   off=0;
  stbl=makelist<symtable*>(&ST_gl,"Global");
   yyin=fopen("ass5_12CS10006_test4.c","r");
  yyout=fopen("ass5_12CS10006_result4.c","w");       // tokens are generated in this file
   rtn;
  rtn=yyparse();
  if(rtn==0) out<<"Parsed Successfully..\n";
  fclose(yyin);
  fclose(yyout);

  /************************      printing output of fourth input file   ********************************/
  out.open("ass5_12CS10006_quads4.out");
  out<<endl<<endl;
  out<<"\t\tIntermediate code file generated by compiler\t"<<endl;
  out<<"\t\t\t\t\tSymbol Tables \n";
   while(stbl){
  stbl->data->update_offset();	
  stbl->data->print(stbl->name);
  stbl=stbl->next;
   }
   out<<endl<<endl<<"\t\t\t\t\tQuad Array"<<endl<<endl;
  qarr.print();
  out<<endl<<endl;
out.close();
/**************************  Testing  five input file            ************************************/
 ST_gl.head=NULL; ST_gl.last=NULL; 
   qArray::quadPtr=0;
   off=0;
 stbl=makelist<symtable*>(&ST_gl,"Global");
 yyin=fopen("ass5_12CS10006_test5.c","r");
  yyout=fopen("ass5_12CS10006_result5.c","w");       // tokens are generated in this file
   rtn;
  rtn=yyparse();
  if(rtn==0) out<<"Parsed Successfully..\n";
  fclose(yyin);
  fclose(yyout);

  /************************      printing output of five input file   ********************************/
 out.open("ass5_12CS10006_quads5.out");
  out<<endl<<endl;
  out<<"\t\tIntermediate code file generated by compiler\t"<<endl;
  out<<"\t\t\t\t\tSymbol Tables \n";
   while(stbl){
  stbl->data->update_offset();	
  stbl->data->print(stbl->name);
  stbl=stbl->next;
   }
   out<<endl<<endl<<"\t\t\t\t\tQuad Array"<<endl<<endl;
  qarr.print();
  out<<endl<<endl;
 out.close();
return 0;
}


expression conv2Bool(expression e)
{
   if(!e.boolex){
	   e.boolex =new boolexp;
	   e.boolex->FL=makelist(nextinstr());
	   qarr.emit(EQ_,"0",e.symptr->name,"0");
	   e.boolex->TL=makelist(nextinstr());
	   qarr.emit(GOTO,0);
           return e;}
   else
        return e;
}


// returns conerted type //always coverts onlt first parameter used second only as refrence

SYMT_ROW* typecheck(SYMT_ROW* E1,SYMT_ROW* E2,bool& e)
{
	
  Type_Data  *t1=E1->type,*t2=E2->type;
  e=true; 
  while(t1 && t2 && e) 
 {
   if(t1->type_name==t2->type_name && t1->no_==t2->no_)
    {
     t1=t1->right ;t2=t2->right;
    }
   else
    e=false;
  }
  
  if(e && t1==NULL && t2==NULL)
     {  return E1;}
   else{ 
        	 //printf("types ate \n"); 
         if(t1->type_name==Double && t2->type_name==Int)
          {	
	//	printf("\n\n\nyebfe\n\n\n");
	       SYMT_ROW* e =convDouble2Int(E1); return e;
	   }
         if(t1->type_name==Int && t2->type_name==Double )
          {
		 //printf("\n\n\nyebfe\n\n\n\n\n\n");
		 SYMT_ROW* e =convInt2Double(E1); return e;
          }
	  if(t1->type_name==Char && t2->type_name==Int)
          {
	       SYMT_ROW* e =convChar2Int(E1); return e;
	   }
	 if(t1->type_name==Char && t2->type_name==Double)
          {
	       SYMT_ROW* e =convChar2Double(E1); return e;
	   }
	    if(t1->type_name==Int && t2->type_name==Char)
          {
	       SYMT_ROW* e =convInt2Char(E1); return e;
	   }
	  if(t1->type_name==Double && t2->type_name==Char)
          {
	       SYMT_ROW* e =convDouble2Char(E1); return e;
	   }	
	}
   throw 5;
return E1;
}

//convert int to double
SYMT_ROW* convInt2Double(SYMT_ROW* e)
{  
    SYMT_ROW* e1;
    Type_Data* t1=new Type_Data(Double);
    e1=ST_funt->gentemp(t1);
    qarr.emit(ASSIGN,e1->name,e->name);  
   return e1;
}

//convert  double to int 
SYMT_ROW* convDouble2Int(SYMT_ROW* e)
{  
    SYMT_ROW* e1;
    Type_Data* t1=new Type_Data(Int);
    e1=ST_funt->gentemp(t1);
    qarr.emit(ASSIGN,e1->name,e->name);  
    return e1;
}

//convert int to char
SYMT_ROW* convInt2Char(SYMT_ROW* e)
{  
    SYMT_ROW* e1;
    Type_Data* t1=new Type_Data(Char);
    e1=ST_funt->gentemp(t1);
    qarr.emit(ASSIGN,e1->name,e->name);  
   return e1;
}

//convert char to int
SYMT_ROW* convChar2Int(SYMT_ROW* e)
{  
    SYMT_ROW* e1;
    Type_Data* t1=new Type_Data(Int);
    e1=ST_funt->gentemp(t1);
    qarr.emit(ASSIGN,e1->name,e->name);  
   return e1;
}

//convert char to double
SYMT_ROW* convChar2Double(SYMT_ROW* e)
{  
    SYMT_ROW* e1;
    Type_Data* t1=new Type_Data(Double);
    e1=ST_funt->gentemp(t1);
    qarr.emit(ASSIGN,e1->name,e->name);  
   return e1;
}


//convert  double to char
SYMT_ROW* convDouble2Char(SYMT_ROW* e)
{  
    SYMT_ROW* e1;
    Type_Data* t1=new Type_Data(Char);
    e1=ST_funt->gentemp(t1);
    qarr.emit(ASSIGN,e1->name,e->name);  
   return e1;
}

// converts to bool
void convBool2Int(expression& e)
{
    e.symptr=ST_funt->gentemp(new Type_Data(Int));
    backpatch(e.boolex->TL,nextinstr()+PC);
    qarr.emit(ASSIGN,e.symptr->name,"1");
    char *buffer = new char[30];
    sprintf(buffer,"%d",nextinstr()+PC+1); 
    qarr.emit(GOTO,buffer);
    backpatch(e.boolex->FL,nextinstr()+PC);
    qarr.emit(ASSIGN,e.symptr->name,"0");	

}

Type_Data *sym_to_type(symtable* tab)
{
  Type_Data *t=new Type_Data(Function,0,NULL);
  SYMT_ROW* p=tab->head;
  while(p)
  {
      t->right=p->type;
      t=t->right;
      p=p->next;
   }
   
}
