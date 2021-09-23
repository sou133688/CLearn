//
//  .c
//  c25.c
//
//  radix sort
//
//  Created by Shuma Matsuzaki
//  2020/06/04 
//  Copyright© Shuma Matszuaki 2020.  All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "c20.c"

void rad_sort(int *, int, int );
int find_max(int *,int);
int find_max_digit(int ,int );
int extract_c_(int ,int ,int );
// void matrix_reset(int *, int,int);


int main() {

  printf("*****************************************************************************************\n" );

  int N;       // 入力配列の要素数
  scanf("%d", &N);               // STDINから要素数を受け取る
  int* array = func_mallocation_(N);  // 配列に動的メモリを割り当てる(作業スペースが必要なので2N)

  for (int i = 0; i < N; i++)
    scanf("%d", &(array[i]));  // STDINから配列要素を受け取る

  int M;      //ソートに利用する基数
  scanf("%d", &M);    //STDINから基数を受け取る

  printf("INIT:::::::");
  print_array_(array, N);             // 配列の初期状態をSTDOUTに出力

  rad_sort(array, N,M);  // 関数rad_sortを呼び出す

  printf("DONE:::::::");
  print_array_(array, N);  // 配列の最終状態をSTDOUTに出力


  free(array);  // 配列に割り当てられた動的メモリを解放
  return 0;     // main関数の終了

}

void rad_sort(int* array, int N, int M) {
  printf("radix sort\n");
  int max,max_digit;

  //最大桁数の把握のために最大の要素を得る
    max=find_max(array,N);

  //最大桁数を把握するために基数Mでの最大桁数を得る
    max_digit=find_max_digit(max,M);

    printf("MAX:%d;;;MAXDIGIT:%d\n",max,max_digit );

/*-------------------*/   //ここまでで配列中の最大値と基数Mにおける最大の桁数が求められている

  int t,i,j;

  int bucket[20][30];
  // int* bucket =func_mallocation_(M-1);
  // for (i = 0; i < M-1 ; i++) {
  //   int* bucket[i] = func_mallocation_(N);
  // }





  for (t = 1; t <= max_digit; t++) {//基数Mにおけるt桁目を考える


// bucket行列の初期化---------------------------
// matrix_reset(bucket, M-1, N);

    int m,n;
    for(m = 0;m < M-1; m++){
      for (n = 0; n < N; n++) {
        bucket[m][n] = -1;
      }
    }

    for(m = 0;m < M-1; m++){
      for (n = 0; n < N; n++) {
        printf("%2d ",bucket[m][n] );
      }
      printf("\n" );
    }

//初期化終了-------------------------------

int k;
i=0;
j=0;
//適切なbucketにarraykを分類していく-------------------
for (i = 0; i < M; i++) {

  for (k = 0; k < N; k++) {
    // c=(array[k]/M**(t-1))%M;//array[k]について基数M,t桁目の値cを得る
    int c;
    c=extract_c_(array[k],M,t);

    if (c==i) {//bucketの種類iとcが一致する場合bucket[i]にいれる
      bucket[i][j]=array[k];
      j++;
    }

  }
}
// bucketへの振り分け完了------------------



    i=j=0;

    //基数Mでのt桁目の値によって作業用配列bucketに分類したものをarrayに戻す
     k=0;
    while (i<M) {
      while (bucket[i][j]>=0) {//初期値(つまり空)になるまで
        array[k]=bucket[i][j];
        j++;//arrayのインデックスを次に
        k++;//arrayのインデックスを次に

      }

      i++;//次のバケットを元の配列に戻す
    }


printf("RAD(%6d)",t );
print_array_(array,N);
}
//基数Mでのt桁目の処理終了

}


int find_max(int *array,int N){//配列の最大値を求める
  int max=0,i;
  for (i = 0; i < N; i++) {
    if (max<array[i]) {
      max=array[i];
    }
  }
  return max;
}

int find_max_digit(int max,int M){
  int max_digit=0;
  int t=1;
  while (t<max) {
    t=t*M;
    max_digit++;
  }
  return max_digit;
}

int extract_c_(int a,int M,int t){
  int i;
  int MM=1;
  int c;
for (i = 0; i < t-1; i++) {
  MM=MM*M;
}
  c=(a/MM)%M;
  return c;
}
//
// void matrix_reset(
//   int* const matrix,
//    const int a,
//    const int b
// ){
//   // printf("AAA%d::%d\n",a,b );
//   matrix[a-1][b-1]=1;
//   // int i,j;
//   // for(i = 0;i < a; i++){
//   //   for (j = 0; j < b; j++) {
//   //     matrix[i][j] = 0;
//   //   }
//   // }
// }
