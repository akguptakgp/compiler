#include<stdio.h>
extern FILE* yyin;
extern FILE* yyout;
extern int yyparse();
int main(int argc,char *argv[])
{
 
 yyin=fopen("ass3_12CS10006_test.c","r");
 yyout=fopen("ass3_12CS10006_result.c","w");
int rtn;
 do
{
  rtn=yylex();
 }while(rtn!=EOF);
  fclose(yyin);
  fclose(yyout);
return 0;
}
