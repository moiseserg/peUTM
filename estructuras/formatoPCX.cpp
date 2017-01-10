#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct imagen{
	char nombre[30];
	char tipo[10];
	char  version[30];
	int rle;
	int bitxpix;
	char bitxpixchar[30];
	int xmin, ymin, xmax,ymax;
	int ancho, alto;
	int resh, resv;
	int numPlanos;
	int bytesxlinea;
	int tipoPaleta;
} I;

void printImg(I i){
	printf("\n\nDatos de la imagen: %s\n", i.nombre);
	printf("Tipo de imagen: %s\n", i.tipo );
	printf("Versión de la  imagen: %s\n", i.version );
	printf("Codificación: %s\n", i.rle==1?" RLE": "No tiene");
	printf("Bits por pixel: %d (%s)\n",i.bitxpix,  i.bitxpixchar );

	printf("xmin: %d \n",i.xmin);
	printf("ymin: %d \n",i.ymin);
	printf("xmax: %d \n",i.xmax);
	printf("ymax: %d \n",i.ymax);
	printf("Ancho %d, Alto: %d\n", i.ancho, i.alto);

	printf("Resolución Horizontal: %d \n",i.resh);
	printf("Resolución Vertical  : %d \n",i.resv);
	
	printf("Número de planos: %d \n",i.numPlanos);
	printf("Bytes por línea  : %d \n",i.bytesxlinea);
	printf("Tipo de paleta: %s\n", i.tipoPaleta==1? "color": "Escala de grises");




}
FILE *abrirArchivo(  char nombre[]){
	FILE *a=NULL;
	if( (a=fopen(nombre, "rb"))==NULL)
		printf("Error, no se puede abrir el archivo: %s\n", nombre );
	return a;
}

I mostrarContenido(FILE *a, char narch[]){
	I img={""};
	strcpy(img.nombre, narch);
	int cont=0, c=0;
	while(!feof(a)){
		if(cont==0)
			printf("%6d) ", c );
		unsigned int val = fgetc(a);

		switch(c){
			case 0: 
				if(val==10)
					strcpy(img.tipo, "pcx");
				break;
			case 1:
				switch(val){
					case 0: strcpy(img.version, "Version 2.5");
							break;	
					case 2: strcpy(img.version, "Version 2.8 con paleta");
							break;	
					case 3: strcpy(img.version, "Version 2.8 paleta x defecto");
							break;	
					case 4: strcpy(img.version, "Paintbrush para windows");
							break;	
					case 5: strcpy(img.version, "Version 3.0 o superior");
							break;	
							
				}
				break;

			case 2:
				img.rle = val;
				break;
			case 3:
				img.bitxpix = val;
				switch(val){
					case 1: strcpy(img.bitxpixchar, "Monocromo");
							break;	
					case 4:strcpy(img.bitxpixchar, "16 colores");
							break;	
					case 8:strcpy(img.bitxpixchar, "256 colores");
							break;	
					case 24:strcpy(img.bitxpixchar, "16.7 millones de colores");
							break;					
 					}
				break;
			case 4: img.xmin = val;break;
			case 5: img.xmin += val<<8;break;
			case 6: img.ymin = val;break;
			case 7: img.ymin += val<<8;break;
			case 8: img.xmax = val;break;
			case 9: img.xmax += val<<8;break;
			case 10: img.ymax = val;break;
			case 11: img.ymax += val<<8;
					img.ancho = img.xmax-img.xmin +1;
					img.alto = img.ymax-img.ymin +1;
					break;
			case 12: img.resh  = val;break;
			case 13: img.resh += val<<8;break;
			case 14: img.resv  = val;break;
			case 15: img.resv += val<<8;break;

			case 65: img.numPlanos = val; break;
			case 66: img.bytesxlinea = val;break;
			case 67: img.bytesxlinea += val<<8;break;
			case 68: img.tipoPaleta = val;break;	
			
		}

		printf("%3x",val );
		if(cont==3 || cont==7 || cont ==11)
			printf(" ");
		if(cont==15)
			printf("\n" );
		cont=(cont+1)%16;
		c++;

		if(c==128)
			return img;
	}


	return img;
}	

unsigned int **reservarMatriz(int f, int c){
	unsigned int **m;
	m=(unsigned int **)calloc(f, sizeof(unsigned int *));

	for(int i=0; i<f; i++)
		m[i] = (unsigned int *)calloc(c, sizeof(unsigned int));

	return m;
}

void leer(unsigned  int **m, I im, FILE *a){

	int f=0, c=0;
	printf("%4d)  ",f );
	while(f<im.alto){
		unsigned int val = fgetc(a);
		if( feof(a) )
			break;

		if(val>=0xc0){
			printf("[%02x ", val);
			int rep=val & 0x3F;

			val = fgetc(a);
			printf("REP:( %02x %02x )] ",rep, val);

			while(rep--){
				*(*(m+f)+c) = val;
				c = (c+1)%im.ancho;
				if(c==0){
					f++;
					printf("\n%4d) ",f );
				}
			}
		}
		else{
			printf("[%02x ]", val);
			*(*(m+f)+c) = val;
			c = (c+1)%im.ancho;
			if(c==0){
					f++;
					printf("\n%4d) ",f );
				}
		}

	}

	printf("\nFin de lectura \n\n");
}

void imprimirImagenTXT(unsigned int **m, I im){

	for(int i=0; i<im.alto; i++){
		for(int j=0; j<im.ancho; j++){
			//if(j%4==0)	printf(" ");
			printf("%02x ",*(*(m+i)+j) );
		}
		printf("\n");
	}

}
int main(int argc, char   *argv[])
{
	FILE *arch=NULL;
	char narch[30]="./logoGris.pcx";
	I img;
	unsigned int **m=NULL;

	if(argc>=2)
		strcpy(narch, (char*)argv[1]);

	arch = abrirArchivo(narch);
	img= mostrarContenido(arch, narch);

	printImg(img);

	m=reservarMatriz(img.alto, img.ancho); //alto = filas

	leer(m, img, arch);
	imprimirImagenTXT(m, img);


	fclose(arch);
	return 0;
}
