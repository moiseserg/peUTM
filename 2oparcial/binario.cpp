#include <stdio.h>

int binario(int v[], int i, int n, int p){

	if(i<n){

		return v[i]*p + binario(v, i+1, n, p*2);
	}
	return 0;
}

int main(){
	
	int v[] = {1, 1, 1 , 1,1 };

	printf("%d\n", binario(v,0,5, 1) );

}