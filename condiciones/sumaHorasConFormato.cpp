#include <stdio.h>
int main (){
	int h1, h2, hs, m1, m2, ms, s1, s2, ss;
		printf("escribe la hora 1	\n");
		scanf("%d: %d: %d", &h1, &m1, &s1);
		printf("escribe la hora 2\n");
		scanf("%d: %d: %d", &h2, &m2, &s2);
		hs= h1 + h2;
		ms = m1 + m2;
		ss = s1 + s2;
		if(ss > 59){
			ss = ss - 60;
			ms = ms + 1	;}
		if (ms > 59){
			hs = hs + 1;
			ms = ms - 60;}
		printf("%02d:%02d:%02d", hs, ms, ss);
return 0;
}
