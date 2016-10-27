/*

9
 9  *********
 8  -********
 7  --*******
 6  ---******
 5  ----*****
 4  -----****
 3  ------***
 2  -------**
 1  --------*

*/

#include <stdio.h>
int main (){
	int a, i, j, k;
	scanf("%d", &a);
	k = a;
	i = a;
	while(i > 0) {
		j=a-k;
		printf("%2d  ", i);
		while (k<a && j > 0){
			printf("-");
			j--;
			}
		j=0;
		while(j < i){
			printf("*");
			j++;
			}
		i--;
		k--;
		printf("\n");
		}
	return 0;
}
