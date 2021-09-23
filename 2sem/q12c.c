#include<stdio.h>
#define N 10
void scanArray(int *);
void mulArray(int *, int);
void printArray(int *);

main()
{
    int a[N];
    int n;
    scanArray(a);
    scanf("%d",&n);
    mulArray(a,n);
    printArray(a);
}


void scanArray(int *a)
{
  int i;
  for(i=0;i<N;i++)
    {
      scanf("%d",a+i);
    }
}

void mulArray(int *a,int n)
{
  int i;
  for(i=0;i<N;i++)
    {
      *(a+i)=*(a+i)*n;
    }
}

void printArray(int *a)
{
  int i;
  for(i=0;i<N;i++)
    {
      printf("%d\n",*(a+i));
    }
}
