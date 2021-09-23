//
//  .c
//  c32.c
//
//  Levenshtein distance_Recursion_Memorization
//
//  Created by Shuma Matsuzaki
//  2020/06/26
//  Copyright© Shuma Matszuaki 2020.  All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "func.c"

int count = 0;     //メモ化なしの再帰関数の呼び出し回数
int count_memo = 0;    //メモ化ありの再帰関数の呼び出し回数

int delta(char *, int, char *, int);  // 関数deltaのプロトタイプ宣言
int ld(char *, int , char *Y, int);  // 関数ldのプロトタイプ宣言
int ldmemo(char *, int , char *, int , int** );  //関数ldmemoのプロトタイプ宣言

int main() {
  int N = 21;                      // 文字列のサイズNを指定
  char* data_x = read_string_(N);  // 1つ目の文字列をdata_xに格納
  char* data_y = read_string_(N);  // 2つ目の文字列をdata_yに格納
  int len_x = count_len_(data_x);  // data_xに格納した文字列の長さを取得
  int len_y = count_len_(data_y);  // data_yに格納した文字列の長さを取得
  int** memo = func_mallocation_2d_(len_x+1, len_y+1);  //2次元配列memoの動的確保

  //配列メモの初期状態として-1を代入しておく
  for (int j = 0; j < len_y+1; j++) {
    for (int i = 0; i < len_x+1; i++) {
      memo[i][j]=-1;
    }
  }

  int lev = ld(data_x, len_x, data_y, len_y);  // ld関数を実行し、levに返り値である編集距離を代入
  int lev_memo = ldmemo(data_x, len_x, data_y, len_y, memo);  // ldmemo関数を実行し、levmに返り値である編集距離を代入

  printf("%s %d\n", data_x, len_x);  // data_xに格納した文字列とその長さをSTDOUTに出力
  printf("%s %d\n", data_y, len_y);  // data_yに格納した文字列とその長さをSTDOUTに出力
  printf("%d %d\n",lev,count);//メモ化なしでの編集距離と呼び出し回数の出力
  printf("%d %d\n",lev_memo,count_memo);//メモ化なしでの編集距離と呼び出し回数の出力

  func_free_2d_(memo,len_x);// 動的に確保された二次元配列memoの開放
  free(data_x);  // 動的に確保された配列data_xの開放
  free(data_y);  // 動的に確保された配列data_yの開放

  return 0;      // プログラムの正常終了
}

/////////////////////////////////////////////

int delta(char *X, int a, char *Y, int b) {//文字列Xの位置aの文字と文字列Yの位置bの文字が等しい場合に0，違う場合に1を返す関数
  if(X[a-1]==Y[b-1])return 0;//文字列Xの位置aの文字と文字列Yの位置bの文字が等しい場合に0，違う場合に1を返す
  else{
    return 1;
  }
}

//////////////////////////////////////////////

int ld(char *X, int m, char *Y, int n) {//編集距離を返す再帰関数

  int Lev;//編集距離Levの定義

  if (m==0||n==0) {//mまたはnが0であるとき
    Lev = vmax_(m,n);//mとnのうち大きい方を編集距離に採用
    // printf("last\n");
  }
  else{//mもnも0でない時
    //関数ldを再帰的に呼び出すことで漸化式を用いて編集距離を求める
    Lev = vmin3_( ld(X,m-1,Y,n-1) + delta(X,m,Y,n) , ld(X,m-1,Y,n)+1, ld(X,m,Y,n-1)+1);
  }
  count++;//再起呼び出し回数のカウント
  return Lev;//編集距離を返す

}

///////////////////////////////////////////////

int ldmemo(char *X, int m, char *Y, int n, int** memo){//メモ化を利用した場合の編集距離を返す再帰関数

  int Lev_memo=0;//編集距離Lev_memoの定義

  if(memo[m][n]!=-1){  //求める編集距離が既にメモされている場合それを採用
      Lev_memo=memo[m][n];
  }
  else if(m>=0 && n>=0){  //そうでない場合再帰によって編集距離Lev_memoを求めつつメモに記録
    if (m==0||n==0) {//mまたはnが0であるとき
      Lev_memo = vmax_(m,n);//mとnのうち大きい方を編集距離に採用
      memo[m][n]=Lev_memo;
    }
    else{//mもnも0でない時

      //2次元配列memoに必要な要素を記録
      memo[m-1][n-1]=ldmemo(X,m-1,Y,n-1,memo);
      memo[m-1][n]=ldmemo(X,m-1,Y,n,memo);
      memo[m][n-1]=ldmemo(X,m,Y,n-1,memo);

      count_memo++;//再起呼び出し回数のカウント

      //関数ldmemoを再帰的に呼び出すことで漸化式を用いて編集距離を求める
      Lev_memo = vmin3_( ldmemo(X,m-1,Y,n-1,memo) + delta(X,m,Y,n) , ldmemo(X,m-1,Y,n,memo)+1, ldmemo(X,m,Y,n-1,memo)+1);
    }
  }
  return Lev_memo;//編集距離を返す
}
