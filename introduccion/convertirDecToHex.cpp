
/*
Convertir un valor de base 10 a hex

Usando operadores de corrimiento y máscaras
Sin ciclos
Dígito por dígito en hexadecimal (bloques de 4 bits en binario = bloques de 1 dígito en hex)
*/

#include <stdio.h>

int main(){
	unsigned int x ;
	scanf("%u", &x);

	printf("%x\n", x );



	printf("%x ",( x & 0xf000) >> 12);
	printf("%x ",( x & 0x0f00) >> 8);
	printf("%x ",( x & 0x00f0) >> 4);
	printf("%x ",( x & 0x000f) );


	return 0;
}
