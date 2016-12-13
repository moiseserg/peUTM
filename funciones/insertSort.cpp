#include <stdio.h>


int main(){

	int v[]  = {5,9,6,3,2,5,1,2,3}, n=8, i, j , k, ii;

	for(int i=0; i<(n-1);i++)
	{
	    if(v[i]>v[i+1])
	    {
	        k=1;
	        j=i+1;
	        while(k)
	        {
	            if(v[j]<v[j-1])
	            {
	                int t=v[j];
	                v[j]=v[j-1];
	                v[j-1]=t;
	                j--;
	            }
	            else
	                k=0;
	        }
	    }

	    for(ii=0; ii<8; ii++){
	    	if(ii==i+2)
	    		printf(" | ");
			printf("%d ",v[ii]);
		}
		printf("\n\n");
	}

	
}
/*

 ./insert 
5 9  | 6 3 2 5 1 2 

5 6 9  | 3 2 5 1 2 

3 5 6 9  | 2 5 1 2 

2 3 5 6 9  | 5 1 2 

2 3 5 5 6 9  | 1 2 

1 2 3 5 5 6 9  | 2 

1 2 2 3 5 5 6 9 

*/
