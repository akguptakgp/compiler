/*************************       Compilers Laboratory Assignment 6             ****************************/
/************************      Written by:Ankit Kumar Gupta (12CS10006)        ***************************/
/************************          Target Code Generation                **************************/    

/***********************       Test file to test Target Code Generation  *************************/
/***********************   this test file tests  Fibonacci Programm using Recursion  ************************/   

int n;
int b;
int c;
int printi(int p);
int prints(char *str);
int fib(int n);

int i;
int fib(int n)
{
	b=1;
if(n>=2){
	b=fib(n-1)+fib(n-2);
	}
return b;
}

void main()
{

prints("The first 10 Fib. Numbers are\n");
for(i=0;i<10;i++){
c=fib(i);
printi(c);
prints("\n");
}
return;
}

