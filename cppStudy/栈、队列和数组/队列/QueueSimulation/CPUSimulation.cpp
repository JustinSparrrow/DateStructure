//
// Created by moqi on 2023/11/5.
//

#include <bits/stdc++.h>
using namespace std;

struct pp{
    char name[100]; // 进程名称
    int t; // 执行时间
};

const int LEN = 100;
pp Q[LEN]; // 循环队列
int head = 0, tail = 0, n = 0; // 队头指针、队尾指针、队列中元素数量

void enqueue(pp x){
    Q[tail] = x; // 将进程加入队列
    tail = (tail+1)%LEN; // 更新队尾指针
    n++; // 队列中元素数量加一
}

pp dequeue(){
    pp x = Q[head]; // 取出队头进程
    head = (head+1)%LEN; // 更新队头指针
    n--; // 队列中元素数量减一
    return x; // 返回取出的进程
}

//int main(){
//    int elapsed = 0, c;
//    int i, q;
//    pp u;
//    cin >> n >> q; // 输入进程数量和时间片大小
//    for(i = 1; i <= n; i++)
//        cin >> Q[i].name >> Q[i].t; // 输入每个进程的名称和执行时间
//    head = 1; // 初始化队头指针
//    tail = n+1; // 初始化队尾指针
//    while (head != tail){
//        u = dequeue(); // 取出队头进程
//        c = min(u.t, q); // 计算本次执行的时间片大小
//        u.t -= c; // 更新进程的执行时间
//        elapsed += c; // 更新已经过去的时间
//        if(u.t > 0)
//            enqueue(u); // 如果进程还未执行完毕，将其重新加入队列
//        else
//            cout << u.name << " " << elapsed << endl; // 进程执行完毕，输出进程名称和执行时间
//    }
//    return 0;
//}
