#include <stdio.h>
#include <stdlib.h>

//プロトタイプ宣言
int vmax_(int x, int y) { return x > y ? x : y; }                  // 2つの値のうち大きい方の値を取得する関数
int vmax3_(int a, int b, int c) { return vmax_(a, vmax_(b, c)); }  // vmax_関数を用いて3つの値の中で最も大きい値を取得する関数
int vmin_(int x, int y) { return x < y ? x : y; }                  // 2つの値のうち小さい方の値を取得する関数
int vmin3_(int a, int b, int c) { return vmin_(a, vmin_(b, c)); }  // vmin_関数を用いて3つの値の中で最も小さいの値を取得する関数

void zeros_(     // 文字列用の配列を\0で初期化する関数
    char* data,  // 文字列を格納する配列
    int N        // 文字列の長さ
) {
  for (int i = 0; i < N; ++i) {
    data[i] = '\0';  // 配列のi番目の要素を\0で初期化
  }
}

char* func_mallocation_char_(  // 文字列用の配列を確保する関数
    const int len_x            // 文字列の長さ
) {
  char* data  = (char*)malloc( len_x * sizeof(char));  // 配列に動的メモリを割り当てる
  if (data == NULL) {                                  // メモリ確保に失敗した際のエラー処理
    printf("Can not allocate memory. 'data' is NULL.\n");
    exit(EXIT_FAILURE);  // メモリ確保に失敗したら、プログラムを終了
  }
  zeros_(data, len_x);   // 配列dataを関数zeros_で初期化
  return data;       // 配列dataの先頭のポインタを返す
}

char* read_string_(  // 文字列用のメモリ確保と、標準入力からの文字列読み込みを行う関数
    const int N      // 文字列の長さ
) {
  char* data = func_mallocation_char_(N);
  scanf("%s", data);          // 文字列を読み込む
  if (data[N - 1] != '\0') {  // 文字列がN以上の場合のエラー処理
    printf("Reading invalid string\n");
    exit(1);  // プログラムを終了
  }
  return data;  // 配列dataの先頭のポインタを返す
}

int count_len_(        // 文字列の長さを計算する関数
    const char* array  // 文字列用の配列
) {
  int ri = 0;
  while (array[ri] != '\0') {  // 文字列の最後の文字の後につく'\0'が検出されるまでカウンターriで数える
    ri++;
  }
  return ri;  // 文字列の長さriを返す
}


int** func_mallocation_2d_(const int len_x, const int len_y){
  int** array_2d = (int **)malloc(sizeof(int *) * len_x);
    if(array_2d == NULL){
        printf("Can not allocate memory. 'array_2d' is NULL.\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < len_x; ++i){
        array_2d[i] = (int*)malloc(sizeof(int) * len_y);
        if(array_2d[i] == NULL){
            printf("Can not allocate memory. 'array_2d[i]' is NULL.\n");
            exit(EXIT_FAILURE);
        }
    }
    return array_2d;
}


//////////
int find_matching(char* X, int M, char* Y, int N, char* buf);
void sort_buf(char* buf, int N);


// int main() {
//   int N = 21;                      // 文字列の(NULLを含めた)サイズNを指定
//   char* data_x = read_string_(N);  // 1つ目の文字列をdata_xに格納
//   char* data_y = read_string_(N);  // 2つ目の文字列をdata_yに格納
//   int len_x = count_len_(data_x);  // data_xに格納した文字列の長さを取得
//   int len_y = count_len_(data_y);  // data_yに格納した文字列の長さを取得
//   char* buf =  func_mallocation_char_(len_x * len_y);   // マッチングした文字列を保存する配列bufの宣言
//
//   int cnt = find_matching(data_x, len_x, data_y, len_y, buf);  // find_matching関数を実行
//   sort_buf(buf, cnt);                                          // sort_buf関数を実行
//
//   printf("%s %d\n", data_x, len_x);  // data_xに格納した文字列とその長さをSTDOUTに出力
//   printf("%s %d\n", data_y, len_y);  // data_yに格納した文字列とその長さをSTDOUTに出力
//
//   char prev = '\0';                // 変数prevを\0で初期化
//   for (int i = 0; i < cnt; ++i) {  // i=0からi=cnt-1まで繰り返す
//     if (prev == buf[i]) continue;  // prev == buf[i]ならばスキップ
//     printf("%c\n", buf[i]);        // buf[i]を出力
//     prev = buf[i];                 // prevにbuf[i]を代入
//   }
//   free(data_x);  // 動的に確保された配列data_xの開放
//   free(data_y);  // 動的に確保された配列data_yの開放
//   return 0;      // プログラムの正常終了
// }
//
//
// int find_matching(  // 文字列Xと文字列Yとで文字が一致した回数をカウントする関数
//     char* X,        // 文字列X
//     int len_x,      // 文字列Xの長さ
//     char* Y,        // 文字列Y
//     int len_y,      // 文字列Yの長さ
//     char* buf       // マッチした文字を保存する配列
// ) {
//   int cnt = 0;  // 一致回数の定義と初期値を0に設定
//   for (int i = 0; i < len_x; ++i) {
//     for (int j = 0; j < len_y; ++j) {
//       if (X[i] == Y[j]) {  // 文字列Xと文字列Yとで一致する文字があった場合
//         buf[cnt] = X[i];   // 一致した文字を配列bufにコピー
//         cnt++;             // 一致した回数をカウント
//       }
//     }
//   }
//   return cnt;  // 一致回数を返す
// }


void sort_buf(  // 文字列Xと文字列Yとで一致した文字の配列bufを昇順ソートする関数
    char* buf,  // マッチした文字を保存されている配列
    int N       // 文字列のサイズ
) {
  for (int i = 0; i < N; ++i) {
    for (int j = 1; j < N - i; ++j) {
      if (buf[j] < buf[j - 1]) {   // ASCIIコードに従い，文字に対応する整数の大小を比較（問題1-5のASCIIコードの説明を参照せよ）
        // 手前の文字に対応する整数が一つ後ろの文字に対応する整数より大きい場合に入れ替えを行なう
        char tmp = buf[j];    // 後ろの文字をtmpに一時保管
        buf[j] = buf[j - 1];  // 手前の文字を後ろにコピー
        buf[j - 1] = tmp;     // tmpに保管されていた後ろの文字を手前に代入
      }
    }
  }
}
