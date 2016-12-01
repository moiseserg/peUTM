#include <stdio.h>
#define T 100

void capturar(char m[T][T], int *f, int *c){
	scanf("%d%d\n", f, c );

	for(int i=0; i< *f; i++)
		gets( m[i] );
		//scanf("%s", m[i]);
}

void imprimir(char m[T][T], int f, int c){
	for(int i=0; i<f; i++){

		for(int j=0; j<c; j++)
			printf("%c",m[i][j] );

		printf("\n");
	}

}

void contar(char m[T][T], int i, int j, 
	int f, int c, int *cont){

	if( i<0 || j <0 || i>=f || j>=c){
		return ;
	}
	if(m[i][j] == '1'){
		(*cont)++ ;
		m[i][j] = '2';

		contar(m, i+1, j, f,c, cont );
		contar(m, i-1, j, f,c, cont );
		contar(m, i, j+1, f,c, cont );
		contar(m, i, j-1, f,c, cont );			
	}
}


int main(){
	int f, c;
	char m[T][T];
	capturar(m, &f, &c);
	imprimir(m,f,c);

	for(int i=0; i<f; i++){
		for(int j=0; j<c; j++){
			if(m[i][j]=='1'){
				int cont=0;
				contar(m, i, j, f,c , &cont  );
				printf("(%d %d) %d\n",i,j, cont );
			}
		}
	}

	imprimir(m,f,c);

	return 0;
}