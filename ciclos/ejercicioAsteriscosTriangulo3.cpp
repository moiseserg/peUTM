/*
 9
 
 1  *
 2  **
 3  ***
 4  ****
 5  *****
 6  ******
 7  *******
 8  ********
 9  *********
 8  ********
 7  *******
 6  ******
 5  *****
 4  ****
 3  ***
 2  **
 1  *


*/

#include <stdio.h>
int main (){
	int a, i=1, j, c=1;
	scanf("%d", &a);
	while(i!=0){
		j=0;
		printf("%2d  ", i);
		while(j<i){
			printf("*");
			j++;
			}
		c++;
		if(c>a)
			i--;
		else 
			i++;
		printf("\n");
		}
	return 0;
	}
