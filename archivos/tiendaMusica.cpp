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

int main(){

	D discos[20];

	C canciones[20];
	char linea[50];
	FILE *arch = fopen("entrada.txt", "r");

	int i=0;

	while(1){
		fgets(linea, 50, arch);
		linea[strlen(linea)-1] = '\0';
		if(strcmp(linea,"QUERY")==0)
			break;

		//datos del album
			//nombre
			strcpy(discos[i].nombre, linea);

			//genero
			fgets(discos[i].genero, 50, arch);
			discos[i].genero[strlen(discos[i].genero)-1] = '\0';
			//artista
			fgets(discos[i].artista, 50, arch);
			discos[i].artista[strlen(discos[i].artista)-1] = '\0';
			//archivo
			fgets(discos[i].archivo, 50, arch);
			discos[i].archivo[strlen(discos[i].archivo)-1] = '\0';
			
			printf("\n%s\n%s\n%s\n%s\n", discos[i].nombre, 
					discos[i].genero,
					discos[i].artista,
					discos[i].archivo);

			//lectura de las canciones
			int j=0;
			while(1){
				fgets(linea, 50, arch);
				linea[strlen(linea)-1] = '\0';

				//Si no hay mas canciones (hay una linea en blanco)
				if(strlen(linea)==0)
					break;

				strcpy(canciones[j].pista, linea);
				fgets(linea, 50, arch);
				sscanf(linea, "%d %d", 
					&canciones[j].mins, &canciones[j].segs);
				j++; //numero de canciones
			}

			//fopen discos[i].archivo
			FILE *arch2 = fopen(discos[i].archivo, "wb");

			//if(NULL)
			//fwrite
			fwrite(canciones, sizeof(C), j, arch2);

			//fclose
			fclose(arch2);

			i++;		
			
	}

	//CONSULTAS
	while(0){
		fgets(linea, 50, arch);
		linea[strlen(linea)-1] = '\0';
		if(strcmp(linea,"END")==0)
			break;
		
	}


}

/*
Exitos de Juan Gabriel
Musica regional mexicana
Juan Gabriel
juangabriel.bin
cucurrucucu paloma
5 12
hasta que te conoci
3 18

Mi amigo bronco
Musica regional mexicana
Bronco
bronco.bin
Mi amigo bronco
3 25
La escuelita
2 23

More than words
rock
Extreme
extreme.bin
More than words
4 25
Can't help falling 
2 36

QUERY
artista:Juan Gabriel
artista:Bronco
genero:Musica regional mexicana
album:Mi amigo bronco
END

*/