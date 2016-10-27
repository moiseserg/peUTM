#include <stdio.h> 
#include <math.h>
int main (){
	double a, b, c, disc, x1, x2;
	printf("dame a: ");
	scanf("%lf", &a);
	printf("dame b: ");
	scanf("%lf", &b);
	printf("dame c: ");
	scanf("%lf", &c);
	disc = (b*b - 4*a*c);
	if (disc==0) {
		printf("Solo hay una raiz: %lf", -b/(2*a));
		}
	else if (disc > 0) {
		x1= ((-b) + sqrt(disc))/(2*a);
		x2= ((-b) - sqrt(disc))/(2*a);
		printf("Las raices son X1: %lf\n X2: % lf", x1, x2);
		}
	else if (disc <0){
		x1= -b/(2*a);
		x2= -b/(2*a);
		disc= (sqrt(disc*-1))/(2*a);
		printf("las raices son X1: %lf + %lfi\n X2: %lf - %lfi", x1, disc, x2, disc);
		}
	return 0;
	}
