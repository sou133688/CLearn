//
//  .c
//  c31.c
//
//  Levenshtein distance_Recursion
//
//  Created by Shuma Matsuzaki
//  2020/06/26
//  Copyright© Shuma Matszuaki 2020.  All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "c30.c"

int delta(char *X, int a, char *Y, int b);  // 関数deltaのプロトタイプ宣言
int ld(char *X, int m, char *Y, int n);     // 関数ldのプロトタイプ宣言


int main() {
  int N = 21;                      // 文字列のサイズNを指定
  char* data_x = read_string_(N);  // 1つ目の文字列をdata_xに格納
  char* data_y = read_string_(N);  // 2つ目の文字列をdata_yに格納
  int len_x = count_len_(data_x);  // data_xに格納した文字列の長さを取得
  int len_y = count_len_(data_y);  // data_yに格納した文字列の長さを取得

  int cnt = ld(data_x, len_x, data_y, len_y);  // ld関数を実行し、cntに返り値である編集距離を代入

  printf("%s %d\n", data_x, len_x);  // data_xに格納した文字列とその長さをSTDOUTに出力
  printf("%s %d\n", data_y, len_y);  // data_yに格納した文字列とその長さをSTDOUTに出力
  printf("%d\n",cnt );//編集距離の出力

  free(data_x);  // 動的に確保された配列data_xの開放
  free(data_y);  // 動的に確保された配列data_yの開放

  return 0;      // プログラムの正常終了
}



int delta(char *X, int a, char *Y, int b) {//文字列Xの位置aの文字と文字列Yの位置bの文字が等しい場合に0，違う場合に1を返す関数
  if(X[a-1]==Y[b-1])return 0;//文字列Xの位置aの文字と文字列Yの位置bの文字が等しい場合に0，違う場合に1を返す
  else{
    return 1;
  }
}


int ld(char *X, int m, char *Y, int n) {//編集距離を返す再帰関数

int Lev;//編集距離Levの定義

if (m==0||n==0) {//mまたはnが0であるとき
  Lev = vmax_(m,n);//mとnのうち大きい方を編集距離に採用
  // printf("last\n");
}
else{//mもnも0でない時
  Lev = vmin3_( ld(X,m-1,Y,n-1) + delta(X,m,Y,n) , ld(X,m-1,Y,n)+1, ld(X,m,Y,n-1)+1);
  //関数ldを再帰的に呼び出すことで漸化式を用いて編集距離を求める
}

  return Lev;//編集距離を返す

}
