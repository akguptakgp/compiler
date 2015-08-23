/*************************       Compilers Laboratory Assignment 6             ****************************/
/************************      Written by:Ankit Kumar Gupta (12CS10006)        ***************************/
/************************          Target Code Generation                **************************/    

/***********************       Test file to test Target Code Generation  *************************/
/***********************       this test file focus on testing declarations    ************************/   


// simple variables
int a1;
char b1;

// simple variables with initilization and with declaration in chain
int a2=34,b2=455;
char c2,d2='f';

// pointers declaration with some initilized 
void  *a3,*b3;
int  *c3=0,*d3;
char * g3,h3;
char *str="just_a_test";

// array declaration
int arr[4]; // 1 D array
int arr2[3][5][5];


// function declarations
int add1();
void add2();
char add2();


int add3(int* a,int b,int c);
void add4(int a,int* b,int su);
int add5(int a,char* b);


int* test6();
void* test5();
char* test4();


int* test3(int a,int b,int c);
void* test2(int a,int* b,int su);
int* test1(int a,char b);

void func(int i, int d);
int prints(char *c);
int printi(int p);
int readi(int *eP);   // *eP is for error, if the input is not an integer
int main()
{
   prints("Testing started \n");
   prints("Nothing to do existing \n");
   prints("Testing ended \n");

   return 0;
}
