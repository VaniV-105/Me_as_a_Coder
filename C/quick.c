#include<stdio.h>
 void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partision(int arr[],int lb,int up){
    int pivot=arr[lb];
    int start=lb;
    int end=up;
    while(start<end){
        while(arr[start]<=pivot){
            start++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if(start<end){
            swap(&arr[start],&arr[end]);
        }
        
    }
    swap(&arr[lb],&arr[end]);
    return end;

}



void quicksort(int arr[],int lb,int up){
    if(lb<up){
        int partionindex=partision(arr,lb,up);
        quicksort(arr,lb,partionindex-1);
        quicksort(arr,partionindex+1,up);
    }
}




int main(){
    int i,n;
    printf("enter the nnum of elements:");
    scanf("%d",&n);

    int arr[n];
    printf("enter the numbers:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1);

    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;

}