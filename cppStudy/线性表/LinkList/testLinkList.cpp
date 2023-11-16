#include "linkList.h"

void testLinkList() {
    linkList myList;
    myList.head = myList.InitList(myList.head, myList.tail);
    myList.ListTraverse(myList.head, myList.tail);

    for(int i = 1; i <= 5; i++) {
        linkList::Node *s = nullptr;
        myList.MakeNode(s, i*10);
        myList.head = myList.Append(myList.head, myList.tail, s);
        myList.ListTraverse(myList.head, myList.tail);
    }

    cout << myList.ListLength(myList.head, myList.tail) << endl;
    myList.ListTraverse(myList.head, myList.tail);
}