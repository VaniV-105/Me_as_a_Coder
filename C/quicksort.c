#include <stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a= *b;
    *b = temp;
}
int partition(int arr[],int lb,int ub){
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    while(start<end){
        while(arr[start]<=pivot){
            ++start;
        }
        while(arr[end]>pivot){
            --end;
        }
        if(start<end){
            swap(&arr[start],&arr[end]);
        }
    }
    swap(&arr[lb],&arr[end]);
    return end;
}
void quicksort(int arr[],int lb,int ub){
    if(lb<ub){
    int pi = partition(arr,lb,ub);
    quicksort(arr,lb,pi-1);
    quicksort(arr,pi+1,ub);
    }
}
void main(){
    int a[10]={23,45,56,76,32,12,11,9,1,3};
    quicksort(a,0,9);
    for(int i=0;i<10;i++){
        printf("%d ",a[i]);
    }
}