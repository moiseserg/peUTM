#include <stdio.h>
#include <stdlib.h>

int bbinaria(int v[], int izq, int der, int busca){


}


int mainx(){
	int v[10] = {2,3,4,5,9,12,15,23,28,30};
	for(int i=0; i<=32; i++){
		printf("%d\n",  bbinaria(v, 0, 9, i));			
	}
}


int compara(const void *p, const void *q){
	int *pp = (int *)p;
	int *qq = (int *)q;
	return *pp - *qq;
}

int main(){
	int v[10] = {2,3,4,5,9,12,15,23,28,30};
	for(int i=0; i<=32; i++){
		int *ptr =(int *)bsearch(&i, v, 10, sizeof(int), compara);

		if(ptr)
			printf("%d está en la pos %d\n", i,  (int)(ptr-v) );		
		else
			printf("%d no está en el vector\n", i );
		
	}

	//printf("%d\n",  bbinaria(v, 0, 9, i));		
}







