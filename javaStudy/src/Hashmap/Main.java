package Hashmap;

public class Main {

    public static void main(String[] args) {

        LinkList linkList = new LinkList();

        // Add some nodes to the link list
        linkList.add("Key1", "Value1");
        linkList.add("Key2", "Value2");
        linkList.add("Key3", "Value3");

        // Print the entire link list
        System.out.println("Printing the entire link list:");
        linkList.printLinkList();

        // Add a node at a specific index
        linkList.loAdd("Key4", "Value4", 1);

        // Print the updated link list
        System.out.println("\nPrinting the updated link list after adding a node at index 1:");
        linkList.printLinkList();

        // Delete a node at a specific index
        linkList.loDeleteNode(2);

        // Print the updated link list
        System.out.println("\nPrinting the updated link list after deleting a node at index 2:");
        linkList.printLinkList();

        // Get a node at a specific index
        int indexToGet = 2;
        Node getNode = linkList.get(indexToGet);
        if (getNode != null) {
            System.out.println("\nGetting node at index " + indexToGet + ": <" + getNode.key + ", " + getNode.value + ">");
        }

        // Print the size of the link list
        System.out.println("\nSize of the link list: " + linkList.size());

        // 创建一个新的哈希表
        MHashMap hashMap = new MHashMap();

        // 添加键值对
        hashMap.put('a', 1);
        hashMap.put('b', 2);
        hashMap.put('c', 3);

        // 获取键值对
        System.out.println("Value for 'a': " + hashMap.get('a'));
        System.out.println("Value for 'b': " + hashMap.get('b'));
        System.out.println("Value for 'x': " + hashMap.get('x')); // 不存在的键，应该返回 null

        // 删除键值对
        // hashMap.remove('b');
        // System.out.println("Value for 'b' after removal: " + hashMap.get('b')); // 已删除的键，应该返回 null
    }
}
