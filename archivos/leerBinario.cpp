#include <stdio.h>
#include <stdlib.h>

typedef struct cancion{
	char pista[20];
	int mins, segs;
} C;

void imprimirDatos(C c[], int cuantos){

	for(int i=0; i<cuantos; i++)
		printf("%-20s %02d:%02d\n", c[i].pista, c[i].mins, c[i].segs );
}

void leerBinario(C c[], FILE *f, int *cuantos){
	*cuantos = 2;

	fread(c, sizeof(C), *cuantos, f);

}

int main(int argc, char *argv[])
{
	C c[10];
	FILE *archb = fopen(argv[1], "rb");
	int cuantos;

	if(archb ==NULL )
	{
		printf("Error no se pudieron abrir los archivos\n");
		exit(0);
	}
	leerBinario(c, archb, &cuantos);
	imprimirDatos(c, cuantos);
	fclose(archb);
	return 0;
}