#include <stdio.h>
#include <stdlib.h>
#include "c20.c"


int ins_sort(int *, int);

int main() {
  printf("-------------------------------------------------------------------------------------\n");


  int N;       // 入力配列の要素数
  scanf("%d", &N);               // STDINから要素数を受け取る
  int* array = func_mallocation_(N+1);  // 配列に動的メモリを割り当てる

  for (int i = 0; i < N; i++)
    scanf("%d", &(array[i]));  // STDINから配列要素を受け取る

  printf("INIT:::::::");
  print_array_(array, N);             // 配列の初期状態をSTDOUTに出力

  int cnt = ins_sort(array, N);  // 比較回数をins_sortから呼び出す

  printf("DONE:::::::");
  print_array_(array, N);  // 配列の最終状態をSTDOUTに出力


  printf("%d\n", cnt);     // comp_が呼んだ合計回数を出力

  free(array);  // 配列に割り当てられた動的メモリを解放
  return 0;     // main関数の終了
}

int ins_sort(int *array, int N) {
  int i,j;
  int comp_count=0;
  int count2;//array[j]>array[N]の分岐に入ったか否かを判断する変数

    for (i = 1; i < N; i++) {
        count2=0;//array[j]>array[N]の分岐に入った回数のカウントをリセット


        /* printf("i=%d : array[N]=%d\n",i,array[N] );*/

        array[N]=array[i];//挿入する要素array[i]をarray[N]に一時保存
        j = i - 1;//挿入する要素番号iの一つ前の要素番号をjとして定義

        for (j = i-1; j >= 0; j--) {
          /* printf("jは%d\n", j);*/

          if (comp_(array,N,j)==1) {//array[j]とarray[N]とを比較し、array[j]>array[N]の時

            /*printf("(array[%d]=%2d) > (array[N]=%2d)\n",j,array[j],array[N]);*/

            comp_count+=1;//比較回数をカウント
            count2+=1;//array[j]>array[N]の分岐に入った回数のカウント

            //array[j+1](つまり挿入したいarray[N])とarray[j]との入れ替えを行う
           func_copy_val_(array,j,j+1);//array[j+1]にarray[j]をコピー
           array[j] = array[N];//array[N]をarray[j]にコピー
            /* printf("if,array[%d]=%2d,array[%d]=%2d\n",j,array[j],j+1,array[j+1]);*/

          }else{
            comp_count+=1;//比較回数をカウント

            array[j+1]=array[N];//array[j+1]にarray[N]をコピー

             // printf("else,array[%d]=%2d\n",j+1,array[j+1]);

            break; //array[j]<=array[N]なのでソートは終了,次のiで比較するためline:59からのforループを抜ける
          }
        }



   if (count2>0){ //array[j]>array[N]の分岐が一度でも適応されている場合
     printf("INST(%2d,%2d)",i,j+1);
     print_array_(array, N+1);
   }
 }

   return comp_count;//比較回数を返す
 }
