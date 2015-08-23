/*************************       Compilers Laboratory Assignment 5             ****************************/
/************************      Written by:Ankit Kumar Gupta (12CS10006)        ***************************/
/************************          Intermediate Code Generation                **************************/    

/***********************       Test file to test Intermediate Code Generation  *************************/
/***********************       this test file focus on testing type checking    ************************/   


// simple variables
int a1;
char b1;
double c1;

// simple variables with initilization and with declaration in chain
int a2=34,b2=455;
char c2,d2='f';
double e2=0.98,f2=9.648;

// array declaration
int arr[4]; // 1 D array
double arr1[4][5];
int arr2[3][5][5];

int main(){

a1=3.4;          // interger assigned double
c1=4;		//  double  assigned interger
a1=c1+3.4*e2;   // double expression assigned integer
c1=a1+3+4*a2;   // integer expression assigned double
a=3>4 ;        // boolean assigned integer

a1=c1+3*e2;   // double expression containg interger and then assigned integer


while(a1)         // integer to boolean coversion
{
a1--;
++b1;
}

for(i;i<0;i++)
{
 e2=a1+3.4;
}
}



