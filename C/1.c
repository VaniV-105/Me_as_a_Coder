//Program to find the perimeter of rectangle
//One static input and one dynamic input
#include<stdio.h>
int main()
{
    float h,w,peri;
    printf("Enter height of the rectangle:\n");
    scanf("%f",&h);
    printf("Enter width of the rectangle:\n");
    scanf("%f",&w);
    peri = 2*(h+w);
    printf("Perimeter of the rectangle = %.2f\n",peri);
    return 0;
}