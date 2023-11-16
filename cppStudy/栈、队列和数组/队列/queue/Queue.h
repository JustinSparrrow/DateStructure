//
// Created by moqi on 2023/10/30.
//

#ifndef DATASTRUCTUREANDALGORITHMS_QUEUE_H
#define DATASTRUCTUREANDALGORITHMS_QUEUE_H
#include <iostream>
using namespace std;
class queue{
public:
    struct QNode{
        char data;
        QNode *next;
    };

    static QNode* InitQueue(); //构造一个空队列

    static void DestroyQueue(QNode* Q);    //销毁队列

    static bool QueueEmpty(QNode* Q);  //判断队列是否为空

    static int QueueLength(QNode* Q);  //返回队列的长度

    static void ClearQueue(QNode* Q);  //清空队列

    static char GetHead(QNode* Q, char &e);    //获得队首的值

    static void EnQueue(QNode* Q, char e); //插入进队尾

    static char DeQueue(QNode *Q, char &e);    //删除队首

    static void QueueTraverse(QNode *Q);   //遍历
};

void testQueue();

#endif //DATASTRUCTUREANDALGORITHMS_QUEUE_H
