// Otra versión de uno de sus compañeros: Eduardo Ramírez
#include <stdio.h>
#include <string.h>

void invertir(char *p);
void suma(char *r,char *n1,char *n2);
void imprimir(char *r);
int main(){

	char n1[1000],n2[1000],r[1001];
	gets(n1);
	gets(n2);
	invertir(n1);
	invertir(n2);
	suma(r,n1,n2);
	imprimir(r);

return 0;
}

void invertir(char *p){

	char *q=p+strlen(p)-1;

	while(p<q)
	{
		char t=*p;
		*p=*q;
		*q=t;
		p++;
		q--;
	}

}

void suma(char *r,char *n1,char *n2){

	int carry=0;
	while(*n1!='\0' && *n2!='\0')
	{
		int d=(*n1-48)+(*n2-48)+carry;
		*r=(d%10)+48;
		carry=d/10;
		r++,n1++,n2++;
	}
	while(*n1!='\0')
	{
		int d=(*n1-48)+carry;
		*r=(d%10)+48;
		carry=d/10;
		r++,n1++;
	}
	while(*n2!='\0')
	{
		int d=(*n2-48)+carry;
		*r=(d%10)+48;
		carry=d/10;
		r++,n2++;
	}
	if(carry)
	{
		*r=carry+48;
		r++;
	}
	*r='\0';

}

void imprimir(char *r){

	char *l=r+strlen(r)-1;
	for(;l!=r;l--)
		printf("%c",*l);
	printf("%c\n",*r);

}
