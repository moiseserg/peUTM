#include <stdio.h>
int main(){
    int n,i=1,c=0,s;
    scanf ("%d", &n);
    while(n!=1){
        
        if (n%2!=0){
            n=(n*3)+1;
            i++;
        }
        else {
            n=n/2;
            c++;
        }
        
    }
    s=i+c;
    printf("%d\n", s);   
    return 0;
}   