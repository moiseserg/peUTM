#include <stdio.h>
int main(){
int x;
	scanf("%d", &x);
	if(x & 1){
		printf("%d es impar\n", x);
	}
	else
	{
		printf("%d es par\n", x);
	}

	return 0;
}
