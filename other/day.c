//
//  day.c
//
//  Find what day of the week
//
//  Created by Shuma Matsuzaki
//  2020/06/23
//  Copyright© Shuma Matszuaki 2020.  All rights reserved.
//


#include<stdio.h>

int modulo(int,int,int);
int gap(int);
void print(int num);


int main(){
  int year,month,day;
  int gapM,num;


  printf("Year:");
  scanf("%d",&year);
  printf("Month:");
  scanf("%d",&month);
  printf("Day:");
  scanf("%d",&day);

  gapM=gap(month);
  num=modulo(year,gapM,day);

  print(num);

  return 0;
}

int modulo(
  int Y,
  int gapM,
  int D
  ){
    int num,leapY;
    int base=4;
    leapY = Y/4;
    num=(Y+leapY+gapM+D+base)%7;
    return num;
}

int gap(
  int M
){
  int gap_array[12]={0,3,4,0,2,5,0,3,6,1,4,6};
  return gap_array[M-1];
}

void print(int num){
  char *a[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

  printf("%s\n",a[num]);
}
