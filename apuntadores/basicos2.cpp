#include <stdio.h>

int main(){
	char dicc[5][16] = {"boo", "ahi",
						 "ay", "ja ja"};
	char *vptr[5];
	char *vptr2[]={NULL,NULL,NULL,NULL,NULL};
	char *vptr3[10]={NULL};

	int i;	
	for( i = 0; dicc[i][0] != '\0'; i++ )
//		puts(dicc[i]);
		printf("%p %s\n", dicc[i], dicc[i] );

	printf("\n>> %p\n", dicc );
}

