#include<stdio.h>

int main(void){
  int n,i,j;

  printf("n=");
  scanf("%d",&n);

  printf("%d行%d列の単位行列を表示します。\n", n, n);

  for(j=1;j<=n;j++){

    for(i=1;i<=n;i++){

     if(j==i){
       printf("1 " );
     }else{
     printf("0 ");
}
    }
    printf("\n");
  }
}
