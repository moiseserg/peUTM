#include <stdio.h>

 
int main()
{
  int n, v[100];

  ///scanf("%d", &n);
  n=10;

  int min, max;
  for(int i=0; i<n; i++){

    scanf("%d", &v[i]);

    if(i==0)
    	min=max=v[i];
    if(v[i]<min)
    	min=v[i];
    if(v[i]>max)
    	max=v[i];

  }

	
    	printf("%d %d %d\n", min, max, max-min);



   return 0;
}
