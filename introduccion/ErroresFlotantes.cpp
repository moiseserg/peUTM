#include <stdio.h>

int main(){
	float x = 13.5625; //0.1 ; //13.5625
	int *ptr = (int *)(&x);

	printf(" %f %x\n", x, *ptr );
	int  i=0;
	for(x=0 ; i< 100000; i++ )
		x = x+ 0.1;


	printf("Valor calculado usando incrementos de 0.1 n veces . . .  %.10f\n",x );

	printf("Valor del producto directo: %.10f\n",0.1*100000 );

  return 0;
}
