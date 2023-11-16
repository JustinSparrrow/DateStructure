//
// Created by moqi on 2023/10/27.
//
// 栈的顺序存储实现
// 栈的顺序存储结构通常由一个一维数组和一个记录栈顶元素位置的变量组成
#ifndef DATASTRUCTUREANDALGORITHMS_LINKSTACK_H
#define DATASTRUCTUREANDALGORITHMS_STACK_H
#include <iostream>
#define MaxSize 10  //储存数据元素的最大数

using namespace std;
class linearStack{
private:
public:
    struct SNode{
        char Data[MaxSize];
        int top;
};

    static bool IsFull(SNode *S, int size);  //判断堆栈S是否已满

    static void Push(SNode *S, char item);   //将元素item压入堆栈

    static bool IsEmpty(SNode *S);  //判断堆栈S是否为空

    static char Pop(SNode *S);   //删除并返回栈顶元素
};

void testLinearStack();

#endif //DATASTRUCTUREANDALGORITHMS_LINKSTACK_H
