#include <stdio.h>

int main(){
	int v1[10] = {1,3,4,6};


	for(int i=0; i<10; i++)
		scanf("%d", &v1[i]);
				
	for(int i=0;i<10; i++)
		printf("v[%d] = %d  %p \n", i, v1[i], &v1[i] );
	printf("\n\n");
	

	return 0;
}
