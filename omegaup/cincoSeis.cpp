#include <stdio.h>

void aCinco(char *a){

	while(*a){
		if(*a=='6')
			*a='5';
		a++;
	}
}


void aSeis(char *a){

	while(*a){
		if(*a=='5')
			*a='6';
		a++;
	}
}

 
 
int main()
{
  int a,b;
  char txt[2222];

  scanf("%d%d", &a, &b);

  int mina=0, maxa=0;
  sprintf(txt,"%d",a);
  aCinco(txt);
  sscanf(txt, "%d", &mina);
  aSeis(txt);
  sscanf(txt, "%d", &maxa);

  int minb=0, maxb=0;
  sprintf(txt,"%d",b);
  aCinco(txt);
  sscanf(txt, "%d", &minb);
  aSeis(txt);
  sscanf(txt, "%d", &maxb);

  printf("%d %d\n", mina+minb, maxa+maxb);

  return 0;
}
