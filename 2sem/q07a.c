#include<stdio.h>
int main(){
  FILE *fp;
  float lmd,n,k;
  fp=fopen("SiO2.txt","r");
  fscanf(fp,"%f %f %f",&lmd, &n, &k);
  printf("%f %f %f\n",lmd,n,k);
  fclose(fp);
}
