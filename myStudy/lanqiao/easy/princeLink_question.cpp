#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* scanfLinkList(Node* head){
    int n = 1;
    Node* p;
    Node* r = head;
    while (n<=10){
        p = new Node();
        p->data = n;
        r->next = p;
        r = r->next;
        p = nullptr;
        n++;
    }
    return head;
}

void printLinkList(Node* head){
    Node *p = head;
    while (p!= nullptr){
        cout << p->data << ' ';
        p=p->next;
    }
    cout << endl;
}

Node* changeLocation(Node *head, int X){
    Node* p = head->next;
    Node* r = head;
    while (p->data!=X){
        p=p->next;
        r=r->next;
    }
    r->next=p->next;
    p->next=head->next;
    head->next=p;

    return head;
}

int main(){
    Node *head = new Node();
    head = scanfLinkList(head);
    int M;
    cin >> M;
    while (M--){
        int X;
        cin >> X;
        changeLocation(head,X);
        printLinkList(head->next);
    }
}