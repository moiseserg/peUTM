#include <stdio.h>
int main (){
	int a, i=0, v[100],s;
	double pro;
	//ciclo para pedir valores
	while (i<100){
		//lectura
		scanf("%d ", &v[i]);
		i++;
	}
	
	i=0;
	while (i<100){
		//muestra cada valor
		printf("v[%d] = %d\n", i, v[i]);
		//acumula en s
		s= s + v[i];
		i++;
	}

	
	printf("Sumatoria: %d\n", s);
	pro = s/100.0;
	printf("Promedio: %.2f", (double)pro);
	return 0;
}
