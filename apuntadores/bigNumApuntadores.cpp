#include <stdio.h>
#include <string.h>

void invertir(char *p);
void imprimir(char *r);
void suma(char *r,char *a,char *b);

int main (){
	char m[100];
	char n[100];
	char r[100];

	gets(m);
	gets(n);

	invertir(n);
	invertir(m);
	suma(r,n,m);
	imprimir(r);

	return 0;
}

//funciones

void invertir(char *p){
	char *q = p+strlen(p)-1;
	for(;p<q;p++,q--){
		char t=*p;
		*p=*q;
		*q=t;
	}

}

void suma(char *r,char *a,char *b){
	int carry=0;

	for(;*a!='\0' && *b!='\0';){
		int d=(*a-'0')+(*b-'0')+carry;
		*r=d%10+'0';
		carry=d/10;
		r++,a++,b++;
	}

	for(;*a!='\0';){
		int d=(*a-'0')+carry;
		*r=d%10+'0';
		carry=d/10;
		r++,a++;
	}
	for(;*b!='\0';){
		int d=(*b-'0')+carry;
		*r=d%10+'0';
		carry=d/10;
		r++,b++;
	}
	if (carry){
		*r=carry+'0';
		r++;

	}
	*r='\0';
}

void imprimir(char *r){
	char *t=r;
	r+=(strlen(r)-1);
	for(;r>=t;r--){
		printf("%c",*r);
	}
	printf("\n");
}
