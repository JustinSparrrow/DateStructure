//
// Created by Lenovo on 2023/10/30.
//
#include "linkStack.h"

listStack::SNode *listStack::CreateStack() {
    SNode *S;
    S = new SNode();
    S->next = nullptr;
    return S;
}

bool listStack::IsEmpty(listStack::SNode *S) {
    return (S->next == nullptr);
}

void listStack::Push(char item, listStack::SNode *S) {
    SNode* TmpCell;
    TmpCell = new SNode();
    TmpCell->Data = item;
    TmpCell->next = S->next;
    S->next = TmpCell;
}

char listStack::Pop(listStack::SNode *S) {
    SNode* FirstCell;
    char TopElem;
    if(IsEmpty(S)){
        cout << "kong" << endl;
        return '\0';
    } else {
        FirstCell = S->next;
        S->next = FirstCell->next;
        TopElem = FirstCell->Data;
        free(FirstCell);
        return TopElem;
    }
}

void listStack::ClearStack(listStack::SNode *S) {
    SNode* curr = S->next;
    while (curr!= nullptr){
        free(S);
        S = curr;
        curr = curr->next;
    }
    free(S);
}

void listStack::LindEdit() {
    SNode *S = CreateStack();
    char ch = getchar();
    while (ch != EOF){
        //EOF为全文结束符
        while (ch != EOF && ch != '\n'){
            switch (ch) {
                case '#':
                    Pop((S));
                    break;
                case '@':
                    ClearStack(S);
                    break;
                default:
                    Push(ch, S);
            }
            ch = getchar();
        }
        ClearStack(S);
        if(ch != EOF)   ch = getchar();
    }
}