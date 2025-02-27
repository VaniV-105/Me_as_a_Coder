#include <stdio.h>
#include <string.h>

void merge(char **arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char *leftArr[n1], *rightArr[n2];

    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (strcmp(leftArr[i], rightArr[j]) <= 0) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(char **arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    char *arr[] = {"banana", "apple", "orange", "grape", "pineapple", "kiwi"};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array of strings:\n");
    for (int i = 0; i < size; i++)
        printf("%s ", arr[i]);
    printf("\n");

    mergeSort(arr, 0, size - 1);

    printf("Sorted array of strings:\n");
    for (int i = 0; i < size; i++)
        printf("%s ", arr[i]);
    printf("\n");

    return 0;
}
