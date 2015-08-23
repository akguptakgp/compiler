%{
#include"y.tab.h"
int no_lines=1;
static void comment();
%}

nondigit [a-zA-Z]
nz_digit [1-9]
digit [0-9]

identifier {nondigit}({nondigit}|{digit})*

int_const {digit}|({nz_digit}{digit}*)

escape-sequence [\']|[\"]|[\?]|[\\]|[\a]|[\b]|[\f]|[\n]|[\r]|[\t]|[\v]

cescape-sequence [\"]|[\?]|[\\]|[\a]|[\b]|[\f]|[\n]|[\r]|[\t]|[\v]  
c-char      escape-sequence|[^\'\\\n]  
c-char-sequence   {c-char}+
character-constant \'{c-char-sequence}\'
enumeration-constant {identifier}
digit-sequence {digit}+
sign [+-]
exponent-part [eE]{sign}{digit-sequence}|[eE]{digit-sequence} 

fractional_const ({digit-sequence}\.{digit-sequence})|({digit-sequence}\.)|(\.{digit-sequence})

floating-const ({fractional_const})|({fractional_const}{exponent-part})|({digit-sequence}{exponent-part})

sescape-sequence [\']|[\?]|[\\]|[\a]|[\b]|[\f]|[\n]|[\r]|[\t]|[\v]              
s_char        {sescape-sequence}|[^\"\\\n]
s-char-sequence   {s_char}+
string-literal   [\"][\"]|([\"]{s-char-sequence}[\"])


punctuator1  "["|"+"|"/"|"?"|"="|","|"]"|"("|"{"|"}"|"."|">"|"*"|"+"|"-"|"~"|"!"|"--"
punctuator2  "%"|"<<"|">>"|"<"|">"|"<="|">="|":"|";"|"..."|"*="|"="|"="|"+="|"="|"<<="
punctuator3  ")"|"&"|"=="|">>="|"="|"&="|"^"|"|"|"^="|"&&"|"||"|"|="|"#"
punctuator {punctuator1}|{punctuator2}|{punctuator3}

single_comment "//".*[\n]
multi_comment  "/*"([^*]|\*+[^*/])*\*+"/"


%%

"/*"            { comment(); }
[\n] 		{ no_lines++; } 
"auto"  	{ fprintf(yyout,"<keyword,%s>\n",yytext); return Auto; }
"break"  	{ fprintf(yyout,"<keyword,%s>\n",yytext); return Break; }
"case"  	{ fprintf(yyout,"<keyword,%s>\n",yytext); return Case; }
"char" 		{ fprintf(yyout,"<keyword,%s>\n",yytext); return Char; }
"const"  	{ fprintf(yyout,"<keyword,%s>\n",yytext); return Const; }
"continue" 	{ fprintf(yyout,"<keyword,%s>\n",yytext); return Continue; }
"default"  	{ fprintf(yyout,"<keyword,%s>\n",yytext); return Default; }
"do"  		{ fprintf(yyout,"<keyword,%s>\n",yytext); return Do; }
"double"  	{ fprintf(yyout,"<keyword,%s>\n",yytext); return Double; }
"else"  	{ fprintf(yyout,"<keyword,%s>\n",yytext); return Else; }
"enum"  	{ fprintf(yyout,"<keyword,%s>\n",yytext); return Enum; }
"extern"  	{ fprintf(yyout,"<keyword,%s>\n",yytext); return Extern; }
"float"	  	{ fprintf(yyout,"<keyword,%s>\n",yytext); return Float; }
"for"  		{ fprintf(yyout,"<keyword,%s>\n",yytext); return For; }
"goto"  	{ fprintf(yyout,"<keyword,%s>\n",yytext); return Goto; }
"if"  		{ fprintf(yyout,"<keyword,%s>\n",yytext); return If; }
"inline"	{ fprintf(yyout,"<keyword,%s>\n",yytext); return Inline; }
"int"  		{ fprintf(yyout,"<keyword,%s>\n",yytext); return Int; }
"long"  	{ fprintf(yyout,"<keyword,%s>\n",yytext); return Long; }
"register"      { fprintf(yyout,"<keyword,%s>\n",yytext); return Register; }
"restrict"	{ fprintf(yyout,"<keyword,%s>\n",yytext); return Restrict; }
"return"  	{ fprintf(yyout,"<keyword,%s>\n",yytext); return Return; }
"short"  	{ fprintf(yyout,"<keyword,%s>\n",yytext); return Short; }
"signed"  	{ fprintf(yyout,"<keyword,%s>\n",yytext); return Signed; }
"sizeof"  	{ fprintf(yyout,"<keyword,%s>\n",yytext); return Sizeof; }
"static"  	{ fprintf(yyout,"<keyword,%s>\n",yytext); return Static; }
"struct"  	{ fprintf(yyout,"<keyword,%s>\n",yytext); return Struct; }
"switch" 	{ fprintf(yyout,"<keyword,%s>\n",yytext); return Switch; }
"typedef" 	{ fprintf(yyout,"<keyword,%s>\n",yytext); return Typedef; }
"union" 	{ fprintf(yyout,"<keyword,%s>\n",yytext); return Union; }
"unsigned"      { fprintf(yyout,"<keyword,%s>\n",yytext); return Unsigned; }
"void"  	{ fprintf(yyout,"<keyword,%s>\n",yytext); return Void; }
"volatile"      { fprintf(yyout,"<keyword,%s>\n",yytext); return Volatile; }
"while"  	{ fprintf(yyout,"<keyword,%s>\n",yytext); return While; }
"_Bool"  	{ fprintf(yyout,"<keyword,%s>\n",yytext); return Bool; }
"_Complex"      { fprintf(yyout,"<keyword,%s>\n",yytext); return Complex; }
"_Imaginary"    { fprintf(yyout,"<keyword,%s>\n",yytext); return Imaginary; }

{identifier} { fprintf(yyout,"<identifier,%s>\n",yytext);return identifier;}
{int_const} {fprintf(yyout,"<int_const,%s>\n",yytext);return Int_Constant  ;}
{floating-const} {fprintf(yyout,"<floating-const,%s>\n",yytext);return Floating_Const;}
{character-constant} {fprintf(yyout,"<character-constant,%s>\n",yytext);return Character_Constant;}
{string-literal} {fprintf(yyout,"<string-literal,%s>\n",yytext);return string_literal ;}

"<="  { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P1; }
">="  { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P2; }
"=="  { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P3; }
"!="  { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P4; }
"="   { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P5; }
"*="  { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P6; }
"/="  { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P7; }
"%="  { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P8; }
"+="  { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P9; }
"-="  { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P10; }
"<<=" { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P11; }
">>=" { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P12; }
"&="  { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P13; }
"^="  { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P14; }
"|="  { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P15; }
"&"   { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P16; }
"*"   { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P17; }
"+"   { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P18; }
"-"   { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P19; }
"~"   { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P20; }
"!"   { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P21; }
"["   { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P22; }
"]"   { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P23; }
"("   { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P24; }
")"   { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P25; }
"{"   { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P26; }
"}"   { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P27; }
"."   { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P28; }
"->"  { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P29; }
"++"  { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P30; }
"--"  { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P31; }
"/"   { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P32; }
"%"   { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P33; }
"<<"  { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P34; }
">>"  { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P35; }
"<"   { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P36; }
">"   { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P37; }
"^"   { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P38; }
"|"   { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P39; }
"&&"  { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P40; }
"||"  { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P41; }
"?"   { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P42; }
":"   { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P43; }
";"   { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P44; }
"..." { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P45; }
","   { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P46; }
"#"   { fprintf(yyout,"<punctuator,'%s'>\n",yytext); return P47; }

{single_comment} { no_lines++;}
[\t' ']  {}

<<EOF>>  {return 0;}
%%


static void comment(void)
{
    int c;

    while ((c = input()) != 0){
         if(c == '\n') 
	  	no_lines++;
        if (c == '*')
        {
            while ((c = input()) == '*');
                 
            if (c == '/')
             {   return;}

            if (c == 0)
                break;
        }
}
    yyerror("unterminated comment");

}
