#include <stdio.h>
#include <string.h>  //quitar string.h para hacer el ejercicio
#define T 100
int main()
{
	char t1[T];
	char t2[T];
	char t3[T], t4[T];
	int i;

	//capturar 2 cadenas	
	gets(t1);
	gets(t2);

	printf("Cadenas introducidas:\n %s\n %s\n", t1, t2);

	//copia y concatena
	strcpy(t3, t1);
	strcat(t3, t2);
	printf("despues de usar strcpy y strcat\n");
	puts(t3);

	//longitud de la cadena
	printf("La longitud de la cadena %s es %d \n", t1, (int)strlen(t1));	
	printf("La longitud de la cadena %s es %d \n", t2, (int)strlen(t2));	
	printf("La longitud de la cadena %s es %d \n", t3, (int)strlen(t3));	

	
	//orden alfabetico
	i=strcmp(t1,t2);		
	if(i==0)
		printf("Las cadenas %s y %s son iguales lexicograficamente \n", t1, t2);	
	else if(i>0)
		printf("%s > %s (lexicograficamente) \n", t1, t2);	
	else
		printf("%s < %s (lexicograficamente) \n", t1, t2);	

	//copia los primeros n bytes de una cadena a otra cadena.
	i=4;
	strncpy(t4, t3, i);
	t4[i]='\0';
	printf("Los primeros %d caracteres de %s son %s\n", i, t3, t4);

	i=6;
	strncpy(t4, t3, i);
	t4[i]='\0';
	printf("Los primeros %d caracteres de %s son %s\n", i, t3, t4);


	//strncat
	i=4;
	strncpy(t4, t3, i);
	t4[i]='\0';
	strncat(t4, t3, i);
	t4[i<<1]='\0';
	printf("despues de strncpy y strncat t4 = %s n\n",  t4);

	return 0;
}
