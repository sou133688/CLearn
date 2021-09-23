#include <stdio.h>
 int main()
  {int kuku[9][9]; 
   int i,j,k,f;
	
   for(i=1; i<=9; i++){
	for(j=1; j<=9; j++){
		kuku[i-1][j-1]=i*j;
	}}
   for(k=0; k<9; k++){
	for(f=0; f<9; f++ ){
		printf("%d*%d=%d\t",k+1,f+1,kuku[k][f]);
		}printf("\n");
}	
return 0;}

