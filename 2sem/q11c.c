#include<stdio.h>
#include<math.h>
#define N 5

float vecNorm(int* p){
  int k;
  float Norm=0, ans=0;
  for(k=0;k<N;++k){

    Norm = Norm + *(p+k)**(p+k) ;
  }
  ans = sqrt(Norm);
  return ans;
}

int main(){
  int a[N];
  int i;
  for(i=0;i<N;++i){
    scanf("%d", &a[i]);
  }
  printf("norm = %f\n", vecNorm(a));
}
