#include<stdio.h>
int main(){
    char op;// Variable for operator
    int a,b;// Variable for operands
    printf("Operand 1:");
    scanf("%d",&a);
    printf("Operand 2:");
    scanf("%d",&b);
    printf("Operator:");
    scanf("%s",&op);
    switch(op){
        case '+':
            printf("%d %c %d = %d",a,op,b,a+b);
            break;
        case '-':
            printf("%d %c %d = %d",a,op,b,a-b);
            break;
        case '*':
            printf("%d %c %d = %d",a,op,b,a*b);
            break;
        case '/':
            printf("%d %c %d = %d",a,op,b,a/b);
            break;
        case '%':
            printf("%d %c %d = %d",a,op,b,a%b);
            break;
        default:
            printf("Enter a Valid Operator.");
    }
    return 0;
}
    

