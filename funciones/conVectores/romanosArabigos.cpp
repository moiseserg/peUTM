#include <stdio.h>

int valorRomano(char c){
	printf("valorRomano %c \n",c );
	switch(c){
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;		
	}
	return 0;
}


int getArabigo(char r[]){
	int i, suma=0;
	
	for( i=0; r[i]!='\0' ; i++)
		if(valorRomano(r[i])<valorRomano(r[i+1]))
			suma -= valorRomano(r[i]);
		else
			suma += valorRomano(r[i]);

	return suma;
}

int main(){
	int  suma=0;
	char r[20];
	gets(r);	
	printf("%d\n",  getArabigo(r));
}

/*
./romanosArabigos 
CCCXLIX
349
*/
