#include <stdio.h>

int main(){
	char dicc[5][16] = {"boo", "ahi", "ay", "ja ja"};
	char *vptr[5];
	char *vptr2[]={NULL,NULL,NULL,NULL,NULL};
	char *vptr3[10]={NULL};
	int a = 123456789;
	char *p=(char *)(&a); //casting para poder accesar a los datos
	int i;

	
	for( i = 0; dicc[i][0] != '\0'; i++ )
		puts(dicc[i]);

	for(i=0; i<5; i++){
		vptr[i] = dicc[i];
		printf("%p  %p %s \n", dicc[i], vptr[i], vptr[i] );

	}

	//usa el apuntador a char para accesar a los datos internos
	//del tipo int  
	//little endian / big endian
	printf("%x %x %x %x\n", *(p), *(p+1), *(p+2), *(p+3) );

}

