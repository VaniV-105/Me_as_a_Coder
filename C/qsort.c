#include <stdio.h>
#include <stdlib.h>

// Comparison function used by qsort
int compare(const void *a, const void *b) {
    // Typecasting pointers to integers and dereferencing them
    return (*(int *)a - *(int *)b);
}

int main() {
    int arr[] = {12, 45, 7, 23, 56, 19};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Using qsort to sort the array
    qsort(arr, n, sizeof(int), compare);


    printf("Array after sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
