//
// Created by moqi on 2023/10/30.
//
#include "Queue.h"

void testQueue() {
    queue::QNode* myQueue = queue::InitQueue();

    queue::EnQueue(myQueue, 'A');
    queue::EnQueue(myQueue, 'B');
    queue::EnQueue(myQueue, 'C');

    cout << "Queue Length: " << queue::QueueLength(myQueue) << endl;

    cout << "Queue Elements: ";
    queue::QueueTraverse(myQueue);

    char head;
    queue::GetHead(myQueue, head);
    cout << "Head of Queue: " << head << endl;

    char dequeued;
    queue::DeQueue(myQueue, dequeued);
    cout << "Dequeued Element: " << dequeued << endl;

    cout << "Updated Queue Elements: ";
    queue::QueueTraverse(myQueue);

    queue::ClearQueue(myQueue);
    cout << "Queue Length after Clearing: " << queue::QueueLength(myQueue) << endl;

    delete myQueue;
}
