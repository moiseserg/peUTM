#include <stdio.h>
#include <string.h>  
// c con clase 
// strlen, strcpy, strcmp, strcat, strstr
// https://github.com/moiseserg/peUTM/wiki
int longCadena(char []);
void copiaCadena( char [], char []);
void invertirCadena(char s[]);
int main(){
	char nombre[100], otra[100];
//	scanf("%s", nombre);
	//gets(nombre);
	scanf("%[a-z ]", nombre);
//	puts(nombre);	printf("%s\n",nombre );

	printf("Longitud de %s es %d\n", 		
		nombre, longCadena(nombre) );
	copiaCadena(otra, nombre);
	invertirCadena(otra);
	printf("%s %s\n", nombre, otra );
}

int longCadena(char nombre[100]){
	int i;
	for(i=0; nombre[i]!='\0'; i++){		
	}
	return i;
}

void copiaCadena( char dest[], char orig[])
{
	int i;
	for(i=0; orig[i]!='\0'; i++){		
		dest[i] = orig[i];
	}
	dest[i] = orig[i];
}

void invertirCadena(char s[]){

	int i = 0;
	int j = longCadena(s) -1;

	for(  ; i<j; i++, j--){
		//swap
		char t = s[i];
		s[i] = s[j];
		s[j] = t;

	}

}


