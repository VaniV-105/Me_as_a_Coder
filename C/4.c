#include <stdio.h>
#include <stdbool.h>
bool positive(int a)
{
    return a>0;
}
int main()
{
    int a;
    printf("Enter a no:");
    scanf("%d",&a);
    if(positive(a))
        printf("Positive No");
    else
        printf("Negative No");
    return 0;
}