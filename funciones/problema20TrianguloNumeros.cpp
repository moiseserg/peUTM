/*
P20. Serie de números en tríangulo
./a.out 
Dame un número  5
  1
  2  3
  4  5  6
  7  8  9 10
 11 12 13 14 15
*/

#include <stdio.h>

void imprimeIniFin(int ini, int fin){
  int i;
  for(i = ini ; i <= fin ;  i++)
     printf("%4d", i);
  printf("\n");
}


int main(){
 	int i, j, n, incI, incJ;
 	scanf("%d", &n);

 	for( i=1, j= 1, incI=1, incJ=2; 
 		n>0; 
 		i+= incI, j+=incJ, incI++, incJ++, n--  )
 		    imprimeIniFin(i, j);
}
