#include <stdio.h>

int main(){
	int mat1[5][5]={0};
	int mat2[5][5]={ {1,2,3}, {5,7}, {8,7}};
	int mat3[][3]={{1,6},{3},{4,5}};

	for(int i=0; i<5; i++)
	{
		for(int j=0; j<5; j++)
			printf("%4d", mat2[i][j] );
		printf("\n");
	}

	for(int i=0; i<5; i++)
	{
		for(int j=0; j<5; j++){
			printf("(%d %d)", i, j);
			scanf("%d", &mat2[i][j]);
		}		
	}

	for(int i=0; i<5; i++)
	{
		for(int j=0; j<5; j++)
			printf("%4d", mat2[i][j] );		
		printf("\n");
	}

	return 0;
}
