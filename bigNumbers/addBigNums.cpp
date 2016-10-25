#include <stdio.h>
#include <string.h>



void capturar(char a[] ){
	gets (a);
	int l= strlen(a),i,j;
	for(i=0,j=l-1;i<j;i++,j--){
		char t=a[i];
		a[i]=a[j];
		a[j]=t;
	}	
}


void imprimir(char a[] ){
	int la=strlen(a);
	 
	for (int i=la-1;i>=0;i--){
		printf("%c",a[i]);
	}
	printf("\n");
}


void sumar (char r[], char a[], char b[]){
	int la=strlen(a);
	int lb=strlen(b);

	int carry=0,i;

	for (i=0;i<la && i<lb; i++){
		int d=(a[i]-48)+(b[i]-48)+carry;
		r[i]= d%10 + 48;
		carry=d/10;
	}
	r[i] = '\0';

	/*int lr=strlen(r);
	for(i=0;i<=lr;i++){
		printf("%c",r[i]);
	}*/


	for (;i<la;i++){
		int d=carry+(a[i]-48);
		r[i]=d%10 + 48;
		carry=d/10;
	}
	for (;i<lb;i++){
		int d=carry+(a[i]-48);
		r[i]=d%10+48;
		carry=d/10;
	}

	if (carry){
		r[i++]= carry+48;		
	}
	r[i++]='\0';

	 
}

int main(){
	char f[5001][1050] = {"0", "1"};
	
	for(int i=2; i<5001; i++){
		//TO-DO		
	}
	
	

	return 0;
}
