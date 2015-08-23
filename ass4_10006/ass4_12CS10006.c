#include<stdio.h>
extern FILE* yyin;
extern FILE* yyout;
extern int yylex();
int main(int argc,char *argv[])
{
 
 yyin=fopen("ass4_12CS10006_test.c","r");
 yyout=fopen("ass4_12CS10006_result.c","w");
int rtn;
rtn=yyparse();
if(rtn==0) printf("Parsed Successfully..\n");
  fclose(yyin);
  fclose(yyout);
return 0;
}
