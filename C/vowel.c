#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<stdbool.h>
int main(){
    printf("Enter a character:");
    char a;
    scanf("%c",&a);
    a = tolower(a);
    if(a=='a' || a=='e' || a=='i'||a=='o'||a=='u')
        printf("Vowel");
    else  
        printf("Consonant");
    printf("%d",(bool)isalnum(a));
}