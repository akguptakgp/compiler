/* Compliler Laboratory Assignment 3
   Test file to test scanner it scans input from this ass3_12CS10006_test.c 
 /*  // and it generates token stream in ass3_12CS10006_result.c 
 created by : Ankit Kumar Gupta
*/

//  function to test 
#include<stdio.h>

//this test file checks all the functionality that tiny C supports

void quicksort(int [10],int,int);  // a simple quick sort algorithm

int main(){                      // function starts
  int x[20],size,j;  
  float f=0.0,0,.0,7.;            // to check const_float 
  char c='d','hkhk';			// to check const_char
  int i=0,j=6;6575;                     // check const_int 

  printf("Enter size of the array: ");  // check string literal functionality
  scanf("%d",&size);     //Punctuators and identifiers

  printf("Enter %d elements: ",size);
  for(i=0;i<size;i++)
    scanf("%d",&x[i]);              

  quicksort(x,0,size-1);

  printf("Sorted elements: ");
  for(i=0;i<size;i++)
    printf(" %d",x[i]);

  return 0;
}

// recursive function to sort array 
void quicksort(int x[10],int first,int last){
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);

    }
}

/* 

this is non terminating comment

*

