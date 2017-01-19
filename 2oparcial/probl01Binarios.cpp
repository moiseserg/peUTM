#include <stdio.h>

int binario(int b[], int n, int i, int pot){

	if(i < n){
		return pot * b[i] + binario(b, n, i+1, pot*2);
	}
	return 0;
}

int main(){
	int b[10] = {1,0 ,0, 1,1};

	printf("%d\n", binario(b, 5, 0, 1));
	return 0;
}