int merge_sort(int* array, int N, int left, int right) {

    if (left >= right) { //配列の要素数が1つの時ソートの必要がないのでreturn
      return 0;
    }

    int mid = (left + right) / 2;//(配列の)中央の要素番号midをとる

    // printf("left:%d,right:%d\n",left,right );

    int count_left=0;//左側配列の比較回数を定義し初期値0に設定
    count_left=merge_sort(array, N, left, mid);//2分した時の左側の配列を再起呼び出しによって要素数が1になるまで分割しその後マージする時の比較回数を代入

    int count_right=0;//右側配列の比較回数を定義し初期値0に設定
    count_right=merge_sort(array, N, mid + 1, right);//2分した時の右側の配列を再起呼び出しによって要素数が1になるまで分割しその後マージする時の比較回数を代入

    int count=0;
    count+=merge(array, N, left, mid, right);//関数mergeによってarray[left]からarray[mid]までの配列とarray[mid+1]からarray[right]までの配列をソートし統合、その際の比較回数をcomp_countに逐一加えていく

    //この段階以前での左側配列,右側配列をソートするまでの比較回数とこの段階での比較回数をcomp_countに代入
    int comp_count=0;
    comp_count = count + count_left + count_right;

    printf("MERG(%2d,%2d)",left,right);
    print_array_range_(array,N,left,right);//mergeした部分のインデックスと配列を表示

    return comp_count;//比較回数の最終的な値をmain関数に返す
}
