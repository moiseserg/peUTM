#include <mpi.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define T 100

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);
    FILE *arch;




    srandom(time(NULL));


    // Get the number of processes
    int world_size, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	MPI_Comm_rank (MPI_COMM_WORLD, &rank);	/* get current process id */
    
    MPI_Status status;

    char nombreArchivo[100] = "salida";
    sprintf(nombreArchivo, "%s%d.txt", nombreArchivo, rank);
    arch =fopen(nombreArchivo, "w");

    
    fprintf(arch, "Numero de procesos %d \n", world_size);
    fprintf(arch, "Hilo actual %d \n", rank);

	int asignacion[5]={0, T/4, T/2, 3*T/4, T };    

	//procesador 0
	if(rank ==0 ){
	    int aleatorios[T];

		for(int i=0;i<T; i++)
			aleatorios[i] = random()%100+rank*50;

		for(int i=0; i<T; i++)
			fprintf(arch, "%d) %d \n", i, aleatorios[i]);
		

		for(int i=1; i<4; i++)
		MPI_Send(
				aleatorios+T/4*i, // ptr a los datos
				T/4, //cant de datos a enviar
				MPI_INT, //tipo de dato
				i, //rank del destino 
				7, 
				MPI_COMM_WORLD
			);



	}
	//los otros procesadores
	else {
		int aleatorios[T/4];

				MPI_Recv(
					aleatorios, // ptr a los datos
					T/4, //cant de datos a enviar
					MPI_INT, //tipo de dato
					0,  //rank de quien envio los datos
					7, //etiqueta
					MPI_COMM_WORLD, //mundo
					&status //status de la comunicacion
				);

		for(int i=0; i<T/4; i++)
			fprintf(arch, "@%d %d) %d \n", rank, i, aleatorios[i]);
		
	}
//MPI_Status status;



    

    // Finalize the MPI environment.
    MPI_Finalize();
}

