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
