//
// Created by 尛柒 on 2024/1/10.
//

#ifndef GRAPH_QUEUE_H
#define GRAPH_QUEUE_H
typedef struct Queue {
    int data;
    struct Queue* next;
} Queue;

Queue* initQueue();
void enQueue(Queue* Q, int data);
int isEmpty(Queue* Q);
int deQueue(Queue* Q);
void printQueue(Queue* Q);

#endif //GRAPH_QUEUE_H
