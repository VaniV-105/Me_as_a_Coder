#include <stdio.h>
int main(){
    int arr[]={1,2,3,4,5,6,7,8};
    int i=2;
    printf("%d",arr[i--]);
    i=2;
    printf("%d",arr[--i]);
    return 0;
}