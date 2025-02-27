#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for stack
typedef struct {
    int* data;
    int top;
    int maxSize;
} Stack;

// Initialize stack
Stack* createStack(int maxSize) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(sizeof(int) * maxSize);
    stack->top = -1;
    stack->maxSize = maxSize;
    return stack;
}

// Check if stack is empty
int isEmpty(Stack* stack) {
    return (stack->top == -1);
}

// Check if stack is full
int isFull(Stack* stack) {
    return (stack->top == stack->maxSize - 1);
}

// Push element onto stack
void push(Stack* stack, int x) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = x;
}

// Pop element from stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->data[stack->top--];
}

// Get top element from stack
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top];
}

typedef struct {
    Stack* inputStack;
    Stack* outputStack;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->inputStack = createStack(100);
    queue->outputStack = createStack(100);
    return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    push(obj->inputStack, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if (isEmpty(obj->outputStack)) {
        while (!isEmpty(obj->inputStack)) {
            push(obj->outputStack, pop(obj->inputStack));
        }
    }
    return pop(obj->outputStack);
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if (isEmpty(obj->outputStack)) {
        while (!isEmpty(obj->inputStack)) {
            push(obj->outputStack, pop(obj->inputStack));
        }
    }
    return peek(obj->outputStack);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return isEmpty(obj->inputStack) && isEmpty(obj->outputStack);
}

/** Deallocates memory previously allocated for the queue. */
void myQueueFree(MyQueue* obj) {
    free(obj->inputStack->data);
    free(obj->inputStack);
    free(obj->outputStack->data);
    free(obj->outputStack);
    free(obj);
}

int main() {
    MyQueue* obj = myQueueCreate();
    myQueuePush(obj, 1);
    myQueuePush(obj, 2);
    int param_2 = myQueuePop(obj);
    int param_3 = myQueuePeek(obj);
    bool param_4 = myQueueEmpty(obj);
    printf("[%d, %d, %d]\n", param_2, param_3, param_4);
    myQueueFree(obj);
    return 0;
}
