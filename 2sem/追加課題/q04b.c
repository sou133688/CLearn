#include<stdio.h>

int main(void){
  int i,n,r,p=1;

  printf("n=");
  scanf("%d",&n);

  printf("r=");
  scanf("%d",&r);

  for(i = n; i >= r+1; i--){

   p=p*i;

  }
  printf("%d\n",p);
}
