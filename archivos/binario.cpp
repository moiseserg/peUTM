#include <stdio.h>
#include <stdlib.h>

typedef struct cancion{
	char pista[20];
	int mins, segs;
} C;

void escribirBinario(C c[], FILE *arch, int n){

	fwrite(c, sizeof(C), n, arch);
}

void escribirTexto(C c[], FILE *arch, int n){
	for(int i=0; i<n; i++){
		fprintf(arch, "%s %d %d\n", c[i].pista, c[i].mins, c[i].segs );
	}
}

int main(int argc, char *argv[])
{
	C c[10] = { {"La cucaracha", 3,23}, {"El raton vaquero", 4,13}};
	FILE *archb = fopen(argv[1], "wb");
	FILE *archt = fopen(argv[2], "w");

	if(archb ==NULL || archt ==NULL)
	{
		printf("Error no se pudieron abrir los archivos\n");
		exit(0);
	}
	escribirTexto(c, archt, 2);
	escribirBinario(c, archb, 2);


	fclose(archt);
	fclose(archb);
	return 0;
}