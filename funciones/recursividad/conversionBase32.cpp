#include <stdio.h>


void convertir(int v, int b){

	if(v>=b){
		convertir(v/b, b);
		printf("%c", v%b <10 ? 48+v%b : 55+v%b);
	}
	else
		printf("%c", v<10 ? 48+v : 55+v);
}

int main(){
	int v, base=32;

	while( scanf("%d", &v)!=EOF){
		convertir(v, base);
		printf(" (base 32)=  %d (base 10)\n", v);
	}	
}

/*
2 (base 32)=  2 (base 10)
9 (base 32)=  9 (base 10)
A (base 32)=  10 (base 10)
P (base 32)=  25 (base 10)
V (base 32)=  31 (base 10)
10 (base 32)=  32 (base 10)
1V (base 32)=  63 (base 10)
20 (base 32)=  64 (base 10)
3V (base 32)=  127 (base 10)
40 (base 32)=  128 (base 10)
FV (base 32)=  511 (base 10)
G0 (base 32)=  512 (base 10)
100 (base 32)=  1024 (base 10)
VV (base 32)=  1023 (base 10)
6C4 (base 32)=  6532 (base 10)
6QB (base 32)=  6987 (base 10)
3OI0 (base 32)=  123456 (base 10)
U3CR (base 32)=  986523 (base 10)
15LR1 (base 32)=  1234785 (base 10)
T38M (base 32)=  953622 (base 10)

*/
