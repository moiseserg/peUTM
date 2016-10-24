#include <stdio.h>

int main(){


	int a=3,b=8;

	printf("Post-incremento\n");
	printf("a= %d  b= %d\n", a++, b++ );
	printf("Variables una instrucción después del Post-incremento\n");
	printf("a= %d  b= %d\n", a, b );

	a=3,b=8;
	printf("\nPre-incremento y Post-incremento \n");
	printf("a= %d  b= %d\n", ++a, b++ );
	printf("Variables una instrucción después del Pre y Post-incremento\n");
	printf("a= %d  b= %d\n", a, b );

	return 0;
}

/*
Post-incremento
a= 3  b= 8
Variables una instrucción después del Post-incremento
a= 4  b= 9

Pre-incremento y Post-incremento 
a= 4  b= 8
Variables una instrucción después del Pre y Post-incremento
a= 4  b= 9

*/
