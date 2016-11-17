#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void minusculas(char *t){
	while(*t) {
		if(*t>='A' && *t<='Z')
			(*t) += 32;
		else if( !(*t>='a' && *t<='z') )
			(*t) = 32;
		t++;
	}

}

int mainx(){

	char *dicc[100], txt[100];

	while(scanf("%s", txt)!=EOF){

		minusculas(txt);
		puts(txt);
	}

	return 0;
}

int estaEnDicc(char d[ ][20], int n, char *w){
//int estaEnDicc(char *d[], int n, char *w){

	printf("Esta en dicc  %s?\n",  w );
	for(int i=0; i<n; i++){
		printf("%s == %s?\n", d[i], w);
		if(strcmp(d[i], w)==0)
			return 1;
	}
	return 0;
}

void crearDiccionario( char d[ ][20], int *nd, char *txt){
//void crearDiccionario( char *d[], int *nd, char *txt){

	char *ptr = strtok(txt, " ");
	while(ptr){
		if(!estaEnDicc(d, *nd, ptr)){				
			strcpy(d[ (*nd)	], ptr);	
			*nd  += 1;
		}
		
		puts(ptr);
		ptr = strtok(NULL, " ");
	}

}
 

 void printDicc(char d[ ][20],  int n){
 //void printDicc(char *d[],  int n){ 	
 	printf("\nDiccionario\n");
 	for(int i=0; i<n; i++){
 		printf("%3d %s\n",i+1, d[i] );		
 	}
 }


void ordenamiento(char d[ ][20],  int n){
	
	char t[20];
	
	for(int i=0; i<n-1; i++){
		for(int j=i; j<n; j++){
			
			if(strcmp(d[i], d[j])> 0)
			{	
				
				strcpy(t, d[i]);
				strcpy( d[i], d[j]);
				strcpy( d[j], t);
			}
		}
	}
}

int main(){

	//char *dicc[100]={NULL};
	char dicc[1000][20]={""};
	char txt[100];
	
	int nd = 0;

	while(1){
		gets(txt);
		if(feof(stdin))
			break;
		minusculas(txt);
		puts(txt);
		crearDiccionario(dicc, &nd, txt);

		printDicc(dicc, nd);
	}


	return 0;
}

