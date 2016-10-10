#include <stdio.h>

int main(){
	unsigned int x ;
	scanf("%u", &x);

	printf("%u ",( x & 0x8000) >> 15);
	printf("%u ",( x & 0x4000) >> 14);
	printf("%u ",( x & 0x2000) >> 13);
	printf("%u ",( x & 0x1000) >> 12);


	printf("%u ",( x & 0x800) >> 11);
	printf("%u ",( x & 0x400) >> 10);
	printf("%u ",( x & 0x200) >> 9);
	printf("%u ",( x & 0x100) >> 8);

	printf("%u ",( x & 0x80) >> 7);
	printf("%u ",( x & 0x40) >> 6);
	printf("%u ",( x & 0x20) >> 5);
	printf("%u ",( x & 0x10) >> 4);


	printf("%u ",( x & 0x8) >> 3);
	printf("%u ",( x & 0x4) >> 2);
	printf("%u ",( x & 0x2) >> 1);
	printf("%u ",( x & 0x1) );


	return 0;
}
