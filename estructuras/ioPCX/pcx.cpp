#include <stdio.h>

typedef struct imagen{
	int xmin, xmax, ymin, ymax;
	int ancho, alto;
} I;

int main(int argc, char  const  *argv[]){
	if(argc>1)
		printf("%s %s \n", argv[0],argv[1]);
	FILE *arch;
	I img;
	arch= fopen(argv[1],"rb");
	if(arch==NULL)
		printf("ERROR \n");
	
	int i=0;
	while(i<128){

		unsigned int valor=fgetc(arch);

		switch(i){
			case 4: img.xmin = valor; break;
			case 5: img.xmin += valor<<8; break;
			case 6: img.ymin = valor; break;
			case 7: img.ymin += valor<<8; break;
			case 8: img.xmax = valor; break;
			case 9: img.xmax += valor<<8; 
					 img.ancho = 1+img.xmax;	
					 break;
			case 10: img.ymax = valor; break;
			case 11: img.ymax += valor<<8; 
					 img.alto = 1+img.ymax;	
					 break;
		}

		printf("(%3d) %2x ",i++, valor );
		if(i%10==0)
			printf("\n");
	}

	printf("\n\nArchivo %s ancho %d alto %d \n", argv[1], img.ancho, img.alto);

	int fila=0, col=0;
	while(fila<img.alto){
		int valor = fgetc(arch);
		if(valor >= 0xc0){
			int rep = 0x3f & valor; /// valor - 0x3c;
			valor = fgetc(arch);
			for( ;  rep--; ){
				printf("%3x ",valor );
				col = (col +1 )%img.ancho;
				if(col==0){
					printf("\n");
					fila++;
				}
			}
		}
		else{
			printf("%3x ",valor );
			col = (col +1 )%img.ancho;
			if(col==0){
				printf("\n");
				fila++;
			}
		}
	}


}