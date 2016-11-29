#include <stdio.h>

void imprimir(char *v){

    if(*v != '\0'){
        printf ("%c", *v);

        imprimir (v+1);
    }
}

//v = a
void copiar(char *v, char *a){

    if(*a == '\0'){
        *v = *a;
    }
    else {
        copiar (v + 1, a + 1);
        *v = *a;
    }
}


//v = a
void copiar2(char *v, char *a, int n){
    *v = *a;

    if(*a != '\0' && n>0)
        copiar2 (v + 1, a + 1, n-1);

}






int main(){

        char k[]= "kevin", s[]="sandra", w[100]="111111111111111";

        imprimir (k); printf ("\n");
        imprimir (s); printf ("\n");

        copiar (w, k);
    puts(w);

        copiar2 (w, s);


    puts(w);


    return 0;

}
