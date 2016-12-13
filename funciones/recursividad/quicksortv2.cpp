#include <stdio.h>
void imp(int v[], int n){
	int i;
	for (i=0; i<n; i++)
		printf("%d ", v[i]);
	printf("\n");
}
void quick(int v[], int n, int iz, int der, int i,int j, int piv){
		if(piv<j){
			if (j<=i){
				if(v[piv]>v[i]){
					int t=v[i];
					v[i]=v[piv];
					v[piv]=t;
					imp(v, 8);
					printf("%d %d %d\n", i, j, piv);
					quick(v, n, iz, der, i-1, j, i);
				}
				else {
					if(i!=1)
						quick(v,n,iz,der,i-1, j, piv);
				}
			}
			else
				quick(v, n, iz, der, der, iz, 0);
		}
		else if (piv>i){
			if (j<=i){
				if (v[j]>v[piv]){
					int t=v[j];
					v[j]=v[piv];
					v[piv]= t;
					imp (v, n);
					printf("%d %d %d\n", i, j, piv);
					quick (v, n, iz, der, i, j+1, j);
				}
				else {
					quick (v, n, iz, der, i, j+1, piv);
					}
			}
			else 
				quick(v, n, iz, der, der, iz, 0);
		}
	}

int main(){
	int v[10]={100, 2, 15, 20, 75, 10, 7, 15};
	quick(v, 8, 1, 7, 7, 1, 0);
	quick(v, 8, 1, 7, 7, 1, 7);
	imp(v, 8);
	return 0;
}
