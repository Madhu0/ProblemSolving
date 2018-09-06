#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

typedef struct Stack {
    int *array;
    int *top;
} Stack;

int isEmpty(Stack s) {
    if (*s.top == -1) {
        return 1;
    }
    return 0;
}

int isFull(Stack s) {
    if (*s.top == MAX_SIZE - 1) {
        return 1;
    }
    return 0;
}

void push(Stack s, int value) {
    if (!isFull(s)) {
        *s.top += 1;
        s.array[*s.top] = value;
    }
}

int pop(Stack s) {
    if (!isEmpty(s)) {
        int temp = s.array[*s.top];
        *s.top -= 1;
        return temp;
    }
    return NULL;
}

int getStackTop(Stack s) {
    if (!isEmpty(s)) {
        return s.array[*s.top];
    }
    return NULL;
}

int main() {
    Stack stack, maxStack;
    stack.array = (int *)malloc(MAX_SIZE*sizeof(int));
    stack.top = (int *)malloc(sizeof(int));
    *stack.top = -1;
    maxStack.array = (int *)malloc(MAX_SIZE*sizeof(int));
    maxStack.top = (int *)malloc(sizeof(int));
    *maxStack.top = -1;
    int testcases;
    scanf("%d", &testcases);
    while(testcases--) {
        int operation;
        int temp;
        scanf("%d", &operation);
        switch(operation) {
            case 1:
                scanf("%d", &temp);
                push(stack, temp);
                if (isEmpty(maxStack) || getStackTop(maxStack) <= temp) {
                    push(maxStack, temp);
                }
                break;
            case 2:
                temp = pop(stack);
                if (getStackTop(maxStack) == temp) {
                    pop(maxStack);
                }
                break;
            case 3:
                printf("%d\n", getStackTop(maxStack));
                break;
        }
    }
    return 1;
}