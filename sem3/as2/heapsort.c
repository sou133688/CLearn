#include <stdio.h>
#include <stdlib.h>	/* rand(  ) で必要 */

#define NUM_DATA 20
int a[NUM_DATA + 1];

void SetData(void);
void Hpsort(int a[ ], int n);
void DownHeap(int a[ ],  int top, int bottom);
void Swap(int a[ ], int i, int j);
void ShowData(int a[ ], int n);
int main(void);

  /* 0 から99 の範囲の整数の乱数をNUM_DATA個作って a[ ] にしまう */
void SetData(void)
{
    int i;

    for (i = 0; i <= NUM_DATA; i++)
        a[i] = rand(  ) % 100;
}

  /* ヒープソートを行う */
void Hpsort(int a[ ], int n)
{
    int leaf, root;

    leaf = n;                   /* 初期値は末尾の要素 */
    root = n/2;                 /* 初期値はその親 */

    while (root > 0 ) {         /* 半順序木を構成 */
        DownHeap(a, leaf, root);
        root--;
    }
    printf("半順序木を構成:\n");
    ShowData(a, NUM_DATA);      /* できあがった半順序木を表示 */

    while(leaf > 0) {
        Swap(a, 1, leaf);       /* 半順序木の根と末尾の要素を交換 */
        leaf--;                 /* 末尾の要素を半順序木から外す */
        DownHeap(a, leaf, 1);   /* 半順序木を再構成する */
    }
}

  /* 半順序木 ( ヒープ ) を構成する */
void DownHeap(int a[ ],  int leaf, int root)
{
    int i;

    i = root * 2;
    while (i <= leaf) {
        if (i < leaf && a[i + 1] > a[i])  /* a[i] と a[i + 1]  の大きい方と */
            i++;
        if (a[root] >= a[i])              /* a[root] と比較 */
            break;                        /* 子の方が大きければ */
        Swap(a, root, i);                 /* 交換 */

        root = i;                         /* 更にその子についても調べる */
        i = root * 2;
    }
}

  /* 配列の要素を交換する */
void Swap(int a[ ], int i, int j)
{
    int temp;

    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

  /* 配列の要素を表示する */
void ShowData(int a[ ], int n)
{
    int i;

    for (i = 1; i <= n; i++) {
        printf("a[%2d] = %2d   ", i, a[i]);
        if(!(i % 5))/* 要素を５つ表示したら改行 */
            printf("\n");
    }
    printf("\n");
}

int main(void)
{
    SetData(  );

    printf("ソート前:\n");
    ShowData(a, NUM_DATA);

    Hpsort(a, NUM_DATA);

    printf("ソート後:\n");
    ShowData(a, NUM_DATA);

    return 0;
}
