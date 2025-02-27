#include <stdio.h>
void swap(int* a,int* b) // Function to swap using pointers
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(void)
{
    printf("Enter two numbers:");
    int a,b;
    scanf("%d %d",&a,&b);
    printf("Value before swap:\na = %d \nb = %d\n",a,b);
    swap(&a,&b);
    printf("Value after swap:\na = %d \nb = %d\n",a,b);
    return 0;
}