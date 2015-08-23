#include "myl.h"

int main()
{
 
  int a1,epa1=1,nca1;
  prints("enter two integer numbers\n");
  while(epa1)
  {
  a1=readi(&epa1);
  if(epa1) prints("invalid... Please reenter\n");
  }
   int a2,epa2=1,nca2;
  while(epa2)
  {
  a2=readi(&epa2);
  if(epa2) prints("invalid... Please reenter\n");
  }
  
  
  prints("enterd number are:");
  nca1=printi(a1);
  //prints("\nnumber of character printed in above integer is :");
  //printi(nca1);
  prints("\t");
  
  nca2=printi(a2);
  //prints("\nnumber of character printed in above integer is :");
  //printi(nca2);
  prints("\n");
  
  prints("sum of enterd number is:\t");
  printi(a1+a2);
    prints("\n");
  
  float b1;
  int epb1=1,ncb1;
  prints("enter two floating point numbers\n");
   while(epb1){
  epb1=readf(&b1);
  if(epb1)  prints("invalid... Please reenter\n");
  }
 
  float b2;
  int epb2=1,ncb2;
   while(epb2){
  epb2=readf(&b2);
  if(epb2)  prints("invalid... Please reenter\n");
  }
  
  
  prints("enterd number are:\t");
  ncb1=printd(b1);  
  //prints("\nnumber of character printed in above float  is :");
  //printi(ncb1);
  prints("\t");
  
  
  //prints("enterd number is:\n");
  ncb2=printd(b2);  
  //prints("\nnumber of character printed in above float  is :");
  //printi(ncb2);
  prints("\n");

  prints("sum of enterd number is:");
  printd(b1+b2);
    prints("\n");
    
    int ncs;
   prints("product  of both sum is:");
   ncs=printd((a1+a2)*(b1+b2));
   prints("\n");
   prints("number of character printed in above product is :");
   printi(ncs);
   prints("\n");

  return 0;
}

