// かぷれかーへんかん！！
#include<stdio.h>

int main() {

  int a,i,j,n,d[3],min,max;
  printf("かぷれかーへんかんだお！\n" );
  scanf("%d",&n);

  if (n<1||n>999||n%111==0){
    printf("えらーだお！\n");
  }

  else{
    for(i = 0;i<999;i++) {


      d[0]=n/1%10;
      d[1]=n/10%10;
      d[2]=n/100%10;


      for (i = 0; i < 3; ++i) {
        for (j = i+1; j < 3; ++j) {
          if (d[i]>d[j]) {
            a=d[i];
            d[i]=d[j];
            d[j]=a;
          }
        }
      }

      min=d[0]*100+d[1]*10+d[2];
      max=d[2]*100+d[1]*10+d[0];

      n=max-min;

      

      printf("%d - %d = %d\n",max,min,n);


      if (n==495) {
        printf("えんど！\n");
        break;
        return 0;

      }



    }
  }
}
