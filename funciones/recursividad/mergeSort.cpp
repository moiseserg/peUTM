#include <stdio.h>

void mezcla(int r[], int a[], int b[], int na, int nb){
	int i=0, j=0, k=0;
	while(i<na && j <nb){
		if(a[i]<b[j])
			r[k++] = a[i++];
		else if (a[i]>b[j])
			r[k++] = b[j++];
		else{
			r[k++] = b[j++];
			r[k++] = a[i++];
		}
	}

	for(;i<na;)
		r[k++] = a[i++];
	for(;j<nb;)
		r[k++] = b[j++];
			
}

void imprimirVector(int v[], int n){

	for (int i = 0; i < n; ++i)
	{
		printf("%d ",v[i] );
	}
	printf("\n");
}

void ms(int v[], int aux[], int izq, int der){
	int m = (izq + der)/ 2 ;
	//printf("ms(%d %d)\n", izq, der);

	if(izq<der){

		ms(v, aux, izq,  m);
		ms(v, aux, m+1, der);

		///merge
		mezcla(?,?,?,?,?);
		
		//copiar los datos al vector original
		for(int i=0; i< der-izq+1; i++)
			v[?]  = aux[?];
	}


}


int main(){
	int v[100] = {1,22,13,44,35,12,4,35,36,48,19,32,12}, aux[100];
	

/*	imprimirVector(v, 5);
	imprimirVector(v+5, 5);

	mezcla(aux, v, v+5, 5,5);
	imprimirVector(aux	, 10);	
*/
	imprimirVector(v	, 11);	
	ms(v, aux, 0, 10);
	imprimirVector(v	, 11);	

	return 0;
}
