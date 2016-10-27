/*
9
 9 *********
 8 ********
 7 *******
 6 ******
 5 *****
 4 ****
 3 ***
 2 **
 1 *

*/

#include <stdio.h>
int main(){
	int a, i, j;
	scanf ("%d", &a);
	for (i=a; i>=1; i--){
		printf("%2d ", i );
			for (j=0; j<i; j++){
			printf("*");
			}
		printf("\n");
		}
	return 0;
}
