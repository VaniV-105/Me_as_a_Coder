#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("Enter the no:");
    int n,a=0,b=1,c=1;
    scanf("%d",&n);
    int i=1;
    if(n==1)
        printf("%d",a);
    else if(n==2)
        printf("%d",b);
    else if(n==3)
        printf("%d",c);
    while(i<=n-3){
        a=b;
        b=c;
        c=a+b;
        i+=1;        
    }
    printf("%d",c);
    return 0;
}