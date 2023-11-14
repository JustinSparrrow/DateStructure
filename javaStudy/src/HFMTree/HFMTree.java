package HFMTree;

import java.util.ArrayList;
import java.util.List;

//根据给定的字符串内容统计每个字符出现的频率

class TreeNode{
    public String code = ""; //统计节点的编码
    public int data;
    public int depth;
    public TreeNode left;
    public TreeNode right;

    public TreeNode(){

    }
    public TreeNode(int data){
        this.data = data;
    }
}

public class HFMTree {
    public List<TreeNode> listNode = new ArrayList<>();

    //对ListNode进行排序（快排）
    private void swap(int i, int j){
        TreeNode temp = listNode.get(i);
        listNode.set(i,listNode.get(j));
        listNode.set(j,temp);
    }

    private int partition(int low, int high){
        int pivot = listNode.get(high).data;
        int i = low - 1;
        for(int j = low; j < high; j++){
            if(listNode.get(j).data<pivot){
                i++;
                swap(i,j);
            }
        }
        swap(i+1,high);
        return i+1;
    }

    private void quickSort(int low, int high){
        if(low < high){
            int pivotIndex = partition(low, high);
            quickSort(low, pivotIndex-1);
            quickSort(pivotIndex+1, high);
        }
    }

    public void quickSort(){
        if(listNode.size() > 1){
            quickSort(0,listNode.size()-1);
        }
    }

    public TreeNode createTree(List<TreeNode> listNode){
        quickSort();
        while (listNode.size() > 1) {
            //从ListNode中找出最小的两个节点
            TreeNode leftNode = listNode.remove(0);
            TreeNode rightNode = listNode.remove(0);

            //根据最小的两个节点创建父节点
            TreeNode node = new TreeNode(leftNode.data + rightNode.data);
            node.left = leftNode;
            node.right = rightNode;

            //把子树添加到list中，重新排序
            listNode.add(node);
            quickSort();
        }
        //返回哈夫曼树的根节点
        return listNode.remove(0);
    }
    //哈夫曼，统计叶子节点的哈夫曼编码
    public void setCode(TreeNode root){
        if(root.left != null) {
            root.left.code = root.code + "0";
            setCode(root.left);
        }

        if(root.right != null) {
            root.right.code = root.code + "1";
            setCode(root.right);
        }
    }
    //打印叶子节点
    public void inorder(TreeNode root, int depth){
        if (root != null) {
            // 判断是否是叶子节点
            if (root.left == null && root.right == null) {
                System.out.println("Depth " + depth + ": " + root.data + ":" + root.code);
            }
            // 递归遍历左子树和右子树，同时将深度加一
            inorder(root.left, depth + 1);
            inorder(root.right, depth + 1);
        }
    }

    public static void main(String[] args) {
        int[] arr = {3, 1, 2, 4, 5, 6};
        List<TreeNode> listNode = new ArrayList<>();
        for(int i = 0; i < arr.length; i++){
            listNode.add(new TreeNode(arr[i]));
        }
        HFMTree hfm = new HFMTree();
        TreeNode root = hfm.createTree(listNode);

        hfm.setCode(root);

        hfm.inorder(root, 0);
    }
}