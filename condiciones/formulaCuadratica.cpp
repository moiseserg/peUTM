/*Ejemplo
./cuadratica 
1
3
1
Discriminante 5.000000
x1=-0.381966
x2=-2.618034
*/

#include <stdio.h>
#include<math.h>
int main(){
	float a,b,c,res;
	scanf("%f",&a);
	scanf("%f",&b);
	scanf("%f",&c);
  
	res=b*b-4*a*c;
	printf("Discriminante %f\n", res);
  
	if(res>0 ){
		printf("x1=%f\n",(-b+sqrt(res))/(2*a));
		printf("x2=%f\n",(-b-sqrt(res))/(2*a));
	}
	if(res==0 ){
		///codigo para sol unica
	}
	if(res< 0 ){
		///codigo de imaginarios
	}
	return 0;
}

// A este ejemplo es importante considerar if - else 
