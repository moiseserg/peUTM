#include <stdio.h>

int main()
{
	int f, n;
	scanf("%d", &n);

	for(f=1; n>1; n--)
		f=f*n;
	printf("El factorial es  %d \n",f);
}
