#include <stdio.h>  
#include <stdlib.h>
#define MAX 100
typedef struct {
    int items[MAX];
    int top;
} Stack;
void initialize(Stack *s) {
    s->top = -1;
}
int isEmpty(Stack *s) {
    return s->top == -1;
}
int isFull(Stack *s) {
    return s->top == MAX - 1;
}
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    s->items[++(s->top)] = value;
    printf("%d pushed to stack\n", value);
}
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Stack is empty\n");
        return -1;
    }
    int value = s->items[(s->top)--];
    return value;
}
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[s->top];
}
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("\nStack elements (top to bottom):\n");
    for (int i = s->top; i >= 0; i--) {
        printf("| %d |\n", s->items[i]);
    }
    printf("-----\n");
}
int size(Stack *s) {
    return s->top + 1;
}
