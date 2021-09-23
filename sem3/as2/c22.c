#include<stdio.h>
#include <stdlib.h>
#include "c20.c"

int bub_sort(int *, int);

int main() {

  int N;       // 入力配列の要素数
  scanf("%d", &N);               // STDINから要素数を受け取る
  int* array = func_mallocation_(N);  // 配列に動的メモリを割り当てる

  for (int i = 0; i < N; i++)
    scanf("%d", &(array[i]));  // STDINから配列要素を受け取る

  printf("INIT:::::::");
  print_array_(array, N);             // 配列の初期状態をSTDOUTに出力

  int cnt = bub_sort(array, N);  // 比較回数をbub_sortから呼び出す

  printf("DONE:::::::");
  print_array_(array, N);  // 配列の最終状態をSTDOUTに出力


  printf("%d\n", cnt);     // comp_が呼んだ合計回数を出力

  free(array);  // 配列に割り当てられた動的メモリを解放
  return 0;     // main関数の終了

}



int bub_sort(int *array, int N) {
  int comp_count = 0;  // 比較した回数の初期値を0に設定
  int i; //配列の、比較する1つ目の要素番号
  int j; //配列の、比較する2つ目の要素番号

  for (i = N; i > 1; i--){//配列を大きい順に右から並べる
      for (j = 1; j < i; j++){   //　array[0]からarray[i-1]までを比較
        comp_count+=1;//比較回数のカウント

        if (comp_(array,j,j-1)==1) {//array[j]<array[j-1]の時
          func_swap_(array,j-1,j);//array[j-1]とarray[j]とを入れ替え
          print_array_(array, N);//入れ替え後のarrayを表示
        }

      }
    }
  return comp_count;  // 比較回数を返す
}
