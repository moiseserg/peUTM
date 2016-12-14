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
	for(int i=0; i<n ; i++)
		printf("%s %d %s %s\n", v[i].placas, v[i].modelo, 
							v[i].color, v[i].marca);

}
int main()
{	
	int n;
	A v[10];
	capturar(&n, v);
	imprimir(n, v);

	return 0;
}

