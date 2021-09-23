#include<stdio.h>

float sqSum(int, int);

int main(){
    int m,n;
    printf("enter m,n= ");
    scanf("%d %d",&m,&n);
    printf("sum of sequence=%f\n",sqSum(m,n));
}

float sqSum(int* m, int* n){
    float ans=0;
int i;
for(i=*m;i<=*n;++i){
    ans+=i*i-2*i+1;
    }
return(ans);
}
