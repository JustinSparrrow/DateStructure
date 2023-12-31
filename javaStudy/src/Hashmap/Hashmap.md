# 哈希表

---
## 目录
### 1. [哈希表的简单介绍](#1-哈希表的简单介绍-)
### 2. [哈希表的构建思路](#2-哈希表的构建思路-)
### 3. [哈希表的构建过程](#3-哈希表的构建过程)
### 4. [散列函数](#4-散列函数)
### 5. [总结](#5-总结)

---

## 1. 哈希表的简单介绍  
哈希表是一种数据结构，它通过将键映射到表中的位置来实现高效的数据查找、插入和删除操作。哈希表通常由一个数组构成，每个数组元组又称哈希桶，用来存储数据。一般情况下哈希表的数组中通常存放着链表、树或其他数据结构的引用，具体取决于哈希表的实现方式和冲突解决策略。  

```markdown
Index 0: -> (key1, value1) -> (key4, value4) -> ...
Index 1: -> (key2, value2) -> ...
Index 2: -> (key3, value3) -> ...
```

当链表长度太长时，可以将一些链表改成树来增加性能。  

当哈希表存储一个键值对时，首先会计算键的哈希码，然后通过某种方法将哈希码映射到数组中的一个位置，这个过程称为哈希函数。如果不同的键映射到了同一个位置，就会发生哈希冲突，通常会使用链表、红黑树等数据结构来解决这个问题。  

哈希表的原理在于通过哈希函数将键映射到数组中的位置，这样可以在常数时间内（平均情况下）进行查找、插入和删除操作。  

**举一个简单的例子，假设哈希表的长度为20，输入"example"，根据简单的哈希函数（将字符串的每个字符的ASCII码值相加，然后对数组长度取模），对于example来说，哈希码：ASCII('e')+ASCII('x')+...+ASCII('e') = 101+120+97+...+101=748，对哈希码取模，748%20=8，所以会存储进index[8]；如果有其他字符串也存储进index[8]中，则通过链表来解决哈希冲突。**  

---
## 2. 哈希表的构建思路  
### a.大致规划  
根据上面的原理，哈希表需要两种数据结构，分别是数组和链表。此处的数组是否为动态数组取决于存储的键值对的数量，如果数量较多，定长数组需要一个个遍历链表节点，性能不会太好，需要动态数组实现一个索引对应一个键值对。这种情况下哈希表的大小只取决于内存大小；而是用定长数组时直接使用哈希函数确定索引值，通过一个数组储存多个链表节点来简化代码操作。所以此处使用定长数组和链表。  

### b.链表(linkList)
先来解决存储键值对的部分即链表，链表的一般操作如下：
```java
class Node{
    public Object key;
    public Object value;
    public Node(){}
    public Node(Object key, Object value){this.key = key; this.value = value;}
}
class linkList{
    private Node head = new Node();                 //头节点，每个索引都有一个独立的头节点
    public void Insert(Object key, Object value);   //在链表尾部插入节点
    public void Delete();                           //删除末尾节点
    public void Delete(Object key);                 //删除指定位置节点
    public Object Search(Object key);               //在链表中查找节点
    public void Traversal();                        //遍历链表访问链表
    public int GetLength();                         //获取链表长度
}
```

### c.数组(Array)  
这里使用定长数组构建哈希表。
```java
class Hashmap{
    private LinkList[] linkListArr;             //哈希表的数组
    private int size = 100;                     //哈希表长度
    public void put(Object key, Object value);  //增加键值对
    public Object get(Object key);              //获取键值对
    public void delete(Object key);             //删除键值对
    public void Iteration();                    //遍历哈希表中的所有键值对，执行特定的那个操作
    public int hash(Object key);                //散列函数
}
```

### d.main函数
随便写几个测试函数就可以了。  

---
## 3. 哈希表的构建过程
把2中提到的类成员函数补齐即可，具体代码见对应的java文件。  

此处主要解释数组中的函数方法：
- 需要定义的类成员对象：
```java
private LinkList[] linkListArr;     //创建数组对象
private int size;                   //数组长度（人为规定）
```
- 构造函数初始化哈希表：
```java
public MHashMap(int size){
    this.size=size;                         //固定数组长度
    linkListArr = new LinkList[size];       //给数组对象分配内存
    for (int i = 0; i < size; i++) {
        linkListArr[i] = new LinkList();    //每个数组位置上建立一个链表对象用来初始化链表的根节点
    }
}
```
- 散列函数：
```java
public int hash(Object key){
    return key.hashCode() % size;       //此处的哈希码就是每个字符的ASCII码值相加然后对数组长度取模
}
```
- 增加键值对：
```java
public void put(Object key, Object value){
    int index = hash(key);                      //哈希映射到数组的位置
    LinkList link = linkListArr[index];         //在数组处创立一个新的link对象
    link.Insert(key,value);                     //调用插入链表节点函数
}
```
其他函数与增加键值对类似，均是通过哈希映射找到相应位置然后创建链表对象调用链表节点中相应的方法即可。

---
## 4. 散列函数
### 哈希码  
哈希码（Hash Code）是根据一定算法将任意长度的输入数据转换为固定长度的输出数据的结果。这个输出通常是一个整数。哈希码的目的是为了快速检索数据，常用于数据结构中，比如哈希表。  

在Java中，Object 类中有一个 hashCode() 方法，它返回对象的哈希码。默认情况下，hashCode() 方法返回的是对象的内存地址经过一定算法得到的哈希值。然而，hashCode() 方法可以被子类重写，以提供更具有意义的哈希码。  

重写 hashCode() 方法的目的是为了使得相等的对象具有相等的哈希码。在Java中，如果两个对象通过 equals() 方法判断为相等，那么它们的 hashCode() 方法应该返回相同的值。这是因为在使用哈希表等数据结构时，相等的对象应该被分配到同一个哈希桶中，以确保数据结构的正确性和高效性。  

### 散列函数
- 散列函数是一个特殊的函数，它接受输入（或"键"）并产生一个固定大小的输出，通常是一个哈希码或散列值。
- 散列函数的目标是将输入数据映射到一个较小的固定范围内，通常是一个整数。这个过程称为"散列"。
- 散列函数的输出通常称为哈希码，散列值或散列码。
- 散列函数在数据结构中广泛使用，例如哈希表，它们用于快速检索数据。

Java 中的散列函数主要用于哈希表和一些基于哈希的集合数据结构，例如 HashMap、HashSet 等。这些数据结构依赖于散列函数来确定对象的存储位置。

Java 中的散列函数通常涉及以下几个重要的方法和概念：

- **hashCode() 方法**
Object 类是 Java 中所有类的超类，在 Object 类中有一个 hashCode() 方法。默认情况下，该方法返回对象的内存地址的哈希码，但是它可以被子类重写以提供更合适的哈希码实现。

- **HashMap 中的散列函数**
HashMap 是 Java 中常用的哈希表实现，它使用键的 hashCode() 方法来确定存储桶的位置。在存储元素时，HashMap 会将键的哈希码进行进一步处理，比如使用取模运算（对数组大小取余）来确定键值对应存储的位置。

- **HashSet 中的散列函数**
HashSet 是基于 HashMap 实现的，它利用了 HashMap 的键存储特性，只是在 HashSet 中只存储了键而没有值。HashSet 使用了 HashMap 中键的哈希码和存储机制来存储元素，并保证元素的唯一性。

- **重写 hashCode() 和 equals() 方法**
为了正确使用哈希集合和哈希映射，Java 类中重写 hashCode() 和 equals() 方法非常重要。hashCode() 方法用于确定对象在哈希表中的位置，而 equals() 方法用于比较两个对象是否相等。根据哈希表的工作原理，如果两个对象相等（即 equals() 返回 true），它们的哈希码也必须相等（hashCode() 返回的值相等）。

在实现自定义类时，应确保重写了 hashCode() 和 equals() 方法，以便正确地在哈希集合或哈希映射中使用。

总体而言，Java 中的散列函数在哈希表和相关数据结构的实现中发挥着关键作用，通过合适的散列函数可以提高数据结构的性能和效率。

---
## 5. 总结
