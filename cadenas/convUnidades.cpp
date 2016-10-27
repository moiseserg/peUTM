#include <stdio.h>


void menu(){

	printf("\nOpciones: \n");
	printf("1) cm\n");
	printf("2) m\n");
	printf("3) km\n");
	printf("4) mm\n");
	printf("5) mi\n");
	printf("0) Salir\n");

}

void opcionCM(){
	int que;

	double cm;
	printf("de centimetros, a qué quieres convertir? ");
	menu();
	scanf("%d", &que);

	printf("Cuántos centimetros?\n");
	scanf("%lf", &cm);

	switch(que){

			case 1: printf("%10.4lf cm \n", cm );
					break;
			case 2: printf("%10.4lf m \n", cm/100.0);
					break;
			case 3: printf("%10.4lf km \n", cm/(100.0*1000.0));
					break;
			case 4: printf("%10.4lf mm \n", cm*10.0);
					break;
			case 5: printf("%10.4lf mi \n", cm*6.2137e-6);
					break;

		}


}

void opcionMts(){
	int que;

	double mts;
	printf("de metros, a qué quieres convertir? ");
	menu();
	scanf("%d", &que);

	printf("Cuántos metros?\n");
	scanf("%lf", &mts);

	switch(que){

			case 1: printf("%10.4lf cm \n", 100*mts );
					break;
			case 2: printf("%10.4lf m \n", mts);
					break;
			case 3: printf("%10.4lf km \n", mts/(1000.0));
					break;
			case 4: printf("%10.4lf mm \n", mts*1000.0);
					break;
			case 5: printf("%10.4lf mi \n", mts*0.00062136999982602);
					break;

		}


}


int main(){

	int opc=1;

	while(opc){
	
		printf("Que quieres convertir?  ");
		menu();
		scanf("%d", &opc);


		switch(opc){

			case 1: opcionCM();
					break;
			case 2: opcionMts();
					break;
			case 3:
					break;
			case 4:
					break;
			case 5:
					break;

		}


	}

	

	return 0;
}
