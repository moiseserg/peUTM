#include <stdio.h>
#include <stdlib.h>

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

	P *u =(P *) malloc(sizeof(P)*3);
	P *v;

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

	//	P *u =(P *) malloc(sizeof(P)*3);
	//P *v;

	scanf("%s", u[0].nombre);
	scanf("%d", &u[0].edad);

	printf("%s %d %f %f\n", u[0].nombre, u[0].edad, 
		u[0].peso, u[0].estatura );

	v = u;
	scanf("%s", v->nombre);
	scanf("%d", &(v->edad));

		printf("%s %d %f %f\n", u[0].nombre, u[0].edad, 
		u[0].peso, u[0].estatura );


}


