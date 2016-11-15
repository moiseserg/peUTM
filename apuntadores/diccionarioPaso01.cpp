#include <stdio.h>
#include <string.h>

void minusculas(char *s)
{
	while(*s != '\0')
	{
		if(*s >= 'A' && *s <= 'Z')
		{
			*s += 32;
		}
		else if(!(*s >= 'a' && *s <= 'z'))
		{
			*s = ' ';
		}
		++s;
	}
}

void diccionario(char d[100][10], int *nd, char*txt) //separa las palabras de una frase
{
	char *ptr;

	ptr = strtok(txt, " ");
	while(ptr != NULL)
	{
		//puts(ptr);
		//ptr = strtok(NULL, " ");
		strcpy(d[*nd], ptr);
		puts(d[*nd]);
		(*nd)++;
		ptr = strtok(NULL, " ");

	}
}

int main()
{
	char txt[100], dicc[100][10]; // declaramos vector y matriz
	int nd=0;			
	while(1) 				// ciclo infinito
	{
		gets(txt);
		if(feof(stdin))break; //si llega al final de cadena se sale
		minusculas(txt);
		diccionario(dicc, &nd, txt);
		puts(txt);
	}
	return 0;
}
