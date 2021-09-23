void get_ops(char *X, int m, char *Y, int n, int **dpt ,char *seq_x, char *seq_y, char *ops){

    int k = get_length(X,m,Y,n,dpt)-1;
    int i=m;
    int j=n;
    int Min;

    while (i>0||j>0) {

        if (i==0&&j!=0) {//文字列Xのみ数え切った場合

              ops[k]='I';
              seq_x[k]=' ';
              seq_y[k]=Y[j];
              j--;

        }else if(j==0&&i!=0){//文字列Yのみ数え切った場合

              ops[k]='D';
              seq_x[k]=X[i];
              seq_y[k]=' ';
              i--;

        }else{//文字列X,Y共に数え切っていない場合

            Min=vmin3_(dpt[i-1][j-1]+delta(X,i,Y,j), dpt[i-1][j]+1, dpt[i][j-1]+1);

            if (Min==dpt[i-1][j-1]+delta(X,i,Y,j)) {//コピーまたは置換

                if (delta(X,i,Y,j)==0) {//コピー
                  ops[k]='=';
                  seq_x[k]=X[i];
                  seq_y[k]=Y[j];

                }else{//置換
                  ops[k]='R';
                  seq_x[k]=X[i];
                  seq_y[k]=Y[j];

                }

                i--;
                j--;

            }else if(Min==dpt[i-1][j]+1){//削除
              ops[k]='D';
              seq_x[k]=X[i];
              seq_y[k]=' ';
              i--;

            }else{//挿入
              ops[k]='I';
              seq_x[k]=' ';
              seq_y[k]=Y[i];
              j--;

            }
        }

        k--;


    }


    printf("%s\n", seq_x);  // seq_xに格納した文字列を出力
    printf("%s\n", seq_y);  // seq_yに格納した文字列を出力
    printf("%s\n", ops);  // opsに格納した文字列を出力





}
