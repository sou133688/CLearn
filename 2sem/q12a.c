#include <stdio.h>

int c(int,int,int);

int main()
{
  int n,a1=1,count=0;
  printf("enter n:\n");
  scanf("%d",&n);

  if(n==1)
    {
      printf("a1=%d",a1);
    }
  else
    {
      printf("a[%d]=%d\n",n,c(a1,count,n));
    }
}

int c(int k,int count,int n)
{
  int ans;
  count=count+1;
  ans=k+count;
  if(count==n-1)
    {
      return ans;
    }
  else
    {
      c(ans,count,n);
    }
}
