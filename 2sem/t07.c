#include<stdio.h>
#define N 4

int main(void){

  int i,j,a[N][N],b[N][N];

  printf("enter 4×4 matrix:\n");
  for(i=0;i<N;++i){
    scanf("%d %d %d %d", &a[i][0],&a[i][1],&a[i][2],&a[i][3]);
  }

  for(i=0;i<N;++i){
    for(j=0;j<N;++j){
      b[j][i]=a[i][j];
    }
  }

  printf("transported matrix:\n");
  for(i=0;i<N;++i){
    for(j=0;j<N;++j){
      printf("%d ", b[i][j]);
      if(j==N-1)
          printf("\n");
    }
  }
}

// Mac(iOS)環境での動作は確認しました。
