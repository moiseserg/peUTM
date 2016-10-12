#include <stdio.h>

int main(){

  //valor a mostrar
	unsigned int x =0x3af5;

	printf("Valor en hexadecimal %X\n", x );

	printf("%x \n\n", (x>> 8 ));
	printf("%x \n\n", (x>> 8 ) & 3);

	printf("%x", (x>> 14) &  3);
	printf("%x ", (x>> 12) &  3);

	printf("%x", (x>> 10) &  3);
	printf("%x ", (x>> 8 ) &  3);

	printf("%x", (x & 0xc0) >> 6);
	printf("%x ", (x & 0x30) >> 4);

	printf("%x", (x & 0xc) >> 2);
	printf("%x ", x & 0x3 );
	printf("\n");
  
  return 0;
}
