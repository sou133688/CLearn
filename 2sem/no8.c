#include <stdio.h>

double Circle(void)
{
   double R, S;
	printf("半径=");
	scanf("%lf", &R);
	S = 3.141592*R*R;
	return S;
	
}
double Triangle(void){
   double teihen,takasa,S;
	printf("底辺=");
	scanf("%lf", &teihen);
	printf("高さ=");
	scanf("%lf", &takasa);
	S=teihen*takasa/2;
	return S;
}
double Square(void){
   double teihen,takasa,S;
	printf("底辺=");
	scanf("%lf", &teihen);
	printf("高さ=");
	scanf("%lf", &takasa);
	S=teihen*takasa;
	return S;
	
}

int main(){
	int status=0;
	double area;
	printf("円>>1,四角形>>2,三角形>>3\n");
	scanf("%d", &status);
	if(status==1){
		area=Circle();
	}else if(status==2){
		area=Square();
	}else if(status==3){
		area=Triangle();
	}
	printf("面積=%5.2lf\n", area);

	return 0;
}

