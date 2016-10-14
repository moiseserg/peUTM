#include<stdio.h>
int main(){
	int h1,m1,s1,h2,m2,s2,ts,ht,modh,mt,modm,st;
	printf("ingrese las horas a sumar\n");
	printf("primera hora:\n");
	scanf("%d:%d:%d",&h1,&m1,&s1);

	printf("segunda hora\n:");
	scanf("%d:%d:%d",&h2,&m2,&s2);
    	ts=(h1*3600)+(h2*3600)+(m1*60)+(m2*60)+(s2+s1);//se convierte todo a segundos
    	ht=(ts/3600);//se sacan las horas
    	modh=(ts%3600);//se saca el sobrante de horas

    	mt=(modh/60);//minutos totales 
    	st=(modh%60);//se sacan lo sobrante de los minutos


    	printf("%d:%d:%d\n",ht,mt,st);
    	return 0;   

}
