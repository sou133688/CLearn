#include<stdio.h>
#define N 3

int main(void){

 int k, i, j;
 int a[N][N],b[N][N],c[N][N];

 printf("A=\n");
  for(i=0;i<N;++i){
    scanf("%d %d %d", &a[i][0],&a[i][1],&a[i][2]);
  }

  printf("B=\n");
  for(i=0;i<N;++i){
    scanf("%d %d %d", &b[i][0],&b[i][1],&b[i][2]);
  }

  printf("A*B=\n");
  for(i=0; i<N; ++i){
    for(j=0; j<N; ++j){
      c[i][j]=0;
      for(k=0; k<N; ++k){
        c[i][j]+=a[i][k]*b[k][j];
      }
    }
  }

  for(i=0; i<N; ++i){
    printf("%d %d %d\n",c[i][0],c[i][1],c[i][2]);
  }
}
