#include<stdio.h>
void insertionsort(int a[],int n){
    for(int i=1;i<n;i++){
        int j=i-1;
        int temp=a[i];
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
void main(){
    int a[10]={23,45,56,76,32,12,11,9,1,3};
    insertionsort(a,10);
    for(int i=0;i<10;i++){
        printf("%d ",a[i]);
    }
}