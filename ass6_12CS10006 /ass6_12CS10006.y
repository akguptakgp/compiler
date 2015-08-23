/*************************       Compilers Laboratory Assignment 6             ****************************/
/************************      Written by:Ankit Kumar Gupta (12CS10006)        ***************************/
/************************          Intermediate Code Generation                **************************/    


/************************    C Declarations and Definitions Section              *****************************/
%{ 
 #include <string.h>                    // for string library functions like strdup         
 #include <utility>    
 #include "ass6_12CS10006_translator.h" // for symbol table and quadarray data type and member function implementation
 extern int yylex();                    // to be called by yyparse()
 void yyerror(char *s);                 // to throw symtex error 
 extern int no_lines;                   // to keep count of number of lines parsed so that can be used while throwing syntex error 
 symtable ST_gl;                        //global symbol table declaration
 symtable* ST_funt=&ST_gl;		//current symbol table pointer declaration for lookup in current function's symbol table  					        //initilized with global symbol table
 qArray qarr;			        //quad array declaration
 bool flag=false;                        // to check whether certain identifier already existed before lookup
 using namespace std;					// in a particular symbol tabel will be set during lookup call
 int pointer_no;			// number of times * has occured while pointer declaration
 pair<char*,int>  fn_st[30]; 
 int pair_indx=0;
%}


/********************         union declaration for the data type of tokens and types     ********************/

%union {
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
}

/***************************       Token Declarations ( will be generated in y.tab.h file)    *********************************/
%token <intval> Auto			//  keywords
%token <intval> Break
%token <intval> Case
%token <intval> Char_
%token <intval> Const
%token <intval> Continue
%token <intval> Default
%token <intval> Do
%token <intval> Double_
%token <intval> Else
%token <intval> Enum
%token <intval> Extern
%token <intval> Float
%token <intval> For
%token <intval> Goto
%token <intval> If
%token <intval> Inline
%token <intval> Int_
%token <intval> Long				// no specific type needed for all keywords
%token <intval> Register
%token <intval> Restrict
%token <intval> Return
%token <intval> Short
%token <intval> Signed
%token <intval> Sizeof
%token <intval> Static
%token <intval> Struct
%token <intval> Switch
%token <intval> Typedef
%token <intval> Union
%token <intval> Unsigned
%token <intval> Void_
%token <intval> Volatile
%token <intval> While
%token <intval> Bool
%token <intval> Complex
%token <intval> Imaginary             

%token <symp> identifier              // symp type because lexer need to store idetifier in the symbol table and
				     // return entry created due to lookup(idetifier_name) in lexical analysis phase
%token <intval> Int_Constant          // to get value of integer constant
%token <floatval> Floating_Const      // to get value of floating constant
%token <intval> Enumeration_Constant  // to get value of enumeration constant  
%token <intval> Character_Constant    // to get value of character constant
%token <stringval> string_literal     // to get value of string_literal

%token <intval> P1                           
%token <intval> P2 
%token <intval> P3			// punctuators
%token <intval> P4
%token <intval> P5
%token <intval> P6
%token <intval> P7
%token <intval> P8
%token <intval> P9
%token <intval> P10
%token <intval> P11
%token <intval> P12
%token <intval> P13
%token <intval> P14
%token <intval> P15
%token <intval> P16
%token <intval> P17
%token <intval> P18
%token <intval> P19
%token <intval> P20
%token <intval> P21
%token <intval> P22
%token <intval> P23				// no specific type needed for all punctuator
%token <intval> P24
%token <intval> P25
%token <intval> P26
%token <intval> P27
%token <intval> P28
%token <intval> P29
%token <intval> P30
%token <intval> P31
%token <intval> P32
%token <intval> P33
%token <intval> P34
%token <intval> P35
%token <intval> P36
%token <intval> P37
%token <intval> P38
%token <intval> P39
%token <intval> P40
%token <intval> P41
%token <intval> P42
%token <intval> P43
%token <intval> P44
%token <intval> P45
%token <intval> P46
%token <intval> P47

 
/***********************************           Expresssions            *****************************************/
 
%type<exp> primary_expression		   	 //   type of all expressions is expression which contains four fields 
%type<exp> postfix_expression		        //        a) symptr for arithematic expressions 
%type<list_ptr> argument_expression_list        //	  b) boolex for boolean expressions   
%type<exp> unary_expression  		       //	  c) symptr for Array expressions
%type<exp> cast_expression		      //	  d) Type_Data* for Array expressions  
%type<exp> multiplicative_expression 		
%type<exp> additive_expression 
%type<exp> shift_expression
%type<exp> relational_expression	 //
%type<exp>  equality_expression		//
%type<exp> AND_expression				//
%type<exp> exclusive_OR_expression //
%type<exp> inclusive_OR_expression	//
%type<exp> logical_AND_expression	//
%type<exp> logical_OR_expression	//
%type<exp> conditional_expression // 
%type<exp> assignment_expression 
%type<intval> assignment_operator
%type<exp> expression	                            
%type<exp> Constant_expression 
%type<exp> assignment_expression_opt
%type<exp> expression_opt
%type<symp> Constant
	
/************************************               Declaration        *********************************************/
  
%type<symp> declaration
%type<t_exp> declaration_specifiers
%type<list_ptr> init_declarator_list
%type<symp> init_declarator
%type<t_exp> type_specifier
%type<intval> specifier_qualifier_list
%type<intval> Enum_specifier   
%type<intval> Enumerator_list
%type<intval> Enumerator
%type<intval> type_qualifier
%type<intval> function_specifier
%type<symp> declarator
%type<symp> direct_declarator
%type<intval> pointer
%type<intval> type_qualifier_list
%type<symtp> parameter_type_list
%type<symtp> parameter_list
%type<symp> parameter_declaration  
//%type<list_ptr> identifier_list
%type<intval> type_name
%type<exp> initializer   
%type<symp> initializer_list
%type<intval> designation
%type<intval> designator_list 
%type<intval> storage_class_specifier
%type<intval> designator
%type<list_ptr> init_declarator_list_opt
%type<t_exp> declaration_specifiers_opt
%type<intval> pointer_opt
%type<symp> identifier_opt
//%type<list_ptr> identifier_list_opt

/************************************          Statements         *************************************************/
	
%type<stmt> statement
%type<stmt> labeled_statement
%type<stmt> compound_statement
%type<stmt> block_item_list
%type<stmt> block_item
%type<stmt> expression_statement
%type<stmt> selection_statement
%type<stmt> iteration_statement
%type<stmt> jump_statement
%type<stmt> block_item_list_opt
	
/**********************************     External Definition        ****************************************/

%type<intval> External_declaration
%type<intval> function_definition
//%type<intval> declaration_list

/****************************     Additional types for augmentations      ******************************************/
%type<intval> M    // corresponding to this rule need to store nextinstr value so intval type
	

%type<stmt> N      // to stop fall throw

%start translation_unit

  
%%

/***************************************** Expressions  ********************************************************/
primary_expression:
		    identifier   {   $$.symptr=$1; $$.boolex=NULL;$$.array=NULL;$$.type=NULL;} 
		   |Constant    {  $$.symptr=$1; $$.boolex=NULL;$$.array=NULL;$$.type=NULL;}  				
		   |string_literal 
                      {
 			  $$.symptr=ST_funt->gentemp(new Type_Data(Pointer,0,new Type_Data(Char)),yylval.stringval); 
			  qarr.emit(ASSIGN,$$.symptr->name,yylval.stringval);
                          $$.boolex=NULL;$$.array=NULL;$$.type=NULL;
		       }
		   |P24 expression P25  
			{
			        $$=$2; 
 			}
		   ;

postfix_expression	:
			 primary_expression		// $$=$1
			|postfix_expression P22 expression P23  //Arrays in Expressions 
					{
                                         if($1.array==NULL)
                                         {
 					  $$.array=$1.symptr;
					  $$.type=$1.symptr->type->right;
                                          $$.symptr=ST_funt->gentemp(new Type_Data(Int),NULL);
                                          char *buffer=new char[30]; 
					  sprintf(buffer,"%d",$$.type->size());
					  qarr.emit(MULT,$$.symptr->name,$3.symptr->name,buffer);
                                         }
					else
					 {
						$$.array=$1.array;
					        $$.type= $1.type->right;
						$$.symptr=ST_funt->gentemp(new Type_Data(Int),NULL);		
						SYMT_ROW* tmp=ST_funt->gentemp(new Type_Data(Int),NULL);
						char *buffer=new char[30]; sprintf(buffer,"%d",$$.type->size());
 						qarr.emit(MULT,tmp->name,$3.symptr->name,buffer);
                                                qarr.emit(PLUS,$$.symptr->name,$1.symptr->name,tmp->name);
					 }
						$$.boolex=NULL;
					 }  
			|postfix_expression P24 argument_expression_list P25{ //function call in Expressions
                          	list_<SYMT_ROW*>* p=$3;
				 int c=0;
                                 bool b;
                                 SYMT_ROW *st=ST_gl.lookup($1.symptr->name)->stptr->head;
                                 while(p){ 
				//printf("calling %s %s\n\n\n",p->data->name,st->name);     
				 //SYMT_ROW* type=typecheck(p->data,st,b);   // type check every param
				 //printf("c=%d",c);
                                 //if(!type)
 				 qarr.emit(PARAM,p->data->name);
				 p=p->next;st=st->next;c++;
				 } 
				// printf("calling %s %s\n\n\n",p->data->name,st->name); 
				 symtable* ST=ST_gl.lookup($1.symptr->name)->stptr;
				// if(st!=ST->last) yyerror("to few arguments\n");
				//else {
				 st=ST->lookup("retval");
				 //printf("type is \n\n"); st->type->print();
				 Type_Data *t=st->type;
				  if(t==NULL) t=new Type_Data(Int);
				 $$.symptr=ST_funt->gentemp(t,NULL);
                                 char *buffer = new char[30]; sprintf(buffer,"%d",c);	
				 qarr.emit(CALL,$$.symptr->name,$1.symptr->name,buffer);//}	
                                }
			|postfix_expression P24 P25 { //function call in Expressions
                                   
         			 symtable* ST=ST_funt->lookup($1.symptr->name)->stptr;
				 SYMT_ROW* st=ST->lookup("retval");
                                 Type_Data *t=st->type;
                                 $$.symptr=ST_funt->gentemp(t,NULL);
			         qarr.emit(CALL,$$.symptr->name,$1.symptr->name,"0");
				 }
			|postfix_expression P28 identifier { }   //to be skipped
			|postfix_expression P29 identifier { }   //to be skipped
			|postfix_expression P30                 // postfix increment
                              { 
				 $$.symptr=ST_funt->gentemp($1.symptr->type,NULL); 
				 qarr.emit(ASSIGN,$$.symptr->name,$1.symptr->name); 
				 qarr.emit(PLUS,$1.symptr->name,$1.symptr->name,"1");
                                 $$.boolex=NULL;$$.array=NULL;$$.type=NULL;
                             }
			|postfix_expression P31    //postfix decrement
				{
					 $$.symptr=ST_funt->gentemp($1.symptr->type,NULL); 
                                         qarr.emit(ASSIGN,$$.symptr->name,$1.symptr->name);
					 qarr.emit(MINUS,$1.symptr->name,$1.symptr->name,"1");
                                         $$.boolex=NULL;$$.array=NULL;$$.type=NULL;
				}
			|P24 type_name P25 P26 initializer_list P27 { } // no type casting to be skipped
			|P24 type_name P25 P26 initializer_list P46 P27 { } // no type casting to be skipped
			;

argument_expression_list	: //argument list for function calling
				assignment_expression { $$=makelist<SYMT_ROW*>($1.symptr);}
				|argument_expression_list P46 assignment_expression {$$=merge<SYMT_ROW*>($1,makelist<SYMT_ROW*>($3.symptr)); }
				;
//unary_operator  :  P16 { } |P17{ }  |P18{ }  |P19{ }  |P20{ }  |P21{ } ;
			
unary_expression	:
			postfix_expression // $$=$1
			|P30 unary_expression // prefix increment
				{ 
				       $$.symptr=ST_funt->gentemp($2.symptr->type,NULL); 
				       qarr.emit(PLUS,$2.symptr->name,$2.symptr->name,"1"); 
                                       qarr.emit(ASSIGN,$$.symptr->name,$2.symptr->name);
                                       $$.boolex=NULL;$$.array=NULL;$$.type=NULL;
        			}
			|P31 unary_expression // perfix decrement
				{
				      $$.symptr=ST_funt->gentemp($2.symptr->type,NULL); 
                                      qarr.emit(MINUS,$2.symptr->name,$2.symptr->name,"1"); 
				      qarr.emit(ASSIGN,$$.symptr->name,$2.symptr->name);
				      $$.boolex=NULL;$$.array=NULL;$$.type=NULL;
				}
			|P16 cast_expression // Address operator
					{
					 $$.symptr=ST_funt->gentemp(new Type_Data(Pointer,0,$2.symptr->type)); 
					 qarr.emit(ADDR,$$.symptr->name,$2.symptr->name);
					 $$.boolex=NULL;$$.array=NULL;$$.type=NULL;
					}   
/***%%%%%%%%%%%%%%%%%%%%%%%%%%%************************Doubt********%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*********************************/
			|P17 M cast_expression  // derefrence operator
				{
					 $$.symptr=ST_funt->gentemp($3.symptr->type->right,NULL); 
					 qarr.emit(DREF,$$.symptr->name,$3.symptr->name);
					 $$.array=$3.symptr;
					 $$.array->initial_value=new char[30];
					 sprintf($$.array->initial_value,"%d",$2)  ;
					 $$.boolex=NULL;$$.type=NULL;
				}   // doubt
			|P18 cast_expression { $$=$2; } // Unary PLUS
			|P19 cast_expression             // Unary MINUS
				{
					 $$.symptr=ST_funt->gentemp($2.symptr->type,NULL);
					 qarr.emit(UMINUS,$$.symptr->name,$2.symptr->name);
					 $$.boolex=NULL;$$.array=NULL;$$.type=NULL;
				}
/*************&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/
			|P20 cast_expression //bit negation
				{	
					 $$.symptr=ST_funt->gentemp($2.symptr->type,NULL); 
					 qarr.emit(UBNEG,$$.symptr->name,$2.symptr->name);
					 $$.boolex=NULL;$$.array=NULL;$$.type=NULL;
				}
			|P21 cast_expression  //negation
				{
				  $$.symptr=ST_funt->gentemp($2.symptr->type,NULL); 
				  qarr.emit(UNOT,$$.symptr->name,$2.symptr->name);
				  $$.boolex=NULL;$$.array=NULL;$$.type=NULL;
				}
			|Sizeof unary_expression { } //to be skipped
			|Sizeof P24 type_name P25 { } //to be skipped
 			;

cast_expression		:
			unary_expression 			       // $$=$1
			|P24 type_name P25 cast_expression { }		//to be skipped
			;

multiplicative_expression   :
		             cast_expression					// $$=$1
			    |multiplicative_expression P17 cast_expression  // multiplication
  				 { 
					SYMT_ROW *st1,*st2;
					if($1.symptr->type->type_name==Int && $3.symptr->type->type_name==Double)
					 {	st1=convInt2Double($1.symptr); st2=$3.symptr;  }	
					else
					if($3.symptr->type->type_name==Int && $1.symptr->type->type_name==Double)
					 {	st2=convInt2Double($3.symptr); st1=$1.symptr;  }
					else {	st1=$1.symptr;st2=$3.symptr;}

					$$.symptr=ST_funt->gentemp(st1->type,NULL); 
					qarr.emit(MULT,$$.symptr->name,st1->name,st2->name); 
					$$.boolex=NULL;$$.array=NULL;$$.type=NULL;
				}
			    |multiplicative_expression P32 cast_expression  //division
				{
				     SYMT_ROW *st1,*st2;
					if($1.symptr->type->type_name==Int && $3.symptr->type->type_name==Double)
					 {	st1=convInt2Double($1.symptr); st2=$3.symptr;  }	
					else
					if($3.symptr->type->type_name==Int && $1.symptr->type->type_name==Double)
					 {	st2=convInt2Double($3.symptr); st1=$1.symptr;  }
					else {	st1=$1.symptr;st2=$3.symptr;}

					$$.symptr=ST_funt->gentemp(st1->type,NULL); 
					qarr.emit(DIV,$$.symptr->name,st1->name,st2->name); 
					$$.boolex=NULL;$$.array=NULL;$$.type=NULL; 
				}
	          	 |multiplicative_expression P33 cast_expression // modulo
				{ 
			            SYMT_ROW *st1,*st2;
					if($1.symptr->type->type_name==Int && $3.symptr->type->type_name==Double)
					 {	st1=convInt2Double($1.symptr); st2=$3.symptr;  }	
					else
					if($3.symptr->type->type_name==Int && $1.symptr->type->type_name==Double)
					 {	st2=convInt2Double($3.symptr); st1=$1.symptr;  }
					else {	st1=$1.symptr;st2=$3.symptr;}

					$$.symptr=ST_funt->gentemp(st1->type,NULL); 
					qarr.emit(MOD,$$.symptr->name,st1->name,st2->name); 
					$$.boolex=NULL;$$.array=NULL;$$.type=NULL;
				}
                ;

additive_expression	 :
			 multiplicative_expression		// $$=$1
			 |additive_expression P18 multiplicative_expression //adition
				{ 	
					SYMT_ROW *st1,*st2;
					if($1.symptr->type->type_name==Int && $3.symptr->type->type_name==Double)
					 {	st1=convInt2Double($1.symptr); st2=$3.symptr;  }	
					else
					if($3.symptr->type->type_name==Int && $1.symptr->type->type_name==Double)
					 {	st2=convInt2Double($3.symptr); st1=$1.symptr;  }
					else {	st1=$1.symptr;st2=$3.symptr;}

					$$.symptr=ST_funt->gentemp(st1->type,NULL); 
					qarr.emit(PLUS,$$.symptr->name,st1->name,st2->name); 
					$$.boolex=NULL;$$.array=NULL;$$.type=NULL;
				}
			 |additive_expression P19 multiplicative_expression // substraction
				 {
					 SYMT_ROW *st1,*st2;
					if($1.symptr->type->type_name==Int && $3.symptr->type->type_name==Double)
					 {	st1=convInt2Double($1.symptr); st2=$3.symptr;  }	
					else
					if($3.symptr->type->type_name==Int && $1.symptr->type->type_name==Double)
					 {	st2=convInt2Double($3.symptr); st1=$1.symptr;  }
					else {	st1=$1.symptr;st2=$3.symptr;}

					$$.symptr=ST_funt->gentemp(st1->type,NULL); 
					qarr.emit(MINUS,$$.symptr->name,st1->name,st2->name); 
					$$.boolex=NULL;$$.array=NULL;$$.type=NULL;
				}
			 ;
shift_expression	:
			additive_expression						// $$=$1
			|shift_expression P34 additive_expression 
				{
					 $$.symptr=ST_funt->gentemp($1.symptr->type,NULL); 
					 qarr.emit(LSHFT,$$.symptr->name,$1.symptr->name,$3.symptr->name);
					 $$.boolex=NULL;$$.array=NULL;$$.type=NULL;
				}
			|shift_expression P35 additive_expression 
				{       $$.symptr=ST_funt->gentemp($1.symptr->type,NULL); 
				 	qarr.emit(RSHFT,$$.symptr->name,$1.symptr->name,$3.symptr->name); 
					$$.boolex=NULL;$$.array=NULL;$$.type=NULL;	
				}
			;
relational_expression  :
			shift_expression 						// $$=$1
			|relational_expression P36 shift_expression  // less than
				{
					 $$.boolex=new boolexp;
          			         $$.boolex->TL=makelist<int>(nextinstr());
				         $$.boolex->FL=makelist<int>(nextinstr()+1);
					 qarr.emit(LT_,0,$1.symptr->name,$3.symptr->name);
					 qarr.emit(GOTO,0);
				      	 $$.symptr=NULL;$$.array=NULL;$$.type=NULL;
				}
			|relational_expression P37 shift_expression // greater than
				{
					 $$.boolex=new boolexp;
    				         $$.boolex->TL=makelist<int>(nextinstr());
					 $$.boolex->FL=makelist<int>(nextinstr()+1);
					 qarr.emit(GT_,0,$1.symptr->name,$3.symptr->name);
					 qarr.emit(GOTO,0);
                                         //qarr.print();
					//printf("executed\n");
					 $$.symptr=NULL;$$.array=NULL;$$.type=NULL;
				 }
			|relational_expression P1 shift_expression // less than
				 {
					  $$.boolex=new boolexp;
            				  $$.boolex->TL=makelist<int>(nextinstr());
				          $$.boolex->FL=makelist<int>(nextinstr()+1);
					  qarr.emit(LEQ_,0,$1.symptr->name,$3.symptr->name);
					  qarr.emit(GOTO,0);
					  $$.symptr=NULL;$$.array=NULL;$$.type=NULL;
				}
			|relational_expression P2 shift_expression  //greater than
				{
					  $$.boolex=new boolexp;
         				  $$.boolex->TL=makelist<int>(nextinstr());
				          $$.boolex->FL=makelist<int>(nextinstr()+1);
					  qarr.emit(GEQ_,0,$1.symptr->name,$3.symptr->name);				
					  qarr.emit(GOTO,0);
					  $$.symptr=NULL;$$.array=NULL;$$.type=NULL;
				}
			;
equality_expression :
			relational_expression					// $$=$1
			|equality_expression P3 relational_expression // equal
				{
	       				 $$.boolex=new boolexp;
           				 $$.boolex->TL=makelist<int>(nextinstr());
					 $$.boolex->FL=makelist<int>(nextinstr()+1);
					 qarr.emit(EQ_,0,$1.symptr->name,$3.symptr->name); 
					 qarr.emit(GOTO,0);
					 $$.symptr=NULL;$$.array=NULL;$$.type=NULL;
				}
			|equality_expression P4 relational_expression // not equal
				{ 
				  	  $$.boolex=new boolexp;
           				  $$.boolex->TL=makelist<int>(nextinstr());
				    	  $$.boolex->FL=makelist<int>(nextinstr()+1);
					  qarr.emit(NEQ_,0,$1.symptr->name,$3.symptr->name);
					  qarr.emit(GOTO,0);
					  $$.symptr=NULL;$$.array=NULL;$$.type=NULL;
				}
			;
AND_expression :
			equality_expression 					// $$=$1
			|AND_expression P16 equality_expression 
				{
					 $$.symptr=ST_funt->gentemp($1.symptr->type,NULL); 
					 qarr.emit(UAND,$$.symptr->name,$1.symptr->name,$3.symptr->name); 
					 $$.boolex=NULL;$$.array=NULL;$$.type=NULL;
				}
			;
exclusive_OR_expression :
			   AND_expression							// $$=$1
			  |exclusive_OR_expression P38 M AND_expression 
				{
					 $$.symptr=ST_funt->gentemp($1.symptr->type,NULL); 
					 qarr.emit(XOR,$$.symptr->name,$1.symptr->name,$4.symptr->name);
					 $$.boolex=NULL;$$.array=NULL;$$.type=NULL;

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
			  ;
inclusive_OR_expression: 
			exclusive_OR_expression				// $$=$1
			|inclusive_OR_expression P39 exclusive_OR_expression 
				{
				    $$.symptr=ST_funt->gentemp($1.symptr->type,NULL); 
				    qarr.emit(UOR,$$.symptr->name,$1.symptr->name,$3.symptr->name);
				    $$.boolex=NULL;$$.array=NULL;$$.type=NULL; 
				}
				 ;
M      : 			 { $$=nextinstr();};
N      :			 { $$.NL=makelist<int>(nextinstr()); qarr.emit(GOTO,0); };		
logical_AND_expression :
					 inclusive_OR_expression	// $$=$1
					 |logical_AND_expression P40 M inclusive_OR_expression 
	/* 			 E -> E1 && M E2
           	 		if $1 == true then we need to goto $4 (i.e. TL of $1 has to be backpatched at the location of $4),
           		 hence M is used as $3 to mark the location before $4 which would used during backpatching                       
                    	  if $1== false then we cannot do anything nothing ... it would done later in the parsing process
                       */
						{
							expression e1=conv2Bool($1);
							expression e2=conv2Bool($4);
						        backpatch(e1.boolex->TL,$3+PC);
		  			                $$.boolex=new boolexp; 
						        $$.boolex->FL=merge<int>(e1.boolex->FL,e2.boolex->FL); 
						        $$.boolex->TL=e2.boolex->TL; 
							$$.symptr=NULL;$$.array=NULL;$$.type=NULL;
						}
					;
logical_OR_expression : 
					logical_AND_expression 			// $$=$1
					|logical_OR_expression P41 M logical_AND_expression 
						{
						     expression e1=conv2Bool($1);
						     expression e2=conv2Bool($4);
						     backpatch(e1.boolex->FL,$3+PC);
					             $$.boolex=new boolexp; 
						     $$.boolex->TL=merge<int>(e1.boolex->TL,e2.boolex->TL); 
						     $$.boolex->FL=e2.boolex->FL; 
						     $$.symptr=NULL;$$.array=NULL;$$.type=NULL;
						}
					;
conditional_expression  : 
						 logical_OR_expression 	// $$=$1
						| logical_OR_expression N P42 M expression N P43 M conditional_expression
 						{
							  
						          expression e1=$1;//conv2Bool($1);
		          				  $$.symptr=ST_funt->gentemp($5.symptr->type); 
						  	  qarr.emit(ASSIGN,$$.symptr->name,$9.symptr->name);
		          				  list_<int> *l=makelist<int>(nextinstr());
							  qarr.emit(GOTO,0);
							  backpatch($6.NL,nextinstr()+PC);
		         				  qarr.emit(ASSIGN,$$.symptr->name,$5.symptr->name);
		       					  l=merge<int>(l,makelist<int>(nextinstr()));
		        				  qarr.emit(GOTO,0);
			  				  backpatch($2.NL,nextinstr()+PC);
			  				  backpatch(e1.boolex->TL,$4+PC);
					 	          backpatch(e1.boolex->FL,$8+PC);
					 	  	  backpatch(l,nextinstr()+PC);
							  $$.boolex=NULL;$$.array=NULL;$$.type=NULL;
						} 
						;

assignment_expression  : 
		        conditional_expression 	 	// $$=$1
		        |unary_expression assignment_operator assignment_expression 
				{ 

				       if(!$1.type && !$3.type){
						if($1.array)           // it is a arithemic expression  assignment 
				                   {
						
						            qarr.delete_(); 
							    qarr.emit(STR,$1.array->name,$3.symptr->name); 
							    $3.symptr->stptr=new symtable();   
/*////////////////////////////////                    */    ST_funt->shift($1.symptr,$3.symptr->stptr); free($3.symptr->stptr);
						   }
						else{
						   if($3.boolex){
							    convBool2Int($3);
						            qarr.emit(ASSIGN,$1.symptr->name,$3.symptr->name);
							}
					       	  else{
					           bool e; 
						   SYMT_ROW *st=typecheck($3.symptr,$1.symptr,e);
						   if(e)
                                                   qarr.emit(ASSIGN,$1.symptr->name,$3.symptr->name);
						   else 
						   qarr.emit(ASSIGN,$1.symptr->name,st->name);	
							}			
               					}
					}
                                       if($1.type && !$3.type) // it is array refrence assignement
                                        {
                                           qarr.emit(ARR_REF,$1.array->name,$1.symptr->name,$3.symptr->name);                             
					}
					if(!$1.type && $3.type) // it is array refrence assignement
                                        {
					  //printf("\n\n\nyes\n\n\n");
                                           qarr.emit(ARR_DREF,$1.symptr->name,$3.array->name,$3.symptr->name);                             
					}
                                       else if($1.type && $3.type) // it is array derefrence assignement
					     {
                                              SYMT_ROW* tmp=ST_funt->gentemp($3.type);
                                              qarr.emit(ARR_DREF,tmp->name,$3.array->name,$3.symptr->name); //$3.symptr->name); 
					      qarr.emit(ARR_REF,$1.array->name,$1.symptr->name,tmp->name); 
					}
                                       $$=$1;
				 } 
		        ;
assignment_operator   :  P5{ }   |  P6{ }  |  P7{ }  |  P8{ }  |  P9{ }  | P10{ }  |  P11{ } |  P12{ } |   P13{ } |  P14{ } |  P15{ }
					  ;

expression:
	     assignment_expression // { $$=$1;}					// $$=$1
      |expression P46 assignment_expression { }
      ;
Constant_expression  : conditional_expression 		// $$=$1
					;

Constant:
	        Int_Constant  
				{  		
					char *buffer=new char[30];
					sprintf(buffer,"%d",yylval.intval);
					$$=ST_funt->gentemp(new Type_Data(Int),buffer);
			  		qarr.emit(ASSIGN,$$->name,buffer);		
				 }
               |Floating_Const 
				{
					char *buffer=new char[30];
					sprintf(buffer,"%lf",yylval.floatval);
					$$=ST_funt->gentemp(new Type_Data(Double),buffer);
				  	qarr.emit(ASSIGN,$$->name,buffer);
				 }
	       |Enumeration_Constant { }     // enum to be skipped
 	       |Character_Constant  
				{
		  			char *buffer=new char[30];
					sprintf(buffer,"%c",yylval.charval);
   		  	  		$$=ST_funt->gentemp(new Type_Data(Char),buffer); 
         				char *buffer1=new char[30];
         				buffer1[0]=buffer1[2]='\''; buffer1[1]=yylval.charval;buffer1[3]='\0';
				    	qarr.emit(ASSIGN,$$->name,buffer1); 
				}
 		   	;


/**********************************Declaration *********************************************/
declaration:	
		declaration_specifiers init_declarator_list_opt P44 
			{                      
			    list_<SYMT_ROW*>* p=$2;
			       do{
                                   Type_Data *t=new Type_Data($1.type);
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
			|declaration_specifiers P44 { }			// to be skipped
			;

declaration_specifiers_opt:
                        declaration_specifiers { } // we have a single datatype on a line, hence it will be skipped
			|		{ }
			;
declaration_specifiers: 
		        storage_class_specifier declaration_specifiers_opt { } // storage class specifiers skipped
			|type_specifier declaration_specifiers_opt 				// $$=$1
			|type_qualifier declaration_specifiers_opt  { }// type qualifier skipped
			|function_specifier declaration_specifiers_opt { }// function specifier skipped
			;

init_declarator_list_opt:
                           init_declarator_list 
		           ;			

init_declarator_list:
			init_declarator 
				{
				   $$=makelist($1);
				}
			|init_declarator_list P46 init_declarator 
				{
				$$=merge($1,makelist($3)); 
				}

			;
init_declarator:
			declarator  
			|declarator P5 initializer 
			{
			     	if($3.type)
					qarr.emit(ARR_DREF,$1->name,$3.array->name,$3.symptr->name);
                                if($3.symptr->initial_value)
				{
                                    qarr.delete_();
	                            $1->initial_value=$3.symptr->initial_value; 
				   // qarr.emit(ASSIGN,$1->name,$3.symptr->initial_value); 
	                            $1->stptr=new symtable();   
				    ST_funt->shift($3.symptr,$1->stptr); free($1->stptr);
				}
                                else
				{
	                              qarr.emit(ASSIGN,$1->name,$3.symptr->name);
			        }
                         } 
			;
storage_class_specifier: // to be skipped as per assignment demand
			Extern
			|Static
			|Auto
			|Register
			;
type_specifier: 	// only few are used
			Void_ { $$.type=Void; $$.width=0;}
			|Char_ { $$.type=Char; $$.width=size_of_char;}
			|Short { }
			|Int_ { $$.type=Int; $$.width=size_of_int;}
			|Long { }
			|Float { }
			|Double_ { $$.type=Double; $$.width=size_of_double;}
			|Signed { }
			|Unsigned { }
			|Bool { }
			|Complex { }
			|Imaginary { }
			|Enum_specifier { }
			;

specifier_qualifier_list_opt:	 // it is skipped				
			specifier_qualifier_list			
			|															// 
			;
specifier_qualifier_list:
			type_specifier specifier_qualifier_list_opt { }       // it will not be used -- yet doubt
			|type_qualifier specifier_qualifier_list_opt	{ }   // type-qualifier to be skipped
			;
identifier_opt		:       // not used here
			identifier
			|	{ }
			;
Enum_specifier:							
		        Enum identifier_opt P26 Enumerator_list P27	{ }		// enum to be skipped
		        |Enum identifier_opt P26 Enumerator_list P46 P27 { }		// enum to be skipped
	    	        |Enum identifier { }					        // enum to be skipped
		        ;
Enumerator_list:
		Enumerator	{ }			// enum to be skipped
		|Enumerator_list P46 Enumerator	{ }	// enum to be skipped
		;
Enumerator:
		Enumeration_Constant	{ }												// enum to be skipped
		|Enumeration_Constant P5 Constant_expression { }	// enum to be skipped
		;
type_qualifier:  
		Const	{ }				// type qualifier skipped
		|Restrict	{ }			// type qualifier skipped
		|Volatile	{ }			// type qualifier skipped
		;
function_specifier: 
		Inline	{ }					// function specifier skipped
		;
pointer_opt	:
		pointer  { $$=$1; } // status variable to check if its a pointer declaration
		|       {  $$=0;}
		;
pointer:
		 P17 type_qualifier_list_opt            {$$=1;   }
		 |P17 type_qualifier_list_opt pointer   {$$=$3+1;  }
		;
declarator:
		pointer_opt direct_declarator 
			{ 
			   $$=$2;
				SYMT_ROW* l=NULL;
                           if($2->stptr) 
                                 l=$2->stptr->lookup("retval");
			   while($1--)
				{
                                 if(l)
					$2->stptr->update(new Type_Data(Pointer,0,NULL),l);
				else{
				         ST_gl.update(new Type_Data(Pointer,0,NULL),$$);}
				}
			}			
			;
type_qualifier_list_opt	:			
			type_qualifier_list { }		// to be skipped
			|											// only this rule will be used
			;
assignment_expression_opt:
			assignment_expression			// $$=$1
			|	{ }
			;
/*identifier_list_opt	:
			//identifier_list  { $$=$1; } // $$=$1; }		// calling / declaring a function without any parameters
				      { $$=NULL;}
			;*/
direct_declarator:
		   identifier       //$$=$1 simple declaration
		   |direct_declarator P22 type_qualifier_list_opt assignment_expression_opt P23 // Array Declaration
				{
					$$=$1;
  					 qarr.delete_(); 	
 					symtable *p=new symtable;    ST_funt->shift($4.symptr,p);					
                                        ST_funt->update(new Type_Data(Array,atoi($4.symptr->initial_value),NULL),$1); free(p);
                                }	
		  |direct_declarator P24 parameter_type_list P25  //Function Declaration with parameters
				{
						$$=$1;
						ST_funt=$3;
						//$$->type=sym_to_type($3);  
						fn_st[pair_indx].first=$$->name;
						fn_st[pair_indx++].second=qArray::quadPtr;
						$$->type=new Type_Data(Function,0,NULL);
						$$->stptr=$3;		
				}
		|direct_declarator P24 P25   // Function Declaration without parameter
				{
                                        $$=$1;
					fn_st[pair_indx].first=$$->name;
					fn_st[pair_indx++].second=qArray::quadPtr;
					$$->stptr=new symtable();  ST_funt=$1->stptr;
					$$->type=new Type_Data(Function,0,NULL);
				}
                |P24 declarator P25 { }  //to be skippped
                |direct_declarator P22 Static type_qualifier_list_opt assignment_expression P23	// Static to be skipped
		|direct_declarator P22 type_qualifier_list Static assignment_expression P23	// type-qualifier to be skipped
                |direct_declarator P22 type_qualifier_list_opt P17 P23 // type-qualifier to be skipped
		;
type_qualifier_list:	
		type_qualifier						// type-qualifier to be skipped
		|type_qualifier_list type_qualifier			// type-qualifier to be skipped
		;
parameter_type_list:
			parameter_list 			// $$=$1
			|parameter_list P46 P45		// to be skippped
			;
parameter_list:
		parameter_declaration 
		{
				 $$=new symtable;
				 //$$->insert($1);
					//printf("\n\n\n%s\n",$1->name);	
				 if(!flag) { ST_funt->shift($1,$$);} 
				else{	
                                      flag=false;
                                      Type_Data* t=$1->type;
       				      $1=$$->lookup($1->name,1);ST_funt->update(t,$1);
				      //$$->insert($1);
				  }//printf("existed \n\n\n");	
 	         }
		|parameter_list P46 parameter_declaration 
			{ 
                              //  printf("type is\n");
                               // $3->head->type->print(); 
				$$=$1;
				if(!flag) { ST_funt->shift($3,$$);} 
				else{	
                                      flag=false;
				Type_Data* t=$3->type;
                                SYMT_ROW* tmp=$$->lookup($3->name,1);  $$->update(t,tmp);
				      //$$->insert($3);
				  }
				//$$->insert($3); 
				//*$$=merge_symtab(*$1,*$$);
				//if(flag) flag=false;
 			}
		;
parameter_declaration:
			declaration_specifiers declarator	
			{
			           
				    //ST_funt->update(new Type_Data($1.type),$$);	                                              
                                   /*$$=new symtable;*/
                                       if(!flag)
					{
					     ST_funt->update(new Type_Data($1.type),$2);
					    // ST_gl.shift($2,$$);
					      $$=$2;
					}
                                     else
                                       {
				
				  	        $$= new SYMT_ROW;
						$$->name=$2->name;
						ST_funt->update(new Type_Data($1.type),$$);
					        //$$->type=new Type_Data($1.type),tmp);
					
					}
                                      
				//     ST=$$;			
			} // edit
		       |declaration_specifiers	{ } // function declaration without  the name of the parameters is not permitted
		;

/*identifier_list:          // this rule will never get executed  becuase parameter declaration is not allowed inside a function 						//and a function can only be called from a function
		 identifier{ $$=makelist<SYMT_ROW*>($1); }
		|identifier_list P46 identifier{ $$=merge<SYMT_ROW*>($1,makelist<SYMT_ROW*>($3));} //} //
		;*/
type_name: 
 		specifier_qualifier_list 
		;
initializer:
		assignment_expression		{}      // to be done			
		|P26  initializer_list  P27 	{ }	// array initialization is skipped
		|P26  initializer_list P46  P27  { }    // array initialization is skipped
		;
designation_opt:
		designation
		|
		;
initializer_list:   					// to be skipped
		designation_opt initializer{} 
		|initializer_list P46 designation_opt initializer
		;
designation:
		designator_list  P5 
		;
designator_list:
		designator
		|designator_list designator
		;
designator:
		P22 Constant_expression P23
	 	|P28 identifier
	 	;
/****************************************Statements ********************************************/
statement:
		labeled_statement { }// labeled_stmt is skipped
		|compound_statement 			// $$=$1
		|expression_statement		
		|selection_statement		// $$=$1
		|iteration_statement		// $$=$1
		|jump_statement				// $$=$1
		;
labeled_statement:
			identifier P43 statement {}// labeled_stmt is skipped
			|Case Constant_expression P43 statement{} // labeled_stmt is skipped
			|Default P43 statement {} // labeled_stmt is skipped
			;
block_item_list_opt	:
			block_item_list   {  $$.NL=$1.NL; if($$.NL) backpatch($$.NL,nextinstr()+PC); 
						  		}     //$$=$1;
			| 		{ $$.NL=NULL;}
			;
compound_statement:
	 		P26 block_item_list_opt P27 {  $$=$2; }
	 		;
block_item_list:
		block_item	 {  $$=$1; }
		|block_item_list M block_item	{backpatch($1.NL,$2+PC); $$.NL=$3.NL; } 
						;
block_item:
		declaration  {}// declaration within a block is skipped
		|statement            {$$.NL=$1.NL; }//printf("executed\n\n\n\n\n\n\n"); }
		;
expression_opt	:
		expression			//$$=$1;
		| { $$.symptr=NULL;}						// skipped
		;
expression_statement:
		expression_opt P44 { 
			  if($1.boolex) {
			     $$.NL=merge($1.boolex->TL,$1.boolex->FL);
				} 
				 else{ $$.NL=NULL;} 
			}
		;
selection_statement:
		 If P24 expression P25 M statement 	
		{
			/*if(!$3.boolex)
			 $3=conv2Bool($3); 
			 backpatch($3.boolex->TL,PC+$5); 
			 $6.NL=merge<int>($3.boolex->FL,$6.NL); 
			 $$.NL=$6.NL; //printf("exited\n\n\n\n");
			*/if(!$3.boolex)
			 $3=conv2Bool($3); 
			 backpatch($3.boolex->TL,PC+$5); 
			 $6.NL=merge<int>($3.boolex->FL,$6.NL); 
			 $$.NL=$6.NL;
			/*\	
		        if(!$4.boolex)
			 $4=conv2Bool($4); 
			 backpatch($4.boolex->TL,PC+$6); 
			 $7.NL=merge<int>($4.boolex->FL,$7.NL); 
			 $$.NL=$7.NL; //printf("hid \n");*/
		}
	       |If P24 expression P25 M  statement N Else M statement
	  	{ 
 /*             if $3 == true then we need to goto before $6 ,
                hence M ( $5 ) is used to mark the location in the quad array before $6 is executed which will be used in backpatching
               else if $3 == false then we need to goto before $10 ,
               hence M ( $9 ) is used to mark the location in the quad array before $10 is executed which will be used in backpatching
               after statement $6 is executed then we need to emit a goto command so that we dont fall through
               hence N ($7) is placed after $6                                        
               */
			 backpatch($3.boolex->TL,PC+$5); 
			 backpatch($3.boolex->FL,PC+$9);
	  		 list_<int>* temp=merge<int>($6.NL,$7.NL); 
			 $$.NL=merge<int>(temp,$10.NL); 
		}
		|Switch P24 expression P25 statement {}		// switch is skipped
		;
iteration_statement:
		While N M P24  expression P25 M statement
		{       
			if(!$5.boolex) {
			backpatch($2.NL,PC+nextinstr());
			$5=conv2Bool($5);
			}
			else 
			backpatch($2.NL,PC+$3);
			backpatch($8.NL,PC+$3);			 
			backpatch($5.boolex->TL,PC+$7); 
			$8.NL=$5.boolex->FL; 
			char *buffer=new char[30]; 
			sprintf(buffer,"%d",PC+$3);qarr.emit(GOTO,buffer);
			$$.NL=$8.NL;
		}
		|Do M statement M While P24 expression P25 P44
		{ 
			if(!$7.boolex) {
			$7=conv2Bool($7);
			}
			backpatch($7.boolex->TL,PC+$2); 
			backpatch($3.NL,PC+$4); 
			$3.NL=$7.boolex->FL; 
			$$.NL=$3.NL;
		}
		/*|For P24 expression_opt P44 M expression_opt P44 M expression_opt N P25 M statement
		{
			if(!$6.boolex)	$6=conv2Bool($6);
 	                backpatch($6.boolex->TL,PC+$12);  
			backpatch($10.NL,PC+$5); 
			backpatch($13.NL,PC+$8);
		 	char *buffer=new char[30]; 
			sprintf(buffer,"%d",PC+$8); 
			qarr.emit(GOTO,buffer); 	
			$13.NL=$6.boolex->FL; 
			$$.NL=$13.NL;
		}*/
		|For P24 expression_opt P44 M N expression_opt P44 M expression_opt N P25 M statement
		{
			if(!$7.boolex)	
			{
				backpatch($6.NL,PC+nextinstr()+1);
				char *buffer=new char[30]; 
				sprintf(buffer,"%d",PC+$9); 
				qarr.emit(GOTO,buffer); 
				$7=conv2Bool($7);
				backpatch($7.boolex->TL,PC+$13);  
				backpatch($11.NL,PC+$5); 
				backpatch($14.NL,PC+$9);	
				$14.NL=$7.boolex->FL; 
				$$.NL=$14.NL;
			}
			else  
			{
				backpatch($6.NL,PC+$5+1); 
	 	                backpatch($7.boolex->TL,PC+$13);  
				backpatch($11.NL,PC+$5); 
				backpatch($14.NL,PC+$9);
			 	char *buffer=new char[30]; 
				sprintf(buffer,"%d",PC+$9); 
				qarr.emit(GOTO,buffer); 	
				$14.NL=$7.boolex->FL; 
				$$.NL=$14.NL;
			}
		}
	
		|For P24 declaration expression_opt P44 expression_opt P25 statement {}    // declaration within for is skipped
		;
jump_statement:
		 Goto identifier P44	{ }		// goto is skipped
		|Continue P44	{ }					// continue is skipped
		|Break P44 { }							// break is skipped
		|Return expression_opt P44 { 
				
					if($2.symptr) qarr.emit(RETURN,$2.symptr->name);  
					else qarr.emit(RETURN);
					$$.NL=NULL; }  
		;

/*******************************************External definitions **********************************************/
translation_unit:
		 External_declaration {}
		|translation_unit External_declaration	{ } //to be skipped
		;
External_declaration:
		function_definition {}
		|declaration	 {}     
		;
function_definition:
		//declaration_specifiers declarator declaration_list compound_statement {}		// to be skipped  
		declaration_specifiers declarator compound_statement 
                    {  
                         //printf("\ndddddddddfffffddddddddn\n\n");
			ST_funt=&ST_gl;
			ST_funt->update(new Type_Data($1.type),$2); 
                        if(!$2->stptr) $2->stptr=new symtable; 
		        SYMT_ROW* l=$2->stptr->lookup("retval");
                        $2->stptr->update(new Type_Data($1.type),l); 	
			//backpatch($3.NL,PC+$4);                           
		   }
		;
/*declaration_list: //skipped
		declaration  {}
		|declaration_list declaration {}
		;*/
%%
void yyerror(char *s) {
  printf("%s at line no.:%d\n",s,no_lines);
}

