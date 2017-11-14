#include <stdio.h>

 
int main()
{
  int f, c, bw, n;

  scanf("%d%d%d", &f, &c, &bw);
  scanf("%d", &n);
  while(n--){
    int a,b;
    scanf("%d%d", &a, &b);
    if( (a+b)%2  == (f+c)%2 )
      printf("%d\n", bw);
    else
      printf("%d\n", (bw+1)%2);

  }

   return 0;
}
