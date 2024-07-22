#include <iostream>
#include <set>
#include <map>
using namespace std;

int main(){

    //红黑树结构，可以自动排序去重
    set<int> se;

    //哈希表
    map<int, int> mp;

    //插入
    se.insert(3);

    mp.insert({1,2});
    //mp.insert({1,2})等价于
    mp[1] = 2;

    mp[1]+=2;   //值加2

    mp[5];  //查找哈希表中是否有5，如果有则不进行操作；如果没有则开辟一个5的空间，并且将值赋值为0

    //map的遍历,此遍历无法修改哈希表的值
    for(auto j : mp){

    }

    mp.find(3); //返回指针
    mp.count(3);    //没有就是0，有就是1
    auto t = mp.find(3);
    int g = mp.count(3);

    return 0;
}