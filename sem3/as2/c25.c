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

  // printf("*****************************************************************************************\n" );

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

void rad_sort(
  int* array,
  int N,
  int M    //配列array,要素数N,基数Mをmain関数から受け取る
) {

  // printf("radix sort\n");

  int max,max_digit;//配列中要素の最大値と基数Mでの最大桁数を定義

  //最大桁数の把握のために最大の要素を得る
    max=find_max(array,N);

  //最大桁数を把握するために基数Mでの最大桁数を得る
    max_digit=find_max_digit(max,M);

    // printf("MAX:%d;;;MAXDIGIT:%d\n",max,max_digit );

/*-------------------*/   //ここまでで配列中の最大値maxと基数Mにおける最大の桁数max_digitが求められている

  int t,i,j; //基数Mでの桁数t,bucketの行・列のカウンターを各々定義

  // int bucket[20][30];//二次元配列bucketの定義とメモリ確保

  // 二次元配列bucketの定義と動的メモリ確保
  int **bucket;
  bucket = (int**)malloc(M*sizeof(int*)) ;
  for (i = 0; i < M ; i++) bucket[i] = (int*)malloc(N*sizeof(int));





  for (t = 1; t <= max_digit; t++) {//基数Mにおけるt桁目を考える


// bucket行列の初期化---------------------------

// matrix_reset(bucket, M-1, N);//bucketを初期化する関数

    int m,n;
    for(m = 0;m < M-1; m++){
      for (n = 0; n < N; n++) {
        bucket[m][n] = -1;//配列の初期値を全て-1として初期化する
      }
    }

//初期化終了-------------------------------


    int k,i=0,j=0; //配列array、二次元配列bucketの行、二次元配列bucketの列のカウンターを各々定義

//適切なbucketにarraykを分類していく-------------------

    for (i = 0; i < M; i++) {//bucketの種類()を選択

      for (k = 0; k < N; k++) {//arrayのカウンターを次に

        //array[k]について基数M,t桁目の値cを得る
        int c;
        c=extract_c_(array[k],M,t);//array[k]のM進数におけるt桁目の値cを求める

        if (c==i) {//bucketの種類iとcが一致する場合array[k]の要素をbucket[i]にいれる
          bucket[i][j]=array[k];
          j++;//bucket[i]での次の列へ
        }

      }

    }
// bucketへの振り分け完了------------------

    i=j=0;//bucketの行,列のカウンターを初期化

//基数Mでのt桁目の値によって作業用配列bucketに分類したものをarrayに戻す
     k=0;//arrayのカウンターを初期化
    while (i<M) {//bucketの種類(行i)がM未満の場合
      while (bucket[i][j]>=0) {//初期値(つまり空)になるまで
        array[k]=bucket[i][j];//arrayにbucketから順々に値を入れていく
        j++;//bucketのインデックスを次に
        k++;//arrayのインデックスを次に
      }
      i++;//次のbucketを元の配列arrayに戻す
    }

//t桁目においてbucketからarrayに要素の適切な振り分け完了

//出力
    printf("RAD(%6d)",t );
    print_array_(array,N);

  }
//基数Mでのt桁目の処理終了


//bucketに割り当てた動的メモリの解放
// free=

}


int find_max(//配列arrayの要素の最大値を求める
  int *array,
  int N
){

  int max=0,i;//仮の最大値maxとarrayのインデックスのカウンターを定義
  for (i = 0; i < N; i++) {
    if (max<array[i]) {
      max=array[i];//もしarray[i]の値が仮定義した最大値maxより大きい場合maxとして扱う
    }
  }

  return max;//上の処理で配列arrayから取り出した最大値を返す
}


int find_max_digit(//配列arrayの最大値maxを利用して基数Mでの最大桁数max_digitを得る関数
  int max,
  int M
){

  int max_digit=0;//最大桁数を0として仮定義
  int t=1;//

  while (t<max) {
    t=t*M;
    max_digit++;
  }

  return max_digit;//上の処理で得た基数Mでの最大桁数max_digitを返す
}


int extract_c_(//array[k]のM進数におけるt桁目の値cを求める
  int a,
  int M,
  int t
){
  //M^(t-1)を求める
  int i,MM=1;
  for (i = 0; i < t-1; i++) {
    MM=MM*M;
  }

  int c;
  c=(a/MM)%M;

  return c;//M進数におけるt桁目の値cを返す
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
