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

void func_free_2d_(int **array_2d, int len_x){
  int i;
  for(i = 0; i < len_x; ++i) free(array_2d[i]);
  free(array_2d);
}

//////////
int find_matching(char* X, int M, char* Y, int N, char* buf);
void sort_buf(char* buf, int N);
