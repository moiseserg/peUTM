#include <stdio.h>

void suma(double *real, double *img, 
	double r1, double i1,double r2, double i2){

	*real = r1 + r2;
	*img  = i1 + i2;

}

void producto(double *real, double *img, 
	double r1, double i1,double r2, double i2){

	*real = r1*r2 - i1*i2;//
	*img  = r1*i2 + r2*i1;//
}

int main(){
	double r1, i1, r2, i2; //entrada
	double real, img;  	//para respuesta

	scanf("%lf%lf%lf%lf", &r1, &i1, &r2, &i2 );	
	suma(&real, &img, r1, i1, r2 , i2);

	printf("suma: %.4lf + %.4lfi\n", real, img );
	
	producto(&real, &img, r1, i1, r2 , i2);

	printf("producto: %.4lf + %.4lfi\n", real, img );
	
}