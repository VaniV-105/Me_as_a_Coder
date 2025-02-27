#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int stack[MAX_SIZE];
int top = -1;

void place(int x) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = x;
    }
}

int removeBook() {
    if (top >= 0) {
        int removedBook = stack[top--];
        return removedBook;
    } else {
        return -1;
    }
}

int main() {
    int Q, i, x;
    char query[10];

    scanf("%d", &Q);

    for (i = 0; i < Q; ++i) {
        scanf("%s", query);

        if (query[0] == 'p') {
            // Type 1: place
            scanf("%d", &x);
            place(x);
        } else {
            // Type 2: remove
            int removedBook = removeBook();
            printf("%d ", removedBook);
        }
    }

    return 0;
}
     
