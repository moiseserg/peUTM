#include <stdio.h>

struct persona{
	char nombre[20];
	unsigned int edad;
	float peso;
	float estatura;
};

int main(){
	struct persona p;
	struct persona q[10];
	struct persona r={"juan", 20, 79, 1.65};		
	struct persona s[10]= { {"juan", 20, 79, 1.65}, 
							{"juan", 20, 79, 1.65}
						};

	struct persona t[]= { {"juan", 20, 79, 1.65}, 
							{"juan", 20, 79, 1.65}
						};

}