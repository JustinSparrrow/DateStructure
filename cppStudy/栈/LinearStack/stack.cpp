//
// Created by moqi on 2023/10/29.
//
#include "linearStack.h"

bool linearStack::IsFull(linearStack::SNode *S, int size) {
    if(S->top == MaxSize-1) {
//        cout << "堆栈已满" << endl;
        return true;
    }
    return false;
}

void linearStack::Push(linearStack::SNode *S, char item) {
    if(!IsFull(S, MaxSize)){
        S->Data[++(S->top)] = item;
        return;
    }
}

bool linearStack::IsEmpty(linearStack::SNode *S) {
    if(S->top == -1) {
//        cout << "堆栈已空" << endl;
        return true;
    }
    return false;
}

char linearStack::Pop(linearStack::SNode *S) {
    if(!IsEmpty(S)) {
        return (S->Data[(S->top)--]);
    }
}
