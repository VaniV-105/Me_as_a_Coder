#include <stdio.h>
#include <string.h>

void insertionSort(char arr[], int n) {
    for (int i = 1; i < n; i++) {
        char key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    char str[] = "insertionsort";
    int len = strlen(str);

    printf("Original string: %s\n", str);

    insertionSort(str, len);

    printf("Sorted string: %s\n", str);

    return 0;
}
