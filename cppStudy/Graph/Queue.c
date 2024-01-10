//
// Created by 尛柒 on 2024/1/10.
//
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue* initQueue(){
    Queue* Q = (Queue*) malloc(sizeof (Queue));
    Q->data = 0;
    Q->next = NULL;
    return Q;
}

void enQueue(Queue* Q, int data){
    Queue* q = Q;
    Queue* node = (Queue*) malloc(sizeof (Queue));
    node->data = data;
    for(int i = 0; i < Q->data; i++){
        q = q->next;
    }
    node->next = q->next;
    q->next = node;
    Q->data++;
}

int isEmpty(Queue* Q){
    if(Q->data == 0 || Q->next == NULL){
        return 1;
    } else {
        return 0;
    }
}

int deQueue(Queue* Q){
    if(isEmpty(Q)){
        return -1;
    } else {
        Queue *node = Q->next;
        int data = node->data;
        Q->next = node->next;
        free(node);
        Q->data--;
        return data;
    }
}

void printQueue(Queue* Q){
    Queue* node = Q->next;
    while (node){
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

