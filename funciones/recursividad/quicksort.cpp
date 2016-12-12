#include <stdio.h>

void imprimirMatriz(int v[],int n){

	int i;
	for(i=0;i<n;i++)
		printf("%d ",v[i]);
}

void Qsort(int v[],int inicio,int fin){
	
	if(fin<=inicio)
		return ;
	int p=v[(fin-inicio)/2+inicio],a;
	int i=inicio;
	int j=fin;
	while(i<=j)
	{
		while(v[i]<p)
		i++;
		while(v[j]>p)
		j--;
		if(i<=j)
		{
			a=v[i];
			v[i]=v[j];
			v[j]=a;
			i++;
			j--;
		}
	}
	Qsort(v,inicio,j);
	Qsort(v,i,fin);
	

}

int main(){

	int vector[1000]={3,2,5,4,9,8,11},n;
	Qsort(vector,0,6);
	imprimirMatriz(vector,7);

return 0;
}
