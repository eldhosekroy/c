#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Queue {
    int front, rear;
    int capacity;
    int* array;
};

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (!queue) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    if (!queue->array) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    return queue;
}

int isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

int isFull(struct Queue* queue) {
    return ((queue->rear + 1) % queue->capacity == queue->front);
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d\n", item);
        return;
    }
    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % queue->capacity;
    }
    queue->array[queue->rear] = item;
    printf("Enqueued %d\n", item);
}

int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue\n");
        return -1;
    }
    item = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    printf("Dequeued %d\n", item);
    return item;
}

int front(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->array[queue->front];
}

int rear(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->array[queue->rear];
}

void display(struct Queue* queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    i = queue->front;
    do {
        printf("%d ", queue->array[i]);
        i = (i + 1) % queue->capacity;
    } while (i != (queue->rear + 1) % queue->capacity);
    printf("\n");
}

int main() {
    int choice, item;
    struct Queue* queue = createQueue(MAX_SIZE);

    do {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Front\n");
        printf("5. Rear\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &item);
                enqueue(queue, item);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                printf("Front element: %d\n", front(queue));
                break;
            case 5:
                printf("Rear element: %d\n", rear(queue));
                break;
            case 0:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    return 0;
}

