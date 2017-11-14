#include <stdio.h>
int main ()
{
int n, v;
scanf ("%d", &n);
for (v=n; v>0; v--){
	if (n%v==0)
	{
		printf ("%d\n", v);
	} 
}
return 0;
}