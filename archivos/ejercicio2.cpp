#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct flor{
	float a,b,c,d;
	char nombre[20];
}F;

void imprimir(F f[], int n){
	for(int i=0; i<n; i++)
		printf("%f %f %f %f %s \n",
			f[i].a, f[i].b, f[i].c, f[i].d, f[i].nombre);
}

int main(int argc, char  *argv[])
{
	FILE *arch = fopen(argv[1],"r");
	FILE *arch2 = fopen(argv[2],"wb");

	F f[20];
	int i=0;

	if(!arch)
		exit(0);

	while(1){
		fscanf(arch, "%f%f%f%f%s", 
		&f[i].a, &f[i].b, &f[i].c, &f[i].d, f[i].nombre );

		if(feof(arch))
			break;
		switch( f[i].nombre[0] ){
			case 's': strcpy(f[i].nombre, "Setosa");
			break;
			case 'v': strcpy(f[i].nombre, "Versicolor");
			break;
			case 'a': strcpy(f[i].nombre, "Virginica");
			break;
		}

		i++;
	}
	
	imprimir(f, i);
	fwrite(f, sizeof(F), i, arch2);
	fclose(arch);
	fclose(arch2);

	return 0;
}