#include<stdio.h>
void heapify(int a[],int n,int i){
    int largest=i;
    int left=2*i+1,right=2*i+2;
    if(left<n && a[left]>a[largest])
        largest=left;
    if(right<n && a[right]>a[largest])
        largest=right;
    if(largest!=i){
        int temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        heapify(a,n,largest);
    }
}
void heapsort(int a[],int n){
    for(int i=n/2-1;i>=0;i--)
        heapify(a,n,i);
    for(int i=n-1;i>=0;i--){
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,i,0);
    }
}
void main(){
    int a[10]={23,45,56,76,32,12,11,9,1,3};
    heapsort(a,10);
    for(int i=0;i<10;i++){
        printf("%d ",a[i]);
    }
}