//
// Created by moqi on 2023/10/25.
//
#include "linearList.h"

/* 注意：
 * L: 这表示指针L本身，即指向动态数组的指针。
 * &L: 这表示指针L的地址，即指向指针L的指针。如果L是一个指向动态数组的指针，那么&L将是一个指向指针L的指针。
 * *L: 这表示对指针L进行解引用操作，即获取指针L所指向的值。如果L是一个指向动态数组的指针，那么L将表示数组的第一个元素
 * *&L: 这表示对指针L的引用，即获取指针L的引用。由于L本身就是一个指针，所以&L等价于L。
 * &*L：这表示对指针L所指向的值的地址，即获取指针L所指向的值的引用。如果L是一个指向动态数组的指针，那么&*L将是数组的第一个元素的地址。
 *
 * 这里的L是指针，不是数组
 */

//构造函数
linearList::linearList() {
    len = 0;
}

bool linearList::compare(int a, int b) {
    return a == b;
}

void linearList::visit(int e){
    cout << e << ' ';
}

//构造一个线性表L
int *linearList::InitList(int *L) {
    L = new int[10];
    len = 0;
    cout << "initialize successfully" << endl;
    return L;
}

/* 注意：
 * 释放内存和修改数据是不同的操作。
 * 释放内存是指将之前分配的内存空间返回给操作系统，使其可以被其他程序使用。这是通过使用`delete`或`delete[]`操作符来完成的，具体取决于内存是使用`new`还是`new[]`分配的。
 * 修改数据是指更改变量或数据结构中存储的值。这可以通过直接赋值、使用指针进行间接赋值或调用相应的函数来实现。
 * 在C++中，释放内存和修改数据是不同的操作。释放内存是为了回收之前分配的内存空间，而修改数据是为了更改存储在内存中的值。在释放内存之后，访问已释放的内存可能会导致未定义的行为，因此在释放内存之前，确保不再需要访问该内存。
 */

//销毁线性表L
/*
 * const 关键字放置在指针类型 int * 前面，表示指针所指向的数据是常量，即不能通过指针修改数据的值。这意味着在函数体内，不能通过指针 L 修改指向的数据
 */
void linearList::DestroyList(const int *L) {
    if (L == nullptr)
        cout << "No such list!" << endl;
    else
        delete[] L;
    len = 0;
}

//重置线性表L为空表
int *linearList::ClearList(int *L) {
    DestroyList(L);
    return InitList(L);
}

//判断线性表L是否为空
bool linearList::ListEmpty(int L) const {
    return ListLength(L) == 0;
}

//返回线性表L中的数据元素个数
/*
 * 将 const 放置在函数参数列表的后面，可以确保在常量成员函数中，不能修改类的成员变量。这是因为常量成员函数被设计为不会对对象的状态产生任何影响，只能读取对象的状态
 */
int linearList::ListLength(int L) const {
    return len;
}

//返回线性表L中第i个位置的元素值到变量e中
void linearList::GetElem(const int* L, int i, int &e) const {
    if(i < 1|| i > len+1){
        cout << "Error location!" << endl;
        return;
    }
    e = L[i-1];
}

//返回线性表L中第一个与e满足判定函数compare()的元素的位序，若不存在则返回0
int linearList::LocateElem(int L, int e, bool (*compare)(int a, int b)) const {
    if(ListEmpty(L))
        return 0;
    for(int i = 0; i < ListLength(L); i++){
        int a = 0;
        GetElem(&L, i, a);
        if(compare(a, e))
            return i+1;
    }
    return 0;
}

//如果当前元素cur_e在L中存在且不是第一个元素，则返回它的前驱元素值到变量pre_e中，否则操作失败
void linearList::PriorElem(int L, int cur_e, int &pre_e) const {
    if (ListEmpty(L)) {
        return;
    }
    int cur_index = LocateElem(L, cur_e, compare);
    if (cur_index <= 1) {
        return;
    }
    GetElem(&L, cur_index - 1, pre_e);
}

//如果当前元素cur_e在L中存在且不是最后一个元素，则返回它的后继元素值到变量next_e中，否则操作失败
void linearList::NextElem(int L, int cur_e, int &next_e) const {
    if (ListEmpty(L)) {
        return;
    }
    int cur_index = LocateElem(L, cur_e, compare);
    if (cur_index == 0 || cur_index == ListLength(L)) {
        return;
    }
    GetElem(&L, cur_index + 1, next_e);
}

//在线性表L的第i个位置之前插入新的数据元素e，并返回新插入的元素值
int linearList::ListInsertBefore(int *L, int i, int e) {
    len++;
    if (i < 1 || i > len + 1) {
        return -1;
    }
    for (int j = len-1; j >= i; j--) {
        L[j] = L[j - 1];
    }
    L[i-1] = e;
    cout << "Insert successfully" << endl;
    return e; // Success
}

//删除线性表L的第i个数据元素，并返回被删除的元素值到变量e中
int linearList::ListDelete(int *L, int i, int &e) {
    if (i < 1 || i > len) {
        cout << "Error: Invalid index!" << endl;
        return -1;
    }
    e = L[i-1];
    for (int j = i; j < len - 1; j++) {
        L[j] = L[j + 1];
    }
    len--;
    return e;
}

//依次对线性表L的每个数据元素调用函数visit()，一旦visit()失败，则操作失败
void linearList::ListTraverse(int L, void (*visit)(int e)) const {
    for(int i = 0; i < ListLength(L); i++){
        int e = 0;
        GetElem(&L, i+1, e);
        visit(e);
    }
}

//将所有在线性表Lb中但不在La中的数据元素插入到La中
void linearList::ListUnion(linearList &La, linearList Lb) {
    int e;
    for (int i = 0; i < Lb.len; i++) {
        if (La.LocateElem(La.len, Lb.len, compare) == 0) {
            La.ListInsertBefore(&La.len, i, Lb.len);
        }
    }
}

//归并La和Lb得到新的线性表Lc，Lc的数据元素也按值非递减排列
void linearList::MergeList(linearList La, linearList Lb, linearList &Lc) {
    int i = 0, j = 0, k = 0;
    while (i < La.len && j < Lb.len) {
        if (La.len < Lb.len) {
            Lc.ListInsertBefore(&Lc.len, k++, La.len);
            i++;
        } else {
            Lc.ListInsertBefore(&Lc.len, k++, Lb.len);
            j++;
        }
    }
    while (i < La.len) {
        Lc.ListInsertBefore(&Lc.len, k++, La.len);
        i++;
    }
    while (j < Lb.len) {
        Lc.ListInsertBefore(&Lc.len, k++, Lb.len);
        j++;
    }
}
