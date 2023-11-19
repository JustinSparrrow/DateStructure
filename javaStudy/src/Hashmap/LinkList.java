package Hashmap;

//链表
public class LinkList {

    private Node head = new Node();  //定义头节点，此节点不存放数据

    public int len = 0;

    public void Insert(Object key, Object value){
        Node curr = head;
        while (curr.next != null){
            curr = curr.next;
            if(curr.key == key){
                curr.value = value;
                return;
            }
        }
        Node p = new Node(key, value);
        curr.next = p;
        len++;
    }

    public void Delete(){
        if(len > 0) {
            Node curr = head;
            while (curr.next.next != null) {
                curr = curr.next;
            }
            curr.next = null;
            len--;
        }
        else {
            System.out.println("Hashmap is empty.");
        }
    }

    public void Delete(Object key){
        Node curr = head;
        while (curr.next != null && curr.next.key != key){
            curr = curr.next;
        }
        if(curr.next == null && curr.key != key){
            System.out.println("no such key");
        }
        if(curr.next != null && curr.next.key == key){
            curr.next = curr.next.next;
            len--;
        }
    }

    public Object Search(Object key){
        Node curr = head;
        while (curr != null && curr.key != key){
            curr = curr.next;
        }
        if(curr == null){
            System.out.println("no such key");
            return null;
        } else {
            System.out.println("value:"+curr.value);
            return curr.value;
        }
    }

    public void Traversal(){
        Node curr = head.next;
        if(curr == null){
            System.out.print("Hashmap is empty.");
        }
        while (curr != null){
            System.out.print("<key:"+ curr.key+" value:"+curr.value+"> ");
            curr = curr.next;
        }
    }

    public int GetLength(){
        return len;
    }

    public class Node {
        public Object key;
        public Object value;
        public Node next;
        public Node(Object key, Object value){
            this.key = key;
            this.value = value;
        }
        public Node(){

        }
    }
}
