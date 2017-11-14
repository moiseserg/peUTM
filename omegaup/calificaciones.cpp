#include <stdio.h>

int main(){
	int n;
	

	while(scanf("%d", &n)!=EOF){
		switch(n){
			case 0:
			case 1:
			case 2:
			case 3: printf("0\n");break;

			case 4:
			case 5:
			case 6:
			case 7:
			case 8: printf("7\n"); break;
			default: printf("10\n");
		}
	}

	return 0;
}