/*************************       Compilers Laboratory Assignment 5             ****************************/
/************************      Written by:Ankit Kumar Gupta (12CS10006)        ***************************/
/************************          Intermediate Code Generation                **************************/    

/***********************       Test file to test Intermediate Code Generation  *************************/
/***********************       this test file focus on testing declarations    ************************/   


// simple variables
int a1;
char b1;
double c1;

// simple variables with initilization and with declaration in chain
int a2=34,b2=455;
char c2,d2='f';
double e2=0.98,f2=9.648;

// pointers declaration with some initilized 
void  *a3,*b3;
int  *c3=0,*d3;
double* e3,f3=0; 
char * g3=0,h3=0;
char *str="just_a_test";

// array declaration
int arr[4]; // 1 D array
double arr1[4][5];
int arr2[3][5][5];


// function declarations
int add1();
void add2();
char add2();


int add3(int* a,int b,int c);
void add4(int a,double* b,int su);
int add5(double a,char* b);


int* test6();
void* test5();
char* test4();


int* test3(int a,int b,int c);
void* test2(int a,double* b,int su);
int* test1(double a,char b);

void func(int i, double d);

/*
int add(int arr);

int brr[3][6];
int a;
double d;
//char c;
int* add(int a,int d){
d=d*a;
a=a/d;
a=d-a;
d=a+d;
a=a>d;
}

int a;
int *p;
int i;
int c;
double d;
int fn(){
    a=5;
   a=d;
if(i>0) {c=3;}
else {d=23;}
for(i=0;i;i++)   
a=*p;
*p=a;
do
{
 a=3;
 c++;
 }while(i>0); 

return 3;
     
}
/*
int a,b,c;
int cond()
{
if(a) s=3;
c=a>b?0:5;
}

int a[3][3][4];
int c;
int add(){
c=a[1][0][0];

}
/*int a[3];
int b;

int add()
{
if(a>3) l=2;
else c=a>0?c:0;
a[3]=a[4];
while(a>5){
a++;
}
do{
b++;
}while(4>5);
for(i;i>0;i++)
{
c=c++;
}

return ;
}

//b=a?7:n
/*int a[4];
int add(int a){
b=a[3];
}*/
/*double d = 2.3;
int i, w[10];
int a = 4, *p, b;
void func(int i, double d);
char c;*/

/*
int a;
int b;
int d;
int asd(int c)
{
a++;
if(c==0) d=3;
if(a>b) c=3;
else c=3;
//while(a>0) 
b=c;
/*for(i=0;i>0;i++)
  {
 d=a+b;
 //c=add(3,5);
}  //printf("24",3);
//}*/
/*do{
a=b+c;
}while(4>5);
//a++;
return 10;
}*/

//int a1[3][5][5];
/*
int a[4];

int c;
/*int add()
{
c=a1[1][2][1];
a1[1][2][1]=7;
a1[1][2][1]=a[3];
}*/
/*
int a;
int b;
int add2(int a,int b);
int add(int a)
{
b=7;
b++;
a=--b;
//add2(a,b);
}*/
/*



// this is skipped

int* add5();
char* add6();
double* add7();



/*
int b[5];
int* p;
int a=p;
int c=b[4];
int add();
/*{
//a=b[4];
//c=*p;
*p=c;
}
/*a=f*4
/*int fn();
int b=8,c[10];
double d,ff;
char d='a';
int w[10];
int a[5][4];
void func(int i);
void add(int i,char j);
int *p=5;

double d = 2.3;
int i, w[10];
int a = 4, *p, b;
void func(int i, double d);
char c;
int add(int s)
{ 
 a=e+4;
 }
/*/
/*
int add_(int i,int j){}
int add(int a){
//ankit=add_(g,h);
j=j*4+4;
h=4>>4;
/*(while(4>5)
{
if(4>7) l=3;
else
k=4;
//}
//}
/*while(4>6)
{
s=9;
}*/

//return 9;
//}
//k=4;//*/
//}

//(5<3)
/*
int a=7;
int c=(4+5)*(5/7)+6%10+a;
*/
/*int a,g[3][4];
int add(int a);*/
/*int f[4][5][10];
int b[4][5][5];
int add(int a)
{
/*a=5
c=4;
add(35,g);
*/
/*f[3][3][3]=b[1][2][5];
}
int *k=0,**j=8;
double*** l=9.7;
int a[4][5][4];
char c[3];
void* y;
char f;
//void* add(int om,int v,int b);
/*char* funt(int* p);
int** fuct2();

/*int add(int i,int a) 
{
k=a;
}*/
