package Hashmap;

public class MHashMap {
    //保存链表数据
    private LinkList[] linkListArr;
    private int size;

    //初始化linklistArr数组长度
    public MHashMap(int size){
        this.size=size;
        linkListArr = new LinkList[size];
        //初始化链表的根节点
        for (int i = 0; i < size; i++) {
            linkListArr[i] = new LinkList();    //每个数组位置上建立一个链表对象
        }
    }
    //添加键值对
    public void put(Object key, Object value){
        //根据key 计算位置
        int index = hash(key);
        LinkList link = linkListArr[index];
        link.Insert(key,value);
    }
    //获得键值对
    public Object get(Object key) {
        int index = hash(key);
        LinkList link = linkListArr[index];
        return link.Search(key);
    }
    public void delete(Object key){
        int index = hash(key);
        LinkList link = linkListArr[index];
        link.Delete(key);
    }
    public void Iteration(){
        for(int i = 0; i < size; i++){
            LinkList link = linkListArr[i];
            link.Traversal();
            System.out.println();
        }
    }
    public int GetLength(int index){
        LinkList link = linkListArr[index];
        return link.GetLength();
    }
    //散列函数
    public int hash(Object key){
        return key.hashCode() % size;
    }

    public static void main(String[] args) {
        MHashMap mhm = new MHashMap(5);

        mhm.put("hello", 1);
        mhm.put("world", 2);
        mhm.put("and", 3);
        mhm.put("thank", 4);
        mhm.put("you", 5);
        mhm.Iteration();
        System.out.println("-------------------------------------------------------");
        mhm.delete("and");
        mhm.Iteration();
        System.out.println("-------------------------------------------------------");
        Object value = mhm.get("hello");
        System.out.println("'hello' is "+value);
        System.out.println("-------------------------------------------------------");
        System.out.println("length of index[3] is "+mhm.GetLength(2));
    }
}
