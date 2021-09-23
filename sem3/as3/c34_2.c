//
//  .c
//  c34.c
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

//関数のプロトタイプ宣言
int delta(char *X, int a, char *Y, int b);
int ld_dp(char *X, int m, char *Y, int n, int **dpt);
void show_matrix(char *X, int m, char *Y, int n, int **dpt);
int get_length(char *X, int m, char *Y, int n, int **dpt);
void get_ops(char *X, int m, char *Y, int n, int **dpt,char *seq_x, char *seq_y, char *ops);


int main() {
  int N = 21;                      // 文字列のサイズNを指定
  char* data_x = read_string_(N);  // 1つ目の文字列をdata_xに格納
  char* data_y = read_string_(N);  // 2つ目の文字列をdata_yに格納
  int len_x = count_len_(data_x);  // data_xに格納した文字列の長さを取得
  int len_y = count_len_(data_y);  // data_yに格納した文字列の長さを取得

  int **dpt = func_mallocation_2d_(len_x+2, len_y+2);//2次元配列dptの動的確保

  ld_dp(data_x, len_x, data_y, len_y, dpt);  // ld関数を実行し、levに返り値である編集距離を代入

  // printf("%s %d\n", data_x, len_x);  // data_xに格納した文字列とその長さをSTDOUTに出力
  // printf("%s %d\n", data_y, len_y);  // data_yに格納した文字列とその長さをSTDOUTに出力
  // printf("%d\n",lev);//メモ化なしでの編集距離と呼び出し回数の出力

  show_matrix(data_x, len_x, data_y, len_y, dpt);

  int length = get_length(data_x, len_x, data_y, len_y, dpt);

  char* seq_x=func_mallocation_char_(length);
  char* seq_y=func_mallocation_char_(length);
  char* ops=func_mallocation_char_(length);

  get_ops(data_x, len_x, data_y, len_y, dpt, seq_x, seq_y, ops);
  printf("%s\n%s\n%s\n",seq_x, seq_y, ops);

  func_free_2d_(dpt,len_x+2);//動的に確保された配列dptの開放
  free(ops);     // ???
  free(seq_x);   // ???
  free(seq_y);
  free(data_x);  // 動的に確保された配列data_xの開放
  free(data_y);  // 動的に確保された配列data_yの開放

  return 0;      // プログラムの正常終了
}

//////////////////////////////////////////////////////////////////

void show_matrix(char *X, int m, char *Y, int n, int **dpt){
  int i,j;//iが縦(行数)jが横（列数）


  //1行目
  printf("    ");
  for (j = 0; j < n+1; j++) {
    printf("  %c", Y[j]);
  }
  printf("\n ");

  //2行目
  for (j = 0; j < n+1; j++) {
    printf(" %2d",dpt[0][j]);
  }
  printf("\n");

  //3行目以降
  for (i = 1; i < m+1; i++) {
    printf("%c",X[i-1]);//文字列X
    for (j = 0; j < n+1; j++) {
      printf(" %2d",dpt[i][j]);
    }
    printf("\n");
  }

}

//////////////////////////////////////////////////////////////////

int get_length(char *X, int m, char *Y, int n, int **dpt){

  int i=m,j=n,len_ops=0,Min;

  while (i>0||j>0) {

    if (i==0) {//文字列Xのみ数え切った場合
        j--;
        len_ops++;
    }else if(j==0){//文字列Yのみ数え切った場合
        i--;
        len_ops++;
    }else{

        Min=vmin3_(dpt[i-1][j-1]+delta(X,i,Y,j), dpt[i-1][j]+1, dpt[i][j-1]+1);

        if (Min==dpt[i-1][j-1]+delta(X,i,Y,j)) {//コピーまたは置換
          i--;
          j--;
        }else if(Min==dpt[i-1][j]+1){//削除
          i--;
        }else{//挿入
          j--;
        }
        len_ops++;

    }
  }
  return len_ops;

}

int delta(char *X, int a, char *Y, int b){
   if(X[a-1]==Y[b-1])return 0;//文字列Xの位置aの文字と文字列Yの位置bの文字が等しい場合に0，違う場合に1を返す
 else{
    return 1;
  }
}
//////////////////////////////////////////////////////////////////

void get_ops(char *X, int m, char *Y, int n, int **dpt ,char *seq_x, char *seq_y, char *ops){

    int k=0;
    int i=m;
    int j=n;
    int Min;

    // int flx=0,fly=0;

    while (1) {
      printf("seq_x[%d]=%c\n",k-1, seq_x[k-1]);  // seq_xに格納した文字列を出力
      printf("seq_y[%d]=%c\n",k-1, seq_y[k-1]);  // seq_yに格納した文字列を出力
      printf("ops[%d]=%c\n", k-1,ops[k-1]);  // opsに格納した文字列を出力

      printf("round%d\n", k);
      printf("X[%d]=%c\nY[%d]=%c\n",i,X[i],j,Y[j] );

        if (i==0&&j==0) {

          break;
        }
        if (i==0) {//文字列Xのみ数え切った場合
            //挿入操作
            while (j!=0) {
              ops[k]='I';
              seq_x[k]=' ';
              seq_y[k]=Y[j-1];

              k++;
              j--;
            }
            break;
        }
        if(j==0){
          //削除操作
            while (i!=0) {
              ops[k]='D';
              seq_x[k]=X[i-1];
              seq_y[k]=' ';

              i--;
              k++;
            }
            break;



        }else{//文字列X,Y共に数え切っていない場合
        Min=vmin3_(dpt[i-1][j-1], dpt[i-1][j], dpt[i][j-1]);
        if (Min==dpt[i-1][j-1]) {//行列での左上の要素が最小の時、コピーまたは置換
                  if (delta(X,i,Y,j)==0) {//コピー
                    ops[k]='=';
                    seq_x[k]=X[i-1];
                    seq_y[k]=Y[j-1];


                  }
                  else{//置換
                    ops[k]='R';
                    seq_x[k]=X[i-1];
                    seq_y[k]=Y[j-1];


                  }
                  k++;
                  i--;
                  j--;
                  continue;
        }
        else if(Min==dpt[i][j-1]){//行列での左の要素が最小の時、挿入
                  ops[k]='I';
                  seq_x[k]=' ';
                  seq_y[k]=Y[j-1];
                  j--;
                  k++;
                  continue;
        }
        else{//行列での上の要素が最小の時、削除
              ops[k]='D';
              seq_x[k]=X[i-1];
              seq_y[k]=' ';
              i--;
              k++;
              continue;
        }

        }



}
    //反転させる
int l = k-1;
for (i = 0; i <= (k-1)/2; ++i) {
  int temp_ops=ops[i];
  int temp_x=seq_x[i];
  int temp_y=seq_y[i];

  ops[i]=ops[l];
  seq_x[i]=seq_x[l];
  seq_y[i]=seq_y[l];
  ops[l]=temp_ops;

  seq_x[l]=temp_x;
  seq_y[l]=temp_y;
  l--;
}

}



///////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////

int ld_dp(char *X, int m, char *Y, int n, int **dpt){//編集距離を計算する関数
// mは行数,nは列数
  int i,j;//行カウンタiと列カウンタj

  for (j = 0; j < n+2; j++) {//横
    dpt[0][j]=j;
  }
  for (i = 0; i < m+2; i++) {//縦
    dpt[i][0]=i;
  }

  for (j = 1; j < n+2; j++) {
      for (i = 1; i < m+2; i++) {
      dpt[i][j] = vmin3_( dpt[i-1][j-1]+delta(X,i,Y,j), dpt[i-1][j]+1, dpt[i][j-1]+1);
    }
  }

  int lev=dpt[m][n];

  return lev;//編集距離を返す
}
