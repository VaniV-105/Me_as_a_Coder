#include <stdio.h>
int main()
{
    printf("Enter a no:");
    int n,sum=0;
    scanf("%d",&n);
    int m=n;
    while(m>0)
    {
        int d=m%10;
        sum+=d*d*d;
        m=m/10;
    }
    if(sum==n)
        printf("Armstrong no.");
    else
        printf("Not an Armstrong no.");
    return 0;
}