#include<stdio.h>
#define max 100
int linearsearch(int a[],int key,int n){
    for(int i=0;i<n;i++){
        if(a[i]==key)
            return i+1;
    }
    return -1;
}
void main(){
    int n,key,i,arr[max];
    printf("Enter the no of elements:");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched:");
    scanf("%d",&key);
    int res=linearsearch(arr,key,n);
    if(res==-1)
        printf("Element not found.");
    else   
        printf("Element found at position:%d",res);
}