#include <stdio.h>

int mcd(int a, int b){

	int r=1;
	for(int i=2; i<= a && i<=b; ){

		if(a%i == 0 && b%i==0){
			a/=i;
			b/=i;
			r*=i;
		}
		else
			i++;
	}
	return r;
}


int main()
{
	int dsor, dvdo, m, a, b;

	scanf("%d %d", &dvdo, &dsor);

	while(scanf("%d %d", &a, &b)!=EOF){
		int tmp = dsor * b;
		dvdo = tmp/dsor*dvdo + tmp/b*a;
		dsor = tmp;
		m = mcd(dvdo, dsor);

		dvdo/=m;
		dsor/=m;

	}

	printf("Reducida %d / %d\n", dvdo, dsor );
	


	return 0;
}