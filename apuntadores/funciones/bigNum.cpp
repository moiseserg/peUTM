#include <stdio.h>
#include <string.h>

//void invertir(char n[]){
void invertir(char *n){
	int i=0, j= strlen(n)-1;
	while(i<j){
		char t = *(n+i); //n[i]
		*(n+i) = *(n+j);
		*(n+j) =  t;
		
		i++;
		j--;
	}

}
void invertir2(char *n){
	char *ptr1= n;
	char *ptr2= n+(int)strlen(n)-1;

	while(ptr1<ptr2){
		char t = *ptr1; //n[i]
		*ptr1 = *ptr2;
		*ptr2 =  t;
		ptr1++;
		ptr2--;
	}

}
int main(){
	char n1[100];
	gets(n1);
	invertir2(n1);
	puts(n1);
}