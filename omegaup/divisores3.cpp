#include <stdio.h>
#include <math.h>
#define T 1000000


int main()
{
	int p, q;
	int sol[T]={0};
	int cont=0;
	scanf("%d%d", &p, &q);

	for( int i=p; i<=q; i++ ){

		int k=2, num=0, lim=sqrt(i)+1;
		while(k<=lim && num<=1){
			if(i%k==0)
				if(k*k==i){
					cont++;
					break;
				}
				else 
					break;
			k++;
		}
	}

	printf("%d\n",cont );

	
	return 0;
}