#include <stdio.h>


int main(){
	int i;
	int v1[10];	
	double v2[10];	


	for(i=0; i<10; i++)		
		scanf("%lf", &v2[i]);
	for(i=0; i<10; i++)		
	printf("v[%d] = %lf @%p\n",i, v2[i], &v2[i] );
	
	printf("%d\n", (int)sizeof(int) );
	printf("%d\n", (int)sizeof(v1) );
	printf("%d\n", (int)sizeof(v2) );
	printf("%d\n", (int)sizeof(v1[0]) );
	printf("%d\n", (int)sizeof(v2[0]) );

	return 0;
}

/*
terminal
ubicarse donde esta el ejecutable (cd)

./lectVector < entrada.in
*/


/*	for(i=0; i<10; i++)		
		scanf("%d", &v1[i]);

	for(i=0; i<10; i++)		
printf("v[%d] = %d @%p\n",i, v1[i], &v1[i] );
*/
