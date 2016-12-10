#include <stdio.h>
void imp(int v[100][100], int n){
	int i, j;
	for (i=0; i<n; i++){
		for (j=0; j<n; j++)
			printf("%d ", v[i][j]);
		printf("\n");
	}
}
void secuenci(int v[100][100],int n, int f, int c, int num){
	if (f<n){
		if (c<n){
			num+=1;
			v[f][c]=num;
			secuenci(v, n, f, c+1, num);
		}
		else 
			secuenci (v, n, f+1,0 , f+1);
	}
}
int main (){
	int v[100][100], n;
	scanf ("%d", &n);
	secuenci(v, n, 0, 0, 0);
	imp(v, n);
	
	return 0;
}
