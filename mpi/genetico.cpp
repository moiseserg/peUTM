#include <mpi.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define T 100


struct P{
	unsigned int v;
	float aptitud;
};


float aprox[201];

int inicializar(P pob[100]){
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



void cruza(P pob[]){
	P aux[100];
	unsigned int masks[32];

	for (int i = 0, b=0 ; i < 32; ++i){
		masks[i] = (1<<(i+1))-1;
		printf("%x\n", masks[i]);
	}

	for(int i=0 ;i < T ; i++){
		int pos=random()%30+1;
		int p1 = random()%(T/2);		
		int p2 = random()%(T/2);
		//TO DO:
	}

	for(int i=0 ;i < T ; i++){
		pob[i] = aux[i];
	}

}


int main(){
	P pob[T];
	srand(time(NULL));
	inicializar(pob);
	evaluaPoblacion(pob);
	cruza(pob);



	return 0;
}
