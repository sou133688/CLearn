#include<stdio.h>

int pick_max_digit(int max,int M){
  int max_digit=0;
  int t=1;
  while (t<max) {
    t=t*M;
    max_digit++;
  }
  return max_digit;
}
