//
// Created by 尛柒 on 2024/1/11.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int level;  // 树的阶数
    int keyNum; // 关键字数量
    int childNum;   // 孩子数量
    int* keys;  // 关键组数组
    struct Node** children; // 孩子数组
    struct Node* parent;    // 父亲指针
}Node;

// 初始化节点
Node* initNode(int level){
    Node* node = (Node*) malloc(sizeof (Node));
    node->level = level;
    node->keyNum = 0;
    node->childNum = 0;
    node->keys = (int*) malloc(sizeof (int)* level);
    node->parent = NULL;
    node->children = (Node**) malloc(sizeof (Node*)* (level+1));
    int i;
    for(i = 0; i < level; i++){
        node->keys[i] = 0;
        node->children[i] = NULL;
    }
    node->keys[i] = 0;
    return node;
}

// 在节点处寻找合适的插入索引
int findSuiteIndex(Node* node, int data){
    int index;
    for(index = 1; index <= node->keyNum; index++){
        if(data < node->keys[index]){
            break;
        }
    }
    return index;
}

// 找到合适的叶子节点
Node* findSuiteLeafNode(Node* T, int data){
    if(T->childNum == 0){
        return T;
    } else {
        int index = findSuiteIndex(T, data);
        return findSuiteLeafNode(T->children[index-1], data);
    }
}

void addData(Node* node, int data, Node** T){
    int index = findSuiteIndex(node, data);
    for(int i = node->keyNum; i >= index; i--){
        node->keys[i+1] = node->keys[i];
    }
    node->keys[index] = data;
    node->keyNum++;
    // 判断是否进行分裂
    if(node->keyNum == node->level){
        // 找到分裂的位置
        int mid = node->level / 2 + node->level % 2;
        // 分裂
        Node* lchild = initNode(node->level);
        Node* rchild = initNode(node->level);
        for(int i = 1; i < mid; i++){
            addData(lchild, node->keys[i], T);
        }
        for(int i = mid+1; i <= node->keyNum; i++){
            addData(rchild, node->keys[i], T);
        }
        for(int i = 0; i < mid; i++){
            lchild->children[i] = node->children[i];
            if(node->children[i] != NULL){
                node->children[i]->parent = lchild;
                lchild->childNum++;
            }
        }
        index = 0;
        for(int i = mid; i < node->childNum; i++){
            rchild->children[index++] = node->children[i];
            if(node->children[i] != NULL){
                node->children[i]->parent = rchild;
                rchild->childNum++;
            }
        }
        // 对父节点进行操作
        if(node->parent == NULL){
            Node* newParent = initNode(node->level);
            addData(newParent, node->keys[mid], T);
            newParent->children[0] = lchild;
            newParent->children[1] = rchild;
            newParent->childNum = 2;
            lchild->parent = newParent;
            rchild->parent = newParent;
            *T = newParent;
        } else {
            index = findSuiteIndex(node->parent, node->keys[mid]);
            lchild->parent = node->parent;
            rchild->parent = node->parent;
            node->parent->children[index-1] = lchild;
            if(node->parent->children[index] != NULL){
                for(int i = node->parent->childNum-1; i >= index; i--){
                    node->parent->children[i+1] = node->parent->children[i];
                }
            }
            node->parent->children[index] = rchild;
            node->parent->childNum++;
            addData(node->parent, node->keys[mid], T);
        }
    }
}

void insert(Node** T, int data){
    Node* node = findSuiteLeafNode(*T, data);
    addData(node, data, T);
}

void printTree(Node* T){
    if(T != NULL){
        for(int i = 1; i <= T->keyNum; i++){
            printf("%d ", T->keys[i]);
        }
        printf("\n");
        for(int i = 0; i < T->childNum; i++){
            printTree(T->children[i]);
        }
    }
}

int main(){
    Node* T = initNode(5);
    insert(&T, 1);
    insert(&T, 2);
    insert(&T, 3);
    insert(&T, 4);
    insert(&T, 5);
    insert(&T, 6);
    insert(&T, 7);
    insert(&T, 8);
    insert(&T, 9);
    insert(&T, 10);
    insert(&T, 11);
    insert(&T, 12);
    insert(&T, 13);
    insert(&T, 14);
    insert(&T, 15);
    printTree(T);
    return 0;
}