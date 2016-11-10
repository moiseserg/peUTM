#include <stdio.h>

void imprimirVocal(char c){

	switch(c){
		case 'a':
 		case 'e':
 		case 'i':
 		case 'o':
 		case 'u':
 		case 'A':
 		case 'E':
 		case 'I':
		case 'O':
 		case 'U':
 					printf("%c",c );
	}
}

int main(){

	char txt[10000], *ptr;


	while(1){

		gets(txt);

		if(feof(stdin)) break;

		ptr = txt;
		while(*ptr != '\0') {
			imprimirVocal(*ptr);
			ptr++;
		}
		printf("\n");

	}
	

	return 0;
}
