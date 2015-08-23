/*************************       Compilers Laboratory Assignment 6             ****************************/
/************************      Written by:Ankit Kumar Gupta (12CS10006)        ***************************/
/************************          Target Code Generation                **************************/    

/***********************       Test file to test Target Code Generation  *************************/
/***********************       this test file focus on testing statements    ************************/   

int a;
int c;
int x;
int i;
int s=3;

int prints(char *c);
int printi(int p);
int readi(int *eP);   // *eP is for error, if the input is not an integer

int main()
{
	prints("Testing started \na=");
	x=3;
	i=4;
	if(i>3) c=3;
	if(i<=0) c=x;
	else c=x;
	prints("\nc=");
 	printi(c);
	prints("\n");

// simple loops
	while(i<10)
	{
		a=c+a;
		i++;
	}
	prints("\na=");
 	printi(a);
	prints("\n");
	prints("\ni=");
 	printi(i);
	prints("\n");

	for(i=0;i>0;i++)
	{
		c=a+s*3;
	}
	prints("\nc=");
 	printi(c);
	prints("\n");
	prints("\ni=");
 	printi(i);
	prints("\n");
	a=0;
	do{
		a++;
	}while(a<10);

// int to booleans 
	i=20;
	while(i)
	{
		a=c+a;
		i--	;
	}
   
	for(i=1;i;i--)
	{
    	prints("\nit worked fine\n");
	}
	prints("\ni=");
 	printi(i);
	prints("\n");
	a=-1;
	do{
		prints("\nit also worked fine\n");
		a++;
	}while(a);
	prints("Testing ended \n");	
	
	return 0;
}
