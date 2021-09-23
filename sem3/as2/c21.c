#include<stdio.h>
#include <stdlib.h>
#include "c20.c"

int sel_sort(int *, int);

int main() {

  int N;       // 入力配列の要素数
  scanf("%d", &N);               // STDINから要素数を受け取る
  int* array = func_mallocation_(N);  // 配列に動的メモリを割り当てる

  for (int i = 0; i < N; i++)
    scanf("%d", &(array[i]));  // STDINから配列要素を受け取る

  printf("INIT:::::::");
  print_array_(array, N);             // 配列の初期状態をSTDOUTに出力


  printf("DONE:::::::");
  print_array_(array, N);  // 配列の最終状態をSTDOUTに出力


  int cnt = sel_sort(array, N);  // 比較回数をsel_sortから呼び出す
  printf("%d\n", cnt);     // comp_が呼んだ合計回数を出力

  free(array);  // 配列に割り当てられた動的メモリを解放
  return 0;     // main関数の終了

}



int sel_sort(int *array, int N) {
  int comp_count = 0;  // 比較した回数の初期値を0に設定
  int i=0; //配列の、比較する1つ目の要素番号
  int j=N-1; //配列の、比較する2つ目の要素番号
  int min; //仮の最小値の要素番号



  for (i = 0; i < N-1; i++) {
    min=i; //array[i]を仮の最小値として定義する
    for (j = i + 1; j < N; j++) {
     comp_count += 1; //比較回数をカウント
     if (comp_(array,j,min)==1) {
       min=j;  //array[j]がarray[min]より小さい場合array[j]を新たに仮の最小値とする
     }
    }
    if (min!=i) {  //仮の最小値として定義したarray[i]よりも小さい値array[min]があった場合
    func_swap_(array,i,min);   // 最小値と先頭要素を交換
    print_array_(array, N);           // 入れ替えられた後の配列を出力
  }
}

  return comp_count;  // 比較回数を返す
}
