package Binary_Tree;

import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

//排序树
//练习:1.创建排序树
//    2.用非递归方式实现树的三序遍历
//    3.二叉树层的遍历(改成Z字形遍历)
public class Tree {
    public TreeNode root;  //树的跟节点

    //左小 右大
    public void addNode(TreeNode node){
        if(root == null){
            root = node;
        } else {
            //保存当前节点
            TreeNode curr = root;
            while (true) {
                if (curr.data > node.data) {
                    if (curr.left == null) {
                        curr.left = node;
                        break;
                    }
                    curr = curr.left;
                }
                if (curr.data <= node.data) {
                    if (curr.right == null) {
                        curr.right = node;
                        break;
                    }
                    curr = curr.right;
                }
            }
        }
    }

    //遍历二叉树：前序、中序、后序、层序
    //前序：根->左->右
    public void preOrder(TreeNode root){
        if(root != null){
            System.out.println(root.data+" ");
            preOrder(root.left);
            preOrder(root.right);
        }
    }
    //中序：左->根->右
    public void inOrder(TreeNode root){
        if(root != null){
            inOrder(root.left);
            System.out.println(root.data+" ");
            inOrder(root.right);
        }
    }
    //后序：左->右->根
    public void postOrder(TreeNode root){
        if(root != null){
            postOrder(root.left);
            postOrder(root.right);
            System.out.println(root.data);
        }
    }
    //层序遍历
    public  List<List<Integer>> levelOrder(TreeNode root){
        List<List<Integer>> list = new LinkedList<>();
        if(root == null){
            return null;
        }
        TreeNode curr = root;
        //队列：先进先出
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(curr);
        while(queue.size() > 0){
            //创建List，保存每一层的节点
            List<Integer> level = new LinkedList<>();
            int size = queue.size();
            for(int i=0;i<size;i++){
                TreeNode node = queue.poll();
                level.add(node.data);
                if(node.left != null){
                    queue.offer(node.left);
                }
                if(node.right != null){
                    queue.offer(node.right);
                }
            }
            //把每一层的数据添加到List中
            list.add(level);
        }
        return list;
    }

    public static void main(String[] args) {
        int[] arr = {7,5,9,6,3,8,10,4};

        Tree tree = new Tree();

        for(int i=0;i<arr.length;i++){
            TreeNode node = new TreeNode(arr[i]);
            tree.addNode(node);
        }
        List<List<Integer>> list = tree.levelOrder(tree.root);
        for(int i=0;i<list.size();i++){
            List<Integer> li = list.get(i);
            for(int j=0;j<li.size();j++){
                System.out.print(li.get(j)+" ");
            }
            System.out.println();
        }

//        tree.inorder(tree.root);
    }
}
