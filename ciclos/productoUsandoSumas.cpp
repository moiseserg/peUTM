//producto usando sumas, m, n positivos
#include <stdio.h>

int main()
{
	int f, n, m;
	scanf("%d", &n);
	scanf("%d", &m);

	for(f=0; m>0; m--)
		f=f+n;
	printf("El producto es  %d \n",f);
}
