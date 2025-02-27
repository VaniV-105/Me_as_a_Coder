#include<stdio.h>
int main(){
int c=0;
int temp=0;
int max,min,avg,a,sum;
printf("enter the number=");
scanf("%d",&a);
min=a;
max=a;
while (a!=0){
c=c+1;
if(a<=min){
min=a;
}
if(a>=max){
max=a;
}
sum=sum+a;
printf("enter the number=");
scanf("%d",&a);
}
avg=sum/c;
printf(" the maximum number is %d",max);
printf(" the minimum number is %d",min);
printf(" the average is %d",avg);
}
