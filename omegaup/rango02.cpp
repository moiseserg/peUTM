#include <stdio.h>

 
int main()
{
  int n, v[100];

  scanf("%d", &n);
  
  
  for(int i=0; i<n; i++){

    scanf("%d", &v[i]);

  }


  int min, minpos, max, maxpos,a,b;
  scanf("%d%d", &a, &b);
  for(int i=a; i<=b; i++){

    if(i==a){
    	min=max=v[i];
    	minpos=maxpos=a;
    }
    if(v[i]<min){
    	min=v[i];
    	minpos=i;
    }
    if(v[i]>max){
    	max=v[i];
    	maxpos=i;
    }

  }
	
   printf("%d\n", minpos);



   return 0;
}
