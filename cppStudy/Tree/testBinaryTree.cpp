#include "BinaryTree.h"

void testBinaryTree(){
    binaryTree::Tree* T = nullptr;

    // 初始化二叉树
    T = binaryTree::InitBiTree(T);

    // 插入子节点
    binaryTree::InsertChild(T, T, 0, 'B');
    binaryTree::InsertChild(T, T, 1, 'C');
    binaryTree::InsertChild(T, T->left, 0, 'D');
    binaryTree::InsertChild(T, T->left, 1, 'E');
    binaryTree::InsertChild(T, T->right, 0, 'F');
    binaryTree::InsertChild(T, T->right, 1, 'G');

    // 打印二叉树的前序遍历结果
    cout << "Preorder traversal: ";
    binaryTree::PreOrderTraverse(T);
    cout << endl;

    // 打印二叉树的中序遍历结果
    cout << "Inorder traversal: ";
    binaryTree::InOrderTraverse(T);
    cout << endl;

    // 打印二叉树的后序遍历结果
    cout << "Postorder traversal: ";
    binaryTree::PostOrderTraverse(T);
    cout << endl;

    // 打印二叉树的层序遍历结果
    cout << "Levelorder traversal: ";
    binaryTree::LevelOrderTraverse(T);
    cout << endl;

    // 判断二叉树是否为空
    if (binaryTree::BiTreeEmpty(T)) {
        cout << "Binary tree is empty" << endl;
    } else {
        cout << "Binary tree is not empty" << endl;
    }

    // 获取二叉树的深度
    int depth = binaryTree::BiTreeDepth(T);
    cout << "Binary tree depth: " << depth << endl;

    // 获取二叉树的根节点
    char root = binaryTree::Root(T);
    cout << "Root of binary tree: " << root << endl;

    // 获取指定节点的值
    binaryTree::Tree* node = T->left;
    char value = binaryTree::Value(T, node);
    cout << "Value of node " << node->val << ": " << value << endl;

    // 更改指定节点的值
    binaryTree::Assign(T, node, 'X');
    value = binaryTree::Value(T, node);
    cout << "New value of node " << node->val << ": " << value << endl;

    // 获取指定节点的双亲节点
    binaryTree::Tree* parent = binaryTree::Parent(T, node);
    if (parent != nullptr) {
        cout << "Parent of node " << node->val << ": " << parent->val << endl;
    } else {
        cout << "Node " << node->val << " is root" << endl;
    }

    // 获取指定节点的左孩子节点
    binaryTree::Tree* leftChild = binaryTree::LeftChild(T, node);
    if (leftChild != nullptr) {
        cout << "Left child of node " << node->val << ": " << leftChild->val << endl;
    } else {
        cout << "Node " << node->val << " has no left child" << endl;
    }

    // 获取指定节点的右孩子节点
    binaryTree::Tree* rightChild = binaryTree::RightChild(T, node);
    if (rightChild != nullptr) {
        cout << "Right child of node " << node->val << ": " << rightChild->val << endl;
    } else {
        cout << "Node " << node->val << " has no right child" << endl;
    }

    // 获取指定节点的左兄弟节点
    binaryTree::Tree* leftSibling = binaryTree::LeftSibling(T, node);
    if (leftSibling != nullptr) {
        cout << "Left sibling of node " << node->val << ": " << leftSibling->val << endl;
    } else {
        cout << "Node " << node->val << " has no left sibling" << endl;
    }

    // 获取指定节点的右兄弟节点
    binaryTree::Tree* rightSibling = binaryTree::RightSibling(T, node);
    if (rightSibling != nullptr) {
        cout << "Right sibling of node " << node->val << ": " << rightSibling->val << endl;
    } else {
        cout << "Node " << node->val << " has no right sibling" << endl;
    }

    // 删除子节点
    binaryTree::DeleteChild(T, T->left, 0);
    binaryTree::DeleteChild(T, T->right, 1);

    // 清空二叉树
    T = binaryTree::ClearBiTree(T);

    // 判断二叉树是否为空
    if (binaryTree::BiTreeEmpty(T)) {
        cout << "Binary tree is empty" << endl;
    } else {
        cout << "Binary tree is not empty" << endl;
    }
}