#include <stdio.h>

struct persona{
	char nombre[20];
	unsigned int edad;
	float peso;
	float estatura;
};

typedef struct persona P;

int main(){
	P p;
	P q[10];
	P r={"juan", 20, 79, 1.65};		
	P s[10]= { {"juan", 20, 79, 1.65}, 
							{"juan", 20, 79, 1.65}
						};

	P t[]= { {"juan", 20, 79, 1.65}, 
							{"juan", 20, 79, 1.65}
						};

}