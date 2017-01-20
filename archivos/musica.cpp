#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cancion{
	char pista[20];
	int mins, segs;
} C;

typedef struct disco{
	char nombre[40];
	char artista[40];
	char genero[40];
	char archivo[40];
} D;

int main()
{
	FILE *arch = fopen("entrada.txt", "r");
	if(arch==NULL){
		printf("Error\n");exit(0);
	}
	D discos[20];
	int ndiscos=0;

	while(1){
		char linea[100];
		fgets(linea, 100, arch );
		//printf("**%s**\n",linea );
		linea[ strlen(linea )-1]= '\0';				

		if(strcmp(linea,"QUERY")==0)
			break;

		strcpy(discos[ndiscos].nombre, linea);
		//genero
		//fgets(linea, 100, stdin);
		//linea[ strlen(linea )-1]= '\0';		
		//strcpy(discos[ndiscos].genero, linea);
		
		fgets(discos[ndiscos].genero,  100, arch);
		discos[ndiscos].genero[strlen(discos[ndiscos].genero) -1 ]= '\0';

		fgets(discos[ndiscos].artista, 100, arch);
		discos[ndiscos].artista[strlen(discos[ndiscos].artista) -1 ]= '\0';

		fgets(discos[ndiscos].archivo, 100, arch);
		discos[ndiscos].archivo[strlen(discos[ndiscos].archivo) -1 ]= '\0';
		
		printf("%s\n%s\n%s\n%s\n", discos[ndiscos].nombre, 
									discos[ndiscos].genero,
									discos[ndiscos].artista,
									discos[ndiscos].archivo );
		ndiscos++;
		break;
	}


	return 0;
}