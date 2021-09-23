#include <stdio.h>

void  bMass(float, float,float* ,float*);

int main()
{
 float h, w;
 float BMI, SW;

 printf("height(cm)?\n");
 scanf("%f", &h);

 printf("weight(kg)?\n");
 scanf("%f", &w);

 bMass(h/100, w, &BMI, &SW);
 printf("BMI=%f,SW=%f", BMI,SW);
}

void bMass(float a, float b, float* x, float* y)
{
 *x = b/(a*a);
 *y = a*a*22;
}
