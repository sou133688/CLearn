#include<stdio.h>
#define n 3

int main(void){

  int i,j;
  int a[n][n],b[n][n];
  int e[n][n];

  for(i=0;i<n;++i){
    for(j=0;j<n;++j){
      if(i==j){
        e[i][j]=1;
      }
      else{
        e[i][j]=0;
      }
    }
  }

  printf("A=\n");
  for(i=0;i<n;++i){
    scanf("%d %d %d", &a[i][0],&a[i][1],&a[i][2]);
  }

  for(i=0;i<n;++i){
     for(j=0;j<n;++j){
       b[i][j] = e[i][j] + a[i][j];
     }
   }


   printf("A+E=\n");
     for(i=0;i<n;++i){
       for(j=0;j<n;++j){
         printf("%d ", b[i][j]);
       }
       printf("\n");
     }
}
