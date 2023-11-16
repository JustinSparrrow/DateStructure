//
// Created by moqi  on 2023/10/26.
//
#include "linkList.h"

bool linkList::compare(int a, int b) {
    return a==b;
}

void linkList::visit(int a) {
    cout << a << ' ';
}

linkList::linkList() {
    head = nullptr;
    tail = nullptr;
}

//分配由p指向的值为e的节点，并返回true；若分配失败，返回false
bool linkList::MakeNode(linkList::Node* &p, int e) {
    p = new Node();
    if (!p) return false;
    p->data = e;
    p->next = nullptr;
    return true;
}

//释放p所指结点
void linkList::FreeNode(linkList::Node &p) {
    Node* q = head;
    while (q->next!=&p){
        q=q->next;
    }
    q->next=p.next;
    delete &p;
}

//构造一个空的线性链表
linkList::Node *linkList::InitList(linkList::Node *head, linkList::Node *tail) {
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->next = nullptr;
    head->data=-1;
    tail->data=-2;
    return head;
}

//销毁线性链表L，L不再存在
void linkList::DestroyList(linkList::Node *head, linkList::Node *tail) {
    Node* curr = head;
    while (curr != nullptr){
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

//将线性链表L重置为空表，并释放原链表的节点空间
linkList::Node *linkList::ClearList(linkList::Node *head, linkList::Node *tail) {
    DestroyList(head, tail);
    InitList(head, tail);
    return head;
}

//已知h指向线性链表的头结点，将s所指节点插入在第一个节点之前
linkList::Node *linkList::InsFirst(linkList::Node h, linkList::Node s) {
    s.next = h.next;
    h.next = &s;
    return &h;
}

//已知h指向线性链表的头结点，删除链表中的第一个节点并以q返回
linkList::Node *linkList::DelFirst(linkList::Node h, linkList::Node &q) {
    Node *curr = h.next;
    h.next = curr->next;
    delete curr;
    return &q;
}

//将指针s所致（彼此以指针相链）的一串节点连接在线性链表L的尾节点前
linkList::Node *linkList::Append(linkList::Node *head, linkList::Node *tail, linkList::Node *s) {
    if (head == nullptr) {
        // 如果链表为空，将s作为新的头节点
        return s;
    }
    if (head == tail) {
        // 如果链表只有一个节点，将s插入在头节点之前
        s->next = head;
        return s;
    }
    Node* curr = head;
    while (curr->next != tail) {
        curr = curr->next;
    }
    curr->next = s;
    s->next = tail;
    return head;
}

//删除线性链表L中的尾节点并以q返回，改变链表L的尾指针指向新的尾节点
linkList::Node *linkList::Remove(linkList::Node *head, linkList::Node *tail, linkList::Node &q) {
    Node* curr = head;
    while (curr->next!=tail)
        curr=curr->next;
    Node* newCurr = head;
    while (newCurr->next!=curr)
        newCurr=newCurr->next;
    newCurr->next=tail;
    q = *curr;
    return head;
}

//已知p指向线性链表L中的一个节点，将s所指节点插入到p所指节点之前，并修改指针p指向新插入的节点
linkList::Node *linkList::InsBefore(linkList::Node *head, linkList::Node *tail, linkList::Node &p, linkList::Node s) {
    Node* curr = head;
    while (curr->next!=&p)
        curr=curr->next;
    curr->next = &s;
    s.next = &p;
    p = *(curr->next);
    return head;
}

//已知p指向线性链表L中的一个节点，将s所指节点插入到p所指节点之后，并修改指针p指向新插入的节点
linkList::Node *linkList::InsAfter(linkList::Node *head, linkList::Node *tail, linkList::Node &p, linkList::Node s) {
    Node* curr = p.next;
    p.next=&s;
    s.next=curr;
    return head;
}

//已知p指向线性链表中的一个节点，返回p所指节点中数据元素的值
linkList::Node * linkList::SetCurElem(linkList::Node &p, int e) {
    p.data = e;
    return head;
}

//已知p指向线性链表中的一个节点，返回p所指节点中数据元素的值
int linkList::GetCurElem(linkList::Node p) {
    return p.data;
}

//若线性链表L为空表，则返回true，否则返回false
bool linkList::ListEmpty(linkList::Node *head, linkList::Node *tail) {
    if (head == nullptr) {
        return true;
    } else {
        return false;
    }
}

//返回线性链表L中的元素个数
int linkList::ListLength(linkList::Node *head, linkList::Node *tail) {
    int nums = 0;
    Node *curr = head->next;
    while (curr!= tail) {
        curr = curr->next;
        nums++;
    }
    return nums;
}

linkList::Node *linkList::GetHead(linkList::Node *head, linkList::Node *tail) {
    return head;
}


linkList::Node *linkList::GetLast(linkList::Node *head, linkList::Node *tail) {
    return tail;
}

//已知p指向线性链表L中的一个节点，返回p所指节点的直接前驱的元素
int linkList::PriorPos(linkList::Node *head, linkList::Node *tail, linkList::Node p) {
    Node* curr = head;
    while (curr->next!=&p)
        curr=curr->next;
    return curr->data;
}

//已知p指向线性链表L中的一个节点，返回p所指节点的直接后继的元素
int linkList::NextPos(linkList::Node *head, linkList::Node *tail, linkList::Node p) {
    return p.next->data;
}

//返回线性表L中第1个与e满足函数compare（）判定关系的元素的位置；若不存在，返回-1
int linkList::LocateElem(linkList::Node *head, linkList::Node *tail, int e, bool (*compare)(int, int)) {
    Node* curr = head;
    int index = 0;
    while (curr!=tail){
        if(compare(curr->data, e)){
            return index;
        }
        curr=curr->next;
        index++;
    }
    return -1;
}

//依次对L的每一个元素调用函数visit（）。一旦visit失败，则操作失败
void linkList::ListTraverse(linkList::Node *head, linkList::Node *tail) {
    Node *curr = head;
    while (curr!= nullptr){
        visit(curr->data);
        curr=curr->next;
    }
    cout << endl;
}

//归并La和Lb得到新的单链线性表Lc，Lc的元素按值非递减排列
linkList::Node *linkList::MergeList_L(linkList::Node *head_La, linkList::Node *tail_La, linkList::Node *head_Lb,
                                      linkList::Node *tail_Lb, linkList::Node *head_Lc, linkList::Node *tail_Lc) {
    head_Lc->next=head_La->next;
    Node* curr = head_Lc;
    while (curr->next!=tail_La){
        curr=curr->next;
    }
    curr->next = head_Lb->next;
    while (curr->next!=tail_Lb)
        curr=curr->next;
    curr->next = tail_Lc;
    delete head_La, head_Lb, tail_La, tail_Lb;
    return head_Lc;
}