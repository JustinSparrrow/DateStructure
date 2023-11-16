//
// Created by Lenovo on 2023/11/6.
//

#ifndef DATASTRUCTUREANDALGORITHMS_BINARYTREE_H
#define DATASTRUCTUREANDALGORITHMS_BINARYTREE_H
#include <bits/stdc++.h>
using namespace std;
class binaryTree{
public:
    struct Tree{
        char val;
        Tree* right;
        Tree* left;
    };

    static Tree* InitBiTree(Tree* T);  //构造空二叉树T

    static void DestroyBiTree(Tree* T);    //销毁二叉树

    static Tree* ClearBiTree(Tree* T); //清空二叉树

    static bool BiTreeEmpty(Tree* T);  //判断是否为空

    static int BiTreeDepth(Tree* T);   //返回T的深度

    static char Root(Tree* T); //返回T的根

    static char Value(Tree* T, Tree* e);    //返回e的值

    static void Assign(Tree* T, Tree *e, char value);  //更改e的值

    static Tree* Parent(Tree* T, Tree* e);  //若e是T的非根节点，则返回它的双亲，否则返回空

    static Tree* LeftChild(Tree* T, Tree* e);  //返回e的左孩子。若无左孩子返回空

    static Tree* RightChild(Tree* T, Tree* e); //返回e的右孩子。若无右孩子返回空

    static Tree* LeftSibling(Tree* T, Tree* e);    //返回e的左兄弟。若e是T的左孩子或无左兄弟，则返回空

    static Tree* RightSibling(Tree* T, Tree* e);   //返回e的右兄弟。若e是T的右孩子或无右兄弟，则返回空

    static void InsertChild(Tree* T, Tree* p, bool LR, char c);   //在p处插入子节点，LR为0插入左节点，为1插入右节点，c为值

    static void DeleteChild(Tree* T, Tree* p, bool LR);    //删除p处子节点，规则同上

    static void PreOrderTraverse(Tree* T); //前序遍历

    static void InOrderTraverse(Tree* T);  //中序遍历

    static void PostOrderTraverse(Tree* T);    //后序遍历

    static void LevelOrderTraverse(Tree* T);   //层序遍历（广度优先搜索，用队列）

    static int TreeOpener(Tree* T); //返回叶子节点总数

    /*
     * 当遍历二叉树时，有四种常见的遍历方法：前序遍历、中序遍历、后序遍历和层序遍历。下面我将逐一介绍这四种遍历方法的特点和实现方式：
        1. 前序遍历（Preorder Traversal）：
           - 特点：首先访问根节点，然后按照先左后右的顺序递归遍历左子树和右子树。
           - 实现方式：可以使用递归或栈来实现前序遍历。

        2. 中序遍历（Inorder Traversal）：
           - 特点：按照先左后根再右的顺序递归遍历左子树、访问根节点，最后递归遍历右子树。
           - 实现方式：可以使用递归或栈来实现中序遍历。

        3. 后序遍历（Postorder Traversal）：
           - 特点：按照先左后右再根的顺序递归遍历左子树和右子树，最后访问根节点。
           - 实现方式：可以使用递归或栈来实现后序遍历。

        4. 层序遍历（Level Order Traversal）：
           - 特点：按照从上到下、从左到右的顺序逐层遍历二叉树的节点。
           - 实现方式：可以使用队列来实现层序遍历。

        这四种遍历方法在不同的场景下有不同的应用。前序遍历常用于复制二叉树、计算二叉树的深度等操作；中序遍历常用于二叉搜索树的中序遍历，可以得到有序的节点序列；后序遍历常用于计算二叉树的深度、删除二叉树等操作；层序遍历常用于查找特定节点、构建二叉树的镜像等操作。
        无论使用哪种遍历方法，都可以通过递归或迭代的方式来实现。具体选择哪种方式取决于实际需求和个人偏好。
     */
};

void testBinaryTree();

#endif //DATASTRUCTUREANDALGORITHMS_BINARYTREE_H
