%{ /* C Declarations and Definitions */
#include <string.h>
 extern int yylex();
 void yyerror(char *s);
%}
%union {
 int intval;
 float floatval;
 char *stringval;
       }
 %token <intval> keyword
 %token <intval> identifier
  %token <intval> int_const  
 %token <intval> floating_const
 %token <intval> enumeration_constant  
  %token <intval> character_constant
  %token <intval> string_literal  
  %token <intval> punctuator   
     
%type <intval> expression

%%
 expression: {printf("YACC");}

%%

void yyerror(char *s) {
  printf("%s\n",s);
}

