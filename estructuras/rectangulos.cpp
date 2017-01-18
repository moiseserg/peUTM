#include <stdio.h>
#include <stdlib.h>

typedef struct Punto{
	int x,y;	
}P;

typedef struct Rectngulo{
	P point1,point2;
}R;

void areaRec(R rec[],int n){

	int i,b,h;
	for(i=0;i<n;i++){
		b=rec[i].point2.x-rec[i].point1.x;
		h=rec[i].point2.y-rec[i].point1.y;
		printf("Area del Rectangulo %d) = %d\n",i+1,b*h);
	}
}

void compRec(R rec[],int n){
  //todos contra todos
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if((rec[j].point1.x>=rec[i].point1.x && rec[j].point1.y>=rec[i].point1.y)&&(rec[j].point2.x<=rec[i].point2.x && rec[j].point2.y<=rec[i].point2.y))
				printf("El Rectangulo %d esta dentro del Rectangulo %d\n",j+1,i+1);
		}
	}
}

int main(int argc,char *argv[]){

	R rec[100];
	FILE *arch;
	arch=fopen(argv[1],"r");
	if(arch==NULL){
		printf("El archivo %s no existe\n",argv[1]);
		exit(0);
	}
	int i=0;
	while(1){
		fscanf(arch,"%d %d %d %d",&rec[i].point1.x,&rec[i].point1.y,&rec[i].point2.x,&rec[i].point2.y);
		if(feof(arch))
			break;
		i++;
	}
	areaRec(rec,i);
	compRec(rec,i);

	fclose(arch);

	return 0;
}
