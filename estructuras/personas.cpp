#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct persona{
	char nombre[10];
	int edad;
} P;

int comparacion(const void *a, const void *b){
	P *aa = (P*)a;
	P *bb = (P*)b;
	return strcmp(aa->nombre, bb->nombre);
}

int comparacion2(const void *a, const void *b){
	return ((P *)a)->edad -  ((P *)b)->edad ;
}

int main(int argc, char *argv[]){
	P lista[20];
	int i;
	FILE *arch = fopen(argv[1], "r");
	FILE *arch2 = fopen(argv[2], "w");
	FILE *arch3 = fopen(argv[3], "w");
    //./personas listaNombres.txt xnombre.txt xedad.txt 
	if(arch==NULL){
		printf("No se puede abrir el archivo %s\n", argv[1] );
		exit(0);
	}

	for( i=0; ;  i++){
		fscanf(arch, "%s %d", 
			lista[i].nombre, &lista[i].edad);
		if(feof(arch))
			break;
	}
	//i se queda con cuántos datos hay en lista[]

	for( int j=0; j<i ;  j++){
		printf("%s %d\n", 
			lista[j].nombre, lista[j].edad);
	}

	qsort(lista, i, sizeof(P), comparacion);
	for( int j=0; j<i ;  j++){
		fprintf(arch2,"%s %d\n", 
			lista[j].nombre, lista[j].edad);
	}
	qsort(lista, i, sizeof(P), comparacion2);
	for( int j=0; j<i ;  j++){
		fprintf(arch3, "%s %d\n", 
			lista[j].nombre, lista[j].edad);
	}

	return 0;
}