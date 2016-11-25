#include <stdio.h>

int  multiplicar (int a,int b){
    
    int resultado=0;

    for(int i=1; i<=a; i++)
    	resultado = resultado + b;

    return resultado;
}



int potencia(int x, int e){
	int prod = 1;

	for(int i=1; i<=e; i++){
		prod = multiplicar(prod, x);
	}
	return prod;
}
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d x %d = %d \n",a,b, multiplicar(a,b));

    printf("%d ^ %d = %d \n",a,b, potencia(a,b));
    return 0;
}

