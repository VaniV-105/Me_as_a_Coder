#include<stdio.h>
#define max 100
int binarysearch(int a[],int key,int n){
    int left=0,right=n-1,mid;
    while(left<=right){
        mid=left+(right-left)/2;
        if(a[mid]==key)
            return mid+1;
        else if(a[mid]<key)
            left=mid+1;
        else    
            right=mid-1;
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
    int res=binarysearch(arr,key,n);
    if(res==-1)
        printf("Element not found.");
    else   
        printf("Element found at position:%d",res);
}