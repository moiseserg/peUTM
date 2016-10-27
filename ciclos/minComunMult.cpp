/*
./a.out 
18
30
2  3  3  5  
mcm es 90
 
emmanuel@iec05:~/Projects/pEst/009minComMultiplo$ ./a.out 
120
150
2  2  2  3  5  5  
mcm es 600
 
emmanuel@iec05:~/Projects/pEst/009minComMultiplo$ ./a.out 
12
15
2  2  3  5  
mcm es 60
 
emmanuel@iec05:~/Projects/pEst/009minComMultiplo$ ./a.out 
10
15
2  3  5  
mcm es 30

*/

#include <stdio.h>

int main()
{
	int m, n, d=2, mcm=1;

	scanf("%d%d", &m, &n);
	
	while(m>1  || n>1)
	{
		while(n%d ==0 || m%d==0)
		{
			if(n%d==0)
				n=n/d;
			if(m%d==0)	
				m=m/d;
			mcm=mcm*d;

			printf("%d  ", d);
		}
		d++;
	}

//	mcm=mcm*m*n;
	printf("mcm es %d\n ", mcm);
	return 0;
}
