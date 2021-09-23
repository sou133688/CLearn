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

    N1 = mid - left+1;
    N2 = right - mid;

    int comp_count=0;

    printf("N1:%d,N2:%d\n",N1,N2 );
    printf("left:%d//right:%d//mid:%d\n",left,right,mid );


    int* A_left = func_mallocation_(N1+1);
    int* A_right = func_mallocation_(N2+1);


    for (i = 0; i < N1; i++) {
      iL=left+i;
      A_left[i]  = array[iL];
      printf("iL=%d:A_left[%d]=%d\n",iL,i,A_left[i] );
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

    }
    printf("count:%d\n",comp_count );
    free(A_right);
    free(A_left);
}
