#include <stdio.h>

int main(){
	char c;
	int bandera = 1;
	int cont=0; //no hay palabras

	while(scanf("%c", &c) != EOF){
		//printf("%c", c );
		if(c == 32){
			//printf("%c", c );
			bandera=1;
		}
		//hay letras
		else if(bandera==1) //ini de la palabra
		{
			cont++;
			bandera=0;
		}



	}

	printf("Hay %d palabras\n", cont  );
	return 0;
}