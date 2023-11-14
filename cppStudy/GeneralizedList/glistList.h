//
// Created by moqi on 2023/11/6.
//

#ifndef DATASTRUCTUREANDALGORITHMS_GLISTLIST_H
#define DATASTRUCTUREANDALGORITHMS_GLISTLIST_H
#include <bits/stdc++.h>
using namespace std;
class GListNode{
public:
    bool isAtom;    //标记节点是否为原子元素
    union{
        int atom;   //原子元素的值
        GListNode* sublist; //子表的指针
    };

    //赋值
    GListNode(int value);

    //指向子表的指针
    GListNode(GListNode* sublist);


};
#endif //DATASTRUCTUREANDALGORITHMS_GLISTLIST_H
