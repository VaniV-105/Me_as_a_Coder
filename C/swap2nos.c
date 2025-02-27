#include <stdio.h>
#include <stdio.h>
int main(){
    int a=2;
    int b=3;
    printf("%d %d\n",a,b);
    a=a^b;
    b=a^b;
    a=a^b;
    printf("%d %d",a,b);

}