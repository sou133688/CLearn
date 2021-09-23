#include<stdio.h>
#define N 5

int sum(int p[]){
  int j;
  int Sum = 0;
  for(j=0;j<N;++j){
    Sum = Sum + p[j];
  }
  return Sum;
}

int main(){
  int a[N];
  int i;
  for(i=0;i<N;++i){
    scanf("%d", &a[i]);
}
  printf("%d\n",sum(a));
}
