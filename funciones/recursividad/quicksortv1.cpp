#include <stdio.h>

int partition( int a[], int izq, int der) {
    int pivote, i, j, t;
    pivote = a[izq];
    i = izq; j = der;

    while( i<j)
    {

        while( a[i] <= pivote   && i<der )
            i++;
        while( a[j] > pivote && j)
            j--;

        if(i<j) {
            t = a[ i ];
            a[ i ] = a[ j ];
            a[ j ] = t;
        }
    }

    t = a[izq];
    a[izq] = a[j];
    a[j] = t;

    return j;
}


void printArray(int v[], int n){
    int i;
    for(i = 0; i < n; ++i)
        printf(" %d ", v[i]);
    printf("\n");
}

void quickSort( int a[], int izq, int der)
{
    int j;

    printf ("\nqsort(%d %d)\n", izq, der);
    if( izq < der ){
        // divide y conquista
        j = partition( a, izq, der);
        printArray (a, 9);
        printf ("\nparticion = a[%d]= %d --> qs(%d %d), qs(%d %d)\n", j, a[j], izq, j-1, j+1, der);
        quickSort( a, izq, j-1);
        quickSort( a, j+1, der);
    }
}


int main(){

    int a[] = { 7, 12, 1, -2, 0, 15, 4, 11, 9};

    int i;
    printf("\n\nAntes de ordenar:  \n");
    printArray (a, 9);
    quickSort( a, 0, 8);
    printf("\n\nDespués de ordenar:  \n");
    printArray (a, 9);
}
