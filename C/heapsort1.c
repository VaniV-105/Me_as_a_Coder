#include <stdio.h>
void print(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
        printf(" ");
    }
}
void heapify(int a[],int n,int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && a[left]>a[largest]){
        largest = left;
    }
    if(right<n && a[right]>a[largest])
        largest = right;
    if(largest!=i){
        int temp = a[i];
        a[i]=a[largest];
        a[largest]=temp;
        heapify(a,n,largest);
    }
}
void heapSort(int a[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    for(int i=n-1;i>=0;i--){
        int temp = a[0];
        a[0]=a[i];
        a[i] = temp;
        printf("Sorting step: ");
        print(a, i);
        heapify(a,i,0);
    }
}
int main(){
    printf("Enter the no of elements:");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Array before sort:");
    print(arr,n);
    heapSort(arr,n);
    printf("Array after sort:");
    print(arr,n);
    return 0;
}