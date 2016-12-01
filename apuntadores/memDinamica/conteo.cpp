#include <stdio.h>
#define T 100

void capturar(char m[T][T], int *f, int *c ){

	scanf("%d%d\n", f, c);
	for (int i = 0; i < *f; ++i)
		gets( m[i] );
}

void imprimir(char m[T][T], int f ){	
	for (int i = 0; i < f; ++i)
		puts( m[i] );
}

void contar(char m[T][T], int i, int j, 
		int f, int c, int *cont
	){

	if( i<0 || j <0  || i >= f ||  j >= c)
		return ;

	if(m[i][j] == '1'){
		m[i][j] = '2';
		(*cont)++;
		contar(m, i+1, j, f, c, cont);
		contar(m, i-1, j, f, c, cont);
		contar(m, i, j-1, f, c, cont);
		contar(m, i, j+1, f, c, cont);
	}
}


int main(){
	char m[T][T];
	int f, c, cont;
	capturar(m, &f, &c);
	imprimir(m, f);

	for (int i = 0; i < f; ++i)
	
		for(int j=0; j<c; j++){
			if(m[i][j] =='1'){
				cont =0;
				contar(m, i, j, f, c, &cont);
				printf("(%d %d) %d\n", i, j, cont );
			}
		}
	
}



