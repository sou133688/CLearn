#include <stdio.h>
#include <stdlib.h>
#include "c20.c"

int merge_sort(int *, int , int , int );
void merge(int *, int , int , int , int );


void print_array_range_(
  const int* const array,
  const int N,
  const int p, const int r) {
  int ri = 0;

  print_array_(array,N);

  for (; ri < N; ++ri) {
    if (ri < p || r < ri) {
      printf(" **");
    } else {
      printf(" %2d", array[ri]);
    }
  }
  printf("\n");
}

int main() {
  printf("*****************************************************************************************\n" );

  int N;       // 入力配列の要素数
  scanf("%d", &N);               // STDINから要素数を受け取る
  int* array = func_mallocation_(2*N);  // 配列に動的メモリを割り当てる(作業スペースが必要なので2N)

  for (int i = 0; i < N; i++)
    scanf("%d", &(array[i]));  // STDINから配列要素を受け取る

  printf("INIT:::::::");
  print_array_(array, N);             // 配列の初期状態をSTDOUTに出力

  int cnt = merge_sort(array, N,0,N-1);  // 比較回数をins_sortから呼び出す

  printf("DONE:::::::");
  print_array_(array, N);  // 配列の最終状態をSTDOUTに出力


  // printf("%d\n", cnt);     // comp_が呼んだ合計回数を出力

  free(array);  // 配列に割り当てられた動的メモリを解放
  return 0;     // main関数の終了
}






int merge_sort(int* array, int N, int left, int right) {

    if (left >= right) { //配列の要素数が1つの時ソートの必要がないのでreturn
      return 0;
    }

    int mid = (left + right) / 2;//(配列の)中央の要素番号midをとる

    int n1=mid-left+1;//2分した時の左側の要素数としてn1を定義
    int n2=right-mid;//2分した時の右側の要素数としてn2を定義

    merge_sort(array, n1, left, mid);//2分した時の左側の配列を再起呼び出しによって要素数が1になるまで分割

    merge_sort(array, n2, mid + 1, right);//2分した時の右側の配列を再起呼び出しによって要素数が1になるまで分割


    printf("Merge\n" );

    merge(array, N, left, mid, right);//関数mergeによってarray[left]からarray[mid]までの配列とarray[mid+1]からarray[right]までの配列を統合

    printf("AfterMerge\n" );
    print_array_(array,8);
    print_array_range_(array,N,left,right);
    printf("--------------------------------------\n");

    return 0;
}




void merge(int* array, int N, int left, int mid, int right) {
    int N1, N2, i, j, k,iL,iR;

    printf("N:%d\n",N );

    N1 = mid - left+1;//
    N2 = right - mid;

    int comp_count=0;

    printf("N1:%d,N2:%d\n",N1,N2 );
    printf("left:%d//right:%d//mid:%d\n",left,right,mid );
    printf("array[4]=%d\n",array[4] );
    // int A_left[N1], A_right[N2];
    //
int* A_left = func_mallocation_(N1+1);//マージする飛騨入り側の配列をA_leftとして定義
int* A_right = func_mallocation_(N2+1);


    for (i = 0; i < N1; i++) {
      iL=left+i;
      A_left[i]  = array[iL];    printf("iL=%d:A_left[%d]=%d\n",iL,i,A_left[i] );
}
    for (i = 0; i < N2; i++) {
      iR=mid+i+1;
      A_right[i] = array[iR];
      printf("iR=%d:A_right[%d]=%d\n",iR,i,A_right[i] );
}
    printf("A_right[0]=%d\n",A_right[0] );

    A_left[N1]  = 99;
    A_right[N2] = 99;
    i = j = 0;

    printf("Aleft:");
    print_array_(A_left, N1);
    printf("Aright:");
    print_array_(A_right, N2);


    for (k = left; k <= right; k++) {
      // while (i<=N1&&j<=N2) {

        if (A_left[i] <= A_right[j]) {
            printf("A_left[%d] <= A_right[%d]\n",i,j);
            comp_count+=1;
            printf("before;array[%d]=%d\nなおこの時A_left[%d]は%d\n",k,array[k],i,array[i] );
            array[k] = A_left[i];
            i++;
            printf("after;array[%d]=%d\n\n",k,array[k] );
        } else {
            printf("A_left[%d] > A_right[%d]\n",i,j);
            comp_count+=1;
            printf("before;array[%d]=%d\n",k,array[k] );
            array[k] = A_right[j];
            j++;
            printf("after;array[%d]=%d\n\n",k,array[k] );
        }
      // }
    }

    // printf("phase\n");
    // print_array_(array, 8);
    printf("count:%d\n",comp_count );
// printf("--------------------------\n");
    free(A_right);
    free(A_left);
}
