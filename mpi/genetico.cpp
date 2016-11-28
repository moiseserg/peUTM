#include <mpi.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define T 200000
unsigned int masks[32];
unsigned int masksc[32];

struct P{
	unsigned int v;
	float aptitud;
};


float aprox[201];

int inicializar(P pob[T]){
	for(int i=0; i< T; i++)
		pob[i].v= random();

	int j=0;
	double  i=-10.0;
	for(; i<= 10.0; i+=0.1)
		aprox[j++] = 75*sin(i/12)+168*cos(i*i/27);
}

float evalua(unsigned int v){
	int d = v & 0xff;
	int c = (v>>8) & 0xff;
	int b = (v>>16) & 0xff;
	int a = (v>>24) & 0xff;

	int j=0;
	double i=-10.0, dif, sum=0;
	for( ; i<= 10.0; i+=0.1, j++){
		
		if(b==0 || d==0)
			dif =1e20;
		else
			dif = aprox[j] - a*sin(i/b)+c*cos(i*i/d);

		sum += dif>0.0?dif:-dif;
	}

	//TO DO: revisar cuando b, d son cero
	return sum;
}

int compara(const void *p, const void *q){
	P *pp = (P*)p; 
	P *qq = (P*)q;

	if( pp->aptitud == qq->aptitud)
		return 0;
	else if( pp->aptitud > qq->aptitud)
		return 1;

	return -1;
}

void binario(unsigned int i, int n){
	for( n-- ; n >=0; n--)
		printf("%d", (i>>n) & 1 );
	printf(" ");
}

void printElemento(P p){

/*	int d = v & 0xff;
	int c = (v>>8) & 0xff;
	int b = (v>>16) & 0xff;
	int a = (v>>24) & 0xff;*/

	for(int i=24; i>=0; i-=8 )
		binario( ( p.v >> i) & 0xff, 8);

	for(int i=24; i>=0; i-=8 )
		printf("%4d ", ( p.v >> i) & 0xff);

	printf("%10.4f\n", p.aptitud);
}

void evaluaPoblacion(P pob[]){
	for (int i = 0; i < T; ++i){
		pob[i].aptitud = evalua(pob[i].v);
	}
	qsort(pob, T, sizeof (P), compara);

	for (int i = 0; i < T/10; ++i){
		//printf("%4d) %15.5f\n",i, pob[i].aptitud );
		printElemento(pob[i]);
	}
}

void mascaras(){

	for (int i = 0, b=0 ; i < 32; ++i){
		masks[i] = (1<<(i+1))-1;
		masksc[i] = ~masks[i];
		printf("%x %x\n", masksc[i], masks[i]);
	}

}


void cruza(P pob[]){
	P aux[T];
	int j=0; //contador para aux

	
	for(int i=0 ;i < T/2 ; i++){
		int pos=random()%31;
		int p1 = random()%(T/2);		
		int p2 = random()%(T/2);
		//TO DO:
		aux[j++].v = (masksc[pos] & pob[p1].v) 
				  +(masks [pos] & pob[p2].v);

		aux[j++].v = (masksc[pos] & pob[p2].v) 
				  +(masks [pos] & pob[p1].v);

/*		printf("\nMask %x %x\n", masksc[pos], masks[pos]);	  
		printf("orig %x %x\n", pob[p1].v, pob[p2].v);
		printf("Res  %x %x\n", aux[j-1].v, aux[j-2].v);
*/

	}

	for(int i=0 ;i < T ; i++){
		pob[i] = aux[i];
	}

}


void mutar(P pob[], int cuantos){
	
	for(int i=0 ;i < cuantos ; i++){
		int pos=random()%T;	
		int bit=random()%32;	
		pob[pos].v =  pob[pos].v ^ (1<<bit);
	}
}

int main(){
	P pob[T];
	srand(time(NULL));
	inicializar(pob);
	mascaras();


	for(int i=0; i<100; i++){
		printf("Generacion %d\n", i+1 );
		evaluaPoblacion(pob);
		cruza(pob);
		mutar(pob, T/10);
	}



	return 0;
}
