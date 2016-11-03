#include <stdio.h>

void linea(int r, char c, int b){
	
	for(int i=0; i<r; i++)
		printf("%c", c );

	if(b)
		printf("\n");
}

/*
6

*
**
***
****
*****
*/
int main01(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		linea(i, '*', 1);

	return 0;
}

/*

5
    *
   **
  ***
 ****
*****
*/	
int main02(){
	int n;
	scanf("%d", &n);
	for(int i=1 ; i<=n; i++)
		linea(n-i, ' ', 0),		linea( i, '*', 1);
	return 0;
}

void lineaTriangulos(int n, int nt){
	//nt = numero de triangulos en la linea
	//n  = tamano del triangulo.

	for(int i=1 ; i<=n; i++)
		for(int j=1; j<= nt; j++)
			linea(n-i, ' ', 0),		linea( i, '*', j==nt?1:0);


}

/*
5 3
    *    *    *
   **   **   **
  ***  ***  ***
 **** **** ****
***************
*/

int main03(){
	int n, nt;
	scanf("%d%d", &n, &nt);
	lineaTriangulos(n, nt);
	return 0;
}
/*
4
5
6
   *   *   *   *   *
  **  **  **  **  **
 *** *** *** *** ***
********************
   *   *   *   *   *
  **  **  **  **  **
 *** *** *** *** ***
********************
   *   *   *   *   *
  **  **  **  **  **
 *** *** *** *** ***
********************
   *   *   *   *   *
  **  **  **  **  **
 *** *** *** *** ***
********************
   *   *   *   *   *
  **  **  **  **  **
 *** *** *** *** ***
********************
   *   *   *   *   *
  **  **  **  **  **
 *** *** *** *** ***
********************

*/
void matrizTriangulos(int n, int nt, int nl){
	//nt = numero de triangulos en la linea
	//n  = tamano del triangulo.
	for(int i=0; i<nl; i++)
		lineaTriangulos(n, nt);

}
int main (){
	int n, nt, nl;
	scanf("%d%d%d", &n, &nt, &nl);
	matrizTriangulos(n, nt,nl );
	return 0;
}
