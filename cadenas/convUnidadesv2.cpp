#include <stdio.h>
#include <string.h>



void opcionCM(int que, double cm){
	 

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

int main(){
	char txt[100], orig[100], dest[100];
	double leer;

	int opc, opc2;


	while(1){
		gets(txt);

		if(strlen(txt)==0)
			break;
		puts(txt);

		sscanf(txt, "%lf %s a %s", &leer, orig,  dest);

		printf("Cantidad %lf \n", leer );
		printf("De que   %s \n", orig );
		printf("A que    %s \n", dest );

		if(strcmp("cm", orig)==0){
			opc = 1;
		}else if(strcmp("m", orig)==0){
			opc = 2;
		}if(strcmp("km", orig)==0){
			opc = 3;
		}if(strcmp("mm", orig)==0){
			opc = 4;
		}if(strcmp("mi", orig)==0){
			opc = 5;
		}


		if(strcmp("cm", dest)==0){
			opc2 = 1;
		}else if(strcmp("m", dest)==0){
			opc2 = 2;
		}if(strcmp("km", dest)==0){
			opc2 = 3;
		}if(strcmp("mm", dest)==0){
			opc2 = 4;
		}if(strcmp("mi", dest)==0){
			opc2 = 5;
		}


		switch(opc){

			case 1: opcionCM(opc2,leer );
					break;
			case 2: //opcionMts();
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
