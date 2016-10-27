#include <stdio.h>

void imprimeCadena(char v[10]){
	int i;
	for( i=0; v[i] != '\0'; i++)
		printf("%c ", v[i] );
	printf("\n");
}


int main(){
	char txt[10]= "casa";

	printf("%s\n", txt);
	imprimeCadena(txt);
}
