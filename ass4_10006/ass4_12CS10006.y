%{ /* C Declarations and Definitions */
 #include <string.h>
 #include "y.tab.h"
 extern int yylex();
 void yyerror(char *s);
 extern int no_lines;
%}


%union {
 int intval;
 float floatval;
 char *stringval;
 }


%token <intval> Auto
%token <intval> Break
%token <intval> Case
%token <intval> Char
%token <intval> Const
%token <intval> Continue
%token <intval> Default
%token <intval> Do
%token <intval> Double
%token <intval> Else
%token <intval> Enum
%token <intval> Extern
%token <intval> Float
%token <intval> For
%token <intval> Goto
%token <intval> If
%token <intval> Inline
%token <intval> Int
%token <intval> Long
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
%token <intval> Void
%token <intval> Volatile
%token <intval> While
%token <intval> Bool
%token <intval> Complex
%token <intval> Imaginary

%token <intval> identifier
%token <intval> Int_Constant  
%token <intval> Floating_Const
%token <intval> Enumeration_Constant    
%token <intval> Character_Constant
%token <intval> string_literal  

%token <intval> P1
%token <intval> P2
%token <intval> P3
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
%token <intval> P23
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

 
 
%type<intval> primary_expression
%type<intval> postfix_expression
%type<intval> argument_expression_list
%type<intval> unary_expression  
%type<intval> unary_operator
%type<intval> cast_expression
%type<intval> multiplicative_expression
%type<intval> additive_expression
%type<intval> relational_expression
%type<intval> equality_expression
%type<intval> AND_expression
%type<intval> exclusive_OR_expression 
%type<intval> inclusive_OR_expression
%type<intval> logical_AND_expression
%type<intval> logical_OR_expression
%type<intval> conditional_expression
%type<intval> assignment_expression
%type<intval> assignment_operator
%type<intval> expression
%type<intval> Constant_expression   
%type<intval> declaration
%type<intval> declaration_specifiers
%type<intval> init_declarator_list
%type<intval> init_declarator
%type<intval> type_specifier
%type<intval> specifier_qualifier_list
%type<intval> Enum_specifier   
%type<intval> Enumerator_list
%type<intval> Enumerator
%type<intval> type_qualifier
%type<intval> function_specifier
%type<intval> declarator
%type<intval> direct_declarator
%type<intval> pointer
%type<intval> type_qualifier_list
%type<intval> parameter_type_list
%type<intval> parameter_list  
%type<intval> parameter_declaration
%type<intval> identifier_list
%type<intval> type_name
%type<intval> initializer   
%type<intval> initializer_list
%type<intval> designation
%type<intval> designator_list 
%type<intval> designator
%type<intval> statement
%type<intval> labeled_statement
%type<intval> compound_statement
%type<intval> block_item_list
%type<intval> block_item
%type<intval> expression_statement
%type<intval> selection_statement
%type<intval> iteration_statement
%type<intval> jump_statement
%type<intval> External_declaration
%type<intval> function_definition
%type<intval> declaration_list
%type<intval> Constant
%type<intval> shift_expression
%type<intval> storage_class_specifier
%expect 1

%start translation_unit
  
%%

primary_expression:
			identifier
		   |Constant
		   |string_literal
		   |P24 expression P25
		   ;

postfix_expression	:
			primary_expression
			|postfix_expression P22 expression P23  
			|postfix_expression P24 argument_expression_list P25
			|postfix_expression P24 P25
			|postfix_expression P28   identifier
			|postfix_expression P29 identifier
			|postfix_expression P30 
			|postfix_expression P31 
			|P24 type_name P25 P26 initializer_list P27 
			|P24 type_name P25 P26 initializer_list P46 P27 
			;

argument_expression_list	:
				assignment_expression
				|argument_expression_list P46 assignment_expression
				;

			
unary_expression	:
			postfix_expression
			|P30 unary_expression
			|P31 unary_expression
			|unary_operator cast_expression
			|Sizeof unary_expression
			|Sizeof P24 type_name P25
			;

unary_operator  :  P16 |P17  |P18  |P19  |P20  |P21 
				;

cast_expression		:
			unary_expression
			|P24 type_name P25 cast_expression
			;

multiplicative_expression   :
		         cast_expression
			    |multiplicative_expression P17 cast_expression
			    |multiplicative_expression P32 cast_expression
                |multiplicative_expression P33 cast_expression
                ;

additive_expression	 :
			 multiplicative_expression
			 |additive_expression P18 multiplicative_expression
			 |additive_expression P19 multiplicative_expression
			 ;
shift_expression	:
			additive_expression
			|shift_expression P34 additive_expression
			|shift_expression P35 additive_expression
			;
relational_expression  :
			shift_expression
			|relational_expression P36 shift_expression
			|relational_expression P37 shift_expression
			|relational_expression P1 shift_expression
			|relational_expression P2 shift_expression
			;
equality_expression :
			relational_expression
			|equality_expression P3 relational_expression
			|equality_expression P4 relational_expression
			;
AND_expression :
			equality_expression
			|AND_expression P16 equality_expression
			;
exclusive_OR_expression :
			   AND_expression
			  |exclusive_OR_expression P38 AND_expression
			  ;
inclusive_OR_expression: 
				exclusive_OR_expression
				|inclusive_OR_expression P39 exclusive_OR_expression
				;
logical_AND_expression :
					 inclusive_OR_expression
					 |logical_AND_expression P40 inclusive_OR_expression
					;
logical_OR_expression : 
					logical_AND_expression
					|logical_OR_expression P41 logical_AND_expression
					;
conditional_expression  : 
						logical_OR_expression
						|logical_OR_expression P42 expression P43 conditional_expression
						;

assignment_expression  : 
		        conditional_expression
		        |unary_expression assignment_operator assignment_expression
		        ;
assignment_operator   :  P5  |  P6  |  P7  |  P8  |  P9  | P10  |  P11 |  P12 |   P13 |  P14 |  P15
					  ;

expression:
			 assignment_expression
            |expression P46 assignment_expression 
            ;
Constant_expression  : conditional_expression
					;

Constant:
			Int_Constant  
            |Floating_Const
	        |Enumeration_Constant  
 		   	|Character_Constant
 		   	;
			

declaration:	
		declaration_specifiers init_declarator_list P44
		|declaration_specifiers P44
		;
declaration_specifiers:
		storage_class_specifier declaration_specifiers
		|storage_class_specifier 
		|type_specifier declaration_specifiers
		|type_specifier 
		|type_qualifier declaration_specifiers
		|type_qualifier 
		|function_specifier declaration_specifiers
		|function_specifier
		;

init_declarator_list:
			init_declarator
			|init_declarator_list P46 init_declarator
			;
init_declarator:
			declarator
			|declarator P5 initializer
			;
storage_class_specifier:
			Extern
			|Static
			|Auto
			|Register
			;
type_specifier:
			Void
			|Char
			|Short
			|Int
			|Long
			|Float
			|Double
			|Signed
			|Unsigned
			|Bool
			|Complex
			|Imaginary
			|Enum_specifier
			;
specifier_qualifier_list:
			type_specifier specifier_qualifier_list
			|type_specifier 
			|type_qualifier specifier_qualifier_list
			|type_qualifier
			;
Enum_specifier:
	     Enum identifier P26 Enumerator_list P27
	     | Enum  P26 Enumerator_list P27
		|Enum identifier P26 Enumerator_list P46 P27
		|Enum  P26 Enumerator_list P46 P27
	    |Enum identifier
		;
Enumerator_list:
		Enumerator
		|Enumerator_list P46 Enumerator
		;
Enumerator:
		Enumeration_Constant
		|Enumeration_Constant P5 Constant_expression
		;
type_qualifier:
		Const
		|Restrict
		|Volatile
		;
function_specifier: 
		Inline
		;
declarator:
		pointer direct_declarator
		|direct_declarator
		;
direct_declarator:
		identifier
		|P24 declarator P25
		|direct_declarator P22 type_qualifier_list assignment_expression P23
		|direct_declarator P22 type_qualifier_list P23
		|direct_declarator P22  assignment_expression P23
		|direct_declarator P22  P23
		|direct_declarator P22 Static type_qualifier_list assignment_expression P23
		|direct_declarator P22 Static assignment_expression P23
		|direct_declarator P22 type_qualifier_list Static assignment_expression P23
		|direct_declarator P22 type_qualifier_list P17 P23
		|direct_declarator P22 P17 P23
		|direct_declarator P24 parameter_type_list P25
		|direct_declarator P24 identifier_list P25
		|direct_declarator P24 P25
		;
pointer:
		P17 type_qualifier_list
		|P17 
		|P17 type_qualifier_list pointer
		|P17  pointer
		;
type_qualifier_list:
		type_qualifier
		|type_qualifier_list type_qualifier
		;
parameter_type_list:
		parameter_list
		|parameter_list P46 P45
		;
parameter_list:
		parameter_declaration
		|parameter_list P46 parameter_declaration
		;
parameter_declaration:
		declaration_specifiers declarator
		|declaration_specifiers
		;
identifier_list:
		identifier
		|identifier_list P46 identifier
		;
type_name:
		specifier_qualifier_list
		;
initializer:
		assignment_expression
		|P26  initializer_list  P27 
		|P26  initializer_list P46  P27 
		;
initializer_list:
		designation initializer
		| initializer
		|initializer_list P46 initializer
		|initializer_list P46 designation initializer
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
statement:
		labeled_statement
		|compound_statement
		|expression_statement
		|selection_statement
		|iteration_statement
		|jump_statement
		;
labeled_statement:
			identifier P43 statement
			|Case Constant_expression P43 statement 
			|Default P43 statement
			;
compound_statement:
	 		P26 block_item_list P27 
	 		|P26 P27 
	 		;
block_item_list:
		block_item
		|block_item_list block_item
		;
block_item:
		declaration
		|statement
		;
expression_statement:
		expression P44
		| P44
		;
selection_statement:
		If P24  expression P25 statement
		|If P24  expression P25 statement Else statement
		|Switch P24 expression P25 statement
		;
iteration_statement:
		While  P24  expression P25 statement
		|Do statement While P24 expression P25 P44
		|For P24 expression P44 expression P44 expression P25 statement
		|For P24 expression P44 expression P44  P25 statement
		|For P24 expression P44  P44 expression P25 statement
		|For P24 expression P44  P44  P25 statement
		|For P24 P44 expression P44 expression P25 statement
		|For P24  P44 expression P44  P25 statement
		|For P24  P44  P44 expression P25 statement
		|For P24  P44  P44  P25 statement
		|For P24 declaration expression P44 expression P25 statement
		|For P24 declaration expression P44 P25 statement
		|For P24 declaration P44 expression P25 statement
		|For P24 declaration  P44 P25 statement
		;
jump_statement:
		Goto identifier P44
		|Continue P44
		|Break P44
		|Return expression P44
	    |Return  P44	
		;
translation_unit:
		External_declaration
		|translation_unit External_declaration	
		;
External_declaration:
		function_definition
		|declaration
		;
function_definition:
		declaration_specifiers declarator declaration_list compound_statement
		|declaration_specifiers declarator  compound_statement
		;
declaration_list:
		declaration
		|declaration_list declaration
		;
%%
void yyerror(char *s) {
  printf("%s at line no.:%d\n",s,no_lines);
}

