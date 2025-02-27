#include <stdio.h>
#include <stdlib.h>
void swap(int* a,int* b){
    int temp = *a;
    *a=*b;
    *b=temp;
}
int LinearSearch(int arr[],int size,int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key)
            return i+1;
    }
    return -1;
}
int BinarySearch(int arr[],int size,int key){
    int left=0;
    int right=size-1;
    while(left<=right){
        int mid= left+(right-left)/2;
        if(arr[mid]==key)
            return mid+1;
        else if(arr[mid]>key)
            right = mid-1;
        else
            left = mid+1;
    }
    return -1;
}
void insertionSort(int arr[],int size){
    for(int i=1;i<size;i++){
        int temp = arr[i];
        int j =i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right = 2*i+2;
    if(left<n && arr[left]>arr[largest])
        largest=left;
    if(right<n && arr[right]>arr[largest])
        largest=right;
    if(largest!=i){
        swap(&arr[largest],&arr[i]);
        heapify(arr,n,largest);
    }
}
void heapSort(int arr[],int n){
    int i;
    for(i=n/2-1;i>=0;i--)
        heapify(arr,n,i);
    for(i=n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}
void merge(int arr[],int l,int m,int r){
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
        L[i]=arr[l+i];
    for(j=0;j<n2;j++)
        R[j]=arr[m+j+1];
    i=0;j=0;k=l;
    while(i<n1 && j<n2){
        if(L[i]<R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int l,int r){
    if(l<r){
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
int partition(int arr[],int lb,int ub){
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    while(start<end){
        while(arr[start]<=pivot)
            start++;
        while(arr[end]>pivot)
            end--;
        if(start<end)
            swap(&arr[start],&arr[end]);
    }
    swap(&arr[lb],&arr[end]);
    return end;
}
int quickSort(int arr[],int lb,int ub){
    if(lb<ub){
    int pi=partition(arr,lb,ub);
    quickSort(arr,lb,pi-1);
    quickSort(arr,pi+1,ub);
    }
}
int main(){
    int a[]={12,4,5,2,1,13,56,43};
    mergeSort(a,0,7);
    for(int i=0;i<8;i++){
        printf("%d ",a[i]);
    }
}