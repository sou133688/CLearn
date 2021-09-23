#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH      8

void merge_sort(int*,int,int);
void showData(int*,int);

int main()
{
    int array[MAX_LENGTH] = { 55 , 13 , 3 , 45 , 74, 87, 46, 30 };
    showData(array,MAX_LENGTH);
    merge_sort(array,0,MAX_LENGTH-1);
}

void merge_sort(int* pArray,int start,int end){
    //  作業用の配列（再帰呼び出しをするため、staticで定義する）
    static int tmp[MAX_LENGTH];
    //  作業用のデータ
    int middle,i,j,k;
    if(start >= end){
        return;
    }
    //  startとendの中間地点を分割点とする
    middle = (start + end) / 2;
    //  前半部分を再帰的に整列
    merge_sort(pArray,start,middle);
    //  後半部分を再帰的に整列
    merge_sort(pArray,middle + 1,end);



    k = 0;
    //  仮想領域のデータをマージしながらコピーする。
    for(i = start; i <= middle; i++){
        tmp[k] = pArray[i];
        k++;
    }
    for(j = end; j >= middle + 1 ; j--){
        tmp[k] = pArray[j];
        k++;
    }




    //  末端からデータを取得して、マージしていく。
    i = 0;
    j = end - start;
    for(k = start; k <= end ; k++){
        if(tmp[i] >= tmp[j]){
            pArray[k] = tmp[i];
            i++;
        }else{
            pArray[k] = tmp[j];
            j--;
        }
    }

    //  結果を出力
    showData(pArray,MAX_LENGTH);
}

//  配列の表示
void showData(int* array,int length){
    int i;
    for(i = 0; i < length; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}
