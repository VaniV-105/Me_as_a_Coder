#include <stdio.h>
#include <stdlib.h>
int main(){
    int a=1234567;
    int sum=0;
    while(a>0){
        int d=a%10;
        sum=sum*10+d;
        a=a/10;
    }
    printf("%d",sum);

}