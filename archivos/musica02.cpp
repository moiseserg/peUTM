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
	C canciones[22];
	int ndiscos=0;
	char linea[100];
	FILE *arch2 =NULL;

	while(1){
		
		fgets(linea, 100, arch );
		linea[ strlen(linea )-1]= '\0';				
		printf("**%s**\n",linea );


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
		int npistas=0;
		//lectura de cada pista
		while(1){
			fgets(linea, 100, arch );
			linea[ strlen(linea )-1]= '\0';				

			if(strlen(linea)==0)
				break;  //no hay mas pistas
			strcpy(canciones[npistas].pista, linea);


			fgets(linea, 100, arch );
			//linea[ strlen(linea )-1]= '\0';				
			sscanf(linea,"%d%d", &canciones[npistas].mins, &canciones[npistas].segs );
			npistas++;
		}

		arch2 = fopen(discos[ndiscos].archivo ,  "wb");
		fwrite(canciones, sizeof(C), npistas, arch2);
		fclose(arch2);

		ndiscos++;
		printf("disco %d\n", ndiscos );
	}

	printf("QUERY\n");

	while(1){
			fgets(linea, 100, arch );
			linea[ strlen(linea )-1]= '\0';				
			printf("\nQ:%s\n",linea);

			if(strcmp(linea, "END")==0)
				break;  //no hay mas consultas

			//procesar consulta
			char *campo = strtok(linea, ":"); 
			char *query = strtok(NULL, ":"); 

			for(int i=0; i<ndiscos; i++){
				arch2 = NULL;
				if(!strcmp(campo, "artista") && !strcmp(query, discos[i].artista)){
					arch2 = fopen(discos[i].archivo, "rb");					
				}
				else if(!strcmp(campo, "genero") && !strcmp(query, discos[i].genero)){
					arch2 = fopen(discos[i].archivo, "rb");					
				}
				else if(!strcmp(campo, "album") && !strcmp(query, discos[i].nombre)){
					arch2 = fopen(discos[i].archivo, "rb");					
				}

				if(arch2){
					printf("\nAlbum  : %s\n",discos[i].nombre );
					printf("Género : %s\n",discos[i].genero );
					printf("Artista: %s\n",discos[i].artista );

					while(1){
						fread(&canciones[0],sizeof(C), 1, arch2);
						if(feof(arch2))break;
						printf("%-20s %02d:%02d\n", 
							canciones[0].pista, canciones[0].mins, canciones[0].segs );
					}

					fclose(arch2);
				}

			}


		}
	return 0;
}