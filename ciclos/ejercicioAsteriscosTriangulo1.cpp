/*

8
*
**
***
****
*****
******
*******
********


*/
#include <stdio.h>

int main()
{
	int n, i, p;
	
	scanf("%d", &n);
	p=n;
	for(n=1	; n<=p; n++)
	{
		for(i=0; i<n; i++)
			printf("*");
		printf("\n");
  }
	
	
	return 0;
}

