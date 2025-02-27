#include <stdio.h>
int main(){
    int x,f,s,t,n;
    printf("Enter the no of elements:");
    scanf("%d",&x);
    printf("Enter the elements:");
    for(int i=0;i<x;i++){
        scanf("%d",&n);
        if(i==0)
            f=s=t=n;
        else{
            if(n>f){
                t=s;
                s=f;
                f=n;
            }
            else if (n>s){
                t=s;
                s=n;
            }
            else if(n>t){
                t=n;
            }
        }
    }
    printf("Third largest element : %d",t);
}

