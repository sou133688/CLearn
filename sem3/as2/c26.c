//
//  .c
//  c26.c
//
//  heap sort
//
//  Created by Shuma Matsuzaki
//  2020/06/06
//  Copyright© Shuma Matszuaki 2020.  All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include "c20.c"


//プロトタイプ宣言
void heap_sort(int*,int);
void downheap(int*,int,int,int);

int main (void) {
  printf("*****************************************************************************************\n" );

  int N;       // 入力配列の要素数
  scanf("%d", &N);               // STDINから要素数を受け取る
  int* array = func_mallocation_(N);  // 配列に動的メモリを割り当てる(作業スペースが必要なので2N)

  for (int i = 0; i < N; i++)
  scanf("%d", &(array[i]));  // STDINから配列要素を受け取る

  printf("INIT:::::::");
  print_array_(array, N);             // 配列の初期状態をSTDOUTに出力

  heap_sort(array, N);

  printf("DONE:::::::");
  print_array_(array, N);  // 配列の最終状態をSTDOUTに出力

  free(array);  // 配列に割り当てられた動的メモリを解放
  return 0;     // main関数の終了
}


/*--------------------------heapsort------------------------*/
void heap_sort (int* array, int N) {
  int i;

  int M;//ヒープ木のサイズ
  int k;//接点のindex
  int j;


  for (M = N; M > 1; M--) {
    // printf("ヒープサイズは%d\n",M );

    for (k= M; k>=0 ; k--) {

        downheap(array,N,k,M-1);

    }

    func_swap_(array,0,M-1);
    // printf("SWAP(%2d,%2d)--", array[0],array[M-1]);
    print_array_(array,N);

    // printf("M:%d\n",M );
  }

  return;
}


/*----------------------------------------------------------*/



/*------------------downheap構造の構築----------------------- */
void downheap(
  int* array,   //配列
  int N,  //配列サイズ
  int k,  //節点
  int M   //heap木のサイズ
){

  int t=k;

  while(1){

    int fl=(2*t+1<=M);//左の子要素がinrange
    int fr=(2*t+2<=M);//右の子要素がinrange


//___________________________________________________
    if (fl==1&&fr==1) {//子が二つの時__両方inrange

      int child_index;
      //child1とchild2を比較して大きい方をChildに
      if (array[2*t+1]>=array[2*t+2]/*comp_(array,2*k+1,2*k+2)==0*/) {//左が大きい時
        child_index=2*t+1;
      }else{
        child_index=2*t+2;
      }

      // printf("\nfl=1::fr=1::adult_index=%d::child_index=%d\n",k,child_index );
      // printf("adult/array[%d]/%d::::child/array[%d]/%d\n",k,array[k],child_index,array[child_index]);

      if(/*adult<child*/array[t]<array[child_index]/*comp_(array,k,2*k+1)==1*/){

        printf("DH(%2d,%2d) ",k,M+1);
        func_swap_(array,t,child_index);//親要素子要素の入れ替え

        // printf("SWAP(%2d,%2d)** ",k,2*k+1);
        print_array_(array,N);

        t=child_index;

        // downheap(array,N,child_index,M);//再帰

      }else{
        break;
      }

    }
    else if(fl==1&&fr==0){//子要素1つ__(2*k+1inrange)かつ(2*k+2outofrange)

        // printf("\nfl=1::fr=0::adult_index=%d::child_index=%d\n",k,2*k+1 );
        // printf("adult/array[%d]/%d::::child/array[%d]/%d\n",k,array[k],2*k+1,array[2*k+1]);

        if(array[t]<array[2*t+1]/*comp_(array,k,2*k+1)==1*/){//adult<child

          printf("DH(%2d,%2d) ",k,M+1);
          func_swap_(array,t,2*t+1);//親要素子要素の入れ替え

          // printf("SWAP(%2d,%2d)// ",k,2*k+1);
          print_array_(array,N);

          // downheap(array,N,2*k+1,M);//再帰

          t=2*t+1;//tの更新

        }else{
          break;
        }

    }
    else{//fl=0&&fr=0//子要素なし_両方outofrange
        // printf("\nfl=0::fr=0\n");
        //何もしない
        break;
    }
//____________________________________________________

  }


  return;

}

/*----------------------------------------------------------*/
