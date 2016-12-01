#include <stdio.h>
#include <string.h>

void imprimir( char mat[50][50],   int f, int c){
	for (int j = c-1; j >=0 ; j--)
//	for (int i = 0; i < f; ++i)
	{
		for (int i = 0; i < f; ++i)
//		for (int j = c-1; j >=0 ; j--)
		{
			if(mat[i][j] == '\0')
				printf("  " );
			else
				printf("%2c", mat[i][j] );
		}
		printf("\n");
	}
}


int main()
{
	char mat[50][50] ={'\0'};
	int f,c=0;

	scanf("%d\n", &f);
	for (int i = 0; i < f; ++i)
	{
		gets(mat[i]);
		puts(mat[i]);

		if(strlen(mat[i])>c){
			c = strlen(mat[i]);
		}
	}
	imprimir(mat, f,c );

	return 0;
}