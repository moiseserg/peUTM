#include <stdio.h>
#include <string.h>

void leerPalabras(char p[10][15], int n){
	int i;
	for(i=0; i< n ; i++){
		scanf("%s", p[i]);
	}
}


void mostrarPalabras(char p[10][15], int n){
	int i;
	for(i=0; i< n ; i++){
		printf("%s %d\n",p[i], (int)strlen(p[i]) );
	}
}


int main(){     
	char palabras[10][15] = {"efrain", "freeman",
							"karime", "sayra"};
	leerPalabras(palabras, 5);
	mostrarPalabras(palabras, 5);

	return 0;
}
