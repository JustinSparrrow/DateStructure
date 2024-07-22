#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int n = 10, m = 1;
    queue<int> q;
    for(int i = 0; i < n; i++) q.push(m++);

    while (q.size()){
        cout << q.front() << ' ';
        q.pop();
    }
    cout << endl;

    //队列的清空（无clear()方法）
    while (q.size()) q.pop();

    //双端队列
    deque<int> dq;
    for(int i = 0; i < n; i++){
        dq.push_back(m++);
        dq.push_front(m++);
    }

    while (dq.size()){
        cout << dq.back() << ' ' << dq.front() << endl;
        dq.pop_back();
        dq.pop_front();
    }

    //清空
    dq.clear();

    //优先队列、堆
    //堆是典型的二叉树
    //自动排序内部数，小到大或者大到小
    //遇到随时需要加入、删除数字，同时需要维护最大最小排序的时候使用堆而非数组
    priority_queue<int, vector<int>, greater<int> > pq; //从小到大的堆,less<>是大到小的堆
    for(int i = 0; i < n; i++){
        //这里用scanf、printf、\n是为了减少运行时间
        int op, x;
        scanf("%d",&op);
        if(op==1){
            scanf("%d",&x);
            q.push(x);
        }
        else if(op == 2){
            printf("%d\n",pq.top());
        }
        else{
            pq.pop();
        }
    }


    return 0;
}