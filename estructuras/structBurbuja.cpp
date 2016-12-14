#include <stdio.h>
#include <string.h>

typedef struct persona{
	char nombre[30];
	int edad;
} P;


void burbujaEdad(P v[], int n){
	int i, j;
	for(i = 1; i<n; i++){
		for(j=0; j<n-i; j++){
			if(v[j].edad > v[j+1].edad ){
				P tmp = v[j];
				v[j] = v[j+1];
				v[j+1] = tmp;
			}
		}
	}
}
void burbujaNombre(P v[], int n){
	int i, j;
	for(i = 1; i<n; i++){
		for(j=0; j<n-i; j++){
			if ( strcmp(v[j].nombre, v[j+1].nombre)>0 ){
				P tmp = v[j];
				v[j] = v[j+1];
				v[j+1] = tmp;
			}
		}
	}
}

int main(){
	P p[10];
	int n, i;

	scanf("%d", &n);

	for(i=0; i<n; i++){
		scanf("%s %d", p[i].nombre, &p[i].edad);
	}

	for(i=0; i<n; i++){
		printf("%s %d\n", p[i].nombre, p[i].edad);
	}

	burbujaEdad(p, 4);

	for(i=0; i<n; i++){
		printf("%s %d\n", p[i].nombre, p[i].edad);
	}

	burbujaNombre(p, 4);

	for(i=0; i<n; i++){
		printf("%s %d\n", p[i].nombre, p[i].edad);
	}

}


//qsort

