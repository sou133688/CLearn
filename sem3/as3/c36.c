#include <stdio.h>
#include <stdlib.h>

#include "ppa_extra_h/p3_header.h"

void print_matrix(int N, int** data);
int rec(int N, int** data);
int check_invalid(int N, int** data);

int main() {
  int N = 9;        //文字列のサイズNを指定
  int** data = func_mallocation_2d_(N, N); //2次元配列dptの動的確保

  for (int i = 0; i < N; i++) {    //9×9のナンプレデータ入力
    for (int j = 0; j < N; j++) {
      scanf("%d", &(data[i][j]));
    }
  }


  // 入力データの表示
  print_matrix(N,data);
  if (check_invalid(N,data)==1) {//エラーがある場合
    printf("### INVALID INPUT\n");
    return 1;
  }

  =rec(N,data);

  if () {
    printf("### NOT FOUND\n");
  }else{
    printf("### FOUND\n");
    print_matrix(N,data);
  }



  func_free_2d_(data, N);
  return 0;               //
}


void print_matrix(int N, int** data){//ナンプレの盤面を表示する関数

  int i,j;

  printf("  ");
  for (j = 0; j < 9; j++) {
    printf(" #%d", j+1);
  }
  printf("\n");

  for (i = 0; i < 9; i++) {
      printf("#%d", i+1);

      for (j = 0; j < 9; j++) {
        printf("  %d",data[i][j] );
      }

      printf("\n");
  }

}

int rec(int N, int** data){//ナンプレを解く関数(再帰)



  return ;

}

int check_invalid(int N, int** data){
  int i,j;

  for (j = 0; j < 9; j++) {
    for (i = 0; i < count; i++) {

    }
  }

}
