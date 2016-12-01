#include <stdio.h>
#include <string.h>

void volteada(char m[10][20], int f, int c ){

	for (int i = 0; i < f; ++i)
	{
		for (int j = c-1; j >=0 ; --j)
		{
			if(m[i][j]=='\0')
				printf(" ");
			else 
				printf("%c", m[i][j]);
		}
		printf("\n");
	}

}

void volteadaVertical(char m[10][20], int f, int c ){

	for (int j = c-1; j >=0 ; --j)
	{		
		for (int i = 0; i < f; ++i)
		{
			if(m[i][j]=='\0')
				printf(" ");
			else 
				printf("%c", m[i][j]);
		}
		printf("\n");
	}

}

int main()
{
	char m[10][20]={'\0'};
	int n, l=0;
	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i)
	{
		gets(m[i]);
		puts(m[i]);
	
		if(strlen(m[i])>l)
			l=strlen(m[i]);
	}

	volteada(m, n, l);

	volteadaVertical(m, n, l);

	return 0;
}


