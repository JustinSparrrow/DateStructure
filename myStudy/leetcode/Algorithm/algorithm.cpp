#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <bits/stdc++.h>
using namespace std;

//STL常用内容
void solve(){
    vector<int> vec;    //容器，对应数字型数组
    string a;   //容器，对应字符串数组
    pair<int, int> pii; //数对结构，一对数
    stack<int> sta; //栈，先进后出
    queue<int> q;   //队列，先进先出
    deque<int> deq; //双端队列，两端都可行使队列操作

    priority_queue<int> dui;    //小根堆大根堆，二叉树结构，可以快速得到最大最小值

    set<int> se;    //黑红树
    map<int, int> mp;   //黑红树，维护的是pair类型

    multimap<int, int> map; //支持重复数据的map
    multiset<int> mse;  //支持重复数据的set

    bitset<8> b;    //节省内存空间的01串数据
}