#include <stdio.h>
#include <stdlib.h>

void func_swap_(  // 配列内の2つの要素を交換し、操作をSTDOUTに出力
    int* const array,  // 要素が交換される配列
    const int pos_a,   // 1番目の交換対象の要素番号
    const int pos_b    // 2番目の交換対象の要素番号
) {
  int tmp = array[pos_a];       // array[pos_a]の値をtmpに退避
  array[pos_a] = array[pos_b];  // array[pos_a]にarray[pos_b]を代入
  array[pos_b] = tmp;           // 退避したarray[pos_a]の値をarray[pos_b]に代入
  printf("SWAP(%2d,%2d)", pos_a, pos_b);
}


int comp_(             // 配列内の2つの要素を比較する関数
    int* const array,  // 要素の比較を行う配列
    const int pos_a,   // 1つ目の比較対象の要素番号
    const int pos_b    // 2つ目の比較対象の要素番号
) {
  if (array[pos_a] < array[pos_b]) return 1;  // 要素の大小を比較して2つ目が大きい場合1を返す
   return 0;                                   // 要素の大小を比較して1つ目が大きい場合0を返す
 }


void print_array_(           // 配列をSTDOUTに表示する関数
    const int* const array,  // 表示する配列
    const int N              // 配列の要素数
) {
  for (int i = 0; i < N; ++i) {
    printf(" %2d", array[i]);
  }
  printf("\n");
}


int* func_mallocation_(  // 配列の動的メモリ確保をおこなう関数
    const int N          // 配列の要素数
) {
  int* data = (int*)malloc(N * sizeof(int));  // 変数dataを要素数Nに応じたint型のメモリ数とする
  if (data == NULL) { // メモリ確保に失敗した際のエラー処理
    printf("Can not allocate memory. 'data' is NULL.\n");
    exit(EXIT_FAILURE);
  }
  return data;  // 確保した配列のポインタを戻り値として返す
}

int* func_copy_val_(
    int* const array,
    const int pos_a,
    const int pos_b
) {
  array[pos_b] = array[pos_a];
  return array;
}

void print_array_range_(
  const int* const array,
  const int N,
  const int p, const int r) {
  int ri = 0;
  for (; ri < N; ++ri) {
    if (ri < p || r < ri) {
      printf(" **");
    } else {
      printf(" %2d", array[ri]);
    }
  }
  printf("\n");
}


// int reverse_array(int*, int);
//
// int main() {
//   int N;       // 入力配列の要素数
//   scanf("%d", &N);               // STDINから要素数を受け取る
//   int* array = func_mallocation_(N);  // 配列に動的メモリを割り当てる
//   for (int i = 0; i < N; i++)
//     scanf("%d", &(array[i]));  // STDINから配列要素を受け取る
//   printf("INIT:::::::");
//   print_array_(array, N);             // 配列の初期状態をSTDOUTに出力
//
//   int cnt = reverse_array(array, N);  // 入力配列を逆順
//   printf("DONE:::::::");
//   print_array_(array, N);  // 配列の最終状態をSTDOUTに出力
//
//   printf("%d\n", cnt);     // comp_が呼んだ合計回数を出力
//
//   free(array);  // 配列に割り当てられた動的メモリを解放
//   return 0;     // main関数の終了
// }
//
// int reverse_array(  // 配列を逆順に並べ替える関数
//     int* array,     //　配列を読み込み
//     int N           // 要素数を読み込み
// ) {
//   int pos_a = 0;       // 配列の1つ目の値をpos_aとして定義
//   int pos_b = N - 1;   // 配列の最後の値をpos_bとして定義
//   int comp_count = 0;  // 比較した回数の初期値を0に設定
//
//   while (pos_a < pos_b) {  //配列の中間地点までarray[pos_a],array[pos_b]を比較
//     comp_count += 2;       // 大小関係の比較回数
//
//     if ((comp_(array, pos_a, pos_b) +   // array[pos_a]がarray[pos_b]より小さいときに1が返ってくる
//           comp_(array, pos_b, pos_a))	// array[pos_b]がarray[pos_a]より小さいときに1が返ってくる
//     == 1) {   			// 上記2パターンのいずれかによって比較する二つの要素が等しくない場合
//       func_swap_(array, pos_a, pos_b);  // 入れ替えられた要素番号を出力
//       print_array_(array, N);           // 入れ替えられた後の配列を出力
//     }
//     pos_a++;  // 1つ次の要素で比較対象にする
//     pos_b--;  // 1つの前の要素を比較対象にする
//   }
//   return comp_count;  // 比較した回数を返す
// }
