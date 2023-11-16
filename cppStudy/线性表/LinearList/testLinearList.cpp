#include "linearList.h"

void testLinearList() {
    cout << "--------Initializing the linear list--------" << endl;
    linearList list;
    int* L = list.InitList(nullptr);

    cout << "--------Inserting elements--------" << endl;
    list.ListInsertBefore(L, 1, 10);
    list.ListInsertBefore(L, 2, 20);
    list.ListInsertBefore(L, 3, 30);

    cout << "--------Traversing the list--------" << endl;
    list.ListTraverse(*L, linearList::visit);
    cout << endl;
    cout << "--------Traversing the list--------" << endl;

    int e;
    list.GetElem(L, 2, e);
    cout << "Element at position 2: " << e << endl;

    int pos = list.LocateElem(*L, 30, linearList::compare);
    cout << "Position of element 30: " << pos << endl;

    list.PriorElem(*L, 30, e);
    cout << "Prior element of 30: " << e << endl;

    list.NextElem(*L, 30, e);
    cout << "Next element of 30: " << e << endl;

    cout << "--------Inserting 55 before position 3--------" << endl;
    list.ListInsertBefore(L, 2, 55);
    list.ListTraverse(*L, linearList::visit);
    cout << endl;

    cout << "--------Deleting element at position 4--------" << endl;
    list.ListDelete(L, 3, e);
    cout << "Deleted element: " << e << endl;
    list.ListTraverse(*L, linearList::visit);
    cout << endl;

    cout << "--------Clearing the list--------" << endl;
    list.ClearList(L);
    cout << "List length after clearing: " << list.ListLength(*L) << endl;

    cout << "--------Destroying the list--------" << endl;
    list.DestroyList(L);
}