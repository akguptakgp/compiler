/*************************       Compilers Laboratory Assignment 6             ****************************/
/************************      Written by:Ankit Kumar Gupta (12CS10006)        ***************************/
/************************          Target Code Generation                **************************/    

/***********************       Test file to test Target Code Generation  *************************/
/***********************       this test file tests bubble sort algorithm    ************************/   

int a;
int b;
int c;
int *ptr;
char *str1;
char *str2="Still Testing\n";

int prints(char *c);
int printi(int p);
int readi(int *eP);   // *eP is for error, if the input is not an integer


int arr[100];
int i;
int j;

int size;
int swap;
int swap2;
int _j;
int _j1;

void sort()
{
	 for(i=0;i<size-1;i++)
  {
    for (j=0;j<size-i-1;j++)
    {
      _j=arr[j];
      _j1=arr[j+1];
      if ( _j> _j1) // /* For decreasing order use < 
      {
        arr[j]=_j1;
        arr[j+1]=_j;
      }
    }
  }
  

	
  return;
}

int main()
{
 
	prints("Testing started \n");
	ptr=&c;
	prints("Enter No. of Elements\t");
	size=readi(ptr);
	for(i=0;i<size;i++)
	{
		prints("Please Enter a integer ");
		a=readi(ptr);
		arr[i]=a;
	}
    
    sort();
    
    prints("The Elements in sorted order are :\n");
    	
	for(i=0;i<size;i++)
	{
		a=arr[i];
 		printi(a);
 		prints("\n");
	}

	prints("Testing ended \n");
	return 0;
}
