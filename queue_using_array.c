#include <stdio.h>
#include <stdlib.h>     
#define MAX 100
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;
void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}
int isEmpty(Queue *q) {
    return q->front == -1;
}
int isFull(Queue *q){
    return (q->rear + 1) % MAX == q->front;
}
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("%d enqueued to queue\n", value);
}
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Queue is empty\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return value;
}
int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->items[q->front];
}
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("\nQueue elements (front to rear):\n");
    int i = q->front;
    while (1) {
        printf("| %d |\n", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("-----\n");
}
int size(Queue *q) {
    if (isEmpty(q)) return 0;
    if (q->rear >= q->front) {
        return q->rear - q->front + 1;
    } else {
        return MAX - q->front + q->rear + 1;
    }
}
int main() {
    Queue queue;
    initialize(&queue);
    
    int choice, value;
    
    while (1) {
        printf("\n========== QUEUE OPERATIONS ==========\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Is Empty?\n");
        printf("6. Is Full?\n");
        printf("7. Size\n");
        printf("8. Exit\n");
        printf("======================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
                
            case 2:
                value = dequeue(&queue);
                if (value != -1) {
                    printf("Dequeued element: %d\n", value);
                }
                break;
                
            case 3:
                value = peek(&queue);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;
                
            case 4:
                display(&queue);
                break;
                
            case 5:
                if (isEmpty(&queue)) {
                    printf("Queue is EMPTY\n");
                } else {
                    printf("Queue is NOT EMPTY\n");
                }
                break;
                
            case 6:
                if (isFull(&queue)) {
                    printf("Queue is FULL\n");
                } else {
                    printf("Queue is NOT FULL\n");
                }
                break;
                
            case 7:
                printf("Queue size: %d\n", size(&queue));
                break;
                
            case 8:
                printf("Exiting program...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
            }
        }
return 0;