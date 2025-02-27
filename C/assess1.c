#include<stdio.h>
void main(){
    int n,sum=0;
    printf("Enter no of numbers:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        sum+=i;
        printf("%.1f,",(float)sum/i);
    }
}