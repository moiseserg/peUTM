#include <stdio.h>
int main (){
	int a, i=0, v[100],s;
	double pro;
		while (i<100){
			scanf("%d ", &v[i]);
		printf("v[%d] = %d\n", i, v[i]);
			s= s + v[i];
			i++;
		}
		printf("Sumatoria: %d\n", s);
		pro = s/100;
		printf("Promedio: %.2f", (double)pro);
	return 0;
}
