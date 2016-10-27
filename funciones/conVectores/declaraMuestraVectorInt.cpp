#include <stdio.h>

int main(){
	int v1[] = {1,3,4,6};
	int v2[10] = {1,4,6,6,7,8,3};
	int v3[10] = {1,2,3,4,5,6,7,8,9,10};
	int v4[10];
	long long int i=0x123456788238282ULL;

	printf("v1 %d\n",  (int)sizeof(v1));
	printf("v2 %d\n",  (int)sizeof(v2));
	printf("v1[0] %d\n",  (int	)sizeof(v1[0]));
	printf("int %d\n",  (int)sizeof(int));
	printf("7 %d\n",  (int)sizeof(7LL));
	printf("7.5 %d\n",  (int)sizeof(7.5));
	
	
/*	for(i=0;i<10; i++)
		printf("v[%d] = %d \t", i, v1[i] );
	printf("\n\n");

	for(i=0;i<10; i++)
		printf("v[%d] = %d \t", i, v2[i] );
	printf("\n\n");

	for(i=0;i<10; i++)
		printf("v[%d] = %d \t", i, v3[i] );
	printf("\n\n");

	for(i=0;i<10; i++)
		printf("v[%d] = %d \t", i, v4[i] );
	printf("\n\n");
*/
	return 0;
}
