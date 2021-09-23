#include<stdio.h>

int main() {
  int i, t,k,j;
  double x[100],sma5[100],sma20[100];

  for (i = 0; i < 100; i++) {
      scanf(".2%lf\n", &x[i]);
  }

  for (j = 5; j < 100; j++) {
    for ( k = 0; k <5 ; k++) {
      sma5[j] = sma5[j] + x[j-k+1];
    }
  }

  for (j = 20; j < 100; j++) {
    for ( k = 0; k < 20; k++) {
      sma20[j] = sma20[j] + x[j-k+1];
    }
  }

  for (t = 20; t <= 100; t++) {
    printf("%d %.2lf %.2lf %.2lf\n", t, x[t], sma5[t]/5, sma20[t]/5);
  }

}
