/*************************       Compilers Laboratory Assignment 6             ****************************/
/************************      Written by:Ankit Kumar Gupta (12CS10006)        ***************************/
/************************          Target Code Generation                **************************/    

/***********************       Test file to test Target Code Generation  *************************/
/***********************       this test file focus on testing expressions    ************************/   


int a;
int b;
int *ptra;
int a1,a2;
int d1,d2=4;
char c;
int call_;
int arr1[10],arr2[10][10],arr3[30][30][30];
int add1(int a,int b){ return a+b;}
int prints(char *c);
int printi(int p);
int readi(int *eP);   // *eP is for error, if the input is not an integer
int main()
{
	prints("Testing started \na=");
	 a=4;
	printi(a);
	prints("\na=");
	c='f';
	a1=a;
	a=5+3*a1+a;
	printi(a);
	prints("\n");
	d1=a;
	prints("\nd1=");
 	printi(d1);
	prints("\n");
	d2=d1*a+d2;
	prints("\nd2=");
 	printi(d2);
	prints("\n");
 	d1=d1/2*d2;
 	prints("\nd1=");
 	printi(d1);
	prints("\n");
 	d2++;
 	prints("\nd2=");
 	printi(d2);
	prints("\n");
 	a1++;
 	prints("\na1=");
 	printi(a1);
	prints("\n");
    --a;
    prints("\na=");
 	printi(a);
	prints("\n");
    ++a;
    prints("\na=");
 	printi(a);
	prints("\n");
 	call_=add1(a,b);
 	prints("\ncall_=");
 	printi(call_);
	prints("\n");	
    ptra=&d1;
    a=*ptra;
    prints("\na=");
 	printi(a);
	prints("\n");
	*ptra=d2;
	prints("\nd1=");
 	printi(d1);
	prints("\n");

	// expression involving Arrays
 	arr1[3]=4;
 	prints("\narr1[3]=");
 	a=arr1[3];
 	printi(a);
	prints("\n");
	arr3[1][2][2]=5;
	a1=arr3[1][2][2];
	prints("\narr3[1][2][2]=");
 	printi(a1);
	prints("\n");

	 d1=d1/d2+d1%d2;
	 a=2>5;
	 d=4>3;
	 prints("\nd1=");
 	printi(d1);
	prints("\n");
	prints("\na=");
 	printi(a);
	prints("\n");
	prints("\nd=");
 	printi(d);
	prints("\n");
	 a=a1^a2;
	 prints("\na=");
 	printi(a);
	prints("\n");
	 a1=(3>a)?a1:a;
	 prints("\na1=");
 	printi(a1);
	prints("\n");
	 d1=add1(a1,a2);
	  prints("\nd1=");
 	printi(d1);
	prints("\n");
	 prints("Testing ended \n");	
	
	 return 0;
}
