#include<stdio.h>


int saiki(int N){

  printf("N=%d\n",N );

  if (N<1) {
    printf("りたーん！\n\n" );
    return 0;
  }

  printf("FHASE1\n");
  saiki(N-1);

  printf("N=%d\n",N );
  printf("\nFHASE2\n" );

  saiki(N-2);

  printf("N=%d\n",N );
  printf("\nFHASE3\n");

  return 0;
}


int main(){

  printf("これから始まる再帰のテスト♪♪\n");

  saiki(2);

  printf("おわりんご！\n");
}
