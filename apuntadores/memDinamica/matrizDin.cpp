#include <stdlib.h>
#include <stdio.h>

int *reservarVector(int n){
	int * ptr = (int * )calloc(n, sizeof(int));

	if(ptr == NULL){
		printf("No hay memoria \n");
		exit(0);
	}
	return ptr;
}

int **reservarMatriz(int f, int c){
	int ** ptr = (int ** )calloc(f, sizeof(int *));

	if(ptr ==NULL){
		printf("No hay memoria \n");
		exit(0);
	}

	for(int i=0; i<f; i++)
		//ptr[i] = reservarVector(c);
		*(ptr+i) = reservarVector(c);
	return ptr;
}


void liberarMatriz(int **m,  int f){

	for(int i=0; i<f; i++)
		free( *(m+i));
	free (m);
}

void capturar(int **m, int f, int c){

	for (int i = 0; i < f; ++i)
		for (int j = 0; j < c; ++j)
			//scanf("%d",  m[i]+j );
			scanf("%d",  *(m+i)+j );
}


void imprimir(int **m, int f, int c){

	for (int i = 0; i < f; ++i){
		printf("%p (%p) ", m + i , *(m+i) );
		for (int j = 0; j < c; ++j)
			printf(" %p %4d ", m[i]+j,  *(m[i]+j) );
			//printf("%d",  *(*(m+i)+j) );
		printf("\n");
	}
}


int ** multiplicarMatrices(int **a, int **b,
	                       int fa, int ca, int cb){
	int **r = reservarMatriz(fa, cb);

	for(int i=0; i<fa; i++){
		for(int j=0; j<cb; j++){
			*(*(r+i)+j) =0;
			for(int k=0; k<ca; k++){
				*(*(r+i)+j)  += *(*(a+i)+k)  *  *(*(b+k)+j);
			}

		}
	}

	return r;
}


/*
./a.out
1 2 3 4 5 6 7 8 9 10 11 12
0x1634010 (0x1634040)  0x1634040    1  0x1634044    2  0x1634048    3
0x1634018 (0x1634060)  0x1634060    4  0x1634064    5  0x1634068    6
0x1634020 (0x1634080)  0x1634080    7  0x1634084    8  0x1634088    9
0x1634028 (0x16340a0)  0x16340a0   10  0x16340a4   11  0x16340a8   12 */

int main(){
	// para prueba con una matriz de 2 x 2
	int f=2, c=2;
	int **a=reservarMatriz(f,c);
	int **b=reservarMatriz(f,c);
	int **r;
	capturar(a, f,c);
	capturar(b, f,c);
	printf("\nMatriz a = \n");
	imprimir(a, f,c);
	printf("\nMatriz b = \n");
	imprimir(b, f,c);

	r = multiplicarMatrices(a,b,f,c,c);

	printf("\nMatriz r = \n");
	imprimir(r, f,c);
	liberarMatriz(r, f);
	liberarMatriz(a, f);
	liberarMatriz(b	, f);
	return 0;
}