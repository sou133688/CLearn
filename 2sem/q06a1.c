#include<stdio.h>
#define n 3

int main(void){
int e[3][3]={{1,0,0},
             {0,1,0},
             {0,1,0}};

int i,j;
int a[n][n],b[n][n];


printf("A=\n");
    for(i=0;i<n;++i){
    for(j=0;j<n;++j){
      scanf("%d", &a[i][j]);
    }
    printf("\n");
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
