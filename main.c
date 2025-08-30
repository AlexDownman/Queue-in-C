#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node *front, *rear;
} queue;

void initQueue(queue *q) {
    q->front = q->rear = NULL;
}

bool isEmpty(queue *q) {
    if (q->front == NULL) {
        return true;
    }
    return false;
}

void enqueue(queue *q, int value) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    Node *temp = q->front;
    int dataDequeued = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return dataDequeued;
}

Node *peekNode(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return NULL;
    }
    return q->front;
}

int peekData(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}

void displayQueueRec(Node *tempNode) {
    if (tempNode->next == NULL) {
        printf("%d\n", tempNode->data);
    } else {
        printf("%d -> ", tempNode->data);
        displayQueueRec(tempNode->next);
    }
}

void displayQueue(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    }
    displayQueueRec(peekNode(q));
}

int main(void) {
    queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    while (!isEmpty(&q)) {
        displayQueue(&q);
        printf("Peeking data: %d\n", peekData(&q));
        printf("Peeking Node Data: %d\n", peekNode(&q)->data);
        dequeue(&q);
        printf("\n");
    }

    return 0;
}
