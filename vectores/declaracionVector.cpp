#include <stdio.h>


int main(){
	int i;
	int v1[10];	
	int v2[10]={3};
	int v3[10]={1,2,3,4,5,6,7,8,9,10};
	int v4[] = {1,2,3,4};


	for(i=0; i<10; i++)		
      printf("v[%d] = %d\n",i, v1[i] );
      
	for(i=0; i<20; i++)
		printf("v[%d] = %d\n",i, v2[i] );

	for(i=0; i<10; i++)
		printf("v[%d] = %d\n",i, v3[i] );

	for(i=0; i<10; i++)
		printf("v[%d] = %d\n",i, v4[i] );

	return 0;
}
