#include <stdio.h>
 

int main(){
	int m[101][100];

	int n;

	scanf("%d", &n);

	for( int i=0; i<n; 	i++ ){
		for( int j=0; j<n; 	j++ ){
			scanf("%d", &m[i][j]);			
		}
	}



	for( int i=0; i<n; 	i++ ){
		for( int j=0; j<n; 	j++ ){
			printf("%5d", m[i][j]);			
		}
		printf("\n");
	}

	int suma=0, i, j;

	for( i=0; i<n; 	i++ ){
		suma += m[i][i];
	}

	printf("suma2 %d\n", suma);

	int suma2 =0;
	for(i=0, j=n-1; i<n; 	i++ , j--){
		suma2 += m[i][j];
		printf("[%d %d ]= %d\n", i, j, m[i][j] );
	}
	printf("suma2 %d\n", suma2);


	for( int i=0; i<n; 	i++ ){
		int s=0;
		for( int j=0; j<n; 	j++ ){
			printf("[%d %d ]= %d   ", i, j, m[i][j] );
			s+= m[i][j];
		}
		printf(" --> %d\n", s);
	}

	return 0;
}