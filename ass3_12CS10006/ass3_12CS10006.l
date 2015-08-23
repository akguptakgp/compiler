%{
#include"y.tab.h"
%}

keyword1 "switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"|"_Bool"|"_Complex"|"_Imaginary"|"struct"
keyword2 "auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"
keyword3 "for"|"goto"|"if"|"inline"|"int"|"long"|"register"|"restrict"|"return"|"short"|"signed"|"sizeof"|"static"

keyword {keyword1}|{keyword2}|{keyword3}

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
comment {single_comment}|{multi_comment}

%%
{keyword}  { fprintf(yyout,"<keyword,%s>\n",yytext); return keyword;}
{identifier} { fprintf(yyout,"<identifier,%s>\n",yytext);return identifier;}
{int_const} {fprintf(yyout,"<int_const,%s>\n",yytext);return int_const;}
{floating-const} {fprintf(yyout,"<floating-const,%s>\n",yytext);return floating_const ;}
{character-constant} {fprintf(yyout,"<character-constant,%s>\n",yytext);return character_constant;}
{string-literal} {fprintf(yyout,"<string-literal,%s>\n",yytext);return string_literal;}
{punctuator} {fprintf(yyout,"<punctuator,'%s'>\n",yytext);return punctuator;}
{comment} {}
[\n\t' ']  {}
 <<EOF>>  {return EOF;yyterminate();}
%%

