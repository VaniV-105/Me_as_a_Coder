#include <stdio.h>
#include <stdlib.h>
int fib(int n){
    if (n==1)
        return 0;
    else if (n==2 || n==3)
        return 1;
    return fib(n-1)+fib(n-2);  
}
int main(){
    printf("Enter the no of element u need the fibonacci for:");
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        printf("Fibonacci element %d is %d\n",i,fib(i));
    return 0;
}