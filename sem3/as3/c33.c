//
//  .c
//  c33.c
//
//  Levenshtein_Distance_Dynamic_Programming
//
//  Created by Shuma Matsuzaki
//  2020/07/07
//  Copyright© Shuma Matszuaki 2020.  All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "func.c"

int delta(char *X, int a, char *Y, int b);  // 関数deltaのプロトタイプ宣言
int ld_dp(char *X, int m, char *Y, int n, int **dpt);     // 関数ldのプロトタイプ宣言

int main() {
  int N = 21;                      // 文字列のサイズNを指定
  char* data_x = read_string_(N);  // 1つ目の文字列をdata_xに格納
  char* data_y = read_string_(N);  // 2つ目の文字列をdata_yに格納
  int len_x = count_len_(data_x);  // data_xに格納した文字列の長さを取得
  int len_y = count_len_(data_y);  // data_yに格納した文字列の長さを取得

  int **dpt = func_mallocation_2d_(len_y+2, len_x+2);//2次元配列dptの動的確保

  int lev = ld_dp(data_x, len_x, data_y, len_y, dpt);  // 関数ldを実行し、levに返り値である編集距離を代入

  printf("%s %d\n", data_x, len_x);  // data_xに格納した文字列とその長さをSTDOUTに出力
  printf("%s %d\n", data_y, len_y);  // data_yに格納した文字列とその長さをSTDOUTに出力
  printf("%d\n",lev);//メモ化なしでの編集距離と呼び出し回数の出力

  //動的にメモリ確保した行列dptと配列data_x,data_yを解放
  func_free_2d_(dpt,len_y+2);
  free(data_x);
  free(data_y);

  return 0;      // プログラムの正常終了
}

///////////////////////////////////////////////////////////////////

int delta(char *X, int a, char *Y, int b) {//文字列Xの位置aの文字と文字列Yの位置bの文字が等しい場合に0，違う場合に1を返す関数
  //文字列Xの位置aの文字と文字列Yの位置bの文字が等しい場合に0，違う場合に1を返す
 if(X[a-1]==Y[b-1])return 0;
 else{return 1;}
 
}

///////////////////////////////////////////////////////////////////

int ld_dp(//編集距離を計算する関数
  char *X, int m, char *Y, int n, int **dpt//文字列X,Yとそれぞれの長さm,n、および動的計画法用のテーブルdptを引数にとる
){
  int i,j;//行カウンタ-iと列カウンタ-jの定義

  // 動的計画法用行列dptに操作を行なう
  for (j = 0; j < n+2; j++) {//1行目に列インデックスと同じ値を代入
    dpt[0][j]=j;
  }
  for (i = 0; i < m+2; i++) {//1列目に行インデックスと同じ値を代入
    dpt[i][0]=i;
  }

  for (j = 1; j < n+2; j++) {
      for (i = 1; i < m+2; i++) {
      //2行目からm行目、2列目からn行目まで
      dpt[i][j] = vmin3_( dpt[i-1][j-1]+delta(X,i,Y,j), dpt[i-1][j]+1, dpt[i][j-1]+1);//dpt[i][j]にその(左上の要素+(一致する場合0・一致しない場合1)),(上の要素+1),(左の要素+1)のうち最小の値をMinに代入
    }
  }

  int lev=dpt[m][n];//行列dptの右下の値が編集距離であるためlevに代入

  return lev;//編集距離を返す
}
