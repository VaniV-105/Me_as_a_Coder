#include<stdio.h>
int main(){
    char name[20],grade;
    int mark;
    printf("Name of Student:");
    scanf("%s",&name);
    printf("Marks:");
    scanf("%d",&mark);
    if(mark>89){
        grade = 'X';
    } else if(mark>79){
        grade = 'A';
    } else if ( mark > 69 ){
        grade = 'B';
    } else if ( mark > 59 ){
        grade = 'C';
    } else if (mark > 49){
        grade = 'D';
    } else if (mark > 34){
        grade = 'P';
    } else {
        grade = 'F';
    }
    printf("Name: %s\n",name);
    printf("Mark: %d\n",mark);
    printf("Grade: %c\n",grade);
    return 0;
}