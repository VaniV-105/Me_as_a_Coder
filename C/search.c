#include<stdio.h>
#include "linearsearch.h"
#include "binarysearch.h"
#include "bubblesort.h"
int main()
{
    int n,i;
    printf("Enter no of elements in the array:");
    scanf("%d",&n);
    int a[n],se,l,ch;
    printf("Enter %d elements of the array:",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter element to be searched:");
    scanf("%d",&se);
    printf("Enter your choice for search:\n\t1.Linear Search\n\t2.Binary Search\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            l=linearsearch(a,n,se);
            break;
        case 2:
            bubblesort(a,n);
            l=binarysearch(a,n,se);
            break;
        default:
            printf("Invalid choice.");
    }
    if(l==-1)
        printf("Element not found.");
    else
        printf("Element found in index: %d",l);
    return 0;
}