#include <stdio.h>
#include <queue>

using namespace std;

typedef struct actual{
	int pos;
	int ttl;
} A;

int listaNodos(int nodos[], int *nnodos, int a){
	
	int   i;
	
	for(i=0; i< *nnodos; i++){
		if(nodos[i]==a)
			return i;
	}
	nodos[i++] = a;
	*nnodos=i;	
	return i-1;
}



int main(){
	int npars,a,b ;
	int nodos[100], nnodos=0;
	
	
	while(1){
		int grafo[100][100]={0};
		nnodos=0;
		scanf("%d", &npars);
		if(npars==0)
			break;
		
		for(int i=0; i<npars; i++){
			scanf("%d%d", &a, &b);
			int inda = listaNodos(nodos, &nnodos, a);
			int indb = listaNodos(nodos, &nnodos, b);
			//printf("%d %d\n", inda, a);
			//printf("%d %d\n", indb, b);
			grafo[inda][indb] = grafo[indb][inda] = 1;
		}


		
		int origen, ttl;
		while(1){		
		
			int visitados[100]={0};
			
			scanf("%d%d", &origen, &ttl);
			

			if(origen==0 && ttl==0)
				break;
			//bfs
			
			printf("caso: origen %d  dest:%d:\n", origen, ttl);
			origen = listaNodos(nodos, &nnodos, origen);
			A nActual={origen, 0};
			
			visitados[origen] =1;
			
			queue <A> q;
			q.push(nActual);
			
			while(!q.empty()){
				A valor= q.front();
				q.pop(); //sacar el elemento de la cola 
								
				int fila = valor.pos; //fila sobre la matriz 
				int ttlAct = valor.ttl;				 
					
				//printf("Cola %d (%d) ttl=%d\n",fila,  nodos[fila], ttlAct);			
				
				for(int i=0; i< nnodos && ttlAct < ttl; i++){
					if(visitados[i] == 0 && grafo[fila][i] ==1){
						A aa = {i, ttlAct+1};
						q.push(aa);
						visitados[i] = 1;
						//printf("visitado %d (%d)\n", i, nodos[i]);
					}
					
				}
				
				
			}
			
			int cont=0;
			for(int i=0; i< nnodos; i++){
				//printf("%d] %d ", i, visitados[i]);
				
				if(visitados[i]==0)
					cont++;
			}
			printf("\n");
			
			printf("respuesta %d\n", cont);
				
		}

		
	}
	
}






