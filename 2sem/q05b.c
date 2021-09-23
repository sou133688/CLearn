#include<stdio.h>

int main(){
  int x[7]={9,4,8,2,5,6,1};
  int t,i;

  printf("並べ替え前: %d %d %d %d %d %d %d\n",x[0],x[1],x[2],x[3],x[4],x[5],x[6]);

  while(x[0]>x[1]||x[1]>x[2]||x[2]>x[3]||x[3]>x[4]||x[4]>x[5]||x[5]>x[6]){
    for(i=0;i<=5;i++){

      if(x[i]>x[i+1]){
       t = x[i];
       x[i] = x[i+1];
       x[i+1] = t;
      }

    }

 }

 printf("並べ替え後: %d %d %d %d %d %d %d\n",x[0],x[1],x[2],x[3],x[4],x[5],x[6]);

}
