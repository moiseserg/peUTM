#include <stdio.h>
#include <stdlib.h>
void imp(char t[9][9], int n){
	system("clear");
	int i, j;
	for ( i=0; i<n;i++){
		for ( j=0; j<n; j++)
			printf("%c ", t[i][j]);
		printf("\n");
	}
	system ("sleep 0.01");
}
int colreina(char t[9][9], int f, int c, int posq[9]){
	int i;
	for(i=0; i<f;i++){
		if (c==posq[i]||(abs(f-i)==abs(c-posq[i])))
			return 0;
	}
	return 1;
}
void reinas(char t[9][9], int n, int f, int c, int posq[9]){
	if (f<n){
		if (c<n){
			t[f][c]='*';
			imp(t, n);
			if(colreina(t, f, c, posq)==1){
				posq[f]=c;
				reinas(t, n, f+1, 0, posq);
			}
			else {
				t[f][c]='-';
				reinas(t, n, f, c+1, posq);
			}
		}
		else {
			t[f][c]='-';
			c=posq[f-1]+1;
			t[f-1][posq[f-1]]='-';
			reinas(t, n, f-1, c, posq);
		}
	}
}
int main(){
	int q[9]={-1, -1, -1, -1, -1, -1, -1, -1};
	char tab[9][9]={"--------",
					"--------",
					"--------",
					"--------",
					"--------",
					"--------",
					"--------",
					"--------"};
	int n, i;
	scanf("%d", &n);
	reinas(tab, n, 0, 0, q);
	imp(tab, n);
	return 0;
}
