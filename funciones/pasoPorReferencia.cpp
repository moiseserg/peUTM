#include <stdio.h>

void porReferencia(int *a){
	printf("Antes de incrementar:  %d (dentro de la función)\n", *a);
	(*a)++;
	printf("Después de incrementar: %d (dentro de la función)\n", *a);
}
int main(){
	int a = 1;
	printf("Antes de llamar a la función: %d\n",a);
	porReferencia(&a);
	printf("Después de llamar a la función: %d\n", a);

}


/*
./pasoPorReferencia 
Antes de llamar a la función: 1
Antes de incrementar:  1 (dentro de la función)
Después de incrementar: 2 (dentro de la función)
Después de llamar a la función: 2

*/
