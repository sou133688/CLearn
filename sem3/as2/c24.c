//
//  .c
//  c24.c
//
//  merge sort
//
//  Created by Shuma Matsuzaki
//  2020/06/03
//  Copyright© Shuma Matszuaki 2020.  All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "c20.c"

int merge_sort(int *, int , int , int );
int merge(int *, int , int , int , int );


int main() {
  printf("*****************************************************************************************\n" );

  int N;       // 入力配列の要素数
  scanf("%d", &N);               // STDINから要素数を受け取る
  int* array = func_mallocation_(2*N);  // 配列に動的メモリを割り当てる(作業スペースが必要なので2N)

  for (int i = 0; i < N; i++)
    scanf("%d", &(array[i]));  // STDINから配列要素を受け取る



  printf("INIT:");
  print_array_(array, N);             // 配列の初期状態をSTDOUTに出力

  int cnt = merge_sort(array, N,0,N-1);  // 比較回数をmerge_sortから呼び出す

  printf("DONE:::::::");
  print_array_(array, N);  // 配列の最終状態をSTDOUTに出力


  printf("cnt:%d\n", cnt);     // 関数comp_が呼ばれた合計回数を出力

  free(array);  // 配列に割り当てられた動的メモリを解放
  return 0;     // main関数の終了
}




// static int comp_count=0;//再帰によってcountが初期化されないよう、ここで定義と初期化(静的変数禁止...)

int merge_sort(int* array, int N, int left, int right) {

    if (left >= right) { //配列の要素数が1つの時ソートの必要がないのでreturn
      return 0;
    }

    int mid = (left + right) / 2;//(配列の)中央の要素番号midをとる

    // printf("left:%d,right:%d\n",left,right );

    int count_left=0;//左側配列の比較回数を定義し初期値0に設定
    count_left=merge_sort(array, N, left, mid);//2分した時の左側の配列を再起呼び出しによって要素数が1になるまで分割しその後マージする時の比較回数を代入

    int count_right=0;//右側配列の比較回数を定義し初期値0に設定
    count_right=merge_sort(array, N, mid + 1, right);//2分した時の右側の配列を再起呼び出しによって要素数が1になるまで分割しその後マージする時の比較回数を代入

    int count=0;
    count+=merge(array, N, left, mid, right);//関数mergeによってarray[left]からarray[mid]までの配列とarray[mid+1]からarray[right]までの配列をソートし統合、その際の比較回数をcomp_countに逐一加えていく

    //この段階以前での左側配列,右側配列をソートするまでの比較回数とこの段階での比較回数をcomp_countに代入
    int comp_count=0;
    comp_count=count+count_left+count_right;

    printf("MERG(%2d,%2d)",left,right);
    print_array_range_(array,N,left,right);//mergeした部分のインデックスと配列を表示

    return comp_count;//比較回数の最終的な値をmain関数に返す
}


//merge関数では比較,ソートした値を右側の作業用領域に保管していき、表示される領域へと戻していく

int merge(int* array, int N, int left, int mid, int right) {

    // printf("N:%d\n",N );

    int N1 = mid - left + 1;//左側配列の要素数
    int N2 = right - mid;//右側配列の要素数

    int comp_count_merge=0;//比較

    // printf("N1:%d,N2:%d\n",N1,N2 );//


    int i=0,j=0,k=N;//左側配列,右側配列,作業用配列のカーソル定義(それぞれ初期値は0,0,Nとする)

    int fl=1,fr=1;//左側配列,右側配列がそれぞれinrangeとして論理値の定義)

  //左側配列,右側配列を比較し作業用配列にソートした値を昇順に格納しておく
    while (fl||fr) {//左側配列または右側配列がinrangeの場合

      // printf("fl:%d,fr:%d\n i:%d,j:%d,k:%d\n",fl,fr,i,j,k);//


        // L=array[i+left];
        // R=array[j+mid+1];


      if(fl&&fr){//左側配列と右側配列がともにinrangeの場合
        comp_count_merge++;//比較回数をカウントする
        //いずれかがoutofrangeの場合比較の必要性がない
      }

      if (((comp_(array,left+i,mid+1+j)==1)/*(array[i+left]<array[j+mid+1])*/||(fr!=1))&&fl) {//(右のみoutofrange) または　( 両方がinrangeかつ(左側配列の値<右側配列) )の値の場合  ***
        func_copy_val_(array,i+left,k);  //左側配列の値を作業用配列に格納array[k]=L;
        i++;//左側配列のカーソル移動
        k++;//作業用配列のカーソル移動
      }else{//(左のみoutofrange) または ( 両方がinrangeかつ(左側配列の値>=右側配列) )の値の場合 ***
        func_copy_val_(array,j+mid+1,k); //右側配列の値を作業用配列に格納
        // array[k]=R;
        j++;//右側配列のカーソル移動
        k++;//作業用配列のカーソル移動
      }

      fl=(i<N1);//論理値の格納(左側配列のインデックスカーソルiがinrangeか否か)
      fr=(j<N2);//論理値の格納(右側配列のインデックスカーソルjがinrangeか否か)

    }

//ここまでで作業配列へのソートと格納終了


//作業配列から、左側配列と右側配列を組み合わせた配列array[left~right+1]へ、ソート済昇順の配列を格納
int t;
for (t = 0; t < right -left+1; t++) {
  // printf("array[%d]=%d\n",N+t,array[N+t] );//
  // printf("array[%d]=%d\n",left+t,array[left+t] );//

  func_copy_val_(array,N+t,left+t);// array[left+t]=array[N+t]__作業配列からの格納
}


// print_array_(array,2*N);//

    return comp_count_merge;//mergeする際の比較回数を関数merge_sortに返す
}
