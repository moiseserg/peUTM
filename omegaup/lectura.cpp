#include <stdio.h>


int main(){
	int i;
	char c, c2;

	/*for(i=32; i< 127;  i++)
		printf("(%d %c)", i, i );*/

	//i = cuantos datos del tipo leyó
	i = scanf("%c", &c);
	printf("i= %d \n", i);

	while(i>0){
		printf("%c ", c);
		i = scanf("%c", &c);
	}


	return 0;
}