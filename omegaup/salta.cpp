#include <stdio.h>

int absoluto(int n){
	return n>=0? n: -n;
}


int main(){
		
	int n, actual,ant, saltos[10000]={0};
	scanf("%d", &n);

	scanf("%d", &ant);

	for( int i=1; i<n; 	i++ ){
		scanf("%d", &actual);		
		int dif=absoluto( actual - ant);
		//printf("d %d\n" , dif);
		saltos[dif]++;
		ant = actual;
	}

	int respuesta = 0;
	for( int i=1; i<n; 	i++ ){
		//printf("[%d] %d \n", i, 	saltos[i] );	
		if(saltos[i]==0){
			respuesta=i;
			break;
		}
	}

	printf("%d\n",respuesta );

	return 0;
}