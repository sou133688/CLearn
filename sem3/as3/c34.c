//
//  .c
//  c34.c
//
//  Levenshtein_Distance_Dynamic_Programming_Process
//
//  Created by Shuma Matsuzaki
//  2020/07/07
//  Copyright© Shuma Matszuaki 2020.  All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "func.c"

//各関数のプロトタイプ宣言
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

  ld_dp(data_x, len_x, data_y, len_y, dpt);  //関数ldの実行

  show_matrix(data_x, len_x, data_y, len_y, dpt);//動的計画法による配列dptを出力

  int length = get_length(data_x, len_x, data_y, len_y, dpt);//文字列opsの大きさを求める

  // 文字列seq_x,seq_y,opsを動的にメモリ確保する
  char* seq_x=func_mallocation_char_(length);
  char* seq_y=func_mallocation_char_(length);
  char* ops=func_mallocation_char_(length);

  get_ops(data_x, len_x, data_y, len_y, dpt, seq_x, seq_y, ops);//編集過程を求める関数get_opsを呼び出す

  printf("%s\n%s\n%s\n",seq_x, seq_y, ops);//編集過程として文字列seq_x,seq_y,opsを出力

  //動的にメモリ確保した行列dptと配列data_x,data_yを解放
  func_free_2d_(dpt,len_x+2);
  free(data_x);
  free(data_y);
  //動的にメモリ確保した文字列seq_x,seq_y,opsを解放
  free(seq_x);
  free(seq_y);
  free(ops);

  return 0;      // プログラムの正常終了
}

//////////////////////////////////////////////////////////////////

void show_matrix(//動的計画法用のテーブルdptを表示する関数
  char *X, int m, char *Y, int n, int **dpt//文字列X,Yとそれぞれの長さm,n、および動的計画法用のテーブルdptを引数にとる
  ){
  int i,j;//行カウンターi,列カウンターjの定義
  //1行目の出力
  printf("    ");
  for (j = 0; j < n+1; j++) {
    printf("  %c", Y[j]);//文字列Yを表示
  }
  printf("\n ");
  //2行目の出力
  for (j = 0; j < n+1; j++) {
    printf(" %2d",dpt[0][j]);//dptの1行目(i=0)を表示
  }
  printf("\n");

  //3行目以降の出力
  for (i = 1; i < m+1; i++) {//dptの2行目からm+1行目まで(i=1からi=mまで)を考える
    printf("%c",X[i-1]);//文字列Xを縦書きのように表示
    for (j = 0; j < n+1; j++) {
      printf(" %2d",dpt[i][j]);//dptのi行目を表示
    }
    printf("\n");
  }

}

//////////////////////////////////////////////////////////////////

int get_length(//opsの長さを取得する関数
  char *X, int m, char *Y, int n, int **dpt//文字列X,Yとそれぞれの長さm,n、および動的計画法用のテーブルdptを引数にとる
){

  int i=m,j=n,len_ops=0,Min;//行カウンターi(初期値はm),列カウンターj(初期値はn),opsの長さlen_ops,dpt[i][j]の左上・上・左の3つのうちの最小値Minを定義

  while (i>0||j>0) {//dptの最も左上(dpt[0][0])に達するまで

    if (i==0) {//文字列Xのみ数え切った場合
        j--;//列カウンターを一つ減らす（左に移動）
        len_ops++;//opsの長さをカウント
    }else if(j==0){//文字列Yのみ数え切った場合
        i--;//行カウンターを一つ減らす（上に移動）
        len_ops++;//opsの長さをカウント
    }else{
        Min=vmin3_(dpt[i-1][j-1]+delta(X,i,Y,j), dpt[i-1][j]+1, dpt[i][j-1]+1);//dpt[i][j]の左上・上・左の3つのうちの最小値をMinに代入

        if (Min==dpt[i-1][j-1]+delta(X,i,Y,j)) {//左上が最小の時、コピーまたは置換の編集操作を行なう
          i--;
          j--;//行カウンター,列カウンターをそれぞれ一つ減らす（左上に移動）
        }else if(Min==dpt[i-1][j]+1){//上が最小の時、削除の編集操作を行なう削除
          i--;//行カウンターを一つ減らす（上に移動）
        }else{//左が最小の時、挿入の編集操作を行なう
          j--;//列カウンターを一つ減らす（左に移動）
        }
        len_ops++;//opsの長さをカウント
    }
  }
  return len_ops;//opsの長さを返す

}

//////////////////////////////////////////////////////////////////

int delta(//指定の文字列の要素が一致するかを判定する関数delta
  char *X, int a, char *Y, int b){//文字列X,Yとそれぞれのインデックスa,bを引数にとる
   if(X[a-1]==Y[b-1])return 0;//文字列Xの位置aの文字と文字列Yの位置bの文字が等しい場合に0，違う場合に1を返す
 else{
    return 1;
  }
}
//////////////////////////////////////////////////////////////////

void get_ops(
  char *X, int m, char *Y, int n, int **dpt ,char *seq_x, char *seq_y, char *ops){//文字列X,Yとそれぞれの長さm,n、および動的計画法用のテーブルdpt、編集過程の文字列seq_x,seq_y,opsを引数にとる

    int k=0,i=m,j=n,Min;//編集過程文字列のカウンタk(初期値0),行カウンターi(初期値はm),列カウンターj(初期値はn),dpt[i][j]の左上・上・左の3つのうちの最小値Minを定義

    while (1) {
        if (i==0&&j==0) {//dptの最も左上(dpt[0][0])に達した時while文から抜ける
          break;
        }

        if (i==0) {//文字列Xのみ数え切った場合
            while (j!=0) {//列カウンタが0に達するまで
              //挿入操作を行ない、seq_xにスペース、seq_yに該当する文字列Yの要素を代入
              ops[k]='I';
              seq_x[k]=' ';
              seq_y[k]=Y[j-1];
              // 編集過程文字列のカウンタkを1つ増やし,行カウンターiを1つ減らす
              j--;
              k++;
            }
            break;//dptの最も左上(dpt[0][0])に達した時while文から抜ける
        }

        if(j==0){//文字列Yのみ数え切った場合
            while (i!=0) {//行カウンタが0に達するまで
              //削除操作を行ない、seq_yにスペース、seq_xに該当する文字列Xの要素を代入
              ops[k]='D';
              seq_x[k]=X[i-1];
              seq_y[k]=' ';
            　// 編集過程文字列のカウンタkを1つ増やし,列カウンターiを1つ減らす
              i--;
              k++;
            }
            break;//dptの最も左上(dpt[0][0])に達した時while文から抜ける
        }

        else{//文字列X,Y共に数え切っていない場合

            Min=vmin3_(dpt[i-1][j-1], dpt[i-1][j], dpt[i][j-1]);//dpt[i][j]の左上・上・左の3つのうちの最小値をMinに代入

            if (Min==dpt[i-1][j-1]) {//行列での左上の要素が最小の時、コピーまたは置換
                  if (delta(X,i,Y,j)==0){//X[i]とY[j]の文字が一致する時
                    //コピー操作を行ない、seq_xに該当する文字列X、seq_yに該当する文字列Yの要素を代入
                    ops[k]='=';
                    seq_x[k]=X[i-1];
                    seq_y[k]=Y[j-1];

                  }
                  else{//X[i]とY[j]の文字が一致しない時
                    //置換操作を行ない、seq_x該当する文字列X、seq_yに該当する文字列Yの要素を代入
                    ops[k]='R';
                    seq_x[k]=X[i-1];
                    seq_y[k]=Y[j-1];

                  }
                  //編集過程文字列のカウンタkを1つ増やし,列カウンターiと行カウンターjを1つ減らす
                  k++;
                  i--;
                  j--;
                  continue;
            }
            else if(Min==dpt[i][j-1]){//行列での左の要素が最小の時
                  //挿入操作を行ない、seq_xにスペース、seq_yに該当する文字列Yの要素を代入
                  ops[k]='I';
                  seq_x[k]=' ';
                  seq_y[k]=Y[j-1];
                  //編集過程文字列のカウンタkを1つ増やし,行カウンターjを1つ減らす
                  j--;
                  k++;
                  continue;
            }
            else{//行列での上の要素が最小の時
                  //削除操作を行ない、seq_yにスペース、seq_xに該当する文字列Xの要素を代入
                  ops[k]='D';
                  seq_x[k]=X[i-1];
                  seq_y[k]=' ';
                  //編集過程文字列のカウンタkを1つ増やし,列カウンターiを1つ減らす
                  i--;
                  k++;
                  continue;
            }
        }
      }

      //文字列seq_x,seq_y,opsを反転させる
      int l = k-1;//文字列を入れ替えるためのインデックス
      for (i = 0; i <= (k-1)/2; ++i) {
            // ops,seq_x,seq_yのインデックス番号iとlの要素をそれぞれ入れ替える
            // ops,seq_x,seq_yのインデックス番号iをそれぞれtemp_に保存
            int temp_ops=ops[i];
            int temp_x=seq_x[i];
            int temp_y=seq_y[i];
            // ops,seq_x,seq_yそれぞれインデックス番号lからiにコピー
            ops[i]=ops[l];
            seq_x[i]=seq_x[l];
            seq_y[i]=seq_y[l];
            // ops,seq_x,seq_yそれぞれtemp_に一時保存していた値をインデックス番号lにコピー
            ops[l]=temp_ops;
            seq_x[l]=temp_x;
            seq_y[l]=temp_y;

            l--;
      }

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
