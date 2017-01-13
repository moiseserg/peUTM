#include <stdio.h>
#include <stdlib.h>

typedef struct imagen{
	int xmin, xmax, ymin, ymax;
	int ancho, alto;
} I;


int main(int argc, char *argv[])
{
	FILE *arch ;
	I img ;
	arch = fopen(argv[1], "rb");
	if(arch ==NULL){
		printf("Error no se pudo abrir\n");
		exit(0);
	}

	for(int i=0; i<128; i++){
		int valor= fgetc(arch);
		printf("%02x ",valor );
		
		if(i%8 ==7)
			printf("\n");

		switch(i){
			case 4: img.xmin = valor;break;
			case 5: img.xmin += valor<<8;break;
			case 6: img.ymin = valor;break;
			case 7: img.ymin += valor<<8;break;

			case 8:  img.xmax = valor;break;
			case 9:  img.xmax += valor<<8;
					img.ancho = img.xmax +1 ;
					 break;
			case 10: img.ymax = valor;break;
			case 11: img.ymax += valor<<8;
					 img.alto = img.ymax +1 ;
					 break;

		}
	}
	printf("%s \n%d %d %d %d\n", argv[1], img.xmin, img.ymin, img.xmax, img.ymax );
	printf("%d %d \n",img.ancho, img.alto );

	for(int filas=0, cols =0; filas < img.alto;  ){
		int val = fgetc(arch);

		if(val >= 0xc0){
			int rep = val & 0x3f;
			val = fgetc(arch);
			for(int k=0; k<rep; k++){
				printf("%02x ", val );

				cols = (cols+1) % img.ancho;
				if(cols==0)
				{
					filas++;
					printf("\n");
				}
			}
		}
		else
		{
			printf("%02x ", val );
			cols = (cols+1) % img.ancho;
			if(cols==0)
			{
				filas++;
				printf("\n");
			}
		}
	}


	fclose(arch);

}