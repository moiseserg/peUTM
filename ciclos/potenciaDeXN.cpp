/*
$ ./a.out 
8
3
8 ^ 3 = 512 
emmanuel@iec05:~/Projects/pEst/003potencias$ ./a.out 
8
4
8 ^ 4 = 4096 
emmanuel@iec05:~/Projects/pEst/003potencias$ ./a.out 
9
3
9 ^ 3 = 729 
emmanuel@iec05:~/Projects/pEst/003potencias$ ./a.out 
2
8
2 ^ 8 = 256 


*/

//potencia de un numero N a la M
#include <stdio.h>

int main()
{
	int f, n, m;
	scanf("%d", &n);	//base
	scanf("%d", &m);  //expo
	printf("%d ^ %d =", n, m);

	for(f=1; m>0; m--)
		f=f*n;
	printf(" %d \n",f);
}
