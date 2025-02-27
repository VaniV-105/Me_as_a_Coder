#include <math.h>
#include <stdio.h>
int main(){
int x,y,m,n;
printf("enter x and y coordinate=");
scanf("%d %d",&x,&y);
printf("enter m and n coordinate=");
scanf("%d %d",&m,&n);
printf("the coordinate of one point is (%d , %d)\n",x,y);
printf("the coordinate of other point is (%d , %d)\n",m,n);
float a=(((n-y)*(n-y))+((m-x)*(m-x)));
printf("enter = %f\n",a);
printf("the distance between two points are =%.4f",sqrt(a));
}