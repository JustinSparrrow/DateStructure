//
// Created by moqi on 2023/10/30.
//
#include "linearStack.h"

void testLinearStack() {
    linearStack::SNode myStack{};
    myStack.top = -1; // 初始化栈顶指针为-1，表示栈为空

    linearStack::Push(&myStack, 'A');
    linearStack::Push(&myStack, 'B');
    linearStack::Push(&myStack, 'C');

    while (!linearStack::IsEmpty(&myStack)) {
        cout << linearStack::Pop(&myStack) << " ";
    }
}