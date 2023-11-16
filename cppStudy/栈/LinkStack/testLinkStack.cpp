//
// Created by moqi on 2023/10/30.
//
#include "linkStack.h"

void testListStack() {
    listStack::SNode* myStack = listStack::CreateStack();

    listStack::Push('A', myStack);
    listStack::Push('B', myStack);
    listStack::Push('C', myStack);
//    cout << listStack::IsEmpty(myStack) << endl;

    while (!listStack::IsEmpty(myStack)) {
        char item = listStack::Pop(myStack);
        std::cout << "Popped item: " << item << std::endl;
    }

    listStack::ClearStack(myStack);
    delete myStack;
}