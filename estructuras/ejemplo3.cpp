#include <stdio.h>

typedef struct persona{
	char nombre[20];
	unsigned int edad;
	float peso;
	float estatura;
} P;


int main(){
	P p;
	P q[10];
	P r={"pedro", 20, 79, 1.65};		
	P s[10]= { {"juan", 20, 79, 1.65}, 
							{"juan", 20, 79, 1.65}
						};

	P t[]= { {"juan", 20, 79, 1.65}, 
							{"juan", 20, 79, 1.65}
						};

	printf("%d\n", (int)sizeof(P) );

	scanf("%s", p.nombre);
	scanf("%d", &p.edad);

	printf("%s %d %f %f\n", p.nombre, p.edad, 
		p.peso, p.estatura );

	p = r;

	printf("%s %d %f %f\n", p.nombre, p.edad, 
		p.peso, p.estatura );

	p = s[0];

	printf("%s %d %f %f\n", p.nombre, p.edad, 
		p.peso, p.estatura );


}


