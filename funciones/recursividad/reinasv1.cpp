#include <stdio.h>
#include <stdlib.h>

int imprimir(int rec[][9],int nr, int f,int c,int cont){
    system("clear");
    for(int i=0;i<nr; i++){
        for(int j=0;j<nr; j++) {
            if(i==f && j==c)
                printf("%5d",cont);
            else
                printf("%5d", rec[i][j]);

        }
        printf("\n");
    }
    system("sleep 0.01");
}

int Imprimir2(char t[][9],int nr){

      for(int i=0;i<nr;i++) {
          printf("%s", t[i]);
          printf("\n");
      }
    printf("\n");
}

void validar(char t[][9], int f, int c,int nr,int a,int cont){


    if(f>=0 && c>=0 && a==1) {
        if(t[f][c]=='O')
            t[f][c]= (cont + 48);

        validar(t, f - 1, c - 1, nr,a,cont);
        a=2;
        return;
    }
    if(f<nr && c<nr && a==2) {
        if(t[f][c]=='O')
            t[f][c]= (cont + 48);

        validar(t, f + 1, c + 1, nr,a,cont);
        a=3;
         return;
    }
    if(f>=0 && c<nr && a==3) {
        if(t[f][c]=='O')
            t[f][c]= (cont + 48);

        validar(t, f - 1, c + 1, nr,a,cont);
        a=4;
        return;
    }
    if(f<nr && c>=0 && a==4) {
        if(t[f][c]=='O')
            t[f][c]= (cont + 48);

        validar(t, f + 1, c - 1, nr,a,cont);
        a=5;
        return;
    }
    if(a==5) {
        for (int i = 0; i < nr; i++)
            for (int j = 0; j < nr; j++)
                if (i == f || j == c)
                    if(t[i][j]=='O')
                        t[i][j]= (cont + 48);
    }
}

void validar2(char t[][9], int f, int c,int nr,int a,int cont){


    if(f>=0 && c>=0 && a==1) {
        if(t[f][c]==(cont + 48))
            t[f][c]= 'O';

        validar2(t, f - 1, c - 1, nr,a,cont);
        a=2;
        return;
    }
    if(f<nr && c<nr && a==2) {
        if(t[f][c]==(cont + 48))
            t[f][c]= 'O';

        validar2(t, f + 1, c + 1, nr,a,cont);
        a=3;
        return;
    }
    if(f>=0 && c<nr && a==3) {
        if(t[f][c]==(cont + 48))
            t[f][c]= 'O';

        validar2(t, f - 1, c + 1, nr,a,cont);
        a=4;
        return;
    }
    if(f<nr && c>=0 && a==4) {
        if(t[f][c]==(cont + 48))
            t[f][c]= 'O';

        validar2(t, f + 1, c - 1, nr,a,cont);
        a=5;
        return;
    }
    if(a==5) {
        for (int i = 0; i < nr; i++)
            for (int j = 0; j < nr; j++)
                if (i == f || j == c)
                if(t[i][j]==(cont + 48))
                    t[i][j]= 'O';
    }
}

void movimiento(char t[][9],int rec[][9],int f, int c,int nr,int cont){
    static int w=0;


    if(c==nr) {
        w = 1;
        return;
    }
    else if(t[f][c]=='O') {
        for (int i = 1; i < 6; ++i) {
            validar(t, f, c, nr,i,cont);
        }
        *(*(rec+f)+c)=cont;
        imprimir(rec,nr,f,c,cont);
        //Imprimir2(t, nr);
        movimiento(t,rec,f-f,c+1,nr,cont+1);
        if(w==1)
            return;
        else {
            for (int i = 1; i < 6; ++i) {
                validar2(t, f, c, nr, i, cont);
            }
            //Imprimir2(t, nr);
            *(*(rec+f)+c)=0;
           // imprimir(rec,nr,f,c,cont);
        }

    }
    if(f<nr) {
        imprimir(rec, nr, f, c, cont);
        movimiento(t, rec, f + 1, c, nr, cont);
    }
    else
        return;

}

int main(){
    char t[9][9]={" "};
    int nr,f=0,c=0,i,cont=1;
    int rec[9][9]={0};

    printf("Inserte numero de reinas en el rango 4<=nr<=8: ");
    scanf("%d",&nr);

    for( i=0;i<nr;i++)
        for(int j=0;j<nr;j++)
            t[i][j]='O';

    movimiento(t,rec,f,c,nr,cont);
    printf("Posicion correcta de las reinas");
}
