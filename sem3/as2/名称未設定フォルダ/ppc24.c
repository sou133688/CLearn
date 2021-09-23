

#include <stdio.h>
#include <stdlib.h>
#include "c20.c"

int merge_sort(int *, int , int , int );
int merge(int *, int , int , int , int );


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

int main() {
  printf("*****************************************************************************************\n" );

  int N;       // 入力配列の要素数
  scanf("%d", &N);               // STDINから要素数を受け取る
  int* array = func_mallocation_(2*N);  // 配列に動的メモリを割り当てる(作業スペースが必要なので2N)

  for (int i = 0; i < N; i++)
    scanf("%d", &(array[i]));  // STDINから配列要素を受け取る

  printf("INIT:::::::");
  print_array_(array, N);             // 配列の初期状態をSTDOUTに出力

  int cnt += merge_sort(array, N,0,N-1);  // 比較回数をins_sortから呼び出す

  printf("DONE:::::::");
  print_array_(array, N);  // 配列の最終状態をSTDOUTに出力


  printf("count:%d\n", cnt);     // comp_が呼んだ合計回数を出力

  free(array);  // 配列に割り当てられた動的メモリを解放
  return 0;     // main関数の終了
}






int merge_sort(int* array, int N, int left, int right) {
    int comp_count=0;

    if (left >= right) { //配列の要素数が1つの時ソートの必要がないのでreturn
      return 0;
    }

    int mid = (left + right) / 2;//(配列の)中央の要素番号midをとる

    // printf("left:%d,right:%d\n",left,right );

    merge_sort(array, N, left, mid);//2分した時の左側の配列を再起呼び出しによって要素数が1になるまで分割

    merge_sort(array, N, mid + 1, right);//2分した時の右側の配列を再起呼び出しによって要素数が1になるまで分割

    // printf("Merge\n" );


    comp_count+=merge(array, N, left, mid, right);//関数mergeによってarray[left]からarray[mid]までの配列とarray[mid+1]からarray[right]までの配列を統合

    //// printf("AfterMerge\n" );
    // print_array_(array,8);
    printf("MERG(%2d,%2d)",left,right );
    print_array_range_(array,N,left,right);
    //// printf("--------------------------------------\n");

    return comp_count;
}




int merge(int* array, int N, int left, int mid, int right) {
    int N1, N2;

    // printf("N:%d\n",N );

    N1 = mid - left + 1;//左側配列の要素数
    N2 = right - mid;

    int comp_count=0;

    // printf("N1:%d,N2:%d\n",N1,N2 );


//カーソルの定義
    int i=0,j=0,k=0;
    k=N;
    int fl=1,fr=1;//フラッグの定義
    int L=0,R=0;

    while (fl||fr) {

      // printf("fl:%d,fr:%d\n i:%d,j:%d,k:%d\n",fl,fr,i,j,k);

      if (fl) {//i<N1の時
        L=array[i+left];

      }
      if (fr){
        R=array[j+mid+1];
      }


      if ((L<R||(fr!=1))&&fl) {//右がoutofrange or　両方がinrange
        comp_count+=1;
        array[k]=L;
        i++;//カーソルの移動
        k++;
      }else{//左のみoutofrange or L>R
        comp_count+=1;
        /////array[k]=R;
        func_copy_val_(array,j+mid+1)
        j++;
        k++;
      }

      fl=(i<N1);
      fr=(j<N2);

    }

//ここまでで作業配列へのソートと格納終了

int t;

for (t = 0; t < right -left+1; t++) {
  // printf("array[%d]=%d\n",N+t,array[N+t] );
  // printf("array[%d]=%d\n",left+t,array[left+t] );
  /////array[left + t]=array[N+t];//作業配列からの格納
  func_copy_val_(array,left+t,N+t);
}


// print_array_(array,2*N);
printf("%d\n", comp_count-1);
