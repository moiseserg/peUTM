#include <stdio.h>

int incrementa1(int x){
	printf("Antes de cambiar (fun)x %p %d\n",&x, x );
	x++;
	printf("Despues de cambiar (fun)x %p %d\n", &x,  x );
}

int incrementa2(int *x){
	printf("Antes de cambiar (fun2)x %p %d\n",x, *x );
	(*x)++;
	printf("Despues de cambiar (fun2)x %p %d\n", x,  *x );
}

int main(){
	
	int a = 10;
	printf("En main antes de incrementa1 (a) %p %d\n", &a, a );
	incrementa1(a);
	printf("En main despues de incrementa1  (a)  %p %d\n", &a, a );

	printf("\nEn main antes de incrementa2  (a) %p %d\n", &a, a );
	incrementa2(&a);
	printf("En main despues de incrementa2  (a) %p %d\n", &a, a );


}