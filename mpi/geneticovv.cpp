#include <mpi.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>


#define T 40
unsigned int masks[32];
unsigned int masksc[32];
FILE *arch = NULL;


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
			 return 1e20;
		else
			dif = aprox[j] - (a*sin(i/b)+c*cos(i*i/d));

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

void printElemento(P p, char msg[]){

/*	int d = v & 0xff;
	int c = (v>>8) & 0xff;
	int b = (v>>16) & 0xff;
	int a = (v>>24) & 0xff;*/

	printf("%s ", msg );

	for(int i=24; i>=0; i-=8 )
		binario( ( p.v >> i) & 0xff, 8);

	for(int i=24; i>=0; i-=8 )
		printf("%4d ", ( p.v >> i) & 0xff);

	printf("%10.4f\n", p.aptitud);
}

void evaluaPoblacion(P pob[], int n){

	
	#pragma omp parallel for
	for (int i = 0; i < n; ++i){
		pob[i].aptitud = evalua(pob[i].v);
	}

	//qsort(pob, n, sizeof (P), compara);

	/*for (int i = 0; i < 2; ++i){
		//printf("%4d) %15.5f\n",i, pob[i].aptitud );
		printElemento(pob[i], "eval ");
	}*/
}

void mascaras(){

	for (int i = 0, b=0 ; i < 32; ++i){
		masks[i] = (1<<(i+1))-1;
		masksc[i] = ~masks[i];
		//printf("%x %x\n", masksc[i], masks[i]);
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

int main(int argc, char** argv) {
 
	P pob[T];
	int nPob = 35;
	srand(time(NULL));

	MPI_Init(&argc, &argv);

		

		int  size, rank;
	    MPI_Status status;

	    MPI_Comm_size(MPI_COMM_WORLD, & size);
		MPI_Comm_rank (MPI_COMM_WORLD, &rank);	/* get current process id */

		char s[100] ;
		sprintf(s,"salida%02d.txt", rank );
	 	freopen(s, "w", stdout);



	    printf("Numero de procesos %d \n",  size);
	    printf("Hilo actual %d \n", rank);

		mascaras();
	    if(rank==0){
	   		inicializar(pob);

	   		//printf("%d\n", (int)sizeof(P));


			for(int ii=0; ii<nPob; ii++){
				printf("\n\nGeneracion %d\n", ii+1);

		   		for(int i=1; i<4; i++){
					
					 

					MPI_Send(
						(int *)(pob+T/4*i) , // ptr a los datos
						T/2, //cant de datos a enviar  T/4
						MPI_INT, //tipo de dato
						i, //rank del destino 
						7, 
						MPI_COMM_WORLD
					);

					for(int w=0; w<2; w++)
						printElemento(pob[T/4*i+w], "mtr env 1");
					
				}

		    	printf("Envio los datos a el resto de los hilos\n");

				evaluaPoblacion(pob, T/4);

				for(int i=1; i<4; i++){
					MPI_Recv(
						(int *)(pob+T/4*i), // ptr a los datos
						T/2, //cant de datos a enviar
						MPI_INT, //tipo de dato
						i,  //rank de quien envio los datos
						17, //etiqueta
						MPI_COMM_WORLD, //mundo
						&status //status de la comunicacion
					);

					printf("Recibe de los esclavos\n");
					for(int w=0; w<T/4; w++){
						char mm[100] ;
						sprintf(mm, "mtr rcv %d %06d ",i, T/4*i+w );
						printElemento(pob[T/4*i+w], mm);
						//printElemento(pob[T/4*i+w], "mtr rcv");
					}
				}

				printf("Recibidos los datos del resto de los hilos\n");

				qsort(pob, T, sizeof (P), compara);


				for(int w=0; w<T; w++){
					char mm[100] ;
					sprintf(mm, "mtr qst %06d " , w ); 
					//printElemento(pob[w], "mst qsort ");
					printElemento(pob[w], mm);
				}

				cruza(pob);
				mutar(pob, T/10);



			}

	    }
	    else{


			for(int ii=0; ii<nPob; ii++){
		    	MPI_Recv(
					(int *)pob, // ptr a los datos
					T/2, //cant de datos a enviar
					MPI_INT, //tipo de dato
					0,  //rank de quien envio los datos
					7, //etiqueta
					MPI_COMM_WORLD, //mundo
					&status //status de la comunicacion
				);

				for(int w=0; w<2; w++)
					printElemento(pob[w], "recv th   ");


		    	//printf("Recibidos los datos desde el master (%d) \n", rank);
				evaluaPoblacion(pob, T/4);
				for(int w=0; w<2; w++)
					printElemento(pob[w], "recv th evl");

				MPI_Send(
					(int *)pob , // ptr a los datos
					T/2, //cant de datos a enviar  T/4
					MPI_INT, //tipo de dato
					0, //rank del destino 
					17, 
					MPI_COMM_WORLD
				);


				printf("Enviados los datos hacia master (%d)\n", rank);
	    	}

	    }
	

/*
	for(int i=0; i<100; i++){
		printf("Generacion %d\n", i+1 );
		evaluaPoblacion(pob);
		cruza(pob);
		mutar(pob, T/10);
	}
*/
    MPI_Finalize();


	return 0;
}
