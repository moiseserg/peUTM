#include <stdio.h>

void capturar(char m[100][100], int f)
{	int i;
	for(i=0; i<f; i++){
		gets(m[i]);
		//scanf("%s",m[i]);
	}
}
void escribir(char m[100][100], int f){
	int i;
	for(i=0; i<f; i++){
		puts(m[i]);
	}
}

void convertirMayusculas(char m[100][100], int f, int c){
	int i, j;
	for(i=0; i<f; i++)
		for(j=0; j<c; j++){
			if(m[i][j] >= 'a' &&  m[i][j] <= 'z' ){
				m[i][j] -=32;
			}
		}
}

int main()
{
	char m[100][100] = {'\0'};
	int f, c, i;
	scanf("%d%d\n", &f, &c);
	capturar(m, f);
	escribir(m, f);
	convertirMayusculas(m, f,c);
	escribir(m, f);
	
	
	return 0;
}
