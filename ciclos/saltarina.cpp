#include <stdio.h>

int abs(int n){

	if(n<0)
		return -n;
	
	return n;
}


int main()
{
	int d[1000] = {0}, n=1, i, a, b, dif;

	while(n){
		scanf("%d", &n);
		if(n>0){
			scanf("%d", &a);
			int esSaltarina = 1;
			for ( i = 0; i < n-1; i++)
			{
				scanf("%d", &b);
				dif = abs(a-b);
				if(dif>=n)
					esSaltarina =0;
				else if(d[dif]==1)
					esSaltarina =0;
				d[dif] = 1;
				a = b;
			}
			if(esSaltarina == 1)
				printf("La secuencia es saltarina\n");
			else
				printf("La secuencia NO es saltarina\n");

		}


	}

	return 0;
}