/*************************       Compilers Laboratory Assignment 5             ****************************/
/************************      Written by:Ankit Kumar Gupta (12CS10006)        ***************************/
/************************          Intermediate Code Generation                **************************/    

/***********************       Test file to test Intermediate Code Generation  *************************/
/***********************       this test file focus on testing expressions    ************************/   


int a;
int *ptra;
int a1,a2;
double d1,d2=4.8;
char c;
int arr1[2],arr2[3][4],arr3[3][3][3];
int add1(int a,int b);
int main(int a,double d)
{
 a=4;
 d=2.5;
 c='f';
 a=5+3*a1+a;
 d1=d1/2.3*d2;
 d2++;
 a1++;
 a1=a1<<4;
 a2=a2>>3;
 --a;
 ++a;
 c=add1(a,b);
 a=d;
 //a=&a1;
 //a=*ptra;
 //*ptra=a; 
 a=arr1[3];
 a1=arr2[2][1];
 a2=arr3[0][1][2];
 arr2[2][1]=arr3[1][2][2];
 d1=d1/d2+d1%d2;
 a=2>5;
 d=4<3;
 a=a1^a2;
 a1=(3>a)?a1:a;

 d1=add1(a1,a2);
}
