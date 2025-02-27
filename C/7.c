#include <stdio.h>
int main()
{
    int a,b,opt;
    printf("1.Add 2.Sub 3.Mult 4.Div\n");
    printf("Enter opt:");
    scanf("%d",&opt);
    printf("Enter No 1:");
    scanf("%d",&a);
    printf("Enter No 2:");
    scanf("%d",&b);
    switch(opt)
    {
        case 1:
            printf("Sum = %d",a+b);
            break;
        case 2:
            printf("Difference = %d",a-b);
            break;
        case 3:
            printf("Product = %d",a*b);
            break;
        case 4:
            printf("Quotient = %d",a/b);
            break;
        default:
            printf("Wrong Option");
    }
    return 0;
}