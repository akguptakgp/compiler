/*************************       Compilers Laboratory Assignment 6             ****************************/
/************************      Written by:Ankit Kumar Gupta (12CS10006)        ***************************/
/************************          Target Code Generation                **************************/    

/***********************       Test file to test Target Code Generation  *************************/
/***********************       this test file focus on Reading from stdin    ************************/   




int a;
int b;
int c;
int *ptr;
char *str1;
char *str2="Still Testing\n";

int prints(char *c);
int printi(int p);
int readi(int *eP);   // *eP is for error, if the input is not an integer

int add(int p1,int p2)
{
	return p1+p2;
}

int main()
{
	prints("Testing started \n");
	ptr=&c;
	prints("Please Enter a integer\n");
	a=readi(ptr);
	prints("entered integer is=");
 	printi(a);
	prints("\n");
	prints(str2);
	prints("Please Enter another integer\n");
	b=readi(ptr);
	prints("entered integer is=");
 	printi(b);
	prints("\n");
	prints("sum is=");
	c=add(a,b);
 	printi(c);
	prints("\n");
	prints("Testing ended \n");
	return 0;
}
