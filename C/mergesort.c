#include<stdio.h>
void merge(int a[],int l,int m,int r){
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1];
    int R[n2];
    for(i=0;i<n1;i++)
        L[i]=a[l+i];
    for(j=0;j<n1;j++)
        R[j]=a[m+j+1];
    i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            a[k]=L[i];
            i++;
        }
        else{
            a[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
       a[k]=L[i];
       i++; 
       k++;
    }
    while(i<n2){
       a[k]=R[j];
       j++; 
       k++;
    }
}
void mergesort(int a[],int l,int r){
    if(l<r){
        int m=l+(r-l)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}
void main(){
    int a[10]={23,45,56,76,32,12,11,9,1,3};
    mergesort(a,0,10);
    for(int i=0;i<10;i++){
        printf("%d ",a[i]);
    }
}