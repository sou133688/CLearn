//
//  .c
//  c35.c
//
//  Levenshtein_Distance_Dynamic_Programming_Matching
//
//  Created by Shuma Matsuzaki
//  2020/07/07
//  Copyright© Shuma Matszuaki 2020.  All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "func.c"

//各関数のプロトタイプ宣言
void show_table(int M1, int M2, int **K);
int ssk(char* X, int m, char* Y, int n, int **dp, int **sumdp);

////////////////////////////////////////////////////////////////////////////////

int main() {

  int N = 21;                      // 文字列のサイズNを指定
  char* data_x = read_string_(N);  // 1つ目の文字列をdata_xに格納
  char* data_y = read_string_(N);  // 2つ目の文字列をdata_yに格納
  int len_x = count_len_(data_x);  // data_xに格納した文字列の長さを取得
  int len_y = count_len_(data_y);  // data_yに格納した文字列の長さを取得

  printf("%s %d\n", data_x, len_x);  // data_xに格納した文字列とその長さをSTDOUTに出力
  printf("%s %d\n", data_y, len_y);  // data_yに格納した文字列とその長さをSTDOUTに出力

  //2次元配列dp,sumdpの動的確保
  int **dp = func_mallocation_2d_(len_x+1, len_y+1);
  int **sumdp = func_mallocation_2d_(len_x+1,len_y+1);

  int match = ssk(data_x, len_x, data_y, len_y, dp,sumdp);  // 関数sskを実行し、matchに返り値であるマッチ数を代入

  //二次元配列dpの出力
  printf("### dp\n");
  show_table(len_x+1, len_y+1, dp);

  //二次元配列sumdpの出力
  printf("### sumdp\n");
  show_table(len_x+1, len_y+1, sumdp);

  printf("%d\n",match);//マッチ数の出力

  func_free_2d_(dp,len_x+1 );//動的に確保された配列dpの開放
  func_free_2d_(sumdp, len_x+1);//動的に確保された配列sumdpの開放
  free(data_x);  //動的に確保された配列data_xの開放
  free(data_y);  //動的に確保された配列data_yの開放

  return 0;//プログラムの正常終了

}

////////////////////////////////////////////////////////////////////////////////

void show_table( int M1, int M2, int **K){//M1行M2列の行列Kを出力する関数

  for (int i = 0; i < M1; ++i) {
   printf("#");
    for (int j = 0; j < M2; ++j) {
      printf(" %3d", K[i][j]);
   }
   printf("\n");
  }

}
////////////////////////////////////////////////////////////////////////////////

int ssk(//match数の計算,テーブルdp・sumdpを計算する関数
  char* X, int m, char* Y, int n, int **dp, int **sumdp){//文字列X,Yとそれぞれの長さm,n、および動的計画法用のテーブルdp,sumdpを引数にとる

  int i,j,match=0;//行カウンターi,列カウンターj,マッチ数match(初期値0)の定義

  for (i = 1; i < m+1; ++i) {
    for (j = 1; j < n+1; ++j) {
      if (X[i-1]==Y[j-1]) {//X[i]とY[j]の文字が一致する時
        dp[i][j]=sumdp[i-1][j-1]+1;//漸化式にしたがってdpを更新
      }
      else{
        dp[i][j]=0;//漸化式にしたがってdpを更新
      }
      //sumdp[i][j]の左上,上,左とdp[i][j]によってsumdpを更新
      sumdp[i][j]=sumdp[i-1][j]+sumdp[i][j-1]-sumdp[i-1][j-1]+dp[i][j];
    }
  }

  for (i = 1; i < m+1; ++i) {
    for (j = 1; j < n+1; ++j) {
      //マッチ数の計算
      match+=dp[i][j];
    }
  }

  return match;//マッチ数を返す
}
