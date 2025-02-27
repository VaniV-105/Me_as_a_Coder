#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(){
    printf("Enter a number :");
    int num,sum=0;
    scanf("%d",&num);
    int n = num;
    while (n>0){
        int d=n%10;
        sum = sum* 10 +d;
        n=n/10;
    }
    if(sum == num)
        printf("Palindrome Number\n");
    else
        printf("Not a palindrome Number\n");
    
    char s[20];
    sprintf(s,"My name is Aashin");
    printf("%s\n",s);
    int number = 255;
    printf("hexadecimal equivalent is %X \n",number);
    printf("Octal representation is %o \n",number);
    return 0;
}