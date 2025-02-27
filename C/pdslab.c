#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Initialize stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Push operation to add an element to the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow, cannot push element\n");
    } else {
        stack->top++;
        stack->items[stack->top] = value;
        printf("%d pushed to stack\n", value);
    }
}

// Pop operation to remove an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow, cannot pop element\n");
        return -1;
    } else {
        int popped = stack->items[stack->top];
        stack->top--;
        return popped;
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    int n;
    printf("Enter the number of test cases: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int query;
        printf("Enter the number of queries for test case %d: ", i + 1);
        scanf("%d", &query);

        for (int j = 0; j < query; j++) {
            char str[10]; // Assuming the maximum length of the string is 10 characters
            int value = 0;
            printf("Enter 'place' or 'remove' followed by a value: ");
            scanf("%s %d", str, &value);

            if (strcmp(str, "place") == 0) {
                push(&stack, value);
            } else if (strcmp(str, "remove") == 0) {
                int removed = pop(&stack);
                if (removed != -1) {
                    printf("%d removed from stack\n", removed);
                }
            }
        }
    }

    return 0;
}
