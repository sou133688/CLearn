#include <stdio.h>

void tousa(int,int,float,float,float*,float*);

int main()
{
    int m,n;
    float x,y;
    float a1,d;

    printf("等差数列の第m項と第n項をそれぞれxとy、初項をa1、公差をdとして入力しなさい。")
    printf("m=");
    scanf("%d",&m);
    printf("x=");
    scanf("%f",&x);
    printf("n=");
    scanf("%d",&n);
    printf("y=");
    scanf("%f",&y);
    tousa(m,n,x,y,&a1,&d);
    printf("a1=%f\nd=%f\n",a1,d);
}

void tousa(int m,int n, float x,float y,float* a1,float* d)
{
    *d=(x-y)/(m+0.-n+0.);
    printf("%f\n",*d);
    *a1=x-(m-1) * *d;
}
