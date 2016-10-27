/*
./a.out 
120
2 2 2 3 5 

emmanuel@iec05:~/Projects/pEst/005factoresPrimos$ ./a.out 
150
2 3 5 5 

emmanuel@iec05:~/Projects/pEst/005factoresPrimos$ ./a.out 
10000
2 2 2 2 5 5 5 5 

emmanuel@iec05:~/Projects/pEst/005factoresPrimos$ ./a.out 
19420
2 2 5 971 

*/
//factores primos de n= 18 -> 2,3,3
#include <stdio.h>

int main()
{
	int f, n;
	scanf("%d", &n);

	for(f=2; n>1; )
	{	
		if(n%f==0)
		{
			n=n/f;
			printf("%d ", f);
		}
		else
			f++;
	}
		
	return 0;
}
