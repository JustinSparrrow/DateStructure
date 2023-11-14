package Hashmap;

public class MHashMap {
    //保存链表数据
    private LinkList[] linkListArr;
    private static int len = 16;
    private int size;

    //初始化linklistArr数组长度
    public MHashMap(){
        this(len);
    }
    public MHashMap(int size){
        this.size=size;
        linkListArr = new LinkList[size];
        //初始化链表的根节点
        for (int i = 0; i < size; i++) {
            linkListArr[i] = new LinkList();
        }
    }
    //添加键值对
    public void put(Object key, Object value){
        //根据key 计算位置
        int index = hash(key);
        LinkList link = linkListArr[index];
        link.add(key,value);
    }
    //获得键值对
    public Object get(Object key) {
        int index = hash(key);
        LinkList link = linkListArr[index];
        //遍历遍历链表
        for(int i=0;i<link.size();i++){
            Node node = link.get(i);
            //比较链表中key,如果找到返回对应的对应的value
            if(node.key.equals(key)){
                return node.value;
            }
        }
        return null;
    }
    //散列函数
    public int hash(Object key){
        return key.hashCode()%size;
    }
}
