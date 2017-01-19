#include <stdio.h>
#include <stdlib.h>

int * funcion(int *a, int na, int *b, int nb, int *n){
	int *r, i, j, band ,cont  =0 ;

	for(i=0; i<na; i++){
		band =0;
		for(j=0; j<nb && band==0; j++){
			if( *(a+i) == *(b+j)){
				band = 1;
				cont++;
			}
		}
	}
	printf("%d\n", cont );

	r = (int * )malloc(sizeof(int)*cont);
	*n = cont;
	cont =0;
	for(i=0; i<na; i++){
		band =0;
		for(j=0; j<nb && band==0; j++){
			if( *(a+i) == *(b+j)){
				band = 1;				
				*(r+cont) = *(a+i);//r[ cont] = a[i]
				cont++;
			}
		}
	}


	return r;
}



int main(){
	int a[] = {3,4,10,6,8,7};
	int b[] = {2,4,6,14,10,12,8,16,5};
	int n;
	int *r = funcion(a, 6, b,9 , &n);

	for(int i=0; i<n; i++)
		printf("%d\n", *(r+i) );

	return  0;
}