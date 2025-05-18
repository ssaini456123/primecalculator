#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int asz;
int* compute_prime_n(long long);
long long compute_fact(long long);

long long compute_fact(long long n)
{
  if(n==1)
  {
    return 1;
  }

  return n*compute_fact(n-1);
}

/**
 * comptue_prime_n(long long)
 */
int* compute_prime_n(long long n)
{
  int* a,i,m,j,t;
  long long f;

  if(n<2)
  {
    return NULL;
  }

  i=2;
  f=0;
  a=(int*)malloc(n*sizeof(int));
  while(f<n)
  {
    *(a+f)=1;
    f++;
  }

  m=sqrt(n);

  for(i;i<=m;i++)
  {
    if ((*(a+i))==1)
    {
      for(j=i*i;j<n;j+=i)
      {
        *(a+j)=0; 
      }
    }
  }

  asz=n+1;

  return a;
}

int main()
{
  long long n;
  int* p,i,s,pp,x;
  char* d;
  i=0;

  scanf("%lld", &n);

  p=compute_prime_n(n);
  s=asz;

  while(i<s)
  {
    x=*(p+i);
    if(x==1)
    {
      d="true";
    }
    else 
    {
      d="false";
    }
    if(i==0||i==1)
    {
      d="false";
    }
    printf("is %d prime? %s\n",i,d);
    i++;
  }
  return 0;
}