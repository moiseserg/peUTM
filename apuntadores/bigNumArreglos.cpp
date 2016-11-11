#include <stdio.h>
#include <string.h>

void capturar(char a[]){
	gets(a);
	int l=strlen(a),i,j;
	for(i=0,j=l-1;i<j;i++,j--){
		int t=a[i];
		a[i]=a[j];
		a[j]=t;
	}
}

void imprimir(char a[]){
	int la=strlen(a);
	for(int i=la-1;i>=0;i--){
		printf("%c",a[i]);
	}
	printf("\n");
}

void sumar(char r[],char a[],char b[]){

	int la=strlen(a);
	int lb=strlen(b);

	int carry=0,i,d;

	for (i=0;i<lb && i<la;i++){
		d=(a[i]-'0')+(b[i]-'0')+carry;
		r[i]=d%10+'0';
		carry=d/10;

	}
	r[i]='\0';

	for(;i<lb;i++){
		d=(b[i]-'0')+ carry;
		r[i]=d%10+'0';
		carry=d/10;
	}
	for(;i<la;i++){
		d=(a[i]-'0')+carry;
		r[i]=d%10+'0';
		carry=d/10;
	}
	if(carry){
		r[i]=carry+'0';
		i++;
	}
	r[i]='\0';
}

int main(){
	char a[100000];
	char b[100000];
	char r[100000];

	capturar(a);
	capturar(b);
	sumar(r,a,b);
	imprimir(r);

	return 0;
}
