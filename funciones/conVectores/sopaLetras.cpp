// Ejemplo no terminado
#include <stdio.h>
#include <string.h>

void capturar(char [100][100], int);
void imprimir(char [100][100], int);

int buscar1(char [100][100], int, int, char []);
int buscar2(char [100][100], int, int, char []);


int main(){
    int f, c, cuantas, i;
    char d[100][100]={'\0'}, palabra[100];

    scanf("%d%d", &f,&c);
    capturar(d, f);
    imprimir(d, f);

    scanf("%d", &cuantas);
    printf(" leido %d\n", cuantas );
    for ( i = 0; i < cuantas; ++i)
    {
        scanf("%s", palabra);
        printf("\nBuscando %s\n", palabra );

		// lógica de esta llamada?
        buscar1(d, f,c, palabra) ||    buscar2(d, f,c, palabra);

    }

    return 0;
}

void capturar(char m[100][100], int f){

    for (int i = 0; i < f; ++i)
    {
        //gets(m[i]);
        scanf("%s", m[i]);
        //scanf("%s", &m[i][0]);
    }
}

void imprimir(char m[100][100], int f){

    for (int i = 0; i < f; ++i)
    {
        printf("%s\n", m[i]);
    }
}

int buscar1(char m[100][100], int f, int c, char p[]){
    int lp = strlen(p);
    for (int i = 0; i < f; ++i)
    {
        for (int j = 0; j < c-lp+1 ; ++j)
        {
            printf("Buscando en %d %d -> %c\n", i, j, m[i][j] );
            if(p[0] == m[i][j]){
                int b=0; //Asumir que si está
                int k = j; //posicion sobre la matriz
                int l = 0; // poscion sobre la palabra
                for (; l < lp; ++k, l++)
                {
                    if(p[l] != m[i][k])
                        b=1;
                }
                //no cambio la bandera => si está
                if(b==0){
                    printf("Está en %d %d\n",i,j );
                    return 1;
                }
            }
        }
    }
    return 0;
}



int buscar2(char m[100][100], int f, int c, char p[]){
    int lp = strlen(p);
    for (int i = 0; i < f-lp+1; ++i)
    {
        for (int j = 0; j < c ; ++j)
        {
            printf("Buscando en %d %d -> %c\n", i, j, m[i][j] );
            if(p[0] == m[i][j]){
                int b=0; //Asumir que si está
                int k = i; //posicion sobre la matriz (fila)
                int l = 0; // poscion sobre la palabra
                printf("   %c != %c? \n",p[l],  m[k][j] );
                for (; l < lp; ++k, l++)
                {
                    printf("   %c != %c? \n",p[l],  m[k][j] );
                    //Alguna diferencia, indica que no está
                    if(p[l] != m[k][j]){
                        b=1;
                        break;
                    }
                }

                //no cambio la bandera => si está
                if(b==0){
                    printf("Está en %d %d\n",i,j );
                    return 1;
                }
            }
        }
    }
    return 0;
}
