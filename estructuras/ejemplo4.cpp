#include <stdio.h>


struct automovil
{
	char placas[10];
	int modelo;
	char color[10];
	char marca[10];
};


int main(){

	struct automovil p;
	struct automovil q={"XBR4322", 1993, "gris", "vw"};
	struct automovil v[] = {{"GR3232", 1993, "gris", "vw"},
							{"XBR4322", 1993, "gris", "vw"}};

	printf("%s %d %s %s\n", q.placas, q.modelo, q.color, q.marca );

	printf("%s %d %s %s\n", p.placas, p.modelo, p.color, p.marca );
	p = q;
	printf("%s %d %s %s\n", p.placas, p.modelo, p.color, p.marca );

	printf("%s %d %s %s\n", v[0].placas, v[0].modelo, v[0].color, v[0].marca );
	printf("%s %d %s %s\n", v[1].placas, v[1].modelo, v[1].color, v[1].marca );



	printf("%d\n", (int ) sizeof(struct automovil) );



	return 0;
}