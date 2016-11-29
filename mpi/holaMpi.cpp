#include <mpi.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    int aleatorios[100];



    srandom(time(NULL));


    // Get the number of processes
    int world_size, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	MPI_Comm_rank (MPI_COMM_WORLD, &rank);	/* get current process id */
    printf("Numero de procesos %d \n", world_size);
    printf("Hilo actual %d \n", rank);

    
	for(int i=0;i<100; i++)
		aleatorios[i] = random()%100+rank*50;

	int minimo = aleatorios[0];

	for(int i=0;i<100; i++){
		if(aleatorios[i]<minimo)
			minimo = aleatorios[i];

	}

	printf("Minimo en  %d  es %d \n", rank, minimo);





    

    // Finalize the MPI environment.
    MPI_Finalize();
}

