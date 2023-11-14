//
// Created by moqi on 2023/10/26.
//

#ifndef DATASTRUCTUREANDALGORITHMS_LINKLIST_H
#define DATASTRUCTUREANDALGORITHMS_LINKLIST_H
#include <iostream>
using namespace std;

class linkList{
private:

public:
    struct Node{
        int data;
        Node *next;
    };
    Node *head;
    Node *tail;

    static bool compare(int a, int b);

    static void visit(int a);

    linkList();

    bool MakeNode(Node* &p, int e);  //分配由p指向的值为e的节点，并返回true；若分配失败，返回false

    void FreeNode(Node &p); //释放p所指结点

    Node* InitList(Node *head, Node *tail); //构造一个空的线性链表

    void DestroyList(Node *head, Node *tail);   //销毁线性链表L，L不再存在

    Node* ClearList(Node *head, Node *tail);    //将线性链表L重置为空表，并释放原链表的节点空间

    Node* InsFirst(Node h, Node s); //已知h指向线性链表的头结点，将s所指节点插入在第一个节点之前

    Node* DelFirst(Node h, Node &q);    //已知h指向线性链表的头结点，删除链表中的第一个节点并以q返回

    Node* Append(Node *head, Node *tail, Node* s);   //将指针s所致（彼此以指针相链）的一串节点连接在线性链表L的最后一个节点上

    Node* Remove(Node *head, Node *tail, Node &q);  //删除线性链表L中的为节点并以q返回，改变链表L的尾指针指向新的尾节点

    Node* InsBefore(Node *head, Node *tail, Node &p, Node s);   //已知p指向线性链表L中的一个节点，将s所指节点插入到p所指节点之前，并修改指针p指向新插入的节点

    Node* InsAfter(Node *head, Node *tail, Node &p, Node s);    //已知p指向线性链表L中的一个节点，将s所指节点插入到p所指节点之后，并修改指针p指向新插入的节点

    Node * SetCurElem(Node &p, int e);   //已知p指向线性链表中的一个节点，用e更新节点的值

    int GetCurElem(Node p); //已知p指向线性链表中的一个节点，返回p所指节点中数据元素的值

    bool ListEmpty(Node *head, Node *tail); //若线性链表L为空表，则返回true，否则返回false

    int ListLength(Node *head, Node *tail); //返回线性链表L中的元素个数

    Node* GetHead(Node *head, Node *tail);

    Node* GetLast(Node *head, Node *tail);

    int PriorPos(Node *head, Node *tail, Node p);   //已知p指向线性链表L中的一个节点，返回p所指节点的直接前驱的元素

    int NextPos(Node *head, Node *tail, Node p);    //已知p指向线性链表L中的一个节点，返回p所指节点的直接后继的元素

    int LocateElem(Node *head, Node *tail, int e, bool(*compare)(int, int));    //返回线性表L中第1个与e满足函数compare（）判定关系的元素的位置；若不存在，返回-1

    void ListTraverse(Node *head, Node *tail);  //依次对L的每一个元素调用函数visit（）。一旦visit失败，则操作失败

    Node* MergeList_L(Node *head_La, Node *tail_La, Node *head_Lb, Node *tail_Lb, Node *head_Lc, Node *tail_Lc);    //归并La和Lb得到新的单链线性表Lc，Lc的元素按值非递减排列
};

void testLinkList();

#endif //DATASTRUCTUREANDALGORITHMS_LINKLIST_H
