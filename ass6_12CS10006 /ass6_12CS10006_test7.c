/*************************       Compilers Laboratory Assignment 6             ****************************/
/************************      Written by:Ankit Kumar Gupta (12CS10006)        ***************************/
/************************          Target Code Generation                **************************/    

/***********************       Test file to test Target Code Generation  *************************/
/***********************       this test file tests quick sort algorithm using Recursion *********************/   


int prints(char *c);
int printi(int p);
int readi(int *eP);   // *eP is for error, if the input is not an integer

int a;
int i_main;
int c;
int *ptr;
int size;
int arr[10];



int tmp1_swap;
int tmp2_swap;

void swap(int i,int j);
void quickSort(int l, int r);
int partition (int l, int h);

void swap(int i,int j)
{
tmp1_swap=arr[i];
tmp2_swap=arr[j];
arr[i]=tmp2_swap;
arr[j]=tmp1_swap;
return;
}

int x;
int i_par;
int j_par;
int tmp1_par;

int partition (int l, int h)
{
     x = arr[h];
     i_par = l-1;
 
    for (j_par = l; j_par <= h-1; j_par++)
    {   
        tmp1_par=arr[j_par];
        if ( tmp1_par<= x)
        {
            i_par++;
            swap (i_par,j_par);
        }
    }
    swap (i_par+1,h);
    //i_par++;
    return i_par+1;
}

int j_qsort;

void quickSort( int l, int r)
{
   

   if( l < r ) 
  {
    // divide and conquer
      j_qsort = partition(l, r);
       quickSort(l, j_qsort-1);
       quickSort(j_qsort+1, r);
   }
  return;
}


int par;
int main() 
{
   

   prints("Testing started \n");
  ptr=&c;
  prints("Enter No. of Elements\t");
  size=readi(ptr);
  for(i_main=0;i_main<size;i_main++)
  {
    prints("Please Enter a integer ");
    a=readi(ptr);
    arr[i_main]=a;
  }
    par=partition(0,size-1);
    printi(par);


    quickSort(0,size-1);
    
    prints("The Elements in sorted order are :\n");
      
  for(i_main=0;i_main<size;i_main++)
  {
    a=arr[i_main];
    printi(a);
    prints("\n");
  }

  prints("Testing ended \n");
  return 0;

}







