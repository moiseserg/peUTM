#include <queue>
#include <stdio.h>
#include <stdlib.h>
#define T 50
using namespace std;

struct P{
	int f, c, pasos;
};

void imprMatriz(char m[T][T], int n){
	for (int i = 0; i < n; i++)
	{
		puts(m[i]);
	}

}

void bfs(char m[T][T], int f, int c){
	if(m[f][c]!=' ')
		return ;
	//crear una cola
	queue <P> q;
	P ini = {f,c,0};
	q.push(ini);

	while( !q.empty()){
		P actual = q.front(); //obtener el frente
		q.pop(); //borrar el elemento al frente
		int ff = actual.f;
		int cc = actual.c;
		int pasos = actual.pasos;
		m[ff][cc] = '.';
		printf("(%d %d) %d\n", ff,cc, pasos );
		imprMatriz(m,8);
		system("sleep 4");

		if(ff>=0 && m[ff-1][cc] == ' '){
			P nuevo = {ff-1, cc, pasos+1};
			q.push(nuevo);
		}
		if(cc<=8 && m[ff][cc+1] == ' '){
			P nuevo = {ff, cc+1, pasos+1};
			q.push(nuevo);
		}
		if(ff<8 && m[ff+1][cc] == ' '){
			P nuevo = {ff+1, cc, pasos+1};
			q.push(nuevo);
		}

		if(cc>=0 && m[ff][cc-1] == ' '){
			P nuevo = {ff, cc-1, pasos+1};
			q.push(nuevo);
		}
	}
}


int main(){
	queue <P> q;
	char m[T][T] = {" x x  x ",
					" x xxxx ",
					" x      ",
					" x  xxx ",
					"    x   ",
					" x  x x ",
					" x  x   ",
					" xxxx   ",};
	bfs(m, 0,0);
}



