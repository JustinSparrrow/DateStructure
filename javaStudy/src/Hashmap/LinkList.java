package Hashmap;

//链表
public class LinkList {

    private Node head = new Node();  //定义头节点，此节点不存放数据
    int size = 0;
    //直接在末尾添加键值对
    public Node add(Object key, Object value){
        Node r = head;
        while (r.next != null) {
            r = r.next;
        }
        Node p = new Node(key, value);
        p.next = null;
        r.next = p;
        return head;
    }

    //选定位置添加键值对
    public Node loAdd(Object key, Object value, int index) {
        if (index < 0 || index > size()) {
            System.out.println("ERROR! There's no such location.");
            return null; // 不再返回值，直接返回
        }
        Node r = head.next;
        int i = 0;
        while (r.next != null && i < index - 1) {
            r = r.next;
            i++;
        }
        Node p = new Node(key, value);
        p.next = r.next;
        r.next = p;
        return head;
    }

    //删除末位节点
    public Node deleteNode(){
        if (head == null || head.next == null) {
            System.out.println("There's only one Node or no Node.");
            return null; // 处理链表为空或只有一个节点的情况
        }
        Node r = head;
        while (r.next.next!=null){
            r=r.next;
        }
        r.next=null;
        size--;
        return head;
    }

    //删除指定位置节点
    public Node loDeleteNode(int index){
        if(index<0||index>=size()){
            System.out.println("There's no such location.");
            return null;
        }
        Node r = head;
        int i = 0;
        while (r.next!=null&&i<index-1){
            r=r.next;
            i++;
        }
        Node p = r.next;
        r.next=p.next;
        size--;
        return head;
    }

    // 获取指定键对应的值
    public Node get(int index) {
        Node p = head.next;
        int i = 0;
        while (p != null && i < index) {
            p = p.next;
            i++;
        }
        return p; // 返回指定位置的节点
    }


    //返回链表长度
    public int size(){
        Node r = head.next;
        size = 0;
        while (r!=null){
            r=r.next;
            size++;
        }
        return size;
    }

    //输出链表所有内容
    public void printLinkList(){
        Node p = head.next;
        int i = 0;
        while (p!=null&&i<=size()){
            if(p.key==null&&p.value==null){
                System.out.println(i+" <null, null>");
            }
            else {
                System.out.println(i+" <"+p.key+", "+p.value+">");
            }
            p=p.next;
            i++;
        }
    }

    //输出指定位置内容
    public void printLink(int index){
        if(index<0||index>size()){
            System.out.println("no such location.");
            return;
        }
        Node p =head.next;
        int i = 0;
        while (p.next!=null&&i<index){
            p=p.next;
            i++;
        }
        System.out.println("<"+p.key+", "+p.value+">");
    }
}
