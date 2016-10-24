#include <stdio.h>

int main(){


	int a=2,b=8, x;

	//Se asigna a x el valor mayor entre a y b
	x = a>b ? a: b;
	printf("%d\n",x );

	//Si a*a es menor que b, a x se le asigna 1, en caso contrario 0
	x = a*a>b ? 1: 0;
	printf("%d\n",x );


	//Este ejemplo particular puede escribirse también sin el operador ternario como:
	x = a*a>b;
	printf("%d\n",x );

	return 0;
}


/*
Salida:
8
0
0
*/
