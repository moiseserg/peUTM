#include <bits/stdc++.h>
#define T 100

int orden(char linea[], char id[]){
	char letra;
	//sscanf para leer datos desde una cadena
	sscanf(linea, "%c %s", &letra, id);
	
	switch(letra){
		case 'D': return 0;
		case 'T': return 1;
		case 'P': return 2;
	}

	return -1; //por si hubiese alguna orden no reconocida
}


void insertar(char cargas[100][20], char id[20], int *numC){

	if(*numC < 100){
		strcpy(cargas[ *numC ], id); 
		(*numC)++;
	}
	else 
		exit(EXIT_FAILURE);
}

int preguntar(char cargas[100][20], char id[20], int numC){
	int resp =0;
	for(numC--; numC>=0 ; numC--, resp++){
		if(strcmp(cargas[numC], id)==0){
			return resp;
		}
	}
	return -1; //error el contenedor no está
}

int main(){
	char cargas[100][20], linea[25], id[20];
	int numContenedores = 0;

	while(1){
		fgets(linea, 25, stdin);

		//salir si no hay más ordenes
		if(feof(stdin))
			break;
		
		int opc = orden(linea, id); 
		 
		switch(opc){
			case 0: insertar(cargas, id, &numContenedores);
					break;
		 
			case 1: numContenedores--;
					break;
		 
			case 2: printf("%d\n", preguntar(cargas, id, numContenedores));
					break;					
		}

		/*printf("Orden %d ", opc);
		if(opc != 1)
			printf("%s\n", id);
		else 
			printf("\n");*/

	}
}
