//
// Created by moqi on 2023/10/30.
//
#include "Queue.h"

queue::QNode *queue::InitQueue() {
    queue::QNode *myQueue = new QNode();
    return myQueue;
}

void queue::DestroyQueue(queue::QNode *Q) {
    queue::QNode *curr = Q->next;
    while (curr!= nullptr){
        free(Q);
        Q=curr;
        curr = curr->next;
    }
    free(Q);
}

bool queue::QueueEmpty(queue::QNode *Q) {
    return (Q->next == nullptr);
}

int queue::QueueLength(queue::QNode *Q) {
    int len = 0;
    queue::QNode *curr = Q->next;
    while (curr!= nullptr){
        len++;
        curr = curr->next;
    }
    return len;
}

void queue::ClearQueue(queue::QNode *Q) {
    DestroyQueue(Q);
    Q = InitQueue();
}

char queue::GetHead(queue::QNode *Q, char &e) {
    e = Q->next->data;
    return e;
}

void queue::EnQueue(queue::QNode *Q, char e) {
    QNode *curr = new QNode();
    curr->data = e;
    curr->next = Q->next;
    Q->next = curr;
}

char queue::DeQueue(queue::QNode *Q, char &e) {
    QNode *curr = Q;
    while (curr->next->next!= nullptr){
        curr=curr->next;
    }
    QNode *decurr = curr->next;
    e = decurr->data;
    free(decurr);
    curr->next = nullptr;
    return 0;
}

void queue::QueueTraverse(queue::QNode *Q) {
    QNode* curr = Q->next;
    while (curr!= nullptr){
        cout << curr->data << ' ';
        curr = curr->next;
    }
    cout << endl;
}
