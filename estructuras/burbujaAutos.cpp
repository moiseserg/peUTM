#include <stdio.h>

typedef struct automovil
{
	char placas[10];
	int modelo;
	char color[10];
	char marca[10];
} A;

void capturar(int *n, A v[]){

	scanf("%d", n);

	for(int i=0; i<*n ; i++)
		scanf("%s %d %s %s", v[i].placas, &v[i].modelo, 
							v[i].color, v[i].marca);

}

void imprimir(int n, A v[]){
	printf("\n\n");
	for(int i=0; i<n ; i++)
		printf("%s %d %s %s\n", v[i].placas, v[i].modelo, 
							v[i].color, v[i].marca);

}

void burbujaModelo(int n, A v[]){
	int i, j;
	for(i=1; i<n; i++){
		for(j=0; j<n-i; j++){
			if(v[j].modelo > v[j+1].modelo){
				A tmp= v[j];
				v[j] = v[j+1];
				v[j+1] = tmp;
			}
		}
	}
}


int main()
{	
	int n;
	A v[10];
	capturar(&n, v);
	imprimir(n, v);
	burbujaModelo(n, v);
	imprimir(n, v);
	

	return 0;
}




/*
/burbujaAutos < autos.txt


KL223 1993 GRIS HYUNDAI
UKJ23 1933 ROJO HONDA
ABC86 1979 AMARILLO FORD
HGT23 1983 AZUL TOYOTA


UKJ23 1933 ROJO HONDA
ABC86 1979 AMARILLO FORD
HGT23 1983 AZUL TOYOTA
KL223 1993 GRIS HYUNDAI


*/