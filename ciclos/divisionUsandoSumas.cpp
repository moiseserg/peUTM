/*
./a.out 
12
5
cociente 2 
Residuo 2 

./a.out 
3501
4
cociente 875 
Residuo 1 

*/

#include <stdio.h>

int main()
{
	int dividendo, divisor, cont;
	scanf("%d%d", &dividendo, &divisor);

	for(cont=0 ; dividendo>=divisor; dividendo-=divisor, cont++);

	printf("cociente %d \n", cont);
	printf("Residuo %d \n", dividendo);
}
