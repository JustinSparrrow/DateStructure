//
// Created by moqi on 2023/10/25.
//

#ifndef DATASTRUCTUREANDALGORITHMS_LINEARLIST_H
#define DATASTRUCTUREANDALGORITHMS_LINEARLIST_H
#include <iostream>
using namespace std;

class linearList{
private:
    int len;
public:
    /* 使用 static 关键字可以带来以下几个作用：
     * 静态成员函数可以在不创建类的对象的情况下直接调用，因为它们不依赖于类的实例。这使得静态成员函数可以用于执行与类的实例无关的操作。
     * 静态成员函数没有隐式的 this 指针，因此无法访问非静态成员变量和非静态成员函数。它们只能访问静态成员变量和静态成员函数。
     * 静态成员函数可以通过类名直接调用，而不需要创建类的对象。这使得静态成员函数可以在不创建类的实例的情况下执行特定的操作。
     */
    linearList();  //构造函数

    static bool compare(int a, int b);

    static void visit(int e);

    int* InitList(int* L);  //操作结果：构造一个空的线性表L

    void DestroyList(const int *L);   //初始条件：线性表L存在；操作结果：销毁线性表L

    int* ClearList(int *L); //初始条件：线性表L存在；操作结果：将L重置为空表

    /* [[nodiscard]]
     * [[nodiscard]] 是一个属性（attribute），用于向编译器发出提示，要求在调用函数或方法后检查其返回值，并确保不要忽略该返回值。
     * 当你在函数或方法的声明或定义前面加上 [[nodiscard]] 属性时，编译器会在调用该函数或方法后，如果没有使用其返回值，产生一个警告或错误。
     * 这个属性可以帮助你避免忽略函数或方法的返回值，从而提高代码的健壮性和可读性。它特别适用于那些返回值具有重要意义或需要进行错误检查的函数或方法。
     */

    [[nodiscard]] bool ListEmpty(int L) const;  //初始条件：线性表L存在；操作结果：若L为空表，返回true，否则返回false

    [[nodiscard]] int ListLength(int L) const;  //初始条件：线性表工已存在；操作结果：返回L中数据元素个数

    void GetElem(const int* L, int i, int &e) const;  //初始条件：线性表L已存在，1≤i≤ListLength（L）；操作结果：用e返回工中第主个数据元素的值。

    int LocateElem(int L, int e, bool compare(int, int)) const;    //初始条件：线性表工已存在，compare（）是数据元素判定函数。操作结果：返回L中第1个与e满足关系compare（）的数据元素的位序。若这样的数据元素不存在，则返回值为0。

    void PriorElem(int L, int cur_e, int &pre_e) const;    //初始条件：线性表工已存在。操作结果：若cur-e是L的数据元素，且不是第一个，则用pre-e返回它的前驱，否则操作失败，pre-e无定义。

    void NextElem(int L, int cur_e, int &next_e) const;   //初始条件：线性表L已存在。操作结果：若cur-e是L的数据元素，且不是最后一个，则用next-e返回它的后继，否则操作失败，next-e无定义。

    int ListInsertBefore(int *L, int i, int e);  //初始条件：线性表L已存在，1≤1≤ListLength（L）+1。操作结果：在工中第i个位置之前插人新的数据元素e，的长度加1

    int ListDelete(int *L, int i, int &e);  //初始条件：线性表L已存在且非空，I≤i≤ListLength（L）。操作结果：删除工的第主个数据元素，并用e返回其值，工的长度减1。

    void ListTraverse(int L, void visit(int)) const; //初始条件：线性表工已存在。換作结果：依次对工的每个数据元素调用函数visit()。一旦visit()失败，则操作失败

    void ListUnion(linearList &La, linearList Lb);  //将所有在线性表Lb中但不在La中的数据元素插入到La中

    void MergeList(linearList La, linearList Lb, linearList &Lc);   //归并La和Lb得到新的线性表Lc，Lc的数据元素也按值非递减排列
};

void testLinearList();  //测试函数

#endif //DATASTRUCTUREANDALGORITHMS_LINEARLIST_H
