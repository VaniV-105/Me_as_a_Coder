#include <stdio.h>
#include <stdlib.h>
int* createList(int n){
    int* a = (int *)malloc(n*sizeof(int));
    return a;
}
int* getElements(int* a,int n){
    int data;
    for(int i=0;i<n;i++){
        printf("Enter Element %d :",i+1);
        scanf("%d",&data);
        a[i] = data;
    }
    return a;
}
void PrintList(int* a,int n){
    printf("The List is:\n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
int* MakeEmpty(int* a,int n){
    for(int i=0;i<n;i++){
        a[i]= 0;
    }
    return a;
}
int Find(int *a,int n,int key){
    for(int i=0;i<n;i++){
        if(a[i]==key)
            return (i+1);
    }
    return -1;
}
int FindKth(int *a,int n,int k){
    if(n<k){
        printf("Kth element not present.");
        return 0;
    }
    else
        return a[k+1];
}
int main() {
    int n,key;
    printf("Enter the no of elements:");
    scanf("%d",&n);
    int* myList = createList(n); 
    myList = getElements(myList,n);
    PrintList(myList,n);
    //MakeEmpty(myList,n);
    //PrintList(myList,n);
    printf("Enter element to be found:");
    scanf("%d",&key);
    int pos = Find(myList,n,key);
    if(pos == -1)
        printf("Element Not Found.");
    else
        printf("Element Found At Position: %d",pos);
    printf("Enter k:");
    int k;
    scanf("%d",&k);
    printf("Element at position %d is %d.",k,FindKth(myList,n,k));
    return 0;
}