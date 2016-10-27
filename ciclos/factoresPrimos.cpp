#include <stdio.h>
int main (){
	int a, pr=2, con=0;
	scanf ("%d", &a);
	while(a!=1){
		while (a % pr ==0){
			a = a/pr;
			printf("%d, ", pr);
			con++;
			}
		pr++;
		}
		printf("\ntiene %d factores primos\n\n", con);
		return 0;
}
