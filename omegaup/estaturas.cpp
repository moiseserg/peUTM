#include <stdio.h>
int main(){
    double a;

    while (scanf("%lf", &a)!=EOF){    	
    	a=a*30.48;
    	printf("%.2lf\n", a );
    }
    return 0;
}