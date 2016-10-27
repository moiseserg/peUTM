#include <stdio.h>

int  longCadena(char txt[]){
	int i=0;
	for ( i = 0; txt[i]!= '\0'; ++i){	}
	return i;
}
int invertirCadena( char txt[]){
	int i=0;
	int j= longCadena(txt)-1;

	for(  ; i<j ; i++, j--){
		char t = txt[i];
		txt[i] = txt[j];
		txt[j] = t;
	}


}

void copiaCadena(char b[], char a[] ){
	// b <= a
	int i;
	for(i =0 ; a[i] != '\0'; i++)
		b[i] = a[i];
	//b[i] = a[i];
}


int main(){
	char txt[80]= "algun texto", otra[100];
	printf("%s -> %d\n",txt, longCadena(txt) );
	invertirCadena(txt);	
	printf("cadena invertida %s \n",txt);

	copiaCadena(otra, txt);
	printf("copia %s %s\n", otra, txt );

	return 0;
}
