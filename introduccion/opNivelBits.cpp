 #include <stdio.h>
 
 int main()
 {
     int a = 21;
     int b = 10;
 
     printf("a= %d  b=%d\n", a, b);
     printf("a == b   %d\n", a==b);
     printf("a < b   %d\n", a<b);
     printf("a > b   %d\n", a>b);
     printf("a <= b   %d\n", a<=b);
     printf("a >= b   %d\n", a>=b);
     printf("a != b   %d\n", a!=b);
     printf("a && b   %d\n", a&&b);
     printf("a || b   %d\n", a||b);
     printf("!(a == b)   %d\n", !(a==b));
 
     a = 10;
     b = 10;
     printf("\n\na= %d  b=%d\n", a, b);
     printf("a == b   %d\n", a==b);
     printf("a < b   %d\n", a<b);
     printf("a > b   %d\n", a>b);
     printf("a <= b   %d\n", a<=b);
     printf("a >= b   %d\n", a>=b);
     printf("a != b   %d\n", a!=b);
     printf("a && b   %d\n", a&&b);
     printf("a || b   %d\n", a||b);
     printf("!(a == b)   %d\n", !(a==b));
 
 
 
 }
/*

a= 21  b=10
a == b   0
a < b   0
a > b   1
a <= b   0
a >= b   1
a != b   1
a && b   1
a || b   1
!(a == b)   1


a= 10  b=10
a == b   1
a < b   0
a > b   0
a <= b   1
a >= b   1
a != b   0
a && b   1
a || b   1
!(a == b)   0

*/