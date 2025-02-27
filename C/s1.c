#include <stdio.h>
#include<stdlib.h>
int main(){
    //prime or not
    printf("Enter no:");
    int n,i,c=0;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        if(n%i==0){
            c++;
        }
    }
    if(c==1)
        printf("Prime No");
    else    
        printf("Composite No");
}