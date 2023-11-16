//
// Created by moqi on 2023/10/30.
//
// 链式堆栈实现
// 以头结点为栈顶
#ifndef DATASTRUCTUREANDALGORITHMS_LINKSTACK_H
#define DATASTRUCTUREANDALGORITHMS_LINKSTACK_H
#include <iostream>
using namespace std;
class listStack{
private:
public:
    struct SNode{
        char Data;
        SNode* next;
    };

    static SNode* CreateStack();   //构建一个堆栈的头结点，返回指针

    static bool IsEmpty(SNode* S); //判断是否为空

    static void Push(char item, SNode *S); //将元素item压入堆栈S中

    static char Pop(SNode *S);  //删除并返回堆栈S的栈顶元素

    static void ClearStack(SNode* S);  //清空堆栈

    void LindEdit();    //利用字符栈S，从终端接受一行并传送至调用过程的数据区
};

void testListStack();

#endif //DATASTRUCTUREANDALGORITHMS_LINKSTACK_H
