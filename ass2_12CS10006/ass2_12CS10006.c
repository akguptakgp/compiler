/*
 Compilers Laboratory Autumn Semester 2014-2015
 Assignment 2 :-Creating Library
 Written by :- Ankit Kumar Gupta (12CS10006)
 Implementation of Library myl.h
*/

// library function to print charcter string terminated by NULL character
// returns number of characters printed.

int prints(char *str)
{
  int no_byte=0;
  int i=0;
  while(str[i++]!='\0') no_byte++;
  
  __asm__ __volatile__ (
			"movl $4, %%eax \n\t"
			"movl $1, %%ebx \n\t"
			"int $128 \n\t"
			:
			:"c"(str), "d"(i)
			) ;  // $4: write, $1: on stdin
 return no_byte;
}



// library function to print charcter string terminated by NULL character
 #define BUFF 20   // Maximum length of integer is 10
// prints the integer value of n 
// returns the number of characters printed.

int printi(int n)
{ 
  char buff[BUFF], zero='0';
  int i=0, j, k, bytes;
  if(n == 0) buff[i++]=zero;
  else{
    if(n < 0) {
      buff[i++]='-';
      n = -n;
    }
    while(n){
      int dig = n%10;
      buff[i++] = (char)(zero+dig);
      n /= 10;
    }
    if(buff[0] == '-') j = 1;
    else j = 0;
    k=i-1;
    while(j<k){
      char temp=buff[j];
      buff[j++] = buff[k];
      buff[k--] = temp;
    }
  }
  bytes = i;
  __asm__ __volatile__ (
			"movl $4, %%eax \n\t"
			"movl $1, %%ebx \n\t"
			"int $128 \n\t"
			:
			:"c"(buff), "d"(bytes)
			) ; // $4: write, $1: on stdin
  return bytes;
}


// library function to read an integer (signed)
#define PLUS 1
#define MINUS -1

// reads an integer (signed) and returns it.
// parameter is for error (ERR = 1, OK = 0).

int readi(int *ep) 
{
  char buff;
  int i=0,rt=0;
  *ep=0;
  int flag=PLUS;
  while(1){
  __asm__ __volatile__ (
			"movl $3, %%eax \n\t"
			"movl $1, %%ebx \n\t"
			"int $128 \n\t"
			:
			:"c"(&buff), "d"(1)
			) ;
  if((buff==' ' || buff=='\n' || buff=='\t') && i==0) continue;
  
  if(buff >= '0' && buff <= '9')
    {
      rt=rt*10+buff-'0';
    }
  else 
    if(buff=='-' && i==0) {flag=MINUS;}
    else 
      {
	if(buff!=' '&& buff!='\n' && buff!='\t')
	  {  *ep=1;
	  }
	else 
	  break;
      }
  i++;
  }
  if(i==0) *ep=1;
  if(flag==MINUS) rt=-rt;

  return rt;
}



// library function to read floating point number
#define DEC 0
#define FLT 1
// reads an floating point (signed) and returns it via parameter.
// return value is for error (ERR = 1, OK = 0)

int readf(float  *fp)
{
  char buff;
 int i=0;
 *fp=0;
 int flag=PLUS;
 int status=DEC;
float mult=0.1;
 int ERR=0;
 while(1){
  __asm__ __volatile__ (
			"movl $3, %%eax \n\t"
			"movl $1, %%ebx \n\t"
			"int $128 \n\t"
			:
			:"c"(&buff), "d"(1)
			) ;
  if((buff==' ' || buff=='\n' || buff=='\t') && i==0) continue;
  
  if(buff=='-' && i==0){ flag=MINUS; continue;}
  
  if(status==DEC)
    {
      if(buff >= '0' && buff <= '9')
	{
	  (*fp)=(*fp)*10+buff-'0';
	}
      else
	{ 
	if(buff=='.')
	  {
	    status=FLT;   
	  }
	else
	  {
	    if(buff!=' '&& buff!='\n' && buff!='\t')
	      {  
		ERR=1;
	      }
	    else 
	      break;
	  }
	}
      i++;
    }
  else
    {
       if(buff >= '0' && buff <= '9')
	{
	    *fp+=((buff-'0')*mult);
              mult/=10;
	}
       else
	  {
	    if(buff!=' ' && buff!='\n' && buff!='\t' )
	      {  
		ERR=1;
	      }
	    else 
	      break;
	  }
      i++;
    }
  // printf("%d\n",i);
 }

 if(i==0) return ERR;
 if(flag==MINUS) *fp=-(*fp);
 return ERR;
}


// library function to print floating point number (signed)
// prints the integerfloat value of n 
// returns the number of characters printed.
// prints upto 6 character after decimal
int  printd(float f){ 
  char buff[BUFF], zero='0';
  int i=0, j, k, bytes;
  
  if(f == 0) buff[i++]=zero;
  else{
    if(f < 0) {
      buff[i++]='-';
      f = -f;
    }
    int n=f;
    while(n){
      int dig = n%10;
      buff[i++] = (char)(zero+dig);
      n /= 10;
    }
    if(buff[0] == '-') j = 1;
    else j = 0;
    k=i-1;
    while(j<k){
      char temp=buff[j];
  buff[j++] = buff[k];
  buff[k--] = temp;
    }
  }
    buff[i++]='.';
    f=f-(int)f;
     int temp,step=0;
      while(step++ < 7)
      {
	temp=f*10;
	f=f*10-temp;
	buff[i++]=(char)(zero+temp);
      }
    
bytes = i-1  ;
__asm__ __volatile__ (
"movl $4, %%eax \n\t"
"movl $1, %%ebx \n\t"
"int $128 \n\t"
:
:"c"(buff), "d"(bytes)
) ; // $4: write, $1: on stdin
 return bytes;
}
