#include <iostream>
#include <bits/stdc++.h>
#include <stack>
using namespace std;

int main(){

    stack<int> sta; //栈：先进后出
    int n = 10;
    int m = 1;

    for(int i = 0; i < n ;i++){
        sta.push(m++);
    }

    //遍历+删除
    while(sta.size()){
        cout << sta.top() << ' ';
        sta.pop();
    }

    return 0;
}