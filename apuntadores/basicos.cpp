#include <stdio.h>

int main(){
	int a = 10;
	int b[5] = {3,2,5,7};
	int *ptr;

	ptr = &a;
	printf("%p  %d  \n", &a, a);
	printf("%p  %d  \n", ptr, *ptr);

	(*ptr)++;
	printf("%p  %d  \n", &a, a);
	printf("%p  %d  \n", ptr, *ptr);

	/* incorrecto
	*ptr++;
	printf("%p  %d  \n", &a, a);
	printf("%p  %d  \n", ptr, *ptr);
	*/

	//int b[5] = {3,2,5,7};
	// b = &b[0]
	for( ptr = &b[0]; ptr != b+5 ; ptr++)
		printf("::%p  %d  \n", ptr, *ptr);		

}

