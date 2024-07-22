#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    a = "Hello, world!";
    cout << a << endl;

    //find()方法见CSDN链接

    cout << a.substr(7,12) << endl; //从第几个位置截取几个元素，且不会越界
    cout << a.substr(7) << endl;    //截取pos位置后的所有元素

    return 0;
}
