//
// Created by Lenovo on 2023/11/6.
//
#include "BinaryTree.h"

binaryTree::Tree *binaryTree::InitBiTree(binaryTree::Tree *T) {
    T = new Tree();
    T->val = 0;
    T->left = nullptr;
    T->right = nullptr;
    return T;
}

void binaryTree::DestroyBiTree(binaryTree::Tree *T) {
    if(T == nullptr)
        return;
    //使用递归的方法来遍历节点并且释放空间
    DestroyBiTree(T->left);
    DestroyBiTree(T->right);

    delete T;
}

binaryTree::Tree *binaryTree::ClearBiTree(binaryTree::Tree *T) {
    DestroyBiTree(T);
    InitBiTree(T);
    return T;
}

bool binaryTree::BiTreeEmpty(binaryTree::Tree *T) {
    return (T == nullptr);
}

int binaryTree::BiTreeDepth(binaryTree::Tree *T) {
    if(T == nullptr)
        return 0;

    int leftDepth = BiTreeDepth(T->left);
    int rightDepth = BiTreeDepth(T->right);

    return max(leftDepth, rightDepth)+1;
}

char binaryTree::Root(binaryTree::Tree *T) {
    return T->val;
}

char binaryTree::Value(binaryTree::Tree *T, binaryTree::Tree *e) {
    if(BiTreeEmpty(T)) return '\0';
    if(T == e){
        return T->val;
    }
    Value(T->left, e);
    Value(T->right, e);
}

void binaryTree::Assign(binaryTree::Tree *T, binaryTree::Tree *e, char value) {
    if(BiTreeEmpty(T)) return;
    if(T == e){
        T->val = value;
    }
    Assign(T->left, e, value);
    Assign(T->right, e, value);
}

binaryTree::Tree *binaryTree::Parent(binaryTree::Tree *T, binaryTree::Tree *e) {
    if(BiTreeEmpty(T)) return nullptr;
    if(T->right == e || T->left == e){
        return T;
    }
    Parent(T->left, e);
    Parent(T->right, e);
}

binaryTree::Tree *binaryTree::LeftChild(binaryTree::Tree *T, binaryTree::Tree *e) {
    if(BiTreeEmpty(T)) return nullptr;
    if(T == e){
        return T->left;
    }
    LeftChild(T->left, e);
    LeftChild(T->right, e);
}

binaryTree::Tree *binaryTree::RightChild(binaryTree::Tree *T, binaryTree::Tree *e) {
    if(BiTreeEmpty(T)) return nullptr;
    if(T == e){
        return T->right;
    }
    RightChild(T->right, e);
    RightChild(T->left, e);
}

binaryTree::Tree *binaryTree::LeftSibling(binaryTree::Tree *T, binaryTree::Tree *e) {
    if(BiTreeEmpty(T)) return nullptr;
    if(T->right == e){
        return T->left;
    }
    LeftSibling(T->left, e);
    LeftSibling(T->right, e);
}

binaryTree::Tree *binaryTree::RightSibling(binaryTree::Tree *T, binaryTree::Tree *e) {
    if(BiTreeEmpty(T)) return nullptr;
    if(T->left == e){
        return T->right;
    }
    RightSibling(T->right, e);
    RightSibling(T->left, e);
}

void binaryTree::InsertChild(binaryTree::Tree *T, binaryTree::Tree *p, bool LR, char c) {
    Tree* newNode = new Tree();
    newNode->val = c;
    newNode->left = nullptr;
    newNode->right = nullptr;
    if(LR == 0){
        newNode->left = p->left;
        p->left = newNode;
    } else {
        newNode->right = p->right;
        p->right = newNode;
    }
}

void binaryTree::DeleteChild(binaryTree::Tree *T, binaryTree::Tree *p, bool LR) {
    if (T == nullptr) {
        printf("Error: Tree is NULL\n");
        return;
    }

    if (LR == 0) {
        if (p->left == nullptr) {
            printf("Error: Left child does not exist\n");
            return;
        }
        free(p->left);
        p->left = nullptr;
    } else {
        if (p->right == nullptr) {
            printf("Error: Right child does not exist\n");
            return;
        }
        free(p->right);
        p->right = nullptr;
    }
}

void binaryTree::PreOrderTraverse(binaryTree::Tree *T) {
    if(T == nullptr) return;

    cout << T->val << " ";
    PreOrderTraverse(T->left);
    PreOrderTraverse(T->right);
}

void binaryTree::InOrderTraverse(binaryTree::Tree *T) {
    if(T == nullptr) return;

    InOrderTraverse(T->left);
    cout << T->val << " ";
    InOrderTraverse(T->right);
}

void binaryTree::PostOrderTraverse(binaryTree::Tree *T) {
    if(T == nullptr) return;

    PostOrderTraverse(T->left);
    PostOrderTraverse(T->right);
    cout << T->val << " ";
}

void binaryTree::LevelOrderTraverse(binaryTree::Tree *T) {
    if(T == nullptr) return;

    queue<Tree*> q;
    q.push(T);

    while (!q.empty()){
        Tree* node = q.front();
        q.pop();

        cout << node->val << " ";

        if(node->left != nullptr){
            q.push(node->left);
        }

        if(node->right != nullptr){
            q.push(node->right);
        }
    }
}
