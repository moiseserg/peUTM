	//matrices funciones
#include <stdio.h>
#define TAM 5
void leerMatriz(int m[TAM][TAM], int f, int c){
	//f = filas --> horizontales
	//c = columnas --> verticales
	int i, j;
	for(i=0; i<f; i++){
		for(j=0; j<c; j++)
			scanf("%d", &m[i][j]);
	}
}
void imprimirMatriz(int m[TAM][TAM], int f, int c){
	//f = filas --> horizontales
	//c = columnas --> verticales
	int i, j;
	for(i=0; i<f; i++){
		for(j=0; j<c; j++)
			printf("%6d", m[i][j]);
		printf("\n");
	}
}

int sumaVector(int v[], int n){
	int i, suma=0;
	for(i=0; i<n; i++)
		suma += v[i];
	return suma;
}

int main(){
	int m[TAM][TAM], filas=2;

	leerMatriz(m, filas,4);
	imprimirMatriz(m, filas, 4);

	printf("suma[0] = %d\n", sumaVector(m[0],4));
	printf("suma[1] = %d\n", sumaVector(m[1],4));

	return 0;
}
