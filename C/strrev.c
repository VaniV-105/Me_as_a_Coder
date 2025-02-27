#include<stdio.h>
#include<string.h>
int main()
{
    char a[20];
    printf("Enter a String:");
    scanf("%s",&a);
    printf("%s",strrev(a));
    return 0;
}