#include <stdio.h>

int main(){


	int a,b,c;

	printf("Valor de a? ");
	scanf("%d", &a);
	printf("Valor de b y c? ");
	scanf("%d%d", &b, &c);

	printf("Valor de a = %d (base 10)\n", a);
	printf("Valor de b = %d (base 10) = %x (hex)\n", b, b);
	printf("Valor de c = %d (base 10) = %o (oct)\n", c,c );

	printf("Mismos valores pero en bloques con alineación izq y der\n");
	printf("Valor de a = %5d (base 10)\n", a);
	printf("Valor de b = %-5d (base 10) = %x (hex)\n", b, b);
	printf("Valor de c = %5d (base 10) = %o (oct)\n", c,c );


	return 0;
}

/*
Valor de a? 250
Valor de b y c? 350
900
Valor de a = 250 (base 10)
Valor de b = 350 (base 10) = 15e (hex)
Valor de c = 900 (base 10) = 1604 (oct)
Mismos valores pero en bloques con alineación izq y der
Valor de a =   250 (base 10)
Valor de b = 350   (base 10) = 15e (hex)
Valor de c =   900 (base 10) = 1604 (oct)

*/
