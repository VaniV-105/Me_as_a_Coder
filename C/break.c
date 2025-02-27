#include <stdio.h>
int main () {
int a = 5;
while( a < 20 ) {
printf("value of a: %d\n", a);
a++;
if( a > 10) {
break;
}
}
return 0;
}