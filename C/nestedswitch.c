#include <stdio.h>
int main () {
int a = 50;
int b = 100;
switch(a) {
case 50:
printf("This is part of outer switch\n", a );
switch(b) {
case 100:
printf("This is part of inner switch\n", a );
}
}
printf("Exact value of a is : %d\n", a );
printf("Exact value of b is : %d\n", b );
return 0;
}