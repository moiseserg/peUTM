#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){     
	FILE *salida=fopen(argv[1], "wb");

	int cabecera[128] ={
 0x0a,  0x05,  0x01,  0x08,  0x00,  0x00,  0x00,  0x00,  0x09,  0x00, 
 0x09,  0x00,  0x2c,  0x01,  0x2c,  0x01,  0x00,  0x00,  0x00,  0x00, 
 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00, 
 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00, 
 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00, 
 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00, 
 0x00,  0x00,  0x00,  0x00,  0x00,  0x01,  0x0a,  0x00,  0x02,  0x00, 
 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00, 
 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00, 
 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00, 
 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00, 
 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00, 
 0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00
	};

int datos[10][10]={
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
	0x00, 0x00, 0x00, 0x00, 0xFF, 0xff, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
	0xff, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
	0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

	for (int i = 0; i < 128; ++i)
		{
			fputc(cabecera[i], salida);
		}	

	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j){
			fputc(0xc1, salida);
			//fputc( ((i+j)%3)*100, salida);
			fputc( datos[i][j], salida);
		}

	fputc(0xc, salida);
	for (int i = 0; i < 256; ++i)
		{
			fputc(i, salida);
			fputc(i, salida);
			fputc(i, salida);
		}		

	fclose(salida);
	return 0;
}