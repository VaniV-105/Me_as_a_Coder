#include <stdio.h>
int fact(int n){
    if(n==0 || n==1)
        return 1;
    return n*fact(n-1);
}
void main(){
    printf("Enter the no:");
    int n;
    scanf("%d",&n);
    printf("%d",fact(n));
}